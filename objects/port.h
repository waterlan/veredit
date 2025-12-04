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

#ifndef port_INCLUDED
#define port_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfPortExpression(port_expression portExpression,
                                    port p);
   extern bool eqPortExpression(port_expression portExpression,
                                port p);
   extern bool eqSelfPortName(vname portName,
                              port p);
   extern bool eqPortName(vname portName,
                          port p);
   extern bool eqSelfPortExpression2(port_expression portExpression2,
                                     port p);
   extern bool eqPortExpression2(port_expression portExpression2,
                                 port p);
   extern bool eqSelf(port a,
                      port b);
   extern bool Eq(port a,
                  port b);
   extern port_expression getPortExpression(port p);
   extern vname getPortName(port p);
   extern port_expression getPortExpression2(port p);
   extern port setPortExpression(port_expression portExpression,
                                 port p);
   extern port setPortName(vname portName,
                           port p);
   extern port setPortExpression2(port_expression portExpression2,
                                  port p);
   extern bool hasPortExpression(port p);
   extern bool hasPortName(port p);
   extern bool hasPortExpression2(port p);
   extern port deepCopy(port src);
   extern void deepFree(port p);

   #ifdef port_cc
      extern port portNew(port_expression portExpression,
                          vname portName,
                          port_expression portExpression2);
      extern port copy(port src,
                       size_t level);
      extern void dump(text Offset,
                       port p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(port p,
                       size_t level);

   #else
      extern port portNew(port_expression portExpression = NULL,
                          vname portName = NULL,
                          port_expression portExpression2 = NULL);
      extern port copy(port src,
                       size_t level = 0);
      extern void dump(text Offset,
                       port p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(port p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
