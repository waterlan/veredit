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

#ifndef verilog_item_list_INCLUDED
#define verilog_item_list_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern verilog_item_list verilog_item_listNew(void);
   extern verilog_item_list verilog_item_listNew(verilog_item element);
   extern bool eqSelfArray(verilog_item_list a,
                           verilog_item_list b);
   extern bool eqArray(verilog_item_list a,
                       verilog_item_list b);
   extern bool eqSelf(verilog_item_list a,
                      verilog_item_list b);
   extern bool Eq(verilog_item_list a,
                  verilog_item_list b);
   extern verilog_item* getArray(verilog_item_list v);
   extern bool hasArray(verilog_item_list v);
   extern size_t size(verilog_item_list v);
   extern bool isEmpty(verilog_item_list v);
   extern void addFirst(verilog_item v,
                        verilog_item_list set);
   extern void add(verilog_item v,
                   verilog_item_list set);
   extern void insert(verilog_item v,
                      size_t position,
                      verilog_item_list set);
   extern verilog_item firstElement(verilog_item_list v);
   extern verilog_item elementAt(size_t position,
                                 verilog_item_list set);
   extern verilog_item elementAt(ssize_t position,
                                 verilog_item_list set);
   extern verilog_item lastElement(verilog_item_list v);
   extern void deepRemove(size_t position,
                          verilog_item_list set);
   extern verilog_item popFirst(verilog_item_list v);
   extern verilog_item popElement(size_t position,
                                  verilog_item_list set);
   extern verilog_item popLast(verilog_item_list v);
   extern void deepAppend(verilog_item_list src,
                          verilog_item_list dest);
   extern verilog_item_list deepCopy(verilog_item_list src);
   extern void deepFree(verilog_item_list v);

   #ifdef verilog_item_list_cc
      extern void setSize(size_t size,
                          verilog_item_list set,
                          verilog_item initVal);
      extern void put(verilog_item v,
                      size_t position,
                      verilog_item_list set,
                      verilog_item initVal);
      extern void remove(size_t position,
                         verilog_item_list set,
                         size_t level);
      extern void append(verilog_item_list src,
                         verilog_item_list dest,
                         size_t level);
      extern verilog_item_list copy(verilog_item_list src,
                                    size_t level);
      extern verilog_item_list select(verilog_item_list src,
                                      bool (*sel_f) (verilog_item),
                                      bool state);
      extern void dump(text Offset,
                       verilog_item_list v,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(verilog_item_list v,
                       size_t level);

   #else
      extern void setSize(size_t size,
                          verilog_item_list set,
                          verilog_item initVal = NULL);
      extern void put(verilog_item v,
                      size_t position,
                      verilog_item_list set,
                      verilog_item initVal = NULL);
      extern void remove(size_t position,
                         verilog_item_list set,
                         size_t level = 0);
      extern void append(verilog_item_list src,
                         verilog_item_list dest,
                         size_t level = 0);
      extern verilog_item_list copy(verilog_item_list src,
                                    size_t level = 0);
      extern verilog_item_list select(verilog_item_list src,
                                      bool (*sel_f) (verilog_item),
                                      bool state = true);
      extern void dump(text Offset,
                       verilog_item_list v,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(verilog_item_list v,
                       size_t level = 0);

   #endif
// End External Functions
#endif
