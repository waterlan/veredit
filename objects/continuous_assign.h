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

#ifndef continuous_assign_INCLUDED
#define continuous_assign_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfSignal(simple_signal signal,
                            continuous_assign c);
   extern bool eqSignal(simple_signal signal,
                        continuous_assign c);
   extern bool eqSelfExpr(expression expr,
                          continuous_assign c);
   extern bool eqExpr(expression expr,
                      continuous_assign c);
   extern bool eqSelf(continuous_assign a,
                      continuous_assign b);
   extern bool Eq(continuous_assign a,
                  continuous_assign b);
   extern simple_signal getSignal(continuous_assign c);
   extern expression getExpr(continuous_assign c);
   extern continuous_assign setSignal(simple_signal signal,
                                      continuous_assign c);
   extern continuous_assign setExpr(expression expr,
                                    continuous_assign c);
   extern bool hasSignal(continuous_assign c);
   extern bool hasExpr(continuous_assign c);
   extern continuous_assign deepCopy(continuous_assign src);
   extern void deepFree(continuous_assign c);

   #ifdef continuous_assign_cc
      extern continuous_assign continuous_assignNew(simple_signal signal,
                                                    expression expr);
      extern continuous_assign copy(continuous_assign src,
                                    size_t level);
      extern void dump(text Offset,
                       continuous_assign c,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(continuous_assign c,
                       size_t level);

   #else
      extern continuous_assign continuous_assignNew(simple_signal signal = NULL,
                                                    expression expr = NULL);
      extern continuous_assign copy(continuous_assign src,
                                    size_t level = 0);
      extern void dump(text Offset,
                       continuous_assign c,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(continuous_assign c,
                       size_t level = 0);

   #endif
// End External Functions
#endif
