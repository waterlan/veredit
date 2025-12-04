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

#ifndef port_reference_INCLUDED
#define port_reference_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfName(vname name,
                          port_reference p);
   extern bool eqName(vname name,
                      port_reference p);
   extern bool eqBusIndex(int busIndex,
                          port_reference p);
   extern bool eqSelfRnge(range rnge,
                          port_reference p);
   extern bool eqRnge(range rnge,
                      port_reference p);
   extern bool eqSelf(port_reference a,
                      port_reference b);
   extern bool Eq(port_reference a,
                  port_reference b);
   extern vname getName(port_reference p);
   extern int getBusIndex(port_reference p);
   extern range getRnge(port_reference p);
   extern port_reference setName(vname name,
                                 port_reference p);
   extern port_reference setBusIndex(int busIndex,
                                     port_reference p);
   extern port_reference setRnge(range rnge,
                                 port_reference p);
   extern bool hasName(port_reference p);
   extern bool hasBusIndex(port_reference p);
   extern bool hasRnge(port_reference p);
   extern port_reference deepCopy(port_reference src);
   extern void deepFree(port_reference p);

   #ifdef port_reference_cc
      extern port_reference port_referenceNew(vname name,
                                              int busIndex,
                                              range rnge);
      extern port_reference copy(port_reference src,
                                 size_t level);
      extern void dump(text Offset,
                       port_reference p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(port_reference p,
                       size_t level);

   #else
      extern port_reference port_referenceNew(vname name = NULL,
                                              int busIndex = -1,
                                              range rnge = NULL);
      extern port_reference copy(port_reference src,
                                 size_t level = 0);
      extern void dump(text Offset,
                       port_reference p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(port_reference p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
