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

#ifndef port_expression_INCLUDED
#define port_expression_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfPortReference(port_reference portReference,
                                   port_expression p);
   extern bool eqPortReference(port_reference portReference,
                               port_expression p);
   extern bool eqSelfCmpnd(compound_port_reference cmpnd,
                           port_expression p);
   extern bool eqCmpnd(compound_port_reference cmpnd,
                       port_expression p);
   extern bool eqSelf(port_expression a,
                      port_expression b);
   extern bool Eq(port_expression a,
                  port_expression b);
   extern port_reference getPortReference(port_expression p);
   extern compound_port_reference getCmpnd(port_expression p);
   extern port_expression setPortReference(port_reference portReference,
                                           port_expression p);
   extern port_expression setCmpnd(compound_port_reference cmpnd,
                                   port_expression p);
   extern bool hasPortReference(port_expression p);
   extern bool hasCmpnd(port_expression p);
   extern port_expression deepCopy(port_expression src);
   extern void deepFree(port_expression p);

   #ifdef port_expression_cc
      extern port_expression port_expressionNew(port_reference portReference,
                                                compound_port_reference cmpnd);
      extern port_expression copy(port_expression src,
                                  size_t level);
      extern void dump(text Offset,
                       port_expression p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(port_expression p,
                       size_t level);

   #else
      extern port_expression port_expressionNew(port_reference portReference = NULL,
                                                compound_port_reference cmpnd = NULL);
      extern port_expression copy(port_expression src,
                                  size_t level = 0);
      extern void dump(text Offset,
                       port_expression p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(port_expression p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
