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

#ifndef compound_port_reference_INCLUDED
#define compound_port_reference_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfPortReferences(port_reference_list portReferences,
                                    compound_port_reference c);
   extern bool eqPortReferences(port_reference_list portReferences,
                                compound_port_reference c);
   extern bool eqSelf(compound_port_reference a,
                      compound_port_reference b);
   extern bool Eq(compound_port_reference a,
                  compound_port_reference b);
   extern port_reference_list getPortReferences(compound_port_reference c);
   extern compound_port_reference setPortReferences(port_reference_list portReferences,
                                                    compound_port_reference c);
   extern bool hasPortReferences(compound_port_reference c);
   extern compound_port_reference deepCopy(compound_port_reference src);
   extern void deepFree(compound_port_reference c);

   #ifdef compound_port_reference_cc
      extern compound_port_reference compound_port_referenceNew(port_reference_list portReferences);
      extern compound_port_reference copy(compound_port_reference src,
                                          size_t level);
      extern void dump(text Offset,
                       compound_port_reference c,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(compound_port_reference c,
                       size_t level);

   #else
      extern compound_port_reference compound_port_referenceNew(port_reference_list portReferences = NULL);
      extern compound_port_reference copy(compound_port_reference src,
                                          size_t level = 0);
      extern void dump(text Offset,
                       compound_port_reference c,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(compound_port_reference c,
                       size_t level = 0);

   #endif
// End External Functions
#endif
