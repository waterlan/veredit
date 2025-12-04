%{
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

#define translation_unit_cc


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "nameset.h"
#include "command.h"
#include "file.h"
#include "translation_unit.h"
#include "module_edit_list.h"
#include "module_edit.h"
#include "edit_list.h"
#include "edit_element.h"
#include "rename_instance_statement.h"
#include "delete_module_statement.h"
#include "shell_statement.h"
#include "bufassigns_statement.h"
#include "match_list.h"
#include "match_item.h"
#include "tiecell_statement.h"
#include "insertObsInput_statement.h"
#include "insertObsOutput_statement.h"
#include "remove_buf_statement.h"
#include "pullup_pin_statement.h"
#include "name_list.h"
#include "editassign_type.h"
#include "buffer_statement.h"
#include "buffernet_statement.h"
#include "buffer_type.h"
#include "editassign_statement.h"
#include "editparameter_decl_type.h"
#include "editparameter_decl_statement.h"
#include "editinst_type.h"
#include "addport_statement.h"
#include "editport_type.h"
#include "delport_statement.h"
#include "editinst_statement.h"
#include "listInst_statement.h"
#include "verilog_item_list.h"
#include "verilog_item.h"
#include "module.h"
#include "port_list.h"
#include "port.h"
#include "port_expression.h"
#include "compound_port_reference.h"
#include "port_reference_list.h"
#include "port_reference.h"
#include "module_item_list.h"
#include "module_item.h"
#include "declaration_list.h"
#include "declaration.h"
#include "signal_type.h"
#include "variable_list.h"
#include "variable_name.h"
#include "expression.h"
#include "assign_list.h"
#include "continuous_assign.h"
#include "parameter_decl_list.h"
#include "parameter_decl.h"
#include "instantiation_list.h"
#include "range.h"
#include "instance.h"
#include "portmap.h"
#include "portmap_element.h"
#include "simple_signal_list.h"
#include "simple_signal.h"
#include "signal_list.h"
#include "Signal.h"
#include "vname.h"

static translation_unit PARSED_translation_unit = NULL;

static FILE *yyINSTREAM = NULL;
static FILE *yyOUTSTREAM = NULL;
static FILE *yyERRSTREAM = NULL;

expvar nameset yyITEMS;
expvar text yyCURRENT_ITEM = NULL;

extern int yylex(void);
extern int yyparse(void);


expfun void setTranslation_unitParserInputStream(FILE* stream)
{
   if (stream ne NULL)
      yyINSTREAM = stream;
}
expfun void setTranslation_unitParserOutputStream(FILE* stream)
{
   extern FILE *yyout;

   if (stream ne NULL)
   {
      yyOUTSTREAM = stream;
      yyout = stream;
   }
}
expfun void setTranslation_unitParserErrorStream(FILE* stream)
{
   if (stream ne NULL)
      yyERRSTREAM = stream;
}
expfun FILE * getTranslation_unitParserInputStream(void)
{
   if (yyINSTREAM != NULL)
      return yyINSTREAM;
   else
      return stdin;
}
expfun FILE * getTranslation_unitParserOutputStream(void)
{
   if (yyOUTSTREAM != NULL)
      return yyOUTSTREAM;
   else
      return stdout;
}
expfun FILE * getTranslation_unitParserErrorStream(void)
{
   if (yyERRSTREAM != NULL)
      return yyERRSTREAM;
   else
      return stderr;
}
expfun text getTranslation_unitCurrentParseItem(bool baseName = false)
{
   extern text yyCURRENT_ITEM;
   if (yyCURRENT_ITEM ne NULL)
   {
      if (baseName)
         return getBasename(yyCURRENT_ITEM);
      else
         return yyCURRENT_ITEM;
   }
   else
      return "stdin";
}
static void yyerror(text message)
{
#ifndef SETBASE
#define SETBASE false
#endif

   extern int yylineno;
   extern rwtext yyTOKEN_BUFFER;

   FILE *f_err = getTranslation_unitParserErrorStream();

   if (yylineno > 0)
      fprintf(f_err, "*** ERROR %s:%d: [Line %d, %s near symbol %s]\n", getTranslation_unitCurrentParseItem(SETBASE),  yylineno, yylineno, message, yyTOKEN_BUFFER);
   else
      fprintf(f_err, "*** ERROR %s: [%s near symbol %s]\n", getTranslation_unitCurrentParseItem(SETBASE), message, yyTOKEN_BUFFER);

   exit(1);
}
%}

%union
{
   text text_field;
   int int_field;
   translation_unit translation_unit_field;
   module_edit_list module_edit_list_field;
   module_edit module_edit_field;
   edit_list edit_list_field;
   edit_element edit_element_field;
   rename_instance_statement rename_instance_statement_field;
   delete_module_statement delete_module_statement_field;
   shell_statement shell_statement_field;
   bufassigns_statement bufassigns_statement_field;
   match_list match_list_field;
   match_item match_item_field;
   tiecell_statement tiecell_statement_field;
   insertObsInput_statement insertObsInput_statement_field;
   insertObsOutput_statement insertObsOutput_statement_field;
   remove_buf_statement remove_buf_statement_field;
   pullup_pin_statement pullup_pin_statement_field;
   name_list name_list_field;
   editassign_type editassign_type_field;
   buffer_statement buffer_statement_field;
   buffernet_statement buffernet_statement_field;
   buffer_type buffer_type_field;
   editassign_statement editassign_statement_field;
   editparameter_decl_type editparameter_decl_type_field;
   editparameter_decl_statement editparameter_decl_statement_field;
   editinst_type editinst_type_field;
   addport_statement addport_statement_field;
   editport_type editport_type_field;
   delport_statement delport_statement_field;
   editinst_statement editinst_statement_field;
   listInst_statement listInst_statement_field;
   verilog_item_list verilog_item_list_field;
   verilog_item verilog_item_field;
   module module_field;
   port_list port_list_field;
   port port_field;
   port_expression port_expression_field;
   compound_port_reference compound_port_reference_field;
   port_reference_list port_reference_list_field;
   port_reference port_reference_field;
   module_item_list module_item_list_field;
   module_item module_item_field;
   declaration_list declaration_list_field;
   declaration declaration_field;
   signal_type signal_type_field;
   variable_list variable_list_field;
   variable_name variable_name_field;
   expression expression_field;
   assign_list assign_list_field;
   continuous_assign continuous_assign_field;
   parameter_decl_list parameter_decl_list_field;
   parameter_decl parameter_decl_field;
   instantiation_list instantiation_list_field;
   range range_field;
   instance instance_field;
   portmap portmap_field;
   portmap_element portmap_element_field;
   simple_signal_list simple_signal_list_field;
   simple_signal simple_signal_field;
   signal_list signal_list_field;
   Signal Signal_field;
   vname vname_field;
}

%token MODULE
%token ENDMODULE
%token INPUT
%token OUTPUT
%token INOUT
%token WIRE
%token SUPPLY0
%token SUPPLY1
%token TRI
%token TRI0
%token TRI1
%token TRIOR
%token TRIAND
%token TRIREG
%token WOR
%token WAND
%token ASSIGN
%token PARAMETER
%token E_MODULE
%token E_OUTPUT
%token E_INPUT
%token INSTANCE
%token ADDPORTS
%token DELPORTS
%token RMPORTS
%token DELNETS
%token ADDINST
%token MODINST
%token KEEPMODNAME
%token DELINST
%token ADDASSIGN
%token DELASSIGN
%token ADDPARAMETERDECL
%token DELPARAMETERDECL
%token DELETE
%token EMPTY
%token BUFFEROUTPUTS
%token EXCLUDE
%token REMOVEBUFFERS
%token BUFFERLIST
%token BUFFER
%token BUFFERINPUT
%token INSERTOBSINPUT
%token OTHER
%token NETS
%token INSERTOBSOUTPUT
%token LISTINST
%token NET
%token TIECELL
%token SHELL
%token BUFASSIGNS
%token PULLUPPIN
%token INST
%token LABEL
%token <text_field> INITIALSTAT
%token <text_field> DEFPARAM
%token <text_field> IDENTIFIER
%token <text_field> WILDCARDS
%token <text_field> STRINGVALUE
%token <int_field> INT_CONSTANT
%token ALL
%token <text_field> compiler_directive

%type <text_field> initial_statement parameter_override
%type <translation_unit_field> translation_unit
%type <module_edit_list_field> module_edit_list
%type <module_edit_field> module_edit
%type <edit_list_field> edit_list
%type <edit_element_field> edit_element
%type <rename_instance_statement_field> rename_instance_statement
%type <delete_module_statement_field> delete_module_statement
%type <shell_statement_field> shell_statement
%type <bufassigns_statement_field> bufassigns_statement
%type <match_list_field> match_list
%type <match_item_field> match_item
%type <tiecell_statement_field> tiecell_statement
%type <insertObsInput_statement_field> insertObsInput_statement
%type <insertObsOutput_statement_field> insertObsOutput_statement
%type <remove_buf_statement_field> remove_buf_statement
%type <pullup_pin_statement_field> pullup_pin_statement
%type <name_list_field> name_list
%type <editassign_type_field> editassign_type
%type <buffer_statement_field> buffer_statement
%type <buffernet_statement_field> buffernet_statement
%type <buffer_type_field> buffer_type
%type <editassign_statement_field> editassign_statement
%type <editparameter_decl_type_field> editparameter_decl_type
%type <editparameter_decl_statement_field> editparameter_decl_statement
%type <editinst_type_field> editinst_type
%type <addport_statement_field> addport_statement
%type <editport_type_field> editport_type
%type <delport_statement_field> delport_statement
%type <editinst_statement_field> editinst_statement
%type <listInst_statement_field> listInst_statement
%type <verilog_item_list_field> verilog_item_list
%type <verilog_item_field> verilog_item
%type <module_field> module
%type <port_list_field> port_list
%type <port_field> port
%type <port_expression_field> port_expression
%type <compound_port_reference_field> compound_port_reference
%type <port_reference_list_field> port_reference_list
%type <port_reference_field> port_reference
%type <module_item_list_field> module_item_list
%type <module_item_field> module_item
%type <declaration_list_field> declaration_list
%type <declaration_field> declaration
%type <signal_type_field> signal_type
%type <variable_list_field> variable_list
%type <variable_name_field> variable_name
%type <expression_field> expression
%type <assign_list_field> assign_list
%type <continuous_assign_field> continuous_assign
%type <parameter_decl_list_field> parameter_decl_list
%type <parameter_decl_field> parameter_decl
%type <instantiation_list_field> instantiation_list
%type <range_field> range
%type <instance_field> instance
%type <portmap_field> portmap
%type <portmap_element_field> portmap_element
%type <simple_signal_list_field> simple_signal_list
%type <simple_signal_field> simple_signal
%type <signal_list_field> compound_signal signal_list
%type <Signal_field> Signal
%type <vname_field> vname

%%

translation_unit : verilog_item_list module_edit_list                                                                                             {$$ = translation_unitNew($1, $2); PARSED_translation_unit = $$;}
                 | module_edit_list                                                                                                               {$$ = translation_unitNew(verilog_item_listNew(), $1); PARSED_translation_unit = $$;}
                 | verilog_item_list                                                                                                              {$$ = translation_unitNew($1, module_edit_listNew()); PARSED_translation_unit = $$;}
                 ;

module_edit_list : module_edit                                                                                                                    {$$ = module_edit_listNew(); add($1, $$);}
                 | module_edit_list module_edit                                                                                                   {add($2, $$);}
                 ;

module_edit : E_MODULE vname '{' edit_list '}'                                                                                                    {$$ = module_editNew($2, $4, (text) NULL);}
            | E_MODULE vname '{' '}'                                                                                                              {$$ = module_editNew($2, edit_listNew(), (text) NULL);}
            | E_MODULE WILDCARDS '{' edit_list '}'                                                                                                {$$ = module_editNew((vname) NULL, $4, $2);}
            | E_MODULE WILDCARDS '{' '}'                                                                                                          {$$ = module_editNew((vname) NULL, edit_listNew(), $2);}
            ;

edit_list : edit_element                                                                                                                          {$$ = edit_listNew(); add($1, $$);}
          | edit_list edit_element                                                                                                                {add($2, $$);}
          ;

edit_element : rename_instance_statement                                                                                                          {$$ = edit_elementNew($1, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | addport_statement                                                                                                                  {$$ = edit_elementNew((rename_instance_statement) NULL, $1, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | delport_statement                                                                                                                  {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, $1, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | editinst_statement                                                                                                                 {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, $1, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | editassign_statement                                                                                                               {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, $1, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | editparameter_decl_statement                                                                                                       {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, $1, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | delete_module_statement                                                                                                            {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, $1, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | buffer_statement                                                                                                                   {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, $1, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | remove_buf_statement                                                                                                               {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, $1, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | buffernet_statement                                                                                                                {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, $1, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | insertObsInput_statement                                                                                                           {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, $1, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | insertObsOutput_statement                                                                                                          {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, $1, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | listInst_statement                                                                                                                 {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, $1, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | tiecell_statement                                                                                                                  {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, $1, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | shell_statement                                                                                                                    {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, $1, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
             | bufassigns_statement                                                                                                               {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, $1, (pullup_pin_statement) NULL);}
             | pullup_pin_statement                                                                                                               {$$ = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, $1);}
             ;

rename_instance_statement : INSTANCE vname '=' vname                                                                                              {$$ = rename_instance_statementNew($2, $4);}
                          ;

delete_module_statement : DELETE EMPTY                                                                                                            {$$ = delete_module_statementNew(); $$->deleteModule = true; $$->empty = true;}
                        | DELETE                                                                                                                  {$$ = delete_module_statementNew(); $$->deleteModule = true;}
                        ;

shell_statement : SHELL vname                                                                                                                     {$$ = shell_statementNew($2);}
                ;

bufassigns_statement : BUFASSIGNS vname E_INPUT IDENTIFIER E_OUTPUT IDENTIFIER                                                                    {$$ = bufassigns_statementNew($2, $4, $6);}
                     | BUFASSIGNS vname E_OUTPUT IDENTIFIER                                                                                       {$$ = bufassigns_statementNew($2, "A", $4);}
                     | BUFASSIGNS vname E_INPUT IDENTIFIER                                                                                        {$$ = bufassigns_statementNew($2, $4, "Z");}
                     | BUFASSIGNS vname                                                                                                           {$$ = bufassigns_statementNew($2, "A", "Z");}
                     ;

match_list : match_item                                                                                                                           {$$ = match_listNew(); add($1, $$);}
           | match_list match_item                                                                                                                {add($2, $$);}
           ;

match_item : vname                                                                                                                                {$$ = match_itemNew($1, (text) NULL);}
           | WILDCARDS                                                                                                                            {$$ = match_itemNew((vname) NULL, $1);}
           ;

tiecell_statement : TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list EXCLUDE simple_signal_list INST match_list LABEL IDENTIFIER {$$ = tiecell_statementNew($2, $4, $6, $8, $10, $12, $14);}
                  | TIECELL vname E_OUTPUT vname NET simple_signal_list EXCLUDE simple_signal_list INST match_list LABEL IDENTIFIER               {$$ = tiecell_statementNew($2, $4, portmapNew(), $6, $8, $10, $12);}
                  | TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list INST match_list LABEL IDENTIFIER                            {$$ = tiecell_statementNew($2, $4, $6, $8, simple_signal_listNew(), $10, $12);}
                  | TIECELL vname E_OUTPUT vname NET simple_signal_list INST match_list LABEL IDENTIFIER                                          {$$ = tiecell_statementNew($2, $4, portmapNew(), $6, simple_signal_listNew(), $8, $10);}
                  | TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list EXCLUDE simple_signal_list LABEL IDENTIFIER                 {$$ = tiecell_statementNew($2, $4, $6, $8, $10, match_listNew(), $12);}
                  | TIECELL vname E_OUTPUT vname NET simple_signal_list EXCLUDE simple_signal_list LABEL IDENTIFIER                               {$$ = tiecell_statementNew($2, $4, portmapNew(), $6, $8, match_listNew(), $10);}
                  | TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list LABEL IDENTIFIER                                            {$$ = tiecell_statementNew($2, $4, $6, $8, simple_signal_listNew(), match_listNew(), $10);}
                  | TIECELL vname E_OUTPUT vname NET simple_signal_list LABEL IDENTIFIER                                                          {$$ = tiecell_statementNew($2, $4, portmapNew(), $6, simple_signal_listNew(), match_listNew(), $8);}
                  | TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list EXCLUDE simple_signal_list INST match_list                  {$$ = tiecell_statementNew($2, $4, $6, $8, $10, $12, "");}
                  | TIECELL vname E_OUTPUT vname NET simple_signal_list EXCLUDE simple_signal_list INST match_list                                {$$ = tiecell_statementNew($2, $4, portmapNew(), $6, $8, $10, "");}
                  | TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list INST match_list                                             {$$ = tiecell_statementNew($2, $4, $6, $8, simple_signal_listNew(), $10, "");}
                  | TIECELL vname E_OUTPUT vname NET simple_signal_list INST match_list                                                           {$$ = tiecell_statementNew($2, $4, portmapNew(), $6, simple_signal_listNew(), $8, "");}
                  | TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list EXCLUDE simple_signal_list                                  {$$ = tiecell_statementNew($2, $4, $6, $8, $10, match_listNew(), "");}
                  | TIECELL vname E_OUTPUT vname NET simple_signal_list EXCLUDE simple_signal_list                                                {$$ = tiecell_statementNew($2, $4, portmapNew(), $6, $8, match_listNew(), "");}
                  | TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list                                                             {$$ = tiecell_statementNew($2, $4, $6, $8, simple_signal_listNew(), match_listNew(), "");}
                  | TIECELL vname E_OUTPUT vname NET simple_signal_list                                                                           {$$ = tiecell_statementNew($2, $4, portmapNew(), $6, simple_signal_listNew(), match_listNew(), "");}
                  ;

insertObsInput_statement : INSERTOBSINPUT vname E_INPUT vname E_OUTPUT vname OTHER portmap NETS simple_signal_list                                {$$ = insertObsInput_statementNew($2, $4, $6, $8, $10);}
                         | INSERTOBSINPUT vname E_INPUT vname E_OUTPUT vname NETS simple_signal_list                                              {$$ = insertObsInput_statementNew($2, $4, $6, portmapNew(), $8);}
                         ;

insertObsOutput_statement : INSERTOBSOUTPUT vname E_INPUT vname E_OUTPUT vname OTHER portmap NETS simple_signal_list                              {$$ = insertObsOutput_statementNew($2, $4, $6, $8, $10);}
                          | INSERTOBSOUTPUT vname E_INPUT vname E_OUTPUT vname NETS simple_signal_list                                            {$$ = insertObsOutput_statementNew($2, $4, $6, portmapNew(), $8);}
                          ;

remove_buf_statement : REMOVEBUFFERS signal_list BUFFERLIST name_list                                                                             {$$ = remove_buf_statementNew($2, $4);}
                     ;

pullup_pin_statement : PULLUPPIN simple_signal_list                                                                                               {$$ = pullup_pin_statementNew($2);}
                     ;

name_list : vname                                                                                                                                 {$$ = name_listNew(); add($1, $$);}
          | name_list ',' vname                                                                                                                   {add($3, $$);}
          ;

editassign_type : ADDASSIGN                                                                                                                       {$$ = _ADDASSIGN;}
                | DELASSIGN                                                                                                                       {$$ = _DELASSIGN;}
                ;

buffer_statement : BUFFEROUTPUTS vname EXCLUDE signal_list                                                                                        {$$ = buffer_statementNew($2, $4);}
                 | BUFFEROUTPUTS vname                                                                                                            {$$ = buffer_statementNew($2, signal_listNew());}
                 ;

buffernet_statement : buffer_type vname E_INPUT IDENTIFIER E_OUTPUT IDENTIFIER instantiation_list                                                 {$$ = buffernet_statementNew($1, $2, $4, $6, $7);}
                    | buffer_type vname E_OUTPUT IDENTIFIER instantiation_list                                                                    {$$ = buffernet_statementNew($1, $2, "A", $4, $5);}
                    | buffer_type vname E_INPUT IDENTIFIER instantiation_list                                                                     {$$ = buffernet_statementNew($1, $2, $4, "Z", $5);}
                    | buffer_type vname instantiation_list                                                                                        {$$ = buffernet_statementNew($1, $2, "A", "Z", $3);}
                    | buffer_type vname E_INPUT IDENTIFIER E_OUTPUT IDENTIFIER                                                                    {$$ = buffernet_statementNew($1, $2, $4, $6, instantiation_listNew());}
                    | buffer_type vname E_OUTPUT IDENTIFIER                                                                                       {$$ = buffernet_statementNew($1, $2, "A", $4, instantiation_listNew());}
                    | buffer_type vname E_INPUT IDENTIFIER                                                                                        {$$ = buffernet_statementNew($1, $2, $4, "Z", instantiation_listNew());}
                    | buffer_type vname                                                                                                           {$$ = buffernet_statementNew($1, $2, "A", "Z", instantiation_listNew());}
                    ;

buffer_type : BUFFER                                                                                                                              {$$ = _BUFFER;}
            | BUFFERINPUT                                                                                                                         {$$ = _BUFFERINPUT;}
            ;

editassign_statement : editassign_type assign_list ALL                                                                                            {$$ = editassign_statementNew($1, $2); $$->all = true;}
                     | editassign_type ALL                                                                                                        {$$ = editassign_statementNew($1, assign_listNew()); $$->all = true;}
                     | editassign_type assign_list                                                                                                {$$ = editassign_statementNew($1, $2);}
                     | editassign_type                                                                                                            {$$ = editassign_statementNew($1, assign_listNew());}
                     ;

editparameter_decl_type : ADDPARAMETERDECL                                                                                                        {$$ = _ADDPARAMETERDECL;}
                        | DELPARAMETERDECL                                                                                                        {$$ = _DELPARAMETERDECL;}
                        ;

editparameter_decl_statement : editparameter_decl_type parameter_decl_list ALL                                                                    {$$ = editparameter_decl_statementNew($1, $2); $$->all = true;}
                             | editparameter_decl_type ALL                                                                                        {$$ = editparameter_decl_statementNew($1, parameter_decl_listNew()); $$->all = true;}
                             | editparameter_decl_type parameter_decl_list                                                                        {$$ = editparameter_decl_statementNew($1, $2);}
                             | editparameter_decl_type                                                                                            {$$ = editparameter_decl_statementNew($1, parameter_decl_listNew());}
                             ;

editinst_type : ADDINST                                                                                                                           {$$ = _ADDINST;}
              | DELINST                                                                                                                           {$$ = _DELINST;}
              | MODINST                                                                                                                           {$$ = _MODINST;}
              ;

addport_statement : ADDPORTS declaration_list                                                                                                     {$$ = addport_statementNew($2);}
                  | ADDPORTS                                                                                                                      {$$ = addport_statementNew(declaration_listNew());}
                  ;

editport_type : DELPORTS                                                                                                                          {$$ = _DELPORTS;}
              | RMPORTS                                                                                                                           {$$ = _RMPORTS;}
              | DELNETS                                                                                                                           {$$ = _DELNETS;}
              ;

delport_statement : editport_type port_list ALL                                                                                                   {$$ = delport_statementNew($1, $2); $$->all = true;}
                  | editport_type ALL                                                                                                             {$$ = delport_statementNew($1, port_listNew()); $$->all = true;}
                  | editport_type port_list                                                                                                       {$$ = delport_statementNew($1, $2);}
                  | editport_type                                                                                                                 {$$ = delport_statementNew($1, port_listNew());}
                  ;

editinst_statement : editinst_type KEEPMODNAME instantiation_list ALL                                                                             {$$ = editinst_statementNew($1, $3); $$->keepmodname = true; $$->all = true;}
                   | editinst_type instantiation_list ALL                                                                                         {$$ = editinst_statementNew($1, $2); $$->all = true;}
                   | editinst_type KEEPMODNAME ALL                                                                                                {$$ = editinst_statementNew($1, instantiation_listNew()); $$->keepmodname = true; $$->all = true;}
                   | editinst_type ALL                                                                                                            {$$ = editinst_statementNew($1, instantiation_listNew()); $$->all = true;}
                   | editinst_type KEEPMODNAME instantiation_list                                                                                 {$$ = editinst_statementNew($1, $3); $$->keepmodname = true;}
                   | editinst_type instantiation_list                                                                                             {$$ = editinst_statementNew($1, $2);}
                   | editinst_type KEEPMODNAME                                                                                                    {$$ = editinst_statementNew($1, instantiation_listNew()); $$->keepmodname = true;}
                   | editinst_type                                                                                                                {$$ = editinst_statementNew($1, instantiation_listNew());}
                   ;

listInst_statement : LISTINST NET simple_signal                                                                                                   {$$ = listInst_statementNew($3);}
                   ;

verilog_item_list : verilog_item                                                                                                                  {$$ = verilog_item_listNew(); add($1, $$);}
                  | verilog_item_list verilog_item                                                                                                {add($2, $$);}
                  ;

verilog_item : compiler_directive                                                                                                                 {$$ = verilog_itemNew($1, (module) NULL);}
             | module                                                                                                                             {$$ = verilog_itemNew((text) NULL, $1);}
             ;

module : MODULE vname '(' port_list ')' ';' module_item_list ENDMODULE                                                                            {$$ = moduleNew($2, $4, $7);}
       | MODULE vname '(' ')' ';' module_item_list ENDMODULE                                                                                      {$$ = moduleNew($2, port_listNew(), $6);}
       | MODULE vname ';' module_item_list ENDMODULE                                                                                              {$$ = moduleNew($2, port_listNew(), $4);}
       | MODULE vname '(' port_list ')' ';' ENDMODULE                                                                                             {$$ = moduleNew($2, $4, module_item_listNew());}
       | MODULE vname '(' ')' ';' ENDMODULE                                                                                                       {$$ = moduleNew($2, port_listNew(), module_item_listNew());}
       | MODULE vname ';' ENDMODULE                                                                                                               {$$ = moduleNew($2, port_listNew(), module_item_listNew());}
       ;

port_list : port                                                                                                                                  {$$ = port_listNew(); add($1, $$);}
          | port_list ',' port                                                                                                                    {add($3, $$);}
          ;

port : port_expression                                                                                                                            {$$ = portNew($1, (vname) NULL, (port_expression) NULL);}
     | '.' vname '(' port_expression ')'                                                                                                          {$$ = portNew((port_expression) NULL, $2, $4);}
     ;

port_expression : port_reference                                                                                                                  {$$ = port_expressionNew($1, (compound_port_reference) NULL);}
                | compound_port_reference                                                                                                         {$$ = port_expressionNew((port_reference) NULL, $1);}
                ;

compound_port_reference : '{' port_reference_list '}'                                                                                             {$$ = compound_port_referenceNew($2);}
                        ;

port_reference_list : port_reference                                                                                                              {$$ = port_reference_listNew(); add($1, $$);}
                    | port_reference_list ',' port_reference                                                                                      {add($3, $$);}
                    ;

port_reference : vname '[' INT_CONSTANT ']'                                                                                                       {$$ = port_referenceNew($1, $3, (range) NULL);}
               | vname                                                                                                                            {$$ = port_referenceNew($1, (int) -1, (range) NULL);}
               | vname range                                                                                                                      {$$ = port_referenceNew($1, (int) -1, $2);}
               ;

module_item_list : module_item                                                                                                                    {$$ = module_item_listNew(); add($1, $$);}
                 | module_item_list module_item                                                                                                   {add($2, $$);}
                 ;

module_item : declaration                                                                                                                         {$$ = module_itemNew($1, (continuous_assign) NULL, (instance) NULL, (text) NULL, (text) NULL, (parameter_decl) NULL);}
            | continuous_assign                                                                                                                   {$$ = module_itemNew((declaration) NULL, $1, (instance) NULL, (text) NULL, (text) NULL, (parameter_decl) NULL);}
            | instance                                                                                                                            {$$ = module_itemNew((declaration) NULL, (continuous_assign) NULL, $1, (text) NULL, (text) NULL, (parameter_decl) NULL);}
            | initial_statement                                                                                                                   {$$ = module_itemNew((declaration) NULL, (continuous_assign) NULL, (instance) NULL, $1, (text) NULL, (parameter_decl) NULL);}
            | parameter_override                                                                                                                  {$$ = module_itemNew((declaration) NULL, (continuous_assign) NULL, (instance) NULL, (text) NULL, $1, (parameter_decl) NULL);}
            | parameter_decl                                                                                                                      {$$ = module_itemNew((declaration) NULL, (continuous_assign) NULL, (instance) NULL, (text) NULL, (text) NULL, $1);}
            ;

initial_statement : INITIALSTAT                                                                                                                   {$$ = $1;}
                  ;

parameter_override : DEFPARAM                                                                                                                     {$$ = $1;}
                   ;

declaration_list : declaration                                                                                                                    {$$ = declaration_listNew(); add($1, $$);}
                 | declaration_list declaration                                                                                                   {add($2, $$);}
                 ;

declaration : signal_type range variable_list ';'                                                                                                 {$$ = declarationNew($1, $2, $3);}
            | signal_type variable_list ';'                                                                                                       {$$ = declarationNew($1, (range) NULL, $2);}
            ;

signal_type : INPUT                                                                                                                               {$$ = _INPUT;}
            | OUTPUT                                                                                                                              {$$ = _OUTPUT;}
            | INOUT                                                                                                                               {$$ = _INOUT;}
            | WIRE                                                                                                                                {$$ = _WIRE;}
            | SUPPLY0                                                                                                                             {$$ = _SUPPLY0;}
            | SUPPLY1                                                                                                                             {$$ = _SUPPLY1;}
            | TRI                                                                                                                                 {$$ = _TRI;}
            | TRI0                                                                                                                                {$$ = _TRI0;}
            | TRI1                                                                                                                                {$$ = _TRI1;}
            | TRIOR                                                                                                                               {$$ = _TRIOR;}
            | TRIAND                                                                                                                              {$$ = _TRIAND;}
            | TRIREG                                                                                                                              {$$ = _TRIREG;}
            | WOR                                                                                                                                 {$$ = _WOR;}
            | WAND                                                                                                                                {$$ = _WAND;}
            ;

variable_list : variable_name                                                                                                                     {$$ = variable_listNew(); add($1, $$);}
              | variable_list ',' variable_name                                                                                                   {add($3, $$);}
              ;

variable_name : vname '=' expression                                                                                                              {$$ = variable_nameNew($1, $3);}
              | vname                                                                                                                             {$$ = variable_nameNew($1, (expression) NULL);}
              ;

expression : INT_CONSTANT                                                                                                                         {$$ = expressionNew($1, (Signal) NULL, (text) NULL);}
           | Signal                                                                                                                               {$$ = expressionNew((int) -1, $1, (text) NULL);}
           | STRINGVALUE                                                                                                                          {$$ = expressionNew((int) -1, (Signal) NULL, $1);}
           ;

assign_list : continuous_assign                                                                                                                   {$$ = assign_listNew(); add($1, $$);}
            | assign_list continuous_assign                                                                                                       {add($2, $$);}
            ;

continuous_assign : ASSIGN simple_signal '=' expression ';'                                                                                       {$$ = continuous_assignNew($2, $4);}
                  ;

parameter_decl_list : parameter_decl                                                                                                              {$$ = parameter_decl_listNew(); add($1, $$);}
                    | parameter_decl_list parameter_decl                                                                                          {add($2, $$);}
                    ;

parameter_decl : PARAMETER simple_signal '=' expression ';'                                                                                       {$$ = parameter_declNew($2, $4);}
               ;

instantiation_list : instance                                                                                                                     {$$ = instantiation_listNew(); add($1, $$);}
                   | instantiation_list instance                                                                                                  {add($2, $$);}
                   ;

range : '[' INT_CONSTANT ':' INT_CONSTANT ']'                                                                                                     {$$ = rangeNew($2, $4);}
      ;

instance : vname vname '(' portmap ')' ';'                                                                                                        {$$ = instanceNew($1, $2, $4, signal_listNew());}
         | vname vname '(' ')' ';'                                                                                                                {$$ = instanceNew($1, $2, portmapNew(), signal_listNew());}
         | vname vname '(' signal_list ')' ';'                                                                                                    {$$ = instanceNew($1, $2, portmapNew(), $4);}
         ;

portmap : portmap_element                                                                                                                         {$$ = portmapNew(); add($1, $$);}
        | portmap ',' portmap_element                                                                                                             {add($3, $$);}
        ;

portmap_element : '.' vname '(' signal_list ')'                                                                                                   {$$ = portmap_elementNew($2, $4);}
                | '.' vname '(' ')'                                                                                                               {$$ = portmap_elementNew($2, signal_listNew());}
                ;

simple_signal_list :                                                                                                                              {$$ = simple_signal_listNew();}
                   | simple_signal_list simple_signal                                                                                             {add($2, $$);}
                   ;

simple_signal : INT_CONSTANT '\'' vname '[' INT_CONSTANT ']'                                                                                       {$$ = simple_signalNew($1, $3, $5, (range) NULL);}
              | vname '[' INT_CONSTANT ']'                                                                                                        {$$ = simple_signalNew((int) -1, $1, $3, (range) NULL);}
              | INT_CONSTANT '\'' vname                                                                                                            {$$ = simple_signalNew($1, $3, (int) -1, (range) NULL);}
              | vname                                                                                                                             {$$ = simple_signalNew((int) -1, $1, (int) -1, (range) NULL);}
              | INT_CONSTANT '\'' vname range                                                                                                      {$$ = simple_signalNew($1, $3, (int) -1, $4);}
              | vname range                                                                                                                       {$$ = simple_signalNew((int) -1, $1, (int) -1, $2);}
              ;

compound_signal : '{' signal_list '}'                                                                                                             {$$ = $2;}
                ;

signal_list : Signal                                                                                                                              {$$ = signal_listNew(); add($1, $$);}
            | signal_list ',' Signal                                                                                                              {add($3, $$);}
            ;

Signal : simple_signal                                                                                                                            {$$ = SignalNew($1, signal_listNew());}
       | compound_signal                                                                                                                          {$$ = SignalNew((simple_signal) NULL, $1);}
       ;

vname : IDENTIFIER                                                                                                                                {$$ = vnameNew($1);}
      | E_MODULE                                                                                                                                  {$$ = vnameNew("MODULE");}
      ;


%%
expfun translation_unit getTranslation_unitDatabase(void)
{
   return PARSED_translation_unit;
}
expfun translation_unit parseTranslation_unit(nameset filenames)
{
   extern nameset yyITEMS;
   extern text yyCURRENT_ITEM;
   extern FILE *yyin;
   extern int yylineno;
   FILE *fo = getTranslation_unitParserOutputStream();

#if YYDEBUG
   extern int yydebug;
   yydebug = 1;
#endif

   yyITEMS = copy(filenames);
   yyCURRENT_ITEM = popFirst(yyITEMS);

   yyin = openR(yyCURRENT_ITEM, true);
   while((yyin eq NULL) &&
         (isEmpty(yyITEMS) eq false))
   {
      yyCURRENT_ITEM = popFirst(yyITEMS);
      yyin = openR(yyCURRENT_ITEM, true);
   }

   if (yyin ne NULL)
   {
      yylineno = 1;
      fprintf(fo, "- parsing '%s' ...\n", yyCURRENT_ITEM);
      yyparse();

      Free(yyITEMS);
      yyITEMS = NULL;

      return getTranslation_unitDatabase();
   }
   else
      exit(1);
}
extern void setTranslation_unitScannerToStream(FILE* stream);
expfun translation_unit parseTranslation_unitFromStream(FILE* fi = stdin,
                                                        int lineno = -1)
{
   extern int yylineno;

#if YYDEBUG
   extern int yydebug;
   yydebug = 1;
#endif

   if (fi ne NULL)
   {
      setTranslation_unitScannerToStream(fi);
      yylineno = lineno;

      yyparse();

      return getTranslation_unitDatabase();
   }
   else
      return NULL;
}
expfun translation_unit parseTranslation_unitFromInputStream(void)
{
   return parseTranslation_unitFromStream(getTranslation_unitParserInputStream(), -1);
}
extern void setTranslation_unitScannerToString(text string);
expfun translation_unit parseTranslation_unitFromString(nameset strings,
                                                        int lineno = -1)
{
   extern nameset yyITEMS;
   extern int yylineno;

#if YYDEBUG
   extern int yydebug;
   yydebug = 1;
#endif

   text item;

   yyITEMS = copy(strings);
   item = popFirst(yyITEMS);

   if (item ne NULL)
   {
      setTranslation_unitScannerToString(item);
      yylineno = lineno;

      yyparse();

      Free(yyITEMS);
      yyITEMS = NULL;

      return getTranslation_unitDatabase();
   }
   else
      return NULL;
}
expfun translation_unit parseTranslation_unitFromString(text string,
                                                        int lineno = -1)
{

#if YYDEBUG
   extern int yydebug;
   yydebug = 1;
#endif
   nameset strings;
   translation_unit t;

   if (string ne NULL)
   {
      strings = namesetNew(string);

      t = parseTranslation_unitFromString(strings, lineno);

      Free(strings);

      return t;
   }
   else
      return NULL;
}
