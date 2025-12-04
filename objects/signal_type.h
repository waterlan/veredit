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

#ifndef signal_type_INCLUDED
#define signal_type_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool Eq(signal_type a,
                  signal_type b);
   extern bool isINPUT(signal_type s);
   extern bool isOUTPUT(signal_type s);
   extern bool isINOUT(signal_type s);
   extern bool isWIRE(signal_type s);
   extern bool isSUPPLY0(signal_type s);
   extern bool isSUPPLY1(signal_type s);
   extern bool isTRI(signal_type s);
   extern bool isTRI0(signal_type s);
   extern bool isTRI1(signal_type s);
   extern bool isTRIOR(signal_type s);
   extern bool isTRIAND(signal_type s);
   extern bool isTRIREG(signal_type s);
   extern bool isWOR(signal_type s);
   extern bool isWAND(signal_type s);
   extern bool isUNDEFINED(signal_type s);
   extern text dumpToString(signal_type s);
   extern text toString(signal_type s);
   extern signal_type parseSignal_type(text t);

   #ifdef signal_type_cc
      extern void dump(text Offset,
                       signal_type s,
                       FILE* fp);

   #else
      extern void dump(text Offset,
                       signal_type s,
                       FILE* fp = stdout);

   #endif
// End External Functions
#endif
