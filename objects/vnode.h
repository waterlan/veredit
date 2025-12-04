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

#ifndef vnode_INCLUDED
#define vnode_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern vnode vnodeNewWithElementInParents(vnode element);
   extern vnode vnodeNewWithElementInInstances(vnode element);
   extern bool eqSelfParents(vnode a,
                             vnode b);
   extern bool eqParents(vnode a,
                         vnode b);
   extern bool eqSelfInstances(vnode a,
                               vnode b);
   extern bool eqInstances(vnode a,
                           vnode b);
   extern bool eqSelfName(text name,
                          vnode v);
   extern bool eqName(text name,
                      vnode v);
   extern bool eqX(int x,
                   vnode v);
   extern bool eqY(int y,
                   vnode v);
   extern bool eqFold(bool foldIn,
                      vnode v);
   extern bool eqSelfBlock(module block,
                           vnode v);
   extern bool eqBlock(module block,
                       vnode v);
   extern bool eqSelfUp(vnode up,
                        vnode v);
   extern bool eqSelfDown(vnode down,
                          vnode v);
   extern bool eqSelf(vnode a,
                      vnode b);
   extern bool Eq(vnode a,
                  vnode b);
   extern vnode* getParents(vnode v);
   extern vnode* getInstances(vnode v);
   extern text getName(vnode v);
   extern int getX(vnode v);
   extern int getY(vnode v);
   extern bool fold(vnode v);
   extern module getBlock(vnode v);
   extern vnode getUp(vnode v);
   extern vnode getDown(vnode v);
   extern vnode setName(text name,
                        vnode v);
   extern vnode setX(int x,
                     vnode v);
   extern vnode setY(int y,
                     vnode v);
   extern vnode setFold(bool fold,
                        vnode v);
   extern vnode setBlock(module block,
                         vnode v);
   extern vnode setUp(vnode up,
                      vnode v);
   extern vnode setDown(vnode down,
                        vnode v);
   extern bool hasParents(vnode v);
   extern bool hasInstances(vnode v);
   extern bool hasName(vnode v);
   extern bool hasBlock(vnode v);
   extern bool hasUp(vnode v);
   extern bool hasDown(vnode v);
   extern vnode endOfRecursionOfUp(vnode v);
   extern vnode endOfRecursionOfDown(vnode v);
   extern size_t sizeOfParents(vnode v);
   extern size_t sizeOfInstances(vnode v);
   extern bool isEmptyParents(vnode v);
   extern bool isEmptyInstances(vnode v);
   extern void addFirstToParents(vnode v,
                                 vnode parent);
   extern void addFirstToInstances(vnode v,
                                   vnode parent);
   extern void addToParents(vnode v,
                            vnode parent);
   extern void addToInstances(vnode v,
                              vnode parent);
   extern void insertIntoParents(vnode v,
                                 size_t position,
                                 vnode parent);
   extern void insertIntoInstances(vnode v,
                                   size_t position,
                                   vnode parent);
   extern vnode firstElementOfParents(vnode v);
   extern vnode firstElementOfInstances(vnode v);
   extern vnode elementAtParents(size_t position,
                                 vnode parent);
   extern vnode elementAtInstances(size_t position,
                                   vnode parent);
   extern vnode elementAtParents(ssize_t position,
                                 vnode parent);
   extern vnode elementAtInstances(ssize_t position,
                                   vnode parent);
   extern vnode lastElementOfParents(vnode v);
   extern vnode lastElementOfInstances(vnode v);
   extern void deepRemoveFromParents(size_t position,
                                     vnode parent);
   extern void deepRemoveFromInstances(size_t position,
                                       vnode parent);
   extern vnode popFirstFromParents(vnode v);
   extern vnode popFirstFromInstances(vnode v);
   extern vnode popElementFromParents(size_t position,
                                      vnode parent);
   extern vnode popElementFromInstances(size_t position,
                                        vnode parent);
   extern vnode popLastFromParents(vnode v);
   extern vnode popLastFromInstances(vnode v);
   extern void deepAppendParents(vnode src,
                                 vnode dest);
   extern void deepAppendInstances(vnode src,
                                   vnode dest);
   extern vnode deepCopy(vnode src);
   extern void deepFree(vnode v);

   #ifdef vnode_cc
      extern vnode vnodeNew(module block,
                            vnode up,
                            vnode down);
      extern void setSizeOfParents(size_t size,
                                   vnode parent,
                                   vnode initVal);
      extern void setSizeOfInstances(size_t size,
                                     vnode parent,
                                     vnode initVal);
      extern void putIntoParents(vnode v,
                                 size_t position,
                                 vnode parent,
                                 vnode initVal);
      extern void putIntoInstances(vnode v,
                                   size_t position,
                                   vnode parent,
                                   vnode initVal);
      extern void removeFromParents(size_t position,
                                    vnode parent,
                                    size_t level);
      extern void removeFromInstances(size_t position,
                                      vnode parent,
                                      size_t level);
      extern void appendParents(vnode src,
                                vnode dest,
                                size_t level);
      extern void appendInstances(vnode src,
                                  vnode dest,
                                  size_t level);
      extern vnode copy(vnode src,
                        size_t level);
      extern vnode selectFromParents(vnode src,
                                     bool (*sel_f) (vnode),
                                     bool state);
      extern vnode selectFromInstances(vnode src,
                                       bool (*sel_f) (vnode),
                                       bool state);
      extern void dump(text Offset,
                       vnode v,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(vnode v,
                       size_t level);

   #else
      extern vnode vnodeNew(module block = NULL,
                            vnode up = NULL,
                            vnode down = NULL);
      extern void setSizeOfParents(size_t size,
                                   vnode parent,
                                   vnode initVal = NULL);
      extern void setSizeOfInstances(size_t size,
                                     vnode parent,
                                     vnode initVal = NULL);
      extern void putIntoParents(vnode v,
                                 size_t position,
                                 vnode parent,
                                 vnode initVal = NULL);
      extern void putIntoInstances(vnode v,
                                   size_t position,
                                   vnode parent,
                                   vnode initVal = NULL);
      extern void removeFromParents(size_t position,
                                    vnode parent,
                                    size_t level = 0);
      extern void removeFromInstances(size_t position,
                                      vnode parent,
                                      size_t level = 0);
      extern void appendParents(vnode src,
                                vnode dest,
                                size_t level = 0);
      extern void appendInstances(vnode src,
                                  vnode dest,
                                  size_t level = 0);
      extern vnode copy(vnode src,
                        size_t level = 0);
      extern vnode selectFromParents(vnode src,
                                     bool (*sel_f) (vnode),
                                     bool state = true);
      extern vnode selectFromInstances(vnode src,
                                       bool (*sel_f) (vnode),
                                       bool state = true);
      extern void dump(text Offset,
                       vnode v,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(vnode v,
                       size_t level = 0);

   #endif
// End External Functions
#endif
