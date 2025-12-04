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

#define verilog_item_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "module.h"
#include "verilog_item.h"


expfun verilog_item verilog_itemNew(text compilerDirective = NULL,
                                    module block = NULL)
{
   verilog_item v = (verilog_item) malloc (sizeof(verilog_item_struct));
   if (v != NULL)
   {
      v->compilerDirective = compilerDirective;
      v->block = block;
   }
   else
      malloc_error("verilog_itemNew()");

   return v;
}
expfun bool eqSelfCompilerDirective(text compilerDirective,
                                    verilog_item v)
{
   if ((compilerDirective == NULL) || (hasCompilerDirective(v) == false))
      return false;
   else if (eqSelf(compilerDirective, getCompilerDirective(v)))
      return true;
   else
      return false;
}
expfun bool eqCompilerDirective(text compilerDirective,
                                verilog_item v)
{
   if ((compilerDirective == NULL) || (hasCompilerDirective(v) == false))
      return false;
   else if (Eq(compilerDirective, getCompilerDirective(v)))
      return true;
   else
      return false;
}
expfun bool eqSelfBlock(module block,
                        verilog_item v)
{
   if ((block == NULL) || (hasBlock(v) == false))
      return false;
   else if (eqSelf(block, getBlock(v)))
      return true;
   else
      return false;
}
expfun bool eqBlock(module block,
                    verilog_item v)
{
   if ((block == NULL) || (hasBlock(v) == false))
      return false;
   else if (Eq(block, getBlock(v)))
      return true;
   else
      return false;
}
expfun bool eqSelf(verilog_item a,
                   verilog_item b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(verilog_item a,
               verilog_item b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqCompilerDirective(getCompilerDirective(a), b) == false)
      return false;
   else if (eqBlock(getBlock(a), b) == false)
      return false;
   else
      return true;
}
expfun text getCompilerDirective(verilog_item v)
{
   if (v != NULL)
      return v->compilerDirective;
   else
      return NULL;
}
expfun module getBlock(verilog_item v)
{
   if (v != NULL)
      return v->block;
   else
      return NULL;
}
expfun verilog_item setCompilerDirective(text compilerDirective,
                                         verilog_item v)
{
   if (v != NULL)
      v->compilerDirective = compilerDirective;
   return v;
}
expfun verilog_item setBlock(module block,
                             verilog_item v)
{
   if (v != NULL)
      v->block = block;
   return v;
}
expfun bool hasCompilerDirective(verilog_item v)
{
   if (getCompilerDirective(v) != NULL)
      return true;
   else
      return false;
}
expfun bool hasBlock(verilog_item v)
{
   if (getBlock(v) != NULL)
      return true;
   else
      return false;
}
expfun verilog_item copy(verilog_item src,
                         size_t level = 0)
{
   verilog_item v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (verilog_item) malloc (sizeof(verilog_item_struct));
      if (v != NULL)
      {
         if (level > 0)
         {
            v->compilerDirective = textNew(src->compilerDirective);
            v->block = copy(src->block, level - 1);
         }
         else
         {
            v->compilerDirective = src->compilerDirective;
            v->block = src->block;
         }
      }
      else
         malloc_error("copy()");

      return v;
   }
}
expfun verilog_item deepCopy(verilog_item src)
{
   verilog_item v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (verilog_item) malloc (sizeof(verilog_item_struct));
      if (v != NULL)
      {
         v->compilerDirective = textNew(src->compilerDirective);
         v->block = deepCopy(src->block);
      }
      else
         malloc_error("deepCopy()");

      return v;
   }
}
expfun void dump(text Offset,
                 verilog_item v,
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

      if (hasCompilerDirective(v) || showEmpty)
      {
         if (v->compilerDirective ne NULL)
            fprintf(fp, "%stext compilerDirective : %s\n", new_Offset, v->compilerDirective);
         else if (showEmpty)
            fprintf(fp, "%stext compilerDirective : NULL\n", new_Offset);
      }

      if (hasBlock(v) || showEmpty)
      {
         fprintf(fp, "%smodule block,\n", new_Offset);
         dump(new_Offset, v->block, fp, showEmpty);
         fprintf(fp, "%s\\end module\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(verilog_item v,
                 size_t level = 0)
{
   if (v ne NULL)
   {
      if (level > 0)
      {

         if (v->compilerDirective ne NULL)
         {
            free((void *) v->compilerDirective);
            v->compilerDirective = NULL;
         }

         Free(v->block, level - 1);
         v->block = NULL;
      }


      free((void *) v);
   }
}
expfun void deepFree(verilog_item v)
{
   if (v ne NULL)
   {

      if (v->compilerDirective ne NULL)
      {
         free((void *) v->compilerDirective);
         v->compilerDirective = NULL;
      }

      deepFree(v->block);
      v->block = NULL;

      free((void *) v);
   }
}
