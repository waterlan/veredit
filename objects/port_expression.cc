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

#define port_expression_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "port_reference.h"
#include "compound_port_reference.h"
#include "port_expression.h"


expfun port_expression port_expressionNew(port_reference portReference = NULL,
                                          compound_port_reference cmpnd = NULL)
{
   port_expression p = (port_expression) malloc (sizeof(port_expression_struct));
   if (p != NULL)
   {
      p->portReference = portReference;
      p->cmpnd = cmpnd;
   }
   else
      malloc_error("port_expressionNew()");

   return p;
}
expfun bool eqSelfPortReference(port_reference portReference,
                                port_expression p)
{
   if ((portReference == NULL) || (hasPortReference(p) == false))
      return false;
   else if (eqSelf(portReference, getPortReference(p)))
      return true;
   else
      return false;
}
expfun bool eqPortReference(port_reference portReference,
                            port_expression p)
{
   if ((portReference == NULL) || (hasPortReference(p) == false))
      return false;
   else if (Eq(portReference, getPortReference(p)))
      return true;
   else
      return false;
}
expfun bool eqSelfCmpnd(compound_port_reference cmpnd,
                        port_expression p)
{
   if ((cmpnd == NULL) || (hasCmpnd(p) == false))
      return false;
   else if (eqSelf(cmpnd, getCmpnd(p)))
      return true;
   else
      return false;
}
expfun bool eqCmpnd(compound_port_reference cmpnd,
                    port_expression p)
{
   if ((cmpnd == NULL) || (hasCmpnd(p) == false))
      return false;
   else if (Eq(cmpnd, getCmpnd(p)))
      return true;
   else
      return false;
}
expfun bool eqSelf(port_expression a,
                   port_expression b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(port_expression a,
               port_expression b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqPortReference(getPortReference(a), b) == false)
      return false;
   else if (eqCmpnd(getCmpnd(a), b) == false)
      return false;
   else
      return true;
}
expfun port_reference getPortReference(port_expression p)
{
   if (p != NULL)
      return p->portReference;
   else
      return NULL;
}
expfun compound_port_reference getCmpnd(port_expression p)
{
   if (p != NULL)
      return p->cmpnd;
   else
      return NULL;
}
expfun port_expression setPortReference(port_reference portReference,
                                        port_expression p)
{
   if (p != NULL)
      p->portReference = portReference;
   return p;
}
expfun port_expression setCmpnd(compound_port_reference cmpnd,
                                port_expression p)
{
   if (p != NULL)
      p->cmpnd = cmpnd;
   return p;
}
expfun bool hasPortReference(port_expression p)
{
   if (getPortReference(p) != NULL)
      return true;
   else
      return false;
}
expfun bool hasCmpnd(port_expression p)
{
   if (getCmpnd(p) != NULL)
      return true;
   else
      return false;
}
expfun port_expression copy(port_expression src,
                            size_t level = 0)
{
   port_expression p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (port_expression) malloc (sizeof(port_expression_struct));
      if (p != NULL)
      {
         if (level > 0)
         {
            p->portReference = copy(src->portReference, level - 1);
            p->cmpnd = copy(src->cmpnd, level - 1);
         }
         else
         {
            p->portReference = src->portReference;
            p->cmpnd = src->cmpnd;
         }
      }
      else
         malloc_error("copy()");

      return p;
   }
}
expfun port_expression deepCopy(port_expression src)
{
   port_expression p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (port_expression) malloc (sizeof(port_expression_struct));
      if (p != NULL)
      {
         p->portReference = deepCopy(src->portReference);
         p->cmpnd = deepCopy(src->cmpnd);
      }
      else
         malloc_error("deepCopy()");

      return p;
   }
}
expfun void dump(text Offset,
                 port_expression p,
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

      if (hasPortReference(p) || showEmpty)
      {
         fprintf(fp, "%sport_reference portReference,\n", new_Offset);
         dump(new_Offset, p->portReference, fp, showEmpty);
         fprintf(fp, "%s\\end port_reference\n", new_Offset);
      }

      if (hasCmpnd(p) || showEmpty)
      {
         fprintf(fp, "%scompound_port_reference cmpnd,\n", new_Offset);
         dump(new_Offset, p->cmpnd, fp, showEmpty);
         fprintf(fp, "%s\\end compound_port_reference\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(port_expression p,
                 size_t level = 0)
{
   if (p ne NULL)
   {
      if (level > 0)
      {

         Free(p->portReference, level - 1);
         p->portReference = NULL;

         Free(p->cmpnd, level - 1);
         p->cmpnd = NULL;
      }


      free((void *) p);
   }
}
expfun void deepFree(port_expression p)
{
   if (p ne NULL)
   {

      deepFree(p->portReference);
      p->portReference = NULL;

      deepFree(p->cmpnd);
      p->cmpnd = NULL;

      free((void *) p);
   }
}
