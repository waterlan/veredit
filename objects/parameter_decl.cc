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

#define parameter_decl_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "simple_signal.h"
#include "expression.h"
#include "parameter_decl.h"


expfun parameter_decl parameter_declNew(simple_signal signal = NULL,
                                        expression expr = NULL)
{
   parameter_decl p = (parameter_decl) malloc (sizeof(parameter_decl_struct));
   if (p != NULL)
   {
      p->signal = signal;
      p->expr = expr;
   }
   else
      malloc_error("parameter_declNew()");

   return p;
}
expfun bool eqSelfSignal(simple_signal signal,
                         parameter_decl p)
{
   if ((signal == NULL) || (hasSignal(p) == false))
      return false;
   else if (eqSelf(signal, getSignal(p)))
      return true;
   else
      return false;
}
expfun bool eqSignal(simple_signal signal,
                     parameter_decl p)
{
   if ((signal == NULL) || (hasSignal(p) == false))
      return false;
   else if (Eq(signal, getSignal(p)))
      return true;
   else
      return false;
}
expfun bool eqSelfExpr(expression expr,
                       parameter_decl p)
{
   if ((expr == NULL) || (hasExpr(p) == false))
      return false;
   else if (eqSelf(expr, getExpr(p)))
      return true;
   else
      return false;
}
expfun bool eqExpr(expression expr,
                   parameter_decl p)
{
   if ((expr == NULL) || (hasExpr(p) == false))
      return false;
   else if (Eq(expr, getExpr(p)))
      return true;
   else
      return false;
}
expfun bool eqSelf(parameter_decl a,
                   parameter_decl b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(parameter_decl a,
               parameter_decl b)
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
expfun simple_signal getSignal(parameter_decl p)
{
   if (p != NULL)
      return p->signal;
   else
      return NULL;
}
expfun expression getExpr(parameter_decl p)
{
   if (p != NULL)
      return p->expr;
   else
      return NULL;
}
expfun parameter_decl setSignal(simple_signal signal,
                                parameter_decl p)
{
   if (p != NULL)
      p->signal = signal;
   return p;
}
expfun parameter_decl setExpr(expression expr,
                              parameter_decl p)
{
   if (p != NULL)
      p->expr = expr;
   return p;
}
expfun bool hasSignal(parameter_decl p)
{
   if (getSignal(p) != NULL)
      return true;
   else
      return false;
}
expfun bool hasExpr(parameter_decl p)
{
   if (getExpr(p) != NULL)
      return true;
   else
      return false;
}
expfun parameter_decl copy(parameter_decl src,
                           size_t level = 0)
{
   parameter_decl p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (parameter_decl) malloc (sizeof(parameter_decl_struct));
      if (p != NULL)
      {
         if (level > 0)
         {
            p->signal = copy(src->signal, level - 1);
            p->expr = copy(src->expr, level - 1);
         }
         else
         {
            p->signal = src->signal;
            p->expr = src->expr;
         }
      }
      else
         malloc_error("copy()");

      return p;
   }
}
expfun parameter_decl deepCopy(parameter_decl src)
{
   parameter_decl p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (parameter_decl) malloc (sizeof(parameter_decl_struct));
      if (p != NULL)
      {
         p->signal = deepCopy(src->signal);
         p->expr = deepCopy(src->expr);
      }
      else
         malloc_error("deepCopy()");

      return p;
   }
}
expfun void dump(text Offset,
                 parameter_decl p,
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

      if (hasSignal(p) || showEmpty)
      {
         fprintf(fp, "%ssimple_signal signal,\n", new_Offset);
         dump(new_Offset, p->signal, fp, showEmpty);
         fprintf(fp, "%s\\end simple_signal\n", new_Offset);
      }

      if (hasExpr(p) || showEmpty)
      {
         fprintf(fp, "%sexpression expr,\n", new_Offset);
         dump(new_Offset, p->expr, fp, showEmpty);
         fprintf(fp, "%s\\end expression\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(parameter_decl p,
                 size_t level = 0)
{
   if (p ne NULL)
   {
      if (level > 0)
      {

         Free(p->signal, level - 1);
         p->signal = NULL;

         Free(p->expr, level - 1);
         p->expr = NULL;
      }


      free((void *) p);
   }
}
expfun void deepFree(parameter_decl p)
{
   if (p ne NULL)
   {

      deepFree(p->signal);
      p->signal = NULL;

      deepFree(p->expr);
      p->expr = NULL;

      free((void *) p);
   }
}
