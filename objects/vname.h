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

#ifndef vname_INCLUDED
#define vname_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfN(text n,
                       vname v);
   extern bool eqN(text n,
                   vname v);
   extern bool eqSelf(vname a,
                      vname b);
   extern bool Eq(vname a,
                  vname b);
   extern text getN(vname v);
   extern vname setN(text n,
                     vname v);
   extern bool hasN(vname v);
   extern vname deepCopy(vname src);
   extern void deepFree(vname v);

   #ifdef vname_cc
      extern vname vnameNew(text n);
      extern vname copy(vname src,
                        size_t level);
      extern void dump(text Offset,
                       vname v,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(vname v,
                       size_t level);

   #else
      extern vname vnameNew(text n = NULL);
      extern vname copy(vname src,
                        size_t level = 0);
      extern void dump(text Offset,
                       vname v,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(vname v,
                       size_t level = 0);

   #endif
// End External Functions
#endif
