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

#define port_reference_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "range.h"
#include "port_reference.h"


expfun port_reference port_referenceNew(vname name = NULL,
                                        int busIndex = -1,
                                        range rnge = NULL)
{
   port_reference p = (port_reference) malloc (sizeof(port_reference_struct));
   if (p != NULL)
   {
      p->name = name;
      p->busIndex = busIndex;
      p->rnge = rnge;
   }
   else
      malloc_error("port_referenceNew()");

   return p;
}
expfun bool eqSelfName(vname name,
                       port_reference p)
{
   if ((name == NULL) || (hasName(p) == false))
      return false;
   else if (eqSelf(name, getName(p)))
      return true;
   else
      return false;
}
expfun bool eqName(vname name,
                   port_reference p)
{
   if ((name == NULL) || (hasName(p) == false))
      return false;
   else if (Eq(name, getName(p)))
      return true;
   else
      return false;
}
expfun bool eqBusIndex(int busIndex,
                       port_reference p)
{
   if (hasBusIndex(p) == false)
      return false;
   else if (busIndex == getBusIndex(p))
      return true;
   else
      return false;
}
expfun bool eqSelfRnge(range rnge,
                       port_reference p)
{
   if ((rnge == NULL) || (hasRnge(p) == false))
      return false;
   else if (eqSelf(rnge, getRnge(p)))
      return true;
   else
      return false;
}
expfun bool eqRnge(range rnge,
                   port_reference p)
{
   if ((rnge == NULL) || (hasRnge(p) == false))
      return false;
   else if (Eq(rnge, getRnge(p)))
      return true;
   else
      return false;
}
expfun bool eqSelf(port_reference a,
                   port_reference b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(port_reference a,
               port_reference b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqName(getName(a), b) == false)
      return false;
   else if (eqBusIndex(getBusIndex(a), b) == false)
      return false;
   else if (eqRnge(getRnge(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getName(port_reference p)
{
   if (p != NULL)
      return p->name;
   else
      return NULL;
}
expfun int getBusIndex(port_reference p)
{
   if (p != NULL)
      return p->busIndex;
   else
      return -1;
}
expfun range getRnge(port_reference p)
{
   if (p != NULL)
      return p->rnge;
   else
      return NULL;
}
expfun port_reference setName(vname name,
                              port_reference p)
{
   if (p != NULL)
      p->name = name;
   return p;
}
expfun port_reference setBusIndex(int busIndex,
                                  port_reference p)
{
   if (p != NULL)
      p->busIndex = busIndex;
   return p;
}
expfun port_reference setRnge(range rnge,
                              port_reference p)
{
   if (p != NULL)
      p->rnge = rnge;
   return p;
}
expfun bool hasName(port_reference p)
{
   if (getName(p) != NULL)
      return true;
   else
      return false;
}
expfun bool hasBusIndex(port_reference p)
{
   if (getBusIndex(p) != -1)
      return true;
   else
      return false;
}
expfun bool hasRnge(port_reference p)
{
   if (getRnge(p) != NULL)
      return true;
   else
      return false;
}
expfun port_reference copy(port_reference src,
                           size_t level = 0)
{
   port_reference p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (port_reference) malloc (sizeof(port_reference_struct));
      if (p != NULL)
      {
         if (level > 0)
         {
            p->name = copy(src->name, level - 1);
            p->busIndex = src->busIndex;
            p->rnge = copy(src->rnge);
         }
         else
         {
            p->name = src->name;
            p->busIndex = src->busIndex;
            p->rnge = src->rnge;
         }
      }
      else
         malloc_error("copy()");

      return p;
   }
}
expfun port_reference deepCopy(port_reference src)
{
   port_reference p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (port_reference) malloc (sizeof(port_reference_struct));
      if (p != NULL)
      {
         p->name = deepCopy(src->name);
         p->busIndex = src->busIndex;
         p->rnge = copy(src->rnge);
      }
      else
         malloc_error("deepCopy()");

      return p;
   }
}
expfun void dump(text Offset,
                 port_reference p,
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

      if (hasName(p) || showEmpty)
      {
         fprintf(fp, "%svname name,\n", new_Offset);
         dump(new_Offset, p->name, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasBusIndex(p) || showEmpty)
         fprintf(fp, "%sint busIndex : %d\n", new_Offset, getBusIndex(p));

      if (hasRnge(p) || showEmpty)
      {
         fprintf(fp, "%srange rnge,\n", new_Offset);
         dump(new_Offset, p->rnge, fp, showEmpty);
         fprintf(fp, "%s\\end range\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(port_reference p,
                 size_t level = 0)
{
   if (p ne NULL)
   {
      if (level > 0)
      {

         Free(p->name, level - 1);
         p->name = NULL;

         Free(p->rnge);
         p->rnge = NULL;
      }


      free((void *) p);
   }
}
expfun void deepFree(port_reference p)
{
   if (p ne NULL)
   {

      deepFree(p->name);
      p->name = NULL;

      Free(p->rnge);
      p->rnge = NULL;

      free((void *) p);
   }
}
