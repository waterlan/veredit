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
#include <stdlib.h>

#include "structures.h"
#include "std_macro.h"
#include "string.h"

#include "version.h"
#include "vname.h"
#include "translation_unit.h"
#include "module_list.h"
#include "module.h"
#include "module_item.h"
#include "module_item_list.h"
#include "verilog_item.h"
#include "verilog_item_list.h"

#include "text.h"
#include "nameset.h"
#include "file.h"
#include "search.h"
#include "write5Set.h"
#include "TranslationUnit.h"
#include "Nameset.h"
#include "Module.h"




static void write5(text separator, size_t tabs, module m, translation_unit t, nameset instmodules, FILE *fp)
{
   extern bool eqInMatch(text a, text b);
	
	if (Index(getN(getName(m)), instmodules, eqInMatch) != -1)
	{
		getHierInstNames(m,t,fp);
	}
}

static void write5(text separator, size_t tabs, verilog_item i, translation_unit t, nameset instmodules, FILE *fp)
{
	if (hasBlock(i) eq true)
	{
		write5(separator, tabs, getBlock(i), t, instmodules, fp);
	}
}

expfun void writeInst(translation_unit t, nameset instmodules, text outfile)
{
   if (hasItems(t) eq true)
   {
      FILE *fo = openW(outfile);
      
		write5Set("", "", (size_t)0, getItems(t), t, instmodules, fo);
      Close(fo);
   }
   else
      fprintf(stdout, "veredit: WARNING: No module definitions found.\n");
} 
