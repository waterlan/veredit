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

#ifndef nameset_INCLUDED
#define nameset_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern nameset namesetNew(void);
   extern nameset namesetNew(text element);
   extern bool eqSelfArray(nameset a,
                           nameset b);
   extern bool eqArray(nameset a,
                       nameset b);
   extern bool eqSelf(nameset a,
                      nameset b);
   extern bool Eq(nameset a,
                  nameset b);
   extern text* getArray(nameset n);
   extern bool hasArray(nameset n);
   extern size_t size(nameset n);
   extern bool isEmpty(nameset n);
   extern void addFirst(text t,
                        nameset set);
   extern void add(text t,
                   nameset set);
   extern void insert(text t,
                      size_t position,
                      nameset set);
   extern text firstElement(nameset n);
   extern text elementAt(size_t position,
                         nameset set);
   extern text elementAt(ssize_t position,
                         nameset set);
   extern text lastElement(nameset n);
   extern void deepRemove(size_t position,
                          nameset set);
   extern text popFirst(nameset n);
   extern text popElement(size_t position,
                          nameset set);
   extern text popLast(nameset n);
   extern void deepAppend(nameset src,
                          nameset dest);
   extern nameset deepCopy(nameset src);
   extern void deepFree(nameset n);

   #ifdef nameset_cc
      extern void setSize(size_t size,
                          nameset set,
                          text initVal);
      extern void put(text t,
                      size_t position,
                      nameset set,
                      text initVal);
      extern void remove(size_t position,
                         nameset set,
                         size_t level);
      extern void append(nameset src,
                         nameset dest,
                         size_t level);
      extern nameset copy(nameset src,
                          size_t level);
      extern nameset select(nameset src,
                            bool (*sel_f) (text),
                            bool state);
      extern void dump(text Offset,
                       nameset n,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(nameset n,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          nameset set,
                          text initVal = NULL);
      extern void put(text t,
                      size_t position,
                      nameset set,
                      text initVal = NULL);
      extern void remove(size_t position,
                         nameset set,
                         size_t level = 0);
      extern void append(nameset src,
                         nameset dest,
                         size_t level = 0);
      extern nameset copy(nameset src,
                          size_t level = 0);
      extern nameset select(nameset src,
                            bool (*sel_f) (text),
                            bool state = true);
      extern void dump(text Offset,
                       nameset n,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(nameset n,
                       size_t level = 0);

   #endif
// End External Functions
#endif
