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
#include <string.h>

#include "structures.h"
#include "std_macro.h"

#include "vnode.h"
#include "vname.h"
#include "module.h"
#include "module_list.h"
#include "verilog_item.h"
#include "verilog_item_list.h"
#include "translation_unit.h"

#include "InstantiationList.h"
#include "Module.h"
#include "ModuleList.h"
#include "TranslationUnit.h"

#include "file.h"
#include "HandleSet.h"

/* 
   A fast 'isInstance' is needed for building hierarchy.
	No use of API functions.
*/

bool isInstance_faster(module m, instantiation_list l)
{
	size_t index;
	instance i;

	index = 0;

	while (index < l->size)
	{
		i = l->array[index];
		if (strcmp(m->name->n, i->cellName->n) == 0)
			return(true);
		++index;
	}
	return(false);
}


/*
  Create B+ tree
*/

void handle(module m, module_list ml)
{
	vnode mod_current, mod_child;
	vnode mod_up;
	instantiation_list il;
	module child;
	size_t index;

   mod_current = getModNode(m);
	il = getInstances(m);

	index = 0;
	while (index < ml->size)  // Go through complete module list.
	{
		child = ml->array[index];
		if (isInstance_faster(child, il) eq true) // is the module an instance of this module?
		{
			mod_child = child->modNode;  // vnode of chile module
			if (mod_current->instancesSize > 0)
			{
				mod_up = mod_current->instances[mod_current->instancesSize - 1];
				mod_up->down = mod_child;
				mod_child->up = mod_up;
			}
			// A module can have multiple parents
			addToParents(mod_current, mod_child);
			addToInstances(mod_child, mod_current);
		}
		++index;
	}

}

void handle(verilog_item i, module_list l)
{
	if (hasBlock(i) eq true) /* it is a module */
	{
		handle(getBlock(i), l);
	}
}

/* 
 create vnode for module
 */

void handle(module m, vnode rootNode)
{
	vnode mod_node;

	mod_node = vnodeNew(m); /* create vnode for this module, link module to vnode */
	setName(getN(getName(m)), mod_node);

	setModNode(mod_node, m); /* link vnode to module */
}

void handle(verilog_item i, vnode rootNode)
{
	if (hasBlock(i) eq true) /* it is a module */
	{
		handle(getBlock(i), rootNode);
	}
}

/* add all modules with no parent to rootNode */
void add_to_root(module m, vnode rootNode)
{
	if (m->modNode->parentsSize == 0)
	{
		addToInstances(m->modNode, rootNode);
		addToParents(rootNode, m->modNode);
	}
}

void add_to_root(module_list l, vnode rootNode)
{
	size_t i=0;
	module m;
	
	while (i<l->size)
	{
		m = l->array[i];
		add_to_root(m, rootNode);
		++i;
	}
}

vnode createRootNode()
{
	vnode rootNode;

	rootNode = vnodeNew();

   if (rootNode != NULL)
   {
      setName("/",rootNode);
      setX(0,rootNode);
      setY(0,rootNode);
   }

   return(rootNode);
}


expfun void buildHierarchy(translation_unit t)
{
	
	vnode rootNode;
	module_list l;

	rootNode = createRootNode();
	setRootNode(rootNode, t);
	l = getModules(t);

   fprintf(stdout, "veredit: Building hierarchy...");
   /* create vnodes for all modules */
	handleSet(getItems(t), rootNode);
   /* build tree of vnodes */
	handleSet(getItems(t), l);
   /* add all modules with no parent to rootNode */
	add_to_root(l, rootNode);
   fprintf(stdout, " Done.\n");
}
/***********************************************************
 *
 * Dump vnode tree.
 *
 ***********************************************************/

void dumpVnodeTree (vnode node, size_t level, FILE *fp)
{
	size_t i,size;
	vnode inst;

	for (i=0;i<level;++i)
      fprintf(fp,"  ");

	fprintf(fp,"%s\n",getName(node));

   size = sizeOfInstances(node);

	for (i=0;i<size;++i)
	{
		inst = elementAtInstances(i,node);
		dumpVnodeTree(inst, level+1, fp);
	}

}
expfun void writeTree(vnode node, text outfile)
{
   FILE *fo = openW(outfile);
     
	dumpVnodeTree(node, (size_t)0, fo);
   Close(fo);
} 
