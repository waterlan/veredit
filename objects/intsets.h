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

#ifndef intsets_INCLUDED
#define intsets_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern intsets intsetsNew(void);
   extern intsets intsetsNew(intset element);
   extern bool eqSelfArray(intsets a,
                           intsets b);
   extern bool eqArray(intsets a,
                       intsets b);
   extern bool eqSelf(intsets a,
                      intsets b);
   extern bool Eq(intsets a,
                  intsets b);
   extern intset* getArray(intsets i);
   extern bool hasArray(intsets i);
   extern size_t size(intsets i);
   extern bool isEmpty(intsets i);
   extern void addFirst(intset i,
                        intsets set);
   extern void add(intset i,
                   intsets set);
   extern void insert(intset i,
                      size_t position,
                      intsets set);
   extern intset firstElement(intsets i);
   extern intset elementAt(size_t position,
                           intsets set);
   extern intset elementAt(ssize_t position,
                           intsets set);
   extern intset lastElement(intsets i);
   extern void deepRemove(size_t position,
                          intsets set);
   extern intset popFirst(intsets i);
   extern intset popElement(size_t position,
                            intsets set);
   extern intset popLast(intsets i);
   extern void deepAppend(intsets src,
                          intsets dest);
   extern intsets deepCopy(intsets src);
   extern void deepFree(intsets i);

   #ifdef intsets_cc
      extern void setSize(size_t size,
                          intsets set,
                          intset initVal);
      extern void put(intset i,
                      size_t position,
                      intsets set,
                      intset initVal);
      extern void remove(size_t position,
                         intsets set,
                         size_t level);
      extern void append(intsets src,
                         intsets dest,
                         size_t level);
      extern intsets copy(intsets src,
                          size_t level);
      extern intsets select(intsets src,
                            bool (*sel_f) (intset),
                            bool state);
      extern void dump(text Offset,
                       intsets i,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(intsets i,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          intsets set,
                          intset initVal = NULL);
      extern void put(intset i,
                      size_t position,
                      intsets set,
                      intset initVal = NULL);
      extern void remove(size_t position,
                         intsets set,
                         size_t level = 0);
      extern void append(intsets src,
                         intsets dest,
                         size_t level = 0);
      extern intsets copy(intsets src,
                          size_t level = 0);
      extern intsets select(intsets src,
                            bool (*sel_f) (intset),
                            bool state = true);
      extern void dump(text Offset,
                       intsets i,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(intsets i,
                       size_t level = 0);

   #endif
// End External Functions
#endif
