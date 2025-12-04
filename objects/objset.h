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

#ifndef objset_INCLUDED
#define objset_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern objset objsetNew(void);
   extern objset objsetNew(void* element);
   extern bool eqSelfArray(objset a,
                           objset b);
   extern bool eqArray(objset a,
                       objset b);
   extern bool eqSelf(objset a,
                      objset b);
   extern bool Eq(objset a,
                  objset b);
   extern void** getArray(objset o);
   extern bool hasArray(objset o);
   extern size_t size(objset o);
   extern bool isEmpty(objset o);
   extern void addFirst(void* v,
                        objset set);
   extern void add(void* v,
                   objset set);
   extern void insert(void* v,
                      size_t position,
                      objset set);
   extern void* firstElement(objset o);
   extern void* elementAt(size_t position,
                          objset set);
   extern void* elementAt(ssize_t position,
                          objset set);
   extern void* lastElement(objset o);
   extern void remove(size_t position,
                      objset set);
   extern void* popFirst(objset o);
   extern void* popElement(size_t position,
                           objset set);
   extern void* popLast(objset o);
   extern void append(objset src,
                      objset dest);
   extern objset copy(objset src);
   extern void deepFree(objset o);

   #ifdef objset_cc
      extern void setSize(size_t size,
                          objset set,
                          void* initVal);
      extern void put(void* v,
                      size_t position,
                      objset set,
                      void* initVal);
      extern objset select(objset src,
                           bool (*sel_f) (void *),
                           bool state);
      extern void dump(text Offset,
                       objset o,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(objset o,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          objset set,
                          void* initVal = NULL);
      extern void put(void* v,
                      size_t position,
                      objset set,
                      void* initVal = NULL);
      extern objset select(objset src,
                           bool (*sel_f) (void *),
                           bool state = true);
      extern void dump(text Offset,
                       objset o,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(objset o,
                       size_t level = 0);

   #endif
// End External Functions
#endif
