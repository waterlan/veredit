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

#ifndef editparameter_decl_statement_INCLUDED
#define editparameter_decl_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqType(editparameter_decl_type type,
                      editparameter_decl_statement e);
   extern bool eqSelfEditparameter_decls(parameter_decl_list editparameter_decls,
                                         editparameter_decl_statement e);
   extern bool eqEditparameter_decls(parameter_decl_list editparameter_decls,
                                     editparameter_decl_statement e);
   extern bool eqAll(bool allIn,
                     editparameter_decl_statement e);
   extern bool eqSelf(editparameter_decl_statement a,
                      editparameter_decl_statement b);
   extern bool Eq(editparameter_decl_statement a,
                  editparameter_decl_statement b);
   extern editparameter_decl_type getType(editparameter_decl_statement e);
   extern parameter_decl_list getEditparameter_decls(editparameter_decl_statement e);
   extern bool all(editparameter_decl_statement e);
   extern editparameter_decl_statement setType(editparameter_decl_type type,
                                               editparameter_decl_statement e);
   extern editparameter_decl_statement setEditparameter_decls(parameter_decl_list editparameter_decls,
                                                              editparameter_decl_statement e);
   extern editparameter_decl_statement setAll(bool all,
                                              editparameter_decl_statement e);
   extern bool hasType(editparameter_decl_statement e);
   extern bool hasEditparameter_decls(editparameter_decl_statement e);
   extern editparameter_decl_statement deepCopy(editparameter_decl_statement src);
   extern void deepFree(editparameter_decl_statement e);

   #ifdef editparameter_decl_statement_cc
      extern editparameter_decl_statement editparameter_decl_statementNew(editparameter_decl_type type,
                                                                          parameter_decl_list editparameter_decls);
      extern editparameter_decl_statement copy(editparameter_decl_statement src,
                                               size_t level);
      extern void dump(text Offset,
                       editparameter_decl_statement e,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(editparameter_decl_statement e,
                       size_t level);

   #else
      extern editparameter_decl_statement editparameter_decl_statementNew(editparameter_decl_type type = _EDITPARAMETER_DECL_TYPE_UNDEFINED,
                                                                          parameter_decl_list editparameter_decls = NULL);
      extern editparameter_decl_statement copy(editparameter_decl_statement src,
                                               size_t level = 0);
      extern void dump(text Offset,
                       editparameter_decl_statement e,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(editparameter_decl_statement e,
                       size_t level = 0);

   #endif
// End External Functions
#endif
