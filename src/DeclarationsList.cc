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
#include "port_reference.h"
#include "port_expression.h"
#include "port.h"
#include "port_list.h"
#include "simple_signal.h"
#include "simple_signal_list.h"
#include "signal_type.h"
#include "variable_name.h"
#include "variable_list.h"
#include "declaration.h"
#include "declaration_list.h"

#include "text.h"
#include "search.h"
#include "HandleSet.h"
#include "Signal_type.h"
#include "VariableList.h"


/* expfun declaration getDeclaration(port , declaration_list )
{
   declaration decl;
   
  This is unfinished.  
   
   return decl;
}

*/

/******************************************************* 
 *
 * Return the declarations that correspond to a port_list 
 *
 *******************************************************/
/* expfun declaration_list getDeclarations_list(port_list p, declaration_list d)
{
   declaration_list l;
   port prt ;
   int i;
   
   l = declaration_listNew();
   
   for(i = 0; i < p->size ; i++)
   {
      prt = p->array[i];
	  
	  add(getDeclaration(prt,d),l) ;
   }
   return l;
}
*/

/**********************************************************
 * add declarations to port_list depending on type
 * only input, output and inout.
 *
 **********************************************************/

void handle(variable_name s, port_list p, signal_type t)
{
   text ts ;
	
	ts = toString(t) ;

  if ((Eq(ts,"input") eq true) ||
   	(Eq(ts,"output") eq true) ||
   	(Eq(ts,"inout") eq true))
  {
	  add(portNew(port_expressionNew(port_referenceNew(getName(s)), NULL), NULL, NULL), p);
  }
}

void handle(declaration d, port_list p)
{
	handleSet(getSignals(d),p,getType(d));
}

/******************************************************* 
 *
 * Return a port_list that corresponds with a declaration_list
 *
 *******************************************************/
expfun port_list getPortlist(declaration_list d)
{
   port_list p ;
   
   p = port_listNew();
   
	handleSet(d,p);
	return p ;  
}   

/******************************************************* 
 *
 * Test if a variable_name is in a declaration_list
 *
 *******************************************************/
expfun bool In(variable_name s, declaration_list l, signal_type t)
{
	size_t i;
	
	i = 0 ;
	
	while (i < size(l))
	{
	   declaration d = l->array[i];
		if ( eqSignal_type(t,getType(d)) eq true)
		{
			
			if (In(s,getSignals(d)) ne -1)
			   return true;
		}
		i++ ;
	}
	return false ;
}



/******************************************************* 
 *
 * Return all declarations of signal_type t.
 *
 *******************************************************/
expfun declaration_list getDeclarationList(declaration_list d, signal_type t)
{
   declaration_list nl ;
	size_t i;
	
	nl = declaration_listNew();
	
	i = 0;
	
	while (i< size(d))
	{
	   declaration nd = d->array[i];
		
		if ( eqSignal_type(t,getType(nd)) eq true)
			add(nd,nl);
		i++;
	}
	
   return nl;       
}   

/******************************************************* 
 *
 * Return all declarations of signal_type input, output and inout.
 *
 *******************************************************/
expfun declaration_list getDeclarationList(declaration_list d)
{
   declaration_list nl ;
	size_t i;
	
	nl = declaration_listNew();
	
	i = 0;
	
	while (i< size(d))
	{
	   declaration nd = d->array[i];
		
		if ( (isINPUT(getType(nd))eq true) || 
		     (isOUTPUT(getType(nd)) eq true) ||
			  (isINOUT(getType(nd)) eq true))
			add(nd,nl);
		i++;
	}
	
   return nl;       
}   

/***********************************************************/

void handle (variable_name s, nameset n)
{
    add(getN(getName(s)),n);
}

void getNames (variable_list s, nameset n)
{
   handleSet(s,n);
}


/******************************************************* 
 *
 * Return the names of all declarations of signal_type t.
 *
 *******************************************************/
expfun nameset getNames(declaration_list d, signal_type t)
{
	nameset n ;
	size_t i;
	
	n = namesetNew();
	
	i = 0;
	
	while (i< size(d))
	{
	   declaration nd = d->array[i];
		
		if ( eqSignal_type(t,getType(nd)) eq true)
		{
			getNames(getSignals(nd),n);
		}
		i++;
	}
	
   return n;       
}   

/***********************************************************/

void handle (variable_name s, simple_signal_list l, range r)
{
	simple_signal sig ;

   sig = simple_signalNew( -1, getName(s), -1, r); 

    add(sig,l);
}

void getSignals (variable_list s, simple_signal_list l, range r)
{
   handleSet(s,l,r);
}

/******************************************************* 
 *
 * Return all declarations of signal_type t as a
 * simple_signal_list.
 *
 *******************************************************/
expfun simple_signal_list getSignals(declaration_list d, signal_type t)
{
	simple_signal_list n ;
	size_t i;
	
	n = simple_signal_listNew();
	
	i = 0;
	
	while (i< size(d))
	{
	   declaration nd = d->array[i];
		
		if ( eqSignal_type(t,getType(nd)) eq true)
		{
			getSignals(getSignals(nd),n,getRnge(nd));
		}
	i++;
	}
	
   return n;       
}   


/******************************************************* 
 *
 * Return the signal_type t of a port name
 *
 *******************************************************/
expfun signal_type getType(text name, declaration_list l)
{
	size_t i;
	ssize_t j;
	
	i = 0 ;
	
	while (i < size(l))
	{
	   declaration d = l->array[i];

		j = In(name,getSignals(d));
		if ( j ne -1)
		   return getType(d);
		
		i++ ;
	}
	return _SIGNAL_TYPE_UNDEFINED ;
	
}

/******************************************************* 
 *
 * Return the signal_type t of a simple_signal
 *
 *******************************************************/

expfun signal_type getType(simple_signal s, declaration_list d)
{
	return getType(getN(getName(s)), d);
}

/******************************************************* 
 *
 * Return the range of a port name
 *
 *******************************************************/
expfun range getRange(text name, declaration_list l)
{
	size_t i;
	ssize_t j;
	
	i = 0 ;
	
	while (i < size(l))
	{
	   declaration d = l->array[i];

		j = In(name,getSignals(d));
		if ( j ne -1)
		   return getRnge(d);
		
		i++ ;
	}
	return NULL ;
	
}

expfun range getRange(vname name, declaration_list l)
{
	return getRange(getN(name), l);
}

