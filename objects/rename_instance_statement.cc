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

#define rename_instance_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "rename_instance_statement.h"


expfun rename_instance_statement rename_instance_statementNew(vname oldName = NULL,
                                                              vname newName = NULL)
{
   rename_instance_statement r = (rename_instance_statement) malloc (sizeof(rename_instance_statement_struct));
   if (r != NULL)
   {
      r->oldName = oldName;
      r->newName = newName;
   }
   else
      malloc_error("rename_instance_statementNew()");

   return r;
}
expfun bool eqSelfOldName(vname oldName,
                          rename_instance_statement r)
{
   if ((oldName == NULL) || (hasOldName(r) == false))
      return false;
   else if (eqSelf(oldName, getOldName(r)))
      return true;
   else
      return false;
}
expfun bool eqOldName(vname oldName,
                      rename_instance_statement r)
{
   if ((oldName == NULL) || (hasOldName(r) == false))
      return false;
   else if (Eq(oldName, getOldName(r)))
      return true;
   else
      return false;
}
expfun bool eqSelfNewName(vname newName,
                          rename_instance_statement r)
{
   if ((newName == NULL) || (hasNewName(r) == false))
      return false;
   else if (eqSelf(newName, getNewName(r)))
      return true;
   else
      return false;
}
expfun bool eqNewName(vname newName,
                      rename_instance_statement r)
{
   if ((newName == NULL) || (hasNewName(r) == false))
      return false;
   else if (Eq(newName, getNewName(r)))
      return true;
   else
      return false;
}
expfun bool eqSelf(rename_instance_statement a,
                   rename_instance_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(rename_instance_statement a,
               rename_instance_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqOldName(getOldName(a), b) == false)
      return false;
   else if (eqNewName(getNewName(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getOldName(rename_instance_statement r)
{
   if (r != NULL)
      return r->oldName;
   else
      return NULL;
}
expfun vname getNewName(rename_instance_statement r)
{
   if (r != NULL)
      return r->newName;
   else
      return NULL;
}
expfun rename_instance_statement setOldName(vname oldName,
                                            rename_instance_statement r)
{
   if (r != NULL)
      r->oldName = oldName;
   return r;
}
expfun rename_instance_statement setNewName(vname newName,
                                            rename_instance_statement r)
{
   if (r != NULL)
      r->newName = newName;
   return r;
}
expfun bool hasOldName(rename_instance_statement r)
{
   if (getOldName(r) != NULL)
      return true;
   else
      return false;
}
expfun bool hasNewName(rename_instance_statement r)
{
   if (getNewName(r) != NULL)
      return true;
   else
      return false;
}
expfun rename_instance_statement copy(rename_instance_statement src,
                                      size_t level = 0)
{
   rename_instance_statement r;

   if (src == NULL)
      return NULL;
   else
   {
      r = (rename_instance_statement) malloc (sizeof(rename_instance_statement_struct));
      if (r != NULL)
      {
         if (level > 0)
         {
            r->oldName = copy(src->oldName, level - 1);
            r->newName = copy(src->newName, level - 1);
         }
         else
         {
            r->oldName = src->oldName;
            r->newName = src->newName;
         }
      }
      else
         malloc_error("copy()");

      return r;
   }
}
expfun rename_instance_statement deepCopy(rename_instance_statement src)
{
   rename_instance_statement r;

   if (src == NULL)
      return NULL;
   else
   {
      r = (rename_instance_statement) malloc (sizeof(rename_instance_statement_struct));
      if (r != NULL)
      {
         r->oldName = deepCopy(src->oldName);
         r->newName = deepCopy(src->newName);
      }
      else
         malloc_error("deepCopy()");

      return r;
   }
}
expfun void dump(text Offset,
                 rename_instance_statement r,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (r == NULL)
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

      if (hasOldName(r) || showEmpty)
      {
         fprintf(fp, "%svname oldName,\n", new_Offset);
         dump(new_Offset, r->oldName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasNewName(r) || showEmpty)
      {
         fprintf(fp, "%svname newName,\n", new_Offset);
         dump(new_Offset, r->newName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(rename_instance_statement r,
                 size_t level = 0)
{
   if (r ne NULL)
   {
      if (level > 0)
      {

         Free(r->oldName, level - 1);
         r->oldName = NULL;

         Free(r->newName, level - 1);
         r->newName = NULL;
      }


      free((void *) r);
   }
}
expfun void deepFree(rename_instance_statement r)
{
   if (r ne NULL)
   {

      deepFree(r->oldName);
      r->oldName = NULL;

      deepFree(r->newName);
      r->newName = NULL;

      free((void *) r);
   }
}
