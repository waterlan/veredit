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

#define verilog_item_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "verilog_item.h"
#include "verilog_item_list.h"


expfun verilog_item_list verilog_item_listNew(void)
{
   verilog_item_list v = (verilog_item_list) malloc (sizeof(verilog_item_list_struct));
   if (v != NULL)
   {
      v->array = NULL;
      v->size = 0;
   }
   else
      malloc_error("verilog_item_listNew()");

   return v;
}
expfun verilog_item_list verilog_item_listNew(verilog_item element)
{
   verilog_item_list v = verilog_item_listNew();

   if (element != NULL)
      add(element, v);

   return v;
}
expfun bool eqSelfArray(verilog_item_list a,
                        verilog_item_list b)
{
   size_t index;

   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else if (a->size != b->size)
      return false;
   else
   {
      index = 0;
      while(index < a->size)
      {
         if (eqSelf(elementAt(index, a), elementAt(index, b)) == false)
            return false;

         index = index + 1;
      }
      return true;
   }
}
expfun bool eqArray(verilog_item_list a,
                    verilog_item_list b)
{
   size_t index;

   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else if (a->size != b->size)
      return false;
   else
   {
      index = 0;
      while(index < a->size)
      {
         if (Eq(elementAt(index, a), elementAt(index, b)) == false)
            return false;

         index = index + 1;
      }
      return true;
   }
}
expfun bool eqSelf(verilog_item_list a,
                   verilog_item_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(verilog_item_list a,
               verilog_item_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun verilog_item* getArray(verilog_item_list v)
{
   if (v != NULL)
      return v->array;
   else
      return NULL;
}
expfun bool hasArray(verilog_item_list v)
{
   if (isEmpty(v) == false)
      return true;
   else
      return false;
}
expfun size_t size(verilog_item_list v)
{
   if (v != NULL)
      return v->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    verilog_item_list set,
                    verilog_item initVal = NULL)
{
   size_t index;
   if (set != NULL)
   {
      if (size <= 0)
      {
         if (isEmpty(set) eq false)
         {
            free((void *) set->array);
            set->array = NULL;
            set->size = 0;
         }
      }
      else if (size ne set->size)
      {
         if (isEmpty(set))
            set->array = (verilog_item *) malloc(sizeof(verilog_item) * size);
         else
            set->array = (verilog_item *) realloc((void *) set->array, sizeof(verilog_item) * size);

         if (set->array ne NULL)
         {
            index = set->size;
            while(index < size)
            {
               set->array[index] = initVal;
               index = index + 1;
            }
            set->size = size;
         }
         else
         {
            set->size = 0;
            malloc_error("setSize(size, set, initVal)");
         }
      }
   }
}
expfun bool isEmpty(verilog_item_list v)
{
   if (size(v) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(verilog_item v,
                     verilog_item_list set)
{
   insert(v, 0, set);
}
expfun void add(verilog_item v,
                verilog_item_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = v;
      else
         malloc_error("add()");
   }
}
expfun void put(verilog_item v,
                size_t position,
                verilog_item_list set,
                verilog_item initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = v;
      else
         malloc_error("put(v, position, set, initVal)");
   }
}
expfun void insert(verilog_item v,
                   size_t position,
                   verilog_item_list set)
{
   size_t index;
   if (set != NULL)
   {
      index = set->size;
      while(index > position)
      {
         put(elementAt(index - 1, set), index, set);
         index = index - 1;
      }
      put(v, position, set);
   }
}
expfun verilog_item firstElement(verilog_item_list v)
{
   if (isEmpty(v) == false)
      return v->array[0];
   else
      return NULL;
}
expfun verilog_item elementAt(size_t position,
                              verilog_item_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun verilog_item elementAt(ssize_t position,
                              verilog_item_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun verilog_item lastElement(verilog_item_list v)
{
   if (isEmpty(v) == false)
      return v->array[v->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   verilog_item_list set,
                   size_t level = 0)
{
   size_t index;
   if (set != NULL)
   {
      if (position < set->size)
      {
         if (level > 0)
            Free(set->array[position], level - 1);

         index = position + 1;
         while(index < set->size)
         {
            put(elementAt(index, set), index - 1, set);
            index = index + 1;
         }
         setSize(set->size - 1, set);
      }
   }
}
expfun void deepRemove(size_t position,
                       verilog_item_list set)
{
   size_t index;
   if (set != NULL)
   {
      if (position < set->size)
      {
         deepFree(set->array[position]);

         index = position + 1;
         while(index < set->size)
         {
            put(elementAt(index, set), index - 1, set);
            index = index + 1;
         }
         setSize(set->size - 1, set);
      }
   }
}
expfun verilog_item popFirst(verilog_item_list v)
{
   verilog_item popElement = firstElement(v);

   if (isEmpty(v) == false)
      remove(0, v);

   return popElement;
}
expfun verilog_item popElement(size_t position,
                               verilog_item_list set)
{
   verilog_item popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun verilog_item popLast(verilog_item_list v)
{
   verilog_item popElement = lastElement(v);

   if (isEmpty(v) == false)
      remove(v->size - 1, v);

   return popElement;
}
expfun void append(verilog_item_list src,
                   verilog_item_list dest,
                   size_t level = 0)
{
   if (src != NULL)
   {
      size_t index = 0;

      if (level > 0)
      {
         while(index < src->size)
         {
            add(copy(elementAt(index, src), level - 1), dest);
            index = index + 1;
         }
      }
      else
      {
         while(index < src->size)
         {
            add(elementAt(index, src), dest);
            index = index + 1;
         }
      }
   }
}
expfun void deepAppend(verilog_item_list src,
                       verilog_item_list dest)
{
   if (src != NULL)
   {
      size_t index = 0;
      while(index < src->size)
      {
         add(deepCopy(elementAt(index, src)), dest);
         index = index + 1;
      }
   }
}
expfun verilog_item_list copy(verilog_item_list src,
                              size_t level = 0)
{
   verilog_item_list v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (verilog_item_list) malloc (sizeof(verilog_item_list_struct));
      if (v != NULL)
      {
         v->array = NULL;
         v->size = 0;
         if (level > 0)
            append(src, v, level - 1);
         else
            append(src, v);
      }
      else
         malloc_error("copy()");

      return v;
   }
}
expfun verilog_item_list deepCopy(verilog_item_list src)
{
   verilog_item_list v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (verilog_item_list) malloc (sizeof(verilog_item_list_struct));
      if (v != NULL)
      {
         v->array = NULL;
         v->size = 0;
         deepAppend(src, v);
      }
      else
         malloc_error("deepCopy()");

      return v;
   }
}
expfun verilog_item_list select(verilog_item_list src,
                                bool (*sel_f) (verilog_item),
                                bool state = true)
{
   verilog_item_list set = verilog_item_listNew();
   verilog_item arrayElement;
   size_t index = 0;
   while(index < size(src))
   {
      arrayElement = elementAt(index, src);
      if (sel_f(arrayElement) eq state)
         add(arrayElement, set);

      index = index + 1;
   }

   return set;
}
expfun void dump(text Offset,
                 verilog_item_list v,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

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

      if (v->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%sverilog_item array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(v) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, v->size);

            index = 0;
            while(index < v->size)
            {

               fprintf(fp, "%sverilog_item array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, v), fp, showEmpty);
               fprintf(fp, "%s\\end verilog_item[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(verilog_item_list v,
                 size_t level = 0)
{
   size_t index;

   if (v ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < v->size)
         {
            Free(v->array[index], level - 1);

            index = index + 1;
         }
      }

      if (v->array ne NULL)
      {
         free((void *) v->array);
         v->array = NULL;
         v->size = 0;
      }

      free((void *) v);
   }
}
expfun void deepFree(verilog_item_list v)
{
   size_t index;

   if (v ne NULL)
   {

      index = 0;
      while(index < v->size)
      {
         deepFree(v->array[index]);

         index = index + 1;
      }
      if (v->array ne NULL)
      {
         free((void *) v->array);
         v->array = NULL;
         v->size = 0;
      }

      free((void *) v);
   }
}
