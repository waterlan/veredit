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

#ifndef intset_INCLUDED
#define intset_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern intset intsetNew(void);
   extern intset intsetNew(int element);
   extern bool eqArray(intset a,
                       intset b);
   extern bool eqSelf(intset a,
                      intset b);
   extern bool Eq(intset a,
                  intset b);
   extern int* getArray(intset i);
   extern bool hasArray(intset i);
   extern size_t size(intset i);
   extern bool isEmpty(intset i);
   extern void addFirst(int i,
                        intset set);
   extern void add(int i,
                   intset set);
   extern void insert(int i,
                      size_t position,
                      intset set);
   extern int firstElement(intset i);
   extern int elementAt(size_t position,
                        intset set);
   extern int elementAt(ssize_t position,
                        intset set);
   extern int lastElement(intset i);
   extern void remove(size_t position,
                      intset set);
   extern int popFirst(intset i);
   extern int popElement(size_t position,
                         intset set);
   extern int popLast(intset i);
   extern void append(intset src,
                      intset dest);
   extern intset copy(intset src);
   extern void Free(intset i);

   #ifdef intset_cc
      extern void setSize(size_t size,
                          intset set,
                          int initVal);
      extern void put(int i,
                      size_t position,
                      intset set,
                      int initVal);
      extern intset select(intset src,
                           bool (*sel_f) (int),
                           bool state);
      extern void dump(text Offset,
                       intset i,
                       FILE* fp,
                       bool showEmpty);

   #else
      extern void setSize(size_t size,
                          intset set,
                          int initVal = 0);
      extern void put(int i,
                      size_t position,
                      intset set,
                      int initVal = 0);
      extern intset select(intset src,
                           bool (*sel_f) (int),
                           bool state = true);
      extern void dump(text Offset,
                       intset i,
                       FILE* fp = stdout,
                       bool showEmpty = false);

   #endif
// End External Functions
#endif
