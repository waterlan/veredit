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

#define assign_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "continuous_assign.h"
#include "assign_list.h"


expfun assign_list assign_listNew(void)
{
   assign_list a = (assign_list) malloc (sizeof(assign_list_struct));
   if (a != NULL)
   {
      a->array = NULL;
      a->size = 0;
   }
   else
      malloc_error("assign_listNew()");

   return a;
}
expfun assign_list assign_listNew(continuous_assign element)
{
   assign_list a = assign_listNew();

   if (element != NULL)
      add(element, a);

   return a;
}
expfun bool eqSelfArray(assign_list a,
                        assign_list b)
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
expfun bool eqArray(assign_list a,
                    assign_list b)
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
expfun bool eqSelf(assign_list a,
                   assign_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(assign_list a,
               assign_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun continuous_assign* getArray(assign_list a)
{
   if (a != NULL)
      return a->array;
   else
      return NULL;
}
expfun bool hasArray(assign_list a)
{
   if (isEmpty(a) == false)
      return true;
   else
      return false;
}
expfun size_t size(assign_list a)
{
   if (a != NULL)
      return a->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    assign_list set,
                    continuous_assign initVal = NULL)
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
            set->array = (continuous_assign *) malloc(sizeof(continuous_assign) * size);
         else
            set->array = (continuous_assign *) realloc((void *) set->array, sizeof(continuous_assign) * size);

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
expfun bool isEmpty(assign_list a)
{
   if (size(a) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(continuous_assign c,
                     assign_list set)
{
   insert(c, 0, set);
}
expfun void add(continuous_assign c,
                assign_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = c;
      else
         malloc_error("add()");
   }
}
expfun void put(continuous_assign c,
                size_t position,
                assign_list set,
                continuous_assign initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = c;
      else
         malloc_error("put(c, position, set, initVal)");
   }
}
expfun void insert(continuous_assign c,
                   size_t position,
                   assign_list set)
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
      put(c, position, set);
   }
}
expfun continuous_assign firstElement(assign_list a)
{
   if (isEmpty(a) == false)
      return a->array[0];
   else
      return NULL;
}
expfun continuous_assign elementAt(size_t position,
                                   assign_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun continuous_assign elementAt(ssize_t position,
                                   assign_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun continuous_assign lastElement(assign_list a)
{
   if (isEmpty(a) == false)
      return a->array[a->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   assign_list set,
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
                       assign_list set)
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
expfun continuous_assign popFirst(assign_list a)
{
   continuous_assign popElement = firstElement(a);

   if (isEmpty(a) == false)
      remove(0, a);

   return popElement;
}
expfun continuous_assign popElement(size_t position,
                                    assign_list set)
{
   continuous_assign popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun continuous_assign popLast(assign_list a)
{
   continuous_assign popElement = lastElement(a);

   if (isEmpty(a) == false)
      remove(a->size - 1, a);

   return popElement;
}
expfun void append(assign_list src,
                   assign_list dest,
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
expfun void deepAppend(assign_list src,
                       assign_list dest)
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
expfun assign_list copy(assign_list src,
                        size_t level = 0)
{
   assign_list a;

   if (src == NULL)
      return NULL;
   else
   {
      a = (assign_list) malloc (sizeof(assign_list_struct));
      if (a != NULL)
      {
         a->array = NULL;
         a->size = 0;
         if (level > 0)
            append(src, a, level - 1);
         else
            append(src, a);
      }
      else
         malloc_error("copy()");

      return a;
   }
}
expfun assign_list deepCopy(assign_list src)
{
   assign_list a;

   if (src == NULL)
      return NULL;
   else
   {
      a = (assign_list) malloc (sizeof(assign_list_struct));
      if (a != NULL)
      {
         a->array = NULL;
         a->size = 0;
         deepAppend(src, a);
      }
      else
         malloc_error("deepCopy()");

      return a;
   }
}
expfun assign_list select(assign_list src,
                          bool (*sel_f) (continuous_assign),
                          bool state = true)
{
   assign_list set = assign_listNew();
   continuous_assign arrayElement;
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
                 assign_list a,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (a == NULL)
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

      if (a->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%scontinuous_assign array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(a) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, a->size);

            index = 0;
            while(index < a->size)
            {

               fprintf(fp, "%scontinuous_assign array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, a), fp, showEmpty);
               fprintf(fp, "%s\\end continuous_assign[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(assign_list a,
                 size_t level = 0)
{
   size_t index;

   if (a ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < a->size)
         {
            Free(a->array[index], level - 1);

            index = index + 1;
         }
      }

      if (a->array ne NULL)
      {
         free((void *) a->array);
         a->array = NULL;
         a->size = 0;
      }

      free((void *) a);
   }
}
expfun void deepFree(assign_list a)
{
   size_t index;

   if (a ne NULL)
   {

      index = 0;
      while(index < a->size)
      {
         deepFree(a->array[index]);

         index = index + 1;
      }
      if (a->array ne NULL)
      {
         free((void *) a->array);
         a->array = NULL;
         a->size = 0;
      }

      free((void *) a);
   }
}
