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

#ifndef variable_name_INCLUDED
#define variable_name_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfName(vname name,
                          variable_name v);
   extern bool eqName(vname name,
                      variable_name v);
   extern bool eqSelfExpr(expression expr,
                          variable_name v);
   extern bool eqExpr(expression expr,
                      variable_name v);
   extern bool eqSelf(variable_name a,
                      variable_name b);
   extern bool Eq(variable_name a,
                  variable_name b);
   extern vname getName(variable_name v);
   extern expression getExpr(variable_name v);
   extern variable_name setName(vname name,
                                variable_name v);
   extern variable_name setExpr(expression expr,
                                variable_name v);
   extern bool hasName(variable_name v);
   extern bool hasExpr(variable_name v);
   extern variable_name deepCopy(variable_name src);
   extern void deepFree(variable_name v);

   #ifdef variable_name_cc
      extern variable_name variable_nameNew(vname name,
                                            expression expr);
      extern variable_name copy(variable_name src,
                                size_t level);
      extern void dump(text Offset,
                       variable_name v,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(variable_name v,
                       size_t level);

   #else
      extern variable_name variable_nameNew(vname name = NULL,
                                            expression expr = NULL);
      extern variable_name copy(variable_name src,
                                size_t level = 0);
      extern void dump(text Offset,
                       variable_name v,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(variable_name v,
                       size_t level = 0);

   #endif
// End External Functions
#endif
