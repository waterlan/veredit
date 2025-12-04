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

#define buffer_type_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "buffer_type.h"


expfun bool Eq(buffer_type a,
               buffer_type b)
{
   if (a == b)
      return true;
   else
      return false;
}
expfun bool isBUFFER(buffer_type b)
{
    return Eq(b, _BUFFER);
}
expfun bool isBUFFERINPUT(buffer_type b)
{
    return Eq(b, _BUFFERINPUT);
}
expfun bool isUNDEFINED(buffer_type b)
{
    return Eq(b, _BUFFER_TYPE_UNDEFINED);
}
expfun void dump(text Offset,
                 buffer_type b,
                 FILE* fp = stdout)
{

   fprintf(fp, Offset);

   fprintf(fp, "%s", dumpToString(b));
}
expfun text dumpToString(buffer_type b)
{
   switch(b)
   {
      case _BUFFER : return "_BUFFER";
      case _BUFFERINPUT : return "_BUFFERINPUT";

      default : return "_UNDEFINED";
   }
}
expfun text toString(buffer_type b)
{
   switch(b)
   {
      case _BUFFER : return "-buffer";
      case _BUFFERINPUT : return "-bufferinput";

      default : return "";
   }
}
expfun buffer_type parseBuffer_type(text t)
{
   if (Eq(t, "_BUFFER") == true ||
       Eq(t, "-buffer") == true)
       return _BUFFER;
   else if (Eq(t, "_BUFFERINPUT") == true ||
            Eq(t, "-bufferinput") == true)
       return _BUFFERINPUT;
   else
       return _BUFFER_TYPE_UNDEFINED;
}
