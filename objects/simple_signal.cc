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

#define simple_signal_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "range.h"
#include "simple_signal.h"


expfun simple_signal simple_signalNew(int cnst = -1,
                                      vname name = NULL,
                                      int busIndex = -1,
                                      range rnge = NULL)
{
   simple_signal s = (simple_signal) malloc (sizeof(simple_signal_struct));
   if (s != NULL)
   {
      s->cnst = cnst;
      s->name = name;
      s->busIndex = busIndex;
      s->rnge = rnge;
   }
   else
      malloc_error("simple_signalNew()");

   return s;
}
expfun bool eqCnst(int cnst,
                   simple_signal s)
{
   if (hasCnst(s) == false)
      return false;
   else if (cnst == getCnst(s))
      return true;
   else
      return false;
}
expfun bool eqSelfName(vname name,
                       simple_signal s)
{
   if ((name == NULL) || (hasName(s) == false))
      return false;
   else if (eqSelf(name, getName(s)))
      return true;
   else
      return false;
}
expfun bool eqName(vname name,
                   simple_signal s)
{
   if ((name == NULL) || (hasName(s) == false))
      return false;
   else if (Eq(name, getName(s)))
      return true;
   else
      return false;
}
expfun bool eqBusIndex(int busIndex,
                       simple_signal s)
{
   if (hasBusIndex(s) == false)
      return false;
   else if (busIndex == getBusIndex(s))
      return true;
   else
      return false;
}
expfun bool eqSelfRnge(range rnge,
                       simple_signal s)
{
   if ((rnge == NULL) || (hasRnge(s) == false))
      return false;
   else if (eqSelf(rnge, getRnge(s)))
      return true;
   else
      return false;
}
expfun bool eqRnge(range rnge,
                   simple_signal s)
{
   if ((rnge == NULL) || (hasRnge(s) == false))
      return false;
   else if (Eq(rnge, getRnge(s)))
      return true;
   else
      return false;
}
expfun bool eqSelf(simple_signal a,
                   simple_signal b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(simple_signal a,
               simple_signal b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqCnst(getCnst(a), b) == false)
      return false;
   else if (eqName(getName(a), b) == false)
      return false;
   else if (eqBusIndex(getBusIndex(a), b) == false)
      return false;
   else if (eqRnge(getRnge(a), b) == false)
      return false;
   else
      return true;
}
expfun int getCnst(simple_signal s)
{
   if (s != NULL)
      return s->cnst;
   else
      return -1;
}
expfun vname getName(simple_signal s)
{
   if (s != NULL)
      return s->name;
   else
      return NULL;
}
expfun int getBusIndex(simple_signal s)
{
   if (s != NULL)
      return s->busIndex;
   else
      return -1;
}
expfun range getRnge(simple_signal s)
{
   if (s != NULL)
      return s->rnge;
   else
      return NULL;
}
expfun simple_signal setCnst(int cnst,
                             simple_signal s)
{
   if (s != NULL)
      s->cnst = cnst;
   return s;
}
expfun simple_signal setName(vname name,
                             simple_signal s)
{
   if (s != NULL)
      s->name = name;
   return s;
}
expfun simple_signal setBusIndex(int busIndex,
                                 simple_signal s)
{
   if (s != NULL)
      s->busIndex = busIndex;
   return s;
}
expfun simple_signal setRnge(range rnge,
                             simple_signal s)
{
   if (s != NULL)
      s->rnge = rnge;
   return s;
}
expfun bool hasCnst(simple_signal s)
{
   if (getCnst(s) != -1)
      return true;
   else
      return false;
}
expfun bool hasName(simple_signal s)
{
   if (getName(s) != NULL)
      return true;
   else
      return false;
}
expfun bool hasBusIndex(simple_signal s)
{
   if (getBusIndex(s) != -1)
      return true;
   else
      return false;
}
expfun bool hasRnge(simple_signal s)
{
   if (getRnge(s) != NULL)
      return true;
   else
      return false;
}
expfun simple_signal copy(simple_signal src,
                          size_t level = 0)
{
   simple_signal s;

   if (src == NULL)
      return NULL;
   else
   {
      s = (simple_signal) malloc (sizeof(simple_signal_struct));
      if (s != NULL)
      {
         if (level > 0)
         {
            s->cnst = src->cnst;
            s->name = copy(src->name, level - 1);
            s->busIndex = src->busIndex;
            s->rnge = copy(src->rnge);
         }
         else
         {
            s->cnst = src->cnst;
            s->name = src->name;
            s->busIndex = src->busIndex;
            s->rnge = src->rnge;
         }
      }
      else
         malloc_error("copy()");

      return s;
   }
}
expfun simple_signal deepCopy(simple_signal src)
{
   simple_signal s;

   if (src == NULL)
      return NULL;
   else
   {
      s = (simple_signal) malloc (sizeof(simple_signal_struct));
      if (s != NULL)
      {
         s->cnst = src->cnst;
         s->name = deepCopy(src->name);
         s->busIndex = src->busIndex;
         s->rnge = copy(src->rnge);
      }
      else
         malloc_error("deepCopy()");

      return s;
   }
}
expfun void dump(text Offset,
                 simple_signal s,
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

      if (hasCnst(s) || showEmpty)
         fprintf(fp, "%sint cnst : %d\n", new_Offset, getCnst(s));

      if (hasName(s) || showEmpty)
      {
         fprintf(fp, "%svname name,\n", new_Offset);
         dump(new_Offset, s->name, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasBusIndex(s) || showEmpty)
         fprintf(fp, "%sint busIndex : %d\n", new_Offset, getBusIndex(s));

      if (hasRnge(s) || showEmpty)
      {
         fprintf(fp, "%srange rnge,\n", new_Offset);
         dump(new_Offset, s->rnge, fp, showEmpty);
         fprintf(fp, "%s\\end range\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(simple_signal s,
                 size_t level = 0)
{
   if (s ne NULL)
   {
      if (level > 0)
      {

         Free(s->name, level - 1);
         s->name = NULL;

         Free(s->rnge);
         s->rnge = NULL;
      }


      free((void *) s);
   }
}
expfun void deepFree(simple_signal s)
{
   if (s ne NULL)
   {

      deepFree(s->name);
      s->name = NULL;

      Free(s->rnge);
      s->rnge = NULL;

      free((void *) s);
   }
}
