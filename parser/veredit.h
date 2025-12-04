/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or veredit_yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int veredit_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum veredit_yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MODULE = 258,                  /* MODULE  */
    ENDMODULE = 259,               /* ENDMODULE  */
    INPUT = 260,                   /* INPUT  */
    OUTPUT = 261,                  /* OUTPUT  */
    INOUT = 262,                   /* INOUT  */
    WIRE = 263,                    /* WIRE  */
    SUPPLY0 = 264,                 /* SUPPLY0  */
    SUPPLY1 = 265,                 /* SUPPLY1  */
    TRI = 266,                     /* TRI  */
    TRI0 = 267,                    /* TRI0  */
    TRI1 = 268,                    /* TRI1  */
    TRIOR = 269,                   /* TRIOR  */
    TRIAND = 270,                  /* TRIAND  */
    TRIREG = 271,                  /* TRIREG  */
    WOR = 272,                     /* WOR  */
    WAND = 273,                    /* WAND  */
    ASSIGN = 274,                  /* ASSIGN  */
    PARAMETER = 275,               /* PARAMETER  */
    E_MODULE = 276,                /* E_MODULE  */
    E_OUTPUT = 277,                /* E_OUTPUT  */
    E_INPUT = 278,                 /* E_INPUT  */
    INSTANCE = 279,                /* INSTANCE  */
    ADDPORTS = 280,                /* ADDPORTS  */
    DELPORTS = 281,                /* DELPORTS  */
    RMPORTS = 282,                 /* RMPORTS  */
    DELNETS = 283,                 /* DELNETS  */
    ADDINST = 284,                 /* ADDINST  */
    MODINST = 285,                 /* MODINST  */
    KEEPMODNAME = 286,             /* KEEPMODNAME  */
    DELINST = 287,                 /* DELINST  */
    ADDASSIGN = 288,               /* ADDASSIGN  */
    DELASSIGN = 289,               /* DELASSIGN  */
    ADDPARAMETERDECL = 290,        /* ADDPARAMETERDECL  */
    DELPARAMETERDECL = 291,        /* DELPARAMETERDECL  */
    DELETE = 292,                  /* DELETE  */
    EMPTY = 293,                   /* EMPTY  */
    BUFFEROUTPUTS = 294,           /* BUFFEROUTPUTS  */
    EXCLUDE = 295,                 /* EXCLUDE  */
    REMOVEBUFFERS = 296,           /* REMOVEBUFFERS  */
    BUFFERLIST = 297,              /* BUFFERLIST  */
    BUFFER = 298,                  /* BUFFER  */
    BUFFERINPUT = 299,             /* BUFFERINPUT  */
    INSERTOBSINPUT = 300,          /* INSERTOBSINPUT  */
    OTHER = 301,                   /* OTHER  */
    NETS = 302,                    /* NETS  */
    INSERTOBSOUTPUT = 303,         /* INSERTOBSOUTPUT  */
    LISTINST = 304,                /* LISTINST  */
    NET = 305,                     /* NET  */
    TIECELL = 306,                 /* TIECELL  */
    SHELL = 307,                   /* SHELL  */
    BUFASSIGNS = 308,              /* BUFASSIGNS  */
    PULLUPPIN = 309,               /* PULLUPPIN  */
    INST = 310,                    /* INST  */
    LABEL = 311,                   /* LABEL  */
    INITIALSTAT = 312,             /* INITIALSTAT  */
    DEFPARAM = 313,                /* DEFPARAM  */
    IDENTIFIER = 314,              /* IDENTIFIER  */
    WILDCARDS = 315,               /* WILDCARDS  */
    STRINGVALUE = 316,             /* STRINGVALUE  */
    INT_CONSTANT = 317,            /* INT_CONSTANT  */
    ALL = 318,                     /* ALL  */
    compiler_directive = 319       /* compiler_directive  */
  };
  typedef enum veredit_yytokentype veredit_yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define MODULE 258
#define ENDMODULE 259
#define INPUT 260
#define OUTPUT 261
#define INOUT 262
#define WIRE 263
#define SUPPLY0 264
#define SUPPLY1 265
#define TRI 266
#define TRI0 267
#define TRI1 268
#define TRIOR 269
#define TRIAND 270
#define TRIREG 271
#define WOR 272
#define WAND 273
#define ASSIGN 274
#define PARAMETER 275
#define E_MODULE 276
#define E_OUTPUT 277
#define E_INPUT 278
#define INSTANCE 279
#define ADDPORTS 280
#define DELPORTS 281
#define RMPORTS 282
#define DELNETS 283
#define ADDINST 284
#define MODINST 285
#define KEEPMODNAME 286
#define DELINST 287
#define ADDASSIGN 288
#define DELASSIGN 289
#define ADDPARAMETERDECL 290
#define DELPARAMETERDECL 291
#define DELETE 292
#define EMPTY 293
#define BUFFEROUTPUTS 294
#define EXCLUDE 295
#define REMOVEBUFFERS 296
#define BUFFERLIST 297
#define BUFFER 298
#define BUFFERINPUT 299
#define INSERTOBSINPUT 300
#define OTHER 301
#define NETS 302
#define INSERTOBSOUTPUT 303
#define LISTINST 304
#define NET 305
#define TIECELL 306
#define SHELL 307
#define BUFASSIGNS 308
#define PULLUPPIN 309
#define INST 310
#define LABEL 311
#define INITIALSTAT 312
#define DEFPARAM 313
#define IDENTIFIER 314
#define WILDCARDS 315
#define STRINGVALUE 316
#define INT_CONSTANT 317
#define ALL 318
#define compiler_directive 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 193 "veredit.y"

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

#line 261 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE veredit_yylval;


int veredit_yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
