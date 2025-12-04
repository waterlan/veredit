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

#ifndef shell_statement_INCLUDED
#define shell_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfShellName(vname shellName,
                               shell_statement s);
   extern bool eqShellName(vname shellName,
                           shell_statement s);
   extern bool eqSelf(shell_statement a,
                      shell_statement b);
   extern bool Eq(shell_statement a,
                  shell_statement b);
   extern vname getShellName(shell_statement s);
   extern shell_statement setShellName(vname shellName,
                                       shell_statement s);
   extern bool hasShellName(shell_statement s);
   extern shell_statement deepCopy(shell_statement src);
   extern void deepFree(shell_statement s);

   #ifdef shell_statement_cc
      extern shell_statement shell_statementNew(vname shellName);
      extern shell_statement copy(shell_statement src,
                                  size_t level);
      extern void dump(text Offset,
                       shell_statement s,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(shell_statement s,
                       size_t level);

   #else
      extern shell_statement shell_statementNew(vname shellName = NULL);
      extern shell_statement copy(shell_statement src,
                                  size_t level = 0);
      extern void dump(text Offset,
                       shell_statement s,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(shell_statement s,
                       size_t level = 0);

   #endif
// End External Functions
#endif
