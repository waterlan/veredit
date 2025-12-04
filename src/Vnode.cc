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

#include "vname.h"
#include "vnode.h"
#include "simple_signal.h" 
#include "Signal.h" 
#include "signal_list.h" 
#include "portmap_element.h"
#include "portmap.h"
#include "instance.h"
#include "module_item.h"
#include "module_item_list.h"
#include "module.h"

#include "text.h"

#include "Portmap.h"
#include "Instance.h"
#include "Module.h"
#include "doEdits.h"


/* remove module with name 'name' from whole vnode tree */
expfun void remove (text name, vnode node, bool empty)
{
   size_t i = 0;
   vnode v;
   module m;

   if (node == NULL)
      return;
   
   /* printf("module %s\n",  getName(node)); */

   while (i < node->instancesSize)
   {
      v = elementAtInstances(i, node);
      m = getBlock(v);
      if ( (empty == false) ||
           ((empty == true) && (hasInstances(m) == false) && (hasAssigns(m) == false)))
      {
         remove(name, v, empty);                   /* go to subnodes */
         if (strcmp(name, getName(v)) == 0)
         {
            removeFromInstances(i, node);
      /*    printf("  deleted %s\n",  getName(v)); */
         }
         else
            ++i;
      }
      else
         ++i;
   }
}

expfun void print (vnode node)
{
   size_t i = 0;
   vnode v;

   if (node == NULL)
      return;
   
   printf("%s\n",  getName(node));

   while (i < node->instancesSize)
   {
      printf("---");
      v = elementAtInstances(i, node);
      print(v);                   /* go to subnodes */
      ++i;
   }
}

/***********************************************************
 *
 * Add a port 'pin' to this vnode and recurse to all parents.
 *
 ***********************************************************/

expfun void pullupPin (vnode node, addport_statement pin, vname module_name, simple_signal pin_simple)
{
   size_t i, j;
   module m;
   vnode parent;
   module_item_list mil;
   module_item mi;
   instance inst;

   //printf("--> sizeOfParents is %d\n",sizeOfParents(node));

   if (sizeOfParents(node) != 0)
   {
      //fprintf(stdout, "veredit: INFO: Pulling up pin %s in module %s.\n", getN(getName(pin_simple)), getName(node));
      /* it is not the rootNode */
      i=0;
      m = getBlock(node);
      
      // duplicate pin additions when going up the hierarchy are automatically ignored by addPorts()
      addPorts(pin, m, true);

      //find instantiations of the module.
      mil = getItems(m);
      j = 0;
      for(j = 0; j < size(mil) ; j++)
      {
         mi = elementAt(j,mil);
         if (hasInstanceItem(mi) eq true) // it is an instance
         {
            inst = getInstanceItem(mi);
            if (equal(module_name, inst) eq true) // it is an instance of module_name.
            {
               // create a signalist
               signal_list sl = signal_listNew();
               Signal sign = SignalNew(pin_simple, NULL);
               add(sign, sl);
               // create a portmap
               portmap_element pme = portmap_elementNew(getName(pin_simple), sl);
               portmap pm = portmapNew();
               add(pme, pm);

               add(pm, getConnections(inst)); // add the portmap connections
               
            }
         }
      }

      while (i < sizeOfParents(node)) // Go through all parents
      {
         parent = elementAtParents(i, node);
         pullupPin (parent, pin, getName(m), pin_simple);
         ++i;
      }
   }
}
/***********************************************************
 *
 * Get hierarchical instance name
 *
 ***********************************************************/

expfun void getHierInstName (vnode node, text hier_inst_name, text name, FILE *fp)
{
   size_t i, j;
   module p;
   vnode parent;
   module_item_list mil;
   module_item mi;
   instance inst;
	vname module_name;
	text keep_inst_name;

   if (sizeOfParents(node) != 0)
   {
      /* it is not the rootNode */
      i=0;
      while (i < sizeOfParents(node)) // Go through all parents
      {
         parent = elementAtParents(i, node);
         p = getBlock(parent);
			module_name = getName(getBlock(node)); // module name of this node
         //get items of the parent.
         mil = getItems(p);

			j = 0;
			for(j = 0; j < size(mil) ; j++)
			{
				mi = elementAt(j,mil);
				if (hasInstanceItem(mi) eq true) // item is an instance
				{
					inst = getInstanceItem(mi);
					if (equal(module_name, inst) eq true) // it is an instance of this node.
					{
						keep_inst_name = textNew(hier_inst_name);
						if (strcmp(hier_inst_name,"") != 0)
							hier_inst_name = concat(getN(getInstName(inst)),"/",hier_inst_name);
						else
							hier_inst_name = getN(getInstName(inst));
                  getHierInstName (parent, hier_inst_name, name, fp);
		            if (sizeOfParents(parent->parents[0]) == 0) //rootnode
						{
                     fprintf(stdout, "veredit: INFO: inst     %s\n", hier_inst_name);
                     fprintf(fp, "%s\t%s\n", name, hier_inst_name);
						}
                  hier_inst_name =  textNew(keep_inst_name);
					}
				}
			}
         ++i;
      }
   }
}
