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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"
#include "error.h"
#include "command.h"
#include "Usage.h"
#include "Driver.h"
#include "translation_unit.h"

int main(int argc,
         char** argv)
{
   translation_unit t;
   bool debug;
   nameset filenames;

   filenames = getArgs(argv[0], argc, argv);
   if (filenames eq NULL)
   {
      if (argc > 1)
         runDriver(argc, argv);
      else
      {
         beep(1);
         Usage(argc, argv);
         exit(1);
      }
   }
   else
   {
      t = parseTranslation_unit(filenames);

      debug = inArgList("-d", argc, argv);
      if (debug eq true)
      {
         fprintf(stdout, "translation_unit t,\n");
         dump("", t, stdout, inArgList("-showEmpty", argc, argv));
      }

      runDriver(t, argc, argv);

      /*************** CODE FROM APPEND SECTION *************/

      /*************** END APPEND SECTION *************/
   }

   exit(0);
}
