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

#ifndef edit_list_INCLUDED
#define edit_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern edit_list edit_listNew(void);
   extern edit_list edit_listNew(edit_element element);
   extern bool eqSelfArray(edit_list a,
                           edit_list b);
   extern bool eqArray(edit_list a,
                       edit_list b);
   extern bool eqSelf(edit_list a,
                      edit_list b);
   extern bool Eq(edit_list a,
                  edit_list b);
   extern edit_element* getArray(edit_list e);
   extern bool hasArray(edit_list e);
   extern size_t size(edit_list e);
   extern bool isEmpty(edit_list e);
   extern void addFirst(edit_element e,
                        edit_list set);
   extern void add(edit_element e,
                   edit_list set);
   extern void insert(edit_element e,
                      size_t position,
                      edit_list set);
   extern edit_element firstElement(edit_list e);
   extern edit_element elementAt(size_t position,
                                 edit_list set);
   extern edit_element elementAt(ssize_t position,
                                 edit_list set);
   extern edit_element lastElement(edit_list e);
   extern void deepRemove(size_t position,
                          edit_list set);
   extern edit_element popFirst(edit_list e);
   extern edit_element popElement(size_t position,
                                  edit_list set);
   extern edit_element popLast(edit_list e);
   extern void deepAppend(edit_list src,
                          edit_list dest);
   extern edit_list deepCopy(edit_list src);
   extern void deepFree(edit_list e);

   #ifdef edit_list_cc
      extern void setSize(size_t size,
                          edit_list set,
                          edit_element initVal);
      extern void put(edit_element e,
                      size_t position,
                      edit_list set,
                      edit_element initVal);
      extern void remove(size_t position,
                         edit_list set,
                         size_t level);
      extern void append(edit_list src,
                         edit_list dest,
                         size_t level);
      extern edit_list copy(edit_list src,
                            size_t level);
      extern edit_list select(edit_list src,
                              bool (*sel_f) (edit_element),
                              bool state);
      extern void dump(text Offset,
                       edit_list e,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(edit_list e,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          edit_list set,
                          edit_element initVal = NULL);
      extern void put(edit_element e,
                      size_t position,
                      edit_list set,
                      edit_element initVal = NULL);
      extern void remove(size_t position,
                         edit_list set,
                         size_t level = 0);
      extern void append(edit_list src,
                         edit_list dest,
                         size_t level = 0);
      extern edit_list copy(edit_list src,
                            size_t level = 0);
      extern edit_list select(edit_list src,
                              bool (*sel_f) (edit_element),
                              bool state = true);
      extern void dump(text Offset,
                       edit_list e,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(edit_list e,
                       size_t level = 0);

   #endif
// End External Functions
#endif
