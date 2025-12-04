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

#define editinst_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "editinst_type.h"
#include "instantiation_list.h"
#include "editinst_statement.h"


expfun editinst_statement editinst_statementNew(editinst_type type = _EDITINST_TYPE_UNDEFINED,
                                                instantiation_list editinstances = NULL)
{
   editinst_statement e = (editinst_statement) malloc (sizeof(editinst_statement_struct));
   if (e != NULL)
   {
      e->type = type;
      e->editinstances = editinstances;
      e->keepmodname = false;
      e->all = false;
   }
   else
      malloc_error("editinst_statementNew()");

   return e;
}
expfun bool eqType(editinst_type type,
                   editinst_statement e)
{
   if (hasType(e) == false)
      return false;
   else if (Eq(type, getType(e)))
      return true;
   else
      return false;
}
expfun bool eqKeepmodname(bool keepmodnameIn,
                          editinst_statement e)
{
   if (e == NULL)
      return false;
   else if (keepmodnameIn == keepmodname(e))
      return true;
   else
      return false;
}
expfun bool eqSelfEditinstances(instantiation_list editinstances,
                                editinst_statement e)
{
   if ((editinstances == NULL) || (hasEditinstances(e) == false))
      return false;
   else if (eqSelf(editinstances, getEditinstances(e)))
      return true;
   else
      return false;
}
expfun bool eqEditinstances(instantiation_list editinstances,
                            editinst_statement e)
{
   if ((editinstances == NULL) || (hasEditinstances(e) == false))
      return false;
   else if (Eq(editinstances, getEditinstances(e)))
      return true;
   else
      return false;
}
expfun bool eqAll(bool allIn,
                  editinst_statement e)
{
   if (e == NULL)
      return false;
   else if (allIn == all(e))
      return true;
   else
      return false;
}
expfun bool eqSelf(editinst_statement a,
                   editinst_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(editinst_statement a,
               editinst_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqType(getType(a), b) == false)
      return false;
   else if (eqKeepmodname(keepmodname(a), b) == false)
      return false;
   else if (eqEditinstances(getEditinstances(a), b) == false)
      return false;
   else if (eqAll(all(a), b) == false)
      return false;
   else
      return true;
}
expfun editinst_type getType(editinst_statement e)
{
   if (e != NULL)
      return e->type;
   else
      return _EDITINST_TYPE_UNDEFINED;
}
expfun bool keepmodname(editinst_statement e)
{
   if (e != NULL)
      return e->keepmodname;
   else
      return false;
}
expfun instantiation_list getEditinstances(editinst_statement e)
{
   if (e != NULL)
      return e->editinstances;
   else
      return NULL;
}
expfun bool all(editinst_statement e)
{
   if (e != NULL)
      return e->all;
   else
      return false;
}
expfun editinst_statement setType(editinst_type type,
                                  editinst_statement e)
{
   if (e != NULL)
      e->type = type;
   return e;
}
expfun editinst_statement setKeepmodname(bool keepmodname,
                                         editinst_statement e)
{
   if (e != NULL)
      e->keepmodname = keepmodname;
   return e;
}
expfun editinst_statement setEditinstances(instantiation_list editinstances,
                                           editinst_statement e)
{
   if (e != NULL)
      e->editinstances = editinstances;
   return e;
}
expfun editinst_statement setAll(bool all,
                                 editinst_statement e)
{
   if (e != NULL)
      e->all = all;
   return e;
}
expfun bool hasType(editinst_statement e)
{
   if (getType(e) != _EDITINST_TYPE_UNDEFINED)
      return true;
   else
      return false;
}
expfun bool hasEditinstances(editinst_statement e)
{
   if (isEmpty(getEditinstances(e)) == false)
      return true;
   else
      return false;
}
expfun editinst_statement copy(editinst_statement src,
                               size_t level = 0)
{
   editinst_statement e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (editinst_statement) malloc (sizeof(editinst_statement_struct));
      if (e != NULL)
      {
         if (level > 0)
         {
            e->type = src->type;
            e->keepmodname = src->keepmodname;
            e->editinstances = copy(src->editinstances, level - 1);
            e->all = src->all;
         }
         else
         {
            e->type = src->type;
            e->keepmodname = src->keepmodname;
            e->editinstances = src->editinstances;
            e->all = src->all;
         }
      }
      else
         malloc_error("copy()");

      return e;
   }
}
expfun editinst_statement deepCopy(editinst_statement src)
{
   editinst_statement e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (editinst_statement) malloc (sizeof(editinst_statement_struct));
      if (e != NULL)
      {
         e->type = src->type;
         e->keepmodname = src->keepmodname;
         e->editinstances = deepCopy(src->editinstances);
         e->all = src->all;
      }
      else
         malloc_error("deepCopy()");

      return e;
   }
}
expfun void dump(text Offset,
                 editinst_statement e,
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
         fprintf(fp, "%seditinst_type type : %s\n", new_Offset, dumpToString(e->type));

      fprintf(fp, "%sbool keepmodname : %d\n", new_Offset, keepmodname(e));

      if (hasEditinstances(e) || showEmpty)
      {
         fprintf(fp, "%sinstantiation_list editinstances,\n", new_Offset);
         dump(new_Offset, e->editinstances, fp, showEmpty);
         fprintf(fp, "%s\\end instantiation_list\n", new_Offset);
      }

      fprintf(fp, "%sbool all : %d\n", new_Offset, all(e));

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(editinst_statement e,
                 size_t level = 0)
{
   if (e ne NULL)
   {
      if (level > 0)
      {

         Free(e->editinstances, level - 1);
         e->editinstances = NULL;
      }


      free((void *) e);
   }
}
expfun void deepFree(editinst_statement e)
{
   if (e ne NULL)
   {

      deepFree(e->editinstances);
      e->editinstances = NULL;

      free((void *) e);
   }
}
