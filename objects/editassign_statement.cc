// Copyright (C) 1999-2025  Erwin Waterlander
// Copyright (C) 1999       Ondrej Popp
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice in the documentation and/or other materials provided with
//    the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
// OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
// BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#define editassign_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "editassign_type.h"
#include "assign_list.h"
#include "editassign_statement.h"


expfun editassign_statement editassign_statementNew(editassign_type type = _EDITASSIGN_TYPE_UNDEFINED,
                                                    assign_list editassigns = NULL)
{
   editassign_statement e = (editassign_statement) malloc (sizeof(editassign_statement_struct));
   if (e != NULL)
   {
      e->type = type;
      e->editassigns = editassigns;
      e->all = false;
   }
   else
      malloc_error("editassign_statementNew()");

   return e;
}
expfun bool eqType(editassign_type type,
                   editassign_statement e)
{
   if (hasType(e) == false)
      return false;
   else if (Eq(type, getType(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfEditassigns(assign_list editassigns,
                              editassign_statement e)
{
   if ((editassigns == NULL) || (hasEditassigns(e) == false))
      return false;
   else if (eqSelf(editassigns, getEditassigns(e)))
      return true;
   else
      return false;
}
expfun bool eqEditassigns(assign_list editassigns,
                          editassign_statement e)
{
   if ((editassigns == NULL) || (hasEditassigns(e) == false))
      return false;
   else if (Eq(editassigns, getEditassigns(e)))
      return true;
   else
      return false;
}
expfun bool eqAll(bool allIn,
                  editassign_statement e)
{
   if (e == NULL)
      return false;
   else if (allIn == all(e))
      return true;
   else
      return false;
}
expfun bool eqSelf(editassign_statement a,
                   editassign_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(editassign_statement a,
               editassign_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqType(getType(a), b) == false)
      return false;
   else if (eqEditassigns(getEditassigns(a), b) == false)
      return false;
   else if (eqAll(all(a), b) == false)
      return false;
   else
      return true;
}
expfun editassign_type getType(editassign_statement e)
{
   if (e != NULL)
      return e->type;
   else
      return _EDITASSIGN_TYPE_UNDEFINED;
}
expfun assign_list getEditassigns(editassign_statement e)
{
   if (e != NULL)
      return e->editassigns;
   else
      return NULL;
}
expfun bool all(editassign_statement e)
{
   if (e != NULL)
      return e->all;
   else
      return false;
}
expfun editassign_statement setType(editassign_type type,
                                    editassign_statement e)
{
   if (e != NULL)
      e->type = type;
   return e;
}
expfun editassign_statement setEditassigns(assign_list editassigns,
                                           editassign_statement e)
{
   if (e != NULL)
      e->editassigns = editassigns;
   return e;
}
expfun editassign_statement setAll(bool all,
                                   editassign_statement e)
{
   if (e != NULL)
      e->all = all;
   return e;
}
expfun bool hasType(editassign_statement e)
{
   if (getType(e) != _EDITASSIGN_TYPE_UNDEFINED)
      return true;
   else
      return false;
}
expfun bool hasEditassigns(editassign_statement e)
{
   if (isEmpty(getEditassigns(e)) == false)
      return true;
   else
      return false;
}
expfun editassign_statement copy(editassign_statement src,
                                 size_t level = 0)
{
   editassign_statement e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (editassign_statement) malloc (sizeof(editassign_statement_struct));
      if (e != NULL)
      {
         if (level > 0)
         {
            e->type = src->type;
            e->editassigns = copy(src->editassigns, level - 1);
            e->all = src->all;
         }
         else
         {
            e->type = src->type;
            e->editassigns = src->editassigns;
            e->all = src->all;
         }
      }
      else
         malloc_error("copy()");

      return e;
   }
}
expfun editassign_statement deepCopy(editassign_statement src)
{
   editassign_statement e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (editassign_statement) malloc (sizeof(editassign_statement_struct));
      if (e != NULL)
      {
         e->type = src->type;
         e->editassigns = deepCopy(src->editassigns);
         e->all = src->all;
      }
      else
         malloc_error("deepCopy()");

      return e;
   }
}
expfun void dump(text Offset,
                 editassign_statement e,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (e == NULL)
   {
      if (showEmpty)
      {
         fprintf(fp, "%s{\n", Offset);
         fprintf(fp, "%sNULL\n", new_Offset);
         fprintf(fp, "%s}\n", Offset);
      }
   }
   else
   {
      fprintf(fp, "%s{\n", Offset);

      if (hasType(e) || showEmpty)
         fprintf(fp, "%seditassign_type type : %s\n", new_Offset, dumpToString(e->type));

      if (hasEditassigns(e) || showEmpty)
      {
         fprintf(fp, "%sassign_list editassigns,\n", new_Offset);
         dump(new_Offset, e->editassigns, fp, showEmpty);
         fprintf(fp, "%s\\end assign_list\n", new_Offset);
      }

      fprintf(fp, "%sbool all : %d\n", new_Offset, all(e));

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(editassign_statement e,
                 size_t level = 0)
{
   if (e ne NULL)
   {
      if (level > 0)
      {

         Free(e->editassigns, level - 1);
         e->editassigns = NULL;
      }


      free((void *) e);
   }
}
expfun void deepFree(editassign_statement e)
{
   if (e ne NULL)
   {

      deepFree(e->editassigns);
      e->editassigns = NULL;

      free((void *) e);
   }
}
