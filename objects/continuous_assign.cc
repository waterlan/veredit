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

#define continuous_assign_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "simple_signal.h"
#include "expression.h"
#include "continuous_assign.h"


expfun continuous_assign continuous_assignNew(simple_signal signal = NULL,
                                              expression expr = NULL)
{
   continuous_assign c = (continuous_assign) malloc (sizeof(continuous_assign_struct));
   if (c != NULL)
   {
      c->signal = signal;
      c->expr = expr;
   }
   else
      malloc_error("continuous_assignNew()");

   return c;
}
expfun bool eqSelfSignal(simple_signal signal,
                         continuous_assign c)
{
   if ((signal == NULL) || (hasSignal(c) == false))
      return false;
   else if (eqSelf(signal, getSignal(c)))
      return true;
   else
      return false;
}
expfun bool eqSignal(simple_signal signal,
                     continuous_assign c)
{
   if ((signal == NULL) || (hasSignal(c) == false))
      return false;
   else if (Eq(signal, getSignal(c)))
      return true;
   else
      return false;
}
expfun bool eqSelfExpr(expression expr,
                       continuous_assign c)
{
   if ((expr == NULL) || (hasExpr(c) == false))
      return false;
   else if (eqSelf(expr, getExpr(c)))
      return true;
   else
      return false;
}
expfun bool eqExpr(expression expr,
                   continuous_assign c)
{
   if ((expr == NULL) || (hasExpr(c) == false))
      return false;
   else if (Eq(expr, getExpr(c)))
      return true;
   else
      return false;
}
expfun bool eqSelf(continuous_assign a,
                   continuous_assign b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(continuous_assign a,
               continuous_assign b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqSignal(getSignal(a), b) == false)
      return false;
   else if (eqExpr(getExpr(a), b) == false)
      return false;
   else
      return true;
}
expfun simple_signal getSignal(continuous_assign c)
{
   if (c != NULL)
      return c->signal;
   else
      return NULL;
}
expfun expression getExpr(continuous_assign c)
{
   if (c != NULL)
      return c->expr;
   else
      return NULL;
}
expfun continuous_assign setSignal(simple_signal signal,
                                   continuous_assign c)
{
   if (c != NULL)
      c->signal = signal;
   return c;
}
expfun continuous_assign setExpr(expression expr,
                                 continuous_assign c)
{
   if (c != NULL)
      c->expr = expr;
   return c;
}
expfun bool hasSignal(continuous_assign c)
{
   if (getSignal(c) != NULL)
      return true;
   else
      return false;
}
expfun bool hasExpr(continuous_assign c)
{
   if (getExpr(c) != NULL)
      return true;
   else
      return false;
}
expfun continuous_assign copy(continuous_assign src,
                              size_t level = 0)
{
   continuous_assign c;

   if (src == NULL)
      return NULL;
   else
   {
      c = (continuous_assign) malloc (sizeof(continuous_assign_struct));
      if (c != NULL)
      {
         if (level > 0)
         {
            c->signal = copy(src->signal, level - 1);
            c->expr = copy(src->expr, level - 1);
         }
         else
         {
            c->signal = src->signal;
            c->expr = src->expr;
         }
      }
      else
         malloc_error("copy()");

      return c;
   }
}
expfun continuous_assign deepCopy(continuous_assign src)
{
   continuous_assign c;

   if (src == NULL)
      return NULL;
   else
   {
      c = (continuous_assign) malloc (sizeof(continuous_assign_struct));
      if (c != NULL)
      {
         c->signal = deepCopy(src->signal);
         c->expr = deepCopy(src->expr);
      }
      else
         malloc_error("deepCopy()");

      return c;
   }
}
expfun void dump(text Offset,
                 continuous_assign c,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (c == NULL)
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

      if (hasSignal(c) || showEmpty)
      {
         fprintf(fp, "%ssimple_signal signal,\n", new_Offset);
         dump(new_Offset, c->signal, fp, showEmpty);
         fprintf(fp, "%s\\end simple_signal\n", new_Offset);
      }

      if (hasExpr(c) || showEmpty)
      {
         fprintf(fp, "%sexpression expr,\n", new_Offset);
         dump(new_Offset, c->expr, fp, showEmpty);
         fprintf(fp, "%s\\end expression\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(continuous_assign c,
                 size_t level = 0)
{
   if (c ne NULL)
   {
      if (level > 0)
      {

         Free(c->signal, level - 1);
         c->signal = NULL;

         Free(c->expr, level - 1);
         c->expr = NULL;
      }


      free((void *) c);
   }
}
expfun void deepFree(continuous_assign c)
{
   if (c ne NULL)
   {

      deepFree(c->signal);
      c->signal = NULL;

      deepFree(c->expr);
      c->expr = NULL;

      free((void *) c);
   }
}
