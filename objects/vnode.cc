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

#define vnode_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vnode.h"
#include "module.h"


expfun vnode vnodeNew(module block = NULL,
                      vnode up = NULL,
                      vnode down = NULL)
{
   vnode v = (vnode) malloc (sizeof(vnode_struct));
   if (v != NULL)
   {
      v->block = block;
      v->up = up;
      v->down = down;
      v->name = NULL;
      v->x = 0;
      v->y = 0;
      v->fold = false;

      v->parents = NULL;
      v->parentsSize = 0;

      v->instances = NULL;
      v->instancesSize = 0;
   }
   else
      malloc_error("vnodeNew()");

   return v;
}
expfun vnode vnodeNewWithElementInParents(vnode element)
{
   vnode v = vnodeNew();

   if (element != NULL)
      addToParents(element, v);

   return v;
}
expfun vnode vnodeNewWithElementInInstances(vnode element)
{
   vnode v = vnodeNew();

   if (element != NULL)
      addToInstances(element, v);

   return v;
}
expfun bool eqSelfParents(vnode a,
                          vnode b)
{
   size_t index;

   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else if (a->parentsSize != b->parentsSize)
      return false;
   else
   {
      index = 0;
      while(index < a->parentsSize)
      {
         if (eqSelf(elementAtParents(index, a), elementAtParents(index, b)) == false)
            return false;

         index = index + 1;
      }
      return true;
   }
}
expfun bool eqParents(vnode a,
                      vnode b)
{
   size_t index;

   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else if (a->parentsSize != b->parentsSize)
      return false;
   else
   {
      index = 0;
      while(index < a->parentsSize)
      {
         if (Eq(elementAtParents(index, a), elementAtParents(index, b)) == false)
            return false;

         index = index + 1;
      }
      return true;
   }
}
expfun bool eqSelfInstances(vnode a,
                            vnode b)
{
   size_t index;

   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else if (a->instancesSize != b->instancesSize)
      return false;
   else
   {
      index = 0;
      while(index < a->instancesSize)
      {
         if (eqSelf(elementAtInstances(index, a), elementAtInstances(index, b)) == false)
            return false;

         index = index + 1;
      }
      return true;
   }
}
expfun bool eqInstances(vnode a,
                        vnode b)
{
   size_t index;

   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else if (a->instancesSize != b->instancesSize)
      return false;
   else
   {
      index = 0;
      while(index < a->instancesSize)
      {
         if (Eq(elementAtInstances(index, a), elementAtInstances(index, b)) == false)
            return false;

         index = index + 1;
      }
      return true;
   }
}
expfun bool eqSelfName(text name,
                       vnode v)
{
   if ((name == NULL) || (hasName(v) == false))
      return false;
   else if (eqSelf(name, getName(v)))
      return true;
   else
      return false;
}
expfun bool eqName(text name,
                   vnode v)
{
   if ((name == NULL) || (hasName(v) == false))
      return false;
   else if (Eq(name, getName(v)))
      return true;
   else
      return false;
}
expfun bool eqX(int x,
                vnode v)
{
   if (v == NULL)
      return false;
   else if (x == getX(v))
      return true;
   else
      return false;
}
expfun bool eqY(int y,
                vnode v)
{
   if (v == NULL)
      return false;
   else if (y == getY(v))
      return true;
   else
      return false;
}
expfun bool eqFold(bool foldIn,
                   vnode v)
{
   if (v == NULL)
      return false;
   else if (foldIn == fold(v))
      return true;
   else
      return false;
}
expfun bool eqSelfBlock(module block,
                        vnode v)
{
   if ((block == NULL) || (hasBlock(v) == false))
      return false;
   else if (eqSelf(block, getBlock(v)))
      return true;
   else
      return false;
}
expfun bool eqBlock(module block,
                    vnode v)
{
   if ((block == NULL) || (hasBlock(v) == false))
      return false;
   else if (Eq(block, getBlock(v)))
      return true;
   else
      return false;
}
expfun bool eqSelfUp(vnode up,
                     vnode v)
{
   if ((up == NULL) || (hasUp(v) == false))
      return false;
   else if (eqSelf(up, getUp(v)))
      return true;
   else
      return false;
}
expfun bool eqSelfDown(vnode down,
                       vnode v)
{
   if ((down == NULL) || (hasDown(v) == false))
      return false;
   else if (eqSelf(down, getDown(v)))
      return true;
   else
      return false;
}
expfun bool eqSelf(vnode a,
                   vnode b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(vnode a,
               vnode b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqParents(a, b) == false)
      return false;
   else if (eqInstances(a, b) == false)
      return false;
   else if (eqName(getName(a), b) == false)
      return false;
   else if (eqX(getX(a), b) == false)
      return false;
   else if (eqY(getY(a), b) == false)
      return false;
   else if (eqFold(fold(a), b) == false)
      return false;
   else if (eqBlock(getBlock(a), b) == false)
      return false;
   else if (eqSelfUp(getUp(a), b) == false)
      return false;
   else if (eqSelfDown(getDown(a), b) == false)
      return false;
   else
      return true;
}
expfun vnode* getParents(vnode v)
{
   if (v != NULL)
      return v->parents;
   else
      return NULL;
}
expfun vnode* getInstances(vnode v)
{
   if (v != NULL)
      return v->instances;
   else
      return NULL;
}
expfun text getName(vnode v)
{
   if (v != NULL)
      return v->name;
   else
      return NULL;
}
expfun int getX(vnode v)
{
   if (v != NULL)
      return v->x;
   else
      return 0;
}
expfun int getY(vnode v)
{
   if (v != NULL)
      return v->y;
   else
      return 0;
}
expfun bool fold(vnode v)
{
   if (v != NULL)
      return v->fold;
   else
      return false;
}
expfun module getBlock(vnode v)
{
   if (v != NULL)
      return v->block;
   else
      return NULL;
}
expfun vnode getUp(vnode v)
{
   if (v != NULL)
      return v->up;
   else
      return NULL;
}
expfun vnode getDown(vnode v)
{
   if (v != NULL)
      return v->down;
   else
      return NULL;
}
expfun vnode setName(text name,
                     vnode v)
{
   if (v != NULL)
      v->name = name;
   return v;
}
expfun vnode setX(int x,
                  vnode v)
{
   if (v != NULL)
      v->x = x;
   return v;
}
expfun vnode setY(int y,
                  vnode v)
{
   if (v != NULL)
      v->y = y;
   return v;
}
expfun vnode setFold(bool fold,
                     vnode v)
{
   if (v != NULL)
      v->fold = fold;
   return v;
}
expfun vnode setBlock(module block,
                      vnode v)
{
   if (v != NULL)
      v->block = block;
   return v;
}
expfun vnode setUp(vnode up,
                   vnode v)
{
   if (v != NULL)
      v->up = up;
   return v;
}
expfun vnode setDown(vnode down,
                     vnode v)
{
   if (v != NULL)
      v->down = down;
   return v;
}
expfun bool hasParents(vnode v)
{
   if (isEmptyParents(v) == false)
      return true;
   else
      return false;
}
expfun bool hasInstances(vnode v)
{
   if (isEmptyInstances(v) == false)
      return true;
   else
      return false;
}
expfun bool hasName(vnode v)
{
   if (getName(v) != NULL)
      return true;
   else
      return false;
}
expfun bool hasBlock(vnode v)
{
   if (getBlock(v) != NULL)
      return true;
   else
      return false;
}
expfun bool hasUp(vnode v)
{
   if (getUp(v) != NULL)
      return true;
   else
      return false;
}
expfun bool hasDown(vnode v)
{
   if (getDown(v) != NULL)
      return true;
   else
      return false;
}
expfun vnode endOfRecursionOfUp(vnode v)
{
   if (hasUp(v))
      return endOfRecursionOfUp(getUp(v));
   else
      return v;
}
expfun vnode endOfRecursionOfDown(vnode v)
{
   if (hasDown(v))
      return endOfRecursionOfDown(getDown(v));
   else
      return v;
}
expfun size_t sizeOfParents(vnode v)
{
   if (v != NULL)
      return v->parentsSize;
   else
      return 0;
}
expfun size_t sizeOfInstances(vnode v)
{
   if (v != NULL)
      return v->instancesSize;
   else
      return 0;
}
expfun void setSizeOfParents(size_t size,
                             vnode parent,
                             vnode initVal = NULL)
{
   size_t index;
   if (parent != NULL)
   {
      if (size <= 0)
      {
         if (isEmptyParents(parent) eq false)
         {
            free((void *) parent->parents);
            parent->parents = NULL;
            parent->parentsSize = 0;
         }
      }
      else if (size ne parent->parentsSize)
      {
         if (isEmptyParents(parent))
            parent->parents = (vnode *) malloc(sizeof(vnode) * size);
         else
            parent->parents = (vnode *) realloc((void *) parent->parents, sizeof(vnode) * size);

         if (parent->parents ne NULL)
         {
            index = parent->parentsSize;
            while(index < size)
            {
               parent->parents[index] = initVal;
               index = index + 1;
            }
            parent->parentsSize = size;
         }
         else
         {
            parent->parentsSize = 0;
            malloc_error("setSizeOfParents(size, parent, initVal)");
         }
      }
   }
}
expfun void setSizeOfInstances(size_t size,
                               vnode parent,
                               vnode initVal = NULL)
{
   size_t index;
   if (parent != NULL)
   {
      if (size <= 0)
      {
         if (isEmptyInstances(parent) eq false)
         {
            free((void *) parent->instances);
            parent->instances = NULL;
            parent->instancesSize = 0;
         }
      }
      else if (size ne parent->instancesSize)
      {
         if (isEmptyInstances(parent))
            parent->instances = (vnode *) malloc(sizeof(vnode) * size);
         else
            parent->instances = (vnode *) realloc((void *) parent->instances, sizeof(vnode) * size);

         if (parent->instances ne NULL)
         {
            index = parent->instancesSize;
            while(index < size)
            {
               parent->instances[index] = initVal;
               index = index + 1;
            }
            parent->instancesSize = size;
         }
         else
         {
            parent->instancesSize = 0;
            malloc_error("setSizeOfInstances(size, parent, initVal)");
         }
      }
   }
}
expfun bool isEmptyParents(vnode v)
{
   if (sizeOfParents(v) > 0)
      return false;
   else
      return true;
}
expfun bool isEmptyInstances(vnode v)
{
   if (sizeOfInstances(v) > 0)
      return false;
   else
      return true;
}
expfun void addFirstToParents(vnode v,
                              vnode parent)
{
   insertIntoParents(v, 0, parent);
}
expfun void addFirstToInstances(vnode v,
                                vnode parent)
{
   insertIntoInstances(v, 0, parent);
}
expfun void addToParents(vnode v,
                         vnode parent)
{
   if (parent != NULL)
   {
      setSizeOfParents(parent->parentsSize + 1, parent);
      if (parent->parents != NULL)
         parent->parents[parent->parentsSize - 1] = v;
      else
         malloc_error("addToParents()");
   }
}
expfun void addToInstances(vnode v,
                           vnode parent)
{
   if (parent != NULL)
   {
      setSizeOfInstances(parent->instancesSize + 1, parent);
      if (parent->instances != NULL)
         parent->instances[parent->instancesSize - 1] = v;
      else
         malloc_error("addToInstances()");
   }
}
expfun void putIntoParents(vnode v,
                           size_t position,
                           vnode parent,
                           vnode initVal = NULL)
{
   if (parent != NULL)
   {
      if (position >= parent->parentsSize)
         setSizeOfParents(position + 1, parent, initVal);
      if (parent->parents != NULL)
         parent->parents[position] = v;
      else
         malloc_error("putIntoParents(v, position, parent, initVal)");
   }
}
expfun void putIntoInstances(vnode v,
                             size_t position,
                             vnode parent,
                             vnode initVal = NULL)
{
   if (parent != NULL)
   {
      if (position >= parent->instancesSize)
         setSizeOfInstances(position + 1, parent, initVal);
      if (parent->instances != NULL)
         parent->instances[position] = v;
      else
         malloc_error("putIntoInstances(v, position, parent, initVal)");
   }
}
expfun void insertIntoParents(vnode v,
                              size_t position,
                              vnode parent)
{
   size_t index;
   if (parent != NULL)
   {
      index = parent->parentsSize;
      while(index > position)
      {
         putIntoParents(elementAtParents(index - 1, parent), index, parent);
         index = index - 1;
      }
      putIntoParents(v, position, parent);
   }
}
expfun void insertIntoInstances(vnode v,
                                size_t position,
                                vnode parent)
{
   size_t index;
   if (parent != NULL)
   {
      index = parent->instancesSize;
      while(index > position)
      {
         putIntoInstances(elementAtInstances(index - 1, parent), index, parent);
         index = index - 1;
      }
      putIntoInstances(v, position, parent);
   }
}
expfun vnode firstElementOfParents(vnode v)
{
   if (isEmptyParents(v) == false)
      return v->parents[0];
   else
      return NULL;
}
expfun vnode firstElementOfInstances(vnode v)
{
   if (isEmptyInstances(v) == false)
      return v->instances[0];
   else
      return NULL;
}
expfun vnode elementAtParents(size_t position,
                              vnode parent)
{
   if (parent != NULL)
   {
      if (position < parent->parentsSize)
         return parent->parents[position];
   }

   return NULL;
}
expfun vnode elementAtInstances(size_t position,
                                vnode parent)
{
   if (parent != NULL)
   {
      if (position < parent->instancesSize)
         return parent->instances[position];
   }

   return NULL;
}
expfun vnode elementAtParents(ssize_t position,
                              vnode parent)
{
   if (parent != NULL)
   {
      if (0 <= position)
         return elementAtParents((size_t) position, parent);
   }

   return NULL;
}
expfun vnode elementAtInstances(ssize_t position,
                                vnode parent)
{
   if (parent != NULL)
   {
      if (0 <= position)
         return elementAtInstances((size_t) position, parent);
   }

   return NULL;
}
expfun vnode lastElementOfParents(vnode v)
{
   if (isEmptyParents(v) == false)
      return v->parents[v->parentsSize - 1];
   else
      return NULL;
}
expfun vnode lastElementOfInstances(vnode v)
{
   if (isEmptyInstances(v) == false)
      return v->instances[v->instancesSize - 1];
   else
      return NULL;
}
expfun void removeFromParents(size_t position,
                              vnode parent,
                              size_t level = 0)
{
   size_t index;
   if (parent != NULL)
   {
      if (position < parent->parentsSize)
      {
         if (level > 0)
            Free(parent->parents[position], level - 1);

         index = position + 1;
         while(index < parent->parentsSize)
         {
            putIntoParents(elementAtParents(index, parent), index - 1, parent);
            index = index + 1;
         }
         setSizeOfParents(parent->parentsSize - 1, parent);
      }
   }
}
expfun void removeFromInstances(size_t position,
                                vnode parent,
                                size_t level = 0)
{
   size_t index;
   if (parent != NULL)
   {
      if (position < parent->instancesSize)
      {
         if (level > 0)
            Free(parent->instances[position], level - 1);

         index = position + 1;
         while(index < parent->instancesSize)
         {
            putIntoInstances(elementAtInstances(index, parent), index - 1, parent);
            index = index + 1;
         }
         setSizeOfInstances(parent->instancesSize - 1, parent);
      }
   }
}
expfun void deepRemoveFromParents(size_t position,
                                  vnode parent)
{
   size_t index;
   if (parent != NULL)
   {
      if (position < parent->parentsSize)
      {
         deepFree(parent->parents[position]);

         index = position + 1;
         while(index < parent->parentsSize)
         {
            putIntoParents(elementAtParents(index, parent), index - 1, parent);
            index = index + 1;
         }
         setSizeOfParents(parent->parentsSize - 1, parent);
      }
   }
}
expfun void deepRemoveFromInstances(size_t position,
                                    vnode parent)
{
   size_t index;
   if (parent != NULL)
   {
      if (position < parent->instancesSize)
      {
         deepFree(parent->instances[position]);

         index = position + 1;
         while(index < parent->instancesSize)
         {
            putIntoInstances(elementAtInstances(index, parent), index - 1, parent);
            index = index + 1;
         }
         setSizeOfInstances(parent->instancesSize - 1, parent);
      }
   }
}
expfun vnode popFirstFromParents(vnode v)
{
   vnode popElement = firstElementOfParents(v);

   if (isEmptyParents(v) == false)
      removeFromParents(0, v);

   return popElement;
}
expfun vnode popFirstFromInstances(vnode v)
{
   vnode popElement = firstElementOfInstances(v);

   if (isEmptyInstances(v) == false)
      removeFromInstances(0, v);

   return popElement;
}
expfun vnode popElementFromParents(size_t position,
                                   vnode parent)
{
   vnode popElement = elementAtParents(position, parent);

   if (isEmptyParents(parent) == false)
      removeFromParents(position, parent);

   return popElement;
}
expfun vnode popElementFromInstances(size_t position,
                                     vnode parent)
{
   vnode popElement = elementAtInstances(position, parent);

   if (isEmptyInstances(parent) == false)
      removeFromInstances(position, parent);

   return popElement;
}
expfun vnode popLastFromParents(vnode v)
{
   vnode popElement = lastElementOfParents(v);

   if (isEmptyParents(v) == false)
      removeFromParents(v->parentsSize - 1, v);

   return popElement;
}
expfun vnode popLastFromInstances(vnode v)
{
   vnode popElement = lastElementOfInstances(v);

   if (isEmptyInstances(v) == false)
      removeFromInstances(v->instancesSize - 1, v);

   return popElement;
}
expfun void appendParents(vnode src,
                          vnode dest,
                          size_t level = 0)
{
   if (src != NULL)
   {
      size_t index = 0;

      if (level > 0)
      {
         while(index < src->parentsSize)
         {
            addToParents(copy(elementAtParents(index, src), level - 1), dest);
            index = index + 1;
         }
      }
      else
      {
         while(index < src->parentsSize)
         {
            addToParents(elementAtParents(index, src), dest);
            index = index + 1;
         }
      }
   }
}
expfun void appendInstances(vnode src,
                            vnode dest,
                            size_t level = 0)
{
   if (src != NULL)
   {
      size_t index = 0;

      if (level > 0)
      {
         while(index < src->instancesSize)
         {
            addToInstances(copy(elementAtInstances(index, src), level - 1), dest);
            index = index + 1;
         }
      }
      else
      {
         while(index < src->instancesSize)
         {
            addToInstances(elementAtInstances(index, src), dest);
            index = index + 1;
         }
      }
   }
}
expfun void deepAppendParents(vnode src,
                              vnode dest)
{
   if (src != NULL)
   {
      size_t index = 0;
      while(index < src->parentsSize)
      {
         addToParents(deepCopy(elementAtParents(index, src)), dest);
         index = index + 1;
      }
   }
}
expfun void deepAppendInstances(vnode src,
                                vnode dest)
{
   if (src != NULL)
   {
      size_t index = 0;
      while(index < src->instancesSize)
      {
         addToInstances(deepCopy(elementAtInstances(index, src)), dest);
         index = index + 1;
      }
   }
}
expfun vnode copy(vnode src,
                  size_t level = 0)
{
   vnode v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (vnode) malloc (sizeof(vnode_struct));
      if (v != NULL)
      {
         if (level > 0)
         {
            v->name = textNew(src->name);
            v->x = src->x;
            v->y = src->y;
            v->fold = src->fold;
            v->block = copy(src->block, level - 1);
            v->up = src->up;
            v->down = src->down;
         }
         else
         {
            v->name = src->name;
            v->x = src->x;
            v->y = src->y;
            v->fold = src->fold;
            v->block = src->block;
            v->up = src->up;
            v->down = src->down;
         }

         v->parents = NULL;
         v->parentsSize = 0;
         if (level > 0)
            appendParents(src, v, level - 1);
         else
            appendParents(src, v);

         v->instances = NULL;
         v->instancesSize = 0;
         if (level > 0)
            appendInstances(src, v, level - 1);
         else
            appendInstances(src, v);
      }
      else
         malloc_error("copy()");

      return v;
   }
}
expfun vnode deepCopy(vnode src)
{
   vnode v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (vnode) malloc (sizeof(vnode_struct));
      if (v != NULL)
      {
         v->name = textNew(src->name);
         v->x = src->x;
         v->y = src->y;
         v->fold = src->fold;
         v->block = deepCopy(src->block);
         v->up = src->up;
         v->down = src->down;

         v->parents = NULL;
         v->parentsSize = 0;
         deepAppendParents(src, v);

         v->instances = NULL;
         v->instancesSize = 0;
         deepAppendInstances(src, v);
      }
      else
         malloc_error("deepCopy()");

      return v;
   }
}
expfun vnode selectFromParents(vnode src,
                               bool (*sel_f) (vnode),
                               bool state = true)
{
   vnode set = vnodeNew();
   vnode parentsElement;
   size_t index = 0;
   while(index < sizeOfParents(src))
   {
      parentsElement = elementAtParents(index, src);
      if (sel_f(parentsElement) eq state)
         addToParents(parentsElement, set);

      index = index + 1;
   }

   return set;
}
expfun vnode selectFromInstances(vnode src,
                                 bool (*sel_f) (vnode),
                                 bool state = true)
{
   vnode set = vnodeNew();
   vnode instancesElement;
   size_t index = 0;
   while(index < sizeOfInstances(src))
   {
      instancesElement = elementAtInstances(index, src);
      if (sel_f(instancesElement) eq state)
         addToInstances(instancesElement, set);

      index = index + 1;
   }

   return set;
}
expfun void dump(text Offset,
                 vnode v,
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

      if (hasName(v) || showEmpty)
      {
         if (v->name ne NULL)
            fprintf(fp, "%stext name : %s\n", new_Offset, v->name);
         else if (showEmpty)
            fprintf(fp, "%stext name : NULL\n", new_Offset);
      }

      fprintf(fp, "%sint x : %d\n", new_Offset, getX(v));

      fprintf(fp, "%sint y : %d\n", new_Offset, getY(v));

      fprintf(fp, "%sbool fold : %d\n", new_Offset, fold(v));

      if (hasBlock(v) || showEmpty)
      {
         fprintf(fp, "%smodule block,\n", new_Offset);
         dump(new_Offset, v->block, fp, showEmpty);
         fprintf(fp, "%s\\end module\n", new_Offset);
      }

      if (hasUp(v) || showEmpty)
         fprintf(fp, "%svnode up : %p (reference)\n", new_Offset, v->up);

      if (hasDown(v) || showEmpty)
         fprintf(fp, "%svnode down : %p (reference)\n", new_Offset, v->down);

      if (v->parents == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%svnode parents : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmptyParents(v) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t parentsSize : %zu\n", new_Offset, v->parentsSize);

            index = 0;
            while(index < v->parentsSize)
            {

               fprintf(fp, "%svnode parents[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAtParents(index, v), fp, showEmpty);
               fprintf(fp, "%s\\end vnode[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      if (v->instances == NULL)
      {
         if (showEmpty)
            fprintf(fp, "%svnode instances : NULL\n", new_Offset);
      }
      else
      {
         if ((isEmptyInstances(v) == false) || showEmpty)
         {
            fprintf(fp, "%ssize_t instancesSize : %zu\n", new_Offset, v->instancesSize);

            index = 0;
            while(index < v->instancesSize)
            {

               fprintf(fp, "%svnode instances[%zu],\n", new_Offset, index);
               dump(new_Offset, elementAtInstances(index, v), fp, showEmpty);
               fprintf(fp, "%s\\end vnode[%zu]\n", new_Offset, index);

               index = index + 1;
            }
         }
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(vnode v,
                 size_t level = 0)
{
   size_t index;

   if (v ne NULL)
   {
      if (level > 0)
      {

         if (v->name ne NULL)
         {
            free((void *) v->name);
            v->name = NULL;
         }

         Free(v->block, level - 1);
         v->block = NULL;

         index = 0;
         while(index < v->parentsSize)
         {
            Free(v->parents[index], level - 1);

            index = index + 1;
         }

         index = 0;
         while(index < v->instancesSize)
         {
            Free(v->instances[index], level - 1);

            index = index + 1;
         }
      }

      if (v->parents ne NULL)
      {
         free((void *) v->parents);
         v->parents = NULL;
         v->parentsSize = 0;
      }
      if (v->instances ne NULL)
      {
         free((void *) v->instances);
         v->instances = NULL;
         v->instancesSize = 0;
      }

      free((void *) v);
   }
}
expfun void deepFree(vnode v)
{
   size_t index;

   if (v ne NULL)
   {

      if (v->name ne NULL)
      {
         free((void *) v->name);
         v->name = NULL;
      }

      deepFree(v->block);
      v->block = NULL;

      index = 0;
      while(index < v->parentsSize)
      {
         deepFree(v->parents[index]);

         index = index + 1;
      }

      index = 0;
      while(index < v->instancesSize)
      {
         deepFree(v->instances[index]);

         index = index + 1;
      }
      if (v->parents ne NULL)
      {
         free((void *) v->parents);
         v->parents = NULL;
         v->parentsSize = 0;
      }
      if (v->instances ne NULL)
      {
         free((void *) v->instances);
         v->instances = NULL;
         v->instancesSize = 0;
      }

      free((void *) v);
   }
}
