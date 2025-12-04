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

#define variable_name_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "expression.h"
#include "variable_name.h"


expfun variable_name variable_nameNew(vname name = NULL,
                                      expression expr = NULL)
{
   variable_name v = (variable_name) malloc (sizeof(variable_name_struct));
   if (v != NULL)
   {
      v->name = name;
      v->expr = expr;
   }
   else
      malloc_error("variable_nameNew()");

   return v;
}
expfun bool eqSelfName(vname name,
                       variable_name v)
{
   if ((name == NULL) || (hasName(v) == false))
      return false;
   else if (eqSelf(name, getName(v)))
      return true;
   else
      return false;
}
expfun bool eqName(vname name,
                   variable_name v)
{
   if ((name == NULL) || (hasName(v) == false))
      return false;
   else if (Eq(name, getName(v)))
      return true;
   else
      return false;
}
expfun bool eqSelfExpr(expression expr,
                       variable_name v)
{
   if ((expr == NULL) || (hasExpr(v) == false))
      return false;
   else if (eqSelf(expr, getExpr(v)))
      return true;
   else
      return false;
}
expfun bool eqExpr(expression expr,
                   variable_name v)
{
   if ((expr == NULL) || (hasExpr(v) == false))
      return false;
   else if (Eq(expr, getExpr(v)))
      return true;
   else
      return false;
}
expfun bool eqSelf(variable_name a,
                   variable_name b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(variable_name a,
               variable_name b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqName(getName(a), b) == false)
      return false;
   else if (eqExpr(getExpr(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getName(variable_name v)
{
   if (v != NULL)
      return v->name;
   else
      return NULL;
}
expfun expression getExpr(variable_name v)
{
   if (v != NULL)
      return v->expr;
   else
      return NULL;
}
expfun variable_name setName(vname name,
                             variable_name v)
{
   if (v != NULL)
      v->name = name;
   return v;
}
expfun variable_name setExpr(expression expr,
                             variable_name v)
{
   if (v != NULL)
      v->expr = expr;
   return v;
}
expfun bool hasName(variable_name v)
{
   if (getName(v) != NULL)
      return true;
   else
      return false;
}
expfun bool hasExpr(variable_name v)
{
   if (getExpr(v) != NULL)
      return true;
   else
      return false;
}
expfun variable_name copy(variable_name src,
                          size_t level = 0)
{
   variable_name v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (variable_name) malloc (sizeof(variable_name_struct));
      if (v != NULL)
      {
         if (level > 0)
         {
            v->name = copy(src->name, level - 1);
            v->expr = copy(src->expr, level - 1);
         }
         else
         {
            v->name = src->name;
            v->expr = src->expr;
         }
      }
      else
         malloc_error("copy()");

      return v;
   }
}
expfun variable_name deepCopy(variable_name src)
{
   variable_name v;

   if (src == NULL)
      return NULL;
   else
   {
      v = (variable_name) malloc (sizeof(variable_name_struct));
      if (v != NULL)
      {
         v->name = deepCopy(src->name);
         v->expr = deepCopy(src->expr);
      }
      else
         malloc_error("deepCopy()");

      return v;
   }
}
expfun void dump(text Offset,
                 variable_name v,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (v == NULL)
   {
      if (showEmpty)
      {
         fprintf(fp, "%s{\n", Offset);
         fprintf(fp, "%sNULL\n", new_Offset);
         fprintf(fp, "%s}\n", Offset);
      }
   }
   else
   {
      fprintf(fp, "%s{\n", Offset);

      if (hasName(v) || showEmpty)
      {
         fprintf(fp, "%svname name,\n", new_Offset);
         dump(new_Offset, v->name, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasExpr(v) || showEmpty)
      {
         fprintf(fp, "%sexpression expr,\n", new_Offset);
         dump(new_Offset, v->expr, fp, showEmpty);
         fprintf(fp, "%s\\end expression\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(variable_name v,
                 size_t level = 0)
{
   if (v ne NULL)
   {
      if (level > 0)
      {

         Free(v->name, level - 1);
         v->name = NULL;

         Free(v->expr, level - 1);
         v->expr = NULL;
      }


      free((void *) v);
   }
}
expfun void deepFree(variable_name v)
{
   if (v ne NULL)
   {

      deepFree(v->name);
      v->name = NULL;

      deepFree(v->expr);
      v->expr = NULL;

      free((void *) v);
   }
}
