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

#ifndef remove_buf_statement_INCLUDED
#define remove_buf_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfSignals(signal_list signals,
                             remove_buf_statement r);
   extern bool eqSignals(signal_list signals,
                         remove_buf_statement r);
   extern bool eqSelfBuffers(name_list buffers,
                             remove_buf_statement r);
   extern bool eqBuffers(name_list buffers,
                         remove_buf_statement r);
   extern bool eqSelf(remove_buf_statement a,
                      remove_buf_statement b);
   extern bool Eq(remove_buf_statement a,
                  remove_buf_statement b);
   extern signal_list getSignals(remove_buf_statement r);
   extern name_list getBuffers(remove_buf_statement r);
   extern remove_buf_statement setSignals(signal_list signals,
                                          remove_buf_statement r);
   extern remove_buf_statement setBuffers(name_list buffers,
                                          remove_buf_statement r);
   extern bool hasSignals(remove_buf_statement r);
   extern bool hasBuffers(remove_buf_statement r);
   extern remove_buf_statement deepCopy(remove_buf_statement src);
   extern void deepFree(remove_buf_statement r);

   #ifdef remove_buf_statement_cc
      extern remove_buf_statement remove_buf_statementNew(signal_list signals,
                                                          name_list buffers);
      extern remove_buf_statement copy(remove_buf_statement src,
                                       size_t level);
      extern void dump(text Offset,
                       remove_buf_statement r,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(remove_buf_statement r,
                       size_t level);

   #else
      extern remove_buf_statement remove_buf_statementNew(signal_list signals = NULL,
                                                          name_list buffers = NULL);
      extern remove_buf_statement copy(remove_buf_statement src,
                                       size_t level = 0);
      extern void dump(text Offset,
                       remove_buf_statement r,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(remove_buf_statement r,
                       size_t level = 0);

   #endif
// End External Functions
#endif
