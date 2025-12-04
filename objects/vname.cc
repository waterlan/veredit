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

#define vname_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"


expfun vname vnameNew(text n = NULL)
{
   vname v = (vname) malloc (sizeof(vname_struct));
   if (v != NULL)
      v->n = n;
   else
      malloc_error("vnameNew()");

   return v;
}
expfun bool eqSelfN(text n,
                    vname v)
{
   if ((n == NULL) || (hasN(v) == false))
      return false;
   else if (eqSelf(n, getN(v)))
      return true;
   else
      return false;
}
expfun bool eqN(text n,
                vname v)
{
   if ((n == NULL) || (hasN(v) == false))
      return false;
   else if (Eq(n, getN(v)))
      return true;
   else
      return false;
}
expfun bool eqSelf(vname a,
                   vname b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(vname a,
               vname b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqN(getN(a), b) == false)
      return false;
   else
      return true;
}
expfun text getN(vname v)
{
   if (v != NULL)
      return v->n;
   else
      return NULL;
}
expfun vname setN(text n,
                  vname v)
{
   if (v != NULL)
      v->n = n;
   return v;
}
expfun bool hasN(vname v)
{
   if (getN(v) != NULL)
      return true;
   else
      return false;
}
expfun vname copy(vname src,
                  size_t level = 0)
{
   vname v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (vname) malloc (sizeof(vname_struct));
      if (v != NULL)
      {
         if (level > 0)
            v->n = textNew(src->n);
         else
            v->n = src->n;
      }
      else
         malloc_error("copy()");

      return v;
   }
}
expfun vname deepCopy(vname src)
{
   vname v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (vname) malloc (sizeof(vname_struct));
      if (v != NULL)
      {
         v->n = textNew(src->n);
      }
      else
         malloc_error("deepCopy()");

      return v;
   }
}
expfun void dump(text Offset,
                 vname v,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (v == NULL)
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

      if (hasN(v) || showEmpty)
      {
         if (v->n ne NULL)
            fprintf(fp, "%stext n : %s\n", new_Offset, v->n);
         else if (showEmpty)
            fprintf(fp, "%stext n : NULL\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(vname v,
                 size_t level = 0)
{
   if (v ne NULL)
   {
      if (level > 0)
      {

         if (v->n ne NULL)
         {
            free((void *) v->n);
            v->n = NULL;
         }
      }


      free((void *) v);
   }
}
expfun void deepFree(vname v)
{
   if (v ne NULL)
   {

      if (v->n ne NULL)
      {
         free((void *) v->n);
         v->n = NULL;
      }

      free((void *) v);
   }
}
