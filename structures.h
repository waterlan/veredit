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

#ifndef structures_INCLUDED
#define structures_INCLUDED

#include <stdlib.h>

#ifndef C3PO_BASIC_TYPES_INCLUDED
#define C3PO_BASIC_TYPES_INCLUDED

   typedef       char* rwtext;
   typedef const char* text;

   typedef struct nameset_struct
   {
      text *array;
      size_t size;
   } nameset_struct, *nameset;

   typedef struct intset_struct
   {
      int *array;
      size_t size;
   } intset_struct, *intset;

   typedef struct intsets_struct
   {
      intset *array;
      size_t size;
   } intsets_struct, *intsets;

   typedef struct objset_struct
   {
      void **array;
      size_t size;
   } objset_struct, *objset;

#endif


   typedef struct vname_struct
   {
      text n;
   } vname_struct, *vname;

   typedef struct range_struct
   {
      int begin;
      int end;
   } range_struct, *range;

   typedef struct port_reference_struct
   {
      vname name;
      int busIndex;
      range rnge;
   } port_reference_struct, *port_reference;

   typedef struct port_reference_list_struct
   {
      port_reference *array;
      size_t size;
   } port_reference_list_struct, *port_reference_list;

   typedef struct compound_port_reference_struct
   {
      port_reference_list portReferences;
   } compound_port_reference_struct, *compound_port_reference;

   typedef struct port_expression_struct
   {
      port_reference portReference;
      compound_port_reference cmpnd;
   } port_expression_struct, *port_expression;

   typedef struct port_struct
   {
      port_expression portExpression;
      vname portName;
      port_expression portExpression2;
   } port_struct, *port;

   typedef struct port_list_struct
   {
      port *array;
      size_t size;
   } port_list_struct, *port_list;

   typedef enum
   {
      _INPUT,
      _OUTPUT,
      _INOUT,
      _WIRE,
      _SUPPLY0,
      _SUPPLY1,
      _TRI,
      _TRI0,
      _TRI1,
      _TRIOR,
      _TRIAND,
      _TRIREG,
      _WOR,
      _WAND,
      _SIGNAL_TYPE_UNDEFINED
   } signal_type;

   typedef struct simple_signal_struct
   {
      int cnst;
      vname name;
      int busIndex;
      range rnge;
   } simple_signal_struct, *simple_signal;

   typedef struct signal_list_struct
   {
      struct Signal_struct **array; /* forward reference to array of Signals due to recursion... */
      size_t size;
   } signal_list_struct, *signal_list;

   typedef struct Signal_struct
   {
      simple_signal simple;
      signal_list cmpnd;
   } Signal_struct, *Signal;

   typedef struct expression_struct
   {
      int number;
      Signal signal;
      text string;
   } expression_struct, *expression;

   typedef struct variable_name_struct
   {
      vname name;
      expression expr;
   } variable_name_struct, *variable_name;

   typedef struct variable_list_struct
   {
      variable_name *array;
      size_t size;
   } variable_list_struct, *variable_list;

   typedef struct declaration_struct
   {
      signal_type type;
      range rnge;
      variable_list signals;
   } declaration_struct, *declaration;

   typedef struct continuous_assign_struct
   {
      simple_signal signal;
      expression expr;
   } continuous_assign_struct, *continuous_assign;

   typedef struct portmap_element_struct
   {
      vname pinName;
      signal_list signals;
   } portmap_element_struct, *portmap_element;

   typedef struct portmap_struct
   {
      portmap_element *array;
      size_t size;
   } portmap_struct, *portmap;

   typedef struct instance_struct
   {
      vname cellName;
      vname instName;
      portmap connections;
      signal_list connections_by_order;
   } instance_struct, *instance;

   typedef struct parameter_decl_struct
   {
      simple_signal signal;
      expression expr;
   } parameter_decl_struct, *parameter_decl;

   typedef struct module_item_struct
   {
      declaration declItem;
      continuous_assign assignItem;
      instance instanceItem;
      text initialItem;
      text overrideItem;
      parameter_decl parameter_declItem;
   } module_item_struct, *module_item;

   typedef struct module_item_list_struct
   {
      module_item *array;
      size_t size;
   } module_item_list_struct, *module_item_list;

   typedef struct vnode_struct
   {
      struct vnode_struct **parents; /* forward reference to array of vnodes due to recursion... */
      size_t parentsSize;
      struct vnode_struct **instances; /* forward reference to array of vnodes due to recursion... */
      size_t instancesSize;
      text name;
      int x;
      int y;
      bool fold;
      struct module_struct *block; /* forward reference to module due to recursion... */
      struct vnode_struct *up; /* forward reference to vnode due to recursion... */
      struct vnode_struct *down; /* forward reference to vnode due to recursion... */
   } vnode_struct, *vnode;

   typedef struct module_struct
   {
      vname name;
      port_list ports;
      module_item_list items;
      vnode modNode;
   } module_struct, *module;

   typedef struct verilog_item_struct
   {
      text compilerDirective;
      module block;
   } verilog_item_struct, *verilog_item;

   typedef struct verilog_item_list_struct
   {
      verilog_item *array;
      size_t size;
   } verilog_item_list_struct, *verilog_item_list;

   typedef struct rename_instance_statement_struct
   {
      vname oldName;
      vname newName;
   } rename_instance_statement_struct, *rename_instance_statement;

   typedef struct declaration_list_struct
   {
      declaration *array;
      size_t size;
   } declaration_list_struct, *declaration_list;

   typedef struct addport_statement_struct
   {
      declaration_list addports;
   } addport_statement_struct, *addport_statement;

   typedef enum
   {
      _DELPORTS,
      _RMPORTS,
      _DELNETS,
      _EDITPORT_TYPE_UNDEFINED
   } editport_type;

   typedef struct delport_statement_struct
   {
      editport_type type;
      port_list delports;
      bool all;
   } delport_statement_struct, *delport_statement;

   typedef enum
   {
      _ADDINST,
      _DELINST,
      _MODINST,
      _EDITINST_TYPE_UNDEFINED
   } editinst_type;

   typedef struct instantiation_list_struct
   {
      instance *array;
      size_t size;
   } instantiation_list_struct, *instantiation_list;

   typedef struct editinst_statement_struct
   {
      editinst_type type;
      bool keepmodname;
      instantiation_list editinstances;
      bool all;
   } editinst_statement_struct, *editinst_statement;

   typedef enum
   {
      _ADDASSIGN,
      _DELASSIGN,
      _EDITASSIGN_TYPE_UNDEFINED
   } editassign_type;

   typedef struct assign_list_struct
   {
      continuous_assign *array;
      size_t size;
   } assign_list_struct, *assign_list;

   typedef struct editassign_statement_struct
   {
      editassign_type type;
      assign_list editassigns;
      bool all;
   } editassign_statement_struct, *editassign_statement;

   typedef enum
   {
      _ADDPARAMETERDECL,
      _DELPARAMETERDECL,
      _EDITPARAMETER_DECL_TYPE_UNDEFINED
   } editparameter_decl_type;

   typedef struct parameter_decl_list_struct
   {
      parameter_decl *array;
      size_t size;
   } parameter_decl_list_struct, *parameter_decl_list;

   typedef struct editparameter_decl_statement_struct
   {
      editparameter_decl_type type;
      parameter_decl_list editparameter_decls;
      bool all;
   } editparameter_decl_statement_struct, *editparameter_decl_statement;

   typedef struct delete_module_statement_struct
   {
      bool deleteModule;
      bool empty;
   } delete_module_statement_struct, *delete_module_statement;

   typedef struct buffer_statement_struct
   {
      vname bufferName;
      signal_list excludes;
   } buffer_statement_struct, *buffer_statement;

   typedef struct name_list_struct
   {
      vname *array;
      size_t size;
   } name_list_struct, *name_list;

   typedef struct remove_buf_statement_struct
   {
      signal_list signals;
      name_list buffers;
   } remove_buf_statement_struct, *remove_buf_statement;

   typedef enum
   {
      _BUFFER,
      _BUFFERINPUT,
      _BUFFER_TYPE_UNDEFINED
   } buffer_type;

   typedef struct buffernet_statement_struct
   {
      buffer_type type;
      vname bufferName;
      text inputName;
      text outputName;
      instantiation_list editinstances;
   } buffernet_statement_struct, *buffernet_statement;

   typedef struct simple_signal_list_struct
   {
      simple_signal *array;
      size_t size;
   } simple_signal_list_struct, *simple_signal_list;

   typedef struct insertObsInput_statement_struct
   {
      vname moduleName;
      vname inputName;
      vname outputName;
      portmap otherPins;
      simple_signal_list Nets;
   } insertObsInput_statement_struct, *insertObsInput_statement;

   typedef struct insertObsOutput_statement_struct
   {
      vname moduleName;
      vname inputName;
      vname outputName;
      portmap otherPins;
      simple_signal_list Nets;
   } insertObsOutput_statement_struct, *insertObsOutput_statement;

   typedef struct listInst_statement_struct
   {
      simple_signal Net;
   } listInst_statement_struct, *listInst_statement;

   typedef struct match_item_struct
   {
      vname name;
      text pattern;
   } match_item_struct, *match_item;

   typedef struct match_list_struct
   {
      match_item *array;
      size_t size;
   } match_list_struct, *match_list;

   typedef struct tiecell_statement_struct
   {
      vname moduleName;
      vname outputName;
      portmap otherPins;
      simple_signal_list Nets;
      simple_signal_list excludes;
      match_list instances;
      text instLabel;
   } tiecell_statement_struct, *tiecell_statement;

   typedef struct shell_statement_struct
   {
      vname shellName;
   } shell_statement_struct, *shell_statement;

   typedef struct bufassigns_statement_struct
   {
      vname bufferName;
      text inputName;
      text outputName;
   } bufassigns_statement_struct, *bufassigns_statement;

   typedef struct pullup_pin_statement_struct
   {
      simple_signal_list Pins;
   } pullup_pin_statement_struct, *pullup_pin_statement;

   typedef struct edit_element_struct
   {
      rename_instance_statement renameInst;
      addport_statement addport;
      delport_statement delport;
      editinst_statement editinst;
      editassign_statement editassign;
      editparameter_decl_statement editparameter_decl;
      delete_module_statement delModule;
      buffer_statement bufferStat;
      remove_buf_statement removeBufStat;
      buffernet_statement bufferNetStat;
      insertObsInput_statement insertObsInputStat;
      insertObsOutput_statement insertObsOutputStat;
      listInst_statement listInstStat;
      tiecell_statement tiecellStat;
      shell_statement shellStat;
      bufassigns_statement bufAssign;
      pullup_pin_statement pullupPin;
   } edit_element_struct, *edit_element;

   typedef struct edit_list_struct
   {
      edit_element *array;
      size_t size;
   } edit_list_struct, *edit_list;

   typedef struct module_edit_struct
   {
      vname name;
      edit_list edtList;
      text pattern;
   } module_edit_struct, *module_edit;

   typedef struct module_edit_list_struct
   {
      module_edit *array;
      size_t size;
   } module_edit_list_struct, *module_edit_list;

   typedef struct translation_unit_struct
   {
      verilog_item_list items;
      module_edit_list edits;
      vnode rootNode;
   } translation_unit_struct, *translation_unit;

   typedef struct dot_struct
   {
      text parent;
      text child;
      int times;
   } dot_struct, *dot;

   typedef struct dot_list_struct
   {
      dot *array;
      size_t size;
   } dot_list_struct, *dot_list;

   typedef struct module_list_struct
   {
      module *array;
      size_t size;
   } module_list_struct, *module_list;

#endif
