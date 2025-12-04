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

#define text_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "arithmetic.h"
#include "nameset.h"


expfun rwtext rwtextNew(size_t size)
{
   rwtext buffer = NULL;

   if (size > 0)
   {
      buffer = (rwtext) malloc (sizeof(char) * size);
      if (buffer eq NULL)
         malloc_error("rwtextNew(size)");
   }

   return buffer;
}
expfun text textNew(size_t size)
{
   return rwtextNew(size);
}
expfun rwtext rwtextNew(text string)
{
   rwtext buffer = NULL;

   if (string ne NULL)
   {
      buffer = rwtextNew(strlen(string) + 1);
      if (buffer ne NULL)
         strcpy(buffer, string);
      else
         malloc_error("rwtextNew(text)");
   }

   return buffer;
}
expfun text textNew(text string)
{
   return rwtextNew(string);
}
expfun bool Eq(text a,
               text b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (strcmp(a, b) == 0)
      return true;
   else
      return false;
}
expfun bool eqSelf(text a,
                   text b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun text concat(text a,
                   text b)
{
   rwtext res = (rwtext) malloc(sizeof(char) * (strlen(a) + strlen(b) + 1));
   if (res ne NULL)
   {
      strcpy(res, a);
      strcpy(res + strlen(res), b);
   }
   else
      malloc_error("concat()");


   return res;
}
expfun text concat(text a,
                   text b,
                   text c)
{
   rwtext res = (rwtext) malloc(sizeof(char) * (strlen(a) + strlen(b) + strlen(c) + 1));
   if (res ne NULL)
   {
      strcpy(res, a);
      strcpy(res + strlen(res), b);
      strcpy(res + strlen(res), c);
   }
   else
      malloc_error("concat()");


   return res;
}
expfun text concat(text a,
                   text b,
                   text c,
                   text d)
{
   rwtext res = (rwtext) malloc(sizeof(char) * (strlen(a) + strlen(b) + strlen(c) + strlen(d) + 1));
   if (res ne NULL)
   {
      strcpy(res, a);
      strcpy(res + strlen(res), b);
      strcpy(res + strlen(res), c);
      strcpy(res + strlen(res), d);
   }
   else
      malloc_error("concat()");


   return res;
}
expfun text repeat(text pattern,
                   size_t amount,
                   int bufferNr = -1)
{
   size_t count = 0;
   static nameset buffers = NULL;
   rwtext buffer = NULL;

   if (buffers eq NULL)
      buffers = namesetNew();

   amount = limitNeg(amount, 0);

   if (bufferNr >= 0)
      buffer = (rwtext) elementAt((size_t) bufferNr, buffers);

   if (buffer eq NULL)
      buffer = rwtextNew(strlen(pattern) * amount + 1);
   else
      buffer = (rwtext) realloc((void *) buffer, sizeof(char) * (strlen(pattern) * amount + 1));

   if (buffer != NULL)
   {
      if (bufferNr >= 0)
         put(buffer, (size_t) bufferNr, buffers);

      buffer[0] = '\0';
      while(count < amount)
      {
         strcpy(buffer + strlen(buffer), pattern);
         count = count + 1;
      }
   }
   else
      malloc_error("repeat(pattern, amount, bufferNr)");

   return buffer;
}
expfun text Spaces(size_t amount,
                   int bufferNr = 0)
{
   return repeat(" ", amount, bufferNr);
}
expfun text Tab(size_t amount,
                int bufferNr = 0)
{
   size_t tabSize = 3;
   return Spaces(tabSize*amount, bufferNr);
}
expfun text toString(int i)
{
   char buffer[100];
   sprintf(buffer, "%d", i);
   return rwtextNew((rwtext) buffer);
}
expfun text toString(double d)
{
   char buffer[100];
   sprintf(buffer, "%g", d);
   return rwtextNew((rwtext) buffer);
}
expfun text toString(size_t s)
{
   char buffer[100];
   sprintf(buffer, "%zu", s);
   return rwtextNew((rwtext) buffer);
}
expfun text toString(ssize_t s)
{
   char buffer[100];
   sprintf(buffer, "%zd", s);
   return rwtextNew((rwtext) buffer);
}
