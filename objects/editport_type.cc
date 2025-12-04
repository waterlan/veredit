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

#define editport_type_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "editport_type.h"


expfun bool Eq(editport_type a,
               editport_type b)
{
   if (a == b)
      return true;
   else
      return false;
}
expfun bool isDELPORTS(editport_type e)
{
    return Eq(e, _DELPORTS);
}
expfun bool isRMPORTS(editport_type e)
{
    return Eq(e, _RMPORTS);
}
expfun bool isDELNETS(editport_type e)
{
    return Eq(e, _DELNETS);
}
expfun bool isUNDEFINED(editport_type e)
{
    return Eq(e, _EDITPORT_TYPE_UNDEFINED);
}
expfun void dump(text Offset,
                 editport_type e,
                 FILE* fp = stdout)
{

   fprintf(fp, Offset);

   fprintf(fp, "%s", dumpToString(e));
}
expfun text dumpToString(editport_type e)
{
   switch(e)
   {
      case _DELPORTS : return "_DELPORTS";
      case _RMPORTS : return "_RMPORTS";
      case _DELNETS : return "_DELNETS";

      default : return "_UNDEFINED";
   }
}
expfun text toString(editport_type e)
{
   switch(e)
   {
      case _DELPORTS : return "-delports";
      case _RMPORTS : return "-rmports";
      case _DELNETS : return "-delnets";

      default : return "";
   }
}
expfun editport_type parseEditport_type(text t)
{
   if (Eq(t, "_DELPORTS") == true ||
       Eq(t, "-delports") == true)
       return _DELPORTS;
   else if (Eq(t, "_RMPORTS") == true ||
            Eq(t, "-rmports") == true)
       return _RMPORTS;
   else if (Eq(t, "_DELNETS") == true ||
            Eq(t, "-delnets") == true)
       return _DELNETS;
   else
       return _EDITPORT_TYPE_UNDEFINED;
}
