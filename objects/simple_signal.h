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

#ifndef simple_signal_INCLUDED
#define simple_signal_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqCnst(int cnst,
                      simple_signal s);
   extern bool eqSelfName(vname name,
                          simple_signal s);
   extern bool eqName(vname name,
                      simple_signal s);
   extern bool eqBusIndex(int busIndex,
                          simple_signal s);
   extern bool eqSelfRnge(range rnge,
                          simple_signal s);
   extern bool eqRnge(range rnge,
                      simple_signal s);
   extern bool eqSelf(simple_signal a,
                      simple_signal b);
   extern bool Eq(simple_signal a,
                  simple_signal b);
   extern int getCnst(simple_signal s);
   extern vname getName(simple_signal s);
   extern int getBusIndex(simple_signal s);
   extern range getRnge(simple_signal s);
   extern simple_signal setCnst(int cnst,
                                simple_signal s);
   extern simple_signal setName(vname name,
                                simple_signal s);
   extern simple_signal setBusIndex(int busIndex,
                                    simple_signal s);
   extern simple_signal setRnge(range rnge,
                                simple_signal s);
   extern bool hasCnst(simple_signal s);
   extern bool hasName(simple_signal s);
   extern bool hasBusIndex(simple_signal s);
   extern bool hasRnge(simple_signal s);
   extern simple_signal deepCopy(simple_signal src);
   extern void deepFree(simple_signal s);

   #ifdef simple_signal_cc
      extern simple_signal simple_signalNew(int cnst,
                                            vname name,
                                            int busIndex,
                                            range rnge);
      extern simple_signal copy(simple_signal src,
                                size_t level);
      extern void dump(text Offset,
                       simple_signal s,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(simple_signal s,
                       size_t level);

   #else
      extern simple_signal simple_signalNew(int cnst = -1,
                                            vname name = NULL,
                                            int busIndex = -1,
                                            range rnge = NULL);
      extern simple_signal copy(simple_signal src,
                                size_t level = 0);
      extern void dump(text Offset,
                       simple_signal s,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(simple_signal s,
                       size_t level = 0);

   #endif
// End External Functions
#endif
