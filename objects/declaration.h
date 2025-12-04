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

#ifndef declaration_INCLUDED
#define declaration_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqType(signal_type type,
                      declaration d);
   extern bool eqSelfRnge(range rnge,
                          declaration d);
   extern bool eqRnge(range rnge,
                      declaration d);
   extern bool eqSelfSignals(variable_list signals,
                             declaration d);
   extern bool eqSignals(variable_list signals,
                         declaration d);
   extern bool eqSelf(declaration a,
                      declaration b);
   extern bool Eq(declaration a,
                  declaration b);
   extern signal_type getType(declaration d);
   extern range getRnge(declaration d);
   extern variable_list getSignals(declaration d);
   extern declaration setType(signal_type type,
                              declaration d);
   extern declaration setRnge(range rnge,
                              declaration d);
   extern declaration setSignals(variable_list signals,
                                 declaration d);
   extern bool hasType(declaration d);
   extern bool hasRnge(declaration d);
   extern bool hasSignals(declaration d);
   extern declaration deepCopy(declaration src);
   extern void deepFree(declaration d);

   #ifdef declaration_cc
      extern declaration declarationNew(signal_type type,
                                        range rnge,
                                        variable_list signals);
      extern declaration copy(declaration src,
                              size_t level);
      extern void dump(text Offset,
                       declaration d,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(declaration d,
                       size_t level);

   #else
      extern declaration declarationNew(signal_type type = _SIGNAL_TYPE_UNDEFINED,
                                        range rnge = NULL,
                                        variable_list signals = NULL);
      extern declaration copy(declaration src,
                              size_t level = 0);
      extern void dump(text Offset,
                       declaration d,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(declaration d,
                       size_t level = 0);

   #endif
// End External Functions
#endif
