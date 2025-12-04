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

#define listInst_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "simple_signal.h"
#include "listInst_statement.h"


expfun listInst_statement listInst_statementNew(simple_signal Net = NULL)
{
   listInst_statement l = (listInst_statement) malloc (sizeof(listInst_statement_struct));
   if (l != NULL)
      l->Net = Net;
   else
      malloc_error("listInst_statementNew()");

   return l;
}
expfun bool eqSelfNet(simple_signal Net,
                      listInst_statement l)
{
   if ((Net == NULL) || (hasNet(l) == false))
      return false;
   else if (eqSelf(Net, getNet(l)))
      return true;
   else
      return false;
}
expfun bool eqNet(simple_signal Net,
                  listInst_statement l)
{
   if ((Net == NULL) || (hasNet(l) == false))
      return false;
   else if (Eq(Net, getNet(l)))
      return true;
   else
      return false;
}
expfun bool eqSelf(listInst_statement a,
                   listInst_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(listInst_statement a,
               listInst_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqNet(getNet(a), b) == false)
      return false;
   else
      return true;
}
expfun simple_signal getNet(listInst_statement l)
{
   if (l != NULL)
      return l->Net;
   else
      return NULL;
}
expfun listInst_statement setNet(simple_signal Net,
                                 listInst_statement l)
{
   if (l != NULL)
      l->Net = Net;
   return l;
}
expfun bool hasNet(listInst_statement l)
{
   if (getNet(l) != NULL)
      return true;
   else
      return false;
}
expfun listInst_statement copy(listInst_statement src,
                               size_t level = 0)
{
   listInst_statement l;

   if (src == NULL)
      return NULL;
   else
   {
      l = (listInst_statement) malloc (sizeof(listInst_statement_struct));
      if (l != NULL)
      {
         if (level > 0)
            l->Net = copy(src->Net, level - 1);
         else
            l->Net = src->Net;
      }
      else
         malloc_error("copy()");

      return l;
   }
}
expfun listInst_statement deepCopy(listInst_statement src)
{
   listInst_statement l;

   if (src == NULL)
      return NULL;
   else
   {
      l = (listInst_statement) malloc (sizeof(listInst_statement_struct));
      if (l != NULL)
      {
         l->Net = deepCopy(src->Net);
      }
      else
         malloc_error("deepCopy()");

      return l;
   }
}
expfun void dump(text Offset,
                 listInst_statement l,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (l == NULL)
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

      if (hasNet(l) || showEmpty)
      {
         fprintf(fp, "%ssimple_signal Net,\n", new_Offset);
         dump(new_Offset, l->Net, fp, showEmpty);
         fprintf(fp, "%s\\end simple_signal\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(listInst_statement l,
                 size_t level = 0)
{
   if (l ne NULL)
   {
      if (level > 0)
      {

         Free(l->Net, level - 1);
         l->Net = NULL;
      }


      free((void *) l);
   }
}
expfun void deepFree(listInst_statement l)
{
   if (l ne NULL)
   {

      deepFree(l->Net);
      l->Net = NULL;

      free((void *) l);
   }
}
