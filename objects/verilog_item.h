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

#ifndef verilog_item_INCLUDED
#define verilog_item_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfCompilerDirective(text compilerDirective,
                                       verilog_item v);
   extern bool eqCompilerDirective(text compilerDirective,
                                   verilog_item v);
   extern bool eqSelfBlock(module block,
                           verilog_item v);
   extern bool eqBlock(module block,
                       verilog_item v);
   extern bool eqSelf(verilog_item a,
                      verilog_item b);
   extern bool Eq(verilog_item a,
                  verilog_item b);
   extern text getCompilerDirective(verilog_item v);
   extern module getBlock(verilog_item v);
   extern verilog_item setCompilerDirective(text compilerDirective,
                                            verilog_item v);
   extern verilog_item setBlock(module block,
                                verilog_item v);
   extern bool hasCompilerDirective(verilog_item v);
   extern bool hasBlock(verilog_item v);
   extern verilog_item deepCopy(verilog_item src);
   extern void deepFree(verilog_item v);

   #ifdef verilog_item_cc
      extern verilog_item verilog_itemNew(text compilerDirective,
                                          module block);
      extern verilog_item copy(verilog_item src,
                               size_t level);
      extern void dump(text Offset,
                       verilog_item v,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(verilog_item v,
                       size_t level);

   #else
      extern verilog_item verilog_itemNew(text compilerDirective = NULL,
                                          module block = NULL);
      extern verilog_item copy(verilog_item src,
                               size_t level = 0);
      extern void dump(text Offset,
                       verilog_item v,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(verilog_item v,
                       size_t level = 0);

   #endif
// End External Functions
#endif
