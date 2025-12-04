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

#ifndef bufassigns_statement_INCLUDED
#define bufassigns_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfBufferName(vname bufferName,
                                bufassigns_statement b);
   extern bool eqBufferName(vname bufferName,
                            bufassigns_statement b);
   extern bool eqSelfInputName(text inputName,
                               bufassigns_statement b);
   extern bool eqInputName(text inputName,
                           bufassigns_statement b);
   extern bool eqSelfOutputName(text outputName,
                                bufassigns_statement b);
   extern bool eqOutputName(text outputName,
                            bufassigns_statement b);
   extern bool eqSelf(bufassigns_statement a,
                      bufassigns_statement b);
   extern bool Eq(bufassigns_statement a,
                  bufassigns_statement b);
   extern vname getBufferName(bufassigns_statement b);
   extern text getInputName(bufassigns_statement b);
   extern text getOutputName(bufassigns_statement b);
   extern bufassigns_statement setBufferName(vname bufferName,
                                             bufassigns_statement b);
   extern bufassigns_statement setInputName(text inputName,
                                            bufassigns_statement b);
   extern bufassigns_statement setOutputName(text outputName,
                                             bufassigns_statement b);
   extern bool hasBufferName(bufassigns_statement b);
   extern bool hasInputName(bufassigns_statement b);
   extern bool hasOutputName(bufassigns_statement b);
   extern bufassigns_statement deepCopy(bufassigns_statement src);
   extern void deepFree(bufassigns_statement b);

   #ifdef bufassigns_statement_cc
      extern bufassigns_statement bufassigns_statementNew(vname bufferName,
                                                          text inputName,
                                                          text outputName);
      extern bufassigns_statement copy(bufassigns_statement src,
                                       size_t level);
      extern void dump(text Offset,
                       bufassigns_statement b,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(bufassigns_statement b,
                       size_t level);

   #else
      extern bufassigns_statement bufassigns_statementNew(vname bufferName = NULL,
                                                          text inputName = "A",
                                                          text outputName = "Z");
      extern bufassigns_statement copy(bufassigns_statement src,
                                       size_t level = 0);
      extern void dump(text Offset,
                       bufassigns_statement b,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(bufassigns_statement b,
                       size_t level = 0);

   #endif
// End External Functions
#endif
