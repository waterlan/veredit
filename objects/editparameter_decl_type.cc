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

#define editparameter_decl_type_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "editparameter_decl_type.h"


expfun bool Eq(editparameter_decl_type a,
               editparameter_decl_type b)
{
   if (a == b)
      return true;
   else
      return false;
}
expfun bool isADDPARAMETERDECL(editparameter_decl_type e)
{
    return Eq(e, _ADDPARAMETERDECL);
}
expfun bool isDELPARAMETERDECL(editparameter_decl_type e)
{
    return Eq(e, _DELPARAMETERDECL);
}
expfun bool isUNDEFINED(editparameter_decl_type e)
{
    return Eq(e, _EDITPARAMETER_DECL_TYPE_UNDEFINED);
}
expfun void dump(text Offset,
                 editparameter_decl_type e,
                 FILE* fp = stdout)
{

   fprintf(fp, Offset);

   fprintf(fp, "%s", dumpToString(e));
}
expfun text dumpToString(editparameter_decl_type e)
{
   switch(e)
   {
      case _ADDPARAMETERDECL : return "_ADDPARAMETERDECL";
      case _DELPARAMETERDECL : return "_DELPARAMETERDECL";

      default : return "_UNDEFINED";
   }
}
expfun text toString(editparameter_decl_type e)
{
   switch(e)
   {
      case _ADDPARAMETERDECL : return "-addparameterdecl";
      case _DELPARAMETERDECL : return "-delparameterdecl";

      default : return "";
   }
}
expfun editparameter_decl_type parseEditparameter_decl_type(text t)
{
   if (Eq(t, "_ADDPARAMETERDECL") == true ||
       Eq(t, "-addparameterdecl") == true)
       return _ADDPARAMETERDECL;
   else if (Eq(t, "_DELPARAMETERDECL") == true ||
            Eq(t, "-delparameterdecl") == true)
       return _DELPARAMETERDECL;
   else
       return _EDITPARAMETER_DECL_TYPE_UNDEFINED;
}
