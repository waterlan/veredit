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
#include "signal_list.h"
#include "Signal.h"
#include "SimpleSignal.h"

#include "text.h"
#include "HandleSet.h"

/******************************************************* 
 *
 * Rename a net.
 * Return the number of renames.
 *
 *******************************************************/
expfun int renameNet(Signal s, simple_signal oldname, simple_signal newname, bool ignoreIndex)
{
	size_t i;
	int renames = 0;

	if(hasSimple(s) eq true)
	{
	   if (ignoreIndex eq true)
		{
			simple_signal ss = getSimple(s);
			if (equal2(ss,oldname) eq true)
			{
				setName(vnameNew(textNew(getN(getName(newname)))),ss);
				setCnst(getCnst(newname),ss);
				++renames;
			}
		}
		else
		{
			if (equal(getSimple(s),oldname) eq true)
			{
				setSimple(copy(newname,true),s);
				++renames;
			}
		}
	}
	else
		if(hasCmpnd(s) eq true)
		{
			i = 0;
			while (i < size(getCmpnd(s)))
			{
				Signal s_rename = elementAt(i, getCmpnd(s));
		      renames = renames + renameNet(s_rename,oldname, newname, ignoreIndex);
				++i;
			}
		}
	
	return(renames);
}

/******************************************************* 
 *
 * Expand signals with bus-range.
 * e.g. A[2:3]   ->   {A[2], A[3]}
 *
 *******************************************************/
expfun void handle(Signal s)
{
	if(hasSimple(s) eq true)
	{
		simple_signal ss = getSimple(s);
		if(hasRnge(ss) eq true)
		{
			s->simple = NULL;
			setCmpnd(expand(ss),s);
		}
	}
	else
		if(hasCmpnd(s) eq true)
		   handleSet(getCmpnd(s));
}

/******************************************************* 
 *
 * Make implicit bus-range explicit and expand.
 * e.g. 
 * wire [2:3] A;
 * .A(A)   ->  .A(A[2:3])  ->   .A({A[2], A[3]})
 *
 *******************************************************/
expfun void handle(Signal s, simple_signal b, range r)
{
	if(hasSimple(s) eq true)
	{
		simple_signal ss = getSimple(s);
		if ((Eq(getName(ss),getName(b)) eq true) && (hasRnge(ss) eq false) && (hasBusIndex(ss) eq false))
		{
		   // same name, and signal has no range or bus index.
			setRnge(r,ss);  // set the range r to signal.
			s->simple = NULL;
			setCmpnd(expand(ss),s); // expand the range
		}
	}
	else
		if(hasCmpnd(s) eq true)
		   handleSet(getCmpnd(s), b, r);
}

