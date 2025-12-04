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

#define editparameter_decl_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "editparameter_decl_type.h"
#include "parameter_decl_list.h"
#include "editparameter_decl_statement.h"


expfun editparameter_decl_statement editparameter_decl_statementNew(editparameter_decl_type type = _EDITPARAMETER_DECL_TYPE_UNDEFINED,
                                                                    parameter_decl_list editparameter_decls = NULL)
{
   editparameter_decl_statement e = (editparameter_decl_statement) malloc (sizeof(editparameter_decl_statement_struct));
   if (e != NULL)
   {
      e->type = type;
      e->editparameter_decls = editparameter_decls;
      e->all = false;
   }
   else
      malloc_error("editparameter_decl_statementNew()");

   return e;
}
expfun bool eqType(editparameter_decl_type type,
                   editparameter_decl_statement e)
{
   if (hasType(e) == false)
      return false;
   else if (Eq(type, getType(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfEditparameter_decls(parameter_decl_list editparameter_decls,
                                      editparameter_decl_statement e)
{
   if ((editparameter_decls == NULL) || (hasEditparameter_decls(e) == false))
      return false;
   else if (eqSelf(editparameter_decls, getEditparameter_decls(e)))
      return true;
   else
      return false;
}
expfun bool eqEditparameter_decls(parameter_decl_list editparameter_decls,
                                  editparameter_decl_statement e)
{
   if ((editparameter_decls == NULL) || (hasEditparameter_decls(e) == false))
      return false;
   else if (Eq(editparameter_decls, getEditparameter_decls(e)))
      return true;
   else
      return false;
}
expfun bool eqAll(bool allIn,
                  editparameter_decl_statement e)
{
   if (e == NULL)
      return false;
   else if (allIn == all(e))
      return true;
   else
      return false;
}
expfun bool eqSelf(editparameter_decl_statement a,
                   editparameter_decl_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(editparameter_decl_statement a,
               editparameter_decl_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqType(getType(a), b) == false)
      return false;
   else if (eqEditparameter_decls(getEditparameter_decls(a), b) == false)
      return false;
   else if (eqAll(all(a), b) == false)
      return false;
   else
      return true;
}
expfun editparameter_decl_type getType(editparameter_decl_statement e)
{
   if (e != NULL)
      return e->type;
   else
      return _EDITPARAMETER_DECL_TYPE_UNDEFINED;
}
expfun parameter_decl_list getEditparameter_decls(editparameter_decl_statement e)
{
   if (e != NULL)
      return e->editparameter_decls;
   else
      return NULL;
}
expfun bool all(editparameter_decl_statement e)
{
   if (e != NULL)
      return e->all;
   else
      return false;
}
expfun editparameter_decl_statement setType(editparameter_decl_type type,
                                            editparameter_decl_statement e)
{
   if (e != NULL)
      e->type = type;
   return e;
}
expfun editparameter_decl_statement setEditparameter_decls(parameter_decl_list editparameter_decls,
                                                           editparameter_decl_statement e)
{
   if (e != NULL)
      e->editparameter_decls = editparameter_decls;
   return e;
}
expfun editparameter_decl_statement setAll(bool all,
                                           editparameter_decl_statement e)
{
   if (e != NULL)
      e->all = all;
   return e;
}
expfun bool hasType(editparameter_decl_statement e)
{
   if (getType(e) != _EDITPARAMETER_DECL_TYPE_UNDEFINED)
      return true;
   else
      return false;
}
expfun bool hasEditparameter_decls(editparameter_decl_statement e)
{
   if (isEmpty(getEditparameter_decls(e)) == false)
      return true;
   else
      return false;
}
expfun editparameter_decl_statement copy(editparameter_decl_statement src,
                                         size_t level = 0)
{
   editparameter_decl_statement e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (editparameter_decl_statement) malloc (sizeof(editparameter_decl_statement_struct));
      if (e != NULL)
      {
         if (level > 0)
         {
            e->type = src->type;
            e->editparameter_decls = copy(src->editparameter_decls, level - 1);
            e->all = src->all;
         }
         else
         {
            e->type = src->type;
            e->editparameter_decls = src->editparameter_decls;
            e->all = src->all;
         }
      }
      else
         malloc_error("copy()");

      return e;
   }
}
expfun editparameter_decl_statement deepCopy(editparameter_decl_statement src)
{
   editparameter_decl_statement e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (editparameter_decl_statement) malloc (sizeof(editparameter_decl_statement_struct));
      if (e != NULL)
      {
         e->type = src->type;
         e->editparameter_decls = deepCopy(src->editparameter_decls);
         e->all = src->all;
      }
      else
         malloc_error("deepCopy()");

      return e;
   }
}
expfun void dump(text Offset,
                 editparameter_decl_statement e,
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
         fprintf(fp, "%seditparameter_decl_type type : %s\n", new_Offset, dumpToString(e->type));

      if (hasEditparameter_decls(e) || showEmpty)
      {
         fprintf(fp, "%sparameter_decl_list editparameter_decls,\n", new_Offset);
         dump(new_Offset, e->editparameter_decls, fp, showEmpty);
         fprintf(fp, "%s\\end parameter_decl_list\n", new_Offset);
      }

      fprintf(fp, "%sbool all : %d\n", new_Offset, all(e));

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(editparameter_decl_statement e,
                 size_t level = 0)
{
   if (e ne NULL)
   {
      if (level > 0)
      {

         Free(e->editparameter_decls, level - 1);
         e->editparameter_decls = NULL;
      }


      free((void *) e);
   }
}
expfun void deepFree(editparameter_decl_statement e)
{
   if (e ne NULL)
   {

      deepFree(e->editparameter_decls);
      e->editparameter_decls = NULL;

      free((void *) e);
   }
}
