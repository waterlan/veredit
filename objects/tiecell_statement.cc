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

#define tiecell_statement_cc

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
#include "match_list.h"
#include "tiecell_statement.h"


expfun tiecell_statement tiecell_statementNew(vname moduleName = NULL,
                                              vname outputName = NULL,
                                              portmap otherPins = NULL,
                                              simple_signal_list Nets = NULL,
                                              simple_signal_list excludes = NULL,
                                              match_list instances = NULL,
                                              text instLabel = "")
{
   tiecell_statement t = (tiecell_statement) malloc (sizeof(tiecell_statement_struct));
   if (t != NULL)
   {
      t->moduleName = moduleName;
      t->outputName = outputName;
      t->otherPins = otherPins;
      t->Nets = Nets;
      t->excludes = excludes;
      t->instances = instances;
      t->instLabel = instLabel;
   }
   else
      malloc_error("tiecell_statementNew()");

   return t;
}
expfun bool eqSelfModuleName(vname moduleName,
                             tiecell_statement t)
{
   if ((moduleName == NULL) || (hasModuleName(t) == false))
      return false;
   else if (eqSelf(moduleName, getModuleName(t)))
      return true;
   else
      return false;
}
expfun bool eqModuleName(vname moduleName,
                         tiecell_statement t)
{
   if ((moduleName == NULL) || (hasModuleName(t) == false))
      return false;
   else if (Eq(moduleName, getModuleName(t)))
      return true;
   else
      return false;
}
expfun bool eqSelfOutputName(vname outputName,
                             tiecell_statement t)
{
   if ((outputName == NULL) || (hasOutputName(t) == false))
      return false;
   else if (eqSelf(outputName, getOutputName(t)))
      return true;
   else
      return false;
}
expfun bool eqOutputName(vname outputName,
                         tiecell_statement t)
{
   if ((outputName == NULL) || (hasOutputName(t) == false))
      return false;
   else if (Eq(outputName, getOutputName(t)))
      return true;
   else
      return false;
}
expfun bool eqSelfOtherPins(portmap otherPins,
                            tiecell_statement t)
{
   if ((otherPins == NULL) || (hasOtherPins(t) == false))
      return false;
   else if (eqSelf(otherPins, getOtherPins(t)))
      return true;
   else
      return false;
}
expfun bool eqOtherPins(portmap otherPins,
                        tiecell_statement t)
{
   if ((otherPins == NULL) || (hasOtherPins(t) == false))
      return false;
   else if (Eq(otherPins, getOtherPins(t)))
      return true;
   else
      return false;
}
expfun bool eqSelfNets(simple_signal_list Nets,
                       tiecell_statement t)
{
   if ((Nets == NULL) || (hasNets(t) == false))
      return false;
   else if (eqSelf(Nets, getNets(t)))
      return true;
   else
      return false;
}
expfun bool eqNets(simple_signal_list Nets,
                   tiecell_statement t)
{
   if ((Nets == NULL) || (hasNets(t) == false))
      return false;
   else if (Eq(Nets, getNets(t)))
      return true;
   else
      return false;
}
expfun bool eqSelfExcludes(simple_signal_list excludes,
                           tiecell_statement t)
{
   if ((excludes == NULL) || (hasExcludes(t) == false))
      return false;
   else if (eqSelf(excludes, getExcludes(t)))
      return true;
   else
      return false;
}
expfun bool eqExcludes(simple_signal_list excludes,
                       tiecell_statement t)
{
   if ((excludes == NULL) || (hasExcludes(t) == false))
      return false;
   else if (Eq(excludes, getExcludes(t)))
      return true;
   else
      return false;
}
expfun bool eqSelfInstances(match_list instances,
                            tiecell_statement t)
{
   if ((instances == NULL) || (hasInstances(t) == false))
      return false;
   else if (eqSelf(instances, getInstances(t)))
      return true;
   else
      return false;
}
expfun bool eqInstances(match_list instances,
                        tiecell_statement t)
{
   if ((instances == NULL) || (hasInstances(t) == false))
      return false;
   else if (Eq(instances, getInstances(t)))
      return true;
   else
      return false;
}
expfun bool eqSelfInstLabel(text instLabel,
                            tiecell_statement t)
{
   if ((instLabel == NULL) || (hasInstLabel(t) == false))
      return false;
   else if (eqSelf(instLabel, getInstLabel(t)))
      return true;
   else
      return false;
}
expfun bool eqInstLabel(text instLabel,
                        tiecell_statement t)
{
   if ((instLabel == NULL) || (hasInstLabel(t) == false))
      return false;
   else if (Eq(instLabel, getInstLabel(t)))
      return true;
   else
      return false;
}
expfun bool eqSelf(tiecell_statement a,
                   tiecell_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(tiecell_statement a,
               tiecell_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqModuleName(getModuleName(a), b) == false)
      return false;
   else if (eqOutputName(getOutputName(a), b) == false)
      return false;
   else if (eqOtherPins(getOtherPins(a), b) == false)
      return false;
   else if (eqNets(getNets(a), b) == false)
      return false;
   else if (eqExcludes(getExcludes(a), b) == false)
      return false;
   else if (eqInstances(getInstances(a), b) == false)
      return false;
   else if (eqInstLabel(getInstLabel(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getModuleName(tiecell_statement t)
{
   if (t != NULL)
      return t->moduleName;
   else
      return NULL;
}
expfun vname getOutputName(tiecell_statement t)
{
   if (t != NULL)
      return t->outputName;
   else
      return NULL;
}
expfun portmap getOtherPins(tiecell_statement t)
{
   if (t != NULL)
      return t->otherPins;
   else
      return NULL;
}
expfun simple_signal_list getNets(tiecell_statement t)
{
   if (t != NULL)
      return t->Nets;
   else
      return NULL;
}
expfun simple_signal_list getExcludes(tiecell_statement t)
{
   if (t != NULL)
      return t->excludes;
   else
      return NULL;
}
expfun match_list getInstances(tiecell_statement t)
{
   if (t != NULL)
      return t->instances;
   else
      return NULL;
}
expfun text getInstLabel(tiecell_statement t)
{
   if (t != NULL)
      return t->instLabel;
   else
      return "";
}
expfun tiecell_statement setModuleName(vname moduleName,
                                       tiecell_statement t)
{
   if (t != NULL)
      t->moduleName = moduleName;
   return t;
}
expfun tiecell_statement setOutputName(vname outputName,
                                       tiecell_statement t)
{
   if (t != NULL)
      t->outputName = outputName;
   return t;
}
expfun tiecell_statement setOtherPins(portmap otherPins,
                                      tiecell_statement t)
{
   if (t != NULL)
      t->otherPins = otherPins;
   return t;
}
expfun tiecell_statement setNets(simple_signal_list Nets,
                                 tiecell_statement t)
{
   if (t != NULL)
      t->Nets = Nets;
   return t;
}
expfun tiecell_statement setExcludes(simple_signal_list excludes,
                                     tiecell_statement t)
{
   if (t != NULL)
      t->excludes = excludes;
   return t;
}
expfun tiecell_statement setInstances(match_list instances,
                                      tiecell_statement t)
{
   if (t != NULL)
      t->instances = instances;
   return t;
}
expfun tiecell_statement setInstLabel(text instLabel,
                                      tiecell_statement t)
{
   if (t != NULL)
      t->instLabel = instLabel;
   return t;
}
expfun bool hasModuleName(tiecell_statement t)
{
   if (getModuleName(t) != NULL)
      return true;
   else
      return false;
}
expfun bool hasOutputName(tiecell_statement t)
{
   if (getOutputName(t) != NULL)
      return true;
   else
      return false;
}
expfun bool hasOtherPins(tiecell_statement t)
{
   if (isEmpty(getOtherPins(t)) == false)
      return true;
   else
      return false;
}
expfun bool hasNets(tiecell_statement t)
{
   if (isEmpty(getNets(t)) == false)
      return true;
   else
      return false;
}
expfun bool hasExcludes(tiecell_statement t)
{
   if (isEmpty(getExcludes(t)) == false)
      return true;
   else
      return false;
}
expfun bool hasInstances(tiecell_statement t)
{
   if (isEmpty(getInstances(t)) == false)
      return true;
   else
      return false;
}
expfun bool hasInstLabel(tiecell_statement t)
{
   if (Eq(getInstLabel(t), "") == false)
      return true;
   else
      return false;
}
expfun tiecell_statement copy(tiecell_statement src,
                              size_t level = 0)
{
   tiecell_statement t;

   if (src == NULL)
      return NULL;
   else
   {
      t = (tiecell_statement) malloc (sizeof(tiecell_statement_struct));
      if (t != NULL)
      {
         if (level > 0)
         {
            t->moduleName = copy(src->moduleName, level - 1);
            t->outputName = copy(src->outputName, level - 1);
            t->otherPins = copy(src->otherPins, level - 1);
            t->Nets = copy(src->Nets, level - 1);
            t->excludes = copy(src->excludes, level - 1);
            t->instances = copy(src->instances, level - 1);
            t->instLabel = textNew(src->instLabel);
         }
         else
         {
            t->moduleName = src->moduleName;
            t->outputName = src->outputName;
            t->otherPins = src->otherPins;
            t->Nets = src->Nets;
            t->excludes = src->excludes;
            t->instances = src->instances;
            t->instLabel = src->instLabel;
         }
      }
      else
         malloc_error("copy()");

      return t;
   }
}
expfun tiecell_statement deepCopy(tiecell_statement src)
{
   tiecell_statement t;

   if (src == NULL)
      return NULL;
   else
   {
      t = (tiecell_statement) malloc (sizeof(tiecell_statement_struct));
      if (t != NULL)
      {
         t->moduleName = deepCopy(src->moduleName);
         t->outputName = deepCopy(src->outputName);
         t->otherPins = deepCopy(src->otherPins);
         t->Nets = deepCopy(src->Nets);
         t->excludes = deepCopy(src->excludes);
         t->instances = deepCopy(src->instances);
         t->instLabel = textNew(src->instLabel);
      }
      else
         malloc_error("deepCopy()");

      return t;
   }
}
expfun void dump(text Offset,
                 tiecell_statement t,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (t == NULL)
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

      if (hasModuleName(t) || showEmpty)
      {
         fprintf(fp, "%svname moduleName,\n", new_Offset);
         dump(new_Offset, t->moduleName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasOutputName(t) || showEmpty)
      {
         fprintf(fp, "%svname outputName,\n", new_Offset);
         dump(new_Offset, t->outputName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasOtherPins(t) || showEmpty)
      {
         fprintf(fp, "%sportmap otherPins,\n", new_Offset);
         dump(new_Offset, t->otherPins, fp, showEmpty);
         fprintf(fp, "%s\\end portmap\n", new_Offset);
      }

      if (hasNets(t) || showEmpty)
      {
         fprintf(fp, "%ssimple_signal_list Nets,\n", new_Offset);
         dump(new_Offset, t->Nets, fp, showEmpty);
         fprintf(fp, "%s\\end simple_signal_list\n", new_Offset);
      }

      if (hasExcludes(t) || showEmpty)
      {
         fprintf(fp, "%ssimple_signal_list excludes,\n", new_Offset);
         dump(new_Offset, t->excludes, fp, showEmpty);
         fprintf(fp, "%s\\end simple_signal_list\n", new_Offset);
      }

      if (hasInstances(t) || showEmpty)
      {
         fprintf(fp, "%smatch_list instances,\n", new_Offset);
         dump(new_Offset, t->instances, fp, showEmpty);
         fprintf(fp, "%s\\end match_list\n", new_Offset);
      }

      if (hasInstLabel(t) || showEmpty)
      {
         if (t->instLabel ne NULL)
            fprintf(fp, "%stext instLabel : %s\n", new_Offset, t->instLabel);
         else if (showEmpty)
            fprintf(fp, "%stext instLabel : NULL\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(tiecell_statement t,
                 size_t level = 0)
{
   if (t ne NULL)
   {
      if (level > 0)
      {

         Free(t->moduleName, level - 1);
         t->moduleName = NULL;

         Free(t->outputName, level - 1);
         t->outputName = NULL;

         Free(t->otherPins, level - 1);
         t->otherPins = NULL;

         Free(t->Nets, level - 1);
         t->Nets = NULL;

         Free(t->excludes, level - 1);
         t->excludes = NULL;

         Free(t->instances, level - 1);
         t->instances = NULL;

         if (t->instLabel ne NULL)
         {
            free((void *) t->instLabel);
            t->instLabel = NULL;
         }
      }


      free((void *) t);
   }
}
expfun void deepFree(tiecell_statement t)
{
   if (t ne NULL)
   {

      deepFree(t->moduleName);
      t->moduleName = NULL;

      deepFree(t->outputName);
      t->outputName = NULL;

      deepFree(t->otherPins);
      t->otherPins = NULL;

      deepFree(t->Nets);
      t->Nets = NULL;

      deepFree(t->excludes);
      t->excludes = NULL;

      deepFree(t->instances);
      t->instances = NULL;

      if (t->instLabel ne NULL)
      {
         free((void *) t->instLabel);
         t->instLabel = NULL;
      }

      free((void *) t);
   }
}
