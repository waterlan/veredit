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
#include "writeSet.h"
#include "TranslationUnit.h"
#include "Instance.h"

static void write(text separator, size_t tabs, range r, FILE *fp)
{
   if ( r != NULL)
   {
      fprintf(fp, "%s%s%d", separator, Tab(tabs), abs(getBegin(r)-getEnd(r))+1);
   }
   else
      fprintf(fp, "%s%s1", separator, Tab(tabs));
} 

static void write(text separator, size_t tabs, signal_type type, FILE *fp)
{
   fprintf(fp, "%s%s", separator, Tab(tabs));
   switch(type)
   {
      case _INPUT   : fprintf(fp, "IN   ");   break;
      case _OUTPUT  : fprintf(fp, "OUT  ");  break;
      case _INOUT   : fprintf(fp, "INOUT");   break;
      case _WIRE    : fprintf(fp, "wire ");    break;
      case _SUPPLY0 : fprintf(fp, "supply0"); break;
      case _SUPPLY1 : fprintf(fp, "supply1"); break;

      default      : break; // should not happen
   }
}

static void write(text separator, size_t tabs, variable_name s, signal_type t, range r, nameset clkNames, FILE *fp)
{
   extern bool Eq(text a, text b);
   text name;
   
   name = getN(getName(s));
   if (Index(name,clkNames,Eq) == -1)
   {
      write(separator, 0, t, fp);

      fprintf(fp, "\t%s", name);

      write("\t", 0, r, fp);
      fprintf(fp, "\t@0\n");
   }
}

static void write(text separator, size_t tabs, declaration d, nameset clkNames, FILE *fp)
{
   signal_type t;
   range r;

   t = getType(d);
   if ((isINPUT(t)  eq true) ||
       (isOUTPUT(t) eq true) ||
       (isINOUT(t)  eq true))
   {
      r = getRnge(d);

      writeSet("", "", tabs, getSignals(d), t, r, clkNames, fp);
   }
}

static void write(text separator, size_t tabs, module_item i, nameset clkNames, FILE *fp)
{
   if (hasDeclItem(i) eq true)
     write(separator, tabs, getDeclItem(i), clkNames, fp);
}

static void write(text separator, size_t tabs, module m, nameset ifspecmodules, nameset clkNames, FILE *fp)
{
   extern bool eqInMatch(text a, text b);
   
   if (Index(getN(getName(m)), ifspecmodules, eqInMatch) != -1)
   {
   
      fprintf(fp, "%s%sDESIGN %s\n", separator, Tab(tabs), getN(getName(m)));
      
      writeSet("", "", tabs , getItems(m), clkNames, fp);

      fprintf(fp, "\n\n");
   }
}

static void write(text separator, size_t tabs, verilog_item i, nameset ifspecmodules, nameset clkNames, FILE *fp)
{
   if (hasBlock(i) eq true)
   {
      write(separator, tabs, getBlock(i), ifspecmodules, clkNames, fp);
   }
}

expfun void writeIfspec(translation_unit t, nameset ifspecmodules, nameset clkNames, text outfile)
{
   if (hasItems(t) eq true)
   {
      FILE *fo = openW(outfile);
      
      writeSet("", "", 0, getItems(t), ifspecmodules, clkNames, fo);
      Close(fo);
   }
   else
      fprintf(stdout, "veredit: WARNING: No module definitions found.\n");
} 
