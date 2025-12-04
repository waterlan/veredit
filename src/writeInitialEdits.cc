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

#include "file.h"
#include "writeSet.h"

#include "Instance.h"
#include "Module.h"

static bool skip(instance i, translation_unit t, bool leafCells, unsigned int instLength)
{
   if ((leafCells eq false) and (isLeafCell(i, t) eq true))
      return true;
   else if (strlen(getN(getInstName(i))) < (unsigned) instLength)
      return true;
   else
      return false;
}

static void write(text separator, size_t tabs, instance i, translation_unit t, bool leafCells, unsigned int instLength, FILE *fp)
{
   if (skip(i, t, leafCells, instLength) eq false)
      fprintf(fp, "%s%s-instance %s = %s // %s\n", separator, Tab(tabs), 
                  getN(getInstName(i)), getN(getInstName(i)), getN(getCellName(i)));
}

static void write(text separator, size_t tabs, module m, translation_unit t, bool leafCells, unsigned int instLength, FILE *fp)
{
   if (hasInstances(m) eq true)
   {
      fprintf(fp, "%s%sMODULE %s\n", separator, Tab(tabs), getN(getName(m)));
      fprintf(fp, "%s{\n", Tab(tabs));
      writeSet("", "", tabs+1, getInstances(m), t, leafCells, instLength, fp);
      fprintf(fp, "%s}\n\n", Tab(tabs));
   }
}

static void write(text separator, size_t tabs, verilog_item i, translation_unit t, bool leafCells, unsigned int instLength, FILE *fp)
{
	if (hasBlock(i) eq true)
	{
		write(separator, tabs, getBlock(i), t, leafCells, instLength, fp);
	}
}

expfun void writeInitialEdits(translation_unit t, bool leafCells, unsigned int instLength, text outfile)
{
   if (hasItems(t) eq true)
   {
      FILE *fo = openW(outfile);
      writeSet("", "", 0, getItems(t), t, leafCells, instLength, fo);
      Close(fo);
   }
   else
      fprintf(stdout, "veredit: WARNING: No module definitions found.\n");
} 
