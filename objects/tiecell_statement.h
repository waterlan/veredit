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

#ifndef tiecell_statement_INCLUDED
#define tiecell_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfModuleName(vname moduleName,
                                tiecell_statement t);
   extern bool eqModuleName(vname moduleName,
                            tiecell_statement t);
   extern bool eqSelfOutputName(vname outputName,
                                tiecell_statement t);
   extern bool eqOutputName(vname outputName,
                            tiecell_statement t);
   extern bool eqSelfOtherPins(portmap otherPins,
                               tiecell_statement t);
   extern bool eqOtherPins(portmap otherPins,
                           tiecell_statement t);
   extern bool eqSelfNets(simple_signal_list Nets,
                          tiecell_statement t);
   extern bool eqNets(simple_signal_list Nets,
                      tiecell_statement t);
   extern bool eqSelfExcludes(simple_signal_list excludes,
                              tiecell_statement t);
   extern bool eqExcludes(simple_signal_list excludes,
                          tiecell_statement t);
   extern bool eqSelfInstances(match_list instances,
                               tiecell_statement t);
   extern bool eqInstances(match_list instances,
                           tiecell_statement t);
   extern bool eqSelfInstLabel(text instLabel,
                               tiecell_statement t);
   extern bool eqInstLabel(text instLabel,
                           tiecell_statement t);
   extern bool eqSelf(tiecell_statement a,
                      tiecell_statement b);
   extern bool Eq(tiecell_statement a,
                  tiecell_statement b);
   extern vname getModuleName(tiecell_statement t);
   extern vname getOutputName(tiecell_statement t);
   extern portmap getOtherPins(tiecell_statement t);
   extern simple_signal_list getNets(tiecell_statement t);
   extern simple_signal_list getExcludes(tiecell_statement t);
   extern match_list getInstances(tiecell_statement t);
   extern text getInstLabel(tiecell_statement t);
   extern tiecell_statement setModuleName(vname moduleName,
                                          tiecell_statement t);
   extern tiecell_statement setOutputName(vname outputName,
                                          tiecell_statement t);
   extern tiecell_statement setOtherPins(portmap otherPins,
                                         tiecell_statement t);
   extern tiecell_statement setNets(simple_signal_list Nets,
                                    tiecell_statement t);
   extern tiecell_statement setExcludes(simple_signal_list excludes,
                                        tiecell_statement t);
   extern tiecell_statement setInstances(match_list instances,
                                         tiecell_statement t);
   extern tiecell_statement setInstLabel(text instLabel,
                                         tiecell_statement t);
   extern bool hasModuleName(tiecell_statement t);
   extern bool hasOutputName(tiecell_statement t);
   extern bool hasOtherPins(tiecell_statement t);
   extern bool hasNets(tiecell_statement t);
   extern bool hasExcludes(tiecell_statement t);
   extern bool hasInstances(tiecell_statement t);
   extern bool hasInstLabel(tiecell_statement t);
   extern tiecell_statement deepCopy(tiecell_statement src);
   extern void deepFree(tiecell_statement t);

   #ifdef tiecell_statement_cc
      extern tiecell_statement tiecell_statementNew(vname moduleName,
                                                    vname outputName,
                                                    portmap otherPins,
                                                    simple_signal_list Nets,
                                                    simple_signal_list excludes,
                                                    match_list instances,
                                                    text instLabel);
      extern tiecell_statement copy(tiecell_statement src,
                                    size_t level);
      extern void dump(text Offset,
                       tiecell_statement t,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(tiecell_statement t,
                       size_t level);

   #else
      extern tiecell_statement tiecell_statementNew(vname moduleName = NULL,
                                                    vname outputName = NULL,
                                                    portmap otherPins = NULL,
                                                    simple_signal_list Nets = NULL,
                                                    simple_signal_list excludes = NULL,
                                                    match_list instances = NULL,
                                                    text instLabel = "");
      extern tiecell_statement copy(tiecell_statement src,
                                    size_t level = 0);
      extern void dump(text Offset,
                       tiecell_statement t,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(tiecell_statement t,
                       size_t level = 0);

   #endif
// End External Functions
#endif
