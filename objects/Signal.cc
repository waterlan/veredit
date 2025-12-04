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

#define Signal_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "simple_signal.h"
#include "signal_list.h"
#include "Signal.h"


expfun Signal SignalNew(simple_signal simple = NULL,
                        signal_list cmpnd = NULL)
{
   Signal s = (Signal) malloc (sizeof(Signal_struct));
   if (s != NULL)
   {
      s->simple = simple;
      s->cmpnd = cmpnd;
   }
   else
      malloc_error("SignalNew()");

   return s;
}
expfun bool eqSelfSimple(simple_signal simple,
                         Signal s)
{
   if ((simple == NULL) || (hasSimple(s) == false))
      return false;
   else if (eqSelf(simple, getSimple(s)))
      return true;
   else
      return false;
}
expfun bool eqSimple(simple_signal simple,
                     Signal s)
{
   if ((simple == NULL) || (hasSimple(s) == false))
      return false;
   else if (Eq(simple, getSimple(s)))
      return true;
   else
      return false;
}
expfun bool eqSelfCmpnd(signal_list cmpnd,
                        Signal s)
{
   if ((cmpnd == NULL) || (hasCmpnd(s) == false))
      return false;
   else if (eqSelf(cmpnd, getCmpnd(s)))
      return true;
   else
      return false;
}
expfun bool eqCmpnd(signal_list cmpnd,
                    Signal s)
{
   if ((cmpnd == NULL) || (hasCmpnd(s) == false))
      return false;
   else if (Eq(cmpnd, getCmpnd(s)))
      return true;
   else
      return false;
}
expfun bool eqSelf(Signal a,
                   Signal b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(Signal a,
               Signal b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqSimple(getSimple(a), b) == false)
      return false;
   else if (eqCmpnd(getCmpnd(a), b) == false)
      return false;
   else
      return true;
}
expfun simple_signal getSimple(Signal s)
{
   if (s != NULL)
      return s->simple;
   else
      return NULL;
}
expfun signal_list getCmpnd(Signal s)
{
   if (s != NULL)
      return s->cmpnd;
   else
      return NULL;
}
expfun Signal setSimple(simple_signal simple,
                        Signal s)
{
   if (s != NULL)
      s->simple = simple;
   return s;
}
expfun Signal setCmpnd(signal_list cmpnd,
                       Signal s)
{
   if (s != NULL)
      s->cmpnd = cmpnd;
   return s;
}
expfun bool hasSimple(Signal s)
{
   if (getSimple(s) != NULL)
      return true;
   else
      return false;
}
expfun bool hasCmpnd(Signal s)
{
   if (isEmpty(getCmpnd(s)) == false)
      return true;
   else
      return false;
}
expfun Signal copy(Signal src,
                   size_t level = 0)
{
   Signal s;

   if (src == NULL)
      return NULL;
   else
   {
      s = (Signal) malloc (sizeof(Signal_struct));
      if (s != NULL)
      {
         if (level > 0)
         {
            s->simple = copy(src->simple, level - 1);
            s->cmpnd = copy(src->cmpnd, level - 1);
         }
         else
         {
            s->simple = src->simple;
            s->cmpnd = src->cmpnd;
         }
      }
      else
         malloc_error("copy()");

      return s;
   }
}
expfun Signal deepCopy(Signal src)
{
   Signal s;

   if (src == NULL)
      return NULL;
   else
   {
      s = (Signal) malloc (sizeof(Signal_struct));
      if (s != NULL)
      {
         s->simple = deepCopy(src->simple);
         s->cmpnd = deepCopy(src->cmpnd);
      }
      else
         malloc_error("deepCopy()");

      return s;
   }
}
expfun void dump(text Offset,
                 Signal s,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (s == NULL)
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

      if (hasSimple(s) || showEmpty)
      {
         fprintf(fp, "%ssimple_signal simple,\n", new_Offset);
         dump(new_Offset, s->simple, fp, showEmpty);
         fprintf(fp, "%s\\end simple_signal\n", new_Offset);
      }

      if (hasCmpnd(s) || showEmpty)
      {
         fprintf(fp, "%ssignal_list cmpnd,\n", new_Offset);
         dump(new_Offset, s->cmpnd, fp, showEmpty);
         fprintf(fp, "%s\\end signal_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(Signal s,
                 size_t level = 0)
{
   if (s ne NULL)
   {
      if (level > 0)
      {

         Free(s->simple, level - 1);
         s->simple = NULL;

         Free(s->cmpnd, level - 1);
         s->cmpnd = NULL;
      }


      free((void *) s);
   }
}
expfun void deepFree(Signal s)
{
   if (s ne NULL)
   {

      deepFree(s->simple);
      s->simple = NULL;

      deepFree(s->cmpnd);
      s->cmpnd = NULL;

      free((void *) s);
   }
}
