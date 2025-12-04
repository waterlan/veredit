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

#include "vname.h"
#include "module.h"
#include "module_list.h"
#include "module_edit_list.h"
#include "verilog_item.h"
#include "verilog_item_list.h"
#include "translation_unit.h"

#include "Module.h"
#include "ModuleList.h"
#include "ModuleEdit.h"
#include "VerilogItemList.h"
#include "text.h"
#include "search.h"


expfun module getModule(text name, translation_unit t)
{
	verilog_item_list items;

   if (hasItems(t) eq true)
	   items = getItems(t);
	else
	   return NULL;
   
   return getModule(name, items);
}

expfun module getModule(vname name, translation_unit t)
{
	return getModule(getN(name), t);
}

ssize_t In(text name, module_edit_list l)
{
	extern bool equal(text name, module_edit m);
	return Index(name,l,equal);
}

ssize_t In(vname name, module_edit_list l)
{
	return In(getN(name), l);
}

expfun module_edit getModuleEdit(text name, translation_unit t)
{
   module_edit_list edits = getEdits(t);
   ssize_t index = In(name, edits);
   if (index ne -1)
      return edits->array[index];
   else
      return NULL;
}

expfun module_edit getModuleEdit(vname name, translation_unit t)
{
	return getModuleEdit(getN(name), t);
}

expfun module_list getModules(translation_unit t)
{
	module_list l;
	verilog_item_list v;
	verilog_item vi;
	size_t i;

	if (t == NULL)
	  return NULL;
	
	l = module_listNew();

	if (hasItems(t) eq true)
	{
		v = getItems(t);
		i = 0;

		while (i < size(v))
		{
			vi = v->array[i];
			if (hasBlock(vi) eq true)
				add(getBlock(vi),l);
			i++;
		}
	}
	
   return(l);
	
}

expfun module_edit getModuleEdit(module m, translation_unit t)
{
   return getModuleEdit(getName(m), t);
}

expfun bool Check(translation_unit t)
{
   return Check(getModules(t), t);
}

expfun module_list findParent(module m, translation_unit t)
{
   return findParent(m, getModules(t));
}

expfun void addModule(module m, translation_unit t)
{

	verilog_item_list items;
	verilog_item      item;

   if (hasItems(t) eq true)
	{
	   items = getItems(t);
		item  = verilog_itemNew(NULL, m);
		add (item, items);
	}
}

