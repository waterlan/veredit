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

#define match_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "match_item.h"
#include "match_list.h"


expfun match_list match_listNew(void)
{
   match_list m = (match_list) malloc (sizeof(match_list_struct));
   if (m != NULL)
   {
      m->array = NULL;
      m->size = 0;
   }
   else
      malloc_error("match_listNew()");

   return m;
}
expfun match_list match_listNew(match_item element)
{
   match_list m = match_listNew();

   if (element != NULL)
      add(element, m);

   return m;
}
expfun bool eqSelfArray(match_list a,
                        match_list b)
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
expfun bool eqArray(match_list a,
                    match_list b)
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
expfun bool eqSelf(match_list a,
                   match_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(match_list a,
               match_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun match_item* getArray(match_list m)
{
   if (m != NULL)
      return m->array;
   else
      return NULL;
}
expfun bool hasArray(match_list m)
{
   if (isEmpty(m) == false)
      return true;
   else
      return false;
}
expfun size_t size(match_list m)
{
   if (m != NULL)
      return m->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    match_list set,
                    match_item initVal = NULL)
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
            set->array = (match_item *) malloc(sizeof(match_item) * size);
         else
            set->array = (match_item *) realloc((void *) set->array, sizeof(match_item) * size);

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
expfun bool isEmpty(match_list m)
{
   if (size(m) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(match_item m,
                     match_list set)
{
   insert(m, 0, set);
}
expfun void add(match_item m,
                match_list set)
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
expfun void put(match_item m,
                size_t position,
                match_list set,
                match_item initVal = NULL)
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
expfun void insert(match_item m,
                   size_t position,
                   match_list set)
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
expfun match_item firstElement(match_list m)
{
   if (isEmpty(m) == false)
      return m->array[0];
   else
      return NULL;
}
expfun match_item elementAt(size_t position,
                            match_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun match_item elementAt(ssize_t position,
                            match_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun match_item lastElement(match_list m)
{
   if (isEmpty(m) == false)
      return m->array[m->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   match_list set,
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
                       match_list set)
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
expfun match_item popFirst(match_list m)
{
   match_item popElement = firstElement(m);

   if (isEmpty(m) == false)
      remove(0, m);

   return popElement;
}
expfun match_item popElement(size_t position,
                             match_list set)
{
   match_item popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun match_item popLast(match_list m)
{
   match_item popElement = lastElement(m);

   if (isEmpty(m) == false)
      remove(m->size - 1, m);

   return popElement;
}
expfun void append(match_list src,
                   match_list dest,
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
expfun void deepAppend(match_list src,
                       match_list dest)
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
expfun match_list copy(match_list src,
                       size_t level = 0)
{
   match_list m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (match_list) malloc (sizeof(match_list_struct));
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
expfun match_list deepCopy(match_list src)
{
   match_list m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (match_list) malloc (sizeof(match_list_struct));
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
expfun match_list select(match_list src,
                         bool (*sel_f) (match_item),
                         bool state = true)
{
   match_list set = match_listNew();
   match_item arrayElement;
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
                 match_list m,
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
            fprintf(fp, "%smatch_item array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(m) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, m->size);

            index = 0;
            while(index < m->size)
            {

               fprintf(fp, "%smatch_item array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, m), fp, showEmpty);
               fprintf(fp, "%s\\end match_item[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(match_list m,
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
expfun void deepFree(match_list m)
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
