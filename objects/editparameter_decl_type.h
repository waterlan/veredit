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

#ifndef editparameter_decl_type_INCLUDED
#define editparameter_decl_type_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool Eq(editparameter_decl_type a,
                  editparameter_decl_type b);
   extern bool isADDPARAMETERDECL(editparameter_decl_type e);
   extern bool isDELPARAMETERDECL(editparameter_decl_type e);
   extern bool isUNDEFINED(editparameter_decl_type e);
   extern text dumpToString(editparameter_decl_type e);
   extern text toString(editparameter_decl_type e);
   extern editparameter_decl_type parseEditparameter_decl_type(text t);

   #ifdef editparameter_decl_type_cc
      extern void dump(text Offset,
                       editparameter_decl_type e,
                       FILE* fp);

   #else
      extern void dump(text Offset,
                       editparameter_decl_type e,
                       FILE* fp = stdout);

   #endif
// End External Functions
#endif
