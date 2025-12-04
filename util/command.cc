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

#define command_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "file.h"
#include "text.h"
#include "nameset.h"


expfun bool inArgList(text name,
                      int argc,
                      char** argv)
{
   text arg;
   int index = 1;
   while(index < argc)
   {
      arg = argv[index];
      if (Eq(name, arg)) 
         return true;

      index = index + 1;
   }
   return false;
}
expfun text getArg(text name,
                   int argc,
                   char** argv)
{
   int index = 1;
   text arg = NULL;
   text current_arg;
   bool found = false;
   while(index < argc)
   {
      current_arg = argv[index];
      if (Eq(name, current_arg))
      {
         found = true;
         break;
      }

      index = index + 1;
   }

   if (found)
   {
      index = index + 1;
      if (index < argc)
      {
         current_arg = argv[index];
         if (*current_arg ne '-')
            arg = current_arg;
      }
   }

   return arg;
}
expfun nameset getArgs(text name,
                       int argc,
                       char** argv)
{
   int index = 0;
   text arg;
   nameset args = namesetNew();
   bool found = false;
   while(index < argc)
   {
      arg = argv[index];
      if (Eq(name, arg))
      {
         index = index + 1;
         if (index < argc)
            found = true;
      }

      if (found &&
          (index < argc))
      {
         arg = argv[index];
         if (*arg eq '-')
            found = false;
         else
            add(arg, args);
      }

      index = index + 1;
   }

   if (isEmpty(args))
   {
      free((void *) args);
      args = NULL;
   }

   return args;
}

expfun bool isInt(text t)
{
   size_t index = 0;
   bool is_int = true;
   while(index < strlen(t))
   {
      if (isdigit((int) t[index]) ne 0)
         index = index + 1;
      else if ((index eq 0) and (t[0] eq '-'))
         index = index + 1;
      else
      {
         is_int = false;
         break;
      }
   }
   return is_int;
}

expfun bool isFloat(text t)
{
   size_t index = 0;
   bool digits = true;
   bool found_point = false;

   while(index < strlen(t))
   {
      if (isdigit((int) t[index]) ne 0) 
         index = index + 1;
      else if (t[index] eq '.')
      {
         index = index + 1;
         found_point = true;
      }
      else
      {
         digits = false;
         break;
      }
   }

   if (found_point)
   {
      if (digits)
         return true;
      else
         return false;
   }
   else
      return false;
}
expfun void dumpCommandline(text file,
                            size_t argc,
                            char** argv)
{
   FILE *fp = openA(file);
   size_t index = 0;

   if (fp != NULL)
   {
      while(index < argc)
      {
         if (index > 0)
            fprintf(fp, " ");

         fprintf(fp, "%s", argv[index]);

         index = index + 1;
      }
      fprintf(fp, "\n");
      Close(fp);
   }
}
