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

#define module_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "port_list.h"
#include "module_item_list.h"
#include "vnode.h"
#include "module.h"


expfun module moduleNew(vname name = NULL,
                        port_list ports = NULL,
                        module_item_list items = NULL)
{
   module m = (module) malloc (sizeof(module_struct));
   if (m != NULL)
   {
      m->name = name;
      m->ports = ports;
      m->items = items;
      m->modNode = NULL;
   }
   else
      malloc_error("moduleNew()");

   return m;
}
expfun bool eqSelfName(vname name,
                       module m)
{
   if ((name == NULL) || (hasName(m) == false))
      return false;
   else if (eqSelf(name, getName(m)))
      return true;
   else
      return false;
}
expfun bool eqName(vname name,
                   module m)
{
   if ((name == NULL) || (hasName(m) == false))
      return false;
   else if (Eq(name, getName(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfPorts(port_list ports,
                        module m)
{
   if ((ports == NULL) || (hasPorts(m) == false))
      return false;
   else if (eqSelf(ports, getPorts(m)))
      return true;
   else
      return false;
}
expfun bool eqPorts(port_list ports,
                    module m)
{
   if ((ports == NULL) || (hasPorts(m) == false))
      return false;
   else if (Eq(ports, getPorts(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfItems(module_item_list items,
                        module m)
{
   if ((items == NULL) || (hasItems(m) == false))
      return false;
   else if (eqSelf(items, getItems(m)))
      return true;
   else
      return false;
}
expfun bool eqItems(module_item_list items,
                    module m)
{
   if ((items == NULL) || (hasItems(m) == false))
      return false;
   else if (Eq(items, getItems(m)))
      return true;
   else
      return false;
}
expfun bool eqSelfModNode(vnode modNode,
                          module m)
{
   if ((modNode == NULL) || (hasModNode(m) == false))
      return false;
   else if (eqSelf(modNode, getModNode(m)))
      return true;
   else
      return false;
}
expfun bool eqSelf(module a,
                   module b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(module a,
               module b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqName(getName(a), b) == false)
      return false;
   else if (eqPorts(getPorts(a), b) == false)
      return false;
   else if (eqItems(getItems(a), b) == false)
      return false;
   else if (eqSelfModNode(getModNode(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getName(module m)
{
   if (m != NULL)
      return m->name;
   else
      return NULL;
}
expfun port_list getPorts(module m)
{
   if (m != NULL)
      return m->ports;
   else
      return NULL;
}
expfun module_item_list getItems(module m)
{
   if (m != NULL)
      return m->items;
   else
      return NULL;
}
expfun vnode getModNode(module m)
{
   if (m != NULL)
      return m->modNode;
   else
      return NULL;
}
expfun module setName(vname name,
                      module m)
{
   if (m != NULL)
      m->name = name;
   return m;
}
expfun module setPorts(port_list ports,
                       module m)
{
   if (m != NULL)
      m->ports = ports;
   return m;
}
expfun module setItems(module_item_list items,
                       module m)
{
   if (m != NULL)
      m->items = items;
   return m;
}
expfun module setModNode(vnode modNode,
                         module m)
{
   if (m != NULL)
      m->modNode = modNode;
   return m;
}
expfun bool hasName(module m)
{
   if (getName(m) != NULL)
      return true;
   else
      return false;
}
expfun bool hasPorts(module m)
{
   if (isEmpty(getPorts(m)) == false)
      return true;
   else
      return false;
}
expfun bool hasItems(module m)
{
   if (isEmpty(getItems(m)) == false)
      return true;
   else
      return false;
}
expfun bool hasModNode(module m)
{
   if (getModNode(m) != NULL)
      return true;
   else
      return false;
}
expfun module copy(module src,
                   size_t level = 0)
{
   module m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module) malloc (sizeof(module_struct));
      if (m != NULL)
      {
         if (level > 0)
         {
            m->name = copy(src->name, level - 1);
            m->ports = copy(src->ports, level - 1);
            m->items = copy(src->items, level - 1);
            m->modNode = src->modNode;
         }
         else
         {
            m->name = src->name;
            m->ports = src->ports;
            m->items = src->items;
            m->modNode = src->modNode;
         }
      }
      else
         malloc_error("copy()");

      return m;
   }
}
expfun module deepCopy(module src)
{
   module m;

   if (src == NULL)
      return NULL;
   else
   {
      m = (module) malloc (sizeof(module_struct));
      if (m != NULL)
      {
         m->name = deepCopy(src->name);
         m->ports = deepCopy(src->ports);
         m->items = deepCopy(src->items);
         m->modNode = src->modNode;
      }
      else
         malloc_error("deepCopy()");

      return m;
   }
}
expfun void dump(text Offset,
                 module m,
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

      if (hasPorts(m) || showEmpty)
      {
         fprintf(fp, "%sport_list ports,\n", new_Offset);
         dump(new_Offset, m->ports, fp, showEmpty);
         fprintf(fp, "%s\\end port_list\n", new_Offset);
      }

      if (hasItems(m) || showEmpty)
      {
         fprintf(fp, "%smodule_item_list items,\n", new_Offset);
         dump(new_Offset, m->items, fp, showEmpty);
         fprintf(fp, "%s\\end module_item_list\n", new_Offset);
      }

      if (hasModNode(m) || showEmpty)
         fprintf(fp, "%svnode modNode : %p (reference)\n", new_Offset, m->modNode);

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(module m,
                 size_t level = 0)
{
   if (m ne NULL)
   {
      if (level > 0)
      {

         Free(m->name, level - 1);
         m->name = NULL;

         Free(m->ports, level - 1);
         m->ports = NULL;

         Free(m->items, level - 1);
         m->items = NULL;
      }


      free((void *) m);
   }
}
expfun void deepFree(module m)
{
   if (m ne NULL)
   {

      deepFree(m->name);
      m->name = NULL;

      deepFree(m->ports);
      m->ports = NULL;

      deepFree(m->items);
      m->items = NULL;

      free((void *) m);
   }
}
