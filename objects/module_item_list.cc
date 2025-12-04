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

#define module_item_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "module_item.h"
#include "module_item_list.h"


expfun module_item_list module_item_listNew(void)
{
   module_item_list m = (module_item_list) malloc (sizeof(module_item_list_struct));
   if (m != NULL)
   {
      m->array = NULL;
      m->size = 0;
   }
   else
      malloc_error("module_item_listNew()");

   return m;
}
expfun module_item_list module_item_listNew(module_item element)
{
   module_item_list m = module_item_listNew();

   if (element != NULL)
      add(element, m);

   return m;
}
expfun bool eqSelfArray(module_item_list a,
                        module_item_list b)
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
expfun bool eqArray(module_item_list a,
                    module_item_list b)
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
expfun bool eqSelf(module_item_list a,
                   module_item_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(module_item_list a,
               module_item_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun module_item* getArray(module_item_list m)
{
   if (m != NULL)
      return m->array;
   else
      return NULL;
}
expfun bool hasArray(module_item_list m)
{
   if (isEmpty(m) == false)
      return true;
   else
      return false;
}
expfun size_t size(module_item_list m)
{
   if (m != NULL)
      return m->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    module_item_list set,
                    module_item initVal = NULL)
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
            set->array = (module_item *) malloc(sizeof(module_item) * size);
         else
            set->array = (module_item *) realloc((void *) set->array, sizeof(module_item) * size);

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
expfun bool isEmpty(module_item_list m)
{
   if (size(m) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(module_item m,
                     module_item_list set)
{
   insert(m, 0, set);
}
expfun void add(module_item m,
                module_item_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = m;
      else
         malloc_error("add()");
   }
}
expfun void put(module_item m,
                size_t position,
                module_item_list set,
                module_item initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = m;
      else
         malloc_error("put(m, position, set, initVal)");
   }
}
expfun void insert(module_item m,
                   size_t position,
                   module_item_list set)
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
      put(m, position, set);
   }
}
expfun module_item firstElement(module_item_list m)
{
   if (isEmpty(m) == false)
      return m->array[0];
   else
      return NULL;
}
expfun module_item elementAt(size_t position,
                             module_item_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun module_item elementAt(ssize_t position,
                             module_item_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun module_item lastElement(module_item_list m)
{
   if (isEmpty(m) == false)
      return m->array[m->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   module_item_list set,
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
                       module_item_list set)
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
expfun module_item popFirst(module_item_list m)
{
   module_item popElement = firstElement(m);

   if (isEmpty(m) == false)
      remove(0, m);

   return popElement;
}
expfun module_item popElement(size_t position,
                              module_item_list set)
{
   module_item popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun module_item popLast(module_item_list m)
{
   module_item popElement = lastElement(m);

   if (isEmpty(m) == false)
      remove(m->size - 1, m);

   return popElement;
}
expfun void append(module_item_list src,
                   module_item_list dest,
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
expfun void deepAppend(module_item_list src,
                       module_item_list dest)
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
expfun module_item_list copy(module_item_list src,
                             size_t level = 0)
{
   module_item_list m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module_item_list) malloc (sizeof(module_item_list_struct));
      if (m != NULL)
      {
         m->array = NULL;
         m->size = 0;
         if (level > 0)
            append(src, m, level - 1);
         else
            append(src, m);
      }
      else
         malloc_error("copy()");

      return m;
   }
}
expfun module_item_list deepCopy(module_item_list src)
{
   module_item_list m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module_item_list) malloc (sizeof(module_item_list_struct));
      if (m != NULL)
      {
         m->array = NULL;
         m->size = 0;
         deepAppend(src, m);
      }
      else
         malloc_error("deepCopy()");

      return m;
   }
}
expfun module_item_list select(module_item_list src,
                               bool (*sel_f) (module_item),
                               bool state = true)
{
   module_item_list set = module_item_listNew();
   module_item arrayElement;
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
                 module_item_list m,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

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

      if (m->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%smodule_item array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(m) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, m->size);

            index = 0;
            while(index < m->size)
            {

               fprintf(fp, "%smodule_item array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, m), fp, showEmpty);
               fprintf(fp, "%s\\end module_item[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(module_item_list m,
                 size_t level = 0)
{
   size_t index;

   if (m ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < m->size)
         {
            Free(m->array[index], level - 1);

            index = index + 1;
         }
      }

      if (m->array ne NULL)
      {
         free((void *) m->array);
         m->array = NULL;
         m->size = 0;
      }

      free((void *) m);
   }
}
expfun void deepFree(module_item_list m)
{
   size_t index;

   if (m ne NULL)
   {

      index = 0;
      while(index < m->size)
      {
         deepFree(m->array[index]);

         index = index + 1;
      }
      if (m->array ne NULL)
      {
         free((void *) m->array);
         m->array = NULL;
         m->size = 0;
      }

      free((void *) m);
   }
}
