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

#ifndef module_item_INCLUDED
#define module_item_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfDeclItem(declaration declItem,
                              module_item m);
   extern bool eqDeclItem(declaration declItem,
                          module_item m);
   extern bool eqSelfAssignItem(continuous_assign assignItem,
                                module_item m);
   extern bool eqAssignItem(continuous_assign assignItem,
                            module_item m);
   extern bool eqSelfInstanceItem(instance instanceItem,
                                  module_item m);
   extern bool eqInstanceItem(instance instanceItem,
                              module_item m);
   extern bool eqSelfInitialItem(text initialItem,
                                 module_item m);
   extern bool eqInitialItem(text initialItem,
                             module_item m);
   extern bool eqSelfOverrideItem(text overrideItem,
                                  module_item m);
   extern bool eqOverrideItem(text overrideItem,
                              module_item m);
   extern bool eqSelfParameter_declItem(parameter_decl parameter_declItem,
                                        module_item m);
   extern bool eqParameter_declItem(parameter_decl parameter_declItem,
                                    module_item m);
   extern bool eqSelf(module_item a,
                      module_item b);
   extern bool Eq(module_item a,
                  module_item b);
   extern declaration getDeclItem(module_item m);
   extern continuous_assign getAssignItem(module_item m);
   extern instance getInstanceItem(module_item m);
   extern text getInitialItem(module_item m);
   extern text getOverrideItem(module_item m);
   extern parameter_decl getParameter_declItem(module_item m);
   extern module_item setDeclItem(declaration declItem,
                                  module_item m);
   extern module_item setAssignItem(continuous_assign assignItem,
                                    module_item m);
   extern module_item setInstanceItem(instance instanceItem,
                                      module_item m);
   extern module_item setInitialItem(text initialItem,
                                     module_item m);
   extern module_item setOverrideItem(text overrideItem,
                                      module_item m);
   extern module_item setParameter_declItem(parameter_decl parameter_declItem,
                                            module_item m);
   extern bool hasDeclItem(module_item m);
   extern bool hasAssignItem(module_item m);
   extern bool hasInstanceItem(module_item m);
   extern bool hasInitialItem(module_item m);
   extern bool hasOverrideItem(module_item m);
   extern bool hasParameter_declItem(module_item m);
   extern module_item deepCopy(module_item src);
   extern void deepFree(module_item m);

   #ifdef module_item_cc
      extern module_item module_itemNew(declaration declItem,
                                        continuous_assign assignItem,
                                        instance instanceItem,
                                        text initialItem,
                                        text overrideItem,
                                        parameter_decl parameter_declItem);
      extern module_item copy(module_item src,
                              size_t level);
      extern void dump(text Offset,
                       module_item m,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(module_item m,
                       size_t level);

   #else
      extern module_item module_itemNew(declaration declItem = NULL,
                                        continuous_assign assignItem = NULL,
                                        instance instanceItem = NULL,
                                        text initialItem = NULL,
                                        text overrideItem = NULL,
                                        parameter_decl parameter_declItem = NULL);
      extern module_item copy(module_item src,
                              size_t level = 0);
      extern void dump(text Offset,
                       module_item m,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(module_item m,
                       size_t level = 0);

   #endif
// End External Functions
#endif
