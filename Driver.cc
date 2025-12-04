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
#include <strings.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"
#include "command.h"
#include "text.h"
#include "error.h"
#include "Usage.h"

#include "nameset.h"
#include "module.h"
#include "translation_unit.h"

#include "TranslationUnit.h"
#include "writeInitialEdits.h"
#include "writeVerilog.h"
#include "writeDot.h"
#include "doEdits.h"
#include "Vnode.h"

#include "writeInstallFile.h"
#include "writeIfspec.h"
#include "writeEdtLib.h"
#include "writeInst.h"
#include "hierarchy.h"

#include "veredit.h"

/* Global variables */
char veredit_mode = VEREDIT_NORMAL ;
static text LicenseText = "\
\n\
Copyright (C) 1999-2025  Erwin Waterlander\n\
Copyright (C) 1999       Ondrej Popp\n\
All rights reserved.\n\
\n\
Redistribution and use in source and binary forms, with or without\n\
modification, are permitted provided that the following conditions\n\
are met:\n\
\n\
1. Redistributions of source code must retain the above copyright\n\
   notice, this list of conditions and the following disclaimer.\n\
2. Redistributions in binary form must reproduce the above copyright\n\
   notice in the documentation and/or other materials provided with\n\
   the distribution.\n\
\n\
THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY\n\
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE\n\
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n\
PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE\n\
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR\n\
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT\n\
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR\n\
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,\n\
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE\n\
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN\n\
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";


expfun void runDriver(int argc,
                      char** argv)
{
   if( inArgList("-L", argc, argv) eq true )
   {
      fprintf(stdout, "%s\n",LicenseText);
   } else {
      Usage(argc, argv);
   }
}
expfun void runDriver(translation_unit t,
                      int argc,
                      char** argv)
{
   text outfile = getArg("-o", argc, argv);

   nameset filenames = getArgs(argv[0], argc, argv);
   nameset clkNames  = getArgs("-clk", argc, argv);
   text    filename;
   unsigned instLength = 0;
   nameset edtmodules = getArgs("-edt", argc, argv);
   nameset installmodules = getArgs("-install", argc, argv);
   nameset ifspecmodules = getArgs("-ifspec", argc, argv);
   nameset instmodules = getArgs("-inst", argc, argv);
   
   if (isEmpty(filenames) eq false)
      filename = filenames->array[0];
   else
      filename = getTranslation_unitCurrentParseItem();
   
   /* there are no features yet in veredit that require the hierarchy tree to be in place
      during edit */
   /* buildHierarchy(t); */

   if ( inArgList("-expand", argc, argv) eq true )
   {
       veredit_mode |= VEREDIT_EXPAND;
   }

   if ( inArgList("-writeDot", argc, argv) eq true )
   {
      if (outfile eq NULL)
         outfile = concat(filename, ".dot");

      text arg = getArg("-instLength", argc, argv);
      if (arg ne NULL)
      {
         if (isInt(arg) eq true) 
            instLength = (unsigned) atoi(arg);
         else
            fprintf(stdout, "Warning : -instLength should be an integer, '%s' detected and rejected\n", arg);
      }   

      writeDot(t, inArgList("-leafCells", argc, argv), instLength, outfile);
   }

   if ( inArgList("-writeEdits", argc, argv) eq true)
   {
      if (outfile eq NULL)
         outfile = concat(filename, ".edt");

      text arg = getArg("-instLength", argc, argv);
      if (arg ne NULL)
      {
         if (isInt(arg) eq true) 
            instLength = (unsigned) atoi(arg);
         else
            fprintf(stdout, "Warning : -instLength should be an integer, '%s' detected and rejected\n", arg);
      }   

      writeInitialEdits(t, inArgList("-leafCells", argc, argv), instLength, outfile);
   }

   if( (hasEdits(t) eq true)
     ||(inArgList("-ver", argc, argv) eq true )
     )
   {
      if (Check(t) eq true)
      {
         if (outfile eq NULL)
            outfile = concat(filename, ".new");

       doEdits(t);
       if (inArgList("-top", argc, argv) eq true)
       {
          buildHierarchy(t);
          text name = getArg("-top", argc, argv);
          module m = getModule(name, t);
          if (m == NULL)
          {
             fprintf(stdout," Veredit: ERROR: Module %s not found.\n", name);
             return;
          }
          writeVerilog(t, getModNode(m), outfile);
       }
       else
          writeVerilog(t, outfile);
      }
   }

 /*  if( inArgList("-hier", argc, argv) eq true )
   {
      print(t->rootNode);
   } */
   if( inArgList("-install", argc, argv) eq true )
   {
      if (Check(t) eq true)
      {
         if (outfile eq NULL)
            outfile = concat(filename, ".install");

         if (installmodules == NULL)
         {
            installmodules = namesetNew();
            add(textNew("*"), installmodules);
         }

       writeInstallFile(t, installmodules, outfile);
      }
   }

   if( inArgList("-ifspec", argc, argv) eq true )
   {
      if (Check(t) eq true)
      {
         if (outfile eq NULL)
            outfile = concat(filename, ".ifspec");

         if (ifspecmodules == NULL)
         {
            ifspecmodules = namesetNew();
            add(textNew("*"), ifspecmodules);
         }

       writeIfspec(t, ifspecmodules, clkNames, outfile);
      }
   }
   if( inArgList("-edt", argc, argv) eq true )
   {
      if (Check(t) eq true)
      {
         if (outfile eq NULL)
            outfile = concat(filename, ".edt_lib");

         if (edtmodules == NULL)
         {
            edtmodules = namesetNew();
            add(textNew("*"), edtmodules);
         }

       writeEdtLib(t, edtmodules, outfile);
      }
   }
   if( inArgList("-inst", argc, argv) eq true )
   {
      if (Check(t) eq true)
      {
         if (outfile eq NULL)
            outfile = concat(filename, ".inst");

         if (instmodules == NULL)
         {
            instmodules = namesetNew();
            add(textNew("*"), instmodules);
         }

       writeInst(t, instmodules, outfile);
      }
   }
   if( inArgList("-hier", argc, argv) eq true )
   {
      buildHierarchy(t);
      if (outfile eq NULL)
         outfile = concat(filename, ".hier");


      writeTree (getRootNode(t), outfile);
   }
}

