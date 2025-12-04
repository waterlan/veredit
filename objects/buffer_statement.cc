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

#define buffer_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "signal_list.h"
#include "buffer_statement.h"


expfun buffer_statement buffer_statementNew(vname bufferName = NULL,
                                            signal_list excludes = NULL)
{
   buffer_statement b = (buffer_statement) malloc (sizeof(buffer_statement_struct));
   if (b != NULL)
   {
      b->bufferName = bufferName;
      b->excludes = excludes;
   }
   else
      malloc_error("buffer_statementNew()");

   return b;
}
expfun bool eqSelfBufferName(vname bufferName,
                             buffer_statement b)
{
   if ((bufferName == NULL) || (hasBufferName(b) == false))
      return false;
   else if (eqSelf(bufferName, getBufferName(b)))
      return true;
   else
      return false;
}
expfun bool eqBufferName(vname bufferName,
                         buffer_statement b)
{
   if ((bufferName == NULL) || (hasBufferName(b) == false))
      return false;
   else if (Eq(bufferName, getBufferName(b)))
      return true;
   else
      return false;
}
expfun bool eqSelfExcludes(signal_list excludes,
                           buffer_statement b)
{
   if ((excludes == NULL) || (hasExcludes(b) == false))
      return false;
   else if (eqSelf(excludes, getExcludes(b)))
      return true;
   else
      return false;
}
expfun bool eqExcludes(signal_list excludes,
                       buffer_statement b)
{
   if ((excludes == NULL) || (hasExcludes(b) == false))
      return false;
   else if (Eq(excludes, getExcludes(b)))
      return true;
   else
      return false;
}
expfun bool eqSelf(buffer_statement a,
                   buffer_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(buffer_statement a,
               buffer_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqBufferName(getBufferName(a), b) == false)
      return false;
   else if (eqExcludes(getExcludes(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getBufferName(buffer_statement b)
{
   if (b != NULL)
      return b->bufferName;
   else
      return NULL;
}
expfun signal_list getExcludes(buffer_statement b)
{
   if (b != NULL)
      return b->excludes;
   else
      return NULL;
}
expfun buffer_statement setBufferName(vname bufferName,
                                      buffer_statement b)
{
   if (b != NULL)
      b->bufferName = bufferName;
   return b;
}
expfun buffer_statement setExcludes(signal_list excludes,
                                    buffer_statement b)
{
   if (b != NULL)
      b->excludes = excludes;
   return b;
}
expfun bool hasBufferName(buffer_statement b)
{
   if (getBufferName(b) != NULL)
      return true;
   else
      return false;
}
expfun bool hasExcludes(buffer_statement b)
{
   if (isEmpty(getExcludes(b)) == false)
      return true;
   else
      return false;
}
expfun buffer_statement copy(buffer_statement src,
                             size_t level = 0)
{
   buffer_statement b;

   if (src == NULL)
      return NULL;
   else
   {
      b = (buffer_statement) malloc (sizeof(buffer_statement_struct));
      if (b != NULL)
      {
         if (level > 0)
         {
            b->bufferName = copy(src->bufferName, level - 1);
            b->excludes = copy(src->excludes, level - 1);
         }
         else
         {
            b->bufferName = src->bufferName;
            b->excludes = src->excludes;
         }
      }
      else
         malloc_error("copy()");

      return b;
   }
}
expfun buffer_statement deepCopy(buffer_statement src)
{
   buffer_statement b;

   if (src == NULL)
      return NULL;
   else
   {
      b = (buffer_statement) malloc (sizeof(buffer_statement_struct));
      if (b != NULL)
      {
         b->bufferName = deepCopy(src->bufferName);
         b->excludes = deepCopy(src->excludes);
      }
      else
         malloc_error("deepCopy()");

      return b;
   }
}
expfun void dump(text Offset,
                 buffer_statement b,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (b == NULL)
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

      if (hasBufferName(b) || showEmpty)
      {
         fprintf(fp, "%svname bufferName,\n", new_Offset);
         dump(new_Offset, b->bufferName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasExcludes(b) || showEmpty)
      {
         fprintf(fp, "%ssignal_list excludes,\n", new_Offset);
         dump(new_Offset, b->excludes, fp, showEmpty);
         fprintf(fp, "%s\\end signal_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(buffer_statement b,
                 size_t level = 0)
{
   if (b ne NULL)
   {
      if (level > 0)
      {

         Free(b->bufferName, level - 1);
         b->bufferName = NULL;

         Free(b->excludes, level - 1);
         b->excludes = NULL;
      }


      free((void *) b);
   }
}
expfun void deepFree(buffer_statement b)
{
   if (b ne NULL)
   {

      deepFree(b->bufferName);
      b->bufferName = NULL;

      deepFree(b->excludes);
      b->excludes = NULL;

      free((void *) b);
   }
}
