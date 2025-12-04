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

#define module_edit_list_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "module_edit.h"
#include "module_edit_list.h"


expfun module_edit_list module_edit_listNew(void)
{
   module_edit_list m = (module_edit_list) malloc (sizeof(module_edit_list_struct));
   if (m != NULL)
   {
      m->array = NULL;
      m->size = 0;
   }
   else
      malloc_error("module_edit_listNew()");

   return m;
}
expfun module_edit_list module_edit_listNew(module_edit element)
{
   module_edit_list m = module_edit_listNew();

   if (element != NULL)
      add(element, m);

   return m;
}
expfun bool eqSelfArray(module_edit_list a,
                        module_edit_list b)
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
expfun bool eqArray(module_edit_list a,
                    module_edit_list b)
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
expfun bool eqSelf(module_edit_list a,
                   module_edit_list b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(module_edit_list a,
               module_edit_list b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqArray(a, b) == false)
      return false;
   else
      return true;
}
expfun module_edit* getArray(module_edit_list m)
{
   if (m != NULL)
      return m->array;
   else
      return NULL;
}
expfun bool hasArray(module_edit_list m)
{
   if (isEmpty(m) == false)
      return true;
   else
      return false;
}
expfun size_t size(module_edit_list m)
{
   if (m != NULL)
      return m->size;
   else
      return 0;
}
expfun void setSize(size_t size,
                    module_edit_list set,
                    module_edit initVal = NULL)
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
            set->array = (module_edit *) malloc(sizeof(module_edit) * size);
         else
            set->array = (module_edit *) realloc((void *) set->array, sizeof(module_edit) * size);

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
expfun bool isEmpty(module_edit_list m)
{
   if (size(m) > 0)
      return false;
   else
      return true;
}
expfun void addFirst(module_edit m,
                     module_edit_list set)
{
   insert(m, 0, set);
}
expfun void add(module_edit m,
                module_edit_list set)
{
   if (set != NULL)
   {
      setSize(set->size + 1, set);
      if (set->array != NULL)
         set->array[set->size - 1] = m;
      else
         malloc_error("add()");
   }
}
expfun void put(module_edit m,
                size_t position,
                module_edit_list set,
                module_edit initVal = NULL)
{
   if (set != NULL)
   {
      if (position >= set->size)
         setSize(position + 1, set, initVal);
      if (set->array != NULL)
         set->array[position] = m;
      else
         malloc_error("put(m, position, set, initVal)");
   }
}
expfun void insert(module_edit m,
                   size_t position,
                   module_edit_list set)
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
      put(m, position, set);
   }
}
expfun module_edit firstElement(module_edit_list m)
{
   if (isEmpty(m) == false)
      return m->array[0];
   else
      return NULL;
}
expfun module_edit elementAt(size_t position,
                             module_edit_list set)
{
   if (set != NULL)
   {
      if (position < set->size)
         return set->array[position];
   }

   return NULL;
}
expfun module_edit elementAt(ssize_t position,
                             module_edit_list set)
{
   if (set != NULL)
   {
      if (0 <= position)
         return elementAt((size_t) position, set);
   }

   return NULL;
}
expfun module_edit lastElement(module_edit_list m)
{
   if (isEmpty(m) == false)
      return m->array[m->size - 1];
   else
      return NULL;
}
expfun void remove(size_t position,
                   module_edit_list set,
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
                       module_edit_list set)
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
expfun module_edit popFirst(module_edit_list m)
{
   module_edit popElement = firstElement(m);

   if (isEmpty(m) == false)
      remove(0, m);

   return popElement;
}
expfun module_edit popElement(size_t position,
                              module_edit_list set)
{
   module_edit popElement = elementAt(position, set);

   if (isEmpty(set) == false)
      remove(position, set);

   return popElement;
}
expfun module_edit popLast(module_edit_list m)
{
   module_edit popElement = lastElement(m);

   if (isEmpty(m) == false)
      remove(m->size - 1, m);

   return popElement;
}
expfun void append(module_edit_list src,
                   module_edit_list dest,
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
expfun void deepAppend(module_edit_list src,
                       module_edit_list dest)
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
expfun module_edit_list copy(module_edit_list src,
                             size_t level = 0)
{
   module_edit_list m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module_edit_list) malloc (sizeof(module_edit_list_struct));
      if (m != NULL)
      {
         m->array = NULL;
         m->size = 0;
         if (level > 0)
            append(src, m, level - 1);
         else
            append(src, m);
      }
      else
         malloc_error("copy()");

      return m;
   }
}
expfun module_edit_list deepCopy(module_edit_list src)
{
   module_edit_list m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module_edit_list) malloc (sizeof(module_edit_list_struct));
      if (m != NULL)
      {
         m->array = NULL;
         m->size = 0;
         deepAppend(src, m);
      }
      else
         malloc_error("deepCopy()");

      return m;
   }
}
expfun module_edit_list select(module_edit_list src,
                               bool (*sel_f) (module_edit),
                               bool state = true)
{
   module_edit_list set = module_edit_listNew();
   module_edit arrayElement;
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
                 module_edit_list m,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   size_t index;

   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (m == NULL)
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

      if (m->array == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%smodule_edit array : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmpty(m) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t size : %zu\n", new_Offset, m->size);

            index = 0;
            while(index < m->size)
            {

               fprintf(fp, "%smodule_edit array[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAt(index, m), fp, showEmpty);
               fprintf(fp, "%s\\end module_edit[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(module_edit_list m,
                 size_t level = 0)
{
   size_t index;

   if (m ne NULL)
   {
      if (level > 0)
      {

         index = 0;
         while(index < m->size)
         {
            Free(m->array[index], level - 1);

            index = index + 1;
         }
      }

      if (m->array ne NULL)
      {
         free((void *) m->array);
         m->array = NULL;
         m->size = 0;
      }

      free((void *) m);
   }
}
expfun void deepFree(module_edit_list m)
{
   size_t index;

   if (m ne NULL)
   {

      index = 0;
      while(index < m->size)
      {
         deepFree(m->array[index]);

         index = index + 1;
      }
      if (m->array ne NULL)
      {
         free((void *) m->array);
         m->array = NULL;
         m->size = 0;
      }

      free((void *) m);
   }
}
