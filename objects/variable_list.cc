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

#define variable_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "variable_name.h"
#include "variable_list.h"


expfun variable_list variable_listNew(void)
{
   variable_list v = (variable_list) malloc (sizeof(variable_list_struct));
   if (v != NULL)
   {
      v->array = NULL;
      v->size = 0;
   }
   else
      malloc_error("variable_listNew()");

   return v;
}
expfun variable_list variable_listNew(variable_name element)
{
   variable_list v = variable_listNew();

   if (element != NULL)
      add(element, v);

   return v;
}
expfun bool eqSelfArray(variable_list a,
                        variable_list b)
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
expfun bool eqArray(variable_list a,
                    variable_list b)
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
expfun bool eqSelf(variable_list a,
                   variable_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(variable_list a,
               variable_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun variable_name* getArray(variable_list v)
{
   if (v != NULL)
      return v->array;
   else
      return NULL;
}
expfun bool hasArray(variable_list v)
{
   if (isEmpty(v) == false)
      return true;
   else
      return false;
}
expfun size_t size(variable_list v)
{
   if (v != NULL)
      return v->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    variable_list set,
                    variable_name initVal = NULL)
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
            set->array = (variable_name *) malloc(sizeof(variable_name) * size);
         else
            set->array = (variable_name *) realloc((void *) set->array, sizeof(variable_name) * size);

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
expfun bool isEmpty(variable_list v)
{
   if (size(v) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(variable_name v,
                     variable_list set)
{
   insert(v, 0, set);
}
expfun void add(variable_name v,
                variable_list set)
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
expfun void put(variable_name v,
                size_t position,
                variable_list set,
                variable_name initVal = NULL)
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
expfun void insert(variable_name v,
                   size_t position,
                   variable_list set)
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
expfun variable_name firstElement(variable_list v)
{
   if (isEmpty(v) == false)
      return v->array[0];
   else
      return NULL;
}
expfun variable_name elementAt(size_t position,
                               variable_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun variable_name elementAt(ssize_t position,
                               variable_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun variable_name lastElement(variable_list v)
{
   if (isEmpty(v) == false)
      return v->array[v->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   variable_list set,
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
                       variable_list set)
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
expfun variable_name popFirst(variable_list v)
{
   variable_name popElement = firstElement(v);

   if (isEmpty(v) == false)
      remove(0, v);

   return popElement;
}
expfun variable_name popElement(size_t position,
                                variable_list set)
{
   variable_name popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun variable_name popLast(variable_list v)
{
   variable_name popElement = lastElement(v);

   if (isEmpty(v) == false)
      remove(v->size - 1, v);

   return popElement;
}
expfun void append(variable_list src,
                   variable_list dest,
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
expfun void deepAppend(variable_list src,
                       variable_list dest)
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
expfun variable_list copy(variable_list src,
                          size_t level = 0)
{
   variable_list v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (variable_list) malloc (sizeof(variable_list_struct));
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
expfun variable_list deepCopy(variable_list src)
{
   variable_list v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (variable_list) malloc (sizeof(variable_list_struct));
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
expfun variable_list select(variable_list src,
                            bool (*sel_f) (variable_name),
                            bool state = true)
{
   variable_list set = variable_listNew();
   variable_name arrayElement;
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
                 variable_list v,
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
            fprintf(fp, "%svariable_name array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(v) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, v->size);

            index = 0;
            while(index < v->size)
            {

               fprintf(fp, "%svariable_name array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, v), fp, showEmpty);
               fprintf(fp, "%s\\end variable_name[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(variable_list v,
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
expfun void deepFree(variable_list v)
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
