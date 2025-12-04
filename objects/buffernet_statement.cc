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

#define buffernet_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "buffer_type.h"
#include "vname.h"
#include "instantiation_list.h"
#include "buffernet_statement.h"


expfun buffernet_statement buffernet_statementNew(buffer_type type = _BUFFER_TYPE_UNDEFINED,
                                                  vname bufferName = NULL,
                                                  text inputName = "A",
                                                  text outputName = "Z",
                                                  instantiation_list editinstances = NULL)
{
   buffernet_statement b = (buffernet_statement) malloc (sizeof(buffernet_statement_struct));
   if (b != NULL)
   {
      b->type = type;
      b->bufferName = bufferName;
      b->inputName = inputName;
      b->outputName = outputName;
      b->editinstances = editinstances;
   }
   else
      malloc_error("buffernet_statementNew()");

   return b;
}
expfun bool eqType(buffer_type type,
                   buffernet_statement b)
{
   if (hasType(b) == false)
      return false;
   else if (Eq(type, getType(b)))
      return true;
   else
      return false;
}
expfun bool eqSelfBufferName(vname bufferName,
                             buffernet_statement b)
{
   if ((bufferName == NULL) || (hasBufferName(b) == false))
      return false;
   else if (eqSelf(bufferName, getBufferName(b)))
      return true;
   else
      return false;
}
expfun bool eqBufferName(vname bufferName,
                         buffernet_statement b)
{
   if ((bufferName == NULL) || (hasBufferName(b) == false))
      return false;
   else if (Eq(bufferName, getBufferName(b)))
      return true;
   else
      return false;
}
expfun bool eqSelfInputName(text inputName,
                            buffernet_statement b)
{
   if ((inputName == NULL) || (hasInputName(b) == false))
      return false;
   else if (eqSelf(inputName, getInputName(b)))
      return true;
   else
      return false;
}
expfun bool eqInputName(text inputName,
                        buffernet_statement b)
{
   if ((inputName == NULL) || (hasInputName(b) == false))
      return false;
   else if (Eq(inputName, getInputName(b)))
      return true;
   else
      return false;
}
expfun bool eqSelfOutputName(text outputName,
                             buffernet_statement b)
{
   if ((outputName == NULL) || (hasOutputName(b) == false))
      return false;
   else if (eqSelf(outputName, getOutputName(b)))
      return true;
   else
      return false;
}
expfun bool eqOutputName(text outputName,
                         buffernet_statement b)
{
   if ((outputName == NULL) || (hasOutputName(b) == false))
      return false;
   else if (Eq(outputName, getOutputName(b)))
      return true;
   else
      return false;
}
expfun bool eqSelfEditinstances(instantiation_list editinstances,
                                buffernet_statement b)
{
   if ((editinstances == NULL) || (hasEditinstances(b) == false))
      return false;
   else if (eqSelf(editinstances, getEditinstances(b)))
      return true;
   else
      return false;
}
expfun bool eqEditinstances(instantiation_list editinstances,
                            buffernet_statement b)
{
   if ((editinstances == NULL) || (hasEditinstances(b) == false))
      return false;
   else if (Eq(editinstances, getEditinstances(b)))
      return true;
   else
      return false;
}
expfun bool eqSelf(buffernet_statement a,
                   buffernet_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(buffernet_statement a,
               buffernet_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqType(getType(a), b) == false)
      return false;
   else if (eqBufferName(getBufferName(a), b) == false)
      return false;
   else if (eqInputName(getInputName(a), b) == false)
      return false;
   else if (eqOutputName(getOutputName(a), b) == false)
      return false;
   else if (eqEditinstances(getEditinstances(a), b) == false)
      return false;
   else
      return true;
}
expfun buffer_type getType(buffernet_statement b)
{
   if (b != NULL)
      return b->type;
   else
      return _BUFFER_TYPE_UNDEFINED;
}
expfun vname getBufferName(buffernet_statement b)
{
   if (b != NULL)
      return b->bufferName;
   else
      return NULL;
}
expfun text getInputName(buffernet_statement b)
{
   if (b != NULL)
      return b->inputName;
   else
      return "A";
}
expfun text getOutputName(buffernet_statement b)
{
   if (b != NULL)
      return b->outputName;
   else
      return "Z";
}
expfun instantiation_list getEditinstances(buffernet_statement b)
{
   if (b != NULL)
      return b->editinstances;
   else
      return NULL;
}
expfun buffernet_statement setType(buffer_type type,
                                   buffernet_statement b)
{
   if (b != NULL)
      b->type = type;
   return b;
}
expfun buffernet_statement setBufferName(vname bufferName,
                                         buffernet_statement b)
{
   if (b != NULL)
      b->bufferName = bufferName;
   return b;
}
expfun buffernet_statement setInputName(text inputName,
                                        buffernet_statement b)
{
   if (b != NULL)
      b->inputName = inputName;
   return b;
}
expfun buffernet_statement setOutputName(text outputName,
                                         buffernet_statement b)
{
   if (b != NULL)
      b->outputName = outputName;
   return b;
}
expfun buffernet_statement setEditinstances(instantiation_list editinstances,
                                            buffernet_statement b)
{
   if (b != NULL)
      b->editinstances = editinstances;
   return b;
}
expfun bool hasType(buffernet_statement b)
{
   if (getType(b) != _BUFFER_TYPE_UNDEFINED)
      return true;
   else
      return false;
}
expfun bool hasBufferName(buffernet_statement b)
{
   if (getBufferName(b) != NULL)
      return true;
   else
      return false;
}
expfun bool hasInputName(buffernet_statement b)
{
   if (Eq(getInputName(b), "A") == false)
      return true;
   else
      return false;
}
expfun bool hasOutputName(buffernet_statement b)
{
   if (Eq(getOutputName(b), "Z") == false)
      return true;
   else
      return false;
}
expfun bool hasEditinstances(buffernet_statement b)
{
   if (isEmpty(getEditinstances(b)) == false)
      return true;
   else
      return false;
}
expfun buffernet_statement copy(buffernet_statement src,
                                size_t level = 0)
{
   buffernet_statement b;

   if (src == NULL)
      return NULL;
   else
   {
      b = (buffernet_statement) malloc (sizeof(buffernet_statement_struct));
      if (b != NULL)
      {
         if (level > 0)
         {
            b->type = src->type;
            b->bufferName = copy(src->bufferName, level - 1);
            b->inputName = textNew(src->inputName);
            b->outputName = textNew(src->outputName);
            b->editinstances = copy(src->editinstances, level - 1);
         }
         else
         {
            b->type = src->type;
            b->bufferName = src->bufferName;
            b->inputName = src->inputName;
            b->outputName = src->outputName;
            b->editinstances = src->editinstances;
         }
      }
      else
         malloc_error("copy()");

      return b;
   }
}
expfun buffernet_statement deepCopy(buffernet_statement src)
{
   buffernet_statement b;

   if (src == NULL)
      return NULL;
   else
   {
      b = (buffernet_statement) malloc (sizeof(buffernet_statement_struct));
      if (b != NULL)
      {
         b->type = src->type;
         b->bufferName = deepCopy(src->bufferName);
         b->inputName = textNew(src->inputName);
         b->outputName = textNew(src->outputName);
         b->editinstances = deepCopy(src->editinstances);
      }
      else
         malloc_error("deepCopy()");

      return b;
   }
}
expfun void dump(text Offset,
                 buffernet_statement b,
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

      if (hasType(b) || showEmpty)
         fprintf(fp, "%sbuffer_type type : %s\n", new_Offset, dumpToString(b->type));

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

      if (hasEditinstances(b) || showEmpty)
      {
         fprintf(fp, "%sinstantiation_list editinstances,\n", new_Offset);
         dump(new_Offset, b->editinstances, fp, showEmpty);
         fprintf(fp, "%s\\end instantiation_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(buffernet_statement b,
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

         Free(b->editinstances, level - 1);
         b->editinstances = NULL;
      }


      free((void *) b);
   }
}
expfun void deepFree(buffernet_statement b)
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

      deepFree(b->editinstances);
      b->editinstances = NULL;

      free((void *) b);
   }
}
