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

#include "SignalList.h"
#include "SimpleSignalList.h"

#include "text.h"
#include "vname.h"
#include "portmap_element.h"
#include "simple_signal.h"
#include "simple_signal_list.h"
#include "signal_list.h"
#include "vname.h"

#include "SignalList.h"
#include "Signal_.h"
#include "HandleSet.h"

expfun bool eqPinName(portmap_element a, portmap_element b)
{
   return Eq(getPinName(a),getPinName(b));
}

expfun bool eqNetName(simple_signal s, portmap_element b)
{
   return InList(getSignals(b),s);
}

/******************************************************* 
 *
 * Rename a net in a module port connection.
 *
 *******************************************************/
expfun int renameNet(portmap_element p, simple_signal oldname, simple_signal newname, bool ignoreIndex, simple_signal_list excludes)
{  
	size_t i;
	int renames = 0;

	if ( In(getN(getPinName(p)), excludes) < 0)
	{
		if (hasSignals(p) eq true)
		{
			i = 0;
			while (i < size(getSignals(p)))
			{
			   Signal s = elementAt(i, getSignals(p));
			   renames = renames + renameNet(s, oldname, newname, ignoreIndex);
				++i;
			}
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
expfun void handle(portmap_element p)
{
	if (hasSignals(p) eq true)
	   handleSet(getSignals(p));
}

/******************************************************* 
 *
 * Make implicit bus-range explicit and expand.
 * e.g. 
 * wire [2:3] A;
 * .A(A)   ->  .A(A[2:3])  ->   .A({A[2], A[3]})
 *
 *******************************************************/
expfun void handle(portmap_element p, simple_signal s, range r)
{
	if (hasSignals(p) eq true)
	   handleSet(getSignals(p), s, r);
}


