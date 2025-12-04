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

#ifndef portmap_element_INCLUDED
#define portmap_element_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfPinName(vname pinName,
                             portmap_element p);
   extern bool eqPinName(vname pinName,
                         portmap_element p);
   extern bool eqSelfSignals(signal_list signals,
                             portmap_element p);
   extern bool eqSignals(signal_list signals,
                         portmap_element p);
   extern bool eqSelf(portmap_element a,
                      portmap_element b);
   extern bool Eq(portmap_element a,
                  portmap_element b);
   extern vname getPinName(portmap_element p);
   extern signal_list getSignals(portmap_element p);
   extern portmap_element setPinName(vname pinName,
                                     portmap_element p);
   extern portmap_element setSignals(signal_list signals,
                                     portmap_element p);
   extern bool hasPinName(portmap_element p);
   extern bool hasSignals(portmap_element p);
   extern portmap_element deepCopy(portmap_element src);
   extern void deepFree(portmap_element p);

   #ifdef portmap_element_cc
      extern portmap_element portmap_elementNew(vname pinName,
                                                signal_list signals);
      extern portmap_element copy(portmap_element src,
                                  size_t level);
      extern void dump(text Offset,
                       portmap_element p,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(portmap_element p,
                       size_t level);

   #else
      extern portmap_element portmap_elementNew(vname pinName = NULL,
                                                signal_list signals = NULL);
      extern portmap_element copy(portmap_element src,
                                  size_t level = 0);
      extern void dump(text Offset,
                       portmap_element p,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(portmap_element p,
                       size_t level = 0);

   #endif
// End External Functions
#endif
