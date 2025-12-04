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

#define instance_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "vname.h"
#include "portmap.h"
#include "signal_list.h"
#include "instance.h"


expfun instance instanceNew(vname cellName = NULL,
                            vname instName = NULL,
                            portmap connections = NULL,
                            signal_list connections_by_order = NULL)
{
   instance i = (instance) malloc (sizeof(instance_struct));
   if (i != NULL)
   {
      i->cellName = cellName;
      i->instName = instName;
      i->connections = connections;
      i->connections_by_order = connections_by_order;
   }
   else
      malloc_error("instanceNew()");

   return i;
}
expfun bool eqSelfCellName(vname cellName,
                           instance i)
{
   if ((cellName == NULL) || (hasCellName(i) == false))
      return false;
   else if (eqSelf(cellName, getCellName(i)))
      return true;
   else
      return false;
}
expfun bool eqCellName(vname cellName,
                       instance i)
{
   if ((cellName == NULL) || (hasCellName(i) == false))
      return false;
   else if (Eq(cellName, getCellName(i)))
      return true;
   else
      return false;
}
expfun bool eqSelfInstName(vname instName,
                           instance i)
{
   if ((instName == NULL) || (hasInstName(i) == false))
      return false;
   else if (eqSelf(instName, getInstName(i)))
      return true;
   else
      return false;
}
expfun bool eqInstName(vname instName,
                       instance i)
{
   if ((instName == NULL) || (hasInstName(i) == false))
      return false;
   else if (Eq(instName, getInstName(i)))
      return true;
   else
      return false;
}
expfun bool eqSelfConnections(portmap connections,
                              instance i)
{
   if ((connections == NULL) || (hasConnections(i) == false))
      return false;
   else if (eqSelf(connections, getConnections(i)))
      return true;
   else
      return false;
}
expfun bool eqConnections(portmap connections,
                          instance i)
{
   if ((connections == NULL) || (hasConnections(i) == false))
      return false;
   else if (Eq(connections, getConnections(i)))
      return true;
   else
      return false;
}
expfun bool eqSelfConnections_by_order(signal_list connections_by_order,
                                       instance i)
{
   if ((connections_by_order == NULL) || (hasConnections_by_order(i) == false))
      return false;
   else if (eqSelf(connections_by_order, getConnections_by_order(i)))
      return true;
   else
      return false;
}
expfun bool eqConnections_by_order(signal_list connections_by_order,
                                   instance i)
{
   if ((connections_by_order == NULL) || (hasConnections_by_order(i) == false))
      return false;
   else if (Eq(connections_by_order, getConnections_by_order(i)))
      return true;
   else
      return false;
}
expfun bool eqSelf(instance a,
                   instance b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(instance a,
               instance b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqCellName(getCellName(a), b) == false)
      return false;
   else if (eqInstName(getInstName(a), b) == false)
      return false;
   else if (eqConnections(getConnections(a), b) == false)
      return false;
   else if (eqConnections_by_order(getConnections_by_order(a), b) == false)
      return false;
   else
      return true;
}
expfun vname getCellName(instance i)
{
   if (i != NULL)
      return i->cellName;
   else
      return NULL;
}
expfun vname getInstName(instance i)
{
   if (i != NULL)
      return i->instName;
   else
      return NULL;
}
expfun portmap getConnections(instance i)
{
   if (i != NULL)
      return i->connections;
   else
      return NULL;
}
expfun signal_list getConnections_by_order(instance i)
{
   if (i != NULL)
      return i->connections_by_order;
   else
      return NULL;
}
expfun instance setCellName(vname cellName,
                            instance i)
{
   if (i != NULL)
      i->cellName = cellName;
   return i;
}
expfun instance setInstName(vname instName,
                            instance i)
{
   if (i != NULL)
      i->instName = instName;
   return i;
}
expfun instance setConnections(portmap connections,
                               instance i)
{
   if (i != NULL)
      i->connections = connections;
   return i;
}
expfun instance setConnections_by_order(signal_list connections_by_order,
                                        instance i)
{
   if (i != NULL)
      i->connections_by_order = connections_by_order;
   return i;
}
expfun bool hasCellName(instance i)
{
   if (getCellName(i) != NULL)
      return true;
   else
      return false;
}
expfun bool hasInstName(instance i)
{
   if (getInstName(i) != NULL)
      return true;
   else
      return false;
}
expfun bool hasConnections(instance i)
{
   if (isEmpty(getConnections(i)) == false)
      return true;
   else
      return false;
}
expfun bool hasConnections_by_order(instance i)
{
   if (isEmpty(getConnections_by_order(i)) == false)
      return true;
   else
      return false;
}
expfun instance copy(instance src,
                     size_t level = 0)
{
   instance i;

   if (src == NULL)
      return NULL;
   else
   {
      i = (instance) malloc (sizeof(instance_struct));
      if (i != NULL)
      {
         if (level > 0)
         {
            i->cellName = copy(src->cellName, level - 1);
            i->instName = copy(src->instName, level - 1);
            i->connections = copy(src->connections, level - 1);
            i->connections_by_order = copy(src->connections_by_order, level - 1);
         }
         else
         {
            i->cellName = src->cellName;
            i->instName = src->instName;
            i->connections = src->connections;
            i->connections_by_order = src->connections_by_order;
         }
      }
      else
         malloc_error("copy()");

      return i;
   }
}
expfun instance deepCopy(instance src)
{
   instance i;

   if (src == NULL)
      return NULL;
   else
   {
      i = (instance) malloc (sizeof(instance_struct));
      if (i != NULL)
      {
         i->cellName = deepCopy(src->cellName);
         i->instName = deepCopy(src->instName);
         i->connections = deepCopy(src->connections);
         i->connections_by_order = deepCopy(src->connections_by_order);
      }
      else
         malloc_error("deepCopy()");

      return i;
   }
}
expfun void dump(text Offset,
                 instance i,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (i == NULL)
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

      if (hasCellName(i) || showEmpty)
      {
         fprintf(fp, "%svname cellName,\n", new_Offset);
         dump(new_Offset, i->cellName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasInstName(i) || showEmpty)
      {
         fprintf(fp, "%svname instName,\n", new_Offset);
         dump(new_Offset, i->instName, fp, showEmpty);
         fprintf(fp, "%s\\end vname\n", new_Offset);
      }

      if (hasConnections(i) || showEmpty)
      {
         fprintf(fp, "%sportmap connections,\n", new_Offset);
         dump(new_Offset, i->connections, fp, showEmpty);
         fprintf(fp, "%s\\end portmap\n", new_Offset);
      }

      if (hasConnections_by_order(i) || showEmpty)
      {
         fprintf(fp, "%ssignal_list connections_by_order,\n", new_Offset);
         dump(new_Offset, i->connections_by_order, fp, showEmpty);
         fprintf(fp, "%s\\end signal_list\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(instance i,
                 size_t level = 0)
{
   if (i ne NULL)
   {
      if (level > 0)
      {

         Free(i->cellName, level - 1);
         i->cellName = NULL;

         Free(i->instName, level - 1);
         i->instName = NULL;

         Free(i->connections, level - 1);
         i->connections = NULL;

         Free(i->connections_by_order, level - 1);
         i->connections_by_order = NULL;
      }


      free((void *) i);
   }
}
expfun void deepFree(instance i)
{
   if (i ne NULL)
   {

      deepFree(i->cellName);
      i->cellName = NULL;

      deepFree(i->instName);
      i->instName = NULL;

      deepFree(i->connections);
      i->connections = NULL;

      deepFree(i->connections_by_order);
      i->connections_by_order = NULL;

      free((void *) i);
   }
}
