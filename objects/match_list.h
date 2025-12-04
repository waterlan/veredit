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

#ifndef match_list_INCLUDED
#define match_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern match_list match_listNew(void);
   extern match_list match_listNew(match_item element);
   extern bool eqSelfArray(match_list a,
                           match_list b);
   extern bool eqArray(match_list a,
                       match_list b);
   extern bool eqSelf(match_list a,
                      match_list b);
   extern bool Eq(match_list a,
                  match_list b);
   extern match_item* getArray(match_list m);
   extern bool hasArray(match_list m);
   extern size_t size(match_list m);
   extern bool isEmpty(match_list m);
   extern void addFirst(match_item m,
                        match_list set);
   extern void add(match_item m,
                   match_list set);
   extern void insert(match_item m,
                      size_t position,
                      match_list set);
   extern match_item firstElement(match_list m);
   extern match_item elementAt(size_t position,
                               match_list set);
   extern match_item elementAt(ssize_t position,
                               match_list set);
   extern match_item lastElement(match_list m);
   extern void deepRemove(size_t position,
                          match_list set);
   extern match_item popFirst(match_list m);
   extern match_item popElement(size_t position,
                                match_list set);
   extern match_item popLast(match_list m);
   extern void deepAppend(match_list src,
                          match_list dest);
   extern match_list deepCopy(match_list src);
   extern void deepFree(match_list m);

   #ifdef match_list_cc
      extern void setSize(size_t size,
                          match_list set,
                          match_item initVal);
      extern void put(match_item m,
                      size_t position,
                      match_list set,
                      match_item initVal);
      extern void remove(size_t position,
                         match_list set,
                         size_t level);
      extern void append(match_list src,
                         match_list dest,
                         size_t level);
      extern match_list copy(match_list src,
                             size_t level);
      extern match_list select(match_list src,
                               bool (*sel_f) (match_item),
                               bool state);
      extern void dump(text Offset,
                       match_list m,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(match_list m,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          match_list set,
                          match_item initVal = NULL);
      extern void put(match_item m,
                      size_t position,
                      match_list set,
                      match_item initVal = NULL);
      extern void remove(size_t position,
                         match_list set,
                         size_t level = 0);
      extern void append(match_list src,
                         match_list dest,
                         size_t level = 0);
      extern match_list copy(match_list src,
                             size_t level = 0);
      extern match_list select(match_list src,
                               bool (*sel_f) (match_item),
                               bool state = true);
      extern void dump(text Offset,
                       match_list m,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(match_list m,
                       size_t level = 0);

   #endif
// End External Functions
#endif
