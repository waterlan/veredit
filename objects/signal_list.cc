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

#define signal_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "Signal.h"
#include "signal_list.h"


expfun signal_list signal_listNew(void)
{
   signal_list s = (signal_list) malloc (sizeof(signal_list_struct));
   if (s != NULL)
   {
      s->array = NULL;
      s->size = 0;
   }
   else
      malloc_error("signal_listNew()");

   return s;
}
expfun signal_list signal_listNew(Signal element)
{
   signal_list s = signal_listNew();

   if (element != NULL)
      add(element, s);

   return s;
}
expfun bool eqSelfArray(signal_list a,
                        signal_list b)
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
expfun bool eqArray(signal_list a,
                    signal_list b)
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
expfun bool eqSelf(signal_list a,
                   signal_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(signal_list a,
               signal_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun Signal* getArray(signal_list s)
{
   if (s != NULL)
      return s->array;
   else
      return NULL;
}
expfun bool hasArray(signal_list s)
{
   if (isEmpty(s) == false)
      return true;
   else
      return false;
}
expfun size_t size(signal_list s)
{
   if (s != NULL)
      return s->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    signal_list set,
                    Signal initVal = NULL)
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
            set->array = (Signal *) malloc(sizeof(Signal) * size);
         else
            set->array = (Signal *) realloc((void *) set->array, sizeof(Signal) * size);

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
expfun bool isEmpty(signal_list s)
{
   if (size(s) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(Signal s,
                     signal_list set)
{
   insert(s, 0, set);
}
expfun void add(Signal s,
                signal_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = s;
      else
         malloc_error("add()");
   }
}
expfun void put(Signal s,
                size_t position,
                signal_list set,
                Signal initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = s;
      else
         malloc_error("put(s, position, set, initVal)");
   }
}
expfun void insert(Signal s,
                   size_t position,
                   signal_list set)
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
      put(s, position, set);
   }
}
expfun Signal firstElement(signal_list s)
{
   if (isEmpty(s) == false)
      return s->array[0];
   else
      return NULL;
}
expfun Signal elementAt(size_t position,
                        signal_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun Signal elementAt(ssize_t position,
                        signal_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun Signal lastElement(signal_list s)
{
   if (isEmpty(s) == false)
      return s->array[s->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   signal_list set,
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
                       signal_list set)
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
expfun Signal popFirst(signal_list s)
{
   Signal popElement = firstElement(s);

   if (isEmpty(s) == false)
      remove(0, s);

   return popElement;
}
expfun Signal popElement(size_t position,
                         signal_list set)
{
   Signal popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun Signal popLast(signal_list s)
{
   Signal popElement = lastElement(s);

   if (isEmpty(s) == false)
      remove(s->size - 1, s);

   return popElement;
}
expfun void append(signal_list src,
                   signal_list dest,
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
expfun void deepAppend(signal_list src,
                       signal_list dest)
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
expfun signal_list copy(signal_list src,
                        size_t level = 0)
{
   signal_list s;

   if (src == NULL)
      return NULL;
   else
   {
      s = (signal_list) malloc (sizeof(signal_list_struct));
      if (s != NULL)
      {
         s->array = NULL;
         s->size = 0;
         if (level > 0)
            append(src, s, level - 1);
         else
            append(src, s);
      }
      else
         malloc_error("copy()");

      return s;
   }
}
expfun signal_list deepCopy(signal_list src)
{
   signal_list s;

   if (src == NULL)
      return NULL;
   else
   {
      s = (signal_list) malloc (sizeof(signal_list_struct));
      if (s != NULL)
      {
         s->array = NULL;
         s->size = 0;
         deepAppend(src, s);
      }
      else
         malloc_error("deepCopy()");

      return s;
   }
}
expfun signal_list select(signal_list src,
                          bool (*sel_f) (Signal),
                          bool state = true)
{
   signal_list set = signal_listNew();
   Signal arrayElement;
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
                 signal_list s,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (s == NULL)
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

      if (s->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%sSignal array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(s) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, s->size);

            index = 0;
            while(index < s->size)
            {

               fprintf(fp, "%sSignal array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, s), fp, showEmpty);
               fprintf(fp, "%s\\end Signal[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(signal_list s,
                 size_t level = 0)
{
   size_t index;

   if (s ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < s->size)
         {
            Free(s->array[index], level - 1);

            index = index + 1;
         }
      }

      if (s->array ne NULL)
      {
         free((void *) s->array);
         s->array = NULL;
         s->size = 0;
      }

      free((void *) s);
   }
}
expfun void deepFree(signal_list s)
{
   size_t index;

   if (s ne NULL)
   {

      index = 0;
      while(index < s->size)
      {
         deepFree(s->array[index]);

         index = index + 1;
      }
      if (s->array ne NULL)
      {
         free((void *) s->array);
         s->array = NULL;
         s->size = 0;
      }

      free((void *) s);
   }
}
