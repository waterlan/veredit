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

#define insertObsOutput_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "portmap.h"
#include "simple_signal_list.h"
#include "insertObsOutput_statement.h"


expfun insertObsOutput_statement insertObsOutput_statementNew(vname moduleName = NULL,
                                                              vname inputName = NULL,
                                                              vname outputName = NULL,
                                                              portmap otherPins = NULL,
                                                              simple_signal_list Nets = NULL)
{
   insertObsOutput_statement i = (insertObsOutput_statement) malloc (sizeof(insertObsOutput_statement_struct));
   if (i != NULL)
   {
      i->moduleName = moduleName;
      i->inputName = inputName;
      i->outputName = outputName;
      i->otherPins = otherPins;
      i->Nets = Nets;
   }
   else
      malloc_error("insertObsOutput_statementNew()");

   return i;
}
expfun bool eqSelfModuleName(vname moduleName,
                             insertObsOutput_statement i)
{
   if ((moduleName == NULL) || (hasModuleName(i) == false))
      return false;
   else if (eqSelf(moduleName, getModuleName(i)))
      return true;
   else
      return false;
}
expfun bool eqModuleName(vname moduleName,
                         insertObsOutput_statement i)
{
   if ((moduleName == NULL) || (hasModuleName(i) == false))
      return false;
   else if (Eq(moduleName, getModuleName(i)))
      return true;
   else
      return false;
}
expfun bool eqSelfInputName(vname inputName,
                            insertObsOutput_statement i)
{
   if ((inputName == NULL) || (hasInputName(i) == false))
      return false;
   else if (eqSelf(inputName, getInputName(i)))
      return true;
   else
      return false;
}
expfun bool eqInputName(vname inputName,
                        insertObsOutput_statement i)
{
   if ((inputName == NULL) || (hasInputName(i) == false))
      return false;
   else if (Eq(inputName, getInputName(i)))
      return true;
   else
      return false;
}
expfun bool eqSelfOutputName(vname outputName,
                             insertObsOutput_statement i)
{
   if ((outputName == NULL) || (hasOutputName(i) == false))
      return false;
   else if (eqSelf(outputName, getOutputName(i)))
      return true;
   else
      return false;
}
expfun bool eqOutputName(vname outputName,
                         insertObsOutput_statement i)
{
   if ((outputName == NULL) || (hasOutputName(i) == false))
      return false;
   else if (Eq(outputName, getOutputName(i)))
      return true;
   else
      return false;
}
expfun bool eqSelfOtherPins(portmap otherPins,
                            insertObsOutput_statement i)
{
   if ((otherPins == NULL) || (hasOtherPins(i) == false))
      return false;
   else if (eqSelf(otherPins, getOtherPins(i)))
      return true;
   else
      return false;
}
expfun bool eqOtherPins(portmap otherPins,
                        insertObsOutput_statement i)
{
   if ((otherPins == NULL) || (hasOtherPins(i) == false))
      return false;
   else if (Eq(otherPins, getOtherPins(i)))
      return true;
   else
      return false;
}
expfun bool eqSelfNets(simple_signal_list Nets,
                       insertObsOutput_statement i)
{
   if ((Nets == NULL) || (hasNets(i) == false))
      return false;
   else if (eqSelf(Nets, getNets(i)))
      return true;
   else
      return false;
}
expfun bool eqNets(simple_signal_list Nets,
                   insertObsOutput_statement i)
{
   if ((Nets == NULL) || (hasNets(i) == false))
      return false;
   else if (Eq(Nets, getNets(i)))
      return true;
   else
      return false;
}
expfun bool eqSelf(insertObsOutput_statement a,
                   insertObsOutput_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(insertObsOutput_statement a,
               insertObsOutput_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqModuleName(getModuleName(a), b) == false)
      return false;
   else if (eqInputName(getInputName(a), b) == false)
      return false;
   else if (eqOutputName(getOutputName(a), b) == false)
      return false;
   else if (eqOtherPins(getOtherPins(a), b) == false)
      return false;
   else if (eqNets(getNets(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getModuleName(insertObsOutput_statement i)
{
   if (i != NULL)
      return i->moduleName;
   else
      return NULL;
}
expfun vname getInputName(insertObsOutput_statement i)
{
   if (i != NULL)
      return i->inputName;
   else
      return NULL;
}
expfun vname getOutputName(insertObsOutput_statement i)
{
   if (i != NULL)
      return i->outputName;
   else
      return NULL;
}
expfun portmap getOtherPins(insertObsOutput_statement i)
{
   if (i != NULL)
      return i->otherPins;
   else
      return NULL;
}
expfun simple_signal_list getNets(insertObsOutput_statement i)
{
   if (i != NULL)
      return i->Nets;
   else
      return NULL;
}
expfun insertObsOutput_statement setModuleName(vname moduleName,
                                               insertObsOutput_statement i)
{
   if (i != NULL)
      i->moduleName = moduleName;
   return i;
}
expfun insertObsOutput_statement setInputName(vname inputName,
                                              insertObsOutput_statement i)
{
   if (i != NULL)
      i->inputName = inputName;
   return i;
}
expfun insertObsOutput_statement setOutputName(vname outputName,
                                               insertObsOutput_statement i)
{
   if (i != NULL)
      i->outputName = outputName;
   return i;
}
expfun insertObsOutput_statement setOtherPins(portmap otherPins,
                                              insertObsOutput_statement i)
{
   if (i != NULL)
      i->otherPins = otherPins;
   return i;
}
expfun insertObsOutput_statement setNets(simple_signal_list Nets,
                                         insertObsOutput_statement i)
{
   if (i != NULL)
      i->Nets = Nets;
   return i;
}
expfun bool hasModuleName(insertObsOutput_statement i)
{
   if (getModuleName(i) != NULL)
      return true;
   else
      return false;
}
expfun bool hasInputName(insertObsOutput_statement i)
{
   if (getInputName(i) != NULL)
      return true;
   else
      return false;
}
expfun bool hasOutputName(insertObsOutput_statement i)
{
   if (getOutputName(i) != NULL)
      return true;
   else
      return false;
}
expfun bool hasOtherPins(insertObsOutput_statement i)
{
   if (isEmpty(getOtherPins(i)) == false)
      return true;
   else
      return false;
}
expfun bool hasNets(insertObsOutput_statement i)
{
   if (isEmpty(getNets(i)) == false)
      return true;
   else
      return false;
}
expfun insertObsOutput_statement copy(insertObsOutput_statement src,
                                      size_t level = 0)
{
   insertObsOutput_statement i;

   if (src == NULL)
      return NULL;
   else
   {
      i = (insertObsOutput_statement) malloc (sizeof(insertObsOutput_statement_struct));
      if (i != NULL)
      {
         if (level > 0)
         {
            i->moduleName = copy(src->moduleName, level - 1);
            i->inputName = copy(src->inputName, level - 1);
            i->outputName = copy(src->outputName, level - 1);
            i->otherPins = copy(src->otherPins, level - 1);
            i->Nets = copy(src->Nets, level - 1);
         }
         else
         {
            i->moduleName = src->moduleName;
            i->inputName = src->inputName;
            i->outputName = src->outputName;
            i->otherPins = src->otherPins;
            i->Nets = src->Nets;
         }
      }
      else
         malloc_error("copy()");

      return i;
   }
}
expfun insertObsOutput_statement deepCopy(insertObsOutput_statement src)
{
   insertObsOutput_statement i;

   if (src == NULL)
      return NULL;
   else
   {
      i = (insertObsOutput_statement) malloc (sizeof(insertObsOutput_statement_struct));
      if (i != NULL)
      {
         i->moduleName = deepCopy(src->moduleName);
         i->inputName = deepCopy(src->inputName);
         i->outputName = deepCopy(src->outputName);
         i->otherPins = deepCopy(src->otherPins);
         i->Nets = deepCopy(src->Nets);
      }
      else
         malloc_error("deepCopy()");

      return i;
   }
}
expfun void dump(text Offset,
                 insertObsOutput_statement i,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (i == NULL)
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

      if (hasModuleName(i) || showEmpty)
      {
         fprintf(fp, "%svname moduleName,\n", new_Offset);
         dump(new_Offset, i->moduleName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasInputName(i) || showEmpty)
      {
         fprintf(fp, "%svname inputName,\n", new_Offset);
         dump(new_Offset, i->inputName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasOutputName(i) || showEmpty)
      {
         fprintf(fp, "%svname outputName,\n", new_Offset);
         dump(new_Offset, i->outputName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasOtherPins(i) || showEmpty)
      {
         fprintf(fp, "%sportmap otherPins,\n", new_Offset);
         dump(new_Offset, i->otherPins, fp, showEmpty);
         fprintf(fp, "%s\\end portmap\n", new_Offset);
      }

      if (hasNets(i) || showEmpty)
      {
         fprintf(fp, "%ssimple_signal_list Nets,\n", new_Offset);
         dump(new_Offset, i->Nets, fp, showEmpty);
         fprintf(fp, "%s\\end simple_signal_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(insertObsOutput_statement i,
                 size_t level = 0)
{
   if (i ne NULL)
   {
      if (level > 0)
      {

         Free(i->moduleName, level - 1);
         i->moduleName = NULL;

         Free(i->inputName, level - 1);
         i->inputName = NULL;

         Free(i->outputName, level - 1);
         i->outputName = NULL;

         Free(i->otherPins, level - 1);
         i->otherPins = NULL;

         Free(i->Nets, level - 1);
         i->Nets = NULL;
      }


      free((void *) i);
   }
}
expfun void deepFree(insertObsOutput_statement i)
{
   if (i ne NULL)
   {

      deepFree(i->moduleName);
      i->moduleName = NULL;

      deepFree(i->inputName);
      i->inputName = NULL;

      deepFree(i->outputName);
      i->outputName = NULL;

      deepFree(i->otherPins);
      i->otherPins = NULL;

      deepFree(i->Nets);
      i->Nets = NULL;

      free((void *) i);
   }
}
