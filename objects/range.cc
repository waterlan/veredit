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

#define range_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "range.h"


expfun range rangeNew(int begin = 0,
                      int end = 0)
{
   range r = (range) malloc (sizeof(range_struct));
   if (r != NULL)
   {
      r->begin = begin;
      r->end = end;
   }
   else
      malloc_error("rangeNew()");

   return r;
}
expfun bool eqBegin(int begin,
                    range r)
{
   if (r == NULL)
      return false;
   else if (begin == getBegin(r))
      return true;
   else
      return false;
}
expfun bool eqEnd(int end,
                  range r)
{
   if (r == NULL)
      return false;
   else if (end == getEnd(r))
      return true;
   else
      return false;
}
expfun bool eqSelf(range a,
                   range b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(range a,
               range b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqBegin(getBegin(a), b) == false)
      return false;
   else if (eqEnd(getEnd(a), b) == false)
      return false;
   else
      return true;
}
expfun int getBegin(range r)
{
   if (r != NULL)
      return r->begin;
   else
      return 0;
}
expfun int getEnd(range r)
{
   if (r != NULL)
      return r->end;
   else
      return 0;
}
expfun range setBegin(int begin,
                      range r)
{
   if (r != NULL)
      r->begin = begin;
   return r;
}
expfun range setEnd(int end,
                    range r)
{
   if (r != NULL)
      r->end = end;
   return r;
}
expfun range copy(range src)
{
   range r;

   if (src == NULL)
      return NULL;
   else
   {
      r = (range) malloc (sizeof(range_struct));
      if (r != NULL)
      {
         r->begin = src->begin;
         r->end = src->end;
      }
      else
         malloc_error("copy()");

      return r;
   }
}
expfun void dump(text Offset,
                 range r,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (r == NULL)
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

      fprintf(fp, "%sint begin : %d\n", new_Offset, getBegin(r));

      fprintf(fp, "%sint end : %d\n", new_Offset, getEnd(r));

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(range r)
{
   if (r ne NULL)
   {

      free((void *) r);
   }
}
