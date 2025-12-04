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
#include "text.h"
#include "version.h"

expfun void Usage(int argc,
                  char** argv)
{

   text progname = argv[0];

   fprintf(stdout, "%s %s  (%s)\n",progname,VEREDIT_VERSION,VEREDIT_DATE);
   fprintf(stdout, " I am made by C3PO, Ondrej Popp and Erwin Waterlander\n");
   fprintf(stdout, " Veredit : https://github.com/waterlan/veredit\n");
   fprintf(stdout, " C3PO    : https://sourceforge.net/projects/c3po\n\n");
   fprintf(stdout, "usage : %s <verilog file(s)> [<editfile>] [options]\n", progname);
   fprintf(stdout,"\nOptions:\n");
	fprintf(stdout,"  -writeEdits                : generate default editfile.\n");
	fprintf(stdout,"    [-leafCells]             : include leaf cells.\n");
	fprintf(stdout,"    [-instLength #]          : only include cells with instantiation names longer than #.\n");
	fprintf(stdout,"  -writeDot                  : generate Dotty hierarchy file.\n");
	fprintf(stdout,"    [-leafCells]             : include leaf cells.\n");
	fprintf(stdout,"    [-instLength #]          : only include cells with instantiation names longer than #.\n");
	fprintf(stdout,"  -install [MODULE-LIST]     : write MPC install file.\n");
	fprintf(stdout,"  -ifspec [MODULE-LIST]      : write GenTB ifspec file.\n");
	fprintf(stdout,"    [-clk CLOCK-LIST]        : space separated list of clock names.\n");
	fprintf(stdout,"  -inst [MODULE-LIST]        : write hierarchical instance names of modules.\n");
	fprintf(stdout,"  -edt [MODULE-LIST]         : write ED&T library.\n");
	fprintf(stdout,"  -hier                      : write module hierarchy.\n");
	fprintf(stdout,"  -ver                       : write Verilog file.\n");
	fprintf(stdout,"  -top MODULE-NAME           : set top module name.\n");
	fprintf(stdout,"  -expand                    : expand port and net declarations, delete single net declarations.\n");
	fprintf(stdout,"  -o <outfile>               : set outfile name.\n");
	fprintf(stdout,"  -L                         : display software license.\n");
}
