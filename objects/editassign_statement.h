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

#ifndef editassign_statement_INCLUDED
#define editassign_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqType(editassign_type type,
                      editassign_statement e);
   extern bool eqSelfEditassigns(assign_list editassigns,
                                 editassign_statement e);
   extern bool eqEditassigns(assign_list editassigns,
                             editassign_statement e);
   extern bool eqAll(bool allIn,
                     editassign_statement e);
   extern bool eqSelf(editassign_statement a,
                      editassign_statement b);
   extern bool Eq(editassign_statement a,
                  editassign_statement b);
   extern editassign_type getType(editassign_statement e);
   extern assign_list getEditassigns(editassign_statement e);
   extern bool all(editassign_statement e);
   extern editassign_statement setType(editassign_type type,
                                       editassign_statement e);
   extern editassign_statement setEditassigns(assign_list editassigns,
                                              editassign_statement e);
   extern editassign_statement setAll(bool all,
                                      editassign_statement e);
   extern bool hasType(editassign_statement e);
   extern bool hasEditassigns(editassign_statement e);
   extern editassign_statement deepCopy(editassign_statement src);
   extern void deepFree(editassign_statement e);

   #ifdef editassign_statement_cc
      extern editassign_statement editassign_statementNew(editassign_type type,
                                                          assign_list editassigns);
      extern editassign_statement copy(editassign_statement src,
                                       size_t level);
      extern void dump(text Offset,
                       editassign_statement e,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(editassign_statement e,
                       size_t level);

   #else
      extern editassign_statement editassign_statementNew(editassign_type type = _EDITASSIGN_TYPE_UNDEFINED,
                                                          assign_list editassigns = NULL);
      extern editassign_statement copy(editassign_statement src,
                                       size_t level = 0);
      extern void dump(text Offset,
                       editassign_statement e,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(editassign_statement e,
                       size_t level = 0);

   #endif
// End External Functions
#endif
