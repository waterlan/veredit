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

#define signal_type_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "signal_type.h"


expfun bool Eq(signal_type a,
               signal_type b)
{
   if (a == b)
      return true;
   else
      return false;
}
expfun bool isINPUT(signal_type s)
{
    return Eq(s, _INPUT);
}
expfun bool isOUTPUT(signal_type s)
{
    return Eq(s, _OUTPUT);
}
expfun bool isINOUT(signal_type s)
{
    return Eq(s, _INOUT);
}
expfun bool isWIRE(signal_type s)
{
    return Eq(s, _WIRE);
}
expfun bool isSUPPLY0(signal_type s)
{
    return Eq(s, _SUPPLY0);
}
expfun bool isSUPPLY1(signal_type s)
{
    return Eq(s, _SUPPLY1);
}
expfun bool isTRI(signal_type s)
{
    return Eq(s, _TRI);
}
expfun bool isTRI0(signal_type s)
{
    return Eq(s, _TRI0);
}
expfun bool isTRI1(signal_type s)
{
    return Eq(s, _TRI1);
}
expfun bool isTRIOR(signal_type s)
{
    return Eq(s, _TRIOR);
}
expfun bool isTRIAND(signal_type s)
{
    return Eq(s, _TRIAND);
}
expfun bool isTRIREG(signal_type s)
{
    return Eq(s, _TRIREG);
}
expfun bool isWOR(signal_type s)
{
    return Eq(s, _WOR);
}
expfun bool isWAND(signal_type s)
{
    return Eq(s, _WAND);
}
expfun bool isUNDEFINED(signal_type s)
{
    return Eq(s, _SIGNAL_TYPE_UNDEFINED);
}
expfun void dump(text Offset,
                 signal_type s,
                 FILE* fp = stdout)
{

   fprintf(fp, Offset);

   fprintf(fp, "%s", dumpToString(s));
}
expfun text dumpToString(signal_type s)
{
   switch(s)
   {
      case _INPUT : return "_INPUT";
      case _OUTPUT : return "_OUTPUT";
      case _INOUT : return "_INOUT";
      case _WIRE : return "_WIRE";
      case _SUPPLY0 : return "_SUPPLY0";
      case _SUPPLY1 : return "_SUPPLY1";
      case _TRI : return "_TRI";
      case _TRI0 : return "_TRI0";
      case _TRI1 : return "_TRI1";
      case _TRIOR : return "_TRIOR";
      case _TRIAND : return "_TRIAND";
      case _TRIREG : return "_TRIREG";
      case _WOR : return "_WOR";
      case _WAND : return "_WAND";

      default : return "_UNDEFINED";
   }
}
expfun text toString(signal_type s)
{
   switch(s)
   {
      case _INPUT : return "input";
      case _OUTPUT : return "output";
      case _INOUT : return "inout";
      case _WIRE : return "wire";
      case _SUPPLY0 : return "supply0";
      case _SUPPLY1 : return "supply1";
      case _TRI : return "tri";
      case _TRI0 : return "tri0";
      case _TRI1 : return "tri1";
      case _TRIOR : return "trior";
      case _TRIAND : return "triand";
      case _TRIREG : return "trireg";
      case _WOR : return "wor";
      case _WAND : return "wand";

      default : return "";
   }
}
expfun signal_type parseSignal_type(text t)
{
   if (Eq(t, "_INPUT") == true ||
       Eq(t, "input") == true)
       return _INPUT;
   else if (Eq(t, "_OUTPUT") == true ||
            Eq(t, "output") == true)
       return _OUTPUT;
   else if (Eq(t, "_INOUT") == true ||
            Eq(t, "inout") == true)
       return _INOUT;
   else if (Eq(t, "_WIRE") == true ||
            Eq(t, "wire") == true)
       return _WIRE;
   else if (Eq(t, "_SUPPLY0") == true ||
            Eq(t, "supply0") == true)
       return _SUPPLY0;
   else if (Eq(t, "_SUPPLY1") == true ||
            Eq(t, "supply1") == true)
       return _SUPPLY1;
   else if (Eq(t, "_TRI") == true ||
            Eq(t, "tri") == true)
       return _TRI;
   else if (Eq(t, "_TRI0") == true ||
            Eq(t, "tri0") == true)
       return _TRI0;
   else if (Eq(t, "_TRI1") == true ||
            Eq(t, "tri1") == true)
       return _TRI1;
   else if (Eq(t, "_TRIOR") == true ||
            Eq(t, "trior") == true)
       return _TRIOR;
   else if (Eq(t, "_TRIAND") == true ||
            Eq(t, "triand") == true)
       return _TRIAND;
   else if (Eq(t, "_TRIREG") == true ||
            Eq(t, "trireg") == true)
       return _TRIREG;
   else if (Eq(t, "_WOR") == true ||
            Eq(t, "wor") == true)
       return _WOR;
   else if (Eq(t, "_WAND") == true ||
            Eq(t, "wand") == true)
       return _WAND;
   else
       return _SIGNAL_TYPE_UNDEFINED;
}
