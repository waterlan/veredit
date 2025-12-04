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
#include <stdlib.h>

#include <fnmatch.h>

#include "structures.h"
#include "std_macro.h"

#include "vname.h"
#include "nameset.h"
#include "module.h"
#include "port_reference.h"
#include "port_expression.h"
#include "port.h"
#include "port_list.h"
#include "signal_type.h"
#include "variable_name.h"
#include "variable_list.h"
#include "declaration.h"
#include "declaration_list.h"
#include "signal_list.h"
#include "module_item.h"
#include "module_item_list.h"
#include "module_list.h"
#include "portmap_element.h"
#include "portmap.h"
#include "instance.h"
#include "instantiation_list.h"
#include "range.h"
#include "simple_signal.h"
#include "simple_signal_list.h"
#include "continuous_assign.h"
#include "assign_list.h"
#include "parameter_decl.h"
#include "parameter_decl_list.h"

#include "delete_module_statement.h"
#include "shell_statement.h"
#include "buffernet_statement.h"
#include "addport_statement.h"
#include "delport_statement.h"
#include "buffer_type.h"
#include "editport_type.h"
#include "editinst_type.h"
#include "editinst_statement.h"
#include "editassign_type.h"
#include "editassign_statement.h"
#include "editparameter_decl_type.h"
#include "editparameter_decl_statement.h"
#include "listInst_statement.h"
#include "edit_list.h"
#include "edit_element.h"
#include "module_edit.h"
#include "module_edit_list.h"
#include "translation_unit.h"

#include "text.h"
#include "search.h"
#include "file.h"
#include "HandleSet.h"

#include "SimpleSignal.h"
#include "Portmap_element.h"
#include "Portmap.h"
#include "DeclarationsList.h"
#include "ModuleItem.h"
#include "ModuleItemList.h"
#include "Instance.h"
#include "InstantiationList.h"
#include "Module.h"
#include "ModuleList.h"
#include "VerilogItemList.h"
#include "TranslationUnit.h"
#include "Vname.h"
#include "Vnode.h"


bool eqSimpleName(port a, port b)
{
   return Eq(getName(getPortReference(getPortExpression(a))), getName(getPortReference(getPortExpression(b))));
}

ssize_t In(port p, port_list l)
{
   extern bool eqSimpleName(port a, port b);
   return Index(p,l,eqSimpleName);
}

void handle(port p, port_list l, module m, bool silent)
{
   if (In(p,l) eq -1)
      add(p,l);
   else
	{
		if (silent eq false)
         fprintf(stdout,"veredit: WARNING: Duplicate port %s in module %s ignored.\n",getN(getName(getPortReference(getPortExpression(p)))), getN(getName(m)));
   }
}

void handle(variable_name s, module_item_list l, signal_type t, text name, range r, bool silent)
{
   declaration n;
   variable_list ns ;
   
   if (In(s,l,t) eq false)
   {
      ns = variable_listNew();
      add(s,ns);
      n = declarationNew(t,r,ns);
      add(n,l);
   } 
   else
	{
		if (silent eq false)
         fprintf(stdout,"veredit: WARNING: Duplicate declarion %s in module %s ignored.\n",getN(getName(s)), name);
   }
   
}

/*
void handle(declaration d, declaration_list l, module m)
{
   handleSet(getSignals(d),l,getType(d), getName(m),getRnge(d));
}*/

void handle(declaration d, module_item_list l, module m, bool silent)
{
   handleSet(getSignals(d),l,getType(d), getN(getName(m)),getRnge(d), silent);
}

// add a port to a module
// silent is used by 'pulluppin'
expfun void addPorts(addport_statement a, module m, bool silent )
{
   declaration_list d = getAddports(a);
   
   if (m == NULL)
      return;
   else
   {
       // create a port_list of the declaration_list d with getPortlist(d)
       // and add that port_list to the module port_list (only type input,output,inout).
       // See DeclarationList.cc
       handleSet(getPortlist(d),getPorts(m),m, silent);
       // Add declaration_list d to module declaration_list.
       handleSet(d,getItems(m),m, silent);
   }
}

void handle(port p, port_list l, text modulename)
{
   ssize_t i;
   
   if ( (i=In(p,l)) ne -1)
      remove((size_t)i,l); // shallow remove.
   else
   {
      fprintf(stdout,"veredit: WARNING: Port %s not found in portlist of module %s.\n",getN(getName(getPortReference(getPortExpression(p)))),modulename);
   }
}

bool equal(port p, variable_name s)
{
   return Eq(getName(getPortReference(getPortExpression(p))),getName(s));
}

ssize_t In(port p, variable_list l)
{
   extern bool equal(port p, variable_name s);
   return Index(p,l,equal);
}


// delete all nets
void delAllNets(module_item_list l)
{
   module_item mi;
   declaration d;
   signal_type st;
	size_t j;

	j = 0;
	while(j<size(l)) // walk through all module items
	{
		mi = l->array[j];
		if (hasDeclItem(mi) eq true)
		{
			d = getDeclItem(mi);
         st = getType(d);
		
         if ((isINPUT(st) eq false) &&
             (isOUTPUT(st) eq false) &&
             (isINOUT(st) eq false))
				setDeclItem(NULL,mi);  // remove complete declaration
		}
		j++;
	}
}

// delete ports
void handle(port p, module_item_list l, editport_type t, text modulename)
{
   variable_list s, sdl;
   variable_name sd;
   declaration d, dnew;
   module_item mi;
   signal_type st;
   
   size_t j;
	ssize_t i;
   int found;
   
      found = 0;
		j = 0;
   
      switch (t)
      {
      case _DELPORTS : // remove declaration of port
         j = 0;
         while(j<size(l)) // walk through all module items
         {
            mi = l->array[j];
            if (hasDeclItem(mi) eq true)
            {
               d = getDeclItem(mi);
               s = getSignals(d);
            
               i=In(p,s); // find port in variables list
            
               if ( i ne -1)
               {
                  found = 1;
                  if (size(s) eq 1)
                    setDeclItem(NULL,mi);  // remove complete declaration (has only one variable)
                  else if (size(s) > 1)
                    remove((size_t)i,s);    // remove port name from list of variables.
               }
            }
            j++;
         }
         break;
      case _RMPORTS :
         dnew = NULL;
         j = 0;
         while(j<size(l)) // walk through all declarations
         {
            mi = l->array[j];
            if (hasDeclItem(mi) eq true)
            {
               d = getDeclItem(mi);
               s = getSignals(d);
            
               i=In(p,s);
            
               if ( i ne -1) // port declaration found
               {
                  found = 1;
                  st = getType(d);
                  if ((isINPUT(st) eq true) ||
                      (isOUTPUT(st) eq true) ||
                      (isINOUT(st) eq true))
                  {
                     sdl = variable_listNew();
                     sd  = variable_nameNew(getName(getPortReference(getPortExpression(p))));
                     add (sd,sdl);
                     dnew = declarationNew(_WIRE, getRnge(d), sdl);
                  }

                  if (size(s) eq 1)
                    setDeclItem(NULL,mi);  // remove complete declaration (has only one variable)
                  else if (size(s) > 1)
                    remove((size_t)i,s);    // remove port name from list of variables.
               }
            }
            j++;
         }
         if (dnew eq NULL)
         {
            sdl = variable_listNew();
            sd  = variable_nameNew(getName(getPortReference(getPortExpression(p))));
            add (sd,sdl);
            dnew = declarationNew(_WIRE, NULL, sdl);
         }
         add (dnew,l); // add new wire declaration
		   break;
      case _DELNETS :
         j = 0;
         while(j<size(l)) // walk through all module items
         {
            mi = l->array[j];
            if (hasDeclItem(mi) eq true)
            {
               d = getDeclItem(mi);
               s = getSignals(d);
               st = getType(d);
            
               i=In(p,s); // find port in variables list
            
               if ( (i ne -1) &&
                    (isINPUT(st) eq false) &&
                    (isOUTPUT(st) eq false) &&
                    (isINOUT(st) eq false))
               {
                  found = 1;
                  if (size(s) eq 1)
                    setDeclItem(NULL,mi);  // remove complete declaration (has only one variable)
                  else if (size(s) > 1)
                    remove((size_t)i,s);    // remove port name from list of variables.
               }
            }
            j++;
         }
         break;
      default : j++;
         break;
      }
      if (found == 0)
         fprintf(stdout,"veredit: WARNING: Port/net %s not found in declaration list of module %s.\n",getN(getName(getPortReference(getPortExpression(p)))),modulename);
   
}

void delPorts(delport_statement dp, module m)
{
    port_list d;
    
   if (m == NULL)
      return;

    if (eqType(_DELNETS,dp) == true)  // delete nets
    {
       if (all(dp) eq true)
          delAllNets(getItems(m));
       else
       {
          d = getDelports(dp);  
          handleSet( d, getItems(m),getType(dp), getN(getName(m)));  // delete nets
       }
    }
    else  // delete ports or nets
    {
       if (all(dp) eq true)
       {
          d = copy(getPorts(m));   // copy pointers
          setSize(0,getPorts(m));
       }
       else
          d = getDelports(dp);  
   
      if (all(dp) eq false)
         handleSet( d, getPorts(m), getN(getName(m)));  // delete ports
      handleSet( d, getItems(m),getType(dp), getN(getName(m)));  // delete nets
    }
}


void handle(portmap_element p, portmap dest, text instancename)
{
   ssize_t i;
   
   if ( (i=In(p,dest)) ne -1)
      remove((size_t)i,dest);
   else
   {
      fprintf(stdout,"veredit: WARNING: Port %s not found in instanciation %s.\n",getN(getPinName(p)),instancename);
   }
   
}

void remove(portmap src, portmap dest, text instancename)
{
   handleSet(src, dest, instancename);
}

void remove(portmap src, portmap dest, vname instancename)
{
   handleSet(src, dest, getN(instancename));
}


/************************************************
 *
 * addInst(instantiation_list l, instance i, text modulename, bool keepmodname, bool modify)
 *
 * add instance to module_item_list.
 ************************************************/

expfun void addInst(module_item_list l, instance i, text modulename, bool keepmodname, bool modify)
{
   instance inst;
   
   inst = getInstance(i,l);
   
   if ( inst eq NULL)
   {
      if (modify eq false)
         add(i,l);
      else
      {
         fprintf(stdout,"veredit: WARNING: Instance %s not found in module %s.\n",getN(getInstName(i)),modulename);
      }
            
   }
   else
   {
      if ((Eq(getCellName(i),getCellName(inst)) eq false) && (keepmodname eq false))
      {
         setCellName(vnameNew(textNew(getN(getCellName(i)))),inst);
         fprintf(stdout,"veredit: INFO: cellName of instance %s of module %s changed to %s.\n",getN(getInstName(i)), modulename, getN(getCellName(i)));
      }
      add(getConnections(i),getConnections(inst));
   }
}

/************************************************
 *
 * addInst(module m, instance i, bool keepmodname, bool modify)
 *
 * add instance to module, or modify only.
 ************************************************/

expfun void addInst(module m, instance i, bool keepmodname, bool modify)
{
   module_item_list l;
   
   l = getItems(m);

   
   addInst(l, i, getN(getName(m)), keepmodname, modify);
   
   if ( Eq(getCellName(i),getName(m)) eq true)
      fprintf(stdout,"veredit: ERROR: Recursive module instanciation, instance %s in module %s.\n",getN(getInstName(i)),getN(getName(m)));

}

/************************************************
 *
 * delInst(module_item_list l, instance i)
 *
 * remove instance from module_item_list.
 * returns: 0 on success
 *          1 on fail
 ************************************************/

expfun int delInst(module_item_list l, instance i)
{
   instance inst;
   
   inst = getInstance(i,l);
   
   if ( inst ne NULL)
   {
      if ( hasConnections(i) eq false)
      {
         ssize_t j = In(i,l);
         remove((size_t)j,l);
      }
      else
        remove(getConnections(i),getConnections(inst),getInstName(i)) ;
      return 0;
   }
   else
   {
      return 1;
   }
}

/************************************************
 *
 * delInst(module m, instance i)
 *
 * remove instance from module.
 * returns: 0 on success
 *          1 on fail
 ************************************************/

expfun int delInst(module m, instance i)
{
   int j;
   module_item_list l;
   
   l = getItems(m);
   
   j = delInst(l,i);
   
   if ( j ne 0)
      fprintf(stdout,"veredit: WARNING: Instance %s not found in module %s.\n",getN(getInstName(i)),getN(getName(m)));

   return j;
}

void handle(instance i, module m, editinst_type t, bool keepmodname )
{
   
   switch (t)
   {
   case _ADDINST :
                  addInst(m,i,keepmodname,false);
                  break;
   case _MODINST :
                  addInst(m,i,keepmodname,true);
                  break;
   case _DELINST :
                  delInst(m,i);
                  break;
   default : break;
   }
   
}

void editInst(editinst_statement e, module m)
{
   if(m eq NULL) return;

   if( all(e) eq true)
     delAllInstances(m);
   
   handleSet(getEditinstances(e), m, getType(e), keepmodname(e));
}


/*
int In(continuous_assign a, assign_list l)
{
   extern bool eqSimpleSignal(continuous_assign a, continuous_assign b);
   return Index(a,l,eqSimpleSignal);
}
*/
/************************************************
 *
 * void addAssign(module m, continuous_assign a)
 *
 * add assign to module.
 ************************************************/

expfun void addAssign(module m, continuous_assign a)
{
   extern bool eqModuleItem(continuous_assign a, module_item i);
   ssize_t inst;
   module_item_list l;
   continuous_assign b;
   
   if (hasItems(m) eq false)
      return;
   else
      l = getItems(m);
   
   if ( (inst=Index(a, l, eqModuleItem)) eq -1)
   {
      add(a,l);
   }
   else
   {
      b = getAssignItem(l->array[inst]);
      setExpr(getExpr(a),b);
   }
}

/************************************************
 *
 * int delAssign(module m, continuous_assign a)
 *
 * remove assign from module.
 * returns: 0 on success
 *          1 on fail
 ************************************************/

expfun int delAssign(module m, continuous_assign a)
{
   extern bool eqModuleItem(continuous_assign a, module_item i);
   ssize_t inst;
   module_item_list l;
   
   l = getItems(m);

   if ( (inst=Index(a, l, eqModuleItem)) ne -1)
   {
      remove((size_t)inst,l);
      return 0;
   }
   else
   {
      fprintf(stdout,"veredit: WARNING: Assignment of signal %s not found in module %s.\n",getN(getName(getSignal(a))),getN(getName(m)));
      return 1;
   }
}

void handle(continuous_assign a, module m, editassign_type t )
{
   switch (t)
   {
   case _ADDASSIGN :
                  addAssign(m,a);
                  break;
   case _DELASSIGN :
                  delAssign(m,a);
                  break;
   default : break;
   }
}

/************************************************
 *
 * void addParameter_declaration(module m, parameter_decl a)
 *
 * add parameter declaration to module.
 ************************************************/

expfun void addParameter_declaration(module m, parameter_decl a)
{
   extern bool eqModuleItem(parameter_decl a, module_item i);
   ssize_t inst;
   module_item_list l;
   parameter_decl b;
   
   if (hasItems(m) eq false)
      return;
   else
      l = getItems(m);
   
   if ( (inst=Index(a, l, eqModuleItem)) eq -1)
   {
      add(a,l);
   }
   else
   {
      b = getParameter_declItem(l->array[inst]);
      setExpr(getExpr(a),b);
   }
}

/************************************************
 *
 * int delParameter_declaration(module m, parameter_decl a)
 *
 * remove parameter_declaration from module.
 * returns: 0 on success
 *          1 on fail
 ************************************************/

expfun int delParameter_declaration(module m, parameter_decl a)
{
   extern bool eqModuleItem(parameter_decl a, module_item i);
   ssize_t inst;
   module_item_list l;
   
   l = getItems(m);

   if ( (inst=Index(a, l, eqModuleItem)) ne -1)
   {
      remove((size_t)inst,l);
      return 0;
   }
   else
   {
      fprintf(stdout,"veredit: WARNING: Parameter declaration %s not found in module %s.\n",getN(getName(getSignal(a))),getN(getName(m)));
      return 1;
   }
}

void handle(parameter_decl a, module m, editparameter_decl_type t )
{
   switch (t)
   {
   case _ADDPARAMETERDECL :
                  addParameter_declaration(m,a);
                  break;
   case _DELPARAMETERDECL :
                  delParameter_declaration(m,a);
                  break;
   default : break;
   }
}


void editAssign(editassign_statement e, module m)
{
   if ((e eq NULL) || (m eq NULL)) return;

   if ((all(e) eq true) and (isDELASSIGN(getType(e)) eq true))
      delAllAssigns(m);
   else
      handleSet(getEditassigns(e), m, getType(e));
}

void editParameter_declaration(editparameter_decl_statement e, module m)
{
   if ((e eq NULL) || (m eq NULL)) return;

   if ((all(e) eq true) and (isDELPARAMETERDECL(getType(e)) eq true))
      delAllParameter_declarations(m);
   else
      handleSet(getEditparameter_decls(e), m, getType(e));
}



static void handle(instance i, simple_signal s, FILE *fp)
{
   if (hasConnections(i) eq true)
   {
      if (Index(s, getConnections(i), eqNetName) != -1)
      {
          fprintf(fp, "%s %s ();\n", getN(getCellName(i)),getN(getInstName(i)));
      }
   }
}

static void listInst(listInst_statement l, module m)
{
   FILE *fo ; 
   text outfile;

   if ((l eq NULL) || (m eq NULL)) return;

   outfile = concat(getN(getName(m)),"-",getN(getName(getNet(l))), ".instlist");
   fo = openW(outfile);

   if (hasInstances(m) eq true)
      handleSet(getInstances(m), getNet(l), fo);
   
   Close(fo);
}

void handle(instance i, module m, buffernet_statement b,nameset allinsts, simple_signal_list allnets, buffer_type t)
{
   if(hasInstances(m) eq true)
      bufferNet(getItems(m), i, b,allinsts,allnets, t);
}

void bufferNet(buffernet_statement b, module m)
{
   nameset allinsts;
   simple_signal_list allnets;
   
   if(m eq NULL) 
      return;
   else
   {
      allinsts = getInstNames(getItems(m));
      allnets = getSignals(getItems(m));
         
      handleSet(getEditinstances(b),m,b,allinsts,allnets, getType(b));
   }

}

void handle(edit_element e, translation_unit t, text name)
{
   module m;

   if ((e == NULL) || (t == NULL) || (name == NULL))
      return;

   m = getModule(name,t);

   if (m == NULL)
   {
      fprintf(stdout,"veredit: WARNING: Module %s not found.\n",name);
      return;
   }
   
   if(hasInsertObsOutputStat(e) eq true)
     insertObsOutputs(getInsertObsOutputStat(e), m,t);

   if(hasInsertObsInputStat(e) eq true)
     insertObsInputs(getInsertObsInputStat(e), m,t);

   if(hasTiecellStat(e) eq true)
     insertTiecell(getTiecellStat(e), m);

   if(hasDelModule(e) eq true)
   {
      // remove module from translation unit
      remove(name,getItems(t), empty(getDelModule(e)));
      // remove module from hierarchy tree
      // commented, because hierarchy is now build just before writing
      // the output netlist when option -top is used.
      //remove(name, getRootNode(t), empty(getDelModule(e)));
   }
   
   if(hasBufferNetStat(e) eq true)
      bufferNet(getBufferNetStat(e), m);

   if(hasBufferStat(e) eq true)
     bufferOutputs(getBufferStat(e), m,t);

   if(hasRemoveBufStat(e) eq true)
     removeBuffers(getRemoveBufStat(e), m,t);

   if(hasAddport(e) eq true)
     addPorts(getAddport(e), m, false);

   if(hasDelport(e) eq true)
     delPorts(getDelport(e), m);

   if(hasEditinst(e) eq true)
      editInst(getEditinst(e), m);

   if(hasEditassign(e) eq true)
      editAssign(getEditassign(e), m);

   if(hasEditparameter_decl(e) eq true)
      editParameter_declaration(getEditparameter_decl(e), m);

   if(hasListInstStat(e) eq true)
      listInst(getListInstStat(e), m);

   if(hasShellStat(e) eq true)
     shellModule(m, getShellName(getShellStat(e)), t);
   
   if(hasBufAssign(e) eq true)
     bufferAssigns(getBufAssign(e), m,t);

   if(hasPullupPin(e) eq true)
     pullupPins(getPullupPin(e), m,t);

}

void handle(module m, module_edit e, translation_unit t)
{
   if (fnmatch(getPattern(e), getN(getName(m)), 0) == 0)
      handleSet(getEdtList(e), t, getN(getName(m)));
}

void handle(module_edit e, translation_unit t)
{
   if(hasPattern(e) eq true)
      handleSet(getModules(t), e, t);
   else
      if(hasEdtList(e) eq true)
         handleSet(getEdtList(e), t, getN(getName(e)));
}

expfun void doEdits(translation_unit t)
{
   if (hasEdits(t) eq true)
      handleSet(getEdits(t), t);
} 
