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

#ifndef std_macro_INCLUDED
#define std_macro_INCLUDED



#ifndef NO_C3PO_OPERATORS

#ifndef NO_C3PO_EQ
#define    eq      ==              /* Logical 'equals'                        */
#endif

#ifndef NO_C3PO_NE
#define    ne      !=              /* Logical inequality                      */
#endif

#ifdef NEED_C3PO_NOT
#define    not      !              /* Logical 'NOT'                           */
#endif

#ifndef NO_C3PO_BNOT
#define    bnot      ~              /* Bitwise 'NOT'  (one's complement)       */
#endif

#ifndef NO_C3PO_CAND
#define    cand      &&              /* Conditional 'AND'                       */
#endif

#ifdef NEED_C3PO_AND
#define    and      &&              /* Logical 'AND'                           */
#endif

#ifndef NO_C3PO_BAND
#define    band      &              /* Bitwise 'AND'                           */
#endif

#ifndef NO_C3PO_COR
#define    cor      ||              /* Conditional 'OR'                        */
#endif

#ifdef NEED_C3PO_OR
#define    or      ||              /* Logical 'OR'                            */
#endif

#ifndef NO_C3PO_BOR
#define    bor      |              /* Bitwise 'OR'                            */
#endif

#ifndef NO_C3PO_BXOR
#define    bxor      ^              /* Bitwise exclusive 'OR'                  */
#endif

#ifndef NO_C3PO_MOD
#define    mod      %              /* Remainder operator                      */
#endif

#endif // NO_C3PO_OPERATORS

#ifndef NULL
#define    NULL      0              /* Null pointer                            */
#endif

#ifndef EOF
#define    EOF      -1              /* end of file                             */
#endif

#ifdef PSEUDO_BOOL

#ifdef HAS_FUTURE_RESERVED_BOOL
#define bool c3po_bool
#endif

typedef    int bool;                /* pseudo boolean                         */

#ifndef true
#define    true      1              /* pseudo boolean true value */
#endif

#ifndef false
#define    false      0              /* pseudo boolean false value */
#endif

#endif // PSEUDO_BOOL

#define    expvar                   /* export variable                        */
#define    expfun                   /* export function                        */

#ifdef SETTRACE
#define TRACE(x) x
#else
#define TRACE(x)
#endif

#endif
