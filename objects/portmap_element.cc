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

#define portmap_element_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "signal_list.h"
#include "portmap_element.h"


expfun portmap_element portmap_elementNew(vname pinName = NULL,
                                          signal_list signals = NULL)
{
   portmap_element p = (portmap_element) malloc (sizeof(portmap_element_struct));
   if (p != NULL)
   {
      p->pinName = pinName;
      p->signals = signals;
   }
   else
      malloc_error("portmap_elementNew()");

   return p;
}
expfun bool eqSelfPinName(vname pinName,
                          portmap_element p)
{
   if ((pinName == NULL) || (hasPinName(p) == false))
      return false;
   else if (eqSelf(pinName, getPinName(p)))
      return true;
   else
      return false;
}
expfun bool eqPinName(vname pinName,
                      portmap_element p)
{
   if ((pinName == NULL) || (hasPinName(p) == false))
      return false;
   else if (Eq(pinName, getPinName(p)))
      return true;
   else
      return false;
}
expfun bool eqSelfSignals(signal_list signals,
                          portmap_element p)
{
   if ((signals == NULL) || (hasSignals(p) == false))
      return false;
   else if (eqSelf(signals, getSignals(p)))
      return true;
   else
      return false;
}
expfun bool eqSignals(signal_list signals,
                      portmap_element p)
{
   if ((signals == NULL) || (hasSignals(p) == false))
      return false;
   else if (Eq(signals, getSignals(p)))
      return true;
   else
      return false;
}
expfun bool eqSelf(portmap_element a,
                   portmap_element b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(portmap_element a,
               portmap_element b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqPinName(getPinName(a), b) == false)
      return false;
   else if (eqSignals(getSignals(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getPinName(portmap_element p)
{
   if (p != NULL)
      return p->pinName;
   else
      return NULL;
}
expfun signal_list getSignals(portmap_element p)
{
   if (p != NULL)
      return p->signals;
   else
      return NULL;
}
expfun portmap_element setPinName(vname pinName,
                                  portmap_element p)
{
   if (p != NULL)
      p->pinName = pinName;
   return p;
}
expfun portmap_element setSignals(signal_list signals,
                                  portmap_element p)
{
   if (p != NULL)
      p->signals = signals;
   return p;
}
expfun bool hasPinName(portmap_element p)
{
   if (getPinName(p) != NULL)
      return true;
   else
      return false;
}
expfun bool hasSignals(portmap_element p)
{
   if (isEmpty(getSignals(p)) == false)
      return true;
   else
      return false;
}
expfun portmap_element copy(portmap_element src,
                            size_t level = 0)
{
   portmap_element p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (portmap_element) malloc (sizeof(portmap_element_struct));
      if (p != NULL)
      {
         if (level > 0)
         {
            p->pinName = copy(src->pinName, level - 1);
            p->signals = copy(src->signals, level - 1);
         }
         else
         {
            p->pinName = src->pinName;
            p->signals = src->signals;
         }
      }
      else
         malloc_error("copy()");

      return p;
   }
}
expfun portmap_element deepCopy(portmap_element src)
{
   portmap_element p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (portmap_element) malloc (sizeof(portmap_element_struct));
      if (p != NULL)
      {
         p->pinName = deepCopy(src->pinName);
         p->signals = deepCopy(src->signals);
      }
      else
         malloc_error("deepCopy()");

      return p;
   }
}
expfun void dump(text Offset,
                 portmap_element p,
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

      if (hasPinName(p) || showEmpty)
      {
         fprintf(fp, "%svname pinName,\n", new_Offset);
         dump(new_Offset, p->pinName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasSignals(p) || showEmpty)
      {
         fprintf(fp, "%ssignal_list signals,\n", new_Offset);
         dump(new_Offset, p->signals, fp, showEmpty);
         fprintf(fp, "%s\\end signal_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(portmap_element p,
                 size_t level = 0)
{
   if (p ne NULL)
   {
      if (level > 0)
      {

         Free(p->pinName, level - 1);
         p->pinName = NULL;

         Free(p->signals, level - 1);
         p->signals = NULL;
      }


      free((void *) p);
   }
}
expfun void deepFree(portmap_element p)
{
   if (p ne NULL)
   {

      deepFree(p->pinName);
      p->pinName = NULL;

      deepFree(p->signals);
      p->signals = NULL;

      free((void *) p);
   }
}
