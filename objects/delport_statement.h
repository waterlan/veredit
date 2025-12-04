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

#ifndef delport_statement_INCLUDED
#define delport_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqType(editport_type type,
                      delport_statement d);
   extern bool eqSelfDelports(port_list delports,
                              delport_statement d);
   extern bool eqDelports(port_list delports,
                          delport_statement d);
   extern bool eqAll(bool allIn,
                     delport_statement d);
   extern bool eqSelf(delport_statement a,
                      delport_statement b);
   extern bool Eq(delport_statement a,
                  delport_statement b);
   extern editport_type getType(delport_statement d);
   extern port_list getDelports(delport_statement d);
   extern bool all(delport_statement d);
   extern delport_statement setType(editport_type type,
                                    delport_statement d);
   extern delport_statement setDelports(port_list delports,
                                        delport_statement d);
   extern delport_statement setAll(bool all,
                                   delport_statement d);
   extern bool hasType(delport_statement d);
   extern bool hasDelports(delport_statement d);
   extern delport_statement deepCopy(delport_statement src);
   extern void deepFree(delport_statement d);

   #ifdef delport_statement_cc
      extern delport_statement delport_statementNew(editport_type type,
                                                    port_list delports);
      extern delport_statement copy(delport_statement src,
                                    size_t level);
      extern void dump(text Offset,
                       delport_statement d,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(delport_statement d,
                       size_t level);

   #else
      extern delport_statement delport_statementNew(editport_type type = _EDITPORT_TYPE_UNDEFINED,
                                                    port_list delports = NULL);
      extern delport_statement copy(delport_statement src,
                                    size_t level = 0);
      extern void dump(text Offset,
                       delport_statement d,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(delport_statement d,
                       size_t level = 0);

   #endif
// End External Functions
#endif
