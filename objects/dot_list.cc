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

#define dot_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "dot.h"
#include "dot_list.h"


expfun dot_list dot_listNew(void)
{
   dot_list d = (dot_list) malloc (sizeof(dot_list_struct));
   if (d != NULL)
   {
      d->array = NULL;
      d->size = 0;
   }
   else
      malloc_error("dot_listNew()");

   return d;
}
expfun dot_list dot_listNew(dot element)
{
   dot_list d = dot_listNew();

   if (element != NULL)
      add(element, d);

   return d;
}
expfun bool eqSelfArray(dot_list a,
                        dot_list b)
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
expfun bool eqArray(dot_list a,
                    dot_list b)
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
expfun bool eqSelf(dot_list a,
                   dot_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(dot_list a,
               dot_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun dot* getArray(dot_list d)
{
   if (d != NULL)
      return d->array;
   else
      return NULL;
}
expfun bool hasArray(dot_list d)
{
   if (isEmpty(d) == false)
      return true;
   else
      return false;
}
expfun size_t size(dot_list d)
{
   if (d != NULL)
      return d->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    dot_list set,
                    dot initVal = NULL)
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
            set->array = (dot *) malloc(sizeof(dot) * size);
         else
            set->array = (dot *) realloc((void *) set->array, sizeof(dot) * size);

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
expfun bool isEmpty(dot_list d)
{
   if (size(d) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(dot d,
                     dot_list set)
{
   insert(d, 0, set);
}
expfun void add(dot d,
                dot_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = d;
      else
         malloc_error("add()");
   }
}
expfun void put(dot d,
                size_t position,
                dot_list set,
                dot initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = d;
      else
         malloc_error("put(d, position, set, initVal)");
   }
}
expfun void insert(dot d,
                   size_t position,
                   dot_list set)
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
      put(d, position, set);
   }
}
expfun dot firstElement(dot_list d)
{
   if (isEmpty(d) == false)
      return d->array[0];
   else
      return NULL;
}
expfun dot elementAt(size_t position,
                     dot_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun dot elementAt(ssize_t position,
                     dot_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun dot lastElement(dot_list d)
{
   if (isEmpty(d) == false)
      return d->array[d->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   dot_list set,
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
                       dot_list set)
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
expfun dot popFirst(dot_list d)
{
   dot popElement = firstElement(d);

   if (isEmpty(d) == false)
      remove(0, d);

   return popElement;
}
expfun dot popElement(size_t position,
                      dot_list set)
{
   dot popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun dot popLast(dot_list d)
{
   dot popElement = lastElement(d);

   if (isEmpty(d) == false)
      remove(d->size - 1, d);

   return popElement;
}
expfun void append(dot_list src,
                   dot_list dest,
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
expfun void deepAppend(dot_list src,
                       dot_list dest)
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
expfun dot_list copy(dot_list src,
                     size_t level = 0)
{
   dot_list d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (dot_list) malloc (sizeof(dot_list_struct));
      if (d != NULL)
      {
         d->array = NULL;
         d->size = 0;
         if (level > 0)
            append(src, d, level - 1);
         else
            append(src, d);
      }
      else
         malloc_error("copy()");

      return d;
   }
}
expfun dot_list deepCopy(dot_list src)
{
   dot_list d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (dot_list) malloc (sizeof(dot_list_struct));
      if (d != NULL)
      {
         d->array = NULL;
         d->size = 0;
         deepAppend(src, d);
      }
      else
         malloc_error("deepCopy()");

      return d;
   }
}
expfun dot_list select(dot_list src,
                       bool (*sel_f) (dot),
                       bool state = true)
{
   dot_list set = dot_listNew();
   dot arrayElement;
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
                 dot_list d,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (d == NULL)
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

      if (d->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%sdot array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(d) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, d->size);

            index = 0;
            while(index < d->size)
            {

               fprintf(fp, "%sdot array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, d), fp, showEmpty);
               fprintf(fp, "%s\\end dot[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(dot_list d,
                 size_t level = 0)
{
   size_t index;

   if (d ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < d->size)
         {
            Free(d->array[index], level - 1);

            index = index + 1;
         }
      }

      if (d->array ne NULL)
      {
         free((void *) d->array);
         d->array = NULL;
         d->size = 0;
      }

      free((void *) d);
   }
}
expfun void deepFree(dot_list d)
{
   size_t index;

   if (d ne NULL)
   {

      index = 0;
      while(index < d->size)
      {
         deepFree(d->array[index]);

         index = index + 1;
      }
      if (d->array ne NULL)
      {
         free((void *) d->array);
         d->array = NULL;
         d->size = 0;
      }

      free((void *) d);
   }
}
