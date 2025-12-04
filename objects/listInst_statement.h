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

#ifndef listInst_statement_INCLUDED
#define listInst_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfNet(simple_signal Net,
                         listInst_statement l);
   extern bool eqNet(simple_signal Net,
                     listInst_statement l);
   extern bool eqSelf(listInst_statement a,
                      listInst_statement b);
   extern bool Eq(listInst_statement a,
                  listInst_statement b);
   extern simple_signal getNet(listInst_statement l);
   extern listInst_statement setNet(simple_signal Net,
                                    listInst_statement l);
   extern bool hasNet(listInst_statement l);
   extern listInst_statement deepCopy(listInst_statement src);
   extern void deepFree(listInst_statement l);

   #ifdef listInst_statement_cc
      extern listInst_statement listInst_statementNew(simple_signal Net);
      extern listInst_statement copy(listInst_statement src,
                                     size_t level);
      extern void dump(text Offset,
                       listInst_statement l,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(listInst_statement l,
                       size_t level);

   #else
      extern listInst_statement listInst_statementNew(simple_signal Net = NULL);
      extern listInst_statement copy(listInst_statement src,
                                     size_t level = 0);
      extern void dump(text Offset,
                       listInst_statement l,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(listInst_statement l,
                       size_t level = 0);

   #endif
// End External Functions
#endif
