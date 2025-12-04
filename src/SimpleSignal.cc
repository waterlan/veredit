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
#include "simple_signal.h"
#include "simple_signal_list.h"
#include "signal_list.h"
#include "Signal.h"
#include "SignalList.h"
#include "DeclarationsList.h"
#include "ModuleItemList.h"
#include "Vname.h"


#include "text.h"
#include "search.h"

bool eqBeginEnd(range a, range b)
{
	if((getBegin(a) == getBegin(b))
	  && (getEnd(a) == getEnd(b)))
		return true;
	else
		return false;
}

expfun bool equal(text a, simple_signal b)
{
	return Eq(a,getName(b));
}

expfun bool equal(simple_signal a, simple_signal b)
{
   if (getCnst(a) == getCnst(b))
	{
		if (Eq(getName(a),getName(b)) eq true)
		{
			if(getBusIndex(a) == getBusIndex(b))
			{
				if ((hasRnge(a) eq false)&&(hasRnge(b) eq false))
					return true;
				else
					return eqBeginEnd(getRnge(a),getRnge(b));
			}
		}
	}
	return false ;
}

/* compare to simple_signals, but ignore index or range */
expfun bool equal2(simple_signal a, simple_signal b)
{
   if (getCnst(a) == getCnst(b))
		return Eq(getName(a),getName(b)) ;
	else
	   return(false);
}

expfun bool equal(simple_signal s, Signal sn)
{
	if(hasSimple(sn) eq true)
	   return equal(getSimple(sn),s);
	else
		if(hasCmpnd(sn) eq true)
		{
			if (In(s, getCmpnd(sn)) ne -1)
				return true;
			else return false;
		}
	return false;
}

/***********************************************************/

expfun bool isBus(simple_signal a)
{
	return hasRnge(a);
}

/***********************************************************
 *
 * Look up in the declarations if a signal is a bus or not.
 *
 ***********************************************************/
expfun bool isBus(simple_signal a, declaration_list d)
{
	if (getRange(getName(a), d) != NULL)
		return true;
	else
		return false;
}

/***********************************************************
 *
 * Look up in the module_item_list if a signal is a bus or not.
 *
 ***********************************************************/
expfun bool isBus(simple_signal a, module_item_list l)
{
	if (getRange(getName(a), l) != NULL)
		return true;
	else
		return false;
}
/***********************************************************/

expfun simple_signal_list expandSimple (simple_signal a)
{
	simple_signal_list l;
	simple_signal s ;
	int i, lower,upper ;
	range r;
	
	l = simple_signal_listNew();
	
	if (isBus(a) eq false)
	{
		add(a,l);
		return l;
	}
	else
	{
		r = getRnge(a);
		lower = getBegin(r);
		upper = getEnd(r);
		
		if (lower <= upper)
		{
			for (i= lower ; i <= upper ; i++)
			{
				s = simple_signalNew(-1,getName(a),i,NULL);
				add(s,l);
			}
		}
		else
		{
			for (i= lower ; i >= upper ; i--)
			{
				s = simple_signalNew(-1,getName(a),i,NULL);
				add(s,l);
			}
		}
		
		
	}
	return l;
}

/******************************************************* 
 *
 * Expand signal with bus-range.
 * e.g. A[2:3]   ->   {A[2], A[3]}
 *
 *******************************************************/
expfun signal_list expand (simple_signal a)
{
	signal_list l;
	Signal sig;
	simple_signal s ;
	int i, lower,upper ;
	range r;
	
	l = signal_listNew();
	
	if (isBus(a) eq false) // No expansion, just put simple_signal in signal_list.
	{
		sig = SignalNew(a,NULL);
		add(sig,l);
		return l;
	}
	else
	{
		r = getRnge(a);
		lower = getBegin(r);
		upper = getEnd(r);
		
		if (lower <= upper)
		{
			for (i= lower ; i <= upper ; i++)
			{
				s = simple_signalNew(-1,getName(a),i,NULL);
				sig = SignalNew(s,NULL);
				add(sig,l);
			}
		}
		else
		{
			for (i= lower ; i >= upper ; i--)
			{
				s = simple_signalNew(-1,getName(a),i,NULL);
				sig = SignalNew(s,NULL);
				add(sig,l);
			}
		}
		
	}
	return l;
}

