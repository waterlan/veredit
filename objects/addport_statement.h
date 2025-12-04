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

#ifndef addport_statement_INCLUDED
#define addport_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfAddports(declaration_list addports,
                              addport_statement a);
   extern bool eqAddports(declaration_list addports,
                          addport_statement a);
   extern bool eqSelf(addport_statement a,
                      addport_statement b);
   extern bool Eq(addport_statement a,
                  addport_statement b);
   extern declaration_list getAddports(addport_statement a);
   extern addport_statement setAddports(declaration_list addports,
                                        addport_statement a);
   extern bool hasAddports(addport_statement a);
   extern addport_statement deepCopy(addport_statement src);
   extern void deepFree(addport_statement a);

   #ifdef addport_statement_cc
      extern addport_statement addport_statementNew(declaration_list addports);
      extern addport_statement copy(addport_statement src,
                                    size_t level);
      extern void dump(text Offset,
                       addport_statement a,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(addport_statement a,
                       size_t level);

   #else
      extern addport_statement addport_statementNew(declaration_list addports = NULL);
      extern addport_statement copy(addport_statement src,
                                    size_t level = 0);
      extern void dump(text Offset,
                       addport_statement a,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(addport_statement a,
                       size_t level = 0);

   #endif
// End External Functions
#endif
