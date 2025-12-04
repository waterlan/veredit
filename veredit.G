include
{
   preambleComment : < 'COPYING.txt'
} 

force translation_unit : [verilog_item_list->items] [module_edit_list->edits]
                         (vnode)->rootNode
                 ;

//**************************  Edit Language ************************************

module_edit_list : (module_edit->array)+
                 ;

force module_edit : E_MODULE ( vname->name | WILDCARDS->pattern )
             '{' 
          [edit_list->edtList] 
          '}'
            ;

edit_list : (edit_element->array)+
          ;

force edit_element : rename_instance_statement->renameInst
             | addport_statement->addport
             | delport_statement->delport
             | editinst_statement->editinst
             | editassign_statement->editassign
             | editparameter_decl_statement->editparameter_decl
             | delete_module_statement->delModule
             | buffer_statement->bufferStat
             | remove_buf_statement->removeBufStat
             | buffernet_statement->bufferNetStat
             | insertObsInput_statement->insertObsInputStat
             | insertObsOutput_statement->insertObsOutputStat
             | listInst_statement->listInstStat
             | tiecell_statement->tiecellStat
             | shell_statement->shellStat
             | bufassigns_statement->bufAssign
             | pullup_pin_statement->pullupPin
             ;

force rename_instance_statement : INSTANCE vname->oldName '=' vname->newName
                                ;

force delete_module_statement : DELETE (bool)->deleteModule ()->deleteModule = true
                                [ EMPTY  (bool)->empty ()->empty = true ]
                              ;

force shell_statement : SHELL vname->shellName
                      ;

force bufassigns_statement : BUFASSIGNS vname->bufferName
                             [ E_INPUT IDENTIFIER->inputName = ['"A"'] ]
                             [ E_OUTPUT IDENTIFIER->outputName = ['"Z"'] ]
                          ;

force match_list : (match_item->array)+
                 ;

force match_item : ( vname->name | WILDCARDS->pattern )
             ;

force tiecell_statement : TIECELL vname->moduleName
                          E_OUTPUT vname->outputName
                          [ OTHER portmap->otherPins ]
                          NET simple_signal_list->Nets
                          [ EXCLUDE simple_signal_list->excludes ]
                          [ INST match_list->instances ]
                          [ LABEL IDENTIFIER->instLabel = ['""'] ]
                        ;


force insertObsInput_statement : INSERTOBSINPUT vname->moduleName
                               E_INPUT vname->inputName
                               E_OUTPUT vname->outputName
                               [ OTHER portmap->otherPins ]
                               NETS simple_signal_list->Nets
                               ;

force insertObsOutput_statement : INSERTOBSOUTPUT vname->moduleName
                                E_INPUT vname->inputName
                                E_OUTPUT vname->outputName
                                [ OTHER portmap->otherPins ]
                                NETS simple_signal_list->Nets
                               ;

force remove_buf_statement : REMOVEBUFFERS signal_list->signals
                             BUFFERLIST name_list->buffers
                           ;

force pullup_pin_statement : PULLUPPIN simple_signal_list->Pins
                           ;

force name_list : vname->array (',' vname->array)*
          ;

enum editassign_type : ADDASSIGN | DELASSIGN ;

force buffer_statement : BUFFEROUTPUTS vname->bufferName 
                         [ EXCLUDE signal_list->excludes ]
                       ;

force buffernet_statement : buffer_type->type vname->bufferName
                            [ E_INPUT IDENTIFIER->inputName = ['"A"'] ]
                            [ E_OUTPUT IDENTIFIER->outputName = ['"Z"'] ]
                            [instantiation_list->editinstances] 
                          ;

enum buffer_type : BUFFER | BUFFERINPUT ;

force editassign_statement : editassign_type->type
                             [assign_list->editassigns]
                             [ ALL (bool)->all ()->all = true ] 
                           ;

enum editparameter_decl_type : ADDPARAMETERDECL | DELPARAMETERDECL ;

force editparameter_decl_statement : editparameter_decl_type->type
                             [parameter_decl_list->editparameter_decls]
                             [ ALL (bool)->all ()->all = true ] 
                           ;


enum editinst_type : ADDINST | DELINST | MODINST;

force addport_statement : ADDPORTS 
                          [declaration_list->addports]
                  ;

enum editport_type : DELPORTS | RMPORTS | DELNETS ;

force delport_statement : editport_type->type
                            [port_list->delports]
                            [ ALL (bool)->all ()->all = true ] 
                          ;

force editinst_statement : editinst_type->type 
                            [ KEEPMODNAME  (bool)->keepmodname ()->keepmodname = true ]
                            [instantiation_list->editinstances] 
                            [ ALL (bool)->all ()->all = true ] 
                  ;

force listInst_statement : LISTINST
                           NET simple_signal->Net
                           ;

<dot_list : (dot->array)*
           >;

<dot : (text)p->parent
      (text)c->child
     (int) times = [0]
     >;

//**************************  Hierarchy ************************************

// recursive tree structure, B+ tree
// This is a tree of modules, not instances.
// A vnode repesents a module. There is only one
// vnode per module.

// A module can have multiple parents.

<force vnode : 
             (vnode->parents)+
             (vnode->instances)+
             (text)->name
             (int)->x
             (int)->y
             (bool)->fold
              module->block
              vnode->up &
              vnode->down &
             >;

//**************************  Verilog ************************************

verilog_item_list : (verilog_item->array)+
                  ;

force verilog_item : compiler_directive->compilerDirective
                   | module->block
                   ;


<module_list : (module->array)+
            >;
     
force module : MODULE vname->name [ '(' [ port_list->ports ] ')' ] ';'
         [module_item_list->items]
         (vnode)->modNode &
         ENDMODULE
       ;

force port_list : port->array (',' port->array)*
          ;

force port : port_expression->portExpression
           | ( '.' vname->portName '(' port_expression->portExpression2 ')' )
           ; 

force port_expression : port_reference->portReference
                      | compound_port_reference->cmpnd
                      ;

force compound_port_reference : '{' port_reference_list->portReferences '}'
                         ;

force port_reference_list : port_reference->array (',' port_reference->array)*
                    ;

force port_reference  : vname->name 
                [ ( '[' INT_CONSTANT->busIndex = [-1] ']' 
                   | range->rnge
                  )
                ]
                ;

force module_item_list : (module_item->array)+
                       ;

force module_item : declaration->declItem
            | continuous_assign->assignItem
            | instance->instanceItem
            | initial_statement->initialItem
            | parameter_override->overrideItem
	    | parameter_decl->parameter_declItem
//          | specify_block->specifyBlock
            ;

//force initial_statement : INITIALSTAT vname->name '(' STRINGVALUE->string ')' ';'
//                        ;

initial_statement : INITIALSTAT->initial
                  ;

parameter_override : DEFPARAM->defparam
                  ;

//specify_block : SPECIFYBLOCK->specifyblock
//              ;

force declaration_list : (declaration->array)+
                 ;

force declaration : signal_type->type [range->rnge] variable_list->signals ';'
            ;

enum signal_type : INPUT | OUTPUT | INOUT | WIRE | SUPPLY0 | SUPPLY1 | TRI | TRI0 | TRI1 | TRIOR | TRIAND | TRIREG | WOR | WAND
                 ;

force variable_list : variable_name->array (',' variable_name->array)*
                       ;

force variable_name : vname->name [ '=' expression->expr]
                  ;

expression :   INT_CONSTANT->number = [-1]
             | Signal->signal
             | STRINGVALUE->string
             ;

force assign_list : (continuous_assign->array)+
            ;

force continuous_assign : ASSIGN simple_signal->signal '=' expression->expr ';'
                   ;

force parameter_decl_list : (parameter_decl->array)+
            ;

force parameter_decl : PARAMETER simple_signal->signal '=' expression->expr ';'
                   ;

instantiation_list : (instance->array)+
                   ;

range : '[' INT_CONSTANT->begin ':' INT_CONSTANT->end ']'
      ;

force instance : vname->cellName
           vname->instName  '(' [ (portmap->connections | signal_list->connections_by_order) ] ')' ';'
         ;

force portmap : portmap_element->array (',' portmap_element->array)*
               ;
               
force portmap_element : '.' vname->pinName '(' [ signal_list->signals ] ')'
                ;

//<simple_signal_list : (simple_signal->array)*
//                    >;

simple_signal_list : (simple_signal->array)*
                    ;

simple_signal : [INT_CONSTANT->cnst = [-1] '\'' ] vname->name 
                [ ( '[' INT_CONSTANT->busIndex = [-1] ']' 
                   | range->rnge
                  )
                ]
                ;

compound_signal : '{' signal_list->signals '}'
                ;

force signal_list : Signal->array (',' Signal->array)*
            ;

force Signal : simple_signal->simple
       | compound_signal->cmpnd
       ;

force vname : IDENTIFIER->n 
            | (text) E_MODULE->n  = '"MODULE"'
     ;

// input_kw : INPUT |
//           '-' INPUT
//         ;

// specify tokens:
// Verilog tokens
MODULE    : 'module';
ENDMODULE : 'endmodule';
INPUT     : 'input';
OUTPUT    : 'output';
INOUT     : 'inout'; 
WIRE      : 'wire';
SUPPLY0   : 'supply0';
SUPPLY1   : 'supply1';
TRI       : 'tri';
TRI0      : 'tri0';
TRI1      : 'tri1';
TRIOR     : 'trior';
TRIAND    : 'triand';
TRIREG    : 'trireg';
WOR       : 'wor';
WAND      : 'wand';
ASSIGN    : 'assign';
PARAMETER : 'parameter';
// INITIALSTAT   : 'initial';

// edit-file tokens
E_MODULE        : 'MODULE';
E_OUTPUT        : '-output';
E_INPUT         : '-input';
INSTANCE        : '-instance';
ADDPORTS        : '-addports';
DELPORTS        : '-delports';
RMPORTS         : '-rmports';
DELNETS         : '-delnets';
ADDINST         : '-addinst';
MODINST         : '-modinst';
KEEPMODNAME     : '-keepmodname';
DELINST         : '-delinst';
ADDASSIGN       : '-addassign';
DELASSIGN       : '-delassign';
ADDPARAMETERDECL : '-addparameterdecl';
DELPARAMETERDECL : '-delparameterdecl';
DELETE          : '-delete';
EMPTY           : '-empty';
BUFFEROUTPUTS   : '-bufferoutputs';
EXCLUDE         : '-exclude';
REMOVEBUFFERS   : '-removebuffers';
BUFFERLIST      : '-bufferlist';
BUFFER          : '-buffer';
BUFFERINPUT     : '-bufferinput';
INSERTOBSINPUT  : '-insertobsinput';
OTHER           : '-other';
NETS            : '-nets';
INSERTOBSOUTPUT : '-insertobsoutput';
LISTINST        : '-listinst';
NET             : '-net';
TIECELL         : '-tiecell';
SHELL           : '-shell';
BUFASSIGNS      : '-bufferassigns';
PULLUPPIN       : '-pulluppin';
INST            : '-inst';
LABEL           : '-label';


text INITIALSTAT  : 'initial[ \t\n]+[^;]*[;]';
text DEFPARAM     : 'defparam[ \t\n]+[^;]*[;]';
//text SPECIFYBLOCK : 'specify[ \t\n]+(.|[\n])*[ \t\n]+endspecify';
text IDENTIFIER   : '[a-zA-Z_][a-zA-Z_0-9$]*';
text IDENTIFIER   : '\\[^ \t\n]+[ \t\n]';
text WILDCARDS    : '[a-zA-Z_0-9$]*[*][a-zA-Z_0-9$*]*';
text STRINGVALUE  : '["][^"]*["]' ;
int  INT_CONSTANT : '[0-9]+';
void ALL          : '-ALL';

linecomment = '"//"[^\n]*';
//comment = '"/*"([^*/]|[^*]"/"|"*"[^/]|"/"[^*])*"*"*"*/"';
// The above breaks on /** **/
// A better regular expression for C comments was created by Jeffrey Friedl
// and later modified by Fred Curtis. See Perl FAQ 6.
// comment = '/\*[^*]*\*+([^/*][^*]*\*+)*/|("(\\.|[^"\\])*"|'(\\.|[^'\\])*'|.[^/"'\\]*)';
// removing the `comments in quoted strings' part and transform it to flex:
comment = '"/*"[^*]*"*"+([^/*][^*]*"*"+)*"/"';

text compiler_directive : '"`"[^\n]*';

skip '{linecomment}';
skip '{comment}';

