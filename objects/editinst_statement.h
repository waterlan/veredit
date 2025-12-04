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

#ifndef editinst_statement_INCLUDED
#define editinst_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqType(editinst_type type,
                      editinst_statement e);
   extern bool eqKeepmodname(bool keepmodnameIn,
                             editinst_statement e);
   extern bool eqSelfEditinstances(instantiation_list editinstances,
                                   editinst_statement e);
   extern bool eqEditinstances(instantiation_list editinstances,
                               editinst_statement e);
   extern bool eqAll(bool allIn,
                     editinst_statement e);
   extern bool eqSelf(editinst_statement a,
                      editinst_statement b);
   extern bool Eq(editinst_statement a,
                  editinst_statement b);
   extern editinst_type getType(editinst_statement e);
   extern bool keepmodname(editinst_statement e);
   extern instantiation_list getEditinstances(editinst_statement e);
   extern bool all(editinst_statement e);
   extern editinst_statement setType(editinst_type type,
                                     editinst_statement e);
   extern editinst_statement setKeepmodname(bool keepmodname,
                                            editinst_statement e);
   extern editinst_statement setEditinstances(instantiation_list editinstances,
                                              editinst_statement e);
   extern editinst_statement setAll(bool all,
                                    editinst_statement e);
   extern bool hasType(editinst_statement e);
   extern bool hasEditinstances(editinst_statement e);
   extern editinst_statement deepCopy(editinst_statement src);
   extern void deepFree(editinst_statement e);

   #ifdef editinst_statement_cc
      extern editinst_statement editinst_statementNew(editinst_type type,
                                                      instantiation_list editinstances);
      extern editinst_statement copy(editinst_statement src,
                                     size_t level);
      extern void dump(text Offset,
                       editinst_statement e,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(editinst_statement e,
                       size_t level);

   #else
      extern editinst_statement editinst_statementNew(editinst_type type = _EDITINST_TYPE_UNDEFINED,
                                                      instantiation_list editinstances = NULL);
      extern editinst_statement copy(editinst_statement src,
                                     size_t level = 0);
      extern void dump(text Offset,
                       editinst_statement e,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(editinst_statement e,
                       size_t level = 0);

   #endif
// End External Functions
#endif
