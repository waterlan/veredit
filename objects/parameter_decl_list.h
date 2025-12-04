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

#ifndef parameter_decl_list_INCLUDED
#define parameter_decl_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern parameter_decl_list parameter_decl_listNew(void);
   extern parameter_decl_list parameter_decl_listNew(parameter_decl element);
   extern bool eqSelfArray(parameter_decl_list a,
                           parameter_decl_list b);
   extern bool eqArray(parameter_decl_list a,
                       parameter_decl_list b);
   extern bool eqSelf(parameter_decl_list a,
                      parameter_decl_list b);
   extern bool Eq(parameter_decl_list a,
                  parameter_decl_list b);
   extern parameter_decl* getArray(parameter_decl_list p);
   extern bool hasArray(parameter_decl_list p);
   extern size_t size(parameter_decl_list p);
   extern bool isEmpty(parameter_decl_list p);
   extern void addFirst(parameter_decl p,
                        parameter_decl_list set);
   extern void add(parameter_decl p,
                   parameter_decl_list set);
   extern void insert(parameter_decl p,
                      size_t position,
                      parameter_decl_list set);
   extern parameter_decl firstElement(parameter_decl_list p);
   extern parameter_decl elementAt(size_t position,
                                   parameter_decl_list set);
   extern parameter_decl elementAt(ssize_t position,
                                   parameter_decl_list set);
   extern parameter_decl lastElement(parameter_decl_list p);
   extern void deepRemove(size_t position,
                          parameter_decl_list set);
   extern parameter_decl popFirst(parameter_decl_list p);
   extern parameter_decl popElement(size_t position,
                                    parameter_decl_list set);
   extern parameter_decl popLast(parameter_decl_list p);
   extern void deepAppend(parameter_decl_list src,
                          parameter_decl_list dest);
   extern parameter_decl_list deepCopy(parameter_decl_list src);
   extern void deepFree(parameter_decl_list p);

   #ifdef parameter_decl_list_cc
      extern void setSize(size_t size,
                          parameter_decl_list set,
                          parameter_decl initVal);
      extern void put(parameter_decl p,
                      size_t position,
                      parameter_decl_list set,
                      parameter_decl initVal);
      extern void remove(size_t position,
                         parameter_decl_list set,
                         size_t level);
      extern void append(parameter_decl_list src,
                         parameter_decl_list dest,
                         size_t level);
      extern parameter_decl_list copy(parameter_decl_list src,
                                      size_t level);
      extern parameter_decl_list select(parameter_decl_list src,
                                        bool (*sel_f) (parameter_decl),
                                        bool state);
      extern void dump(text Offset,
                       parameter_decl_list p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(parameter_decl_list p,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          parameter_decl_list set,
                          parameter_decl initVal = NULL);
      extern void put(parameter_decl p,
                      size_t position,
                      parameter_decl_list set,
                      parameter_decl initVal = NULL);
      extern void remove(size_t position,
                         parameter_decl_list set,
                         size_t level = 0);
      extern void append(parameter_decl_list src,
                         parameter_decl_list dest,
                         size_t level = 0);
      extern parameter_decl_list copy(parameter_decl_list src,
                                      size_t level = 0);
      extern parameter_decl_list select(parameter_decl_list src,
                                        bool (*sel_f) (parameter_decl),
                                        bool state = true);
      extern void dump(text Offset,
                       parameter_decl_list p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(parameter_decl_list p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
