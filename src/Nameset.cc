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

#include <fnmatch.h>
#include <string.h>

#include "structures.h"
#include "std_macro.h"
#include "veredit.h"

#include "text.h"
#include "search.h"
#include "nameset.h"

expfun bool eqInMatch(text a, text b)
{
   if ((fnmatch(a, b, 0) == 0) || (fnmatch(b, a, 0) == 0))
		return true;
	else
	   return false;
}

expfun ssize_t In(text name, nameset a)
{
	//extern bool Eq(text a, text b);
	//extern text elementAt(size_t index, nameset n);
      //extern size_t  size(nameset n);

	return Index(name, a, Eq, true, elementAt, size);
}

expfun size_t matchCount(text name, nameset a)
{
//	extern bool Eq(text a, text b);
//	extern text elementAt(size_t index, nameset n);
 //     extern size_t  size(nameset n);

	return matchCount(name, a, Eq, true, elementAt, size);
}


/************************************************
 *
 * nameNew(nameset names, text buffer, text base, int index)
 *
 * create a new name based on 'base' and 'index'
 * that is not in list 'names'.
 * output is stored in 'buffer'.
 *
 ************************************************/
expfun void nameNew(nameset names, rwtext buffer, text base, int index)
{
	int i;
	char basebuffer[VEREDIT_MAX_NAME_LENGTH] ;

	strncpy(basebuffer, base, sizeof(basebuffer)-50);
	if (basebuffer[0] == '\\') //escaped name
		basebuffer[strlen(basebuffer)-1] = 0;
	
	if (index ne -1)
		sprintf(buffer,"%s_%d_inst",basebuffer,index);
	else
		sprintf(buffer,"%s_inst",basebuffer);
	if (basebuffer[0] == '\\') //escaped name
		strcat (buffer, " ");

	i=0;
	while (In(buffer,names) ne -1)
	{
		if (index ne -1)
			sprintf(buffer,"%s_%d_inst_%d",basebuffer,index,i);
		else
			sprintf(buffer,"%s_inst_%d",basebuffer,i);
		if (basebuffer[0] == '\\') //escaped name
			strcat (buffer, " ");
		i++;
	}

	if (basebuffer[0] == '\\') //escaped name
		strcat (buffer, " ");

	add(textNew(buffer),names);
} 


