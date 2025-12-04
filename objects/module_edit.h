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

#ifndef module_edit_INCLUDED
#define module_edit_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfName(vname name,
                          module_edit m);
   extern bool eqName(vname name,
                      module_edit m);
   extern bool eqSelfEdtList(edit_list edtList,
                             module_edit m);
   extern bool eqEdtList(edit_list edtList,
                         module_edit m);
   extern bool eqSelfPattern(text pattern,
                             module_edit m);
   extern bool eqPattern(text pattern,
                         module_edit m);
   extern bool eqSelf(module_edit a,
                      module_edit b);
   extern bool Eq(module_edit a,
                  module_edit b);
   extern vname getName(module_edit m);
   extern edit_list getEdtList(module_edit m);
   extern text getPattern(module_edit m);
   extern module_edit setName(vname name,
                              module_edit m);
   extern module_edit setEdtList(edit_list edtList,
                                 module_edit m);
   extern module_edit setPattern(text pattern,
                                 module_edit m);
   extern bool hasName(module_edit m);
   extern bool hasEdtList(module_edit m);
   extern bool hasPattern(module_edit m);
   extern module_edit deepCopy(module_edit src);
   extern void deepFree(module_edit m);

   #ifdef module_edit_cc
      extern module_edit module_editNew(vname name,
                                        edit_list edtList,
                                        text pattern);
      extern module_edit copy(module_edit src,
                              size_t level);
      extern void dump(text Offset,
                       module_edit m,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(module_edit m,
                       size_t level);

   #else
      extern module_edit module_editNew(vname name = NULL,
                                        edit_list edtList = NULL,
                                        text pattern = NULL);
      extern module_edit copy(module_edit src,
                              size_t level = 0);
      extern void dump(text Offset,
                       module_edit m,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(module_edit m,
                       size_t level = 0);

   #endif
// End External Functions
#endif
