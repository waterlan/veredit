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

#define pullup_pin_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "simple_signal_list.h"
#include "pullup_pin_statement.h"


expfun pullup_pin_statement pullup_pin_statementNew(simple_signal_list Pins = NULL)
{
   pullup_pin_statement p = (pullup_pin_statement) malloc (sizeof(pullup_pin_statement_struct));
   if (p != NULL)
      p->Pins = Pins;
   else
      malloc_error("pullup_pin_statementNew()");

   return p;
}
expfun bool eqSelfPins(simple_signal_list Pins,
                       pullup_pin_statement p)
{
   if ((Pins == NULL) || (hasPins(p) == false))
      return false;
   else if (eqSelf(Pins, getPins(p)))
      return true;
   else
      return false;
}
expfun bool eqPins(simple_signal_list Pins,
                   pullup_pin_statement p)
{
   if ((Pins == NULL) || (hasPins(p) == false))
      return false;
   else if (Eq(Pins, getPins(p)))
      return true;
   else
      return false;
}
expfun bool eqSelf(pullup_pin_statement a,
                   pullup_pin_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(pullup_pin_statement a,
               pullup_pin_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqPins(getPins(a), b) == false)
      return false;
   else
      return true;
}
expfun simple_signal_list getPins(pullup_pin_statement p)
{
   if (p != NULL)
      return p->Pins;
   else
      return NULL;
}
expfun pullup_pin_statement setPins(simple_signal_list Pins,
                                    pullup_pin_statement p)
{
   if (p != NULL)
      p->Pins = Pins;
   return p;
}
expfun bool hasPins(pullup_pin_statement p)
{
   if (isEmpty(getPins(p)) == false)
      return true;
   else
      return false;
}
expfun pullup_pin_statement copy(pullup_pin_statement src,
                                 size_t level = 0)
{
   pullup_pin_statement p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (pullup_pin_statement) malloc (sizeof(pullup_pin_statement_struct));
      if (p != NULL)
      {
         if (level > 0)
            p->Pins = copy(src->Pins, level - 1);
         else
            p->Pins = src->Pins;
      }
      else
         malloc_error("copy()");

      return p;
   }
}
expfun pullup_pin_statement deepCopy(pullup_pin_statement src)
{
   pullup_pin_statement p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (pullup_pin_statement) malloc (sizeof(pullup_pin_statement_struct));
      if (p != NULL)
      {
         p->Pins = deepCopy(src->Pins);
      }
      else
         malloc_error("deepCopy()");

      return p;
   }
}
expfun void dump(text Offset,
                 pullup_pin_statement p,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (p == NULL)
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

      if (hasPins(p) || showEmpty)
      {
         fprintf(fp, "%ssimple_signal_list Pins,\n", new_Offset);
         dump(new_Offset, p->Pins, fp, showEmpty);
         fprintf(fp, "%s\\end simple_signal_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(pullup_pin_statement p,
                 size_t level = 0)
{
   if (p ne NULL)
   {
      if (level > 0)
      {

         Free(p->Pins, level - 1);
         p->Pins = NULL;
      }


      free((void *) p);
   }
}
expfun void deepFree(pullup_pin_statement p)
{
   if (p ne NULL)
   {

      deepFree(p->Pins);
      p->Pins = NULL;

      free((void *) p);
   }
}
