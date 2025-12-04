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

#ifndef module_INCLUDED
#define module_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfName(vname name,
                          module m);
   extern bool eqName(vname name,
                      module m);
   extern bool eqSelfPorts(port_list ports,
                           module m);
   extern bool eqPorts(port_list ports,
                       module m);
   extern bool eqSelfItems(module_item_list items,
                           module m);
   extern bool eqItems(module_item_list items,
                       module m);
   extern bool eqSelfModNode(vnode modNode,
                             module m);
   extern bool eqSelf(module a,
                      module b);
   extern bool Eq(module a,
                  module b);
   extern vname getName(module m);
   extern port_list getPorts(module m);
   extern module_item_list getItems(module m);
   extern vnode getModNode(module m);
   extern module setName(vname name,
                         module m);
   extern module setPorts(port_list ports,
                          module m);
   extern module setItems(module_item_list items,
                          module m);
   extern module setModNode(vnode modNode,
                            module m);
   extern bool hasName(module m);
   extern bool hasPorts(module m);
   extern bool hasItems(module m);
   extern bool hasModNode(module m);
   extern module deepCopy(module src);
   extern void deepFree(module m);

   #ifdef module_cc
      extern module moduleNew(vname name,
                              port_list ports,
                              module_item_list items);
      extern module copy(module src,
                         size_t level);
      extern void dump(text Offset,
                       module m,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(module m,
                       size_t level);

   #else
      extern module moduleNew(vname name = NULL,
                              port_list ports = NULL,
                              module_item_list items = NULL);
      extern module copy(module src,
                         size_t level = 0);
      extern void dump(text Offset,
                       module m,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(module m,
                       size_t level = 0);

   #endif
// End External Functions
#endif
