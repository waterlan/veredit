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

#ifndef module_list_INCLUDED
#define module_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern module_list module_listNew(void);
   extern module_list module_listNew(module element);
   extern bool eqSelfArray(module_list a,
                           module_list b);
   extern bool eqArray(module_list a,
                       module_list b);
   extern bool eqSelf(module_list a,
                      module_list b);
   extern bool Eq(module_list a,
                  module_list b);
   extern module* getArray(module_list m);
   extern bool hasArray(module_list m);
   extern size_t size(module_list m);
   extern bool isEmpty(module_list m);
   extern void addFirst(module m,
                        module_list set);
   extern void add(module m,
                   module_list set);
   extern void insert(module m,
                      size_t position,
                      module_list set);
   extern module firstElement(module_list m);
   extern module elementAt(size_t position,
                           module_list set);
   extern module elementAt(ssize_t position,
                           module_list set);
   extern module lastElement(module_list m);
   extern void deepRemove(size_t position,
                          module_list set);
   extern module popFirst(module_list m);
   extern module popElement(size_t position,
                            module_list set);
   extern module popLast(module_list m);
   extern void deepAppend(module_list src,
                          module_list dest);
   extern module_list deepCopy(module_list src);
   extern void deepFree(module_list m);

   #ifdef module_list_cc
      extern void setSize(size_t size,
                          module_list set,
                          module initVal);
      extern void put(module m,
                      size_t position,
                      module_list set,
                      module initVal);
      extern void remove(size_t position,
                         module_list set,
                         size_t level);
      extern void append(module_list src,
                         module_list dest,
                         size_t level);
      extern module_list copy(module_list src,
                              size_t level);
      extern module_list select(module_list src,
                                bool (*sel_f) (module),
                                bool state);
      extern void dump(text Offset,
                       module_list m,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(module_list m,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          module_list set,
                          module initVal = NULL);
      extern void put(module m,
                      size_t position,
                      module_list set,
                      module initVal = NULL);
      extern void remove(size_t position,
                         module_list set,
                         size_t level = 0);
      extern void append(module_list src,
                         module_list dest,
                         size_t level = 0);
      extern module_list copy(module_list src,
                              size_t level = 0);
      extern module_list select(module_list src,
                                bool (*sel_f) (module),
                                bool state = true);
      extern void dump(text Offset,
                       module_list m,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(module_list m,
                       size_t level = 0);

   #endif
// End External Functions
#endif
