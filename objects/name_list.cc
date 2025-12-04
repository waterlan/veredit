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

#define name_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "name_list.h"


expfun name_list name_listNew(void)
{
   name_list n = (name_list) malloc (sizeof(name_list_struct));
   if (n != NULL)
   {
      n->array = NULL;
      n->size = 0;
   }
   else
      malloc_error("name_listNew()");

   return n;
}
expfun name_list name_listNew(vname element)
{
   name_list n = name_listNew();

   if (element != NULL)
      add(element, n);

   return n;
}
expfun bool eqSelfArray(name_list a,
                        name_list b)
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
expfun bool eqArray(name_list a,
                    name_list b)
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
expfun bool eqSelf(name_list a,
                   name_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(name_list a,
               name_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun vname* getArray(name_list n)
{
   if (n != NULL)
      return n->array;
   else
      return NULL;
}
expfun bool hasArray(name_list n)
{
   if (isEmpty(n) == false)
      return true;
   else
      return false;
}
expfun size_t size(name_list n)
{
   if (n != NULL)
      return n->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    name_list set,
                    vname initVal = NULL)
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
            set->array = (vname *) malloc(sizeof(vname) * size);
         else
            set->array = (vname *) realloc((void *) set->array, sizeof(vname) * size);

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
expfun bool isEmpty(name_list n)
{
   if (size(n) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(vname v,
                     name_list set)
{
   insert(v, 0, set);
}
expfun void add(vname v,
                name_list set)
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
expfun void put(vname v,
                size_t position,
                name_list set,
                vname initVal = NULL)
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
expfun void insert(vname v,
                   size_t position,
                   name_list set)
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
expfun vname firstElement(name_list n)
{
   if (isEmpty(n) == false)
      return n->array[0];
   else
      return NULL;
}
expfun vname elementAt(size_t position,
                       name_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun vname elementAt(ssize_t position,
                       name_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun vname lastElement(name_list n)
{
   if (isEmpty(n) == false)
      return n->array[n->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   name_list set,
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
                       name_list set)
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
expfun vname popFirst(name_list n)
{
   vname popElement = firstElement(n);

   if (isEmpty(n) == false)
      remove(0, n);

   return popElement;
}
expfun vname popElement(size_t position,
                        name_list set)
{
   vname popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun vname popLast(name_list n)
{
   vname popElement = lastElement(n);

   if (isEmpty(n) == false)
      remove(n->size - 1, n);

   return popElement;
}
expfun void append(name_list src,
                   name_list dest,
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
expfun void deepAppend(name_list src,
                       name_list dest)
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
expfun name_list copy(name_list src,
                      size_t level = 0)
{
   name_list n;

   if (src == NULL)
      return NULL;
   else
   {
      n = (name_list) malloc (sizeof(name_list_struct));
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
expfun name_list deepCopy(name_list src)
{
   name_list n;

   if (src == NULL)
      return NULL;
   else
   {
      n = (name_list) malloc (sizeof(name_list_struct));
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
expfun name_list select(name_list src,
                        bool (*sel_f) (vname),
                        bool state = true)
{
   name_list set = name_listNew();
   vname arrayElement;
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
                 name_list n,
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
            fprintf(fp, "%svname array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(n) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, n->size);

            index = 0;
            while(index < n->size)
            {

               fprintf(fp, "%svname array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, n), fp, showEmpty);
               fprintf(fp, "%s\\end vname[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(name_list n,
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
            Free(n->array[index], level - 1);

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
expfun void deepFree(name_list n)
{
   size_t index;

   if (n ne NULL)
   {

      index = 0;
      while(index < n->size)
      {
         deepFree(n->array[index]);

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
