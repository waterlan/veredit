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

#define instantiation_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "instance.h"
#include "instantiation_list.h"


expfun instantiation_list instantiation_listNew(void)
{
   instantiation_list i = (instantiation_list) malloc (sizeof(instantiation_list_struct));
   if (i != NULL)
   {
      i->array = NULL;
      i->size = 0;
   }
   else
      malloc_error("instantiation_listNew()");

   return i;
}
expfun instantiation_list instantiation_listNew(instance element)
{
   instantiation_list i = instantiation_listNew();

   if (element != NULL)
      add(element, i);

   return i;
}
expfun bool eqSelfArray(instantiation_list a,
                        instantiation_list b)
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
expfun bool eqArray(instantiation_list a,
                    instantiation_list b)
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
expfun bool eqSelf(instantiation_list a,
                   instantiation_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(instantiation_list a,
               instantiation_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun instance* getArray(instantiation_list i)
{
   if (i != NULL)
      return i->array;
   else
      return NULL;
}
expfun bool hasArray(instantiation_list i)
{
   if (isEmpty(i) == false)
      return true;
   else
      return false;
}
expfun size_t size(instantiation_list i)
{
   if (i != NULL)
      return i->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    instantiation_list set,
                    instance initVal = NULL)
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
            set->array = (instance *) malloc(sizeof(instance) * size);
         else
            set->array = (instance *) realloc((void *) set->array, sizeof(instance) * size);

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
expfun bool isEmpty(instantiation_list i)
{
   if (size(i) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(instance i,
                     instantiation_list set)
{
   insert(i, 0, set);
}
expfun void add(instance i,
                instantiation_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = i;
      else
         malloc_error("add()");
   }
}
expfun void put(instance i,
                size_t position,
                instantiation_list set,
                instance initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = i;
      else
         malloc_error("put(i, position, set, initVal)");
   }
}
expfun void insert(instance i,
                   size_t position,
                   instantiation_list set)
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
      put(i, position, set);
   }
}
expfun instance firstElement(instantiation_list i)
{
   if (isEmpty(i) == false)
      return i->array[0];
   else
      return NULL;
}
expfun instance elementAt(size_t position,
                          instantiation_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun instance elementAt(ssize_t position,
                          instantiation_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun instance lastElement(instantiation_list i)
{
   if (isEmpty(i) == false)
      return i->array[i->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   instantiation_list set,
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
                       instantiation_list set)
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
expfun instance popFirst(instantiation_list i)
{
   instance popElement = firstElement(i);

   if (isEmpty(i) == false)
      remove(0, i);

   return popElement;
}
expfun instance popElement(size_t position,
                           instantiation_list set)
{
   instance popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun instance popLast(instantiation_list i)
{
   instance popElement = lastElement(i);

   if (isEmpty(i) == false)
      remove(i->size - 1, i);

   return popElement;
}
expfun void append(instantiation_list src,
                   instantiation_list dest,
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
expfun void deepAppend(instantiation_list src,
                       instantiation_list dest)
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
expfun instantiation_list copy(instantiation_list src,
                               size_t level = 0)
{
   instantiation_list i;

   if (src == NULL)
      return NULL;
   else
   {
      i = (instantiation_list) malloc (sizeof(instantiation_list_struct));
      if (i != NULL)
      {
         i->array = NULL;
         i->size = 0;
         if (level > 0)
            append(src, i, level - 1);
         else
            append(src, i);
      }
      else
         malloc_error("copy()");

      return i;
   }
}
expfun instantiation_list deepCopy(instantiation_list src)
{
   instantiation_list i;

   if (src == NULL)
      return NULL;
   else
   {
      i = (instantiation_list) malloc (sizeof(instantiation_list_struct));
      if (i != NULL)
      {
         i->array = NULL;
         i->size = 0;
         deepAppend(src, i);
      }
      else
         malloc_error("deepCopy()");

      return i;
   }
}
expfun instantiation_list select(instantiation_list src,
                                 bool (*sel_f) (instance),
                                 bool state = true)
{
   instantiation_list set = instantiation_listNew();
   instance arrayElement;
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
                 instantiation_list i,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

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

      if (i->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%sinstance array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(i) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, i->size);

            index = 0;
            while(index < i->size)
            {

               fprintf(fp, "%sinstance array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, i), fp, showEmpty);
               fprintf(fp, "%s\\end instance[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(instantiation_list i,
                 size_t level = 0)
{
   size_t index;

   if (i ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < i->size)
         {
            Free(i->array[index], level - 1);

            index = index + 1;
         }
      }

      if (i->array ne NULL)
      {
         free((void *) i->array);
         i->array = NULL;
         i->size = 0;
      }

      free((void *) i);
   }
}
expfun void deepFree(instantiation_list i)
{
   size_t index;

   if (i ne NULL)
   {

      index = 0;
      while(index < i->size)
      {
         deepFree(i->array[index]);

         index = index + 1;
      }
      if (i->array ne NULL)
      {
         free((void *) i->array);
         i->array = NULL;
         i->size = 0;
      }

      free((void *) i);
   }
}
