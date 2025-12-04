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

#define declaration_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "declaration.h"
#include "declaration_list.h"


expfun declaration_list declaration_listNew(void)
{
   declaration_list d = (declaration_list) malloc (sizeof(declaration_list_struct));
   if (d != NULL)
   {
      d->array = NULL;
      d->size = 0;
   }
   else
      malloc_error("declaration_listNew()");

   return d;
}
expfun declaration_list declaration_listNew(declaration element)
{
   declaration_list d = declaration_listNew();

   if (element != NULL)
      add(element, d);

   return d;
}
expfun bool eqSelfArray(declaration_list a,
                        declaration_list b)
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
expfun bool eqArray(declaration_list a,
                    declaration_list b)
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
expfun bool eqSelf(declaration_list a,
                   declaration_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(declaration_list a,
               declaration_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun declaration* getArray(declaration_list d)
{
   if (d != NULL)
      return d->array;
   else
      return NULL;
}
expfun bool hasArray(declaration_list d)
{
   if (isEmpty(d) == false)
      return true;
   else
      return false;
}
expfun size_t size(declaration_list d)
{
   if (d != NULL)
      return d->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    declaration_list set,
                    declaration initVal = NULL)
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
            set->array = (declaration *) malloc(sizeof(declaration) * size);
         else
            set->array = (declaration *) realloc((void *) set->array, sizeof(declaration) * size);

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
expfun bool isEmpty(declaration_list d)
{
   if (size(d) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(declaration d,
                     declaration_list set)
{
   insert(d, 0, set);
}
expfun void add(declaration d,
                declaration_list set)
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
expfun void put(declaration d,
                size_t position,
                declaration_list set,
                declaration initVal = NULL)
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
expfun void insert(declaration d,
                   size_t position,
                   declaration_list set)
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
expfun declaration firstElement(declaration_list d)
{
   if (isEmpty(d) == false)
      return d->array[0];
   else
      return NULL;
}
expfun declaration elementAt(size_t position,
                             declaration_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun declaration elementAt(ssize_t position,
                             declaration_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun declaration lastElement(declaration_list d)
{
   if (isEmpty(d) == false)
      return d->array[d->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   declaration_list set,
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
                       declaration_list set)
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
expfun declaration popFirst(declaration_list d)
{
   declaration popElement = firstElement(d);

   if (isEmpty(d) == false)
      remove(0, d);

   return popElement;
}
expfun declaration popElement(size_t position,
                              declaration_list set)
{
   declaration popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun declaration popLast(declaration_list d)
{
   declaration popElement = lastElement(d);

   if (isEmpty(d) == false)
      remove(d->size - 1, d);

   return popElement;
}
expfun void append(declaration_list src,
                   declaration_list dest,
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
expfun void deepAppend(declaration_list src,
                       declaration_list dest)
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
expfun declaration_list copy(declaration_list src,
                             size_t level = 0)
{
   declaration_list d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (declaration_list) malloc (sizeof(declaration_list_struct));
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
expfun declaration_list deepCopy(declaration_list src)
{
   declaration_list d;

   if (src == NULL)
      return NULL;
   else
   {
      d = (declaration_list) malloc (sizeof(declaration_list_struct));
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
expfun declaration_list select(declaration_list src,
                               bool (*sel_f) (declaration),
                               bool state = true)
{
   declaration_list set = declaration_listNew();
   declaration arrayElement;
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
                 declaration_list d,
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
            fprintf(fp, "%sdeclaration array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(d) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, d->size);

            index = 0;
            while(index < d->size)
            {

               fprintf(fp, "%sdeclaration array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, d), fp, showEmpty);
               fprintf(fp, "%s\\end declaration[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(declaration_list d,
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
expfun void deepFree(declaration_list d)
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
