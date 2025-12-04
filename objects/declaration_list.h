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

#ifndef declaration_list_INCLUDED
#define declaration_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern declaration_list declaration_listNew(void);
   extern declaration_list declaration_listNew(declaration element);
   extern bool eqSelfArray(declaration_list a,
                           declaration_list b);
   extern bool eqArray(declaration_list a,
                       declaration_list b);
   extern bool eqSelf(declaration_list a,
                      declaration_list b);
   extern bool Eq(declaration_list a,
                  declaration_list b);
   extern declaration* getArray(declaration_list d);
   extern bool hasArray(declaration_list d);
   extern size_t size(declaration_list d);
   extern bool isEmpty(declaration_list d);
   extern void addFirst(declaration d,
                        declaration_list set);
   extern void add(declaration d,
                   declaration_list set);
   extern void insert(declaration d,
                      size_t position,
                      declaration_list set);
   extern declaration firstElement(declaration_list d);
   extern declaration elementAt(size_t position,
                                declaration_list set);
   extern declaration elementAt(ssize_t position,
                                declaration_list set);
   extern declaration lastElement(declaration_list d);
   extern void deepRemove(size_t position,
                          declaration_list set);
   extern declaration popFirst(declaration_list d);
   extern declaration popElement(size_t position,
                                 declaration_list set);
   extern declaration popLast(declaration_list d);
   extern void deepAppend(declaration_list src,
                          declaration_list dest);
   extern declaration_list deepCopy(declaration_list src);
   extern void deepFree(declaration_list d);

   #ifdef declaration_list_cc
      extern void setSize(size_t size,
                          declaration_list set,
                          declaration initVal);
      extern void put(declaration d,
                      size_t position,
                      declaration_list set,
                      declaration initVal);
      extern void remove(size_t position,
                         declaration_list set,
                         size_t level);
      extern void append(declaration_list src,
                         declaration_list dest,
                         size_t level);
      extern declaration_list copy(declaration_list src,
                                   size_t level);
      extern declaration_list select(declaration_list src,
                                     bool (*sel_f) (declaration),
                                     bool state);
      extern void dump(text Offset,
                       declaration_list d,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(declaration_list d,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          declaration_list set,
                          declaration initVal = NULL);
      extern void put(declaration d,
                      size_t position,
                      declaration_list set,
                      declaration initVal = NULL);
      extern void remove(size_t position,
                         declaration_list set,
                         size_t level = 0);
      extern void append(declaration_list src,
                         declaration_list dest,
                         size_t level = 0);
      extern declaration_list copy(declaration_list src,
                                   size_t level = 0);
      extern declaration_list select(declaration_list src,
                                     bool (*sel_f) (declaration),
                                     bool state = true);
      extern void dump(text Offset,
                       declaration_list d,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(declaration_list d,
                       size_t level = 0);

   #endif
// End External Functions
#endif
