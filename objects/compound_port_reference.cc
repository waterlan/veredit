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

#define compound_port_reference_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "port_reference_list.h"
#include "compound_port_reference.h"


expfun compound_port_reference compound_port_referenceNew(port_reference_list portReferences = NULL)
{
   compound_port_reference c = (compound_port_reference) malloc (sizeof(compound_port_reference_struct));
   if (c != NULL)
      c->portReferences = portReferences;
   else
      malloc_error("compound_port_referenceNew()");

   return c;
}
expfun bool eqSelfPortReferences(port_reference_list portReferences,
                                 compound_port_reference c)
{
   if ((portReferences == NULL) || (hasPortReferences(c) == false))
      return false;
   else if (eqSelf(portReferences, getPortReferences(c)))
      return true;
   else
      return false;
}
expfun bool eqPortReferences(port_reference_list portReferences,
                             compound_port_reference c)
{
   if ((portReferences == NULL) || (hasPortReferences(c) == false))
      return false;
   else if (Eq(portReferences, getPortReferences(c)))
      return true;
   else
      return false;
}
expfun bool eqSelf(compound_port_reference a,
                   compound_port_reference b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(compound_port_reference a,
               compound_port_reference b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqPortReferences(getPortReferences(a), b) == false)
      return false;
   else
      return true;
}
expfun port_reference_list getPortReferences(compound_port_reference c)
{
   if (c != NULL)
      return c->portReferences;
   else
      return NULL;
}
expfun compound_port_reference setPortReferences(port_reference_list portReferences,
                                                 compound_port_reference c)
{
   if (c != NULL)
      c->portReferences = portReferences;
   return c;
}
expfun bool hasPortReferences(compound_port_reference c)
{
   if (isEmpty(getPortReferences(c)) == false)
      return true;
   else
      return false;
}
expfun compound_port_reference copy(compound_port_reference src,
                                    size_t level = 0)
{
   compound_port_reference c;

   if (src == NULL)
      return NULL;
   else
   {
      c = (compound_port_reference) malloc (sizeof(compound_port_reference_struct));
      if (c != NULL)
      {
         if (level > 0)
            c->portReferences = copy(src->portReferences, level - 1);
         else
            c->portReferences = src->portReferences;
      }
      else
         malloc_error("copy()");

      return c;
   }
}
expfun compound_port_reference deepCopy(compound_port_reference src)
{
   compound_port_reference c;

   if (src == NULL)
      return NULL;
   else
   {
      c = (compound_port_reference) malloc (sizeof(compound_port_reference_struct));
      if (c != NULL)
      {
         c->portReferences = deepCopy(src->portReferences);
      }
      else
         malloc_error("deepCopy()");

      return c;
   }
}
expfun void dump(text Offset,
                 compound_port_reference c,
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

      if (hasPortReferences(c) || showEmpty)
      {
         fprintf(fp, "%sport_reference_list portReferences,\n", new_Offset);
         dump(new_Offset, c->portReferences, fp, showEmpty);
         fprintf(fp, "%s\\end port_reference_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(compound_port_reference c,
                 size_t level = 0)
{
   if (c ne NULL)
   {
      if (level > 0)
      {

         Free(c->portReferences, level - 1);
         c->portReferences = NULL;
      }


      free((void *) c);
   }
}
expfun void deepFree(compound_port_reference c)
{
   if (c ne NULL)
   {

      deepFree(c->portReferences);
      c->portReferences = NULL;

      free((void *) c);
   }
}
