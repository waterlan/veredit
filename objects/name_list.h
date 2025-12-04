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

#ifndef name_list_INCLUDED
#define name_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern name_list name_listNew(void);
   extern name_list name_listNew(vname element);
   extern bool eqSelfArray(name_list a,
                           name_list b);
   extern bool eqArray(name_list a,
                       name_list b);
   extern bool eqSelf(name_list a,
                      name_list b);
   extern bool Eq(name_list a,
                  name_list b);
   extern vname* getArray(name_list n);
   extern bool hasArray(name_list n);
   extern size_t size(name_list n);
   extern bool isEmpty(name_list n);
   extern void addFirst(vname v,
                        name_list set);
   extern void add(vname v,
                   name_list set);
   extern void insert(vname v,
                      size_t position,
                      name_list set);
   extern vname firstElement(name_list n);
   extern vname elementAt(size_t position,
                          name_list set);
   extern vname elementAt(ssize_t position,
                          name_list set);
   extern vname lastElement(name_list n);
   extern void deepRemove(size_t position,
                          name_list set);
   extern vname popFirst(name_list n);
   extern vname popElement(size_t position,
                           name_list set);
   extern vname popLast(name_list n);
   extern void deepAppend(name_list src,
                          name_list dest);
   extern name_list deepCopy(name_list src);
   extern void deepFree(name_list n);

   #ifdef name_list_cc
      extern void setSize(size_t size,
                          name_list set,
                          vname initVal);
      extern void put(vname v,
                      size_t position,
                      name_list set,
                      vname initVal);
      extern void remove(size_t position,
                         name_list set,
                         size_t level);
      extern void append(name_list src,
                         name_list dest,
                         size_t level);
      extern name_list copy(name_list src,
                            size_t level);
      extern name_list select(name_list src,
                              bool (*sel_f) (vname),
                              bool state);
      extern void dump(text Offset,
                       name_list n,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(name_list n,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          name_list set,
                          vname initVal = NULL);
      extern void put(vname v,
                      size_t position,
                      name_list set,
                      vname initVal = NULL);
      extern void remove(size_t position,
                         name_list set,
                         size_t level = 0);
      extern void append(name_list src,
                         name_list dest,
                         size_t level = 0);
      extern name_list copy(name_list src,
                            size_t level = 0);
      extern name_list select(name_list src,
                              bool (*sel_f) (vname),
                              bool state = true);
      extern void dump(text Offset,
                       name_list n,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(name_list n,
                       size_t level = 0);

   #endif
// End External Functions
#endif
