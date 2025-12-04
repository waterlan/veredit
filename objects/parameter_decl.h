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

#ifndef parameter_decl_INCLUDED
#define parameter_decl_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfSignal(simple_signal signal,
                            parameter_decl p);
   extern bool eqSignal(simple_signal signal,
                        parameter_decl p);
   extern bool eqSelfExpr(expression expr,
                          parameter_decl p);
   extern bool eqExpr(expression expr,
                      parameter_decl p);
   extern bool eqSelf(parameter_decl a,
                      parameter_decl b);
   extern bool Eq(parameter_decl a,
                  parameter_decl b);
   extern simple_signal getSignal(parameter_decl p);
   extern expression getExpr(parameter_decl p);
   extern parameter_decl setSignal(simple_signal signal,
                                   parameter_decl p);
   extern parameter_decl setExpr(expression expr,
                                 parameter_decl p);
   extern bool hasSignal(parameter_decl p);
   extern bool hasExpr(parameter_decl p);
   extern parameter_decl deepCopy(parameter_decl src);
   extern void deepFree(parameter_decl p);

   #ifdef parameter_decl_cc
      extern parameter_decl parameter_declNew(simple_signal signal,
                                              expression expr);
      extern parameter_decl copy(parameter_decl src,
                                 size_t level);
      extern void dump(text Offset,
                       parameter_decl p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(parameter_decl p,
                       size_t level);

   #else
      extern parameter_decl parameter_declNew(simple_signal signal = NULL,
                                              expression expr = NULL);
      extern parameter_decl copy(parameter_decl src,
                                 size_t level = 0);
      extern void dump(text Offset,
                       parameter_decl p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(parameter_decl p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
