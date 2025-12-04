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

#define addport_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "declaration_list.h"
#include "addport_statement.h"


expfun addport_statement addport_statementNew(declaration_list addports = NULL)
{
   addport_statement a = (addport_statement) malloc (sizeof(addport_statement_struct));
   if (a != NULL)
      a->addports = addports;
   else
      malloc_error("addport_statementNew()");

   return a;
}
expfun bool eqSelfAddports(declaration_list addports,
                           addport_statement a)
{
   if ((addports == NULL) || (hasAddports(a) == false))
      return false;
   else if (eqSelf(addports, getAddports(a)))
      return true;
   else
      return false;
}
expfun bool eqAddports(declaration_list addports,
                       addport_statement a)
{
   if ((addports == NULL) || (hasAddports(a) == false))
      return false;
   else if (Eq(addports, getAddports(a)))
      return true;
   else
      return false;
}
expfun bool eqSelf(addport_statement a,
                   addport_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(addport_statement a,
               addport_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqAddports(getAddports(a), b) == false)
      return false;
   else
      return true;
}
expfun declaration_list getAddports(addport_statement a)
{
   if (a != NULL)
      return a->addports;
   else
      return NULL;
}
expfun addport_statement setAddports(declaration_list addports,
                                     addport_statement a)
{
   if (a != NULL)
      a->addports = addports;
   return a;
}
expfun bool hasAddports(addport_statement a)
{
   if (isEmpty(getAddports(a)) == false)
      return true;
   else
      return false;
}
expfun addport_statement copy(addport_statement src,
                              size_t level = 0)
{
   addport_statement a;

   if (src == NULL)
      return NULL;
   else
   {
      a = (addport_statement) malloc (sizeof(addport_statement_struct));
      if (a != NULL)
      {
         if (level > 0)
            a->addports = copy(src->addports, level - 1);
         else
            a->addports = src->addports;
      }
      else
         malloc_error("copy()");

      return a;
   }
}
expfun addport_statement deepCopy(addport_statement src)
{
   addport_statement a;

   if (src == NULL)
      return NULL;
   else
   {
      a = (addport_statement) malloc (sizeof(addport_statement_struct));
      if (a != NULL)
      {
         a->addports = deepCopy(src->addports);
      }
      else
         malloc_error("deepCopy()");

      return a;
   }
}
expfun void dump(text Offset,
                 addport_statement a,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (a == NULL)
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

      if (hasAddports(a) || showEmpty)
      {
         fprintf(fp, "%sdeclaration_list addports,\n", new_Offset);
         dump(new_Offset, a->addports, fp, showEmpty);
         fprintf(fp, "%s\\end declaration_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(addport_statement a,
                 size_t level = 0)
{
   if (a ne NULL)
   {
      if (level > 0)
      {

         Free(a->addports, level - 1);
         a->addports = NULL;
      }


      free((void *) a);
   }
}
expfun void deepFree(addport_statement a)
{
   if (a ne NULL)
   {

      deepFree(a->addports);
      a->addports = NULL;

      free((void *) a);
   }
}
