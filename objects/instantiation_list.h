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

#ifndef instantiation_list_INCLUDED
#define instantiation_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern instantiation_list instantiation_listNew(void);
   extern instantiation_list instantiation_listNew(instance element);
   extern bool eqSelfArray(instantiation_list a,
                           instantiation_list b);
   extern bool eqArray(instantiation_list a,
                       instantiation_list b);
   extern bool eqSelf(instantiation_list a,
                      instantiation_list b);
   extern bool Eq(instantiation_list a,
                  instantiation_list b);
   extern instance* getArray(instantiation_list i);
   extern bool hasArray(instantiation_list i);
   extern size_t size(instantiation_list i);
   extern bool isEmpty(instantiation_list i);
   extern void addFirst(instance i,
                        instantiation_list set);
   extern void add(instance i,
                   instantiation_list set);
   extern void insert(instance i,
                      size_t position,
                      instantiation_list set);
   extern instance firstElement(instantiation_list i);
   extern instance elementAt(size_t position,
                             instantiation_list set);
   extern instance elementAt(ssize_t position,
                             instantiation_list set);
   extern instance lastElement(instantiation_list i);
   extern void deepRemove(size_t position,
                          instantiation_list set);
   extern instance popFirst(instantiation_list i);
   extern instance popElement(size_t position,
                              instantiation_list set);
   extern instance popLast(instantiation_list i);
   extern void deepAppend(instantiation_list src,
                          instantiation_list dest);
   extern instantiation_list deepCopy(instantiation_list src);
   extern void deepFree(instantiation_list i);

   #ifdef instantiation_list_cc
      extern void setSize(size_t size,
                          instantiation_list set,
                          instance initVal);
      extern void put(instance i,
                      size_t position,
                      instantiation_list set,
                      instance initVal);
      extern void remove(size_t position,
                         instantiation_list set,
                         size_t level);
      extern void append(instantiation_list src,
                         instantiation_list dest,
                         size_t level);
      extern instantiation_list copy(instantiation_list src,
                                     size_t level);
      extern instantiation_list select(instantiation_list src,
                                       bool (*sel_f) (instance),
                                       bool state);
      extern void dump(text Offset,
                       instantiation_list i,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(instantiation_list i,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          instantiation_list set,
                          instance initVal = NULL);
      extern void put(instance i,
                      size_t position,
                      instantiation_list set,
                      instance initVal = NULL);
      extern void remove(size_t position,
                         instantiation_list set,
                         size_t level = 0);
      extern void append(instantiation_list src,
                         instantiation_list dest,
                         size_t level = 0);
      extern instantiation_list copy(instantiation_list src,
                                     size_t level = 0);
      extern instantiation_list select(instantiation_list src,
                                       bool (*sel_f) (instance),
                                       bool state = true);
      extern void dump(text Offset,
                       instantiation_list i,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(instantiation_list i,
                       size_t level = 0);

   #endif
// End External Functions
#endif
