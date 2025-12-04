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

#ifndef pullup_pin_statement_INCLUDED
#define pullup_pin_statement_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfPins(simple_signal_list Pins,
                          pullup_pin_statement p);
   extern bool eqPins(simple_signal_list Pins,
                      pullup_pin_statement p);
   extern bool eqSelf(pullup_pin_statement a,
                      pullup_pin_statement b);
   extern bool Eq(pullup_pin_statement a,
                  pullup_pin_statement b);
   extern simple_signal_list getPins(pullup_pin_statement p);
   extern pullup_pin_statement setPins(simple_signal_list Pins,
                                       pullup_pin_statement p);
   extern bool hasPins(pullup_pin_statement p);
   extern pullup_pin_statement deepCopy(pullup_pin_statement src);
   extern void deepFree(pullup_pin_statement p);

   #ifdef pullup_pin_statement_cc
      extern pullup_pin_statement pullup_pin_statementNew(simple_signal_list Pins);
      extern pullup_pin_statement copy(pullup_pin_statement src,
                                       size_t level);
      extern void dump(text Offset,
                       pullup_pin_statement p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(pullup_pin_statement p,
                       size_t level);

   #else
      extern pullup_pin_statement pullup_pin_statementNew(simple_signal_list Pins = NULL);
      extern pullup_pin_statement copy(pullup_pin_statement src,
                                       size_t level = 0);
      extern void dump(text Offset,
                       pullup_pin_statement p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(pullup_pin_statement p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
