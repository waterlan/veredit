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

#ifndef Instance_INCLUDED
#define Instance_INCLUDED
   extern module getModule(instance i, translation_unit t);
   extern bool isLeafCell(instance i, translation_unit t);
   extern bool isUndeclaredCell(instance i, translation_unit t);
   extern edit_element getEditElement(instance i, module_edit m);
   extern text getInstName(instance i, module_edit m);
   extern bool modified(instance i, module_edit m);
   extern bool equal(vname name, instance i);
   extern bool equal(module m, instance i);
   extern bool eqInstName(instance i, instance j);
   extern bool eqInstName(instance i, module_item j);
   extern simple_signal_list getSignals(instance i);
   extern instance getSignals(instance i, simple_signal s);
   extern int count(instance i, simple_signal s, signal_type t, translation_unit tu);
   extern int renameNet(instance i, simple_signal oldname, simple_signal newname, bool ignoreIndex, simple_signal_list excludes);
   extern void expandSignals(instance i);
   extern void expandSignals(instance i, simple_signal s, range r);
#endif
