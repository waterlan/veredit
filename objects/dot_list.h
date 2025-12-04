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

#ifndef dot_list_INCLUDED
#define dot_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern dot_list dot_listNew(void);
   extern dot_list dot_listNew(dot element);
   extern bool eqSelfArray(dot_list a,
                           dot_list b);
   extern bool eqArray(dot_list a,
                       dot_list b);
   extern bool eqSelf(dot_list a,
                      dot_list b);
   extern bool Eq(dot_list a,
                  dot_list b);
   extern dot* getArray(dot_list d);
   extern bool hasArray(dot_list d);
   extern size_t size(dot_list d);
   extern bool isEmpty(dot_list d);
   extern void addFirst(dot d,
                        dot_list set);
   extern void add(dot d,
                   dot_list set);
   extern void insert(dot d,
                      size_t position,
                      dot_list set);
   extern dot firstElement(dot_list d);
   extern dot elementAt(size_t position,
                        dot_list set);
   extern dot elementAt(ssize_t position,
                        dot_list set);
   extern dot lastElement(dot_list d);
   extern void deepRemove(size_t position,
                          dot_list set);
   extern dot popFirst(dot_list d);
   extern dot popElement(size_t position,
                         dot_list set);
   extern dot popLast(dot_list d);
   extern void deepAppend(dot_list src,
                          dot_list dest);
   extern dot_list deepCopy(dot_list src);
   extern void deepFree(dot_list d);

   #ifdef dot_list_cc
      extern void setSize(size_t size,
                          dot_list set,
                          dot initVal);
      extern void put(dot d,
                      size_t position,
                      dot_list set,
                      dot initVal);
      extern void remove(size_t position,
                         dot_list set,
                         size_t level);
      extern void append(dot_list src,
                         dot_list dest,
                         size_t level);
      extern dot_list copy(dot_list src,
                           size_t level);
      extern dot_list select(dot_list src,
                             bool (*sel_f) (dot),
                             bool state);
      extern void dump(text Offset,
                       dot_list d,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(dot_list d,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          dot_list set,
                          dot initVal = NULL);
      extern void put(dot d,
                      size_t position,
                      dot_list set,
                      dot initVal = NULL);
      extern void remove(size_t position,
                         dot_list set,
                         size_t level = 0);
      extern void append(dot_list src,
                         dot_list dest,
                         size_t level = 0);
      extern dot_list copy(dot_list src,
                           size_t level = 0);
      extern dot_list select(dot_list src,
                             bool (*sel_f) (dot),
                             bool state = true);
      extern void dump(text Offset,
                       dot_list d,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(dot_list d,
                       size_t level = 0);

   #endif
// End External Functions
#endif
