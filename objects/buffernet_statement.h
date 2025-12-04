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

#ifndef buffernet_statement_INCLUDED
#define buffernet_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqType(buffer_type type,
                      buffernet_statement b);
   extern bool eqSelfBufferName(vname bufferName,
                                buffernet_statement b);
   extern bool eqBufferName(vname bufferName,
                            buffernet_statement b);
   extern bool eqSelfInputName(text inputName,
                               buffernet_statement b);
   extern bool eqInputName(text inputName,
                           buffernet_statement b);
   extern bool eqSelfOutputName(text outputName,
                                buffernet_statement b);
   extern bool eqOutputName(text outputName,
                            buffernet_statement b);
   extern bool eqSelfEditinstances(instantiation_list editinstances,
                                   buffernet_statement b);
   extern bool eqEditinstances(instantiation_list editinstances,
                               buffernet_statement b);
   extern bool eqSelf(buffernet_statement a,
                      buffernet_statement b);
   extern bool Eq(buffernet_statement a,
                  buffernet_statement b);
   extern buffer_type getType(buffernet_statement b);
   extern vname getBufferName(buffernet_statement b);
   extern text getInputName(buffernet_statement b);
   extern text getOutputName(buffernet_statement b);
   extern instantiation_list getEditinstances(buffernet_statement b);
   extern buffernet_statement setType(buffer_type type,
                                      buffernet_statement b);
   extern buffernet_statement setBufferName(vname bufferName,
                                            buffernet_statement b);
   extern buffernet_statement setInputName(text inputName,
                                           buffernet_statement b);
   extern buffernet_statement setOutputName(text outputName,
                                            buffernet_statement b);
   extern buffernet_statement setEditinstances(instantiation_list editinstances,
                                               buffernet_statement b);
   extern bool hasType(buffernet_statement b);
   extern bool hasBufferName(buffernet_statement b);
   extern bool hasInputName(buffernet_statement b);
   extern bool hasOutputName(buffernet_statement b);
   extern bool hasEditinstances(buffernet_statement b);
   extern buffernet_statement deepCopy(buffernet_statement src);
   extern void deepFree(buffernet_statement b);

   #ifdef buffernet_statement_cc
      extern buffernet_statement buffernet_statementNew(buffer_type type,
                                                        vname bufferName,
                                                        text inputName,
                                                        text outputName,
                                                        instantiation_list editinstances);
      extern buffernet_statement copy(buffernet_statement src,
                                      size_t level);
      extern void dump(text Offset,
                       buffernet_statement b,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(buffernet_statement b,
                       size_t level);

   #else
      extern buffernet_statement buffernet_statementNew(buffer_type type = _BUFFER_TYPE_UNDEFINED,
                                                        vname bufferName = NULL,
                                                        text inputName = "A",
                                                        text outputName = "Z",
                                                        instantiation_list editinstances = NULL);
      extern buffernet_statement copy(buffernet_statement src,
                                      size_t level = 0);
      extern void dump(text Offset,
                       buffernet_statement b,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(buffernet_statement b,
                       size_t level = 0);

   #endif
// End External Functions
#endif
