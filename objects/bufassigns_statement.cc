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

#define bufassigns_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "bufassigns_statement.h"


expfun bufassigns_statement bufassigns_statementNew(vname bufferName = NULL,
                                                    text inputName = "A",
                                                    text outputName = "Z")
{
   bufassigns_statement b = (bufassigns_statement) malloc (sizeof(bufassigns_statement_struct));
   if (b != NULL)
   {
      b->bufferName = bufferName;
      b->inputName = inputName;
      b->outputName = outputName;
   }
   else
      malloc_error("bufassigns_statementNew()");

   return b;
}
expfun bool eqSelfBufferName(vname bufferName,
                             bufassigns_statement b)
{
   if ((bufferName == NULL) || (hasBufferName(b) == false))
      return false;
   else if (eqSelf(bufferName, getBufferName(b)))
      return true;
   else
      return false;
}
expfun bool eqBufferName(vname bufferName,
                         bufassigns_statement b)
{
   if ((bufferName == NULL) || (hasBufferName(b) == false))
      return false;
   else if (Eq(bufferName, getBufferName(b)))
      return true;
   else
      return false;
}
expfun bool eqSelfInputName(text inputName,
                            bufassigns_statement b)
{
   if ((inputName == NULL) || (hasInputName(b) == false))
      return false;
   else if (eqSelf(inputName, getInputName(b)))
      return true;
   else
      return false;
}
expfun bool eqInputName(text inputName,
                        bufassigns_statement b)
{
   if ((inputName == NULL) || (hasInputName(b) == false))
      return false;
   else if (Eq(inputName, getInputName(b)))
      return true;
   else
      return false;
}
expfun bool eqSelfOutputName(text outputName,
                             bufassigns_statement b)
{
   if ((outputName == NULL) || (hasOutputName(b) == false))
      return false;
   else if (eqSelf(outputName, getOutputName(b)))
      return true;
   else
      return false;
}
expfun bool eqOutputName(text outputName,
                         bufassigns_statement b)
{
   if ((outputName == NULL) || (hasOutputName(b) == false))
      return false;
   else if (Eq(outputName, getOutputName(b)))
      return true;
   else
      return false;
}
expfun bool eqSelf(bufassigns_statement a,
                   bufassigns_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(bufassigns_statement a,
               bufassigns_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqBufferName(getBufferName(a), b) == false)
      return false;
   else if (eqInputName(getInputName(a), b) == false)
      return false;
   else if (eqOutputName(getOutputName(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getBufferName(bufassigns_statement b)
{
   if (b != NULL)
      return b->bufferName;
   else
      return NULL;
}
expfun text getInputName(bufassigns_statement b)
{
   if (b != NULL)
      return b->inputName;
   else
      return "A";
}
expfun text getOutputName(bufassigns_statement b)
{
   if (b != NULL)
      return b->outputName;
   else
      return "Z";
}
expfun bufassigns_statement setBufferName(vname bufferName,
                                          bufassigns_statement b)
{
   if (b != NULL)
      b->bufferName = bufferName;
   return b;
}
expfun bufassigns_statement setInputName(text inputName,
                                         bufassigns_statement b)
{
   if (b != NULL)
      b->inputName = inputName;
   return b;
}
expfun bufassigns_statement setOutputName(text outputName,
                                          bufassigns_statement b)
{
   if (b != NULL)
      b->outputName = outputName;
   return b;
}
expfun bool hasBufferName(bufassigns_statement b)
{
   if (getBufferName(b) != NULL)
      return true;
   else
      return false;
}
expfun bool hasInputName(bufassigns_statement b)
{
   if (Eq(getInputName(b), "A") == false)
      return true;
   else
      return false;
}
expfun bool hasOutputName(bufassigns_statement b)
{
   if (Eq(getOutputName(b), "Z") == false)
      return true;
   else
      return false;
}
expfun bufassigns_statement copy(bufassigns_statement src,
                                 size_t level = 0)
{
   bufassigns_statement b;

   if (src == NULL)
      return NULL;
   else
   {
      b = (bufassigns_statement) malloc (sizeof(bufassigns_statement_struct));
      if (b != NULL)
      {
         if (level > 0)
         {
            b->bufferName = copy(src->bufferName, level - 1);
            b->inputName = textNew(src->inputName);
            b->outputName = textNew(src->outputName);
         }
         else
         {
            b->bufferName = src->bufferName;
            b->inputName = src->inputName;
            b->outputName = src->outputName;
         }
      }
      else
         malloc_error("copy()");

      return b;
   }
}
expfun bufassigns_statement deepCopy(bufassigns_statement src)
{
   bufassigns_statement b;

   if (src == NULL)
      return NULL;
   else
   {
      b = (bufassigns_statement) malloc (sizeof(bufassigns_statement_struct));
      if (b != NULL)
      {
         b->bufferName = deepCopy(src->bufferName);
         b->inputName = textNew(src->inputName);
         b->outputName = textNew(src->outputName);
      }
      else
         malloc_error("deepCopy()");

      return b;
   }
}
expfun void dump(text Offset,
                 bufassigns_statement b,
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

      if (hasInputName(b) || showEmpty)
      {
         if (b->inputName ne NULL)
            fprintf(fp, "%stext inputName : %s\n", new_Offset, b->inputName);
         else if (showEmpty)
            fprintf(fp, "%stext inputName : NULL\n", new_Offset);
      }

      if (hasOutputName(b) || showEmpty)
      {
         if (b->outputName ne NULL)
            fprintf(fp, "%stext outputName : %s\n", new_Offset, b->outputName);
         else if (showEmpty)
            fprintf(fp, "%stext outputName : NULL\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(bufassigns_statement b,
                 size_t level = 0)
{
   if (b ne NULL)
   {
      if (level > 0)
      {

         Free(b->bufferName, level - 1);
         b->bufferName = NULL;

         if (b->inputName ne NULL)
         {
            free((void *) b->inputName);
            b->inputName = NULL;
         }

         if (b->outputName ne NULL)
         {
            free((void *) b->outputName);
            b->outputName = NULL;
         }
      }


      free((void *) b);
   }
}
expfun void deepFree(bufassigns_statement b)
{
   if (b ne NULL)
   {

      deepFree(b->bufferName);
      b->bufferName = NULL;

      if (b->inputName ne NULL)
      {
         free((void *) b->inputName);
         b->inputName = NULL;
      }

      if (b->outputName ne NULL)
      {
         free((void *) b->outputName);
         b->outputName = NULL;
      }

      free((void *) b);
   }
}
