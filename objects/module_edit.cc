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

#define module_edit_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "edit_list.h"
#include "module_edit.h"


expfun module_edit module_editNew(vname name = NULL,
                                  edit_list edtList = NULL,
                                  text pattern = NULL)
{
   module_edit m = (module_edit) malloc (sizeof(module_edit_struct));
   if (m != NULL)
   {
      m->name = name;
      m->edtList = edtList;
      m->pattern = pattern;
   }
   else
      malloc_error("module_editNew()");

   return m;
}
expfun bool eqSelfName(vname name,
                       module_edit m)
{
   if ((name == NULL) || (hasName(m) == false))
      return false;
   else if (eqSelf(name, getName(m)))
      return true;
   else
      return false;
}
expfun bool eqName(vname name,
                   module_edit m)
{
   if ((name == NULL) || (hasName(m) == false))
      return false;
   else if (Eq(name, getName(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfEdtList(edit_list edtList,
                          module_edit m)
{
   if ((edtList == NULL) || (hasEdtList(m) == false))
      return false;
   else if (eqSelf(edtList, getEdtList(m)))
      return true;
   else
      return false;
}
expfun bool eqEdtList(edit_list edtList,
                      module_edit m)
{
   if ((edtList == NULL) || (hasEdtList(m) == false))
      return false;
   else if (Eq(edtList, getEdtList(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfPattern(text pattern,
                          module_edit m)
{
   if ((pattern == NULL) || (hasPattern(m) == false))
      return false;
   else if (eqSelf(pattern, getPattern(m)))
      return true;
   else
      return false;
}
expfun bool eqPattern(text pattern,
                      module_edit m)
{
   if ((pattern == NULL) || (hasPattern(m) == false))
      return false;
   else if (Eq(pattern, getPattern(m)))
      return true;
   else
      return false;
}
expfun bool eqSelf(module_edit a,
                   module_edit b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(module_edit a,
               module_edit b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqName(getName(a), b) == false)
      return false;
   else if (eqEdtList(getEdtList(a), b) == false)
      return false;
   else if (eqPattern(getPattern(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getName(module_edit m)
{
   if (m != NULL)
      return m->name;
   else
      return NULL;
}
expfun edit_list getEdtList(module_edit m)
{
   if (m != NULL)
      return m->edtList;
   else
      return NULL;
}
expfun text getPattern(module_edit m)
{
   if (m != NULL)
      return m->pattern;
   else
      return NULL;
}
expfun module_edit setName(vname name,
                           module_edit m)
{
   if (m != NULL)
      m->name = name;
   return m;
}
expfun module_edit setEdtList(edit_list edtList,
                              module_edit m)
{
   if (m != NULL)
      m->edtList = edtList;
   return m;
}
expfun module_edit setPattern(text pattern,
                              module_edit m)
{
   if (m != NULL)
      m->pattern = pattern;
   return m;
}
expfun bool hasName(module_edit m)
{
   if (getName(m) != NULL)
      return true;
   else
      return false;
}
expfun bool hasEdtList(module_edit m)
{
   if (isEmpty(getEdtList(m)) == false)
      return true;
   else
      return false;
}
expfun bool hasPattern(module_edit m)
{
   if (getPattern(m) != NULL)
      return true;
   else
      return false;
}
expfun module_edit copy(module_edit src,
                        size_t level = 0)
{
   module_edit m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module_edit) malloc (sizeof(module_edit_struct));
      if (m != NULL)
      {
         if (level > 0)
         {
            m->name = copy(src->name, level - 1);
            m->edtList = copy(src->edtList, level - 1);
            m->pattern = textNew(src->pattern);
         }
         else
         {
            m->name = src->name;
            m->edtList = src->edtList;
            m->pattern = src->pattern;
         }
      }
      else
         malloc_error("copy()");

      return m;
   }
}
expfun module_edit deepCopy(module_edit src)
{
   module_edit m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module_edit) malloc (sizeof(module_edit_struct));
      if (m != NULL)
      {
         m->name = deepCopy(src->name);
         m->edtList = deepCopy(src->edtList);
         m->pattern = textNew(src->pattern);
      }
      else
         malloc_error("deepCopy()");

      return m;
   }
}
expfun void dump(text Offset,
                 module_edit m,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (m == NULL)
   {
      if (showEmpty)
      {
         fprintf(fp, "%s{\n", Offset);
         fprintf(fp, "%sNULL\n", new_Offset);
         fprintf(fp, "%s}\n", Offset);
      }
   }
   else
   {
      fprintf(fp, "%s{\n", Offset);

      if (hasName(m) || showEmpty)
      {
         fprintf(fp, "%svname name,\n", new_Offset);
         dump(new_Offset, m->name, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasEdtList(m) || showEmpty)
      {
         fprintf(fp, "%sedit_list edtList,\n", new_Offset);
         dump(new_Offset, m->edtList, fp, showEmpty);
         fprintf(fp, "%s\\end edit_list\n", new_Offset);
      }

      if (hasPattern(m) || showEmpty)
      {
         if (m->pattern ne NULL)
            fprintf(fp, "%stext pattern : %s\n", new_Offset, m->pattern);
         else if (showEmpty)
            fprintf(fp, "%stext pattern : NULL\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(module_edit m,
                 size_t level = 0)
{
   if (m ne NULL)
   {
      if (level > 0)
      {

         Free(m->name, level - 1);
         m->name = NULL;

         Free(m->edtList, level - 1);
         m->edtList = NULL;

         if (m->pattern ne NULL)
         {
            free((void *) m->pattern);
            m->pattern = NULL;
         }
      }


      free((void *) m);
   }
}
expfun void deepFree(module_edit m)
{
   if (m ne NULL)
   {

      deepFree(m->name);
      m->name = NULL;

      deepFree(m->edtList);
      m->edtList = NULL;

      if (m->pattern ne NULL)
      {
         free((void *) m->pattern);
         m->pattern = NULL;
      }

      free((void *) m);
   }
}
