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

#define file_cc

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "Constants.h"


expfun text getBasename(text filename)
{
   static char base[200];
   ssize_t i;
   strcpy(base, filename);
   i = (ssize_t) strlen(base) - 1;
   while(i >= 0)
   {
      if (base[i] eq '/')
         return base + i + 1;
      i = i - 1;
   }
   return base;
}
expfun text stripSuffix(text filename)
{
   static char core[200];
   ssize_t i;
   strcpy(core, getBasename(filename));
   i = (ssize_t) strlen(core) - 1;
   while(i >= 0)
   {
      if (core[i] eq '.')
         core[i] = '\0';
      i = i - 1;
   }
   return core;
}
expfun FILE * openR(text filename,
                    bool Warn = true)
{
   FILE *fi = fopen(filename, "r");
   if ((fi == NULL) && Warn)
      fprintf(getErrorStream(), "\n** WARNING : couldn't open '%s', (ignored) ...\n", filename);

   return fi;
}
expfun bool existsFile(text filename)
{
   FILE *fp = openR(filename, false);
   if (fp != NULL)
   {
      fclose(fp);
      return true;
   }
   else
      return false;
}
expfun FILE * openW(text filename,
                    bool Backup = false)
{
   size_t index;
   char moveName[STRING_SIZE];
   FILE *fo;
   if (existsFile(filename) &&
       Backup)
   {
      sprintf(moveName, "%s.tmp", filename);
      index = 1;
      while(existsFile(moveName))
      {
         sprintf(moveName, "%s.tmp%zu", filename, index);
         index = index + 1;
      }

      fprintf(getLogStream(), "\n- existing file '%s' has been moved to '%s',", filename, moveName);
      rename(filename, moveName);
   }

   fo = fopen(filename, "w");
   if (fo != NULL)
      fprintf(getLogStream(), "\n- generating '%s'\n", filename);
   else
   {
      fprintf(getErrorStream(), "\n- couldn't open '%s', using stdout...\n", filename);
      fo = stdout;
   }

   return fo;
}
expfun FILE * openA(text filename)
{
   FILE *fo = fopen(filename, "a");
   if (fo != NULL)
      fprintf(getLogStream(), "\n- appending to '%s'\n", filename);
   else
   {
      fprintf(getErrorStream(), "\n- couldn't open '%s', using stdout...\n", filename);
      fo = stdout;
   }

   return fo;
}
expfun bool isOpen(FILE* fp)
{
   if ((fp != NULL) &&
       (fp != stdout) &&
       (fp != stderr))
      return true;
   else
      return false;
}
expfun void Close(FILE* fp)
{
   if (isOpen(fp))
      fclose(fp);
}
expfun unsigned long getFileSize(text filename)
{
   struct stat s;
   if (stat(filename, &s) == 0)
      return (unsigned long) s.st_size;
   else
      return 0;
}
