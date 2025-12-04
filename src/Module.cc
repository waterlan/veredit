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
#include "veredit.h"

#include "nameset.h"

#include "addport_statement.h"
#include "vname.h"
#include "expression.h"
#include "name_list.h"
#include "pullup_pin_statement.h" 
#include "bufassigns_statement.h"
#include "insertObsInput_statement.h"
#include "insertObsOutput_statement.h"
#include "tiecell_statement.h"
#include "remove_buf_statement.h"
#include "buffer_statement.h"
#include "simple_signal.h"
#include "simple_signal_list.h"
#include "signal_type.h"
#include "signal_list.h"
#include "Signal.h"
#include "portmap.h"
#include "portmap_element.h"
#include "variable_name.h"
#include "variable_list.h"
#include "instance.h"
#include "module.h"
#include "port_reference.h"
#include "port_expression.h"
#include "port.h"
#include "port_list.h"
#include "module_item.h"
#include "module_item_list.h"
#include "continuous_assign.h"
#include "assign_list.h"
#include "parameter_decl.h"
#include "parameter_decl_list.h"
#include "declaration.h"
#include "declaration_list.h"
#include "instantiation_list.h"
#include "translation_unit.h"
#include "vnode.h"
#include "hierarchy.h"

#include "text.h"
#include "search.h"

#include "Vnode.h"
#include "doEdits.h"
#include "Vname.h"
#include "Nameset.h"
#include "SimpleSignal.h"
#include "SimpleSignalList.h"
#include "DeclarationsList.h"
#include "ModuleItemList.h"
#include "Module.h"
#include "Instance.h"
#include "InstantiationList.h"
#include "SignalList.h"
#include "TranslationUnit.h"
#include "HandleSet.h"


expfun bool equal(text name, module m)
{
   return Eq(name, getName(m));
}   

expfun bool isLeafCell(module m)
{
   if (hasInstances(m) eq true)
      return false;
   else
      return true;
}

expfun bool Check(module m, translation_unit t)
{
 //  fprintf(stdout, "Checking module %s ...\n", getName(m));
   return Check(getInstances(m), getModuleEdit(m, t));
}      

expfun bool isParent(module child, module parent)
{
   return isInstance(child,getInstances(parent));
}

/* expfun declaration_list getDeclarations_list(port_list p, module m)
{
   return getDeclarations_list(p, getDeclarations(getItems(m)));
}
*/

expfun void delAllAssigns(module m)
{
   module_item_list l;
   module_item mi;
   size_t i;

   if (hasItems(m) eq false)
      return;
   else
   {
      l = getItems(m);

      i = 0;
      while (i < size(l))
      {
         mi = l->array[i];
         if (hasAssignItem(mi) eq true)
            //setAssignItem(NULL,mi);
            remove(i, l);
         else
            i++;
      }
   }
}

expfun void delAllParameter_declarations(module m)
{
   module_item_list l;
   module_item mi;
   size_t i;

   if (hasItems(m) eq false)
      return;
   else
   {
      l = getItems(m);

      i = 0;
      while (i < size(l))
      {
         mi = l->array[i];
         if (hasParameter_declItem(mi) eq true)
            //setParameter_declItem(NULL,mi);
            remove(i, l);
         else
            i++;
      }
   }
}

expfun void delAllInstances(module m)
{
   module_item_list l;
   module_item mi;
   size_t i;

   if (hasItems(m) eq false)
      return;
   else
   {
      l = getItems(m);

      i = 0;
      while (i < size(l))
      {
         mi = l->array[i];
         if (hasInstanceItem(mi) eq true)
            //setInstanceItem(NULL,mi);
            remove(i, l);
         else
            i++;
      }
   }
}

/******************************************************* 
 *
 * Return  assign_list
 *
 *******************************************************/

expfun assign_list getAssigns(module m)
{
   if (m != NULL)
   {
      return getAssigns(getItems(m));
   }
   else
      return NULL;
}

/******************************************************* 
 *
 * Return  parameter_decl_list
 *
 *******************************************************/

expfun parameter_decl_list getParameter_declarations(module m)
{
   if (m != NULL)
   {
      return getParameter_declarations(getItems(m));
   }
   else
      return NULL;
}

/******************************************************* 
 *
 * Return  declarations_list
 *
 *******************************************************/

expfun declaration_list getDeclarations(module m)
{
   if (m != NULL)
   {
      return getDeclarations(getItems(m));
   }
   else
      return NULL;
}

expfun declaration_list getPortDeclarations(module m)
{
   if (m != NULL)
   {
      return getPortDeclarations(getItems(m));
   }
   else
      return NULL;
}

expfun declaration_list getNetDeclarations(module m)
{
   if (m != NULL)
   {
      return getNetDeclarations(getItems(m));
   }
   else
      return NULL;
}

/******************************************************* 
 *
 * Return  instantiation_list
 *
 *******************************************************/

expfun instantiation_list getInstances(module m)
{
   if (m != NULL)
   {
      return getInstances(getItems(m));
   }
   else
      return NULL;
}

/******************************************************* 
 *
 * Return all declarations of signal_type t as a
 * simple_signal_list.
 *
 *******************************************************/
expfun simple_signal_list getSignals(module m, signal_type t)
{
   return getSignals(getDeclarations(getItems(m)), t);
}

/******************************************************* 
 *
 * Return name of first declaration of signal_type t as a
 * text.
 *
 *******************************************************/
expfun text getSignal(module m, signal_type t)
{
   simple_signal_list l = getSignals(m, t);
   if (size(l) > 0)
      return getN(getName(l->array[0]));
   else
      return NULL;
}

/******************************************************* 
 *
 * Return the signal_type t of a port name
 *
 *******************************************************/

expfun signal_type getType(text name, module m)
{
   return getType(name, getItems(m));
}

/******************************************************* 
 *
 * Return the signal_type t of a simple_signal
 *
 *******************************************************/

expfun signal_type getType(simple_signal s, module m)
{
   return getType(getN(getName(s)), m);
}

/***********************************************************/


void handle(instance i, simple_signal s, instantiation_list new_il)
{
   instance new_i;
   
   
   new_i = getSignals(i,s);
   
   if(hasConnections(new_i) eq true)
      add(new_i, new_il);
}

void handle(simple_signal s, instantiation_list i, instantiation_list new_il)
{
   handleSet(i,s,new_il);
}

/******************************************************* 
 *
 * Returns number of inputs output is connected to
 * If returnvalue is > 0, output is reentrant.
 *
 *******************************************************/
int reentrant(simple_signal output, module m, translation_unit t)
{
   int nr;
   signal_type s_input;
   instantiation_list i;
   
   s_input = parseSignal_type("_INPUT");
   i = instantiation_listNew();
   
   // find instances portmaps connected to output => instantiation_list i
   
   handle(output,getInstances(m),i);
   
   // tel het aantal inputs
   
   nr = count(i,output,s_input,t);
   
   return nr;
}

expfun instance bufferNew(simple_signal inputnet, simple_signal outputnet, text instname, text bufferinput, text bufferoutput, text buffername)
{
   instance newbuffer ;
   portmap newportmap ;
   portmap_element newportmap_element ;
   signal_list newsignal_list ;
   Signal newSignal ;
   
   newbuffer = instanceNew();
   newportmap = portmapNew();
   
   // output
   
   newsignal_list = signal_listNew();
   newSignal = SignalNew(copy(outputnet,true),NULL);
   
   add(newSignal,newsignal_list);
   newportmap_element = portmap_elementNew(vnameNew(textNew(bufferoutput)),newsignal_list);
   add(newportmap_element, newportmap);
   
   // input
   
   newsignal_list = signal_listNew();
   newSignal = SignalNew(copy(inputnet,true),NULL);
   
   add(newSignal,newsignal_list);
   newportmap_element = portmap_elementNew(vnameNew(textNew(bufferinput)),newsignal_list);
   add(newportmap_element, newportmap);
   
   setConnections(newportmap,newbuffer);
   setCellName(vnameNew(textNew(buffername)),newbuffer);
   setInstName(vnameNew(textNew(instname)),newbuffer);
   
   return newbuffer;

}

expfun instance obsNew(simple_signal inputnet, simple_signal outputnet, text instname, insertObsOutput_statement is)
{
   text obsinput, obsoutput, obsname;
   instance newobs ;
   portmap newportmap ;
   portmap_element newportmap_element ;
   signal_list newsignal_list ;
   Signal newSignal ;
   
   obsinput = getN(getInputName(is));
   obsoutput = getN(getOutputName(is));
   obsname = getN(getModuleName(is));
   
   newobs = instanceNew();
   newportmap = portmapNew();
   
   // output
   
   newsignal_list = signal_listNew();
   newSignal = SignalNew(copy(outputnet,true),NULL);
   
   add(newSignal,newsignal_list);
   newportmap_element = portmap_elementNew(vnameNew(textNew(obsoutput)),newsignal_list);
   add(newportmap_element, newportmap);
   
   // input
   
   newsignal_list = signal_listNew();
   newSignal = SignalNew(copy(inputnet,true),NULL);
   
   add(newSignal,newsignal_list);
   newportmap_element = portmap_elementNew(vnameNew(textNew(obsinput)),newsignal_list);
   add(newportmap_element, newportmap);
   
   // others
   
   append(deepCopy(getOtherPins(is)), newportmap);
   
   setConnections(newportmap,newobs);
   setCellName(vnameNew(textNew(obsname)),newobs);
   setInstName(vnameNew(textNew(instname)),newobs);
   
   return newobs;

}
expfun instance obsNew(simple_signal inputnet, simple_signal outputnet, text instname, insertObsInput_statement is)
{
   text obsinput, obsoutput, obsname;
   instance newobs ;
   portmap newportmap ;
   portmap_element newportmap_element ;
   signal_list newsignal_list ;
   Signal newSignal ;
   
   obsinput = getN(getInputName(is));
   obsoutput = getN(getOutputName(is));
   obsname = getN(getModuleName(is));
   
   newobs = instanceNew();
   newportmap = portmapNew();
   
   // output
   
   newsignal_list = signal_listNew();
   newSignal = SignalNew(copy(outputnet,true),NULL);
   
   add(newSignal,newsignal_list);
   newportmap_element = portmap_elementNew(vnameNew(textNew(obsoutput)),newsignal_list);
   add(newportmap_element, newportmap);
   
   // input
   
   newsignal_list = signal_listNew();
   newSignal = SignalNew(copy(inputnet,true),NULL);
   
   add(newSignal,newsignal_list);
   newportmap_element = portmap_elementNew(vnameNew(textNew(obsinput)),newsignal_list);
   add(newportmap_element, newportmap);
   
   // others
   
   append(deepCopy(getOtherPins(is)), newportmap);
   
   setConnections(newportmap,newobs);
   setCellName(vnameNew(textNew(obsname)),newobs);
   setInstName(vnameNew(textNew(instname)),newobs);
   
   return newobs;

}

/*************************************************/

void bufferOutput(simple_signal output, module m, text bufferinput, text bufferoutput, text buffername, buffer_statement b, int nr, simple_signal_list allnets, nameset allinsts)
{
   simple_signal newnetname;
   instance newbuffer ;
   text outputname ;
   char buffer[VEREDIT_MAX_NAME_LENGTH];

   outputname = getN(getName(output));
         
   if (In(output,getExcludes(b)) ne -1)
   {
      if (hasBusIndex(output) eq true)
         fprintf(stdout,"veredit: reentrant output %s[%d], %d input(s), Excluded\n",outputname,getBusIndex(output), nr);
      else
         fprintf(stdout,"veredit: reentrant output %s, %d input(s), Excluded\n",outputname, nr);
   }
   else
   {
      newnetname = simple_signalNew();

      fprintf(stdout,"veredit: reentrant output %s",outputname);
      if (hasBusIndex(output) eq true)
         fprintf(stdout,"[%d]",getBusIndex(output));
      fprintf(stdout,", %d input(s)\n", nr);

      nameNew(allnets, buffer, outputname, getBusIndex(output));
   
      setName(vnameNew(textNew(buffer)),newnetname);
//    setRnge(getRnge(output),newnetname);
//    setBusIndex(getBusIndex(output),newnetname);
      renameNet(getItems(m),output,newnetname,false,NULL);
      
      nameNew(allinsts, buffer, outputname, getBusIndex(output));
      
      newbuffer = bufferNew(newnetname,output,buffer,bufferinput,bufferoutput,buffername);
   
      add(newbuffer,getItems(m));
   }

}

/*************************************************/

void addWire(module m, simple_signal s)
{
   module_item_list l;
   signal_type s_wire;
   declaration d;
   variable_name sd;
   variable_list sdl;
   
   l = getItems(m);
   
   sdl = variable_listNew();
   sd = variable_nameNew(getName(s));
   
   add(sd,sdl);
   s_wire = parseSignal_type("_WIRE");
   d = declarationNew(s_wire,getRnge(s),sdl);
   
   add(d,l);
   
}

/***********************************************************
 *
 * Look up in the declarations of a module if a signal is a bus or not.
 *
 ***********************************************************/
expfun bool isBus(simple_signal s, module m)
{
   return (isBus(s, getItems(m)));
}

/******************************************************* 
 *
 * Return the range of a port name
 *
 *******************************************************/
expfun range getRange(text name, module m)
{
   return (getRange(name, getItems(m)));
}

expfun range getRange(vname name, module m)
{
   return getRange(getN(name), m);
}
/****************************************************************************
 Insert one observe module at an output pin.
 ****************************************************************************/
void insertObsOutput(simple_signal output, module m, insertObsOutput_statement is, simple_signal_list allnets, nameset allinsts)
{
   simple_signal newnetname;
   instance newobs ;
   text outputname ;
   char obscell[VEREDIT_MAX_NAME_LENGTH];
   
   if (isBus(output, m) eq true)
   {
      // the signal is declared as a bus.
      // Make implicit bus-ranges of the bus in the port connections explicit and expand.
      expandSignals(getItems(m), output, getRange(getName(output),m));
   }

   outputname = getN(getName(output));
         
   newnetname = simple_signalNew();

   fprintf(stdout,"veredit: obs output %s",outputname);
   if (hasBusIndex(output) eq true)
      fprintf(stdout,"[%d]",getBusIndex(output));
   fprintf(stdout,"\n");

   nameNew(allnets, obscell, outputname, getBusIndex(output));
   
   setName(vnameNew(textNew(obscell)),newnetname);
   renameNet(getItems(m),output,newnetname,false,NULL);
   
   nameNew(allinsts, obscell, outputname, getBusIndex(output));
   
   newobs = obsNew(newnetname,output,obscell,is);
   
   add(newobs,getItems(m));

}

/****************************************************************************
 Insert one observe module at an input pin.
 ****************************************************************************/
void insertObsInput(simple_signal input, module m, insertObsInput_statement is, simple_signal_list allnets, nameset allinsts)
{
   simple_signal newnetname;
   instance newobs ;
   text inputname ;
   char obscell[VEREDIT_MAX_NAME_LENGTH];

   if (isBus(input, m) eq true)
   {
      // the signal is declared as a bus.
      // Make implicit bus-ranges of the bus in the port connections explicit and expand.
      expandSignals(getItems(m), input, getRange(getName(input),m));
   }

   inputname = getN(getName(input));
         
   newnetname = simple_signalNew();

   fprintf(stdout,"veredit: obs input %s",inputname);
   if (hasBusIndex(input) eq true)
      fprintf(stdout,"[%d]",getBusIndex(input));
   fprintf(stdout,"\n");

   nameNew(allnets, obscell, inputname, getBusIndex(input));
   
   setName(vnameNew(textNew(obscell)),newnetname);
   renameNet(getItems(m),input,newnetname,false,NULL);
   
   nameNew(allinsts, obscell, inputname, getBusIndex(input));
   
   newobs = obsNew(input,newnetname,obscell,is);
   
   add(newobs,getItems(m));

}


/****************************************************************************
 Insert observe modules at an output pins.
 ****************************************************************************/
expfun void insertObsOutputs(insertObsOutput_statement is, module m, translation_unit t)
{
   size_t index, j;
   simple_signal output;
   simple_signal_list outputs, allnets;
   simple_signal_list busoutputs;
   simple_signal busbitoutput;
   nameset allinsts;
   //text obsname ;
   //module obsmodule ;
   
   if(m eq NULL) return;
   fprintf(stdout,"veredit: INSERTOBSOUTPUT module %s.\n", getN(getName(m)));

   //obsname = getN(getModuleName(is));
   //obsmodule = getModule(obsname,t);
   
   expandSignals(getItems(m));

   allnets = getSignals(getItems(m));   // store all nets
   
   allinsts = getInstNames(getItems(m));   // store all instance names

   outputs = getNets(is);

   index = 0;
   
   while (index < size(outputs))
   {
      output = outputs->array[index];

      if ((isBus(output) eq false) && (hasBusIndex(output) eq false) && (isBus(output,m)eq true))
      // no bus range or index specified, but it is a bus.
         setRnge(getRange(getName(output),m),output);  // copy the range from the declaration

      if (isBus(output) eq false)
      {
         insertObsOutput(output,m,is,allnets,allinsts);
      }
      else
      {
         busoutputs = expandSimple(output);
         j = 0;
         while (j < size(busoutputs))
         {
            busbitoutput = busoutputs->array[j];
            insertObsOutput(busbitoutput,m,is,allnets,allinsts);
            ++j;
         }
      }
      index++;
   }
}
/****************************************************************************
 Insert observe modules at an input pins.
 ****************************************************************************/
expfun void insertObsInputs(insertObsInput_statement is, module m, translation_unit t)
{
   size_t index, j;
   simple_signal input;
   simple_signal_list inputs, allnets;
   simple_signal_list businputs;
   simple_signal busbitinput;
   nameset allinsts;
   //text obsname ;
   //module obsmodule ;
   
   if(m eq NULL) return;
   fprintf(stdout,"veredit: INSERTOBSINPUT module %s.\n", getN(getName(m)));

   //obsname = getN(getModuleName(is));
   //obsmodule = getModule(obsname,t);
   
   expandSignals(getItems(m));

   allnets = getSignals(getItems(m));   // store all nets
   
   allinsts = getInstNames(getItems(m));   // store all instance names

   inputs = getNets(is); // all inputs that will get an observation module.

   index = 0;
   
   while (index < size(inputs))
   {
      input = inputs->array[index];

      if ((isBus(input) eq false) && (hasBusIndex(input) eq false) && (isBus(input,m)eq true))
      // no bus range or index specified, but it is a bus.
         setRnge(getRange(getName(input),m),input);  // copy the range from the declaration

      if (isBus(input) eq false)
      {
         insertObsInput(input,m,is,allnets,allinsts);
      }
      else
      {
         businputs = expandSimple(input);
         j = 0;
         while (j < size(businputs))
         {
            busbitinput = businputs->array[j];
            insertObsInput(busbitinput,m,is,allnets,allinsts);
            ++j;
         }
      }
      index++;
   }
}

/****************************************************************************
 ****************************************************************************/

void bufferOutputBus(simple_signal output, module m, text bufferinput, text bufferoutput, text buffername, buffer_statement b, int nr, simple_signal_list allnets, nameset allinsts)
{
   simple_signal newnetname, busoutput, busbitoutput;
   simple_signal_list busoutputs;
   instance newbuffer ;
   text outputname ;
   char buffer[VEREDIT_MAX_NAME_LENGTH];
   char buffer_instname[VEREDIT_MAX_NAME_LENGTH];
   size_t j;

   outputname = getN(getName(output));
   busoutput = simple_signalNew(-1,getName(output),-1,NULL);
   
   if (In(busoutput,getExcludes(b)) ne -1)
      fprintf(stdout,"veredit: reentrant output bus %s, %d input(s), Excluded\n",outputname, nr);
   else
   {
      newnetname = simple_signalNew();

      fprintf(stdout,"veredit: reentrant output bus %s",outputname);
      fprintf(stdout,", %d input(s)\n", nr);

      nameNew(allnets, buffer, outputname, -1);
   
      setName(vnameNew(textNew(buffer)),newnetname);

      renameNet(getItems(m),busoutput,newnetname,true,NULL);
      
      setRnge(getRnge(output),newnetname);
      addWire(m,newnetname);
      setRnge(NULL,newnetname);
   
      
      j = 0;
      busoutputs = expandSimple(output);
      while (j < size(busoutputs))
      {
         busbitoutput = busoutputs->array[j];

         newnetname = simple_signalNew();
         setName(vnameNew(textNew(buffer)),newnetname);
         setBusIndex(getBusIndex(busbitoutput),newnetname);

   //    renameNet(getItems(m),busbitoutput,newnetname,false,NULL);
         
         nameNew(allinsts, buffer_instname, outputname, -1);
         newbuffer = bufferNew(newnetname,busbitoutput,buffer_instname,bufferinput,bufferoutput,buffername);
   
         add(newbuffer,getItems(m));
         j++;
      }
      
      
   }

}

/******************************************************* 
 *
 * Buffer the outputs
 *
 *******************************************************/
expfun void bufferOutputs(buffer_statement b, module m, translation_unit t)
{
   signal_type s_output;
   signal_type s_input;
   simple_signal_list outputs, allnets;
   size_t index ;
   int nr ;
   nameset allinsts;

   simple_signal output ;
   size_t j;
   simple_signal busoutput;
   simple_signal busbitoutput;
   simple_signal_list busoutputs;
   
   text buffername, bufferinput, bufferoutput ;
   module buffermodule ;
   
   if(m eq NULL) return;

   fprintf(stdout,"veredit: BUFFEROUTPUTS module %s.\n", getN(getName(m)));

   buffername = getN(getBufferName(b));
   buffermodule = getModule(buffername,t);
   
   if (buffermodule == NULL)
   {
      fprintf(stdout,"veredit: ERROR: Declaration of buffer module %s not found.\n",buffername);
      return;
   }


   
   s_output = parseSignal_type("_OUTPUT");
   s_input = parseSignal_type("_INPUT");
   
   if ((bufferinput = getSignal(buffermodule,s_input)) == NULL)
   {
      fprintf(stdout,"veredit: ERROR: Inputpin of buffer module %s not found.\n",buffername);
      return;
   }
   if ((bufferoutput = getSignal(buffermodule,s_output)) == NULL)
   {
      fprintf(stdout,"veredit: ERROR: Outputpin of buffer module %s not found.\n",buffername);
      return;
   }
   

   expandSignals(getItems(m));

   allnets = getSignals(getItems(m));   // store all nets
   
   allinsts = getInstNames(getItems(m));   // store all instance names

   // find outputs
   
   outputs = getSignals(getDeclarations(getItems(m)),s_output);
   
   index = 0;
   
   while (index < size(outputs))
   {
      output = outputs->array[index];
      
      if (isBus(output) eq false)
         {
            if ((nr = reentrant(output, m, t)) > 0)
               bufferOutput(output, m, bufferinput, bufferoutput, buffername,b,nr,allnets,allinsts);
         }
      
      else
      {
         busoutput = simple_signalNew(-1,getName(output),-1,NULL);
         if ((nr = reentrant(busoutput, m, t)) > 0)
         {
            bufferOutputBus(output, m, bufferinput, bufferoutput, buffername,b,nr,allnets,allinsts);
         }
         else  // check every single busbit
         {
            j = 0;
            busoutputs = expandSimple(output);
            while (j < size(busoutputs))
            {
               busbitoutput = busoutputs->array[j];
               if ((nr = reentrant(busbitoutput, m, t)) > 0)
                  bufferOutput(busbitoutput, m, bufferinput, bufferoutput, buffername,b,nr,allnets,allinsts);
               j++;
            }
         }
      
      }
      index++;
   }
   
}


/*
  instance tieNew(simple_signal outputnet, text instname, tiecell_statement ts)
  Create a new TIECELL
  Returns: an instance
 */
instance tieNew(simple_signal outputnet, text instname, tiecell_statement ts)
{
   text tieoutput, tiename;
   instance newtie ;
   portmap newportmap ;
   portmap_element newportmap_element ;
   signal_list newsignal_list ;
   Signal newSignal ;
   
      tieoutput = getN(getOutputName(ts));
      tiename   = getN(getModuleName(ts));
      
      newtie     = instanceNew();
      newportmap = portmapNew();
      
      // output
      
      newsignal_list = signal_listNew();
      newSignal = SignalNew(outputnet, NULL);
      
      add(newSignal,newsignal_list);
      newportmap_element = portmap_elementNew(vnameNew(textNew(tieoutput)),newsignal_list);
      add(newportmap_element, newportmap);
      
      // others
      
      append(deepCopy(getOtherPins(ts)), newportmap);
   
      setConnections(newportmap,newtie);
      setCellName(vnameNew(textNew(tiename)),newtie);
      setInstName(vnameNew(textNew(instname)),newtie);
      
      return newtie;

}

expfun void insertTiecell(tiecell_statement t, module m)
{
   
   simple_signal_list allnets, tienets;
   simple_signal n, outputnet;
   nameset allinsts;
   size_t index;
	ssize_t i;
   int tie_added;
   char tiecell_instname[VEREDIT_MAX_NAME_LENGTH];
   char tiecell_netname[VEREDIT_MAX_NAME_LENGTH];
   instance newtie;

   if((t == NULL) || (m == NULL))
      return;

   allnets = getSignals(getItems(m));   // store all nets of the module
   tienets = getNets(t);                    // the nets to tie.

   // create a new netname based on the tiecell module name.
   nameNew(allnets, tiecell_netname, concat(getN(getModuleName(t)),"_tienet"), -1);
   outputnet = simple_signalNew();
   setName(vnameNew(textNew(tiecell_netname)), outputnet);

   tie_added = 0;
   index = 0;
   while (index < size(tienets))
   {
      n = tienets->array[index];

      if ((isBus(n) eq true) || (hasBusIndex(n) eq true) ||
          (isBus(n,m) eq true) // look for a busrange in declaration.
          )
      {
         fprintf(stdout, "veredit: WARNING: TIECELL not inserted for net %s in module %s, bus signals not supported.\n", getN(getName(n)), getN(getName(m)));
      }
      else
      {
         if((i = In(n, allnets)) >= 0) // Net found in module
         {
            tie_added = renameNet(getItems(m),n,outputnet,true,getExcludes(t),getInstances(t));
         }
      }
      ++index;
   }

   if (tie_added > 0) // a tie net was found
   {
      allinsts = getInstNames(getItems(m));   // store all instance names

      // create a new instance name based on the tiecell module name.
      nameNew(allinsts, tiecell_instname, concat(getN(getModuleName(t)), getInstLabel(t)), -1);

      // create new TIECELL
      newtie = tieNew(outputnet,tiecell_instname,t);
      
      // add TIECELL to module instances.
      add(newtie,getItems(m));
      fprintf(stdout,"veredit: Tiecell %s added to module %s\n", getN(getModuleName(t)), getN(getName(m)));
   }
   
}


/*******************************************************/
void removeBuffers(simple_signal s, module m, translation_unit t, name_list n)
{
    // 1 find all instances connected to 's' which are in 'n'
    // 2  find all nets connected to this list but not 's'
    // 3  rename those nets to 's'
    
    // 4 repeat 1 until no more instances
    
    // 5 find all instances connected to 's' which are not leavcells.
    
}

void handle(Signal s, module m, translation_unit t, name_list n)
{
   if(hasSimple(s) eq true)
   {
      removeBuffers(getSimple(s), m, t, n);
   }
   else
      if(hasCmpnd(s) eq true)
         handleSet(getCmpnd(s), m, t, n);
}

/******************************************************* 
 *
 * Remove buffertree.
 *
 *******************************************************/
expfun void removeBuffers(remove_buf_statement r, module m, translation_unit t)
{
  handleSet(getSignals(r), m, t, getBuffers(r));
}
/******************************************************* 
 *
 * Create shell
 *
 *******************************************************/
expfun void shellModule(module m, vname shellname, translation_unit t)
{
   module sh ;
   text  n;
   instance newinst ;
   portmap  newportmap;
   portmap_element newportmap_element;
   port_list pl;
   port p;
   simple_signal net;
   signal_list newsignal_list ;
   Signal newSignal ;
   module_item mi_new;
   module_item_list mil;
   declaration d, dnew;
   declaration_list dl;
   size_t index;

   if ((m == NULL) || (shellname == NULL) || (t == NULL))
      return;
  

   newinst    = instanceNew(); // a new instance
   newportmap = portmapNew();  // a new portmap

   // create a port_list of the declaration_list
   pl = getPortlist(getDeclarations(getItems(m)));
   // build the instance portmap of the port list.
   index = 0;
   while ( index < size(pl))
   {
      p = elementAt(index,pl);
      if (hasPortExpression(p) eq true)
      {
         port_expression pe = getPortExpression(p);

         if (hasPortReference(pe) eq true)
         {
            n = getN(getName(getPortReference(pe)));

            net = simple_signalNew();
            setName(vnameNew(textNew(n)), net);
            newsignal_list = signal_listNew();
            newSignal = SignalNew(net, NULL);
            add(newSignal,newsignal_list);

            newportmap_element = portmap_elementNew(vnameNew(textNew(n)),newsignal_list);

            add(newportmap_element, newportmap);
         }
      }
      // compound port expression not (yet) supported
      ++index;
   }

   // get input, output and inout declarations.
   dl = getDeclarationList(getDeclarations(getItems(m)));

   // build a new module_item_list.
   mil = module_item_listNew();
   index = 0;
   while ( index < size(dl))
   {
      d = elementAt(index,dl);
      dnew = deepCopy(d);
      mi_new = module_itemNew(dnew, NULL, NULL);
      add(mi_new, mil);
      ++index;
   }

   // Add wire declarations to new module_item_list.
   index = 0;
   while ( index < size(dl))
   {
      d = elementAt(index,dl);
      if (hasRnge(d) eq true)
      {
         dnew = deepCopy(d);
         setType(_WIRE, dnew);
         mi_new = module_itemNew(dnew, NULL, NULL);
         add(mi_new, mil);
      }
      ++index;
   }
   n = getN(getName(m)); // name of the original module
   setConnections(newportmap,newinst); // add the connections to the new instance
   setCellName(vnameNew(textNew(n)),newinst);  // set the cellname of the new instance
   setInstName(vnameNew(textNew(concat(n,"_inst"))),newinst); // set the instance name.

   // add new instance to module item list
   add(newinst, mil);

   sh = moduleNew(shellname, deepCopy(getPorts(m)), mil); // create the new module.

   addModule(sh, t); // add module to design.
   fprintf(stdout,"veredit: New module %s created. Shell around module %s.\n", getN(shellname), n);
  
}

/******************************************************* 
 *
 * Check if there are continuous assigns in a module.
 *
 *******************************************************/
expfun bool hasAssigns(module m)
{
   return hasAssigns(getItems(m));
}

/******************************************************* 
 *
 * Check if there are instances in a module.
 *
 *******************************************************/
expfun bool hasInstances(module m)
{
   return hasInstances(getItems(m));
}

/******************************************************* 
 *
 * Buffer the assigns
 *
 *******************************************************/
expfun void bufferAssigns(bufassigns_statement b, module m, translation_unit t)
{
   assign_list a;
   continuous_assign c;
   size_t index;
   int count;
   simple_signal s;
   simple_signal inputnetname;
   expression e;
   instance newbuffer ;
   char buffer[VEREDIT_MAX_NAME_LENGTH];
   text outputname ;
   text buffername ;
   text buf_inputname, buf_outputname ;
   nameset allinsts;
   
   buffername = getN(getBufferName(b));
   a = getAssigns(m);
   index = 0;
   count = 0;
   allinsts = getInstNames(getItems(m));   // store all instance names

   while (index < size(a))
   {
      c = elementAt(index, a);
      s = deepCopy(getSignal(c));
      e = getExpr(c);
      outputname = getN(getName(s));
      if (hasSignal(e) eq true)
      {
         if (hasSimple(getSignal(e)) eq true)
         {
            inputnetname = deepCopy(getSimple(getSignal(e)));
            nameNew(allinsts, buffer, outputname, getBusIndex(s));
            buf_inputname = getInputName(b) ;
            buf_outputname = getOutputName(b) ;
            newbuffer = bufferNew(inputnetname, s,buffer,buf_inputname,buf_outputname,buffername);
            add(newbuffer,getItems(m));
            delAssign(m,c);
            ++count;
         }
         else
            fprintf(stdout,"veredit: ERROR: Continuous assigment of signal %s in module %s is not simple.\n",outputname, getN(getName(m)));
      }
      else
      {
            fprintf(stdout,"veredit: ERROR: Continuous assigment of signal %s in module %s is not simple.\n",outputname, getN(getName(m)));
      }
      ++index;
   }
   if (index > 0)
   fprintf(stdout,"veredit: INFO: %d out of %d continuous assigments replaced by a buffer in module %s.\n",count, (int)index, getN(getName(m)));

}
/******************************************************* 
 *
 * Find a declaration
 *
 *******************************************************/
expfun bool hasPortDeclaration(module m, text name)
{
   return hasPortDeclaration(name, getItems(m));
}
/******************************************************* 
 *
 * Pull up pins
 *
 *******************************************************/
expfun void pullupPins(pullup_pin_statement p, module m, translation_unit t)
{
   simple_signal_list pins;
   simple_signal pin;
   range r;
   text name;
   vnode this_module, parent;
   signal_type st;
   addport_statement aps;
   declaration d;
   declaration_list dl;
   variable_list vl;
   variable_name vn;
   size_t index, i;

   if(m eq NULL) return;

   if (hasPins(p) eq true)
      pins = getPins (p);
   else
      return;
   
   if (getRootNode(t) == NULL)
      buildHierarchy(t);

   index = 0;

   while ( index < size(pins))
   {
      pin = elementAt(index,pins);
      name = getN(getName(pin));
      //fprintf(stdout, "veredit: INFO: Searching port %s in module %s.\n", name, getN(getName(m)));
      if (hasPortDeclaration(m, name) eq true)
      {
         fprintf(stdout, "veredit: INFO: Pulling up port %s of module %s.\n", name, getN(getName(m)));
         r = getRange(name,m);
         st = getType(name,m);

         //create a declaration
         vn = variable_nameNew(getName(pin), NULL);
         vl = variable_listNew();
         add(vn, vl);
         d = declarationNew(st, r, vl);

         // create an addport_statement
         dl = declaration_listNew();
         add(d,dl);
         aps = addport_statementNew(dl);

         this_module = getModNode(m);
         i = 0;
         while (i < sizeOfParents(this_module)) // Go through all parents
         {
            //printf ("sizeOfParents is %d\n",sizeOfParents(this_module));
            parent = elementAtParents(i, this_module);
            pullupPin (parent, aps, getName(m), pin);
            ++i;
         }
         
      }
      else
      {
         fprintf(stdout, "veredit: WARNING: Port declaration %s not found in module %s.\n", name, getN(getName(m)));
      };
      ++index;
   }
      
   
}
/******************************************************* 
 *
 * Get hierarchical instance names.
 *
 *******************************************************/
expfun void getHierInstNames(module m, translation_unit t, FILE *fp)
{
   text name;
   vnode this_module;

   if(m eq NULL) return;

   if (getRootNode(t) == NULL)
      buildHierarchy(t);

   fprintf(stdout, "veredit: INFO: module %s\n", getN(getName(m)));

   this_module = getModNode(m);
	name = textNew("");
   getHierInstName (this_module, name, getN(getName(m)), fp);
}
