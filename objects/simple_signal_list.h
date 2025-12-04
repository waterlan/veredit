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

#ifndef simple_signal_list_INCLUDED
#define simple_signal_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern simple_signal_list simple_signal_listNew(void);
   extern simple_signal_list simple_signal_listNew(simple_signal element);
   extern bool eqSelfArray(simple_signal_list a,
                           simple_signal_list b);
   extern bool eqArray(simple_signal_list a,
                       simple_signal_list b);
   extern bool eqSelf(simple_signal_list a,
                      simple_signal_list b);
   extern bool Eq(simple_signal_list a,
                  simple_signal_list b);
   extern simple_signal* getArray(simple_signal_list s);
   extern bool hasArray(simple_signal_list s);
   extern size_t size(simple_signal_list s);
   extern bool isEmpty(simple_signal_list s);
   extern void addFirst(simple_signal s,
                        simple_signal_list set);
   extern void add(simple_signal s,
                   simple_signal_list set);
   extern void insert(simple_signal s,
                      size_t position,
                      simple_signal_list set);
   extern simple_signal firstElement(simple_signal_list s);
   extern simple_signal elementAt(size_t position,
                                  simple_signal_list set);
   extern simple_signal elementAt(ssize_t position,
                                  simple_signal_list set);
   extern simple_signal lastElement(simple_signal_list s);
   extern void deepRemove(size_t position,
                          simple_signal_list set);
   extern simple_signal popFirst(simple_signal_list s);
   extern simple_signal popElement(size_t position,
                                   simple_signal_list set);
   extern simple_signal popLast(simple_signal_list s);
   extern void deepAppend(simple_signal_list src,
                          simple_signal_list dest);
   extern simple_signal_list deepCopy(simple_signal_list src);
   extern void deepFree(simple_signal_list s);

   #ifdef simple_signal_list_cc
      extern void setSize(size_t size,
                          simple_signal_list set,
                          simple_signal initVal);
      extern void put(simple_signal s,
                      size_t position,
                      simple_signal_list set,
                      simple_signal initVal);
      extern void remove(size_t position,
                         simple_signal_list set,
                         size_t level);
      extern void append(simple_signal_list src,
                         simple_signal_list dest,
                         size_t level);
      extern simple_signal_list copy(simple_signal_list src,
                                     size_t level);
      extern simple_signal_list select(simple_signal_list src,
                                       bool (*sel_f) (simple_signal),
                                       bool state);
      extern void dump(text Offset,
                       simple_signal_list s,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(simple_signal_list s,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          simple_signal_list set,
                          simple_signal initVal = NULL);
      extern void put(simple_signal s,
                      size_t position,
                      simple_signal_list set,
                      simple_signal initVal = NULL);
      extern void remove(size_t position,
                         simple_signal_list set,
                         size_t level = 0);
      extern void append(simple_signal_list src,
                         simple_signal_list dest,
                         size_t level = 0);
      extern simple_signal_list copy(simple_signal_list src,
                                     size_t level = 0);
      extern simple_signal_list select(simple_signal_list src,
                                       bool (*sel_f) (simple_signal),
                                       bool state = true);
      extern void dump(text Offset,
                       simple_signal_list s,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(simple_signal_list s,
                       size_t level = 0);

   #endif
// End External Functions
#endif
