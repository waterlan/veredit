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

#ifndef rename_instance_statement_INCLUDED
#define rename_instance_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfOldName(vname oldName,
                             rename_instance_statement r);
   extern bool eqOldName(vname oldName,
                         rename_instance_statement r);
   extern bool eqSelfNewName(vname newName,
                             rename_instance_statement r);
   extern bool eqNewName(vname newName,
                         rename_instance_statement r);
   extern bool eqSelf(rename_instance_statement a,
                      rename_instance_statement b);
   extern bool Eq(rename_instance_statement a,
                  rename_instance_statement b);
   extern vname getOldName(rename_instance_statement r);
   extern vname getNewName(rename_instance_statement r);
   extern rename_instance_statement setOldName(vname oldName,
                                               rename_instance_statement r);
   extern rename_instance_statement setNewName(vname newName,
                                               rename_instance_statement r);
   extern bool hasOldName(rename_instance_statement r);
   extern bool hasNewName(rename_instance_statement r);
   extern rename_instance_statement deepCopy(rename_instance_statement src);
   extern void deepFree(rename_instance_statement r);

   #ifdef rename_instance_statement_cc
      extern rename_instance_statement rename_instance_statementNew(vname oldName,
                                                                    vname newName);
      extern rename_instance_statement copy(rename_instance_statement src,
                                            size_t level);
      extern void dump(text Offset,
                       rename_instance_statement r,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(rename_instance_statement r,
                       size_t level);

   #else
      extern rename_instance_statement rename_instance_statementNew(vname oldName = NULL,
                                                                    vname newName = NULL);
      extern rename_instance_statement copy(rename_instance_statement src,
                                            size_t level = 0);
      extern void dump(text Offset,
                       rename_instance_statement r,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(rename_instance_statement r,
                       size_t level = 0);

   #endif
// End External Functions
#endif
