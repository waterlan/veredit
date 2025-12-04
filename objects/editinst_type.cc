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

#define editinst_type_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "editinst_type.h"


expfun bool Eq(editinst_type a,
               editinst_type b)
{
   if (a == b)
      return true;
   else
      return false;
}
expfun bool isADDINST(editinst_type e)
{
    return Eq(e, _ADDINST);
}
expfun bool isDELINST(editinst_type e)
{
    return Eq(e, _DELINST);
}
expfun bool isMODINST(editinst_type e)
{
    return Eq(e, _MODINST);
}
expfun bool isUNDEFINED(editinst_type e)
{
    return Eq(e, _EDITINST_TYPE_UNDEFINED);
}
expfun void dump(text Offset,
                 editinst_type e,
                 FILE* fp = stdout)
{

   fprintf(fp, Offset);

   fprintf(fp, "%s", dumpToString(e));
}
expfun text dumpToString(editinst_type e)
{
   switch(e)
   {
      case _ADDINST : return "_ADDINST";
      case _DELINST : return "_DELINST";
      case _MODINST : return "_MODINST";

      default : return "_UNDEFINED";
   }
}
expfun text toString(editinst_type e)
{
   switch(e)
   {
      case _ADDINST : return "-addinst";
      case _DELINST : return "-delinst";
      case _MODINST : return "-modinst";

      default : return "";
   }
}
expfun editinst_type parseEditinst_type(text t)
{
   if (Eq(t, "_ADDINST") == true ||
       Eq(t, "-addinst") == true)
       return _ADDINST;
   else if (Eq(t, "_DELINST") == true ||
            Eq(t, "-delinst") == true)
       return _DELINST;
   else if (Eq(t, "_MODINST") == true ||
            Eq(t, "-modinst") == true)
       return _MODINST;
   else
       return _EDITINST_TYPE_UNDEFINED;
}
