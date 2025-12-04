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

#define edit_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "edit_element.h"
#include "edit_list.h"


expfun edit_list edit_listNew(void)
{
   edit_list e = (edit_list) malloc (sizeof(edit_list_struct));
   if (e != NULL)
   {
      e->array = NULL;
      e->size = 0;
   }
   else
      malloc_error("edit_listNew()");

   return e;
}
expfun edit_list edit_listNew(edit_element element)
{
   edit_list e = edit_listNew();

   if (element != NULL)
      add(element, e);

   return e;
}
expfun bool eqSelfArray(edit_list a,
                        edit_list b)
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
expfun bool eqArray(edit_list a,
                    edit_list b)
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
expfun bool eqSelf(edit_list a,
                   edit_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(edit_list a,
               edit_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun edit_element* getArray(edit_list e)
{
   if (e != NULL)
      return e->array;
   else
      return NULL;
}
expfun bool hasArray(edit_list e)
{
   if (isEmpty(e) == false)
      return true;
   else
      return false;
}
expfun size_t size(edit_list e)
{
   if (e != NULL)
      return e->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    edit_list set,
                    edit_element initVal = NULL)
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
            set->array = (edit_element *) malloc(sizeof(edit_element) * size);
         else
            set->array = (edit_element *) realloc((void *) set->array, sizeof(edit_element) * size);

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
expfun bool isEmpty(edit_list e)
{
   if (size(e) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(edit_element e,
                     edit_list set)
{
   insert(e, 0, set);
}
expfun void add(edit_element e,
                edit_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = e;
      else
         malloc_error("add()");
   }
}
expfun void put(edit_element e,
                size_t position,
                edit_list set,
                edit_element initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = e;
      else
         malloc_error("put(e, position, set, initVal)");
   }
}
expfun void insert(edit_element e,
                   size_t position,
                   edit_list set)
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
      put(e, position, set);
   }
}
expfun edit_element firstElement(edit_list e)
{
   if (isEmpty(e) == false)
      return e->array[0];
   else
      return NULL;
}
expfun edit_element elementAt(size_t position,
                              edit_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun edit_element elementAt(ssize_t position,
                              edit_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun edit_element lastElement(edit_list e)
{
   if (isEmpty(e) == false)
      return e->array[e->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   edit_list set,
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
                       edit_list set)
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
expfun edit_element popFirst(edit_list e)
{
   edit_element popElement = firstElement(e);

   if (isEmpty(e) == false)
      remove(0, e);

   return popElement;
}
expfun edit_element popElement(size_t position,
                               edit_list set)
{
   edit_element popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun edit_element popLast(edit_list e)
{
   edit_element popElement = lastElement(e);

   if (isEmpty(e) == false)
      remove(e->size - 1, e);

   return popElement;
}
expfun void append(edit_list src,
                   edit_list dest,
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
expfun void deepAppend(edit_list src,
                       edit_list dest)
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
expfun edit_list copy(edit_list src,
                      size_t level = 0)
{
   edit_list e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (edit_list) malloc (sizeof(edit_list_struct));
      if (e != NULL)
      {
         e->array = NULL;
         e->size = 0;
         if (level > 0)
            append(src, e, level - 1);
         else
            append(src, e);
      }
      else
         malloc_error("copy()");

      return e;
   }
}
expfun edit_list deepCopy(edit_list src)
{
   edit_list e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (edit_list) malloc (sizeof(edit_list_struct));
      if (e != NULL)
      {
         e->array = NULL;
         e->size = 0;
         deepAppend(src, e);
      }
      else
         malloc_error("deepCopy()");

      return e;
   }
}
expfun edit_list select(edit_list src,
                        bool (*sel_f) (edit_element),
                        bool state = true)
{
   edit_list set = edit_listNew();
   edit_element arrayElement;
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
                 edit_list e,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (e == NULL)
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

      if (e->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%sedit_element array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(e) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, e->size);

            index = 0;
            while(index < e->size)
            {

               fprintf(fp, "%sedit_element array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, e), fp, showEmpty);
               fprintf(fp, "%s\\end edit_element[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(edit_list e,
                 size_t level = 0)
{
   size_t index;

   if (e ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < e->size)
         {
            Free(e->array[index], level - 1);

            index = index + 1;
         }
      }

      if (e->array ne NULL)
      {
         free((void *) e->array);
         e->array = NULL;
         e->size = 0;
      }

      free((void *) e);
   }
}
expfun void deepFree(edit_list e)
{
   size_t index;

   if (e ne NULL)
   {

      index = 0;
      while(index < e->size)
      {
         deepFree(e->array[index]);

         index = index + 1;
      }
      if (e->array ne NULL)
      {
         free((void *) e->array);
         e->array = NULL;
         e->size = 0;
      }

      free((void *) e);
   }
}
