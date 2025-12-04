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

#ifndef assign_list_INCLUDED
#define assign_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern assign_list assign_listNew(void);
   extern assign_list assign_listNew(continuous_assign element);
   extern bool eqSelfArray(assign_list a,
                           assign_list b);
   extern bool eqArray(assign_list a,
                       assign_list b);
   extern bool eqSelf(assign_list a,
                      assign_list b);
   extern bool Eq(assign_list a,
                  assign_list b);
   extern continuous_assign* getArray(assign_list a);
   extern bool hasArray(assign_list a);
   extern size_t size(assign_list a);
   extern bool isEmpty(assign_list a);
   extern void addFirst(continuous_assign c,
                        assign_list set);
   extern void add(continuous_assign c,
                   assign_list set);
   extern void insert(continuous_assign c,
                      size_t position,
                      assign_list set);
   extern continuous_assign firstElement(assign_list a);
   extern continuous_assign elementAt(size_t position,
                                      assign_list set);
   extern continuous_assign elementAt(ssize_t position,
                                      assign_list set);
   extern continuous_assign lastElement(assign_list a);
   extern void deepRemove(size_t position,
                          assign_list set);
   extern continuous_assign popFirst(assign_list a);
   extern continuous_assign popElement(size_t position,
                                       assign_list set);
   extern continuous_assign popLast(assign_list a);
   extern void deepAppend(assign_list src,
                          assign_list dest);
   extern assign_list deepCopy(assign_list src);
   extern void deepFree(assign_list a);

   #ifdef assign_list_cc
      extern void setSize(size_t size,
                          assign_list set,
                          continuous_assign initVal);
      extern void put(continuous_assign c,
                      size_t position,
                      assign_list set,
                      continuous_assign initVal);
      extern void remove(size_t position,
                         assign_list set,
                         size_t level);
      extern void append(assign_list src,
                         assign_list dest,
                         size_t level);
      extern assign_list copy(assign_list src,
                              size_t level);
      extern assign_list select(assign_list src,
                                bool (*sel_f) (continuous_assign),
                                bool state);
      extern void dump(text Offset,
                       assign_list a,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(assign_list a,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          assign_list set,
                          continuous_assign initVal = NULL);
      extern void put(continuous_assign c,
                      size_t position,
                      assign_list set,
                      continuous_assign initVal = NULL);
      extern void remove(size_t position,
                         assign_list set,
                         size_t level = 0);
      extern void append(assign_list src,
                         assign_list dest,
                         size_t level = 0);
      extern assign_list copy(assign_list src,
                              size_t level = 0);
      extern assign_list select(assign_list src,
                                bool (*sel_f) (continuous_assign),
                                bool state = true);
      extern void dump(text Offset,
                       assign_list a,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(assign_list a,
                       size_t level = 0);

   #endif
// End External Functions
#endif
