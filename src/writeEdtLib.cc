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

#include <fnmatch.h>

#include "structures.h"
#include "std_macro.h"
#include "string.h"

#include "version.h"
#include "vname.h"
#include "translation_unit.h"
#include "module_list.h"
#include "module.h"
#include "port_list.h"
#include "port.h"
#include "portmap.h"
#include "portmap_element.h"
#include "simple_signal.h"
#include "signal_list.h"
#include "Signal.h"
#include "signal_type.h"
#include "variable_list.h"
#include "variable_name.h"
#include "expression.h"
#include "continuous_assign.h"
#include "declaration.h"
#include "module_item.h"
#include "module_item_list.h"
#include "verilog_item.h"
#include "verilog_item_list.h"
#include "instantiation_list.h"
#include "instance.h"
#include "range.h"

#include "text.h"
#include "nameset.h"
#include "file.h"
#include "search.h"
#include "write3Set.h"
#include "TranslationUnit.h"
#include "Instance.h"
#include "Nameset.h"


static void write3(text separator, size_t tabs, signal_type type, FILE *fp)
{
   fprintf(fp, "%s%s", separator, Tab(tabs));
   switch(type)
   {
      case _INPUT   : fprintf(fp, "Input ");   break;
      case _OUTPUT  : fprintf(fp, "Output");  break;
      case _INOUT   : fprintf(fp, "InOut ");   break;
      case _WIRE    : fprintf(fp, "wire ");    break;
      case _SUPPLY0 : fprintf(fp, "supply0"); break;
      case _SUPPLY1 : fprintf(fp, "supply1"); break;

      default      : break; // should not happen
   }
}

static void writefan(text separator, size_t tabs, signal_type type, FILE *fp)
{
   fprintf(fp, "%s%s", separator, Tab(tabs));
   switch(type)
   {
      case _INPUT   : fprintf(fp, "fanin = 1.0;");   break;
      case _OUTPUT  : fprintf(fp, "fanout = 0.015;");  break;
      case _INOUT   : fprintf(fp, "fanin = 1.0; fanout = 0.015;");   break;
      case _WIRE    : fprintf(fp, "wire ");    break;
      case _SUPPLY0 : fprintf(fp, "supply0"); break;
      case _SUPPLY1 : fprintf(fp, "supply1"); break;

      default      : break; // should not happen
   }
}
static void write3(text separator, size_t tabs, variable_name s, signal_type t, range r, FILE *fp)
{
	text name;
	int i, begin, end ;
	int done = 0;
	int step;
	
	name = getN(getName(s));

	if ( r != NULL)
	{
	   begin = getBegin(r);
		end = getEnd(r);
		i = begin;
		if (begin < end)
		   step = 1;
		else
		   step = -1;

		while (done == 0)
		{
		   
			write3(separator, 0, t, fp);
			fprintf(fp, " %s[%d] { ", name, i);
			fprintf(fp, "_ndsArray = \"%s\" ", name);
			fprintf(fp, "{ %d; %d; %d; } ", begin, end, i);
			writefan("" , 0, t, fp);
			fprintf(fp, " }\n");
			
			if (i == end)
			   done = 1;
			i = i + step;
		}
	}
	else
	{

	write3(separator, 0, t, fp);

	fprintf(fp, " %s { ", name);
	writefan("" , 0, t, fp);
	fprintf(fp, " }\n");

	}
}

static void write3(text separator, size_t tabs, declaration d, FILE *fp)
{
   signal_type t;
	range r;

	t = getType(d);
	if ((isINPUT(t)  eq true) ||
	    (isOUTPUT(t) eq true) ||
		 (isINOUT(t)  eq true))
	{
		r = getRnge(d);

		write3Set("  ", "  ", tabs, getSignals(d), t, r, fp);
	}
}

static void write3(text separator, size_t tabs, module_item i, FILE *fp)
{
	if (hasDeclItem(i) eq true)
	  write3(separator, tabs, getDeclItem(i), fp);
}

static void write3(text separator, size_t tabs, module m, nameset edtmodules, FILE *fp)
{
   extern bool eqInMatch(text a, text b);
	
	if (Index(getN(getName(m)), edtmodules, eqInMatch) != -1)
	{
		fprintf(fp, "%s%sCell %s {\n", separator, Tab(tabs), getN(getName(m)));
		
		write3Set("", "", tabs , getItems(m), fp);

		fprintf(fp, "\n  Property { area = 1.0; }\n");
		fprintf(fp, "}\n\n");
	}
}

static void write3(text separator, size_t tabs, verilog_item i, nameset edtmodules, FILE *fp)
{
	if (hasBlock(i) eq true)
	{
		write3(separator, tabs, getBlock(i), edtmodules, fp);
	}
}

expfun void writeEdtLib(translation_unit t, nameset edtmodules, text outfile)
{
   if (hasItems(t) eq true)
   {
      FILE *fo = openW(outfile);
      
      fprintf(fo, "Library veredit {\n");
      fprintf(fo, "  Property {\n");
      fprintf(fo, "    date = \"tomorrow\";\n");
      fprintf(fo, "    version = \"veredit %s\";\n", VEREDIT_VERSION);
      fprintf(fo, "    vendor = \"veredit %s\";\n", VEREDIT_VERSION);
      fprintf(fo, "    origin = \"veredit %s\";\n", VEREDIT_VERSION);
      fprintf(fo, "    source = \"veredit %s\";\n", VEREDIT_VERSION);
      fprintf(fo, "    process = \"CMOS12\";\n");
      fprintf(fo, "    voltage = \"1.1\";\n");
      fprintf(fo, "    temperature = \"125\";\n");
      fprintf(fo, "    filename = \"%s\";\n", outfile);
      fprintf(fo, "    libnorm = \"2.2\";\n");
      fprintf(fo, "  }\n");
		// fprintf(fo,"// veredit %s\n\n",VEREDIT_VERSION);
		write3Set("", "", 0, getItems(t), edtmodules, fo);
      fprintf(fo, "}\n");
      Close(fo);
   }
   else
      fprintf(stdout, "veredit: WARNING: No module definitions found.\n");
} 
