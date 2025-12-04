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

#ifndef portmap_INCLUDED
#define portmap_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern portmap portmapNew(void);
   extern portmap portmapNew(portmap_element element);
   extern bool eqSelfArray(portmap a,
                           portmap b);
   extern bool eqArray(portmap a,
                       portmap b);
   extern bool eqSelf(portmap a,
                      portmap b);
   extern bool Eq(portmap a,
                  portmap b);
   extern portmap_element* getArray(portmap p);
   extern bool hasArray(portmap p);
   extern size_t size(portmap p);
   extern bool isEmpty(portmap p);
   extern void addFirst(portmap_element p,
                        portmap set);
   extern void add(portmap_element p,
                   portmap set);
   extern void insert(portmap_element p,
                      size_t position,
                      portmap set);
   extern portmap_element firstElement(portmap p);
   extern portmap_element elementAt(size_t position,
                                    portmap set);
   extern portmap_element elementAt(ssize_t position,
                                    portmap set);
   extern portmap_element lastElement(portmap p);
   extern void deepRemove(size_t position,
                          portmap set);
   extern portmap_element popFirst(portmap p);
   extern portmap_element popElement(size_t position,
                                     portmap set);
   extern portmap_element popLast(portmap p);
   extern void deepAppend(portmap src,
                          portmap dest);
   extern portmap deepCopy(portmap src);
   extern void deepFree(portmap p);

   #ifdef portmap_cc
      extern void setSize(size_t size,
                          portmap set,
                          portmap_element initVal);
      extern void put(portmap_element p,
                      size_t position,
                      portmap set,
                      portmap_element initVal);
      extern void remove(size_t position,
                         portmap set,
                         size_t level);
      extern void append(portmap src,
                         portmap dest,
                         size_t level);
      extern portmap copy(portmap src,
                          size_t level);
      extern portmap select(portmap src,
                            bool (*sel_f) (portmap_element),
                            bool state);
      extern void dump(text Offset,
                       portmap p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(portmap p,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          portmap set,
                          portmap_element initVal = NULL);
      extern void put(portmap_element p,
                      size_t position,
                      portmap set,
                      portmap_element initVal = NULL);
      extern void remove(size_t position,
                         portmap set,
                         size_t level = 0);
      extern void append(portmap src,
                         portmap dest,
                         size_t level = 0);
      extern portmap copy(portmap src,
                          size_t level = 0);
      extern portmap select(portmap src,
                            bool (*sel_f) (portmap_element),
                            bool state = true);
      extern void dump(text Offset,
                       portmap p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(portmap p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
