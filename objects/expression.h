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

#ifndef expression_INCLUDED
#define expression_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqNumber(int number,
                        expression e);
   extern bool eqSelfSignal(Signal signal,
                            expression e);
   extern bool eqSignal(Signal signal,
                        expression e);
   extern bool eqSelfString(text string,
                            expression e);
   extern bool eqString(text string,
                        expression e);
   extern bool eqSelf(expression a,
                      expression b);
   extern bool Eq(expression a,
                  expression b);
   extern int getNumber(expression e);
   extern Signal getSignal(expression e);
   extern text getString(expression e);
   extern expression setNumber(int number,
                               expression e);
   extern expression setSignal(Signal signal,
                               expression e);
   extern expression setString(text string,
                               expression e);
   extern bool hasNumber(expression e);
   extern bool hasSignal(expression e);
   extern bool hasString(expression e);
   extern expression deepCopy(expression src);
   extern void deepFree(expression e);

   #ifdef expression_cc
      extern expression expressionNew(int number,
                                      Signal signal,
                                      text string);
      extern expression copy(expression src,
                             size_t level);
      extern void dump(text Offset,
                       expression e,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(expression e,
                       size_t level);

   #else
      extern expression expressionNew(int number = -1,
                                      Signal signal = NULL,
                                      text string = NULL);
      extern expression copy(expression src,
                             size_t level = 0);
      extern void dump(text Offset,
                       expression e,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(expression e,
                       size_t level = 0);

   #endif
// End External Functions
#endif
