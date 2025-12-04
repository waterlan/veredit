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

#ifndef translation_unit_INCLUDED
#define translation_unit_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfItems(verilog_item_list items,
                           translation_unit t);
   extern bool eqItems(verilog_item_list items,
                       translation_unit t);
   extern bool eqSelfEdits(module_edit_list edits,
                           translation_unit t);
   extern bool eqEdits(module_edit_list edits,
                       translation_unit t);
   extern bool eqSelfRootNode(vnode rootNode,
                              translation_unit t);
   extern bool eqRootNode(vnode rootNode,
                          translation_unit t);
   extern bool eqSelf(translation_unit a,
                      translation_unit b);
   extern bool Eq(translation_unit a,
                  translation_unit b);
   extern verilog_item_list getItems(translation_unit t);
   extern module_edit_list getEdits(translation_unit t);
   extern vnode getRootNode(translation_unit t);
   extern translation_unit setItems(verilog_item_list items,
                                    translation_unit t);
   extern translation_unit setEdits(module_edit_list edits,
                                    translation_unit t);
   extern translation_unit setRootNode(vnode rootNode,
                                       translation_unit t);
   extern bool hasItems(translation_unit t);
   extern bool hasEdits(translation_unit t);
   extern bool hasRootNode(translation_unit t);
   extern translation_unit deepCopy(translation_unit src);
   extern void deepFree(translation_unit t);
   extern void setTranslation_unitParserInputStream(FILE* stream);
   extern void setTranslation_unitParserOutputStream(FILE* stream);
   extern void setTranslation_unitParserErrorStream(FILE* stream);
   extern translation_unit getTranslation_unitDatabase(void);
   extern translation_unit parseTranslation_unit(nameset filenames);
   extern void setTranslation_unitScannerToStream(FILE* stream);
   extern translation_unit parseTranslation_unitFromInputStream(void);
   extern void writeTranslation_unitParserPrompt(void);
   extern void setTranslation_unitScannerToString(text string);
   extern void flushTranslation_unitScannerBuffer(void);

   #ifdef translation_unit_cc
      extern translation_unit translation_unitNew(verilog_item_list items,
                                                  module_edit_list edits);
      extern translation_unit copy(translation_unit src,
                                   size_t level);
      extern void dump(text Offset,
                       translation_unit t,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(translation_unit t,
                       size_t level);
      extern text getTranslation_unitCurrentParseItem(bool baseName);
      extern translation_unit parseTranslation_unitFromStream(FILE* fi,
                                                              int lineno);
      extern translation_unit parseTranslation_unitFromString(nameset strings,
                                                              int lineno);
      extern translation_unit parseTranslation_unitFromString(text string,
                                                              int lineno);

   #else
      extern translation_unit translation_unitNew(verilog_item_list items = NULL,
                                                  module_edit_list edits = NULL);
      extern translation_unit copy(translation_unit src,
                                   size_t level = 0);
      extern void dump(text Offset,
                       translation_unit t,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(translation_unit t,
                       size_t level = 0);
      extern text getTranslation_unitCurrentParseItem(bool baseName = false);
      extern translation_unit parseTranslation_unitFromStream(FILE* fi = stdin,
                                                              int lineno = -1);
      extern translation_unit parseTranslation_unitFromString(nameset strings,
                                                              int lineno = -1);
      extern translation_unit parseTranslation_unitFromString(text string,
                                                              int lineno = -1);

   #endif
// End External Functions
#endif
