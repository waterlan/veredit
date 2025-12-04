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

#define delport_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "editport_type.h"
#include "port_list.h"
#include "delport_statement.h"


expfun delport_statement delport_statementNew(editport_type type = _EDITPORT_TYPE_UNDEFINED,
                                              port_list delports = NULL)
{
   delport_statement d = (delport_statement) malloc (sizeof(delport_statement_struct));
   if (d != NULL)
   {
      d->type = type;
      d->delports = delports;
      d->all = false;
   }
   else
      malloc_error("delport_statementNew()");

   return d;
}
expfun bool eqType(editport_type type,
                   delport_statement d)
{
   if (hasType(d) == false)
      return false;
   else if (Eq(type, getType(d)))
      return true;
   else
      return false;
}
expfun bool eqSelfDelports(port_list delports,
                           delport_statement d)
{
   if ((delports == NULL) || (hasDelports(d) == false))
      return false;
   else if (eqSelf(delports, getDelports(d)))
      return true;
   else
      return false;
}
expfun bool eqDelports(port_list delports,
                       delport_statement d)
{
   if ((delports == NULL) || (hasDelports(d) == false))
      return false;
   else if (Eq(delports, getDelports(d)))
      return true;
   else
      return false;
}
expfun bool eqAll(bool allIn,
                  delport_statement d)
{
   if (d == NULL)
      return false;
   else if (allIn == all(d))
      return true;
   else
      return false;
}
expfun bool eqSelf(delport_statement a,
                   delport_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(delport_statement a,
               delport_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqType(getType(a), b) == false)
      return false;
   else if (eqDelports(getDelports(a), b) == false)
      return false;
   else if (eqAll(all(a), b) == false)
      return false;
   else
      return true;
}
expfun editport_type getType(delport_statement d)
{
   if (d != NULL)
      return d->type;
   else
      return _EDITPORT_TYPE_UNDEFINED;
}
expfun port_list getDelports(delport_statement d)
{
   if (d != NULL)
      return d->delports;
   else
      return NULL;
}
expfun bool all(delport_statement d)
{
   if (d != NULL)
      return d->all;
   else
      return false;
}
expfun delport_statement setType(editport_type type,
                                 delport_statement d)
{
   if (d != NULL)
      d->type = type;
   return d;
}
expfun delport_statement setDelports(port_list delports,
                                     delport_statement d)
{
   if (d != NULL)
      d->delports = delports;
   return d;
}
expfun delport_statement setAll(bool all,
                                delport_statement d)
{
   if (d != NULL)
      d->all = all;
   return d;
}
expfun bool hasType(delport_statement d)
{
   if (getType(d) != _EDITPORT_TYPE_UNDEFINED)
      return true;
   else
      return false;
}
expfun bool hasDelports(delport_statement d)
{
   if (isEmpty(getDelports(d)) == false)
      return true;
   else
      return false;
}
expfun delport_statement copy(delport_statement src,
                              size_t level = 0)
{
   delport_statement d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (delport_statement) malloc (sizeof(delport_statement_struct));
      if (d != NULL)
      {
         if (level > 0)
         {
            d->type = src->type;
            d->delports = copy(src->delports, level - 1);
            d->all = src->all;
         }
         else
         {
            d->type = src->type;
            d->delports = src->delports;
            d->all = src->all;
         }
      }
      else
         malloc_error("copy()");

      return d;
   }
}
expfun delport_statement deepCopy(delport_statement src)
{
   delport_statement d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (delport_statement) malloc (sizeof(delport_statement_struct));
      if (d != NULL)
      {
         d->type = src->type;
         d->delports = deepCopy(src->delports);
         d->all = src->all;
      }
      else
         malloc_error("deepCopy()");

      return d;
   }
}
expfun void dump(text Offset,
                 delport_statement d,
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

      if (hasType(d) || showEmpty)
         fprintf(fp, "%seditport_type type : %s\n", new_Offset, dumpToString(d->type));

      if (hasDelports(d) || showEmpty)
      {
         fprintf(fp, "%sport_list delports,\n", new_Offset);
         dump(new_Offset, d->delports, fp, showEmpty);
         fprintf(fp, "%s\\end port_list\n", new_Offset);
      }

      fprintf(fp, "%sbool all : %d\n", new_Offset, all(d));

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(delport_statement d,
                 size_t level = 0)
{
   if (d ne NULL)
   {
      if (level > 0)
      {

         Free(d->delports, level - 1);
         d->delports = NULL;
      }


      free((void *) d);
   }
}
expfun void deepFree(delport_statement d)
{
   if (d ne NULL)
   {

      deepFree(d->delports);
      d->delports = NULL;

      free((void *) d);
   }
}
