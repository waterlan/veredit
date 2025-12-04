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

#define dot_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "dot.h"


expfun dot dotNew(text parent = NULL,
                  text child = NULL,
                  int times = 0)
{
   dot d = (dot) malloc (sizeof(dot_struct));
   if (d != NULL)
   {
      d->parent = parent;
      d->child = child;
      d->times = times;
   }
   else
      malloc_error("dotNew()");

   return d;
}
expfun bool eqSelfParent(text parent,
                         dot d)
{
   if ((parent == NULL) || (hasParent(d) == false))
      return false;
   else if (eqSelf(parent, getParent(d)))
      return true;
   else
      return false;
}
expfun bool eqParent(text parent,
                     dot d)
{
   if ((parent == NULL) || (hasParent(d) == false))
      return false;
   else if (Eq(parent, getParent(d)))
      return true;
   else
      return false;
}
expfun bool eqSelfChild(text child,
                        dot d)
{
   if ((child == NULL) || (hasChild(d) == false))
      return false;
   else if (eqSelf(child, getChild(d)))
      return true;
   else
      return false;
}
expfun bool eqChild(text child,
                    dot d)
{
   if ((child == NULL) || (hasChild(d) == false))
      return false;
   else if (Eq(child, getChild(d)))
      return true;
   else
      return false;
}
expfun bool eqTimes(int times,
                    dot d)
{
   if (hasTimes(d) == false)
      return false;
   else if (times == getTimes(d))
      return true;
   else
      return false;
}
expfun bool eqSelf(dot a,
                   dot b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(dot a,
               dot b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqParent(getParent(a), b) == false)
      return false;
   else if (eqChild(getChild(a), b) == false)
      return false;
   else if (eqTimes(getTimes(a), b) == false)
      return false;
   else
      return true;
}
expfun text getParent(dot d)
{
   if (d != NULL)
      return d->parent;
   else
      return NULL;
}
expfun text getChild(dot d)
{
   if (d != NULL)
      return d->child;
   else
      return NULL;
}
expfun int getTimes(dot d)
{
   if (d != NULL)
      return d->times;
   else
      return 0;
}
expfun dot setParent(text parent,
                     dot d)
{
   if (d != NULL)
      d->parent = parent;
   return d;
}
expfun dot setChild(text child,
                    dot d)
{
   if (d != NULL)
      d->child = child;
   return d;
}
expfun dot setTimes(int times,
                    dot d)
{
   if (d != NULL)
      d->times = times;
   return d;
}
expfun bool hasParent(dot d)
{
   if (getParent(d) != NULL)
      return true;
   else
      return false;
}
expfun bool hasChild(dot d)
{
   if (getChild(d) != NULL)
      return true;
   else
      return false;
}
expfun bool hasTimes(dot d)
{
   if (getTimes(d) != 0)
      return true;
   else
      return false;
}
expfun dot copy(dot src,
                size_t level = 0)
{
   dot d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (dot) malloc (sizeof(dot_struct));
      if (d != NULL)
      {
         if (level > 0)
         {
            d->parent = textNew(src->parent);
            d->child = textNew(src->child);
            d->times = src->times;
         }
         else
         {
            d->parent = src->parent;
            d->child = src->child;
            d->times = src->times;
         }
      }
      else
         malloc_error("copy()");

      return d;
   }
}
expfun dot deepCopy(dot src)
{
   dot d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (dot) malloc (sizeof(dot_struct));
      if (d != NULL)
      {
         d->parent = textNew(src->parent);
         d->child = textNew(src->child);
         d->times = src->times;
      }
      else
         malloc_error("deepCopy()");

      return d;
   }
}
expfun void dump(text Offset,
                 dot d,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (d == NULL)
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

      if (hasParent(d) || showEmpty)
      {
         if (d->parent ne NULL)
            fprintf(fp, "%stext parent : %s\n", new_Offset, d->parent);
         else if (showEmpty)
            fprintf(fp, "%stext parent : NULL\n", new_Offset);
      }

      if (hasChild(d) || showEmpty)
      {
         if (d->child ne NULL)
            fprintf(fp, "%stext child : %s\n", new_Offset, d->child);
         else if (showEmpty)
            fprintf(fp, "%stext child : NULL\n", new_Offset);
      }

      if (hasTimes(d) || showEmpty)
         fprintf(fp, "%sint times : %d\n", new_Offset, getTimes(d));

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(dot d,
                 size_t level = 0)
{
   if (d ne NULL)
   {
      if (level > 0)
      {

         if (d->parent ne NULL)
         {
            free((void *) d->parent);
            d->parent = NULL;
         }

         if (d->child ne NULL)
         {
            free((void *) d->child);
            d->child = NULL;
         }
      }


      free((void *) d);
   }
}
expfun void deepFree(dot d)
{
   if (d ne NULL)
   {

      if (d->parent ne NULL)
      {
         free((void *) d->parent);
         d->parent = NULL;
      }

      if (d->child ne NULL)
      {
         free((void *) d->child);
         d->child = NULL;
      }

      free((void *) d);
   }
}
