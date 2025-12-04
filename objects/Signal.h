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

#ifndef Signal_INCLUDED
#define Signal_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfSimple(simple_signal simple,
                            Signal s);
   extern bool eqSimple(simple_signal simple,
                        Signal s);
   extern bool eqSelfCmpnd(signal_list cmpnd,
                           Signal s);
   extern bool eqCmpnd(signal_list cmpnd,
                       Signal s);
   extern bool eqSelf(Signal a,
                      Signal b);
   extern bool Eq(Signal a,
                  Signal b);
   extern simple_signal getSimple(Signal s);
   extern signal_list getCmpnd(Signal s);
   extern Signal setSimple(simple_signal simple,
                           Signal s);
   extern Signal setCmpnd(signal_list cmpnd,
                          Signal s);
   extern bool hasSimple(Signal s);
   extern bool hasCmpnd(Signal s);
   extern Signal deepCopy(Signal src);
   extern void deepFree(Signal s);

   #ifdef Signal_cc
      extern Signal SignalNew(simple_signal simple,
                              signal_list cmpnd);
      extern Signal copy(Signal src,
                         size_t level);
      extern void dump(text Offset,
                       Signal s,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(Signal s,
                       size_t level);

   #else
      extern Signal SignalNew(simple_signal simple = NULL,
                              signal_list cmpnd = NULL);
      extern Signal copy(Signal src,
                         size_t level = 0);
      extern void dump(text Offset,
                       Signal s,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(Signal s,
                       size_t level = 0);

   #endif
// End External Functions
#endif
