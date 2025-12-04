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

#ifndef dot_INCLUDED
#define dot_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfParent(text parent,
                            dot d);
   extern bool eqParent(text parent,
                        dot d);
   extern bool eqSelfChild(text child,
                           dot d);
   extern bool eqChild(text child,
                       dot d);
   extern bool eqTimes(int times,
                       dot d);
   extern bool eqSelf(dot a,
                      dot b);
   extern bool Eq(dot a,
                  dot b);
   extern text getParent(dot d);
   extern text getChild(dot d);
   extern int getTimes(dot d);
   extern dot setParent(text parent,
                        dot d);
   extern dot setChild(text child,
                       dot d);
   extern dot setTimes(int times,
                       dot d);
   extern bool hasParent(dot d);
   extern bool hasChild(dot d);
   extern bool hasTimes(dot d);
   extern dot deepCopy(dot src);
   extern void deepFree(dot d);

   #ifdef dot_cc
      extern dot dotNew(text parent,
                        text child,
                        int times);
      extern dot copy(dot src,
                      size_t level);
      extern void dump(text Offset,
                       dot d,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(dot d,
                       size_t level);

   #else
      extern dot dotNew(text parent = NULL,
                        text child = NULL,
                        int times = 0);
      extern dot copy(dot src,
                      size_t level = 0);
      extern void dump(text Offset,
                       dot d,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(dot d,
                       size_t level = 0);

   #endif
// End External Functions
#endif
