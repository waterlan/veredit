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

#define expression_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "Signal.h"
#include "expression.h"


expfun expression expressionNew(int number = -1,
                                Signal signal = NULL,
                                text string = NULL)
{
   expression e = (expression) malloc (sizeof(expression_struct));
   if (e != NULL)
   {
      e->number = number;
      e->signal = signal;
      e->string = string;
   }
   else
      malloc_error("expressionNew()");

   return e;
}
expfun bool eqNumber(int number,
                     expression e)
{
   if (hasNumber(e) == false)
      return false;
   else if (number == getNumber(e))
      return true;
   else
      return false;
}
expfun bool eqSelfSignal(Signal signal,
                         expression e)
{
   if ((signal == NULL) || (hasSignal(e) == false))
      return false;
   else if (eqSelf(signal, getSignal(e)))
      return true;
   else
      return false;
}
expfun bool eqSignal(Signal signal,
                     expression e)
{
   if ((signal == NULL) || (hasSignal(e) == false))
      return false;
   else if (Eq(signal, getSignal(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfString(text string,
                         expression e)
{
   if ((string == NULL) || (hasString(e) == false))
      return false;
   else if (eqSelf(string, getString(e)))
      return true;
   else
      return false;
}
expfun bool eqString(text string,
                     expression e)
{
   if ((string == NULL) || (hasString(e) == false))
      return false;
   else if (Eq(string, getString(e)))
      return true;
   else
      return false;
}
expfun bool eqSelf(expression a,
                   expression b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(expression a,
               expression b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqNumber(getNumber(a), b) == false)
      return false;
   else if (eqSignal(getSignal(a), b) == false)
      return false;
   else if (eqString(getString(a), b) == false)
      return false;
   else
      return true;
}
expfun int getNumber(expression e)
{
   if (e != NULL)
      return e->number;
   else
      return -1;
}
expfun Signal getSignal(expression e)
{
   if (e != NULL)
      return e->signal;
   else
      return NULL;
}
expfun text getString(expression e)
{
   if (e != NULL)
      return e->string;
   else
      return NULL;
}
expfun expression setNumber(int number,
                            expression e)
{
   if (e != NULL)
      e->number = number;
   return e;
}
expfun expression setSignal(Signal signal,
                            expression e)
{
   if (e != NULL)
      e->signal = signal;
   return e;
}
expfun expression setString(text string,
                            expression e)
{
   if (e != NULL)
      e->string = string;
   return e;
}
expfun bool hasNumber(expression e)
{
   if (getNumber(e) != -1)
      return true;
   else
      return false;
}
expfun bool hasSignal(expression e)
{
   if (getSignal(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasString(expression e)
{
   if (getString(e) != NULL)
      return true;
   else
      return false;
}
expfun expression copy(expression src,
                       size_t level = 0)
{
   expression e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (expression) malloc (sizeof(expression_struct));
      if (e != NULL)
      {
         if (level > 0)
         {
            e->number = src->number;
            e->signal = copy(src->signal, level - 1);
            e->string = textNew(src->string);
         }
         else
         {
            e->number = src->number;
            e->signal = src->signal;
            e->string = src->string;
         }
      }
      else
         malloc_error("copy()");

      return e;
   }
}
expfun expression deepCopy(expression src)
{
   expression e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (expression) malloc (sizeof(expression_struct));
      if (e != NULL)
      {
         e->number = src->number;
         e->signal = deepCopy(src->signal);
         e->string = textNew(src->string);
      }
      else
         malloc_error("deepCopy()");

      return e;
   }
}
expfun void dump(text Offset,
                 expression e,
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

      if (hasNumber(e) || showEmpty)
         fprintf(fp, "%sint number : %d\n", new_Offset, getNumber(e));

      if (hasSignal(e) || showEmpty)
      {
         fprintf(fp, "%sSignal signal,\n", new_Offset);
         dump(new_Offset, e->signal, fp, showEmpty);
         fprintf(fp, "%s\\end Signal\n", new_Offset);
      }

      if (hasString(e) || showEmpty)
      {
         if (e->string ne NULL)
            fprintf(fp, "%stext string : %s\n", new_Offset, e->string);
         else if (showEmpty)
            fprintf(fp, "%stext string : NULL\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(expression e,
                 size_t level = 0)
{
   if (e ne NULL)
   {
      if (level > 0)
      {

         Free(e->signal, level - 1);
         e->signal = NULL;

         if (e->string ne NULL)
         {
            free((void *) e->string);
            e->string = NULL;
         }
      }


      free((void *) e);
   }
}
expfun void deepFree(expression e)
{
   if (e ne NULL)
   {

      deepFree(e->signal);
      e->signal = NULL;

      if (e->string ne NULL)
      {
         free((void *) e->string);
         e->string = NULL;
      }

      free((void *) e);
   }
}
