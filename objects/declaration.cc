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

#define declaration_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "signal_type.h"
#include "range.h"
#include "variable_list.h"
#include "declaration.h"


expfun declaration declarationNew(signal_type type = _SIGNAL_TYPE_UNDEFINED,
                                  range rnge = NULL,
                                  variable_list signals = NULL)
{
   declaration d = (declaration) malloc (sizeof(declaration_struct));
   if (d != NULL)
   {
      d->type = type;
      d->rnge = rnge;
      d->signals = signals;
   }
   else
      malloc_error("declarationNew()");

   return d;
}
expfun bool eqType(signal_type type,
                   declaration d)
{
   if (hasType(d) == false)
      return false;
   else if (Eq(type, getType(d)))
      return true;
   else
      return false;
}
expfun bool eqSelfRnge(range rnge,
                       declaration d)
{
   if ((rnge == NULL) || (hasRnge(d) == false))
      return false;
   else if (eqSelf(rnge, getRnge(d)))
      return true;
   else
      return false;
}
expfun bool eqRnge(range rnge,
                   declaration d)
{
   if ((rnge == NULL) || (hasRnge(d) == false))
      return false;
   else if (Eq(rnge, getRnge(d)))
      return true;
   else
      return false;
}
expfun bool eqSelfSignals(variable_list signals,
                          declaration d)
{
   if ((signals == NULL) || (hasSignals(d) == false))
      return false;
   else if (eqSelf(signals, getSignals(d)))
      return true;
   else
      return false;
}
expfun bool eqSignals(variable_list signals,
                      declaration d)
{
   if ((signals == NULL) || (hasSignals(d) == false))
      return false;
   else if (Eq(signals, getSignals(d)))
      return true;
   else
      return false;
}
expfun bool eqSelf(declaration a,
                   declaration b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(declaration a,
               declaration b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqType(getType(a), b) == false)
      return false;
   else if (eqRnge(getRnge(a), b) == false)
      return false;
   else if (eqSignals(getSignals(a), b) == false)
      return false;
   else
      return true;
}
expfun signal_type getType(declaration d)
{
   if (d != NULL)
      return d->type;
   else
      return _SIGNAL_TYPE_UNDEFINED;
}
expfun range getRnge(declaration d)
{
   if (d != NULL)
      return d->rnge;
   else
      return NULL;
}
expfun variable_list getSignals(declaration d)
{
   if (d != NULL)
      return d->signals;
   else
      return NULL;
}
expfun declaration setType(signal_type type,
                           declaration d)
{
   if (d != NULL)
      d->type = type;
   return d;
}
expfun declaration setRnge(range rnge,
                           declaration d)
{
   if (d != NULL)
      d->rnge = rnge;
   return d;
}
expfun declaration setSignals(variable_list signals,
                              declaration d)
{
   if (d != NULL)
      d->signals = signals;
   return d;
}
expfun bool hasType(declaration d)
{
   if (getType(d) != _SIGNAL_TYPE_UNDEFINED)
      return true;
   else
      return false;
}
expfun bool hasRnge(declaration d)
{
   if (getRnge(d) != NULL)
      return true;
   else
      return false;
}
expfun bool hasSignals(declaration d)
{
   if (isEmpty(getSignals(d)) == false)
      return true;
   else
      return false;
}
expfun declaration copy(declaration src,
                        size_t level = 0)
{
   declaration d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (declaration) malloc (sizeof(declaration_struct));
      if (d != NULL)
      {
         if (level > 0)
         {
            d->type = src->type;
            d->rnge = copy(src->rnge);
            d->signals = copy(src->signals, level - 1);
         }
         else
         {
            d->type = src->type;
            d->rnge = src->rnge;
            d->signals = src->signals;
         }
      }
      else
         malloc_error("copy()");

      return d;
   }
}
expfun declaration deepCopy(declaration src)
{
   declaration d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (declaration) malloc (sizeof(declaration_struct));
      if (d != NULL)
      {
         d->type = src->type;
         d->rnge = copy(src->rnge);
         d->signals = deepCopy(src->signals);
      }
      else
         malloc_error("deepCopy()");

      return d;
   }
}
expfun void dump(text Offset,
                 declaration d,
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
         fprintf(fp, "%ssignal_type type : %s\n", new_Offset, dumpToString(d->type));

      if (hasRnge(d) || showEmpty)
      {
         fprintf(fp, "%srange rnge,\n", new_Offset);
         dump(new_Offset, d->rnge, fp, showEmpty);
         fprintf(fp, "%s\\end range\n", new_Offset);
      }

      if (hasSignals(d) || showEmpty)
      {
         fprintf(fp, "%svariable_list signals,\n", new_Offset);
         dump(new_Offset, d->signals, fp, showEmpty);
         fprintf(fp, "%s\\end variable_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(declaration d,
                 size_t level = 0)
{
   if (d ne NULL)
   {
      if (level > 0)
      {

         Free(d->rnge);
         d->rnge = NULL;

         Free(d->signals, level - 1);
         d->signals = NULL;
      }


      free((void *) d);
   }
}
expfun void deepFree(declaration d)
{
   if (d ne NULL)
   {

      Free(d->rnge);
      d->rnge = NULL;

      deepFree(d->signals);
      d->signals = NULL;

      free((void *) d);
   }
}
