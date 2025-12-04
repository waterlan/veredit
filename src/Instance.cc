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
#include "range.h"
#include "signal_type.h"
#include "edit_element.h"
#include "simple_signal.h"
#include "simple_signal_list.h"
#include "portmap_element.h"
#include "portmap.h"
#include "signal_list.h"
#include "Signal.h"
#include "instance.h"
#include "module_item.h"
#include "module.h"

#include "Vname.h"
#include "EditElement.h"
#include "Portmap_element.h"
#include "Signal_.h"
#include "DeclarationsList.h"
#include "Signal_type.h"
#include "SimpleSignal.h"
#include "Signal_.h"
#include "Module.h"
#include "ModuleEdit.h"
#include "TranslationUnit.h"
#include "text.h"
#include "HandleSet.h"

expfun module getModule(instance i, translation_unit t)
{
   return getModule(getCellName(i), t);
}

expfun bool isLeafCell(instance i, translation_unit t)
{
   return isLeafCell(getModule(i, t));
}

expfun bool isUndeclaredCell(instance i, translation_unit t)
{
   
   if (getModule(getCellName(i), t) == NULL)
     return true ;
   else
     return false ;
}


expfun edit_element getEditElement(instance i, module_edit m)
{
   return getEditElement(getInstName(i), m);
}

expfun text getInstName(instance i, module_edit m)
{
   edit_element e = getEditElement(i, m);
   if (e ne NULL)
      return getNewName(e);
   else
      return getN(getInstName(i));
}

expfun bool modified(instance i, module_edit m)
{
   if (Eq(getInstName(i, m), getInstName(i)) eq true)
      return false;
   else
      return true;
}     

// test if module name of instance is equal to a name.
expfun bool equal(vname name, instance i)
{
   return Eq(name, getCellName(i));
}

// test if module name of instance is equal to a module name.
expfun bool equal(module m, instance i)
{
   return Eq(getName(m),getCellName(i));
}

expfun bool eqInstName(instance i, instance j)
{
   if (Eq(getInstName(i),getInstName(j)) eq true)
      return true;
   else
	  return false;

}

expfun bool eqInstName(instance i, module_item j)
{
   if (hasInstanceItem(j) eq true)
		return eqInstName(getInstName(i),getInstanceItem(j));
   else
	  return false;

}
/***********************************************************/

void handle(simple_signal s, simple_signal_list l)
{
	add(s,l);
}

void handle(Signal s, simple_signal_list l)
{
	if(hasSimple(s) eq true)
	   handle(getSimple(s),l);
	else
		if(hasCmpnd(s) eq true)
		   handleSet(getCmpnd(s),l);
}

void handle(portmap_element p, simple_signal_list l)
{
	if (hasSignals(p) eq true)
	   handleSet(getSignals(p),l);
}

/******************************************************* 
 *
 * Return all signals connected to instance as a
 * simple_signal_list.
 *
 *******************************************************/
expfun simple_signal_list getSignals(instance i)
{
   simple_signal_list l;
	
	l = simple_signal_listNew();
	
	if (hasConnections_by_order(i) eq true)
		handleSet(getConnections_by_order(i),l);
	else
		if (hasConnections(i) eq true)
		{
			handleSet(getConnections(i), l);
			return l;
		}
	
	return l;
}

/***********************************************************/

void handle(Signal s, portmap new_p, simple_signal ss, portmap_element orig_p)
{
	if(hasSimple(s) eq true)
	{
	   if (equal(getSimple(s),ss) eq true)
			add(orig_p,new_p);
	}
	else
		if(hasCmpnd(s) eq true)
		   handleSet(getCmpnd(s),new_p, ss, orig_p);
}

void handle(portmap_element p, portmap new_p, simple_signal s)
{
	if (hasSignals(p) eq true)
	   handleSet(getSignals(p),new_p, s, p);
}

/******************************************************* 
 *
 * Return all portmaps of an instance connected to a simple_signal as an
 * instance with those portmaps only.
 *
 *******************************************************/
expfun instance getSignals(instance i, simple_signal s)
{
	instance new_i;
	portmap p;

	p = portmapNew();
	new_i = instanceNew(getCellName(i), getInstName(i), p, NULL);
	
		if (hasConnections(i) eq true)
		{
			handleSet(getConnections(i), p, s);
			return new_i;
		}
	
	return new_i;
}

/***********************************************************/

/******************************************************* 
 *
 * Define the number of type t portmaps signal s is connected to.
 * Store it in *number.
 *
 *******************************************************/
void handle(Signal s, simple_signal ss, signal_type t, text cellname, text pinname, int *number, translation_unit tu)
{
	if(hasSimple(s) eq true)
	{
		
		if (equal(getSimple(s),ss) eq true)
		{
			module m = getModule(cellname,tu);
			if (m == NULL)
			   fprintf(stdout,"veredit: WARNING: Declaration of module %s not found. Could not check output %s.\n",cellname,getN(getName(ss)));
			else
			{
			  signal_type st = getType(pinname, m);
			  if (eqSignal_type(t,st) eq true)
			    *number = *number + 1;
			}
			     
		}
	}
	else
		if(hasCmpnd(s) eq true)
		   handleSet(getCmpnd(s), ss, t, cellname, pinname, number,tu);
}

/******************************************************* 
 *
 * Define the number of type t portmaps signal s is connected to.
 * Store it in *number.
 *
 *******************************************************/
void handle (portmap_element p, simple_signal s, signal_type t, text cellname, int *number, translation_unit tu)
{
	if (hasSignals(p) eq true)
	   handleSet(getSignals(p), s, t, cellname, getN(getPinName(p)), number, tu);

}

/******************************************************* 
 *
 * Return the number of type t portmaps signal s is connected to.
 *
 *******************************************************/
expfun int count(instance i, simple_signal s, signal_type t, translation_unit tu)
{
   int number;
  
   number = 0;

	if (hasConnections(i) eq true)
		{
			handleSet(getConnections(i), s, t, getN(getCellName(i)), &number,tu);
		}
	

	return number;
}



/******************************************************* 
 *
 * Rename a net connected to instances
 * Return the number of renames
 *
 *******************************************************/
expfun int renameNet(instance i, simple_signal oldname, simple_signal newname, bool ignoreIndex, simple_signal_list excludes)
{
	size_t index ;
	int renames ;
	portmap_element p;

	renames = 0;

	if (hasConnections_by_order(i) eq true)
   {
		index = 0;
		while (index < size(getConnections_by_order(i)))
		{
		   Signal s = elementAt(index, getConnections_by_order(i));
			renames = renames + renameNet(s, oldname, newname, ignoreIndex);
		   ++index;
		}
	}
	else
	if (hasConnections(i) eq true)
		{
			index = 0;
			while (index < size(getConnections(i)))
			{
				p = elementAt(index, getConnections(i));
			   renames = renames + renameNet(p, oldname, newname, ignoreIndex, excludes);
				++index;
			}
		}
	return(renames);
}



/******************************************************* 
 *
 * Expand signals with bus-range connected to portmaps.
 * e.g. .A(A[2:3])   ->   .A({A[2], A[3]})
 *
 *******************************************************/
expfun void expandSignals(instance i)
{
	if (hasConnections_by_order(i) eq true)
		handleSet(getConnections_by_order(i));
	else
	if (hasConnections(i) eq true)
		{
			handleSet(getConnections(i));
		}
}
/******************************************************* 
 *
 * Make implicit bus-range explicit and expand.
 * e.g. 
 * wire [2:3] A;
 * .A(A)   ->  .A(A[2:3])  ->   .A({A[2], A[3]})
 *
 *******************************************************/
expfun void expandSignals(instance i, simple_signal s, range r)
{
	if (hasConnections_by_order(i) eq true)
		handleSet(getConnections_by_order(i), s, r);
	else
	if (hasConnections(i) eq true)
		{
			handleSet(getConnections(i), s, r);
		}
}
