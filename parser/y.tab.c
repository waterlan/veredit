/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "veredit.y"

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

#line 262 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
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
  typedef enum yytokentype yytoken_kind_t;
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

#line 509 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MODULE = 3,                     /* MODULE  */
  YYSYMBOL_ENDMODULE = 4,                  /* ENDMODULE  */
  YYSYMBOL_INPUT = 5,                      /* INPUT  */
  YYSYMBOL_OUTPUT = 6,                     /* OUTPUT  */
  YYSYMBOL_INOUT = 7,                      /* INOUT  */
  YYSYMBOL_WIRE = 8,                       /* WIRE  */
  YYSYMBOL_SUPPLY0 = 9,                    /* SUPPLY0  */
  YYSYMBOL_SUPPLY1 = 10,                   /* SUPPLY1  */
  YYSYMBOL_TRI = 11,                       /* TRI  */
  YYSYMBOL_TRI0 = 12,                      /* TRI0  */
  YYSYMBOL_TRI1 = 13,                      /* TRI1  */
  YYSYMBOL_TRIOR = 14,                     /* TRIOR  */
  YYSYMBOL_TRIAND = 15,                    /* TRIAND  */
  YYSYMBOL_TRIREG = 16,                    /* TRIREG  */
  YYSYMBOL_WOR = 17,                       /* WOR  */
  YYSYMBOL_WAND = 18,                      /* WAND  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_PARAMETER = 20,                 /* PARAMETER  */
  YYSYMBOL_E_MODULE = 21,                  /* E_MODULE  */
  YYSYMBOL_E_OUTPUT = 22,                  /* E_OUTPUT  */
  YYSYMBOL_E_INPUT = 23,                   /* E_INPUT  */
  YYSYMBOL_INSTANCE = 24,                  /* INSTANCE  */
  YYSYMBOL_ADDPORTS = 25,                  /* ADDPORTS  */
  YYSYMBOL_DELPORTS = 26,                  /* DELPORTS  */
  YYSYMBOL_RMPORTS = 27,                   /* RMPORTS  */
  YYSYMBOL_DELNETS = 28,                   /* DELNETS  */
  YYSYMBOL_ADDINST = 29,                   /* ADDINST  */
  YYSYMBOL_MODINST = 30,                   /* MODINST  */
  YYSYMBOL_KEEPMODNAME = 31,               /* KEEPMODNAME  */
  YYSYMBOL_DELINST = 32,                   /* DELINST  */
  YYSYMBOL_ADDASSIGN = 33,                 /* ADDASSIGN  */
  YYSYMBOL_DELASSIGN = 34,                 /* DELASSIGN  */
  YYSYMBOL_ADDPARAMETERDECL = 35,          /* ADDPARAMETERDECL  */
  YYSYMBOL_DELPARAMETERDECL = 36,          /* DELPARAMETERDECL  */
  YYSYMBOL_DELETE = 37,                    /* DELETE  */
  YYSYMBOL_EMPTY = 38,                     /* EMPTY  */
  YYSYMBOL_BUFFEROUTPUTS = 39,             /* BUFFEROUTPUTS  */
  YYSYMBOL_EXCLUDE = 40,                   /* EXCLUDE  */
  YYSYMBOL_REMOVEBUFFERS = 41,             /* REMOVEBUFFERS  */
  YYSYMBOL_BUFFERLIST = 42,                /* BUFFERLIST  */
  YYSYMBOL_BUFFER = 43,                    /* BUFFER  */
  YYSYMBOL_BUFFERINPUT = 44,               /* BUFFERINPUT  */
  YYSYMBOL_INSERTOBSINPUT = 45,            /* INSERTOBSINPUT  */
  YYSYMBOL_OTHER = 46,                     /* OTHER  */
  YYSYMBOL_NETS = 47,                      /* NETS  */
  YYSYMBOL_INSERTOBSOUTPUT = 48,           /* INSERTOBSOUTPUT  */
  YYSYMBOL_LISTINST = 49,                  /* LISTINST  */
  YYSYMBOL_NET = 50,                       /* NET  */
  YYSYMBOL_TIECELL = 51,                   /* TIECELL  */
  YYSYMBOL_SHELL = 52,                     /* SHELL  */
  YYSYMBOL_BUFASSIGNS = 53,                /* BUFASSIGNS  */
  YYSYMBOL_PULLUPPIN = 54,                 /* PULLUPPIN  */
  YYSYMBOL_INST = 55,                      /* INST  */
  YYSYMBOL_LABEL = 56,                     /* LABEL  */
  YYSYMBOL_INITIALSTAT = 57,               /* INITIALSTAT  */
  YYSYMBOL_DEFPARAM = 58,                  /* DEFPARAM  */
  YYSYMBOL_IDENTIFIER = 59,                /* IDENTIFIER  */
  YYSYMBOL_WILDCARDS = 60,                 /* WILDCARDS  */
  YYSYMBOL_STRINGVALUE = 61,               /* STRINGVALUE  */
  YYSYMBOL_INT_CONSTANT = 62,              /* INT_CONSTANT  */
  YYSYMBOL_ALL = 63,                       /* ALL  */
  YYSYMBOL_compiler_directive = 64,        /* compiler_directive  */
  YYSYMBOL_65_ = 65,                       /* '{'  */
  YYSYMBOL_66_ = 66,                       /* '}'  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_68_ = 68,                       /* ','  */
  YYSYMBOL_69_ = 69,                       /* '('  */
  YYSYMBOL_70_ = 70,                       /* ')'  */
  YYSYMBOL_71_ = 71,                       /* ';'  */
  YYSYMBOL_72_ = 72,                       /* '.'  */
  YYSYMBOL_73_ = 73,                       /* '['  */
  YYSYMBOL_74_ = 74,                       /* ']'  */
  YYSYMBOL_75_ = 75,                       /* ':'  */
  YYSYMBOL_76_ = 76,                       /* '\''  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_translation_unit = 78,          /* translation_unit  */
  YYSYMBOL_module_edit_list = 79,          /* module_edit_list  */
  YYSYMBOL_module_edit = 80,               /* module_edit  */
  YYSYMBOL_edit_list = 81,                 /* edit_list  */
  YYSYMBOL_edit_element = 82,              /* edit_element  */
  YYSYMBOL_rename_instance_statement = 83, /* rename_instance_statement  */
  YYSYMBOL_delete_module_statement = 84,   /* delete_module_statement  */
  YYSYMBOL_shell_statement = 85,           /* shell_statement  */
  YYSYMBOL_bufassigns_statement = 86,      /* bufassigns_statement  */
  YYSYMBOL_match_list = 87,                /* match_list  */
  YYSYMBOL_match_item = 88,                /* match_item  */
  YYSYMBOL_tiecell_statement = 89,         /* tiecell_statement  */
  YYSYMBOL_insertObsInput_statement = 90,  /* insertObsInput_statement  */
  YYSYMBOL_insertObsOutput_statement = 91, /* insertObsOutput_statement  */
  YYSYMBOL_remove_buf_statement = 92,      /* remove_buf_statement  */
  YYSYMBOL_pullup_pin_statement = 93,      /* pullup_pin_statement  */
  YYSYMBOL_name_list = 94,                 /* name_list  */
  YYSYMBOL_editassign_type = 95,           /* editassign_type  */
  YYSYMBOL_buffer_statement = 96,          /* buffer_statement  */
  YYSYMBOL_buffernet_statement = 97,       /* buffernet_statement  */
  YYSYMBOL_buffer_type = 98,               /* buffer_type  */
  YYSYMBOL_editassign_statement = 99,      /* editassign_statement  */
  YYSYMBOL_editparameter_decl_type = 100,  /* editparameter_decl_type  */
  YYSYMBOL_editparameter_decl_statement = 101, /* editparameter_decl_statement  */
  YYSYMBOL_editinst_type = 102,            /* editinst_type  */
  YYSYMBOL_addport_statement = 103,        /* addport_statement  */
  YYSYMBOL_editport_type = 104,            /* editport_type  */
  YYSYMBOL_delport_statement = 105,        /* delport_statement  */
  YYSYMBOL_editinst_statement = 106,       /* editinst_statement  */
  YYSYMBOL_listInst_statement = 107,       /* listInst_statement  */
  YYSYMBOL_verilog_item_list = 108,        /* verilog_item_list  */
  YYSYMBOL_verilog_item = 109,             /* verilog_item  */
  YYSYMBOL_module = 110,                   /* module  */
  YYSYMBOL_port_list = 111,                /* port_list  */
  YYSYMBOL_port = 112,                     /* port  */
  YYSYMBOL_port_expression = 113,          /* port_expression  */
  YYSYMBOL_compound_port_reference = 114,  /* compound_port_reference  */
  YYSYMBOL_port_reference_list = 115,      /* port_reference_list  */
  YYSYMBOL_port_reference = 116,           /* port_reference  */
  YYSYMBOL_module_item_list = 117,         /* module_item_list  */
  YYSYMBOL_module_item = 118,              /* module_item  */
  YYSYMBOL_initial_statement = 119,        /* initial_statement  */
  YYSYMBOL_parameter_override = 120,       /* parameter_override  */
  YYSYMBOL_declaration_list = 121,         /* declaration_list  */
  YYSYMBOL_declaration = 122,              /* declaration  */
  YYSYMBOL_signal_type = 123,              /* signal_type  */
  YYSYMBOL_variable_list = 124,            /* variable_list  */
  YYSYMBOL_variable_name = 125,            /* variable_name  */
  YYSYMBOL_expression = 126,               /* expression  */
  YYSYMBOL_assign_list = 127,              /* assign_list  */
  YYSYMBOL_continuous_assign = 128,        /* continuous_assign  */
  YYSYMBOL_parameter_decl_list = 129,      /* parameter_decl_list  */
  YYSYMBOL_parameter_decl = 130,           /* parameter_decl  */
  YYSYMBOL_instantiation_list = 131,       /* instantiation_list  */
  YYSYMBOL_range = 132,                    /* range  */
  YYSYMBOL_instance = 133,                 /* instance  */
  YYSYMBOL_portmap = 134,                  /* portmap  */
  YYSYMBOL_portmap_element = 135,          /* portmap_element  */
  YYSYMBOL_simple_signal_list = 136,       /* simple_signal_list  */
  YYSYMBOL_simple_signal = 137,            /* simple_signal  */
  YYSYMBOL_compound_signal = 138,          /* compound_signal  */
  YYSYMBOL_signal_list = 139,              /* signal_list  */
  YYSYMBOL_Signal = 140,                   /* Signal  */
  YYSYMBOL_vname = 141                     /* vname  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   659

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  331

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    76,
      69,    70,     2,     2,    68,     2,    72,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    75,    71,
       2,    67,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,    66,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   387,   387,   388,   389,   392,   393,   396,   397,   398,
     399,   402,   403,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     425,   428,   429,   432,   435,   436,   437,   438,   441,   442,
     445,   446,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   467,   468,
     471,   472,   475,   478,   481,   482,   485,   486,   489,   490,
     493,   494,   495,   496,   497,   498,   499,   500,   503,   504,
     507,   508,   509,   510,   513,   514,   517,   518,   519,   520,
     523,   524,   525,   528,   529,   532,   533,   534,   537,   538,
     539,   540,   543,   544,   545,   546,   547,   548,   549,   550,
     553,   556,   557,   560,   561,   564,   565,   566,   567,   568,
     569,   572,   573,   576,   577,   580,   581,   584,   587,   588,
     591,   592,   593,   596,   597,   600,   601,   602,   603,   604,
     605,   608,   611,   614,   615,   618,   619,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   638,   639,   642,   643,   646,   647,   648,   651,   652,
     655,   658,   659,   662,   665,   666,   669,   672,   673,   674,
     677,   678,   681,   682,   685,   686,   689,   690,   691,   692,
     693,   694,   697,   700,   701,   704,   705,   708,   709
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MODULE", "ENDMODULE",
  "INPUT", "OUTPUT", "INOUT", "WIRE", "SUPPLY0", "SUPPLY1", "TRI", "TRI0",
  "TRI1", "TRIOR", "TRIAND", "TRIREG", "WOR", "WAND", "ASSIGN",
  "PARAMETER", "E_MODULE", "E_OUTPUT", "E_INPUT", "INSTANCE", "ADDPORTS",
  "DELPORTS", "RMPORTS", "DELNETS", "ADDINST", "MODINST", "KEEPMODNAME",
  "DELINST", "ADDASSIGN", "DELASSIGN", "ADDPARAMETERDECL",
  "DELPARAMETERDECL", "DELETE", "EMPTY", "BUFFEROUTPUTS", "EXCLUDE",
  "REMOVEBUFFERS", "BUFFERLIST", "BUFFER", "BUFFERINPUT", "INSERTOBSINPUT",
  "OTHER", "NETS", "INSERTOBSOUTPUT", "LISTINST", "NET", "TIECELL",
  "SHELL", "BUFASSIGNS", "PULLUPPIN", "INST", "LABEL", "INITIALSTAT",
  "DEFPARAM", "IDENTIFIER", "WILDCARDS", "STRINGVALUE", "INT_CONSTANT",
  "ALL", "compiler_directive", "'{'", "'}'", "'='", "','", "'('", "')'",
  "';'", "'.'", "'['", "']'", "':'", "'\\''", "$accept",
  "translation_unit", "module_edit_list", "module_edit", "edit_list",
  "edit_element", "rename_instance_statement", "delete_module_statement",
  "shell_statement", "bufassigns_statement", "match_list", "match_item",
  "tiecell_statement", "insertObsInput_statement",
  "insertObsOutput_statement", "remove_buf_statement",
  "pullup_pin_statement", "name_list", "editassign_type",
  "buffer_statement", "buffernet_statement", "buffer_type",
  "editassign_statement", "editparameter_decl_type",
  "editparameter_decl_statement", "editinst_type", "addport_statement",
  "editport_type", "delport_statement", "editinst_statement",
  "listInst_statement", "verilog_item_list", "verilog_item", "module",
  "port_list", "port", "port_expression", "compound_port_reference",
  "port_reference_list", "port_reference", "module_item_list",
  "module_item", "initial_statement", "parameter_override",
  "declaration_list", "declaration", "signal_type", "variable_list",
  "variable_name", "expression", "assign_list", "continuous_assign",
  "parameter_decl_list", "parameter_decl", "instantiation_list", "range",
  "instance", "portmap", "portmap_element", "simple_signal_list",
  "simple_signal", "compound_signal", "signal_list", "Signal", "vname", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-278)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   176,   142,  -278,    49,    17,  -278,     6,  -278,  -278,
    -278,  -278,   -35,    -3,    46,  -278,  -278,    17,  -278,    65,
     321,   195,   523,   176,    50,   176,   198,  -278,  -278,  -278,
    -278,    61,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,   120,   120,  -278,
    -278,   339,  -278,  -278,  -278,  -278,    10,  -278,  -278,  -278,
     176,   176,   356,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,   114,   176,    25,  -278,  -278,   176,   176,
     106,   176,   176,   176,  -278,  -278,   558,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,    16,  -278,  -278,
     176,  -278,    -5,  -278,    12,  -278,    30,  -278,  -278,  -278,
    -278,   593,   236,  -278,   395,   122,    73,   135,   189,  -278,
     188,   220,   223,   240,  -278,  -278,   241,   221,  -278,   176,
     251,   252,   309,   356,  -278,  -278,   353,    25,  -278,  -278,
     -26,  -278,   371,   372,   120,   414,  -278,   259,   120,  -278,
    -278,  -278,    28,  -278,     7,  -278,     0,  -278,    88,  -278,
      95,  -278,  -278,    38,  -278,  -278,   176,  -278,   413,    33,
    -278,   469,   311,   176,   134,   373,  -278,   134,   362,   176,
    -278,   229,   134,    55,   176,  -278,    25,   248,   176,    25,
     176,   176,  -278,   176,   379,   380,  -278,  -278,  -278,   381,
     382,   176,  -278,  -278,  -278,   125,  -278,  -278,  -278,  -278,
    -278,   374,  -278,   487,  -278,   383,   369,  -278,   188,   375,
    -278,   315,   376,  -278,  -278,  -278,   377,   176,   307,  -278,
     313,  -278,   387,  -278,   388,  -278,  -278,   421,   427,   -25,
    -278,   428,   176,   196,  -278,  -278,  -278,   384,   389,  -278,
    -278,  -278,  -278,  -278,   390,   385,   391,   392,   176,   176,
     176,   385,  -278,   401,   176,   402,   176,  -278,   317,   115,
    -278,  -278,  -278,  -278,   264,   341,   -24,    67,  -278,   176,
    -278,  -278,   314,   385,  -278,   385,  -278,  -278,  -278,   148,
     405,   176,  -278,    63,   120,   209,   120,   154,   224,  -278,
     155,  -278,  -278,  -278,  -278,  -278,  -278,   148,   406,   148,
     407,   408,  -278,   120,   120,   239,   216,  -278,   253,  -278,
    -278,   148,   409,   410,   450,   263,  -278,  -278,  -278,   451,
    -278
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   113,     0,     3,     5,     4,   111,   114,
     198,   197,     0,     0,     0,     1,     6,     2,   112,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   123,   126,
     125,   131,   120,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,   141,
     142,     0,   133,   138,   139,   135,     0,   136,   140,   137,
       0,     0,    94,    95,    96,    97,    90,    92,    91,    66,
      67,    84,    85,    32,     0,     0,    78,    79,     0,     0,
       0,     0,     0,     0,   184,    10,     0,    11,    13,    19,
      27,    28,    26,    23,    24,    21,    29,    83,    20,    22,
       0,    17,    89,    18,   109,    14,   101,    15,    16,    25,
       8,     0,     0,   128,     0,     0,     0,     0,     0,   132,
       0,     0,   189,     0,   117,   134,     0,     0,   161,     0,
     164,     0,     0,    93,   143,    31,    69,     0,   195,   196,
       0,   193,     0,     0,     0,     0,    33,    37,    63,     9,
      12,    81,    82,   168,    77,    87,    88,   171,   108,   105,
     107,   174,    99,   100,     7,   127,     0,   119,     0,     0,
     122,     0,     0,     0,     0,     0,   191,     0,     0,     0,
     146,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,   185,    80,   169,     0,
       0,    73,    86,   172,   104,   106,   103,   175,    98,   129,
     116,     0,   118,     0,   130,     0,   188,   167,   165,     0,
     166,     0,     0,   162,   145,   163,     0,     0,     0,   180,
       0,    30,    68,   192,    62,    64,   194,     0,     0,     0,
      35,    36,    75,    76,   102,   124,   115,     0,     0,   190,
     170,   187,   173,   178,     0,     0,     0,     0,     0,     0,
       0,     0,   184,     0,    71,     0,    72,   176,     0,     0,
     181,   177,   179,    65,     0,     0,     0,    57,    34,    74,
     186,   183,     0,     0,   184,     0,   184,   184,   184,     0,
       0,    70,   182,     0,    59,     0,    61,    56,    55,    41,
      53,    38,    40,    49,   184,   184,   184,     0,     0,     0,
       0,     0,    39,    58,    60,    54,    52,    48,    51,    47,
      45,     0,     0,     0,     0,    50,    46,    44,    43,     0,
      42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,   504,   268,   490,   -54,  -278,  -278,  -278,  -278,
     -16,  -277,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,   506,  -278,   411,   398,   346,  -278,  -278,   -18,
     -97,   -49,  -278,  -278,  -278,   -48,  -278,   393,   337,    85,
    -278,   -84,  -278,   -92,  -146,   -50,   -93,   -80,   265,  -144,
     -44,  -278,  -130,  -137,    -1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,    86,    87,    88,    89,    90,    91,
     300,   301,    92,    93,    94,    95,    96,   234,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     7,     8,     9,    26,    27,    28,    29,   112,    30,
      51,    52,    53,    54,   133,    55,    56,   127,   128,   219,
     152,    57,   156,    58,   160,   119,    59,   228,   229,   148,
     138,   139,   140,   141,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    14,   125,   121,   123,   113,   129,   187,   201,     1,
     157,   161,   205,   153,   134,    48,   188,   168,    31,    60,
      48,   261,    31,   312,   115,   262,   287,     2,    10,   199,
     200,    10,   150,    10,    19,    47,    20,   220,     2,   312,
     220,   312,   189,   158,   255,   220,    10,    47,   312,    15,
      60,    10,   236,   230,    10,   130,   232,   150,   155,   131,
     132,   161,    21,   202,   203,   161,    11,   207,   198,    11,
       3,    11,   176,   136,   213,   159,    10,   142,   143,   151,
     145,   146,   147,   126,    11,   185,    10,   120,    10,    11,
     137,   197,    11,   162,    10,    23,   264,   266,    23,   154,
     192,   208,    25,    60,   196,    31,   116,   288,   207,    10,
     304,    22,   207,    60,    11,    31,    10,   120,   277,   125,
     137,   114,   289,   290,    11,   226,    11,   227,   130,   120,
      23,   255,    11,   291,   118,    24,    10,    25,    23,   282,
     294,    10,   296,   297,   298,    25,    10,    11,   209,   161,
     161,   204,   135,    60,    11,    10,   144,    60,   206,    60,
     313,   314,   315,    10,   125,    31,   249,    60,    31,    10,
      60,   207,   216,   207,    11,    10,    10,   120,   130,    11,
     137,   276,   120,   231,    11,   281,   161,   235,   244,   237,
     238,   169,   239,    11,   306,   217,   218,    10,   207,   137,
      60,    11,    13,   293,    60,   295,   171,    11,   299,   307,
     308,   311,    60,    11,    11,   299,   120,    10,   265,    61,
      62,    63,    64,    65,    66,    67,   254,    68,    69,    70,
      71,    72,    73,   196,    74,    11,    75,    10,    76,    77,
      78,    60,    60,    79,    80,    10,    81,    82,    83,    84,
     196,   172,   196,   196,   196,    11,   305,   273,   274,   275,
      10,    85,   222,    60,   173,    60,   116,   225,   117,   196,
     196,   196,   323,    16,    10,    11,   299,   255,    60,   309,
     310,   194,   195,    11,    10,    16,   120,   174,   302,   179,
      60,   316,   180,   318,   321,   322,   175,   179,    11,   302,
     224,   120,   165,   178,   166,   325,   302,   177,   302,   324,
     283,   284,    11,   299,   233,   302,   189,   302,   182,   329,
     302,   183,    11,   299,   302,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    10,   124,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      10,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   255,   184,   256,    49,    50,
      11,   189,   189,   257,   292,   214,   215,   285,   286,   251,
     215,   280,   215,   186,   190,   191,    49,    50,    11,   167,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    10,   210,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    10,   221,   193,   215,   240,   241,
     242,   243,   248,   259,   245,   247,   250,   252,   253,   260,
     263,   268,    49,    50,    11,   189,   258,   227,   267,   269,
     278,   279,   271,   272,   303,   317,   319,   320,   326,   327,
      49,    50,    11,   212,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      10,   246,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    10,   328,
     330,    17,   111,    18,   170,   211,   223,   163,     0,     0,
     270,     0,   181,     0,     0,     0,    49,    50,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    50,    11,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,    74,     0,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,    81,    82,    83,    84,     0,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    67,   110,
      68,    69,    70,    71,    72,    73,     0,    74,     0,    75,
       0,    76,    77,    78,     0,     0,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,    61,    62,    63,
      64,    65,    66,    67,   149,    68,    69,    70,    71,    72,
      73,     0,    74,     0,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164
};

static const yytype_int16 yycheck[] =
{
       1,     2,    51,    47,    48,    23,    56,   137,   154,     3,
     102,   104,   158,    97,    62,    20,    42,   114,    19,    20,
      20,    46,    23,   300,    25,    50,    50,    21,    21,    22,
      23,    21,    86,    21,    69,    19,    71,   174,    21,   316,
     177,   318,    68,    31,    68,   182,    21,    19,   325,     0,
      51,    21,   189,   183,    21,    56,   186,   111,    63,    60,
      61,   154,    65,    63,   156,   158,    59,   160,   152,    59,
      64,    59,   122,    74,   171,    63,    21,    78,    79,    63,
      81,    82,    83,    73,    59,   133,    21,    62,    21,    59,
      65,    63,    59,    63,    21,    65,   242,   243,    65,   100,
     144,    63,    72,   104,   148,   106,    68,    40,   201,    21,
      47,    65,   205,   114,    59,   116,    21,    62,   262,   168,
      65,    71,    55,    56,    59,    70,    59,    72,   129,    62,
      65,    68,    59,   279,    73,    70,    21,    72,    65,   269,
     284,    21,   286,   287,   288,    72,    21,    59,   166,   242,
     243,    63,    38,   154,    59,    21,    50,   158,    63,   160,
     304,   305,   306,    21,   213,   166,   216,   168,   169,    21,
     171,   264,   173,   266,    59,    21,    21,    62,   179,    59,
      65,   261,    62,   184,    59,    70,   279,   188,    63,   190,
     191,    69,   193,    59,    40,    61,    62,    21,   291,    65,
     201,    59,    60,   283,   205,   285,    71,    59,    60,    55,
      56,    56,   213,    59,    59,    60,    62,    21,    22,    24,
      25,    26,    27,    28,    29,    30,   227,    32,    33,    34,
      35,    36,    37,   277,    39,    59,    41,    21,    43,    44,
      45,   242,   243,    48,    49,    21,    51,    52,    53,    54,
     294,    62,   296,   297,   298,    59,    47,   258,   259,   260,
      21,    66,   177,   264,    76,   266,    68,   182,    70,   313,
     314,   315,    56,     5,    21,    59,    60,    68,   279,    55,
      56,    22,    23,    59,    21,    17,    62,    67,   289,    68,
     291,   307,    71,   309,    55,    56,    73,    68,    59,   300,
      71,    62,    66,    62,    68,   321,   307,    67,   309,    56,
      46,    47,    59,    60,    66,   316,    68,   318,    67,    56,
     321,    69,    59,    60,   325,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    68,    67,    70,    57,    58,
      59,    68,    68,    70,    70,    74,    75,    46,    47,    74,
      75,    74,    75,    40,    23,    23,    57,    58,    59,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    62,    22,    75,    59,    59,
      59,    59,    73,    22,    70,    62,    71,    71,    71,    22,
      22,    62,    57,    58,    59,    68,    68,    72,    74,    69,
      59,    59,    71,    71,    59,    59,    59,    59,    59,    59,
      57,    58,    59,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    59,
      59,     7,    22,     7,   116,   169,   179,   106,    -1,    -1,
     255,    -1,   129,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    41,    -1,    43,    44,    45,    -1,
      -1,    48,    49,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    66,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    41,
      -1,    43,    44,    45,    -1,    -1,    48,    49,    -1,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    66,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    41,    -1,    43,    44,    45,    -1,
      -1,    48,    49,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    21,    64,    78,    79,    80,   108,   109,   110,
      21,    59,   141,    60,   141,     0,    80,    79,   109,    69,
      71,    65,    65,    65,    70,    72,   111,   112,   113,   114,
     116,   141,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    57,
      58,   117,   118,   119,   120,   122,   123,   128,   130,   133,
     141,    24,    25,    26,    27,    28,    29,    30,    32,    33,
      34,    35,    36,    37,    39,    41,    43,    44,    45,    48,
      49,    51,    52,    53,    54,    66,    81,    82,    83,    84,
      85,    86,    89,    90,    91,    92,    93,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      66,    81,   115,   116,    71,   141,    68,    70,    73,   132,
      62,   137,   141,   137,     4,   118,    73,   124,   125,   132,
     141,   141,   141,   121,   122,    38,   141,    65,   137,   138,
     139,   140,   141,   141,    50,   141,   141,   141,   136,    66,
      82,    63,   127,   128,   141,    63,   129,   130,    31,    63,
     131,   133,    63,   111,    66,    66,    68,     4,   117,    69,
     112,    71,    62,    76,    67,    73,   132,    67,    62,    68,
      71,   124,    67,    69,    67,   122,    40,   139,    42,    68,
      23,    23,   137,    22,    22,    23,   137,    63,   128,    22,
      23,   131,    63,   130,    63,   131,    63,   133,    63,   116,
       4,   113,     4,   117,    74,    75,   141,    61,    62,   126,
     140,    62,   126,   125,    71,   126,    70,    72,   134,   135,
     139,   141,   139,    66,    94,   141,   140,   141,   141,   141,
      59,    59,    59,    59,    63,    70,     4,    62,    73,   132,
      71,    74,    71,    71,   141,    68,    70,    70,    68,    22,
      22,    46,    50,    22,   131,    22,   131,    74,    62,    69,
     135,    71,    71,   141,   141,   141,   134,   136,    59,    59,
      74,    70,   139,    46,    47,    46,    47,    50,    40,    55,
      56,   131,    70,   134,   136,   134,   136,   136,   136,    60,
      87,    88,   141,    59,    47,    47,    40,    55,    56,    55,
      56,    56,    88,   136,   136,   136,    87,    59,    87,    59,
      59,    55,    56,    56,    56,    87,    59,    59,    59,    56,
      59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    78,    78,    79,    79,    80,    80,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    84,    84,    85,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    92,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99,    99,    99,   100,   100,   101,   101,   101,   101,
     102,   102,   102,   103,   103,   104,   104,   104,   105,   105,
     105,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   108,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   115,   115,
     116,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   119,   120,   121,   121,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   125,   126,   126,   126,   127,   127,
     128,   129,   129,   130,   131,   131,   132,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   137,   137,
     137,   137,   138,   139,   139,   140,   140,   141,   141
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     2,     5,     4,     5,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     1,     2,     6,     4,     4,     2,     1,     2,
       1,     1,    14,    12,    12,    10,    12,    10,    10,     8,
      12,    10,    10,     8,    10,     8,     8,     6,    10,     8,
      10,     8,     4,     2,     1,     3,     1,     1,     4,     2,
       7,     5,     5,     3,     6,     4,     4,     2,     1,     1,
       3,     2,     2,     1,     1,     1,     3,     2,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     3,     2,
       2,     1,     4,     3,     3,     2,     3,     2,     2,     1,
       3,     1,     2,     1,     1,     8,     7,     5,     7,     6,
       4,     1,     3,     1,     5,     1,     1,     3,     1,     3,
       4,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     2,
       5,     1,     2,     5,     1,     2,     5,     6,     5,     6,
       1,     3,     5,     4,     0,     2,     6,     4,     3,     1,
       4,     2,     3,     1,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* translation_unit: verilog_item_list module_edit_list  */
#line 387 "veredit.y"
                                                                                                                                                  {(yyval.translation_unit_field) = translation_unitNew((yyvsp[-1].verilog_item_list_field), (yyvsp[0].module_edit_list_field)); PARSED_translation_unit = (yyval.translation_unit_field);}
#line 1949 "y.tab.c"
    break;

  case 3: /* translation_unit: module_edit_list  */
#line 388 "veredit.y"
                                                                                                                                                  {(yyval.translation_unit_field) = translation_unitNew(verilog_item_listNew(), (yyvsp[0].module_edit_list_field)); PARSED_translation_unit = (yyval.translation_unit_field);}
#line 1955 "y.tab.c"
    break;

  case 4: /* translation_unit: verilog_item_list  */
#line 389 "veredit.y"
                                                                                                                                                  {(yyval.translation_unit_field) = translation_unitNew((yyvsp[0].verilog_item_list_field), module_edit_listNew()); PARSED_translation_unit = (yyval.translation_unit_field);}
#line 1961 "y.tab.c"
    break;

  case 5: /* module_edit_list: module_edit  */
#line 392 "veredit.y"
                                                                                                                                                  {(yyval.module_edit_list_field) = module_edit_listNew(); add((yyvsp[0].module_edit_field), (yyval.module_edit_list_field));}
#line 1967 "y.tab.c"
    break;

  case 6: /* module_edit_list: module_edit_list module_edit  */
#line 393 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].module_edit_field), (yyval.module_edit_list_field));}
#line 1973 "y.tab.c"
    break;

  case 7: /* module_edit: E_MODULE vname '{' edit_list '}'  */
#line 396 "veredit.y"
                                                                                                                                                  {(yyval.module_edit_field) = module_editNew((yyvsp[-3].vname_field), (yyvsp[-1].edit_list_field), (text) NULL);}
#line 1979 "y.tab.c"
    break;

  case 8: /* module_edit: E_MODULE vname '{' '}'  */
#line 397 "veredit.y"
                                                                                                                                                  {(yyval.module_edit_field) = module_editNew((yyvsp[-2].vname_field), edit_listNew(), (text) NULL);}
#line 1985 "y.tab.c"
    break;

  case 9: /* module_edit: E_MODULE WILDCARDS '{' edit_list '}'  */
#line 398 "veredit.y"
                                                                                                                                                  {(yyval.module_edit_field) = module_editNew((vname) NULL, (yyvsp[-1].edit_list_field), (yyvsp[-3].text_field));}
#line 1991 "y.tab.c"
    break;

  case 10: /* module_edit: E_MODULE WILDCARDS '{' '}'  */
#line 399 "veredit.y"
                                                                                                                                                  {(yyval.module_edit_field) = module_editNew((vname) NULL, edit_listNew(), (yyvsp[-2].text_field));}
#line 1997 "y.tab.c"
    break;

  case 11: /* edit_list: edit_element  */
#line 402 "veredit.y"
                                                                                                                                                  {(yyval.edit_list_field) = edit_listNew(); add((yyvsp[0].edit_element_field), (yyval.edit_list_field));}
#line 2003 "y.tab.c"
    break;

  case 12: /* edit_list: edit_list edit_element  */
#line 403 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].edit_element_field), (yyval.edit_list_field));}
#line 2009 "y.tab.c"
    break;

  case 13: /* edit_element: rename_instance_statement  */
#line 406 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((yyvsp[0].rename_instance_statement_field), (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2015 "y.tab.c"
    break;

  case 14: /* edit_element: addport_statement  */
#line 407 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (yyvsp[0].addport_statement_field), (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2021 "y.tab.c"
    break;

  case 15: /* edit_element: delport_statement  */
#line 408 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (yyvsp[0].delport_statement_field), (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2027 "y.tab.c"
    break;

  case 16: /* edit_element: editinst_statement  */
#line 409 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (yyvsp[0].editinst_statement_field), (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2033 "y.tab.c"
    break;

  case 17: /* edit_element: editassign_statement  */
#line 410 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (yyvsp[0].editassign_statement_field), (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2039 "y.tab.c"
    break;

  case 18: /* edit_element: editparameter_decl_statement  */
#line 411 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (yyvsp[0].editparameter_decl_statement_field), (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2045 "y.tab.c"
    break;

  case 19: /* edit_element: delete_module_statement  */
#line 412 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (yyvsp[0].delete_module_statement_field), (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2051 "y.tab.c"
    break;

  case 20: /* edit_element: buffer_statement  */
#line 413 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (yyvsp[0].buffer_statement_field), (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2057 "y.tab.c"
    break;

  case 21: /* edit_element: remove_buf_statement  */
#line 414 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (yyvsp[0].remove_buf_statement_field), (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2063 "y.tab.c"
    break;

  case 22: /* edit_element: buffernet_statement  */
#line 415 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (yyvsp[0].buffernet_statement_field), (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2069 "y.tab.c"
    break;

  case 23: /* edit_element: insertObsInput_statement  */
#line 416 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (yyvsp[0].insertObsInput_statement_field), (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2075 "y.tab.c"
    break;

  case 24: /* edit_element: insertObsOutput_statement  */
#line 417 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (yyvsp[0].insertObsOutput_statement_field), (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2081 "y.tab.c"
    break;

  case 25: /* edit_element: listInst_statement  */
#line 418 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (yyvsp[0].listInst_statement_field), (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2087 "y.tab.c"
    break;

  case 26: /* edit_element: tiecell_statement  */
#line 419 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (yyvsp[0].tiecell_statement_field), (shell_statement) NULL, (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2093 "y.tab.c"
    break;

  case 27: /* edit_element: shell_statement  */
#line 420 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (yyvsp[0].shell_statement_field), (bufassigns_statement) NULL, (pullup_pin_statement) NULL);}
#line 2099 "y.tab.c"
    break;

  case 28: /* edit_element: bufassigns_statement  */
#line 421 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (yyvsp[0].bufassigns_statement_field), (pullup_pin_statement) NULL);}
#line 2105 "y.tab.c"
    break;

  case 29: /* edit_element: pullup_pin_statement  */
#line 422 "veredit.y"
                                                                                                                                                  {(yyval.edit_element_field) = edit_elementNew((rename_instance_statement) NULL, (addport_statement) NULL, (delport_statement) NULL, (editinst_statement) NULL, (editassign_statement) NULL, (editparameter_decl_statement) NULL, (delete_module_statement) NULL, (buffer_statement) NULL, (remove_buf_statement) NULL, (buffernet_statement) NULL, (insertObsInput_statement) NULL, (insertObsOutput_statement) NULL, (listInst_statement) NULL, (tiecell_statement) NULL, (shell_statement) NULL, (bufassigns_statement) NULL, (yyvsp[0].pullup_pin_statement_field));}
#line 2111 "y.tab.c"
    break;

  case 30: /* rename_instance_statement: INSTANCE vname '=' vname  */
#line 425 "veredit.y"
                                                                                                                                                  {(yyval.rename_instance_statement_field) = rename_instance_statementNew((yyvsp[-2].vname_field), (yyvsp[0].vname_field));}
#line 2117 "y.tab.c"
    break;

  case 31: /* delete_module_statement: DELETE EMPTY  */
#line 428 "veredit.y"
                                                                                                                                                  {(yyval.delete_module_statement_field) = delete_module_statementNew(); (yyval.delete_module_statement_field)->deleteModule = true; (yyval.delete_module_statement_field)->empty = true;}
#line 2123 "y.tab.c"
    break;

  case 32: /* delete_module_statement: DELETE  */
#line 429 "veredit.y"
                                                                                                                                                  {(yyval.delete_module_statement_field) = delete_module_statementNew(); (yyval.delete_module_statement_field)->deleteModule = true;}
#line 2129 "y.tab.c"
    break;

  case 33: /* shell_statement: SHELL vname  */
#line 432 "veredit.y"
                                                                                                                                                  {(yyval.shell_statement_field) = shell_statementNew((yyvsp[0].vname_field));}
#line 2135 "y.tab.c"
    break;

  case 34: /* bufassigns_statement: BUFASSIGNS vname E_INPUT IDENTIFIER E_OUTPUT IDENTIFIER  */
#line 435 "veredit.y"
                                                                                                                                                  {(yyval.bufassigns_statement_field) = bufassigns_statementNew((yyvsp[-4].vname_field), (yyvsp[-2].text_field), (yyvsp[0].text_field));}
#line 2141 "y.tab.c"
    break;

  case 35: /* bufassigns_statement: BUFASSIGNS vname E_OUTPUT IDENTIFIER  */
#line 436 "veredit.y"
                                                                                                                                                  {(yyval.bufassigns_statement_field) = bufassigns_statementNew((yyvsp[-2].vname_field), "A", (yyvsp[0].text_field));}
#line 2147 "y.tab.c"
    break;

  case 36: /* bufassigns_statement: BUFASSIGNS vname E_INPUT IDENTIFIER  */
#line 437 "veredit.y"
                                                                                                                                                  {(yyval.bufassigns_statement_field) = bufassigns_statementNew((yyvsp[-2].vname_field), (yyvsp[0].text_field), "Z");}
#line 2153 "y.tab.c"
    break;

  case 37: /* bufassigns_statement: BUFASSIGNS vname  */
#line 438 "veredit.y"
                                                                                                                                                  {(yyval.bufassigns_statement_field) = bufassigns_statementNew((yyvsp[0].vname_field), "A", "Z");}
#line 2159 "y.tab.c"
    break;

  case 38: /* match_list: match_item  */
#line 441 "veredit.y"
                                                                                                                                                  {(yyval.match_list_field) = match_listNew(); add((yyvsp[0].match_item_field), (yyval.match_list_field));}
#line 2165 "y.tab.c"
    break;

  case 39: /* match_list: match_list match_item  */
#line 442 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].match_item_field), (yyval.match_list_field));}
#line 2171 "y.tab.c"
    break;

  case 40: /* match_item: vname  */
#line 445 "veredit.y"
                                                                                                                                                  {(yyval.match_item_field) = match_itemNew((yyvsp[0].vname_field), (text) NULL);}
#line 2177 "y.tab.c"
    break;

  case 41: /* match_item: WILDCARDS  */
#line 446 "veredit.y"
                                                                                                                                                  {(yyval.match_item_field) = match_itemNew((vname) NULL, (yyvsp[0].text_field));}
#line 2183 "y.tab.c"
    break;

  case 42: /* tiecell_statement: TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list EXCLUDE simple_signal_list INST match_list LABEL IDENTIFIER  */
#line 449 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-12].vname_field), (yyvsp[-10].vname_field), (yyvsp[-8].portmap_field), (yyvsp[-6].simple_signal_list_field), (yyvsp[-4].simple_signal_list_field), (yyvsp[-2].match_list_field), (yyvsp[0].text_field));}
#line 2189 "y.tab.c"
    break;

  case 43: /* tiecell_statement: TIECELL vname E_OUTPUT vname NET simple_signal_list EXCLUDE simple_signal_list INST match_list LABEL IDENTIFIER  */
#line 450 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-10].vname_field), (yyvsp[-8].vname_field), portmapNew(), (yyvsp[-6].simple_signal_list_field), (yyvsp[-4].simple_signal_list_field), (yyvsp[-2].match_list_field), (yyvsp[0].text_field));}
#line 2195 "y.tab.c"
    break;

  case 44: /* tiecell_statement: TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list INST match_list LABEL IDENTIFIER  */
#line 451 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-10].vname_field), (yyvsp[-8].vname_field), (yyvsp[-6].portmap_field), (yyvsp[-4].simple_signal_list_field), simple_signal_listNew(), (yyvsp[-2].match_list_field), (yyvsp[0].text_field));}
#line 2201 "y.tab.c"
    break;

  case 45: /* tiecell_statement: TIECELL vname E_OUTPUT vname NET simple_signal_list INST match_list LABEL IDENTIFIER  */
#line 452 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-8].vname_field), (yyvsp[-6].vname_field), portmapNew(), (yyvsp[-4].simple_signal_list_field), simple_signal_listNew(), (yyvsp[-2].match_list_field), (yyvsp[0].text_field));}
#line 2207 "y.tab.c"
    break;

  case 46: /* tiecell_statement: TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list EXCLUDE simple_signal_list LABEL IDENTIFIER  */
#line 453 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-10].vname_field), (yyvsp[-8].vname_field), (yyvsp[-6].portmap_field), (yyvsp[-4].simple_signal_list_field), (yyvsp[-2].simple_signal_list_field), match_listNew(), (yyvsp[0].text_field));}
#line 2213 "y.tab.c"
    break;

  case 47: /* tiecell_statement: TIECELL vname E_OUTPUT vname NET simple_signal_list EXCLUDE simple_signal_list LABEL IDENTIFIER  */
#line 454 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-8].vname_field), (yyvsp[-6].vname_field), portmapNew(), (yyvsp[-4].simple_signal_list_field), (yyvsp[-2].simple_signal_list_field), match_listNew(), (yyvsp[0].text_field));}
#line 2219 "y.tab.c"
    break;

  case 48: /* tiecell_statement: TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list LABEL IDENTIFIER  */
#line 455 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-8].vname_field), (yyvsp[-6].vname_field), (yyvsp[-4].portmap_field), (yyvsp[-2].simple_signal_list_field), simple_signal_listNew(), match_listNew(), (yyvsp[0].text_field));}
#line 2225 "y.tab.c"
    break;

  case 49: /* tiecell_statement: TIECELL vname E_OUTPUT vname NET simple_signal_list LABEL IDENTIFIER  */
#line 456 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-6].vname_field), (yyvsp[-4].vname_field), portmapNew(), (yyvsp[-2].simple_signal_list_field), simple_signal_listNew(), match_listNew(), (yyvsp[0].text_field));}
#line 2231 "y.tab.c"
    break;

  case 50: /* tiecell_statement: TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list EXCLUDE simple_signal_list INST match_list  */
#line 457 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-10].vname_field), (yyvsp[-8].vname_field), (yyvsp[-6].portmap_field), (yyvsp[-4].simple_signal_list_field), (yyvsp[-2].simple_signal_list_field), (yyvsp[0].match_list_field), "");}
#line 2237 "y.tab.c"
    break;

  case 51: /* tiecell_statement: TIECELL vname E_OUTPUT vname NET simple_signal_list EXCLUDE simple_signal_list INST match_list  */
#line 458 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-8].vname_field), (yyvsp[-6].vname_field), portmapNew(), (yyvsp[-4].simple_signal_list_field), (yyvsp[-2].simple_signal_list_field), (yyvsp[0].match_list_field), "");}
#line 2243 "y.tab.c"
    break;

  case 52: /* tiecell_statement: TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list INST match_list  */
#line 459 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-8].vname_field), (yyvsp[-6].vname_field), (yyvsp[-4].portmap_field), (yyvsp[-2].simple_signal_list_field), simple_signal_listNew(), (yyvsp[0].match_list_field), "");}
#line 2249 "y.tab.c"
    break;

  case 53: /* tiecell_statement: TIECELL vname E_OUTPUT vname NET simple_signal_list INST match_list  */
#line 460 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-6].vname_field), (yyvsp[-4].vname_field), portmapNew(), (yyvsp[-2].simple_signal_list_field), simple_signal_listNew(), (yyvsp[0].match_list_field), "");}
#line 2255 "y.tab.c"
    break;

  case 54: /* tiecell_statement: TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list EXCLUDE simple_signal_list  */
#line 461 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-8].vname_field), (yyvsp[-6].vname_field), (yyvsp[-4].portmap_field), (yyvsp[-2].simple_signal_list_field), (yyvsp[0].simple_signal_list_field), match_listNew(), "");}
#line 2261 "y.tab.c"
    break;

  case 55: /* tiecell_statement: TIECELL vname E_OUTPUT vname NET simple_signal_list EXCLUDE simple_signal_list  */
#line 462 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-6].vname_field), (yyvsp[-4].vname_field), portmapNew(), (yyvsp[-2].simple_signal_list_field), (yyvsp[0].simple_signal_list_field), match_listNew(), "");}
#line 2267 "y.tab.c"
    break;

  case 56: /* tiecell_statement: TIECELL vname E_OUTPUT vname OTHER portmap NET simple_signal_list  */
#line 463 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-6].vname_field), (yyvsp[-4].vname_field), (yyvsp[-2].portmap_field), (yyvsp[0].simple_signal_list_field), simple_signal_listNew(), match_listNew(), "");}
#line 2273 "y.tab.c"
    break;

  case 57: /* tiecell_statement: TIECELL vname E_OUTPUT vname NET simple_signal_list  */
#line 464 "veredit.y"
                                                                                                                                                  {(yyval.tiecell_statement_field) = tiecell_statementNew((yyvsp[-4].vname_field), (yyvsp[-2].vname_field), portmapNew(), (yyvsp[0].simple_signal_list_field), simple_signal_listNew(), match_listNew(), "");}
#line 2279 "y.tab.c"
    break;

  case 58: /* insertObsInput_statement: INSERTOBSINPUT vname E_INPUT vname E_OUTPUT vname OTHER portmap NETS simple_signal_list  */
#line 467 "veredit.y"
                                                                                                                                                  {(yyval.insertObsInput_statement_field) = insertObsInput_statementNew((yyvsp[-8].vname_field), (yyvsp[-6].vname_field), (yyvsp[-4].vname_field), (yyvsp[-2].portmap_field), (yyvsp[0].simple_signal_list_field));}
#line 2285 "y.tab.c"
    break;

  case 59: /* insertObsInput_statement: INSERTOBSINPUT vname E_INPUT vname E_OUTPUT vname NETS simple_signal_list  */
#line 468 "veredit.y"
                                                                                                                                                  {(yyval.insertObsInput_statement_field) = insertObsInput_statementNew((yyvsp[-6].vname_field), (yyvsp[-4].vname_field), (yyvsp[-2].vname_field), portmapNew(), (yyvsp[0].simple_signal_list_field));}
#line 2291 "y.tab.c"
    break;

  case 60: /* insertObsOutput_statement: INSERTOBSOUTPUT vname E_INPUT vname E_OUTPUT vname OTHER portmap NETS simple_signal_list  */
#line 471 "veredit.y"
                                                                                                                                                  {(yyval.insertObsOutput_statement_field) = insertObsOutput_statementNew((yyvsp[-8].vname_field), (yyvsp[-6].vname_field), (yyvsp[-4].vname_field), (yyvsp[-2].portmap_field), (yyvsp[0].simple_signal_list_field));}
#line 2297 "y.tab.c"
    break;

  case 61: /* insertObsOutput_statement: INSERTOBSOUTPUT vname E_INPUT vname E_OUTPUT vname NETS simple_signal_list  */
#line 472 "veredit.y"
                                                                                                                                                  {(yyval.insertObsOutput_statement_field) = insertObsOutput_statementNew((yyvsp[-6].vname_field), (yyvsp[-4].vname_field), (yyvsp[-2].vname_field), portmapNew(), (yyvsp[0].simple_signal_list_field));}
#line 2303 "y.tab.c"
    break;

  case 62: /* remove_buf_statement: REMOVEBUFFERS signal_list BUFFERLIST name_list  */
#line 475 "veredit.y"
                                                                                                                                                  {(yyval.remove_buf_statement_field) = remove_buf_statementNew((yyvsp[-2].signal_list_field), (yyvsp[0].name_list_field));}
#line 2309 "y.tab.c"
    break;

  case 63: /* pullup_pin_statement: PULLUPPIN simple_signal_list  */
#line 478 "veredit.y"
                                                                                                                                                  {(yyval.pullup_pin_statement_field) = pullup_pin_statementNew((yyvsp[0].simple_signal_list_field));}
#line 2315 "y.tab.c"
    break;

  case 64: /* name_list: vname  */
#line 481 "veredit.y"
                                                                                                                                                  {(yyval.name_list_field) = name_listNew(); add((yyvsp[0].vname_field), (yyval.name_list_field));}
#line 2321 "y.tab.c"
    break;

  case 65: /* name_list: name_list ',' vname  */
#line 482 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].vname_field), (yyval.name_list_field));}
#line 2327 "y.tab.c"
    break;

  case 66: /* editassign_type: ADDASSIGN  */
#line 485 "veredit.y"
                                                                                                                                                  {(yyval.editassign_type_field) = _ADDASSIGN;}
#line 2333 "y.tab.c"
    break;

  case 67: /* editassign_type: DELASSIGN  */
#line 486 "veredit.y"
                                                                                                                                                  {(yyval.editassign_type_field) = _DELASSIGN;}
#line 2339 "y.tab.c"
    break;

  case 68: /* buffer_statement: BUFFEROUTPUTS vname EXCLUDE signal_list  */
#line 489 "veredit.y"
                                                                                                                                                  {(yyval.buffer_statement_field) = buffer_statementNew((yyvsp[-2].vname_field), (yyvsp[0].signal_list_field));}
#line 2345 "y.tab.c"
    break;

  case 69: /* buffer_statement: BUFFEROUTPUTS vname  */
#line 490 "veredit.y"
                                                                                                                                                  {(yyval.buffer_statement_field) = buffer_statementNew((yyvsp[0].vname_field), signal_listNew());}
#line 2351 "y.tab.c"
    break;

  case 70: /* buffernet_statement: buffer_type vname E_INPUT IDENTIFIER E_OUTPUT IDENTIFIER instantiation_list  */
#line 493 "veredit.y"
                                                                                                                                                  {(yyval.buffernet_statement_field) = buffernet_statementNew((yyvsp[-6].buffer_type_field), (yyvsp[-5].vname_field), (yyvsp[-3].text_field), (yyvsp[-1].text_field), (yyvsp[0].instantiation_list_field));}
#line 2357 "y.tab.c"
    break;

  case 71: /* buffernet_statement: buffer_type vname E_OUTPUT IDENTIFIER instantiation_list  */
#line 494 "veredit.y"
                                                                                                                                                  {(yyval.buffernet_statement_field) = buffernet_statementNew((yyvsp[-4].buffer_type_field), (yyvsp[-3].vname_field), "A", (yyvsp[-1].text_field), (yyvsp[0].instantiation_list_field));}
#line 2363 "y.tab.c"
    break;

  case 72: /* buffernet_statement: buffer_type vname E_INPUT IDENTIFIER instantiation_list  */
#line 495 "veredit.y"
                                                                                                                                                  {(yyval.buffernet_statement_field) = buffernet_statementNew((yyvsp[-4].buffer_type_field), (yyvsp[-3].vname_field), (yyvsp[-1].text_field), "Z", (yyvsp[0].instantiation_list_field));}
#line 2369 "y.tab.c"
    break;

  case 73: /* buffernet_statement: buffer_type vname instantiation_list  */
#line 496 "veredit.y"
                                                                                                                                                  {(yyval.buffernet_statement_field) = buffernet_statementNew((yyvsp[-2].buffer_type_field), (yyvsp[-1].vname_field), "A", "Z", (yyvsp[0].instantiation_list_field));}
#line 2375 "y.tab.c"
    break;

  case 74: /* buffernet_statement: buffer_type vname E_INPUT IDENTIFIER E_OUTPUT IDENTIFIER  */
#line 497 "veredit.y"
                                                                                                                                                  {(yyval.buffernet_statement_field) = buffernet_statementNew((yyvsp[-5].buffer_type_field), (yyvsp[-4].vname_field), (yyvsp[-2].text_field), (yyvsp[0].text_field), instantiation_listNew());}
#line 2381 "y.tab.c"
    break;

  case 75: /* buffernet_statement: buffer_type vname E_OUTPUT IDENTIFIER  */
#line 498 "veredit.y"
                                                                                                                                                  {(yyval.buffernet_statement_field) = buffernet_statementNew((yyvsp[-3].buffer_type_field), (yyvsp[-2].vname_field), "A", (yyvsp[0].text_field), instantiation_listNew());}
#line 2387 "y.tab.c"
    break;

  case 76: /* buffernet_statement: buffer_type vname E_INPUT IDENTIFIER  */
#line 499 "veredit.y"
                                                                                                                                                  {(yyval.buffernet_statement_field) = buffernet_statementNew((yyvsp[-3].buffer_type_field), (yyvsp[-2].vname_field), (yyvsp[0].text_field), "Z", instantiation_listNew());}
#line 2393 "y.tab.c"
    break;

  case 77: /* buffernet_statement: buffer_type vname  */
#line 500 "veredit.y"
                                                                                                                                                  {(yyval.buffernet_statement_field) = buffernet_statementNew((yyvsp[-1].buffer_type_field), (yyvsp[0].vname_field), "A", "Z", instantiation_listNew());}
#line 2399 "y.tab.c"
    break;

  case 78: /* buffer_type: BUFFER  */
#line 503 "veredit.y"
                                                                                                                                                  {(yyval.buffer_type_field) = _BUFFER;}
#line 2405 "y.tab.c"
    break;

  case 79: /* buffer_type: BUFFERINPUT  */
#line 504 "veredit.y"
                                                                                                                                                  {(yyval.buffer_type_field) = _BUFFERINPUT;}
#line 2411 "y.tab.c"
    break;

  case 80: /* editassign_statement: editassign_type assign_list ALL  */
#line 507 "veredit.y"
                                                                                                                                                  {(yyval.editassign_statement_field) = editassign_statementNew((yyvsp[-2].editassign_type_field), (yyvsp[-1].assign_list_field)); (yyval.editassign_statement_field)->all = true;}
#line 2417 "y.tab.c"
    break;

  case 81: /* editassign_statement: editassign_type ALL  */
#line 508 "veredit.y"
                                                                                                                                                  {(yyval.editassign_statement_field) = editassign_statementNew((yyvsp[-1].editassign_type_field), assign_listNew()); (yyval.editassign_statement_field)->all = true;}
#line 2423 "y.tab.c"
    break;

  case 82: /* editassign_statement: editassign_type assign_list  */
#line 509 "veredit.y"
                                                                                                                                                  {(yyval.editassign_statement_field) = editassign_statementNew((yyvsp[-1].editassign_type_field), (yyvsp[0].assign_list_field));}
#line 2429 "y.tab.c"
    break;

  case 83: /* editassign_statement: editassign_type  */
#line 510 "veredit.y"
                                                                                                                                                  {(yyval.editassign_statement_field) = editassign_statementNew((yyvsp[0].editassign_type_field), assign_listNew());}
#line 2435 "y.tab.c"
    break;

  case 84: /* editparameter_decl_type: ADDPARAMETERDECL  */
#line 513 "veredit.y"
                                                                                                                                                  {(yyval.editparameter_decl_type_field) = _ADDPARAMETERDECL;}
#line 2441 "y.tab.c"
    break;

  case 85: /* editparameter_decl_type: DELPARAMETERDECL  */
#line 514 "veredit.y"
                                                                                                                                                  {(yyval.editparameter_decl_type_field) = _DELPARAMETERDECL;}
#line 2447 "y.tab.c"
    break;

  case 86: /* editparameter_decl_statement: editparameter_decl_type parameter_decl_list ALL  */
#line 517 "veredit.y"
                                                                                                                                                  {(yyval.editparameter_decl_statement_field) = editparameter_decl_statementNew((yyvsp[-2].editparameter_decl_type_field), (yyvsp[-1].parameter_decl_list_field)); (yyval.editparameter_decl_statement_field)->all = true;}
#line 2453 "y.tab.c"
    break;

  case 87: /* editparameter_decl_statement: editparameter_decl_type ALL  */
#line 518 "veredit.y"
                                                                                                                                                  {(yyval.editparameter_decl_statement_field) = editparameter_decl_statementNew((yyvsp[-1].editparameter_decl_type_field), parameter_decl_listNew()); (yyval.editparameter_decl_statement_field)->all = true;}
#line 2459 "y.tab.c"
    break;

  case 88: /* editparameter_decl_statement: editparameter_decl_type parameter_decl_list  */
#line 519 "veredit.y"
                                                                                                                                                  {(yyval.editparameter_decl_statement_field) = editparameter_decl_statementNew((yyvsp[-1].editparameter_decl_type_field), (yyvsp[0].parameter_decl_list_field));}
#line 2465 "y.tab.c"
    break;

  case 89: /* editparameter_decl_statement: editparameter_decl_type  */
#line 520 "veredit.y"
                                                                                                                                                  {(yyval.editparameter_decl_statement_field) = editparameter_decl_statementNew((yyvsp[0].editparameter_decl_type_field), parameter_decl_listNew());}
#line 2471 "y.tab.c"
    break;

  case 90: /* editinst_type: ADDINST  */
#line 523 "veredit.y"
                                                                                                                                                  {(yyval.editinst_type_field) = _ADDINST;}
#line 2477 "y.tab.c"
    break;

  case 91: /* editinst_type: DELINST  */
#line 524 "veredit.y"
                                                                                                                                                  {(yyval.editinst_type_field) = _DELINST;}
#line 2483 "y.tab.c"
    break;

  case 92: /* editinst_type: MODINST  */
#line 525 "veredit.y"
                                                                                                                                                  {(yyval.editinst_type_field) = _MODINST;}
#line 2489 "y.tab.c"
    break;

  case 93: /* addport_statement: ADDPORTS declaration_list  */
#line 528 "veredit.y"
                                                                                                                                                  {(yyval.addport_statement_field) = addport_statementNew((yyvsp[0].declaration_list_field));}
#line 2495 "y.tab.c"
    break;

  case 94: /* addport_statement: ADDPORTS  */
#line 529 "veredit.y"
                                                                                                                                                  {(yyval.addport_statement_field) = addport_statementNew(declaration_listNew());}
#line 2501 "y.tab.c"
    break;

  case 95: /* editport_type: DELPORTS  */
#line 532 "veredit.y"
                                                                                                                                                  {(yyval.editport_type_field) = _DELPORTS;}
#line 2507 "y.tab.c"
    break;

  case 96: /* editport_type: RMPORTS  */
#line 533 "veredit.y"
                                                                                                                                                  {(yyval.editport_type_field) = _RMPORTS;}
#line 2513 "y.tab.c"
    break;

  case 97: /* editport_type: DELNETS  */
#line 534 "veredit.y"
                                                                                                                                                  {(yyval.editport_type_field) = _DELNETS;}
#line 2519 "y.tab.c"
    break;

  case 98: /* delport_statement: editport_type port_list ALL  */
#line 537 "veredit.y"
                                                                                                                                                  {(yyval.delport_statement_field) = delport_statementNew((yyvsp[-2].editport_type_field), (yyvsp[-1].port_list_field)); (yyval.delport_statement_field)->all = true;}
#line 2525 "y.tab.c"
    break;

  case 99: /* delport_statement: editport_type ALL  */
#line 538 "veredit.y"
                                                                                                                                                  {(yyval.delport_statement_field) = delport_statementNew((yyvsp[-1].editport_type_field), port_listNew()); (yyval.delport_statement_field)->all = true;}
#line 2531 "y.tab.c"
    break;

  case 100: /* delport_statement: editport_type port_list  */
#line 539 "veredit.y"
                                                                                                                                                  {(yyval.delport_statement_field) = delport_statementNew((yyvsp[-1].editport_type_field), (yyvsp[0].port_list_field));}
#line 2537 "y.tab.c"
    break;

  case 101: /* delport_statement: editport_type  */
#line 540 "veredit.y"
                                                                                                                                                  {(yyval.delport_statement_field) = delport_statementNew((yyvsp[0].editport_type_field), port_listNew());}
#line 2543 "y.tab.c"
    break;

  case 102: /* editinst_statement: editinst_type KEEPMODNAME instantiation_list ALL  */
#line 543 "veredit.y"
                                                                                                                                                  {(yyval.editinst_statement_field) = editinst_statementNew((yyvsp[-3].editinst_type_field), (yyvsp[-1].instantiation_list_field)); (yyval.editinst_statement_field)->keepmodname = true; (yyval.editinst_statement_field)->all = true;}
#line 2549 "y.tab.c"
    break;

  case 103: /* editinst_statement: editinst_type instantiation_list ALL  */
#line 544 "veredit.y"
                                                                                                                                                  {(yyval.editinst_statement_field) = editinst_statementNew((yyvsp[-2].editinst_type_field), (yyvsp[-1].instantiation_list_field)); (yyval.editinst_statement_field)->all = true;}
#line 2555 "y.tab.c"
    break;

  case 104: /* editinst_statement: editinst_type KEEPMODNAME ALL  */
#line 545 "veredit.y"
                                                                                                                                                  {(yyval.editinst_statement_field) = editinst_statementNew((yyvsp[-2].editinst_type_field), instantiation_listNew()); (yyval.editinst_statement_field)->keepmodname = true; (yyval.editinst_statement_field)->all = true;}
#line 2561 "y.tab.c"
    break;

  case 105: /* editinst_statement: editinst_type ALL  */
#line 546 "veredit.y"
                                                                                                                                                  {(yyval.editinst_statement_field) = editinst_statementNew((yyvsp[-1].editinst_type_field), instantiation_listNew()); (yyval.editinst_statement_field)->all = true;}
#line 2567 "y.tab.c"
    break;

  case 106: /* editinst_statement: editinst_type KEEPMODNAME instantiation_list  */
#line 547 "veredit.y"
                                                                                                                                                  {(yyval.editinst_statement_field) = editinst_statementNew((yyvsp[-2].editinst_type_field), (yyvsp[0].instantiation_list_field)); (yyval.editinst_statement_field)->keepmodname = true;}
#line 2573 "y.tab.c"
    break;

  case 107: /* editinst_statement: editinst_type instantiation_list  */
#line 548 "veredit.y"
                                                                                                                                                  {(yyval.editinst_statement_field) = editinst_statementNew((yyvsp[-1].editinst_type_field), (yyvsp[0].instantiation_list_field));}
#line 2579 "y.tab.c"
    break;

  case 108: /* editinst_statement: editinst_type KEEPMODNAME  */
#line 549 "veredit.y"
                                                                                                                                                  {(yyval.editinst_statement_field) = editinst_statementNew((yyvsp[-1].editinst_type_field), instantiation_listNew()); (yyval.editinst_statement_field)->keepmodname = true;}
#line 2585 "y.tab.c"
    break;

  case 109: /* editinst_statement: editinst_type  */
#line 550 "veredit.y"
                                                                                                                                                  {(yyval.editinst_statement_field) = editinst_statementNew((yyvsp[0].editinst_type_field), instantiation_listNew());}
#line 2591 "y.tab.c"
    break;

  case 110: /* listInst_statement: LISTINST NET simple_signal  */
#line 553 "veredit.y"
                                                                                                                                                  {(yyval.listInst_statement_field) = listInst_statementNew((yyvsp[0].simple_signal_field));}
#line 2597 "y.tab.c"
    break;

  case 111: /* verilog_item_list: verilog_item  */
#line 556 "veredit.y"
                                                                                                                                                  {(yyval.verilog_item_list_field) = verilog_item_listNew(); add((yyvsp[0].verilog_item_field), (yyval.verilog_item_list_field));}
#line 2603 "y.tab.c"
    break;

  case 112: /* verilog_item_list: verilog_item_list verilog_item  */
#line 557 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].verilog_item_field), (yyval.verilog_item_list_field));}
#line 2609 "y.tab.c"
    break;

  case 113: /* verilog_item: compiler_directive  */
#line 560 "veredit.y"
                                                                                                                                                  {(yyval.verilog_item_field) = verilog_itemNew((yyvsp[0].text_field), (module) NULL);}
#line 2615 "y.tab.c"
    break;

  case 114: /* verilog_item: module  */
#line 561 "veredit.y"
                                                                                                                                                  {(yyval.verilog_item_field) = verilog_itemNew((text) NULL, (yyvsp[0].module_field));}
#line 2621 "y.tab.c"
    break;

  case 115: /* module: MODULE vname '(' port_list ')' ';' module_item_list ENDMODULE  */
#line 564 "veredit.y"
                                                                                                                                                  {(yyval.module_field) = moduleNew((yyvsp[-6].vname_field), (yyvsp[-4].port_list_field), (yyvsp[-1].module_item_list_field));}
#line 2627 "y.tab.c"
    break;

  case 116: /* module: MODULE vname '(' ')' ';' module_item_list ENDMODULE  */
#line 565 "veredit.y"
                                                                                                                                                  {(yyval.module_field) = moduleNew((yyvsp[-5].vname_field), port_listNew(), (yyvsp[-1].module_item_list_field));}
#line 2633 "y.tab.c"
    break;

  case 117: /* module: MODULE vname ';' module_item_list ENDMODULE  */
#line 566 "veredit.y"
                                                                                                                                                  {(yyval.module_field) = moduleNew((yyvsp[-3].vname_field), port_listNew(), (yyvsp[-1].module_item_list_field));}
#line 2639 "y.tab.c"
    break;

  case 118: /* module: MODULE vname '(' port_list ')' ';' ENDMODULE  */
#line 567 "veredit.y"
                                                                                                                                                  {(yyval.module_field) = moduleNew((yyvsp[-5].vname_field), (yyvsp[-3].port_list_field), module_item_listNew());}
#line 2645 "y.tab.c"
    break;

  case 119: /* module: MODULE vname '(' ')' ';' ENDMODULE  */
#line 568 "veredit.y"
                                                                                                                                                  {(yyval.module_field) = moduleNew((yyvsp[-4].vname_field), port_listNew(), module_item_listNew());}
#line 2651 "y.tab.c"
    break;

  case 120: /* module: MODULE vname ';' ENDMODULE  */
#line 569 "veredit.y"
                                                                                                                                                  {(yyval.module_field) = moduleNew((yyvsp[-2].vname_field), port_listNew(), module_item_listNew());}
#line 2657 "y.tab.c"
    break;

  case 121: /* port_list: port  */
#line 572 "veredit.y"
                                                                                                                                                  {(yyval.port_list_field) = port_listNew(); add((yyvsp[0].port_field), (yyval.port_list_field));}
#line 2663 "y.tab.c"
    break;

  case 122: /* port_list: port_list ',' port  */
#line 573 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].port_field), (yyval.port_list_field));}
#line 2669 "y.tab.c"
    break;

  case 123: /* port: port_expression  */
#line 576 "veredit.y"
                                                                                                                                                  {(yyval.port_field) = portNew((yyvsp[0].port_expression_field), (vname) NULL, (port_expression) NULL);}
#line 2675 "y.tab.c"
    break;

  case 124: /* port: '.' vname '(' port_expression ')'  */
#line 577 "veredit.y"
                                                                                                                                                  {(yyval.port_field) = portNew((port_expression) NULL, (yyvsp[-3].vname_field), (yyvsp[-1].port_expression_field));}
#line 2681 "y.tab.c"
    break;

  case 125: /* port_expression: port_reference  */
#line 580 "veredit.y"
                                                                                                                                                  {(yyval.port_expression_field) = port_expressionNew((yyvsp[0].port_reference_field), (compound_port_reference) NULL);}
#line 2687 "y.tab.c"
    break;

  case 126: /* port_expression: compound_port_reference  */
#line 581 "veredit.y"
                                                                                                                                                  {(yyval.port_expression_field) = port_expressionNew((port_reference) NULL, (yyvsp[0].compound_port_reference_field));}
#line 2693 "y.tab.c"
    break;

  case 127: /* compound_port_reference: '{' port_reference_list '}'  */
#line 584 "veredit.y"
                                                                                                                                                  {(yyval.compound_port_reference_field) = compound_port_referenceNew((yyvsp[-1].port_reference_list_field));}
#line 2699 "y.tab.c"
    break;

  case 128: /* port_reference_list: port_reference  */
#line 587 "veredit.y"
                                                                                                                                                  {(yyval.port_reference_list_field) = port_reference_listNew(); add((yyvsp[0].port_reference_field), (yyval.port_reference_list_field));}
#line 2705 "y.tab.c"
    break;

  case 129: /* port_reference_list: port_reference_list ',' port_reference  */
#line 588 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].port_reference_field), (yyval.port_reference_list_field));}
#line 2711 "y.tab.c"
    break;

  case 130: /* port_reference: vname '[' INT_CONSTANT ']'  */
#line 591 "veredit.y"
                                                                                                                                                  {(yyval.port_reference_field) = port_referenceNew((yyvsp[-3].vname_field), (yyvsp[-1].int_field), (range) NULL);}
#line 2717 "y.tab.c"
    break;

  case 131: /* port_reference: vname  */
#line 592 "veredit.y"
                                                                                                                                                  {(yyval.port_reference_field) = port_referenceNew((yyvsp[0].vname_field), (int) -1, (range) NULL);}
#line 2723 "y.tab.c"
    break;

  case 132: /* port_reference: vname range  */
#line 593 "veredit.y"
                                                                                                                                                  {(yyval.port_reference_field) = port_referenceNew((yyvsp[-1].vname_field), (int) -1, (yyvsp[0].range_field));}
#line 2729 "y.tab.c"
    break;

  case 133: /* module_item_list: module_item  */
#line 596 "veredit.y"
                                                                                                                                                  {(yyval.module_item_list_field) = module_item_listNew(); add((yyvsp[0].module_item_field), (yyval.module_item_list_field));}
#line 2735 "y.tab.c"
    break;

  case 134: /* module_item_list: module_item_list module_item  */
#line 597 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].module_item_field), (yyval.module_item_list_field));}
#line 2741 "y.tab.c"
    break;

  case 135: /* module_item: declaration  */
#line 600 "veredit.y"
                                                                                                                                                  {(yyval.module_item_field) = module_itemNew((yyvsp[0].declaration_field), (continuous_assign) NULL, (instance) NULL, (text) NULL, (text) NULL, (parameter_decl) NULL);}
#line 2747 "y.tab.c"
    break;

  case 136: /* module_item: continuous_assign  */
#line 601 "veredit.y"
                                                                                                                                                  {(yyval.module_item_field) = module_itemNew((declaration) NULL, (yyvsp[0].continuous_assign_field), (instance) NULL, (text) NULL, (text) NULL, (parameter_decl) NULL);}
#line 2753 "y.tab.c"
    break;

  case 137: /* module_item: instance  */
#line 602 "veredit.y"
                                                                                                                                                  {(yyval.module_item_field) = module_itemNew((declaration) NULL, (continuous_assign) NULL, (yyvsp[0].instance_field), (text) NULL, (text) NULL, (parameter_decl) NULL);}
#line 2759 "y.tab.c"
    break;

  case 138: /* module_item: initial_statement  */
#line 603 "veredit.y"
                                                                                                                                                  {(yyval.module_item_field) = module_itemNew((declaration) NULL, (continuous_assign) NULL, (instance) NULL, (yyvsp[0].text_field), (text) NULL, (parameter_decl) NULL);}
#line 2765 "y.tab.c"
    break;

  case 139: /* module_item: parameter_override  */
#line 604 "veredit.y"
                                                                                                                                                  {(yyval.module_item_field) = module_itemNew((declaration) NULL, (continuous_assign) NULL, (instance) NULL, (text) NULL, (yyvsp[0].text_field), (parameter_decl) NULL);}
#line 2771 "y.tab.c"
    break;

  case 140: /* module_item: parameter_decl  */
#line 605 "veredit.y"
                                                                                                                                                  {(yyval.module_item_field) = module_itemNew((declaration) NULL, (continuous_assign) NULL, (instance) NULL, (text) NULL, (text) NULL, (yyvsp[0].parameter_decl_field));}
#line 2777 "y.tab.c"
    break;

  case 141: /* initial_statement: INITIALSTAT  */
#line 608 "veredit.y"
                                                                                                                                                  {(yyval.text_field) = (yyvsp[0].text_field);}
#line 2783 "y.tab.c"
    break;

  case 142: /* parameter_override: DEFPARAM  */
#line 611 "veredit.y"
                                                                                                                                                  {(yyval.text_field) = (yyvsp[0].text_field);}
#line 2789 "y.tab.c"
    break;

  case 143: /* declaration_list: declaration  */
#line 614 "veredit.y"
                                                                                                                                                  {(yyval.declaration_list_field) = declaration_listNew(); add((yyvsp[0].declaration_field), (yyval.declaration_list_field));}
#line 2795 "y.tab.c"
    break;

  case 144: /* declaration_list: declaration_list declaration  */
#line 615 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].declaration_field), (yyval.declaration_list_field));}
#line 2801 "y.tab.c"
    break;

  case 145: /* declaration: signal_type range variable_list ';'  */
#line 618 "veredit.y"
                                                                                                                                                  {(yyval.declaration_field) = declarationNew((yyvsp[-3].signal_type_field), (yyvsp[-2].range_field), (yyvsp[-1].variable_list_field));}
#line 2807 "y.tab.c"
    break;

  case 146: /* declaration: signal_type variable_list ';'  */
#line 619 "veredit.y"
                                                                                                                                                  {(yyval.declaration_field) = declarationNew((yyvsp[-2].signal_type_field), (range) NULL, (yyvsp[-1].variable_list_field));}
#line 2813 "y.tab.c"
    break;

  case 147: /* signal_type: INPUT  */
#line 622 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _INPUT;}
#line 2819 "y.tab.c"
    break;

  case 148: /* signal_type: OUTPUT  */
#line 623 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _OUTPUT;}
#line 2825 "y.tab.c"
    break;

  case 149: /* signal_type: INOUT  */
#line 624 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _INOUT;}
#line 2831 "y.tab.c"
    break;

  case 150: /* signal_type: WIRE  */
#line 625 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _WIRE;}
#line 2837 "y.tab.c"
    break;

  case 151: /* signal_type: SUPPLY0  */
#line 626 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _SUPPLY0;}
#line 2843 "y.tab.c"
    break;

  case 152: /* signal_type: SUPPLY1  */
#line 627 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _SUPPLY1;}
#line 2849 "y.tab.c"
    break;

  case 153: /* signal_type: TRI  */
#line 628 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _TRI;}
#line 2855 "y.tab.c"
    break;

  case 154: /* signal_type: TRI0  */
#line 629 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _TRI0;}
#line 2861 "y.tab.c"
    break;

  case 155: /* signal_type: TRI1  */
#line 630 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _TRI1;}
#line 2867 "y.tab.c"
    break;

  case 156: /* signal_type: TRIOR  */
#line 631 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _TRIOR;}
#line 2873 "y.tab.c"
    break;

  case 157: /* signal_type: TRIAND  */
#line 632 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _TRIAND;}
#line 2879 "y.tab.c"
    break;

  case 158: /* signal_type: TRIREG  */
#line 633 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _TRIREG;}
#line 2885 "y.tab.c"
    break;

  case 159: /* signal_type: WOR  */
#line 634 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _WOR;}
#line 2891 "y.tab.c"
    break;

  case 160: /* signal_type: WAND  */
#line 635 "veredit.y"
                                                                                                                                                  {(yyval.signal_type_field) = _WAND;}
#line 2897 "y.tab.c"
    break;

  case 161: /* variable_list: variable_name  */
#line 638 "veredit.y"
                                                                                                                                                  {(yyval.variable_list_field) = variable_listNew(); add((yyvsp[0].variable_name_field), (yyval.variable_list_field));}
#line 2903 "y.tab.c"
    break;

  case 162: /* variable_list: variable_list ',' variable_name  */
#line 639 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].variable_name_field), (yyval.variable_list_field));}
#line 2909 "y.tab.c"
    break;

  case 163: /* variable_name: vname '=' expression  */
#line 642 "veredit.y"
                                                                                                                                                  {(yyval.variable_name_field) = variable_nameNew((yyvsp[-2].vname_field), (yyvsp[0].expression_field));}
#line 2915 "y.tab.c"
    break;

  case 164: /* variable_name: vname  */
#line 643 "veredit.y"
                                                                                                                                                  {(yyval.variable_name_field) = variable_nameNew((yyvsp[0].vname_field), (expression) NULL);}
#line 2921 "y.tab.c"
    break;

  case 165: /* expression: INT_CONSTANT  */
#line 646 "veredit.y"
                                                                                                                                                  {(yyval.expression_field) = expressionNew((yyvsp[0].int_field), (Signal) NULL, (text) NULL);}
#line 2927 "y.tab.c"
    break;

  case 166: /* expression: Signal  */
#line 647 "veredit.y"
                                                                                                                                                  {(yyval.expression_field) = expressionNew((int) -1, (yyvsp[0].Signal_field), (text) NULL);}
#line 2933 "y.tab.c"
    break;

  case 167: /* expression: STRINGVALUE  */
#line 648 "veredit.y"
                                                                                                                                                  {(yyval.expression_field) = expressionNew((int) -1, (Signal) NULL, (yyvsp[0].text_field));}
#line 2939 "y.tab.c"
    break;

  case 168: /* assign_list: continuous_assign  */
#line 651 "veredit.y"
                                                                                                                                                  {(yyval.assign_list_field) = assign_listNew(); add((yyvsp[0].continuous_assign_field), (yyval.assign_list_field));}
#line 2945 "y.tab.c"
    break;

  case 169: /* assign_list: assign_list continuous_assign  */
#line 652 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].continuous_assign_field), (yyval.assign_list_field));}
#line 2951 "y.tab.c"
    break;

  case 170: /* continuous_assign: ASSIGN simple_signal '=' expression ';'  */
#line 655 "veredit.y"
                                                                                                                                                  {(yyval.continuous_assign_field) = continuous_assignNew((yyvsp[-3].simple_signal_field), (yyvsp[-1].expression_field));}
#line 2957 "y.tab.c"
    break;

  case 171: /* parameter_decl_list: parameter_decl  */
#line 658 "veredit.y"
                                                                                                                                                  {(yyval.parameter_decl_list_field) = parameter_decl_listNew(); add((yyvsp[0].parameter_decl_field), (yyval.parameter_decl_list_field));}
#line 2963 "y.tab.c"
    break;

  case 172: /* parameter_decl_list: parameter_decl_list parameter_decl  */
#line 659 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].parameter_decl_field), (yyval.parameter_decl_list_field));}
#line 2969 "y.tab.c"
    break;

  case 173: /* parameter_decl: PARAMETER simple_signal '=' expression ';'  */
#line 662 "veredit.y"
                                                                                                                                                  {(yyval.parameter_decl_field) = parameter_declNew((yyvsp[-3].simple_signal_field), (yyvsp[-1].expression_field));}
#line 2975 "y.tab.c"
    break;

  case 174: /* instantiation_list: instance  */
#line 665 "veredit.y"
                                                                                                                                                  {(yyval.instantiation_list_field) = instantiation_listNew(); add((yyvsp[0].instance_field), (yyval.instantiation_list_field));}
#line 2981 "y.tab.c"
    break;

  case 175: /* instantiation_list: instantiation_list instance  */
#line 666 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].instance_field), (yyval.instantiation_list_field));}
#line 2987 "y.tab.c"
    break;

  case 176: /* range: '[' INT_CONSTANT ':' INT_CONSTANT ']'  */
#line 669 "veredit.y"
                                                                                                                                                  {(yyval.range_field) = rangeNew((yyvsp[-3].int_field), (yyvsp[-1].int_field));}
#line 2993 "y.tab.c"
    break;

  case 177: /* instance: vname vname '(' portmap ')' ';'  */
#line 672 "veredit.y"
                                                                                                                                                  {(yyval.instance_field) = instanceNew((yyvsp[-5].vname_field), (yyvsp[-4].vname_field), (yyvsp[-2].portmap_field), signal_listNew());}
#line 2999 "y.tab.c"
    break;

  case 178: /* instance: vname vname '(' ')' ';'  */
#line 673 "veredit.y"
                                                                                                                                                  {(yyval.instance_field) = instanceNew((yyvsp[-4].vname_field), (yyvsp[-3].vname_field), portmapNew(), signal_listNew());}
#line 3005 "y.tab.c"
    break;

  case 179: /* instance: vname vname '(' signal_list ')' ';'  */
#line 674 "veredit.y"
                                                                                                                                                  {(yyval.instance_field) = instanceNew((yyvsp[-5].vname_field), (yyvsp[-4].vname_field), portmapNew(), (yyvsp[-2].signal_list_field));}
#line 3011 "y.tab.c"
    break;

  case 180: /* portmap: portmap_element  */
#line 677 "veredit.y"
                                                                                                                                                  {(yyval.portmap_field) = portmapNew(); add((yyvsp[0].portmap_element_field), (yyval.portmap_field));}
#line 3017 "y.tab.c"
    break;

  case 181: /* portmap: portmap ',' portmap_element  */
#line 678 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].portmap_element_field), (yyval.portmap_field));}
#line 3023 "y.tab.c"
    break;

  case 182: /* portmap_element: '.' vname '(' signal_list ')'  */
#line 681 "veredit.y"
                                                                                                                                                  {(yyval.portmap_element_field) = portmap_elementNew((yyvsp[-3].vname_field), (yyvsp[-1].signal_list_field));}
#line 3029 "y.tab.c"
    break;

  case 183: /* portmap_element: '.' vname '(' ')'  */
#line 682 "veredit.y"
                                                                                                                                                  {(yyval.portmap_element_field) = portmap_elementNew((yyvsp[-2].vname_field), signal_listNew());}
#line 3035 "y.tab.c"
    break;

  case 184: /* simple_signal_list: %empty  */
#line 685 "veredit.y"
                                                                                                                                                  {(yyval.simple_signal_list_field) = simple_signal_listNew();}
#line 3041 "y.tab.c"
    break;

  case 185: /* simple_signal_list: simple_signal_list simple_signal  */
#line 686 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].simple_signal_field), (yyval.simple_signal_list_field));}
#line 3047 "y.tab.c"
    break;

  case 186: /* simple_signal: INT_CONSTANT '\'' vname '[' INT_CONSTANT ']'  */
#line 689 "veredit.y"
                                                                                                                                                   {(yyval.simple_signal_field) = simple_signalNew((yyvsp[-5].int_field), (yyvsp[-3].vname_field), (yyvsp[-1].int_field), (range) NULL);}
#line 3053 "y.tab.c"
    break;

  case 187: /* simple_signal: vname '[' INT_CONSTANT ']'  */
#line 690 "veredit.y"
                                                                                                                                                  {(yyval.simple_signal_field) = simple_signalNew((int) -1, (yyvsp[-3].vname_field), (yyvsp[-1].int_field), (range) NULL);}
#line 3059 "y.tab.c"
    break;

  case 188: /* simple_signal: INT_CONSTANT '\'' vname  */
#line 691 "veredit.y"
                                                                                                                                                   {(yyval.simple_signal_field) = simple_signalNew((yyvsp[-2].int_field), (yyvsp[0].vname_field), (int) -1, (range) NULL);}
#line 3065 "y.tab.c"
    break;

  case 189: /* simple_signal: vname  */
#line 692 "veredit.y"
                                                                                                                                                  {(yyval.simple_signal_field) = simple_signalNew((int) -1, (yyvsp[0].vname_field), (int) -1, (range) NULL);}
#line 3071 "y.tab.c"
    break;

  case 190: /* simple_signal: INT_CONSTANT '\'' vname range  */
#line 693 "veredit.y"
                                                                                                                                                   {(yyval.simple_signal_field) = simple_signalNew((yyvsp[-3].int_field), (yyvsp[-1].vname_field), (int) -1, (yyvsp[0].range_field));}
#line 3077 "y.tab.c"
    break;

  case 191: /* simple_signal: vname range  */
#line 694 "veredit.y"
                                                                                                                                                  {(yyval.simple_signal_field) = simple_signalNew((int) -1, (yyvsp[-1].vname_field), (int) -1, (yyvsp[0].range_field));}
#line 3083 "y.tab.c"
    break;

  case 192: /* compound_signal: '{' signal_list '}'  */
#line 697 "veredit.y"
                                                                                                                                                  {(yyval.signal_list_field) = (yyvsp[-1].signal_list_field);}
#line 3089 "y.tab.c"
    break;

  case 193: /* signal_list: Signal  */
#line 700 "veredit.y"
                                                                                                                                                  {(yyval.signal_list_field) = signal_listNew(); add((yyvsp[0].Signal_field), (yyval.signal_list_field));}
#line 3095 "y.tab.c"
    break;

  case 194: /* signal_list: signal_list ',' Signal  */
#line 701 "veredit.y"
                                                                                                                                                  {add((yyvsp[0].Signal_field), (yyval.signal_list_field));}
#line 3101 "y.tab.c"
    break;

  case 195: /* Signal: simple_signal  */
#line 704 "veredit.y"
                                                                                                                                                  {(yyval.Signal_field) = SignalNew((yyvsp[0].simple_signal_field), signal_listNew());}
#line 3107 "y.tab.c"
    break;

  case 196: /* Signal: compound_signal  */
#line 705 "veredit.y"
                                                                                                                                                  {(yyval.Signal_field) = SignalNew((simple_signal) NULL, (yyvsp[0].signal_list_field));}
#line 3113 "y.tab.c"
    break;

  case 197: /* vname: IDENTIFIER  */
#line 708 "veredit.y"
                                                                                                                                                  {(yyval.vname_field) = vnameNew((yyvsp[0].text_field));}
#line 3119 "y.tab.c"
    break;

  case 198: /* vname: E_MODULE  */
#line 709 "veredit.y"
                                                                                                                                                  {(yyval.vname_field) = vnameNew("MODULE");}
#line 3125 "y.tab.c"
    break;


#line 3129 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 713 "veredit.y"

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
