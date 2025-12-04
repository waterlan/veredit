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

#ifndef instance_INCLUDED
#define instance_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfCellName(vname cellName,
                              instance i);
   extern bool eqCellName(vname cellName,
                          instance i);
   extern bool eqSelfInstName(vname instName,
                              instance i);
   extern bool eqInstName(vname instName,
                          instance i);
   extern bool eqSelfConnections(portmap connections,
                                 instance i);
   extern bool eqConnections(portmap connections,
                             instance i);
   extern bool eqSelfConnections_by_order(signal_list connections_by_order,
                                          instance i);
   extern bool eqConnections_by_order(signal_list connections_by_order,
                                      instance i);
   extern bool eqSelf(instance a,
                      instance b);
   extern bool Eq(instance a,
                  instance b);
   extern vname getCellName(instance i);
   extern vname getInstName(instance i);
   extern portmap getConnections(instance i);
   extern signal_list getConnections_by_order(instance i);
   extern instance setCellName(vname cellName,
                               instance i);
   extern instance setInstName(vname instName,
                               instance i);
   extern instance setConnections(portmap connections,
                                  instance i);
   extern instance setConnections_by_order(signal_list connections_by_order,
                                           instance i);
   extern bool hasCellName(instance i);
   extern bool hasInstName(instance i);
   extern bool hasConnections(instance i);
   extern bool hasConnections_by_order(instance i);
   extern instance deepCopy(instance src);
   extern void deepFree(instance i);

   #ifdef instance_cc
      extern instance instanceNew(vname cellName,
                                  vname instName,
                                  portmap connections,
                                  signal_list connections_by_order);
      extern instance copy(instance src,
                           size_t level);
      extern void dump(text Offset,
                       instance i,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(instance i,
                       size_t level);

   #else
      extern instance instanceNew(vname cellName = NULL,
                                  vname instName = NULL,
                                  portmap connections = NULL,
                                  signal_list connections_by_order = NULL);
      extern instance copy(instance src,
                           size_t level = 0);
      extern void dump(text Offset,
                       instance i,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(instance i,
                       size_t level = 0);

   #endif
// End External Functions
#endif
