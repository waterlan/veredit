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

#include "continuous_assign.h"
#include "parameter_decl.h"
#include "declaration.h"
#include "module_item.h"

#include "SimpleSignal.h"


bool eqSimpleSignal(continuous_assign a, continuous_assign b)
{
   return equal(getSignal(a),getSignal(b));
}

bool eqSimpleSignal(parameter_decl a, parameter_decl b)
{
   return equal(getSignal(a),getSignal(b));
}

expfun bool eqModuleItem(continuous_assign a, module_item i)
{
	
	if ((a eq NULL) || (i eq NULL) || (hasAssignItem(i) eq false))
	   return false;
	
	return eqSimpleSignal(a, getAssignItem(i));
}

expfun bool eqModuleItem(parameter_decl a, module_item i)
{
	
	if ((a eq NULL) || (i eq NULL) || (hasParameter_declItem(i) eq false))
	   return false;
	
	return eqSimpleSignal(a, getParameter_declItem(i));
}


