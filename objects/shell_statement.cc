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

#define shell_statement_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "shell_statement.h"


expfun shell_statement shell_statementNew(vname shellName = NULL)
{
   shell_statement s = (shell_statement) malloc (sizeof(shell_statement_struct));
   if (s != NULL)
      s->shellName = shellName;
   else
      malloc_error("shell_statementNew()");

   return s;
}
expfun bool eqSelfShellName(vname shellName,
                            shell_statement s)
{
   if ((shellName == NULL) || (hasShellName(s) == false))
      return false;
   else if (eqSelf(shellName, getShellName(s)))
      return true;
   else
      return false;
}
expfun bool eqShellName(vname shellName,
                        shell_statement s)
{
   if ((shellName == NULL) || (hasShellName(s) == false))
      return false;
   else if (Eq(shellName, getShellName(s)))
      return true;
   else
      return false;
}
expfun bool eqSelf(shell_statement a,
                   shell_statement b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(shell_statement a,
               shell_statement b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqShellName(getShellName(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getShellName(shell_statement s)
{
   if (s != NULL)
      return s->shellName;
   else
      return NULL;
}
expfun shell_statement setShellName(vname shellName,
                                    shell_statement s)
{
   if (s != NULL)
      s->shellName = shellName;
   return s;
}
expfun bool hasShellName(shell_statement s)
{
   if (getShellName(s) != NULL)
      return true;
   else
      return false;
}
expfun shell_statement copy(shell_statement src,
                            size_t level = 0)
{
   shell_statement s;

   if (src == NULL)
      return NULL;
   else
   {
      s = (shell_statement) malloc (sizeof(shell_statement_struct));
      if (s != NULL)
      {
         if (level > 0)
            s->shellName = copy(src->shellName, level - 1);
         else
            s->shellName = src->shellName;
      }
      else
         malloc_error("copy()");

      return s;
   }
}
expfun shell_statement deepCopy(shell_statement src)
{
   shell_statement s;

   if (src == NULL)
      return NULL;
   else
   {
      s = (shell_statement) malloc (sizeof(shell_statement_struct));
      if (s != NULL)
      {
         s->shellName = deepCopy(src->shellName);
      }
      else
         malloc_error("deepCopy()");

      return s;
   }
}
expfun void dump(text Offset,
                 shell_statement s,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (s == NULL)
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

      if (hasShellName(s) || showEmpty)
      {
         fprintf(fp, "%svname shellName,\n", new_Offset);
         dump(new_Offset, s->shellName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(shell_statement s,
                 size_t level = 0)
{
   if (s ne NULL)
   {
      if (level > 0)
      {

         Free(s->shellName, level - 1);
         s->shellName = NULL;
      }


      free((void *) s);
   }
}
expfun void deepFree(shell_statement s)
{
   if (s ne NULL)
   {

      deepFree(s->shellName);
      s->shellName = NULL;

      free((void *) s);
   }
}
