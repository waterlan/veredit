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

#define remove_buf_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "signal_list.h"
#include "name_list.h"
#include "remove_buf_statement.h"


expfun remove_buf_statement remove_buf_statementNew(signal_list signals = NULL,
                                                    name_list buffers = NULL)
{
   remove_buf_statement r = (remove_buf_statement) malloc (sizeof(remove_buf_statement_struct));
   if (r != NULL)
   {
      r->signals = signals;
      r->buffers = buffers;
   }
   else
      malloc_error("remove_buf_statementNew()");

   return r;
}
expfun bool eqSelfSignals(signal_list signals,
                          remove_buf_statement r)
{
   if ((signals == NULL) || (hasSignals(r) == false))
      return false;
   else if (eqSelf(signals, getSignals(r)))
      return true;
   else
      return false;
}
expfun bool eqSignals(signal_list signals,
                      remove_buf_statement r)
{
   if ((signals == NULL) || (hasSignals(r) == false))
      return false;
   else if (Eq(signals, getSignals(r)))
      return true;
   else
      return false;
}
expfun bool eqSelfBuffers(name_list buffers,
                          remove_buf_statement r)
{
   if ((buffers == NULL) || (hasBuffers(r) == false))
      return false;
   else if (eqSelf(buffers, getBuffers(r)))
      return true;
   else
      return false;
}
expfun bool eqBuffers(name_list buffers,
                      remove_buf_statement r)
{
   if ((buffers == NULL) || (hasBuffers(r) == false))
      return false;
   else if (Eq(buffers, getBuffers(r)))
      return true;
   else
      return false;
}
expfun bool eqSelf(remove_buf_statement a,
                   remove_buf_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(remove_buf_statement a,
               remove_buf_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqSignals(getSignals(a), b) == false)
      return false;
   else if (eqBuffers(getBuffers(a), b) == false)
      return false;
   else
      return true;
}
expfun signal_list getSignals(remove_buf_statement r)
{
   if (r != NULL)
      return r->signals;
   else
      return NULL;
}
expfun name_list getBuffers(remove_buf_statement r)
{
   if (r != NULL)
      return r->buffers;
   else
      return NULL;
}
expfun remove_buf_statement setSignals(signal_list signals,
                                       remove_buf_statement r)
{
   if (r != NULL)
      r->signals = signals;
   return r;
}
expfun remove_buf_statement setBuffers(name_list buffers,
                                       remove_buf_statement r)
{
   if (r != NULL)
      r->buffers = buffers;
   return r;
}
expfun bool hasSignals(remove_buf_statement r)
{
   if (isEmpty(getSignals(r)) == false)
      return true;
   else
      return false;
}
expfun bool hasBuffers(remove_buf_statement r)
{
   if (isEmpty(getBuffers(r)) == false)
      return true;
   else
      return false;
}
expfun remove_buf_statement copy(remove_buf_statement src,
                                 size_t level = 0)
{
   remove_buf_statement r;

   if (src == NULL)
      return NULL;
   else
   {
      r = (remove_buf_statement) malloc (sizeof(remove_buf_statement_struct));
      if (r != NULL)
      {
         if (level > 0)
         {
            r->signals = copy(src->signals, level - 1);
            r->buffers = copy(src->buffers, level - 1);
         }
         else
         {
            r->signals = src->signals;
            r->buffers = src->buffers;
         }
      }
      else
         malloc_error("copy()");

      return r;
   }
}
expfun remove_buf_statement deepCopy(remove_buf_statement src)
{
   remove_buf_statement r;

   if (src == NULL)
      return NULL;
   else
   {
      r = (remove_buf_statement) malloc (sizeof(remove_buf_statement_struct));
      if (r != NULL)
      {
         r->signals = deepCopy(src->signals);
         r->buffers = deepCopy(src->buffers);
      }
      else
         malloc_error("deepCopy()");

      return r;
   }
}
expfun void dump(text Offset,
                 remove_buf_statement r,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (r == NULL)
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

      if (hasSignals(r) || showEmpty)
      {
         fprintf(fp, "%ssignal_list signals,\n", new_Offset);
         dump(new_Offset, r->signals, fp, showEmpty);
         fprintf(fp, "%s\\end signal_list\n", new_Offset);
      }

      if (hasBuffers(r) || showEmpty)
      {
         fprintf(fp, "%sname_list buffers,\n", new_Offset);
         dump(new_Offset, r->buffers, fp, showEmpty);
         fprintf(fp, "%s\\end name_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(remove_buf_statement r,
                 size_t level = 0)
{
   if (r ne NULL)
   {
      if (level > 0)
      {

         Free(r->signals, level - 1);
         r->signals = NULL;

         Free(r->buffers, level - 1);
         r->buffers = NULL;
      }


      free((void *) r);
   }
}
expfun void deepFree(remove_buf_statement r)
{
   if (r ne NULL)
   {

      deepFree(r->signals);
      r->signals = NULL;

      deepFree(r->buffers);
      r->buffers = NULL;

      free((void *) r);
   }
}
