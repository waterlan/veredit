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

#define translation_unit_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "verilog_item_list.h"
#include "module_edit_list.h"
#include "vnode.h"
#include "translation_unit.h"


expfun translation_unit translation_unitNew(verilog_item_list items = NULL,
                                            module_edit_list edits = NULL)
{
   translation_unit t = (translation_unit) malloc (sizeof(translation_unit_struct));
   if (t != NULL)
   {
      t->items = items;
      t->edits = edits;
      t->rootNode = NULL;
   }
   else
      malloc_error("translation_unitNew()");

   return t;
}
expfun bool eqSelfItems(verilog_item_list items,
                        translation_unit t)
{
   if ((items == NULL) || (hasItems(t) == false))
      return false;
   else if (eqSelf(items, getItems(t)))
      return true;
   else
      return false;
}
expfun bool eqItems(verilog_item_list items,
                    translation_unit t)
{
   if ((items == NULL) || (hasItems(t) == false))
      return false;
   else if (Eq(items, getItems(t)))
      return true;
   else
      return false;
}
expfun bool eqSelfEdits(module_edit_list edits,
                        translation_unit t)
{
   if ((edits == NULL) || (hasEdits(t) == false))
      return false;
   else if (eqSelf(edits, getEdits(t)))
      return true;
   else
      return false;
}
expfun bool eqEdits(module_edit_list edits,
                    translation_unit t)
{
   if ((edits == NULL) || (hasEdits(t) == false))
      return false;
   else if (Eq(edits, getEdits(t)))
      return true;
   else
      return false;
}
expfun bool eqSelfRootNode(vnode rootNode,
                           translation_unit t)
{
   if ((rootNode == NULL) || (hasRootNode(t) == false))
      return false;
   else if (eqSelf(rootNode, getRootNode(t)))
      return true;
   else
      return false;
}
expfun bool eqRootNode(vnode rootNode,
                       translation_unit t)
{
   if ((rootNode == NULL) || (hasRootNode(t) == false))
      return false;
   else if (Eq(rootNode, getRootNode(t)))
      return true;
   else
      return false;
}
expfun bool eqSelf(translation_unit a,
                   translation_unit b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(translation_unit a,
               translation_unit b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqItems(getItems(a), b) == false)
      return false;
   else if (eqEdits(getEdits(a), b) == false)
      return false;
   else if (eqRootNode(getRootNode(a), b) == false)
      return false;
   else
      return true;
}
expfun verilog_item_list getItems(translation_unit t)
{
   if (t != NULL)
      return t->items;
   else
      return NULL;
}
expfun module_edit_list getEdits(translation_unit t)
{
   if (t != NULL)
      return t->edits;
   else
      return NULL;
}
expfun vnode getRootNode(translation_unit t)
{
   if (t != NULL)
      return t->rootNode;
   else
      return NULL;
}
expfun translation_unit setItems(verilog_item_list items,
                                 translation_unit t)
{
   if (t != NULL)
      t->items = items;
   return t;
}
expfun translation_unit setEdits(module_edit_list edits,
                                 translation_unit t)
{
   if (t != NULL)
      t->edits = edits;
   return t;
}
expfun translation_unit setRootNode(vnode rootNode,
                                    translation_unit t)
{
   if (t != NULL)
      t->rootNode = rootNode;
   return t;
}
expfun bool hasItems(translation_unit t)
{
   if (isEmpty(getItems(t)) == false)
      return true;
   else
      return false;
}
expfun bool hasEdits(translation_unit t)
{
   if (isEmpty(getEdits(t)) == false)
      return true;
   else
      return false;
}
expfun bool hasRootNode(translation_unit t)
{
   if (getRootNode(t) != NULL)
      return true;
   else
      return false;
}
expfun translation_unit copy(translation_unit src,
                             size_t level = 0)
{
   translation_unit t;

   if (src == NULL)
      return NULL;
   else
   {
      t = (translation_unit) malloc (sizeof(translation_unit_struct));
      if (t != NULL)
      {
         if (level > 0)
         {
            t->items = copy(src->items, level - 1);
            t->edits = copy(src->edits, level - 1);
            t->rootNode = copy(src->rootNode, level - 1);
         }
         else
         {
            t->items = src->items;
            t->edits = src->edits;
            t->rootNode = src->rootNode;
         }
      }
      else
         malloc_error("copy()");

      return t;
   }
}
expfun translation_unit deepCopy(translation_unit src)
{
   translation_unit t;

   if (src == NULL)
      return NULL;
   else
   {
      t = (translation_unit) malloc (sizeof(translation_unit_struct));
      if (t != NULL)
      {
         t->items = deepCopy(src->items);
         t->edits = deepCopy(src->edits);
         t->rootNode = deepCopy(src->rootNode);
      }
      else
         malloc_error("deepCopy()");

      return t;
   }
}
expfun void dump(text Offset,
                 translation_unit t,
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

      if (hasItems(t) || showEmpty)
      {
         fprintf(fp, "%sverilog_item_list items,\n", new_Offset);
         dump(new_Offset, t->items, fp, showEmpty);
         fprintf(fp, "%s\\end verilog_item_list\n", new_Offset);
      }

      if (hasEdits(t) || showEmpty)
      {
         fprintf(fp, "%smodule_edit_list edits,\n", new_Offset);
         dump(new_Offset, t->edits, fp, showEmpty);
         fprintf(fp, "%s\\end module_edit_list\n", new_Offset);
      }

      if (hasRootNode(t) || showEmpty)
      {
         fprintf(fp, "%svnode rootNode,\n", new_Offset);
         dump(new_Offset, t->rootNode, fp, showEmpty);
         fprintf(fp, "%s\\end vnode\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(translation_unit t,
                 size_t level = 0)
{
   if (t ne NULL)
   {
      if (level > 0)
      {

         Free(t->items, level - 1);
         t->items = NULL;

         Free(t->edits, level - 1);
         t->edits = NULL;

         Free(t->rootNode, level - 1);
         t->rootNode = NULL;
      }


      free((void *) t);
   }
}
expfun void deepFree(translation_unit t)
{
   if (t ne NULL)
   {

      deepFree(t->items);
      t->items = NULL;

      deepFree(t->edits);
      t->edits = NULL;

      deepFree(t->rootNode);
      t->rootNode = NULL;

      free((void *) t);
   }
}
