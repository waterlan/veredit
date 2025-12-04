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

#define port_reference_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "port_reference.h"
#include "port_reference_list.h"


expfun port_reference_list port_reference_listNew(void)
{
   port_reference_list p = (port_reference_list) malloc (sizeof(port_reference_list_struct));
   if (p != NULL)
   {
      p->array = NULL;
      p->size = 0;
   }
   else
      malloc_error("port_reference_listNew()");

   return p;
}
expfun port_reference_list port_reference_listNew(port_reference element)
{
   port_reference_list p = port_reference_listNew();

   if (element != NULL)
      add(element, p);

   return p;
}
expfun bool eqSelfArray(port_reference_list a,
                        port_reference_list b)
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
expfun bool eqArray(port_reference_list a,
                    port_reference_list b)
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
expfun bool eqSelf(port_reference_list a,
                   port_reference_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(port_reference_list a,
               port_reference_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun port_reference* getArray(port_reference_list p)
{
   if (p != NULL)
      return p->array;
   else
      return NULL;
}
expfun bool hasArray(port_reference_list p)
{
   if (isEmpty(p) == false)
      return true;
   else
      return false;
}
expfun size_t size(port_reference_list p)
{
   if (p != NULL)
      return p->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    port_reference_list set,
                    port_reference initVal = NULL)
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
            set->array = (port_reference *) malloc(sizeof(port_reference) * size);
         else
            set->array = (port_reference *) realloc((void *) set->array, sizeof(port_reference) * size);

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
expfun bool isEmpty(port_reference_list p)
{
   if (size(p) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(port_reference p,
                     port_reference_list set)
{
   insert(p, 0, set);
}
expfun void add(port_reference p,
                port_reference_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = p;
      else
         malloc_error("add()");
   }
}
expfun void put(port_reference p,
                size_t position,
                port_reference_list set,
                port_reference initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = p;
      else
         malloc_error("put(p, position, set, initVal)");
   }
}
expfun void insert(port_reference p,
                   size_t position,
                   port_reference_list set)
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
      put(p, position, set);
   }
}
expfun port_reference firstElement(port_reference_list p)
{
   if (isEmpty(p) == false)
      return p->array[0];
   else
      return NULL;
}
expfun port_reference elementAt(size_t position,
                                port_reference_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun port_reference elementAt(ssize_t position,
                                port_reference_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun port_reference lastElement(port_reference_list p)
{
   if (isEmpty(p) == false)
      return p->array[p->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   port_reference_list set,
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
                       port_reference_list set)
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
expfun port_reference popFirst(port_reference_list p)
{
   port_reference popElement = firstElement(p);

   if (isEmpty(p) == false)
      remove(0, p);

   return popElement;
}
expfun port_reference popElement(size_t position,
                                 port_reference_list set)
{
   port_reference popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun port_reference popLast(port_reference_list p)
{
   port_reference popElement = lastElement(p);

   if (isEmpty(p) == false)
      remove(p->size - 1, p);

   return popElement;
}
expfun void append(port_reference_list src,
                   port_reference_list dest,
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
expfun void deepAppend(port_reference_list src,
                       port_reference_list dest)
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
expfun port_reference_list copy(port_reference_list src,
                                size_t level = 0)
{
   port_reference_list p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (port_reference_list) malloc (sizeof(port_reference_list_struct));
      if (p != NULL)
      {
         p->array = NULL;
         p->size = 0;
         if (level > 0)
            append(src, p, level - 1);
         else
            append(src, p);
      }
      else
         malloc_error("copy()");

      return p;
   }
}
expfun port_reference_list deepCopy(port_reference_list src)
{
   port_reference_list p;

   if (src == NULL)
      return NULL;
   else
   {
      p = (port_reference_list) malloc (sizeof(port_reference_list_struct));
      if (p != NULL)
      {
         p->array = NULL;
         p->size = 0;
         deepAppend(src, p);
      }
      else
         malloc_error("deepCopy()");

      return p;
   }
}
expfun port_reference_list select(port_reference_list src,
                                  bool (*sel_f) (port_reference),
                                  bool state = true)
{
   port_reference_list set = port_reference_listNew();
   port_reference arrayElement;
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
                 port_reference_list p,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (p == NULL)
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

      if (p->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%sport_reference array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(p) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, p->size);

            index = 0;
            while(index < p->size)
            {

               fprintf(fp, "%sport_reference array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, p), fp, showEmpty);
               fprintf(fp, "%s\\end port_reference[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(port_reference_list p,
                 size_t level = 0)
{
   size_t index;

   if (p ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < p->size)
         {
            Free(p->array[index], level - 1);

            index = index + 1;
         }
      }

      if (p->array ne NULL)
      {
         free((void *) p->array);
         p->array = NULL;
         p->size = 0;
      }

      free((void *) p);
   }
}
expfun void deepFree(port_reference_list p)
{
   size_t index;

   if (p ne NULL)
   {

      index = 0;
      while(index < p->size)
      {
         deepFree(p->array[index]);

         index = index + 1;
      }
      if (p->array ne NULL)
      {
         free((void *) p->array);
         p->array = NULL;
         p->size = 0;
      }

      free((void *) p);
   }
}
