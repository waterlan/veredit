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

#ifndef Module_INCLUDED
#define Module_INCLUDED
   extern bool equal(text name, module m);
   extern bool isLeafCell(module m);
   extern bool Check(module m, translation_unit t);
   extern bool isParent(module child, module parent);
   extern void delAllAssigns(module m);
   extern void delAllParameter_declarations(module m);
   extern void delAllInstances(module m);
   extern assign_list getAssigns(module m);
   extern parameter_decl_list getParameter_declarations(module m);
   extern declaration_list getDeclarations(module m);
   extern declaration_list getPortDeclarations(module m);
   extern declaration_list getNetDeclarations(module m);
   extern instantiation_list getInstances(module m);
   extern simple_signal_list getSignals(module m, signal_type t);
   extern text getSignal(module m, signal_type t);
   extern signal_type getType(text name, module m);
   extern signal_type getType(simple_signal s, module m);
   extern instance bufferNew(simple_signal inputnet, simple_signal outputnet, text instname, text bufferinput, text bufferoutput, text buffername);
   extern instance obsNew(simple_signal inputnet, simple_signal outputnet, text instname, insertObsOutput_statement is);
   extern instance obsNew(simple_signal inputnet, simple_signal outputnet, text instname, insertObsInput_statement is);
   extern bool isBus(simple_signal s, module m);
   extern range getRange(text name, module m);
   extern range getRange(vname name, module m);
   extern void insertObsOutputs(insertObsOutput_statement is, module m, translation_unit t);
   extern void insertObsInputs(insertObsInput_statement is, module m, translation_unit t);
   extern void bufferOutputs(buffer_statement b, module m, translation_unit t);
   extern void insertTiecell(tiecell_statement t, module m);
   extern void removeBuffers(remove_buf_statement r, module m, translation_unit t);
   extern void shellModule(module m, vname shellname, translation_unit t);
   extern bool hasAssigns(module m);
   extern bool hasInstances(module m);
   extern void bufferAssigns(bufassigns_statement b, module m, translation_unit t);
   extern bool hasPortDeclaration(module m, text name);
   extern void pullupPins(pullup_pin_statement p, module m, translation_unit t);
   extern void getHierInstNames(module m, translation_unit t, FILE *fp);
#endif
