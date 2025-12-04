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

#ifndef variable_list_INCLUDED
#define variable_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern variable_list variable_listNew(void);
   extern variable_list variable_listNew(variable_name element);
   extern bool eqSelfArray(variable_list a,
                           variable_list b);
   extern bool eqArray(variable_list a,
                       variable_list b);
   extern bool eqSelf(variable_list a,
                      variable_list b);
   extern bool Eq(variable_list a,
                  variable_list b);
   extern variable_name* getArray(variable_list v);
   extern bool hasArray(variable_list v);
   extern size_t size(variable_list v);
   extern bool isEmpty(variable_list v);
   extern void addFirst(variable_name v,
                        variable_list set);
   extern void add(variable_name v,
                   variable_list set);
   extern void insert(variable_name v,
                      size_t position,
                      variable_list set);
   extern variable_name firstElement(variable_list v);
   extern variable_name elementAt(size_t position,
                                  variable_list set);
   extern variable_name elementAt(ssize_t position,
                                  variable_list set);
   extern variable_name lastElement(variable_list v);
   extern void deepRemove(size_t position,
                          variable_list set);
   extern variable_name popFirst(variable_list v);
   extern variable_name popElement(size_t position,
                                   variable_list set);
   extern variable_name popLast(variable_list v);
   extern void deepAppend(variable_list src,
                          variable_list dest);
   extern variable_list deepCopy(variable_list src);
   extern void deepFree(variable_list v);

   #ifdef variable_list_cc
      extern void setSize(size_t size,
                          variable_list set,
                          variable_name initVal);
      extern void put(variable_name v,
                      size_t position,
                      variable_list set,
                      variable_name initVal);
      extern void remove(size_t position,
                         variable_list set,
                         size_t level);
      extern void append(variable_list src,
                         variable_list dest,
                         size_t level);
      extern variable_list copy(variable_list src,
                                size_t level);
      extern variable_list select(variable_list src,
                                  bool (*sel_f) (variable_name),
                                  bool state);
      extern void dump(text Offset,
                       variable_list v,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(variable_list v,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          variable_list set,
                          variable_name initVal = NULL);
      extern void put(variable_name v,
                      size_t position,
                      variable_list set,
                      variable_name initVal = NULL);
      extern void remove(size_t position,
                         variable_list set,
                         size_t level = 0);
      extern void append(variable_list src,
                         variable_list dest,
                         size_t level = 0);
      extern variable_list copy(variable_list src,
                                size_t level = 0);
      extern variable_list select(variable_list src,
                                  bool (*sel_f) (variable_name),
                                  bool state = true);
      extern void dump(text Offset,
                       variable_list v,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(variable_list v,
                       size_t level = 0);

   #endif
// End External Functions
#endif
