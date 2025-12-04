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

#ifndef range_INCLUDED
#define range_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqBegin(int begin,
                       range r);
   extern bool eqEnd(int end,
                     range r);
   extern bool eqSelf(range a,
                      range b);
   extern bool Eq(range a,
                  range b);
   extern int getBegin(range r);
   extern int getEnd(range r);
   extern range setBegin(int begin,
                         range r);
   extern range setEnd(int end,
                       range r);
   extern range copy(range src);
   extern void Free(range r);

   #ifdef range_cc
      extern range rangeNew(int begin,
                            int end);
      extern void dump(text Offset,
                       range r,
                       FILE* fp,
                       bool showEmpty);

   #else
      extern range rangeNew(int begin = 0,
                            int end = 0);
      extern void dump(text Offset,
                       range r,
                       FILE* fp = stdout,
                       bool showEmpty = false);

   #endif
// End External Functions
#endif
