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

#include "vnode.h"

#include "nameset.h"
#include "version.h"
#include "vname.h"
#include "translation_unit.h"
#include "module_list.h"
#include "module.h"
#include "port_reference.h"
#include "port_reference_list.h"
#include "compound_port_reference.h"
#include "port_expression.h"
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
#include "assign_list.h"
#include "parameter_decl.h"
#include "parameter_decl_list.h"
#include "declaration_list.h"
#include "declaration.h"
#include "module_item.h"
#include "module_item_list.h"
#include "instantiation_list.h"
#include "instance.h"
#include "range.h"
#include "verilog_item.h"
#include "verilog_item_list.h"

#include "text.h"
#include "file.h"
#include "writeSet.h"
#include "Nameset.h"
#include "TranslationUnit.h"
#include "Instance.h"
#include "Module.h"
#include "TextFunctions.h"

#include "veredit.h"

#define MAXLINELENGTH 80

extern char veredit_mode;

static void write(text separator, size_t tabs, range r, FILE *fp)
{
   if (r != NULL)
		fprintf(fp, "%s%s[%d:%d]", separator, Tab(tabs), getBegin(r), getEnd(r));
} 

static void write(text separator, size_t tabs, simple_signal s, size_t *len, size_t *maxlen, FILE *fp)
{
   size_t extralen ;
	
	extralen = strlen(separator) + strlen(getN(getName(s)));
	
   
	if(*len == 0)
	{
		fprintf(fp, "%s%s", separator, Tab(tabs));
		*len = extralen + tabs * 3;
	}
	else
	if ((*len + extralen) > *maxlen)
	{
		if (Eq(separator,", ") eq true) 
		{
			fprintf(fp, ",\n%s", Tab(tabs));
		   *len = extralen + tabs * 3;
		}
		else
		   *len = *len + extralen + 1;
	}
	else
	{
		fprintf(fp, "%s", separator);
		*len = *len + extralen + 1;
	}
#ifdef DEBUG
   printf("DEBUG:     writing simple_signal %s\n", getName(s));
#endif

   if (hasCnst(s) eq true)
      fprintf(fp, "%d'", getCnst(s));
   fprintf(fp, "%s", getN(getName(s)));

   if (hasBusIndex(s) eq true)
	{
      *len = *len + 3;
      fprintf(fp, "[%d]", getBusIndex(s));
	}
   else if (hasRnge(s) eq true)
	{
      *len = *len + 5;
      write("", 0, getRnge(s), fp);
	}
}

static void write(text separator, size_t tabs, Signal s, size_t *len, size_t *maxlen, FILE *fp)
{
   if (hasSimple(s) eq true)
      write(separator, tabs, getSimple(s), len, maxlen, fp);
   else
   {
		fprintf(fp,"%s",separator);
      fprintf(fp, "{ ");
      writeSet("", ", ", tabs, getCmpnd(s), len, maxlen, fp);
      fprintf(fp, " }");
   }
}   

static void write(text separator, size_t tabs, portmap_element p, size_t *len, size_t *maxlen, FILE *fp)
{                       
   size_t extralen ;

#ifdef DEBUG
   printf("DEBUG:     writing portmap_element %s\n", getPinName(p));
#endif
	
	extralen = strlen(separator) + strlen(getN(getPinName(p))) + 2;
	
	if (*len == 0)
	{
		fprintf(fp, "%s%s.%s(", separator, Tab(tabs), getN(getPinName(p)));
		*len = extralen + tabs * 3;
	}
	else
	if ((*len + extralen) > *maxlen)
	{
		fprintf(fp, "%s\n%s.%s(", separator, Tab(tabs), getN(getPinName(p)));
		*len = extralen + tabs * 3;
	}
	else
	{
	   fprintf(fp, "%s .%s(", separator, getN(getPinName(p)));
		*len = *len + extralen + 1;
   }   
	writeSet("", ",", tabs, getSignals(p), len, maxlen, fp);
   
	fprintf(fp, ")");
}


static void write(text separator, size_t tabs, port_reference pr, size_t *len, size_t *maxlen, FILE *fp)
{
   size_t extralen ;
	
	extralen = strlen(separator) + strlen(getN(getName(pr)));
   
	if(*len == 0)
	{
		fprintf(fp, "%s%s", separator, Tab(tabs));
		*len = extralen + tabs * 3;
	}
	else
	if ((*len + extralen) > *maxlen)
	{
		fprintf(fp, "%s\n%s", separator, Tab(tabs));
	   *len = extralen + tabs * 3;
	}
	else
	{
		fprintf(fp, "%s ", separator);
		*len = *len + extralen + 1;
	}
#ifdef DEBUG
   printf("DEBUG:     writing port_reference %s\n", getName(pr));
#endif

   fprintf(fp, "%s", getN(getName(pr)));

   if (hasBusIndex(pr) eq true)
	{
      *len = *len + 3;
		fprintf(fp, "[%d]", getBusIndex(pr));
	}
   else if (hasRnge(pr) eq true)
	{
      *len = *len + 5;
      write("", 0, getRnge(pr), fp);
	}
}


static void write(text separator, size_t tabs, compound_port_reference cpr, size_t *len, size_t *maxlen, FILE *fp)
{
   fprintf(fp, "{");
	*len = *len + 2;
      writeSet("", ",", tabs, getPortReferences(cpr), len, maxlen, fp);
   fprintf(fp, " }");
	*len = *len + 2;
}

static void write(text separator, size_t tabs, port_expression pe, size_t *len, size_t *maxlen, FILE *fp)
{

#ifdef DEBUG
	printf("DEBUG:     writing port expression %s\n", getSimpleName(p));
#endif

	if (hasPortReference(pe) eq true)
		write(separator,tabs,getPortReference(pe),len,maxlen,fp);
	
	if (hasCmpnd(pe) eq true)
      write(separator, tabs, getCmpnd(pe), len, maxlen, fp);

		

}
static void write(text separator, size_t tabs, port p, size_t *len, size_t *maxlen, FILE *fp)
{
   size_t extralen ;

	if (hasPortExpression(p) eq true)
	{
		write(separator,tabs,getPortExpression(p),len,maxlen,fp);
	}

	if (hasPortName(p) eq true)
	{
		fprintf(fp, "%s .%s(",separator, getN(getPortName(p)));
		extralen = strlen(getN(getPortName(p))) ;
		*len = *len + extralen + 2 ;

		if (hasPortExpression2(p) eq true)
		   write(separator,tabs,getPortExpression2(p),len,maxlen,fp);
		fprintf(fp, ")");
	}

}

static void write(text separator, size_t tabs, expression e, size_t *len, size_t *maxlen, FILE *fp)
{
	if (getNumber(e) != -1)
		fprintf(fp,"%d",getNumber(e));
	else
	{
		if (hasSignal(e) eq true)
			write("", tabs, getSignal(e), len, maxlen, fp);
		else
			if (hasString(e) eq true)
				fprintf(fp, "%s",getString(e));
	}
}

static void write(text separator, size_t tabs, variable_name s, size_t *len, size_t *maxlen, FILE *fp)
{
   size_t extralen ;
	
	extralen = strlen(getN(getName(s))) ;
	
	if ((*len + extralen) > *maxlen)
	{
		fprintf(fp, "%s\n%s", separator, Tab(tabs+1));
		*len = extralen + (tabs+1) * 3;
	}
	else
	{
   	fprintf(fp, "%s", separator);
		*len = *len + extralen + strlen(separator) ;
	}
	
   fprintf(fp, "%s", getN(getName(s)));

   if (hasExpr(s) eq true)
	{
		fprintf(fp, " = ");
		write("",0, getExpr(s), len, maxlen, fp);
	}
}

static void write(text separator, size_t tabs, signal_type type, FILE *fp)
{
   fprintf(fp, "%s%s", separator, Tab(tabs));
   fprintf(fp, "%s", toString(type));
}

/*****************************************************************************/
static void write(text separator, size_t tabs, variable_name s, signal_type t, range r, FILE *fp)
{

   if ( r != NULL)
   {
      write(separator, tabs, t, fp);
      fprintf(fp, " ");
      write("", 0, r, fp);
      fprintf(fp, " %s;\n", getN(getName(s)));
   }
	else if ( t != _WIRE ) /* delete single net declarations */
	{
      write(separator, tabs, t, fp);
      fprintf(fp, " %s;\n", getN(getName(s)));
	}
   
}


static void write(text separator, size_t tabs, declaration d, size_t *len, size_t *maxlen, FILE *fp)
{
   signal_type t;
   range r;

   t = getType(d);
   r = getRnge(d);

   if (veredit_mode & VEREDIT_EXPAND)
   {
      writeSet("", "", tabs, getSignals(d), t, r, fp);
   }
   else
   {
      *len = strlen(toString(t)) + 1;
      
      write(separator, tabs, t, fp);

      if (hasRnge(d) eq true)
      {
         fprintf(fp, " ");
         write("", 0, r, fp);
      }

      writeSet(" ", ", ", tabs, getSignals(d), len, maxlen, fp);
      fprintf(fp, ";\n");
   }
}

/*****************************************************************************/

static void write(text separator, size_t tabs, continuous_assign a, FILE *fp)
{
   size_t len = 0;
	size_t maxlen = (size_t)MAXLINELENGTH;
	
	fprintf(fp, "%sassign",Tab(tabs));
	write(separator, (size_t)0, getSignal(a), &len, &maxlen, fp);
	fprintf(fp, " = ");
	write(separator, (size_t)0, getExpr(a), &len, &maxlen, fp);
	fprintf(fp, " ;\n");
}

static void write(text separator, size_t tabs, parameter_decl a, FILE *fp)
{
   size_t len = 0;
	size_t maxlen = (size_t)MAXLINELENGTH;
	
	fprintf(fp, "%sparameter",Tab(tabs));
	write(separator, (size_t)0, getSignal(a), &len, &maxlen, fp);
	fprintf(fp, " = ");
	write(separator, (size_t)0, getExpr(a), &len, &maxlen, fp);
	fprintf(fp, " ;\n");
}

/*****************************************************************************/

static void write(text separator, size_t tabs, instance i, module_edit e, size_t *len, size_t *maxlen, FILE *fp)
{
   *len = strlen(separator) + tabs * 3 + strlen(getN(getCellName(i))) + strlen(getInstName(i, e)) +3;
	
	fprintf(fp, "%s%s%s %s", separator, Tab(tabs), getN(getCellName(i)), getInstName(i, e));
   if (hasConnections(i) eq true)
   {
      fprintf(fp, " (");
      writeSet("", ",", tabs + 1, getConnections(i), len, maxlen, fp);
      fprintf(fp, ");\n");
   }
   else
   if (hasConnections_by_order(i) eq true)
   {
      fprintf(fp, " (");
      writeSet("", ", ", tabs + 1, getConnections_by_order(i), len, maxlen, fp);
      fprintf(fp, ");\n");
   }
   else
      fprintf(fp, "();\n");
}

/****************************************************************************
 *
 * writing port and net declarations and assigns
 *
 ****************************************************************************/

//static void write(text separator, size_t tabs, module_item i, module_edit e, size_t *len, size_t *maxlen, FILE *fp)
//{
//	if (hasDeclItem(i) eq true)
//	  write(separator, tabs, getDeclItem(i), len, maxlen, fp);
//
//	if (hasAssignItem(i) eq true)
//	  write(" ", tabs+1, getAssignItem(i), fp);
//
////	if (hasInstanceItem(i) eq true)
////	  write("", tabs+1, getInstanceItem(i), e, len, maxlen, fp);
//}

/***************************************************************************
 *
 * writing initial and defparam statements
 *
 ***************************************************************************/

static void write(text separator, size_t tabs, module_item i, FILE *fp)
{
	if (hasInitialItem(i) eq true)
	  fprintf(fp, "%s%s%s\n", separator, Tab(tabs), getInitialItem(i));

	if (hasOverrideItem(i) eq true)
	  fprintf(fp, "%s%s%s\n",separator, Tab(tabs), getOverrideItem(i));

//	if (hasInstanceItem(i) eq true)
//	  write("", tabs+1, getInstanceItem(i), e, len, maxlen, fp);
}

/*****************************************************************************/

static void write(text separator, size_t tabs, module m, translation_unit t, FILE *fp)
{
   size_t maxlen = (size_t)MAXLINELENGTH;
	size_t len = 0;
	
#ifdef DEBUG
   printf("DEBUG: veredit mode: %d\n",veredit_mode);
#endif

#ifdef DEBUG
   printf("DEBUG: writing module %s\n",getName(m));
#endif
	fprintf(fp, "%s%smodule %s(", separator, Tab(tabs), getN(getName(m)));
   
	len = strlen(separator) + tabs*3 + strlen(getN(getName(m))) + 10;
	
#ifdef DEBUG
   printf("DEBUG:   writing ports\n");
#endif
	writeSet("", ",", tabs + 2, getPorts(m), &len, &maxlen, fp);
   
	fprintf(fp, " );\n");

#ifdef DEBUG
   printf("DEBUG:   writing paramter declarations\n");
#endif
      parameter_decl_list pmdl = getParameter_declarations(m);
	writeSet(" ", " ", tabs , pmdl, fp);

#ifdef DEBUG
   printf("DEBUG:   writing port declarations\n");
#endif
   //writeSet("", "", tabs , getItems(m), getModuleEdit(m, t), &len, &maxlen, fp);
   writeSet("", "", tabs , getPortDeclarations(m), &len, &maxlen, fp);
#ifdef DEBUG
   printf("DEBUG:   writing net declarations\n");
#endif
   writeSet("", "", tabs , getNetDeclarations(m), &len, &maxlen, fp);
   fprintf(fp, "\n");

#ifdef DEBUG
   printf("DEBUG:   writing assigns\n");
#endif
   assign_list al = getAssigns(m);
	writeSet(" ", " ", tabs+1 , al, fp);
	if (size(al) > 0)
      fprintf(fp, "\n");

#ifdef DEBUG
   printf("DEBUG:   writing instances\n");
#endif
	if (hasInstances(m) eq true)
      writeSet("", "", tabs + 1, getInstances(m), getModuleEdit(m, t), &len, &maxlen, fp);

#ifdef DEBUG
   printf("DEBUG:   writing module items 2\n");
#endif
   writeSet("", "", tabs + 1 , getItems(m), fp);

   fprintf(fp, "%s%sendmodule\n\n", separator, Tab(tabs));
}

static void write(text separator, size_t tabs, verilog_item i, translation_unit t, FILE *fp)
{
	if(hasCompilerDirective(i) eq true)
		fprintf (fp,"%s\n\n",getCompilerDirective(i));
	else if (hasBlock(i) eq true)
	{
		write(separator, tabs, getBlock(i), t, fp);
	}
}

expfun void writeVerilog(translation_unit t, text outfile)
{
   if (hasItems(t) eq true)
   {
      FILE *fo = openW(outfile);
      
		writeHeader(fo);
		writeSet("", "", (size_t)0, getItems(t), t, fo);
      Close(fo);
   }
   else
      fprintf(stdout, "veredit: WARNING: No module definitions found.\n");
} 

void writeVnode(vnode v, translation_unit t, FILE *fp)
{
	size_t i;
	vnode node;
	static nameset mlist = NULL;
	text mname ;

	if (mlist == NULL)
		mlist = namesetNew();

	i = 0;
	while (i < sizeOfInstances(v))
	{
		node = elementAtInstances(i, v);
		writeVnode(node, t, fp);
		++i;
	}
	if (sizeOfParents(v) != 0)
	{
		/* it is not the rootNode */
		mname = getName(v);
		
		if (In(mname, mlist) < 0)
		{
		   write("", 0, getBlock(v), t, fp);
			add(mname, mlist);
		}
	}
}

expfun void writeVerilog(translation_unit t, vnode top, text outfile)
{
	if ((t == NULL) || (top == NULL) || (outfile == NULL))
	{
		return;
	}
   FILE *fo = openW(outfile);
	writeHeader(fo);

   writeVnode(top, t, fo);
   Close(fo);
} 
