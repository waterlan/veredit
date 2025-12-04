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

#define module_item_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "declaration.h"
#include "continuous_assign.h"
#include "instance.h"
#include "parameter_decl.h"
#include "module_item.h"


expfun module_item module_itemNew(declaration declItem = NULL,
                                  continuous_assign assignItem = NULL,
                                  instance instanceItem = NULL,
                                  text initialItem = NULL,
                                  text overrideItem = NULL,
                                  parameter_decl parameter_declItem = NULL)
{
   module_item m = (module_item) malloc (sizeof(module_item_struct));
   if (m != NULL)
   {
      m->declItem = declItem;
      m->assignItem = assignItem;
      m->instanceItem = instanceItem;
      m->initialItem = initialItem;
      m->overrideItem = overrideItem;
      m->parameter_declItem = parameter_declItem;
   }
   else
      malloc_error("module_itemNew()");

   return m;
}
expfun bool eqSelfDeclItem(declaration declItem,
                           module_item m)
{
   if ((declItem == NULL) || (hasDeclItem(m) == false))
      return false;
   else if (eqSelf(declItem, getDeclItem(m)))
      return true;
   else
      return false;
}
expfun bool eqDeclItem(declaration declItem,
                       module_item m)
{
   if ((declItem == NULL) || (hasDeclItem(m) == false))
      return false;
   else if (Eq(declItem, getDeclItem(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfAssignItem(continuous_assign assignItem,
                             module_item m)
{
   if ((assignItem == NULL) || (hasAssignItem(m) == false))
      return false;
   else if (eqSelf(assignItem, getAssignItem(m)))
      return true;
   else
      return false;
}
expfun bool eqAssignItem(continuous_assign assignItem,
                         module_item m)
{
   if ((assignItem == NULL) || (hasAssignItem(m) == false))
      return false;
   else if (Eq(assignItem, getAssignItem(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfInstanceItem(instance instanceItem,
                               module_item m)
{
   if ((instanceItem == NULL) || (hasInstanceItem(m) == false))
      return false;
   else if (eqSelf(instanceItem, getInstanceItem(m)))
      return true;
   else
      return false;
}
expfun bool eqInstanceItem(instance instanceItem,
                           module_item m)
{
   if ((instanceItem == NULL) || (hasInstanceItem(m) == false))
      return false;
   else if (Eq(instanceItem, getInstanceItem(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfInitialItem(text initialItem,
                              module_item m)
{
   if ((initialItem == NULL) || (hasInitialItem(m) == false))
      return false;
   else if (eqSelf(initialItem, getInitialItem(m)))
      return true;
   else
      return false;
}
expfun bool eqInitialItem(text initialItem,
                          module_item m)
{
   if ((initialItem == NULL) || (hasInitialItem(m) == false))
      return false;
   else if (Eq(initialItem, getInitialItem(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfOverrideItem(text overrideItem,
                               module_item m)
{
   if ((overrideItem == NULL) || (hasOverrideItem(m) == false))
      return false;
   else if (eqSelf(overrideItem, getOverrideItem(m)))
      return true;
   else
      return false;
}
expfun bool eqOverrideItem(text overrideItem,
                           module_item m)
{
   if ((overrideItem == NULL) || (hasOverrideItem(m) == false))
      return false;
   else if (Eq(overrideItem, getOverrideItem(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfParameter_declItem(parameter_decl parameter_declItem,
                                     module_item m)
{
   if ((parameter_declItem == NULL) || (hasParameter_declItem(m) == false))
      return false;
   else if (eqSelf(parameter_declItem, getParameter_declItem(m)))
      return true;
   else
      return false;
}
expfun bool eqParameter_declItem(parameter_decl parameter_declItem,
                                 module_item m)
{
   if ((parameter_declItem == NULL) || (hasParameter_declItem(m) == false))
      return false;
   else if (Eq(parameter_declItem, getParameter_declItem(m)))
      return true;
   else
      return false;
}
expfun bool eqSelf(module_item a,
                   module_item b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(module_item a,
               module_item b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqDeclItem(getDeclItem(a), b) == false)
      return false;
   else if (eqAssignItem(getAssignItem(a), b) == false)
      return false;
   else if (eqInstanceItem(getInstanceItem(a), b) == false)
      return false;
   else if (eqInitialItem(getInitialItem(a), b) == false)
      return false;
   else if (eqOverrideItem(getOverrideItem(a), b) == false)
      return false;
   else if (eqParameter_declItem(getParameter_declItem(a), b) == false)
      return false;
   else
      return true;
}
expfun declaration getDeclItem(module_item m)
{
   if (m != NULL)
      return m->declItem;
   else
      return NULL;
}
expfun continuous_assign getAssignItem(module_item m)
{
   if (m != NULL)
      return m->assignItem;
   else
      return NULL;
}
expfun instance getInstanceItem(module_item m)
{
   if (m != NULL)
      return m->instanceItem;
   else
      return NULL;
}
expfun text getInitialItem(module_item m)
{
   if (m != NULL)
      return m->initialItem;
   else
      return NULL;
}
expfun text getOverrideItem(module_item m)
{
   if (m != NULL)
      return m->overrideItem;
   else
      return NULL;
}
expfun parameter_decl getParameter_declItem(module_item m)
{
   if (m != NULL)
      return m->parameter_declItem;
   else
      return NULL;
}
expfun module_item setDeclItem(declaration declItem,
                               module_item m)
{
   if (m != NULL)
      m->declItem = declItem;
   return m;
}
expfun module_item setAssignItem(continuous_assign assignItem,
                                 module_item m)
{
   if (m != NULL)
      m->assignItem = assignItem;
   return m;
}
expfun module_item setInstanceItem(instance instanceItem,
                                   module_item m)
{
   if (m != NULL)
      m->instanceItem = instanceItem;
   return m;
}
expfun module_item setInitialItem(text initialItem,
                                  module_item m)
{
   if (m != NULL)
      m->initialItem = initialItem;
   return m;
}
expfun module_item setOverrideItem(text overrideItem,
                                   module_item m)
{
   if (m != NULL)
      m->overrideItem = overrideItem;
   return m;
}
expfun module_item setParameter_declItem(parameter_decl parameter_declItem,
                                         module_item m)
{
   if (m != NULL)
      m->parameter_declItem = parameter_declItem;
   return m;
}
expfun bool hasDeclItem(module_item m)
{
   if (getDeclItem(m) != NULL)
      return true;
   else
      return false;
}
expfun bool hasAssignItem(module_item m)
{
   if (getAssignItem(m) != NULL)
      return true;
   else
      return false;
}
expfun bool hasInstanceItem(module_item m)
{
   if (getInstanceItem(m) != NULL)
      return true;
   else
      return false;
}
expfun bool hasInitialItem(module_item m)
{
   if (getInitialItem(m) != NULL)
      return true;
   else
      return false;
}
expfun bool hasOverrideItem(module_item m)
{
   if (getOverrideItem(m) != NULL)
      return true;
   else
      return false;
}
expfun bool hasParameter_declItem(module_item m)
{
   if (getParameter_declItem(m) != NULL)
      return true;
   else
      return false;
}
expfun module_item copy(module_item src,
                        size_t level = 0)
{
   module_item m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module_item) malloc (sizeof(module_item_struct));
      if (m != NULL)
      {
         if (level > 0)
         {
            m->declItem = copy(src->declItem, level - 1);
            m->assignItem = copy(src->assignItem, level - 1);
            m->instanceItem = copy(src->instanceItem, level - 1);
            m->initialItem = textNew(src->initialItem);
            m->overrideItem = textNew(src->overrideItem);
            m->parameter_declItem = copy(src->parameter_declItem, level - 1);
         }
         else
         {
            m->declItem = src->declItem;
            m->assignItem = src->assignItem;
            m->instanceItem = src->instanceItem;
            m->initialItem = src->initialItem;
            m->overrideItem = src->overrideItem;
            m->parameter_declItem = src->parameter_declItem;
         }
      }
      else
         malloc_error("copy()");

      return m;
   }
}
expfun module_item deepCopy(module_item src)
{
   module_item m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module_item) malloc (sizeof(module_item_struct));
      if (m != NULL)
      {
         m->declItem = deepCopy(src->declItem);
         m->assignItem = deepCopy(src->assignItem);
         m->instanceItem = deepCopy(src->instanceItem);
         m->initialItem = textNew(src->initialItem);
         m->overrideItem = textNew(src->overrideItem);
         m->parameter_declItem = deepCopy(src->parameter_declItem);
      }
      else
         malloc_error("deepCopy()");

      return m;
   }
}
expfun void dump(text Offset,
                 module_item m,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (m == NULL)
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

      if (hasDeclItem(m) || showEmpty)
      {
         fprintf(fp, "%sdeclaration declItem,\n", new_Offset);
         dump(new_Offset, m->declItem, fp, showEmpty);
         fprintf(fp, "%s\\end declaration\n", new_Offset);
      }

      if (hasAssignItem(m) || showEmpty)
      {
         fprintf(fp, "%scontinuous_assign assignItem,\n", new_Offset);
         dump(new_Offset, m->assignItem, fp, showEmpty);
         fprintf(fp, "%s\\end continuous_assign\n", new_Offset);
      }

      if (hasInstanceItem(m) || showEmpty)
      {
         fprintf(fp, "%sinstance instanceItem,\n", new_Offset);
         dump(new_Offset, m->instanceItem, fp, showEmpty);
         fprintf(fp, "%s\\end instance\n", new_Offset);
      }

      if (hasInitialItem(m) || showEmpty)
      {
         if (m->initialItem ne NULL)
            fprintf(fp, "%stext initialItem : %s\n", new_Offset, m->initialItem);
         else if (showEmpty)
            fprintf(fp, "%stext initialItem : NULL\n", new_Offset);
      }

      if (hasOverrideItem(m) || showEmpty)
      {
         if (m->overrideItem ne NULL)
            fprintf(fp, "%stext overrideItem : %s\n", new_Offset, m->overrideItem);
         else if (showEmpty)
            fprintf(fp, "%stext overrideItem : NULL\n", new_Offset);
      }

      if (hasParameter_declItem(m) || showEmpty)
      {
         fprintf(fp, "%sparameter_decl parameter_declItem,\n", new_Offset);
         dump(new_Offset, m->parameter_declItem, fp, showEmpty);
         fprintf(fp, "%s\\end parameter_decl\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(module_item m,
                 size_t level = 0)
{
   if (m ne NULL)
   {
      if (level > 0)
      {

         Free(m->declItem, level - 1);
         m->declItem = NULL;

         Free(m->assignItem, level - 1);
         m->assignItem = NULL;

         Free(m->instanceItem, level - 1);
         m->instanceItem = NULL;

         if (m->initialItem ne NULL)
         {
            free((void *) m->initialItem);
            m->initialItem = NULL;
         }

         if (m->overrideItem ne NULL)
         {
            free((void *) m->overrideItem);
            m->overrideItem = NULL;
         }

         Free(m->parameter_declItem, level - 1);
         m->parameter_declItem = NULL;
      }


      free((void *) m);
   }
}
expfun void deepFree(module_item m)
{
   if (m ne NULL)
   {

      deepFree(m->declItem);
      m->declItem = NULL;

      deepFree(m->assignItem);
      m->assignItem = NULL;

      deepFree(m->instanceItem);
      m->instanceItem = NULL;

      if (m->initialItem ne NULL)
      {
         free((void *) m->initialItem);
         m->initialItem = NULL;
      }

      if (m->overrideItem ne NULL)
      {
         free((void *) m->overrideItem);
         m->overrideItem = NULL;
      }

      deepFree(m->parameter_declItem);
      m->parameter_declItem = NULL;

      free((void *) m);
   }
}
