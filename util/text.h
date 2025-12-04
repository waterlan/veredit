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

#ifndef text_INCLUDED
#define text_INCLUDED




// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern rwtext rwtextNew(size_t size);
   extern text textNew(size_t size);
   extern rwtext rwtextNew(text string);
   extern text textNew(text string);
   extern bool Eq(text a,
                  text b);
   extern bool eqSelf(text a,
                      text b);
   extern text concat(text a,
                      text b);
   extern text concat(text a,
                      text b,
                      text c);
   extern text concat(text a,
                      text b,
                      text c,
                      text d);
   extern text toString(int i);
   extern text toString(double d);
   extern text toString(size_t s);
   extern text toString(ssize_t s);

   #ifdef text_cc
      extern text repeat(text pattern,
                         size_t amount,
                         int bufferNr);
      extern text Spaces(size_t amount,
                         int bufferNr);
      extern text Tab(size_t amount,
                      int bufferNr);

   #else
      extern text repeat(text pattern,
                         size_t amount,
                         int bufferNr = -1);
      extern text Spaces(size_t amount,
                         int bufferNr = 0);
      extern text Tab(size_t amount,
                      int bufferNr = 0);

   #endif
// End External Functions
#endif
