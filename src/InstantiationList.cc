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

#include "nameset.h"
#include "vname.h"
#include "simple_signal.h"
#include "simple_signal_list.h"
#include "Signal.h"
#include "signal_list.h"
#include "portmap_element.h"
#include "portmap.h"
#include "instance.h"
#include "instantiation_list.h"
#include "edit_list.h"
#include "edit_element.h"
#include "module_edit.h"

#include "text.h"
#include "Nameset.h"
#include "Instance.h"
#include "search.h"
#include "HandleSet.h"
#include "Portmap_element.h"
#include "Portmap.h"
#include "Module.h"
#include "EditElement.h"
#include "SimpleSignalList.h"


expfun bool Check1(instantiation_list l, module_edit m)
{
   static nameset instNames = NULL;
   bool   ok = true; 

   if (instNames eq NULL)
      instNames = namesetNew();
   else
      setSize(0, instNames);

   instance i;
   text instName;
   size_t index = 0;
   while(index < size(l))
   {
      i = l->array[index];
        
      instName = getInstName(i, m);
      TRACE(fprintf(stdout, "check instname %s module %s\n", instName, getN(getName(m)));)
      if (In(instName, instNames) eq -1)
         add(instName, instNames);
      else
      {
         fprintf(stdout, "veredit: ERROR: instance %s multiple defined in module %s\n",
                                  instName, getN(getName(m)));
         ok = false;
      }

      index = index + 1;
   }

   return ok;
}     

expfun bool Check(instantiation_list l, module_edit m)
{
   static nameset instNames = NULL;

   if (instNames eq NULL)
      instNames = namesetNew();
   else
      setSize(0, instNames);

   instance i;
   text instName;
   size_t index = 0;
   while(index < size(l))
   {
      i = l->array[index];
        
      instName = getInstName(i, m);
      add(instName, instNames);

      index = index + 1;
   }

   edit_list e_l = getEdtList(m);
   edit_element e; 

   index = 0;
   size_t  count; 
   text newName;
   while(index < size(e_l))
   {
      e = e_l->array[index];
      newName = getNewName(e);

      count = matchCount(newName, instNames);
      if (count > 1)
      {
         fprintf(stdout, "ERROR : instance %s multiple defined in module %s\n",
                                  newName, getN(getName(m)));
         return false;
      }
 
      index = index + 1;
   }

   return true;
}     

ssize_t In(module m, instantiation_list i)
{
	//extern bool equal(module m, instance i);
	//extern instance elementAt(size_t position, instantiation_list set);
	//extern size_t size(instantiation_list i);
	return Index(m, i, equal, true, elementAt, size);
}

expfun bool isInstance(module m, instantiation_list i)
{
   if (In(m,i) ne -1)
     return true;
   else
     return false;
}

/******************************************************* 
 *
 * Return the number of type t portmaps signal s is connected to.
 *
 *******************************************************/

expfun int count(instantiation_list l, simple_signal s, signal_type t, translation_unit tu)
{
  size_t index;
  int number;
  
  index = 0;
  number = 0;
  
  while (index < size(l))
  {
     number = number + count(l->array[index],s,t,tu);
	  index++;
	}
	return number;
}


expfun ssize_t In(instance i, instantiation_list l)
{
	//extern bool eqInstName(instance i, instance j);
	//extern instance elementAt(size_t position, instantiation_list set);
	//extern size_t size(instantiation_list i);
	return Index(i,l,eqInstName, true, elementAt, size);
}

instance getInstance(instance i, instantiation_list l)
{
	ssize_t index;

	index = In(i,l);
	
	if(index ne -1)
		return elementAt(index,l);
	else
		return NULL;
	
}


