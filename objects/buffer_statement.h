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

#ifndef buffer_statement_INCLUDED
#define buffer_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfBufferName(vname bufferName,
                                buffer_statement b);
   extern bool eqBufferName(vname bufferName,
                            buffer_statement b);
   extern bool eqSelfExcludes(signal_list excludes,
                              buffer_statement b);
   extern bool eqExcludes(signal_list excludes,
                          buffer_statement b);
   extern bool eqSelf(buffer_statement a,
                      buffer_statement b);
   extern bool Eq(buffer_statement a,
                  buffer_statement b);
   extern vname getBufferName(buffer_statement b);
   extern signal_list getExcludes(buffer_statement b);
   extern buffer_statement setBufferName(vname bufferName,
                                         buffer_statement b);
   extern buffer_statement setExcludes(signal_list excludes,
                                       buffer_statement b);
   extern bool hasBufferName(buffer_statement b);
   extern bool hasExcludes(buffer_statement b);
   extern buffer_statement deepCopy(buffer_statement src);
   extern void deepFree(buffer_statement b);

   #ifdef buffer_statement_cc
      extern buffer_statement buffer_statementNew(vname bufferName,
                                                  signal_list excludes);
      extern buffer_statement copy(buffer_statement src,
                                   size_t level);
      extern void dump(text Offset,
                       buffer_statement b,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(buffer_statement b,
                       size_t level);

   #else
      extern buffer_statement buffer_statementNew(vname bufferName = NULL,
                                                  signal_list excludes = NULL);
      extern buffer_statement copy(buffer_statement src,
                                   size_t level = 0);
      extern void dump(text Offset,
                       buffer_statement b,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(buffer_statement b,
                       size_t level = 0);

   #endif
// End External Functions
#endif
