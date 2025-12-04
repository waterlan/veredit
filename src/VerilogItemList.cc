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

#include "structures.h"
#include "std_macro.h"

#include "module.h"
#include "verilog_item.h"
#include "verilog_item_list.h"

#include "text.h"

#include "Vname.h"
#include "Module.h"


ssize_t In(text name, verilog_item_list v)
{
	size_t i;
	module m;
   verilog_item vi;

   i = 0;
	while (i < size(v))
	{
		vi = v->array[i];
		if (hasBlock(vi) eq true)
		{
		   m = getBlock(vi);
			if (Eq(name,getName(m)) eq true)
				return((ssize_t)i);
		}
		i++;
	}
	return(-1);
	
}

/******************************************************* 
 *
 * Find a module in a verilog_item_list
 *
 *******************************************************/
expfun module getModule(text name, verilog_item_list l)
{
	ssize_t i;

   if ((name == 0) || (l == NULL))
		 return NULL;

	i = In (name, l);

	if (i != -1)
		return (getBlock(elementAt(i,l)));
	else
		return NULL;
}


/*********************************************
 *
 * Remove a module from a verilog_item_list
 * If empty is true the module will only be deleted
 * if it has no instances.
 *
 *********************************************/
expfun void remove(text name, verilog_item_list v, bool empty)
{
   module m;
   ssize_t index = In(name, v);

   if (index ne -1)
	{
	   if (empty == false)
		{
			remove((size_t)index,v);
			fprintf(stdout, "veredit: Module %s deleted.\n", name);
		}
		else
		{
		   m = getBlock(elementAt(index,v));
			if ((hasInstances(m) == false) && (hasAssigns(m) == false))
			{
				remove((size_t)index,v);
				fprintf(stdout, "veredit: Module %s deleted.\n", name);
			}
		}
	}
}

