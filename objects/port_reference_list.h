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

#ifndef port_reference_list_INCLUDED
#define port_reference_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern port_reference_list port_reference_listNew(void);
   extern port_reference_list port_reference_listNew(port_reference element);
   extern bool eqSelfArray(port_reference_list a,
                           port_reference_list b);
   extern bool eqArray(port_reference_list a,
                       port_reference_list b);
   extern bool eqSelf(port_reference_list a,
                      port_reference_list b);
   extern bool Eq(port_reference_list a,
                  port_reference_list b);
   extern port_reference* getArray(port_reference_list p);
   extern bool hasArray(port_reference_list p);
   extern size_t size(port_reference_list p);
   extern bool isEmpty(port_reference_list p);
   extern void addFirst(port_reference p,
                        port_reference_list set);
   extern void add(port_reference p,
                   port_reference_list set);
   extern void insert(port_reference p,
                      size_t position,
                      port_reference_list set);
   extern port_reference firstElement(port_reference_list p);
   extern port_reference elementAt(size_t position,
                                   port_reference_list set);
   extern port_reference elementAt(ssize_t position,
                                   port_reference_list set);
   extern port_reference lastElement(port_reference_list p);
   extern void deepRemove(size_t position,
                          port_reference_list set);
   extern port_reference popFirst(port_reference_list p);
   extern port_reference popElement(size_t position,
                                    port_reference_list set);
   extern port_reference popLast(port_reference_list p);
   extern void deepAppend(port_reference_list src,
                          port_reference_list dest);
   extern port_reference_list deepCopy(port_reference_list src);
   extern void deepFree(port_reference_list p);

   #ifdef port_reference_list_cc
      extern void setSize(size_t size,
                          port_reference_list set,
                          port_reference initVal);
      extern void put(port_reference p,
                      size_t position,
                      port_reference_list set,
                      port_reference initVal);
      extern void remove(size_t position,
                         port_reference_list set,
                         size_t level);
      extern void append(port_reference_list src,
                         port_reference_list dest,
                         size_t level);
      extern port_reference_list copy(port_reference_list src,
                                      size_t level);
      extern port_reference_list select(port_reference_list src,
                                        bool (*sel_f) (port_reference),
                                        bool state);
      extern void dump(text Offset,
                       port_reference_list p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(port_reference_list p,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          port_reference_list set,
                          port_reference initVal = NULL);
      extern void put(port_reference p,
                      size_t position,
                      port_reference_list set,
                      port_reference initVal = NULL);
      extern void remove(size_t position,
                         port_reference_list set,
                         size_t level = 0);
      extern void append(port_reference_list src,
                         port_reference_list dest,
                         size_t level = 0);
      extern port_reference_list copy(port_reference_list src,
                                      size_t level = 0);
      extern port_reference_list select(port_reference_list src,
                                        bool (*sel_f) (port_reference),
                                        bool state = true);
      extern void dump(text Offset,
                       port_reference_list p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(port_reference_list p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
