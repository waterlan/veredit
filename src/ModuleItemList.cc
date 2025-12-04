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
#include "veredit.h"

#include "buffernet_statement.h"
#include "match_list.h"
#include "nameset.h"
#include "vname.h"
#include "range.h"
#include "simple_signal.h"
#include "simple_signal_list.h"
#include "Signal.h"
#include "signal_type.h"
#include "signal_list.h"
#include "portmap_element.h"
#include "portmap.h"
#include "instance.h"
#include "declaration.h"
#include "module_item.h"
#include "module_item_list.h"
#include "assign_list.h"
#include "parameter_decl_list.h"
#include "declaration_list.h"
#include "instantiation_list.h"

#include "buffer_type.h"
#include "Signal_type.h"
#include "VariableList.h"
#include "Instance.h"
#include "Nameset.h"
#include "Portmap.h"
#include "SimpleSignalList.h"
#include "Module.h"
#include "MatchList.h"

#include "text.h"
#include "search.h"
#include "HandleSet.h"

/******************************************************* 
 *
 * Return the signal_type t of a port name
 *
 *******************************************************/

expfun signal_type getType(text name, module_item_list l)
{
   size_t i;
   ssize_t j;
   module_item mi;
   declaration d;
   
   i = 0 ;
   
   while (i < size(l))
   {
      mi = l->array[i];

      if (hasDeclItem(mi) eq true)
      {
         d = getDeclItem(mi) ;
         j = In(name,getSignals(d));
         if ( j ne -1)
            return getType(d);
      }
      i++ ;
   }
   return _SIGNAL_TYPE_UNDEFINED ;
   
}

/******************************************************* 
 *
 * Return the declarations of a module_item_list.
 *
 *******************************************************/
expfun declaration_list getDeclarations(module_item_list mil)
{
   declaration_list l;
   module_item mi;
   size_t i;

   if (mil == NULL)
      return NULL;

   l = declaration_listNew();
   
   for(i = 0; i < size(mil) ; i++)
   {
      mi = elementAt(i,mil);
      if (hasDeclItem(mi) eq true)
        add(getDeclItem(mi),l) ;
   }
   return l;
}

/******************************************************* 
 *
 * Return the port declarations of a module_item_list.
 *
 *******************************************************/
expfun declaration_list getPortDeclarations(module_item_list mil)
{
   declaration_list l;
   module_item mi;
   declaration d;
   signal_type t;
   size_t i;

   if (mil == NULL)
      return NULL;

   l = declaration_listNew();
   
   for(i = 0; i < size(mil) ; i++)
   {
      mi = elementAt(i,mil);
      if (hasDeclItem(mi) eq true)
      {
        d = getDeclItem(mi);
        t = getType(d);
        if ((isINPUT(t)  eq true) ||
            (isOUTPUT(t) eq true) ||
            (isINOUT(t)  eq true))
           add(getDeclItem(mi),l) ;
      }
   }
   return l;
}

/******************************************************* 
 *
 * Return the net declarations of a module_item_list.
 *
 *******************************************************/
expfun declaration_list getNetDeclarations(module_item_list mil)
{
   declaration_list l;
   module_item mi;
   declaration d;
   signal_type t;
   size_t i;

   if (mil == NULL)
      return NULL;

   l = declaration_listNew();
   
   for(i = 0; i < size(mil) ; i++)
   {
      mi = elementAt(i,mil);
      if (hasDeclItem(mi) eq true)
      {
        d = getDeclItem(mi);
        t = getType(d);
        if ((isINPUT(t)  eq false) &&
            (isOUTPUT(t) eq false) &&
            (isINOUT(t)  eq false))
           add(getDeclItem(mi),l) ;
      }
   }
   return l;
}

/******************************************************* 
 *
 * Return the assigns of a module_item_list.
 *
 *******************************************************/
expfun assign_list getAssigns(module_item_list mil)
{
   assign_list l;
   module_item mi;
   size_t i;

   if (mil == NULL)
      return NULL;

   l = assign_listNew();
   
   for(i = 0; i < size(mil) ; i++)
   {
      mi = elementAt(i,mil);
      if (hasAssignItem(mi) eq true)
        add(getAssignItem(mi),l) ;
   }
   return l;
}

/******************************************************* 
 *
 * Return the parameter declarations of a module_item_list.
 *
 *******************************************************/
expfun parameter_decl_list getParameter_declarations(module_item_list mil)
{
   parameter_decl_list l;
   module_item mi;
   size_t i;

   if (mil == NULL)
      return NULL;

   l = parameter_decl_listNew();
   
   for(i = 0; i < size(mil) ; i++)
   {
      mi = elementAt(i,mil);
      if (hasParameter_declItem(mi) eq true)
        add(getParameter_declItem(mi),l) ;
   }
   return l;
}

/******************************************************* 
 *
 * Add a declaration to module_item_list
 *
 *******************************************************/
expfun void add(declaration d, module_item_list l)
{
   module_item i;

   if ((d == NULL) || (l == NULL))
      return ;

   i = module_itemNew(d,NULL,NULL);
   add(i,l);
}

/******************************************************* 
 *
 * Return the instances of a module_item_list.
 *
 *******************************************************/
expfun instantiation_list getInstances(module_item_list mil)
{
   instantiation_list l;
   module_item mi;
   size_t i;
   
   if (mil == NULL)
      return NULL;

   l = instantiation_listNew();
   
   for(i = 0; i < size(mil) ; i++)
   {
      mi = elementAt(i,mil);
      if (hasInstanceItem(mi) eq true)
        add(getInstanceItem(mi),l) ;
   }
   return l;
}

/******************************************************* 
 *
 * Add an instance to module_item_list
 *
 *******************************************************/
expfun void add(instance inst, module_item_list l)
{
   module_item i;

   if ((inst == NULL) || (l == NULL))
      return ;

   i = module_itemNew(NULL,NULL,inst);
   add(i,l);
}

/******************************************************* 
 *
 * Check if there are instances in a module_item_list.
 *
 *******************************************************/
expfun bool hasInstances(module_item_list l)
{
   size_t s, index ;
   module_item i;

   s = size(l);

   index = 0;
   while (index < s)
   {
      i = elementAt(index, l);
      if (hasInstanceItem(i) == true)
         return(true);
      ++index;
   }

   return(false);
}

/*******************************************************/
expfun ssize_t In(instance i, module_item_list l)
{
   //extern bool eqInstName(instance i, module_item j);
   //extern module_item elementAt(size_t position, module_item_list set);
   //extern size_t size(module_item_list m);

   return Index(i,l,eqInstName, true, elementAt, size);
}


expfun instance getInstance(instance i, module_item_list l)
{
   ssize_t index;

   index = In(i,l);
   
   if(index ne -1)
      return getInstanceItem(elementAt(index,l));
   else
      return NULL;
   
}

/******************************************************* 
 *
 * Expand signals with bus-range connected to portmaps.
 * e.g. .A(A[2:3])   ->   .A({A[2], A[3]})
 *
 *******************************************************/

expfun void expandSignals(module_item_list i)
{
   size_t index ;

   index = 0;

   while (index < size(i))
   {
      module_item m = i->array[index];
      if (hasInstanceItem(m) eq true)
      {
         instance inst = getInstanceItem(m);
         expandSignals(inst);
      }
      index++;
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
expfun void expandSignals(module_item_list i, simple_signal s, range r)
{
   size_t index ;

   index = 0;

   while (index < size(i))
   {
      module_item m = i->array[index];
      if (hasInstanceItem(m) eq true)
      {
         instance inst = getInstanceItem(m);
         expandSignals(inst, s, r);
      }
      index++;
   }
}

/******************************************************* 
 *
 * Rename a net connected to instances
 * Returns the number of renames.
 *
 *******************************************************/

expfun int renameNet(module_item_list l, simple_signal oldname, simple_signal newname, bool ignoreIndex, simple_signal_list excludes)
{
   size_t i;
   int renames;
   
   i = 0;
   renames = 0; 
   
   while (i< size(l))
   {
      module_item m = l->array[i];
      if (hasInstanceItem(m) eq true)
      {
         instance inst = getInstanceItem(m);
         renames = renames + renameNet(inst,oldname,newname,ignoreIndex, excludes);
      }
      ++i;
   }
   return(renames);
}

/******************************************************* 
 *
 * Rename a net connected to instances
 * Returns the number of renames.
 *
 *******************************************************/

expfun int renameNet(module_item_list l, simple_signal oldname, simple_signal newname, bool ignoreIndex, simple_signal_list excludes, match_list ml)
{
   size_t i;
   int renames;
   
   i = 0;
   renames = 0; 
   
   while (i< size(l))
   {
      module_item m = l->array[i];
      if (hasInstanceItem(m) eq true)
      {
         instance inst = getInstanceItem(m);
         if ( (isEmpty(ml) eq true) || (In(getInstName(inst), ml) >= 0))
            renames = renames + renameNet(inst,oldname,newname,ignoreIndex, excludes);
      }
      ++i;
   }
   return(renames);
}

/******************************************************* 
 *
 * Return all signals connected to instance_list as a
 * simple_signal_list.
 *
 *******************************************************/

expfun simple_signal_list getSignals(module_item_list i)
{
   simple_signal_list l, li;
   size_t j;
   
   l = simple_signal_listNew();
   
   j=0;
   while (j < size(i))
   {
      module_item m = i->array[j];
      if (hasInstanceItem(m) eq true)
      {
         instance inst = getInstanceItem(m);
         li = getSignals(inst);
         append(li,l);
      }
      j++;
   }
   return l;
}

/***********************************************************/

void handle(module_item i, nameset n)
{
   if (hasInstanceItem(i) eq true)
   {
      instance inst = getInstanceItem(i);
      if (getInstName(inst) != NULL)
         add(getN(getInstName(inst)),n);
   }
}

expfun nameset getInstNames(module_item_list l)
{
   nameset n;
   
   n = namesetNew();
   
   
   handleSet(l,n);
   
   return n ;
   
}

/******************************************************* 
 *
 * Test if a variable_name is in a module_item_list (declaration)
 *
 *******************************************************/
expfun bool In(variable_name s, module_item_list l, signal_type t)
{
   size_t i;
   
   i = 0 ;
   
   while (i < size(l))
   {
      module_item mi = l->array[i];
      if (hasDeclItem(mi) eq true)
      {
         declaration d = getDeclItem(mi);
         if ( eqSignal_type(t,getType(d)) eq true)
         {
            
            if (In(s,getSignals(d)) ne -1)
               return true;
         }
      }
      i++ ;
   }
   return false ;
}

/******************************************************* 
 *
 * Test if a variable_name is in a module_item_list (declaration)
 *
 *******************************************************/
expfun bool In(text name, module_item_list l, signal_type t)
{
   size_t i;
   
   i = 0 ;
   
   while (i < size(l))
   {
      module_item mi = l->array[i];
      if (hasDeclItem(mi) eq true)
      {
         declaration d = getDeclItem(mi);
         if (( eqSignal_type(t,getType(d)) eq true))
         {
            
            if (In(name,getSignals(d)) ne -1)
               return true;
         }
      }
      i++ ;
   }
   return false ;
}
/******************************************************* 
 *
 * Find a port declaration
 *
 *******************************************************/
expfun bool hasPortDeclaration(text name, module_item_list l)
{
   size_t i;
   
   i = 0 ;
   signal_type st;
   
   while (i < size(l))
   {
      module_item mi = l->array[i];
      if (hasDeclItem(mi) eq true)
      {
         declaration d = getDeclItem(mi);
         st = getType(d);
         if ((isINPUT(st) eq true) ||
             (isOUTPUT(st) eq true) ||
             (isINOUT(st) eq true))
         {
            if (In(name,getSignals(d)) ne -1)
               return true;
         }
      }
      i++ ;
   }
   return false ;
}

/******************************************************* 
 *
 * Return the range of a port name
 *
 *******************************************************/
expfun range getRange(text name, module_item_list l)
{
   size_t i;
   ssize_t j;
   
   i = 0 ;
   
   while (i < size(l))
   {
      module_item mi = l->array[i];
      if (hasDeclItem(mi) eq true)
      {
         declaration d = getDeclItem(mi);

         j = In(name,getSignals(d));
         if ( j ne -1)
            return getRnge(d);
      }
      i++ ;
   }
   return NULL ;
}

expfun range getRange(vname name, module_item_list l)
{
   return getRange(getN(name), l);
}

/******************************************************* 
 *
 * Add a continuous_assign to module_item_list
 *
 *******************************************************/
expfun void add(continuous_assign a, module_item_list l)
{
   module_item i;

   i = module_itemNew(NULL,a,NULL);
   add(i,l);
}

/******************************************************* 
 *
 * Add a parameter declaration to module_item_list
 *
 *******************************************************/
expfun void add(parameter_decl a, module_item_list l)
{
   module_item i;

   i = module_itemNew(NULL,NULL,NULL,NULL,NULL,a);
   add(i,l);
}

/******************************************************* 
 *
 * Check if there are continuous assigns in a module_item_list.
 *
 *******************************************************/
expfun bool hasAssigns(module_item_list l)
{
   size_t s, index ;
   module_item i;

   s = size(l);

   index = 0;
   while (index < s)
   {
      i = elementAt(index, l);
      if (hasAssignItem(i) == true)
         return(true);
      ++index;
   }

   return(false);
}

void bufferNet(simple_signal s,module_item_list l, buffernet_statement b, nameset allinsts, simple_signal_list allnets, buffer_type t)
{
   simple_signal oldnetname, newnetname;
   char buffer[VEREDIT_MAX_NAME_LENGTH];
   instance newbuffer;
   text buffername ;
   text buf_inputname, buf_outputname ;

   /* s   is the netname in the portmap_element in the instance of the module */

   // copy original net to oldnetname (deep).
   oldnetname = copy(s,9);
   
   // generate new netname.
   nameNew(allnets, buffer, getN(getName(oldnetname)), getBusIndex(s));
   setName(vnameNew(textNew(buffer)),s);
   setRnge(NULL,s);
   setBusIndex(-1,s);


   // copy modified net to newnetname (deep).
   newnetname = copy(s,9);

   // create new unique buffer instance name.
   nameNew(allinsts, buffer, getN(getName(oldnetname)), getBusIndex(oldnetname));

   buffername = getN(getBufferName(b));
   buf_inputname = getInputName(b) ;
   buf_outputname = getOutputName(b) ;
   
   // create new buffer
   switch (t)
   {
   case _BUFFER :
      newbuffer = bufferNew(newnetname, oldnetname, buffer, buf_inputname, buf_outputname, buffername);
      break;
   case _BUFFERINPUT :
      newbuffer = bufferNew(oldnetname, newnetname, buffer, buf_inputname, buf_outputname, buffername);
      break;
   default : break;
   }

   
   add(newbuffer,l);
}

void bufferNet(Signal s,module_item_list l, buffernet_statement b, nameset allinsts, simple_signal_list allnets, buffer_type t)
{
   if (hasSimple(s) eq true)
   {
      bufferNet(getSimple(s),l,b, allinsts,allnets, t);
   }
}


void handle(portmap_element p, portmap pm, module_item_list l, buffernet_statement b, nameset allinsts, simple_signal_list allnets, buffer_type t)
{
   ssize_t i;

   /*  p    is the portmap_element from the buffernet edit statement */
   /*  pm   is the portmap of the matching instance in the module */
   /*  pe   is the matching portmap_element of the portmap of the matching instance in the module */

   if ( (i=In(p,pm)) ne -1)
   {
      portmap_element pe = elementAt(i,pm);
      signal_list sl = getSignals(pe);
      if (size(sl) eq 1)
      {
         Signal sig = elementAt((size_t)0,sl);
         if (hasSimple(sig) eq true)
            bufferNet(sig,l,b,allinsts,allnets, t);
         else
            fprintf(stdout, "veredit: WARNING: Port %s is not single bit..\n",getN(getPinName(p)));
      }
      else
         fprintf(stdout, "veredit: WARNING: Port %s is not single bit.\n",getN(getPinName(p)));
   }
   else
      fprintf(stdout, "veredit: WARNING: Port %s not found.\n",getN(getPinName(p)));
}


/******************************************************* 
 *
 * 
 * 
 *
 *******************************************************/
expfun void bufferNet(module_item_list l,  instance i, buffernet_statement b, nameset allinsts, simple_signal_list allnets, buffer_type t)
{
   instance inst;

   fprintf(stdout, "veredit: Buffer instance %s...\n",getN(getInstName(i)));
   
   inst = getInstance(i,l);

   /*  i    is the instance from the buffernet edit statement */
   /*  inst is the matching instance in the module */

   if (inst ne NULL)
   {
      if(hasConnections(i) eq true)
         handleSet(getConnections(i),getConnections(inst),l,b,allinsts,allnets, t);
   }
   else
      fprintf(stdout, "veredit: instance %s not found.\n",getN(getInstName(i)));

}

