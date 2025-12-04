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

#ifndef match_item_INCLUDED
#define match_item_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfName(vname name,
                          match_item m);
   extern bool eqName(vname name,
                      match_item m);
   extern bool eqSelfPattern(text pattern,
                             match_item m);
   extern bool eqPattern(text pattern,
                         match_item m);
   extern bool eqSelf(match_item a,
                      match_item b);
   extern bool Eq(match_item a,
                  match_item b);
   extern vname getName(match_item m);
   extern text getPattern(match_item m);
   extern match_item setName(vname name,
                             match_item m);
   extern match_item setPattern(text pattern,
                                match_item m);
   extern bool hasName(match_item m);
   extern bool hasPattern(match_item m);
   extern match_item deepCopy(match_item src);
   extern void deepFree(match_item m);

   #ifdef match_item_cc
      extern match_item match_itemNew(vname name,
                                      text pattern);
      extern match_item copy(match_item src,
                             size_t level);
      extern void dump(text Offset,
                       match_item m,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(match_item m,
                       size_t level);

   #else
      extern match_item match_itemNew(vname name = NULL,
                                      text pattern = NULL);
      extern match_item copy(match_item src,
                             size_t level = 0);
      extern void dump(text Offset,
                       match_item m,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(match_item m,
                       size_t level = 0);

   #endif
// End External Functions
#endif
