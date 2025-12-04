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

#ifndef ModuleItemList_INCLUDED
#define ModuleItemList_INCLUDED
   extern signal_type getType(text name, module_item_list l);
   extern declaration_list getDeclarations(module_item_list mil);
   extern declaration_list getPortDeclarations(module_item_list mil);
   extern declaration_list getNetDeclarations(module_item_list mil);
   extern assign_list getAssigns(module_item_list mil);
   extern parameter_decl_list getParameter_declarations(module_item_list mil);
   extern void add(declaration d, module_item_list l);
   extern instantiation_list getInstances(module_item_list mil);
   extern void add(instance inst, module_item_list l);
   extern bool hasInstances(module_item_list l);
   extern ssize_t In(instance i, module_item_list l);
   extern instance getInstance(instance i, module_item_list l);
   extern void expandSignals(module_item_list i);
   extern void expandSignals(module_item_list i, simple_signal s, range r);
   extern int renameNet(module_item_list l, simple_signal oldname, simple_signal newname, bool ignoreIndex, simple_signal_list excludes);
   extern int renameNet(module_item_list l, simple_signal oldname, simple_signal newname, bool ignoreIndex, simple_signal_list excludes, match_list ml);
   extern simple_signal_list getSignals(module_item_list i);
   extern nameset getInstNames(module_item_list l);
   extern bool In(variable_name s, module_item_list l, signal_type t);
   extern bool In(text name, module_item_list l, signal_type t);
   extern bool hasPortDeclaration(text name, module_item_list l);
   extern range getRange(text name, module_item_list l);
   extern range getRange(vname name, module_item_list l);
   extern void add(continuous_assign a, module_item_list l);
   extern void add(parameter_decl a, module_item_list l);
   extern bool hasAssigns(module_item_list l);
   extern void bufferNet(module_item_list l,  instance i, buffernet_statement b, nameset allinsts, simple_signal_list allnets, buffer_type t);
#endif
