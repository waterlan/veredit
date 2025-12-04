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

#define nameset_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "nameset.h"


expfun nameset namesetNew(void)
{
   nameset n = (nameset) malloc (sizeof(nameset_struct));
   if (n != NULL)
   {
      n->array = NULL;
      n->size = 0;
   }
   else
      malloc_error("namesetNew()");

   return n;
}
expfun nameset namesetNew(text element)
{
   nameset n = namesetNew();

   if (element != NULL)
      add(element, n);

   return n;
}
expfun bool eqSelfArray(nameset a,
                        nameset b)
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
expfun bool eqArray(nameset a,
                    nameset b)
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
expfun bool eqSelf(nameset a,
                   nameset b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(nameset a,
               nameset b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun text* getArray(nameset n)
{
   if (n != NULL)
      return n->array;
   else
      return NULL;
}
expfun bool hasArray(nameset n)
{
   if (isEmpty(n) == false)
      return true;
   else
      return false;
}
expfun size_t size(nameset n)
{
   if (n != NULL)
      return n->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    nameset set,
                    text initVal = NULL)
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
            set->array = (text *) malloc(sizeof(text) * size);
         else
            set->array = (text *) realloc((void *) set->array, sizeof(text) * size);

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
expfun bool isEmpty(nameset n)
{
   if (size(n) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(text t,
                     nameset set)
{
   insert(t, 0, set);
}
expfun void add(text t,
                nameset set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = t;
      else
         malloc_error("add()");
   }
}
expfun void put(text t,
                size_t position,
                nameset set,
                text initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = t;
      else
         malloc_error("put(t, position, set, initVal)");
   }
}
expfun void insert(text t,
                   size_t position,
                   nameset set)
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
      put(t, position, set);
   }
}
expfun text firstElement(nameset n)
{
   if (isEmpty(n) == false)
      return n->array[0];
   else
      return NULL;
}
expfun text elementAt(size_t position,
                      nameset set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun text elementAt(ssize_t position,
                      nameset set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun text lastElement(nameset n)
{
   if (isEmpty(n) == false)
      return n->array[n->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   nameset set,
                   size_t level = 0)
{
   size_t index;
   if (set != NULL)
   {
      if (position < set->size)
      {
         if (level > 0)
         {
            if (set->array[position] ne NULL)
               free((void *) set->array[position]);
         }

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
                       nameset set)
{
   size_t index;
   if (set != NULL)
   {
      if (position < set->size)
      {
         if (set->array[position] ne NULL)
            free((void *) set->array[position]);

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
expfun text popFirst(nameset n)
{
   text popElement = firstElement(n);

   if (isEmpty(n) == false)
      remove(0, n);

   return popElement;
}
expfun text popElement(size_t position,
                       nameset set)
{
   text popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun text popLast(nameset n)
{
   text popElement = lastElement(n);

   if (isEmpty(n) == false)
      remove(n->size - 1, n);

   return popElement;
}
expfun void append(nameset src,
                   nameset dest,
                   size_t level = 0)
{
   if (src != NULL)
   {
      size_t index = 0;

      if (level > 0)
      {
         while(index < src->size)
         {
            add(textNew(elementAt(index, src)), dest);
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
expfun void deepAppend(nameset src,
                       nameset dest)
{
   if (src != NULL)
   {
      size_t index = 0;
      while(index < src->size)
      {
         add(textNew(elementAt(index, src)), dest);
         index = index + 1;
      }
   }
}
expfun nameset copy(nameset src,
                    size_t level = 0)
{
   nameset n;

   if (src == NULL)
      return NULL;
   else
   {
      n = (nameset) malloc (sizeof(nameset_struct));
      if (n != NULL)
      {
         n->array = NULL;
         n->size = 0;
         if (level > 0)
            append(src, n, level - 1);
         else
            append(src, n);
      }
      else
         malloc_error("copy()");

      return n;
   }
}
expfun nameset deepCopy(nameset src)
{
   nameset n;

   if (src == NULL)
      return NULL;
   else
   {
      n = (nameset) malloc (sizeof(nameset_struct));
      if (n != NULL)
      {
         n->array = NULL;
         n->size = 0;
         deepAppend(src, n);
      }
      else
         malloc_error("deepCopy()");

      return n;
   }
}
expfun nameset select(nameset src,
                      bool (*sel_f) (text),
                      bool state = true)
{
   nameset set = namesetNew();
   text arrayElement;
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
                 nameset n,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (n == NULL)
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

      if (n->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%stext array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(n) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, n->size);

            index = 0;
            while(index < n->size)
            {

               if (elementAt(index, n) ne NULL)
                  fprintf(fp, "%stext array[%zu] : %s\n", new_Offset, index, elementAt(index, n));
               else if (showEmpty)
                  fprintf(fp, "%stext array[%zu] : NULL\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(nameset n,
                 size_t level = 0)
{
   size_t index;

   if (n ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < n->size)
         {
            if (n->array[index] ne NULL)
               free((void *) n->array[index]);

            index = index + 1;
         }
      }

      if (n->array ne NULL)
      {
         free((void *) n->array);
         n->array = NULL;
         n->size = 0;
      }

      free((void *) n);
   }
}
expfun void deepFree(nameset n)
{
   size_t index;

   if (n ne NULL)
   {

      index = 0;
      while(index < n->size)
      {
         if (n->array[index] ne NULL)
            free((void *) n->array[index]);

         index = index + 1;
      }
      if (n->array ne NULL)
      {
         free((void *) n->array);
         n->array = NULL;
         n->size = 0;
      }

      free((void *) n);
   }
}
