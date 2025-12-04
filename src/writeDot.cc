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
#include <string.h>

#include "structures.h"
#include "std_macro.h"

#include "vname.h"
#include "translation_unit.h"
#include "module.h"
#include "module_list.h"
#include "verilog_item.h"
#include "verilog_item_list.h"
#include "instance.h"
#include "instantiation_list.h"
#include "dot.h"
#include "dot_list.h"

#include "text.h"
#include "search.h"
#include "file.h"
#include "write2Set.h"

#include "Instance.h"
#include "Module.h"

static bool skip(instance i, translation_unit t, bool leafCells, unsigned int instLength)
{
   if ((leafCells eq false) and (isUndeclaredCell(i, t) eq true))
      return true;
   else if (strlen(getN(getInstName(i))) < (unsigned) instLength)
      return true;
   else
      return false;
}


bool eqChild(dot d, dot d2)
{
   return Eq(getChild(d),getChild(d2)) ;
}


void write2(text separator, size_t tabs, dot d, FILE *fp)
{ 
  int i;
  
   fprintf(fp, "%s%s", separator, Tab(tabs)); 

   if ( (i = getTimes(d)) > 1)
     fprintf(fp,"%s -> %s   [label= \"%dx \"];\n",getParent(d),getChild(d),i);
   else
     fprintf(fp,"%s -> %s\n",getParent(d),getChild(d));
}

ssize_t In(dot dt, dot_list l)
{
	extern bool eqChild(dot d, dot d2);
	return Index(dt,l,eqChild);
}

static void write2(text separator, size_t tabs, instance i, translation_unit t, bool leafCells, unsigned int instLength, text n, dot_list dl,FILE *fp)
{
   dot dt;
   ssize_t number;
   int nr ;
   
   fprintf(fp, "%s%s", separator, Tab(tabs)); 

   if (skip(i, t, leafCells, instLength) eq false)
   {
      dt = dotNew(n,getN(getCellName(i)));
	  
	  if ( (number = In(dt,dl)) < 0 )
	  {
	      setTimes(1,dt);
	  	  add(dt,dl);
	  }
	  else
	  {
	     nr = getTimes(elementAt(number,dl)) ;
		 nr++ ;
		 setTimes(nr,elementAt(number,dl)) ;
	  }
   }
}

static void write2(text separator, size_t tabs, module m, translation_unit t, bool leafCells, unsigned int instLength, FILE *fp)
{
   dot_list  d;

   fprintf(fp, "%s%s", separator, Tab(tabs)); 

   if (hasInstances(m) eq true)
   {
	  d = dot_listNew();
	  write2Set("", "", 0, getInstances(m), t, leafCells, instLength, getN(getName(m)),d, fp);
	  write2Set("", "", 0, d, fp);
   }
}

static void write2(text separator, size_t tabs, verilog_item i, translation_unit t, bool leafCells, unsigned int instLength, FILE *fp)
{
	if (hasBlock(i) eq true)
	{
		write2(separator, tabs, getBlock(i), t, leafCells, instLength, fp);
	}
}

expfun void writeDot(translation_unit t, bool leafCells, unsigned int instLength, text outfile)
{
   if (hasItems(t) eq true)
   {
      
	  FILE *fo = openW(outfile);

      fprintf(fo, "DIGRAPH VERILOG{\n");
      fprintf(fo, "rankdir=LR;\n");
      write2Set("", "", 0, getItems(t), t, leafCells, instLength, fo);
      fprintf(fo, "}\n");


      Close(fo);
   }
   else
      fprintf(stdout, "WARNING: No module definitions found.\n");
} 
