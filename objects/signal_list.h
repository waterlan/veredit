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

#ifndef signal_list_INCLUDED
#define signal_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern signal_list signal_listNew(void);
   extern signal_list signal_listNew(Signal element);
   extern bool eqSelfArray(signal_list a,
                           signal_list b);
   extern bool eqArray(signal_list a,
                       signal_list b);
   extern bool eqSelf(signal_list a,
                      signal_list b);
   extern bool Eq(signal_list a,
                  signal_list b);
   extern Signal* getArray(signal_list s);
   extern bool hasArray(signal_list s);
   extern size_t size(signal_list s);
   extern bool isEmpty(signal_list s);
   extern void addFirst(Signal s,
                        signal_list set);
   extern void add(Signal s,
                   signal_list set);
   extern void insert(Signal s,
                      size_t position,
                      signal_list set);
   extern Signal firstElement(signal_list s);
   extern Signal elementAt(size_t position,
                           signal_list set);
   extern Signal elementAt(ssize_t position,
                           signal_list set);
   extern Signal lastElement(signal_list s);
   extern void deepRemove(size_t position,
                          signal_list set);
   extern Signal popFirst(signal_list s);
   extern Signal popElement(size_t position,
                            signal_list set);
   extern Signal popLast(signal_list s);
   extern void deepAppend(signal_list src,
                          signal_list dest);
   extern signal_list deepCopy(signal_list src);
   extern void deepFree(signal_list s);

   #ifdef signal_list_cc
      extern void setSize(size_t size,
                          signal_list set,
                          Signal initVal);
      extern void put(Signal s,
                      size_t position,
                      signal_list set,
                      Signal initVal);
      extern void remove(size_t position,
                         signal_list set,
                         size_t level);
      extern void append(signal_list src,
                         signal_list dest,
                         size_t level);
      extern signal_list copy(signal_list src,
                              size_t level);
      extern signal_list select(signal_list src,
                                bool (*sel_f) (Signal),
                                bool state);
      extern void dump(text Offset,
                       signal_list s,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(signal_list s,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          signal_list set,
                          Signal initVal = NULL);
      extern void put(Signal s,
                      size_t position,
                      signal_list set,
                      Signal initVal = NULL);
      extern void remove(size_t position,
                         signal_list set,
                         size_t level = 0);
      extern void append(signal_list src,
                         signal_list dest,
                         size_t level = 0);
      extern signal_list copy(signal_list src,
                              size_t level = 0);
      extern signal_list select(signal_list src,
                                bool (*sel_f) (Signal),
                                bool state = true);
      extern void dump(text Offset,
                       signal_list s,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(signal_list s,
                       size_t level = 0);

   #endif
// End External Functions
#endif
