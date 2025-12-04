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

#define delete_module_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "delete_module_statement.h"


expfun delete_module_statement delete_module_statementNew(void)
{
   delete_module_statement d = (delete_module_statement) malloc (sizeof(delete_module_statement_struct));
   if (d != NULL)
   {
      d->deleteModule = false;
      d->empty = false;
   }
   else
      malloc_error("delete_module_statementNew()");

   return d;
}
expfun bool eqDeleteModule(bool deleteModuleIn,
                           delete_module_statement d)
{
   if (d == NULL)
      return false;
   else if (deleteModuleIn == deleteModule(d))
      return true;
   else
      return false;
}
expfun bool eqEmpty(bool emptyIn,
                    delete_module_statement d)
{
   if (d == NULL)
      return false;
   else if (emptyIn == empty(d))
      return true;
   else
      return false;
}
expfun bool eqSelf(delete_module_statement a,
                   delete_module_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(delete_module_statement a,
               delete_module_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqDeleteModule(deleteModule(a), b) == false)
      return false;
   else if (eqEmpty(empty(a), b) == false)
      return false;
   else
      return true;
}
expfun bool deleteModule(delete_module_statement d)
{
   if (d != NULL)
      return d->deleteModule;
   else
      return false;
}
expfun bool empty(delete_module_statement d)
{
   if (d != NULL)
      return d->empty;
   else
      return false;
}
expfun delete_module_statement setDeleteModule(bool deleteModule,
                                               delete_module_statement d)
{
   if (d != NULL)
      d->deleteModule = deleteModule;
   return d;
}
expfun delete_module_statement setEmpty(bool empty,
                                        delete_module_statement d)
{
   if (d != NULL)
      d->empty = empty;
   return d;
}
expfun delete_module_statement copy(delete_module_statement src)
{
   delete_module_statement d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (delete_module_statement) malloc (sizeof(delete_module_statement_struct));
      if (d != NULL)
      {
         d->deleteModule = src->deleteModule;
         d->empty = src->empty;
      }
      else
         malloc_error("copy()");

      return d;
   }
}
expfun void dump(text Offset,
                 delete_module_statement d,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (d == NULL)
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

      fprintf(fp, "%sbool deleteModule : %d\n", new_Offset, deleteModule(d));

      fprintf(fp, "%sbool empty : %d\n", new_Offset, empty(d));

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(delete_module_statement d)
{
   if (d ne NULL)
   {

      free((void *) d);
   }
}
