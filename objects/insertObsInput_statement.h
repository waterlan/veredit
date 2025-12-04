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

#ifndef insertObsInput_statement_INCLUDED
#define insertObsInput_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfModuleName(vname moduleName,
                                insertObsInput_statement i);
   extern bool eqModuleName(vname moduleName,
                            insertObsInput_statement i);
   extern bool eqSelfInputName(vname inputName,
                               insertObsInput_statement i);
   extern bool eqInputName(vname inputName,
                           insertObsInput_statement i);
   extern bool eqSelfOutputName(vname outputName,
                                insertObsInput_statement i);
   extern bool eqOutputName(vname outputName,
                            insertObsInput_statement i);
   extern bool eqSelfOtherPins(portmap otherPins,
                               insertObsInput_statement i);
   extern bool eqOtherPins(portmap otherPins,
                           insertObsInput_statement i);
   extern bool eqSelfNets(simple_signal_list Nets,
                          insertObsInput_statement i);
   extern bool eqNets(simple_signal_list Nets,
                      insertObsInput_statement i);
   extern bool eqSelf(insertObsInput_statement a,
                      insertObsInput_statement b);
   extern bool Eq(insertObsInput_statement a,
                  insertObsInput_statement b);
   extern vname getModuleName(insertObsInput_statement i);
   extern vname getInputName(insertObsInput_statement i);
   extern vname getOutputName(insertObsInput_statement i);
   extern portmap getOtherPins(insertObsInput_statement i);
   extern simple_signal_list getNets(insertObsInput_statement i);
   extern insertObsInput_statement setModuleName(vname moduleName,
                                                 insertObsInput_statement i);
   extern insertObsInput_statement setInputName(vname inputName,
                                                insertObsInput_statement i);
   extern insertObsInput_statement setOutputName(vname outputName,
                                                 insertObsInput_statement i);
   extern insertObsInput_statement setOtherPins(portmap otherPins,
                                                insertObsInput_statement i);
   extern insertObsInput_statement setNets(simple_signal_list Nets,
                                           insertObsInput_statement i);
   extern bool hasModuleName(insertObsInput_statement i);
   extern bool hasInputName(insertObsInput_statement i);
   extern bool hasOutputName(insertObsInput_statement i);
   extern bool hasOtherPins(insertObsInput_statement i);
   extern bool hasNets(insertObsInput_statement i);
   extern insertObsInput_statement deepCopy(insertObsInput_statement src);
   extern void deepFree(insertObsInput_statement i);

   #ifdef insertObsInput_statement_cc
      extern insertObsInput_statement insertObsInput_statementNew(vname moduleName,
                                                                  vname inputName,
                                                                  vname outputName,
                                                                  portmap otherPins,
                                                                  simple_signal_list Nets);
      extern insertObsInput_statement copy(insertObsInput_statement src,
                                           size_t level);
      extern void dump(text Offset,
                       insertObsInput_statement i,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(insertObsInput_statement i,
                       size_t level);

   #else
      extern insertObsInput_statement insertObsInput_statementNew(vname moduleName = NULL,
                                                                  vname inputName = NULL,
                                                                  vname outputName = NULL,
                                                                  portmap otherPins = NULL,
                                                                  simple_signal_list Nets = NULL);
      extern insertObsInput_statement copy(insertObsInput_statement src,
                                           size_t level = 0);
      extern void dump(text Offset,
                       insertObsInput_statement i,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(insertObsInput_statement i,
                       size_t level = 0);

   #endif
// End External Functions
#endif
