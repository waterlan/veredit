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

#define port_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "port_expression.h"
#include "vname.h"
#include "port.h"


expfun port portNew(port_expression portExpression = NULL,
                    vname portName = NULL,
                    port_expression portExpression2 = NULL)
{
   port p = (port) malloc (sizeof(port_struct));
   if (p != NULL)
   {
      p->portExpression = portExpression;
      p->portName = portName;
      p->portExpression2 = portExpression2;
   }
   else
      malloc_error("portNew()");

   return p;
}
expfun bool eqSelfPortExpression(port_expression portExpression,
                                 port p)
{
   if ((portExpression == NULL) || (hasPortExpression(p) == false))
      return false;
   else if (eqSelf(portExpression, getPortExpression(p)))
      return true;
   else
      return false;
}
expfun bool eqPortExpression(port_expression portExpression,
                             port p)
{
   if ((portExpression == NULL) || (hasPortExpression(p) == false))
      return false;
   else if (Eq(portExpression, getPortExpression(p)))
      return true;
   else
      return false;
}
expfun bool eqSelfPortName(vname portName,
                           port p)
{
   if ((portName == NULL) || (hasPortName(p) == false))
      return false;
   else if (eqSelf(portName, getPortName(p)))
      return true;
   else
      return false;
}
expfun bool eqPortName(vname portName,
                       port p)
{
   if ((portName == NULL) || (hasPortName(p) == false))
      return false;
   else if (Eq(portName, getPortName(p)))
      return true;
   else
      return false;
}
expfun bool eqSelfPortExpression2(port_expression portExpression2,
                                  port p)
{
   if ((portExpression2 == NULL) || (hasPortExpression2(p) == false))
      return false;
   else if (eqSelf(portExpression2, getPortExpression2(p)))
      return true;
   else
      return false;
}
expfun bool eqPortExpression2(port_expression portExpression2,
                              port p)
{
   if ((portExpression2 == NULL) || (hasPortExpression2(p) == false))
      return false;
   else if (Eq(portExpression2, getPortExpression2(p)))
      return true;
   else
      return false;
}
expfun bool eqSelf(port a,
                   port b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(port a,
               port b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqPortExpression(getPortExpression(a), b) == false)
      return false;
   else if (eqPortName(getPortName(a), b) == false)
      return false;
   else if (eqPortExpression2(getPortExpression2(a), b) == false)
      return false;
   else
      return true;
}
expfun port_expression getPortExpression(port p)
{
   if (p != NULL)
      return p->portExpression;
   else
      return NULL;
}
expfun vname getPortName(port p)
{
   if (p != NULL)
      return p->portName;
   else
      return NULL;
}
expfun port_expression getPortExpression2(port p)
{
   if (p != NULL)
      return p->portExpression2;
   else
      return NULL;
}
expfun port setPortExpression(port_expression portExpression,
                              port p)
{
   if (p != NULL)
      p->portExpression = portExpression;
   return p;
}
expfun port setPortName(vname portName,
                        port p)
{
   if (p != NULL)
      p->portName = portName;
   return p;
}
expfun port setPortExpression2(port_expression portExpression2,
                               port p)
{
   if (p != NULL)
      p->portExpression2 = portExpression2;
   return p;
}
expfun bool hasPortExpression(port p)
{
   if (getPortExpression(p) != NULL)
      return true;
   else
      return false;
}
expfun bool hasPortName(port p)
{
   if (getPortName(p) != NULL)
      return true;
   else
      return false;
}
expfun bool hasPortExpression2(port p)
{
   if (getPortExpression2(p) != NULL)
      return true;
   else
      return false;
}
expfun port copy(port src,
                 size_t level = 0)
{
   port p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (port) malloc (sizeof(port_struct));
      if (p != NULL)
      {
         if (level > 0)
         {
            p->portExpression = copy(src->portExpression, level - 1);
            p->portName = copy(src->portName, level - 1);
            p->portExpression2 = copy(src->portExpression2, level - 1);
         }
         else
         {
            p->portExpression = src->portExpression;
            p->portName = src->portName;
            p->portExpression2 = src->portExpression2;
         }
      }
      else
         malloc_error("copy()");

      return p;
   }
}
expfun port deepCopy(port src)
{
   port p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (port) malloc (sizeof(port_struct));
      if (p != NULL)
      {
         p->portExpression = deepCopy(src->portExpression);
         p->portName = deepCopy(src->portName);
         p->portExpression2 = deepCopy(src->portExpression2);
      }
      else
         malloc_error("deepCopy()");

      return p;
   }
}
expfun void dump(text Offset,
                 port p,
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

      if (hasPortExpression(p) || showEmpty)
      {
         fprintf(fp, "%sport_expression portExpression,\n", new_Offset);
         dump(new_Offset, p->portExpression, fp, showEmpty);
         fprintf(fp, "%s\\end port_expression\n", new_Offset);
      }

      if (hasPortName(p) || showEmpty)
      {
         fprintf(fp, "%svname portName,\n", new_Offset);
         dump(new_Offset, p->portName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasPortExpression2(p) || showEmpty)
      {
         fprintf(fp, "%sport_expression portExpression2,\n", new_Offset);
         dump(new_Offset, p->portExpression2, fp, showEmpty);
         fprintf(fp, "%s\\end port_expression\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(port p,
                 size_t level = 0)
{
   if (p ne NULL)
   {
      if (level > 0)
      {

         Free(p->portExpression, level - 1);
         p->portExpression = NULL;

         Free(p->portName, level - 1);
         p->portName = NULL;

         Free(p->portExpression2, level - 1);
         p->portExpression2 = NULL;
      }


      free((void *) p);
   }
}
expfun void deepFree(port p)
{
   if (p ne NULL)
   {

      deepFree(p->portExpression);
      p->portExpression = NULL;

      deepFree(p->portName);
      p->portName = NULL;

      deepFree(p->portExpression2);
      p->portExpression2 = NULL;

      free((void *) p);
   }
}
