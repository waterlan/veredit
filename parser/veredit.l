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
#include "file.h"
#include "veredit.h"

extern void setTranslation_unitParserInputStream(FILE* stream);
extern FILE * getTranslation_unitParserOutputStream(void);

expvar rwtext yyTOKEN_BUFFER = NULL;
static void lexReport(text token,
                      text val = NULL,
                      YYSTYPE* yys = NULL)
{
   TRACE(FILE *fo = getTranslation_unitParserOutputStream();)

   static size_t prev_size = 0;
   size_t need_size;

   if (val ne NULL)
      need_size = strlen(val) + strlen(token) + 6;
   else
      need_size = strlen(token) + 3;

   if (need_size > prev_size)
   {
      if (yyTOKEN_BUFFER eq NULL)
         yyTOKEN_BUFFER = (rwtext) malloc(sizeof(char) * need_size);
      else
         yyTOKEN_BUFFER = (rwtext) realloc((void *) yyTOKEN_BUFFER, sizeof(char) * need_size);

      prev_size = need_size;
   }

   if (val ne NULL)
   {
      sprintf(yyTOKEN_BUFFER, "'%s' (%s)", val, token);
      if (yys ne NULL)
         yys->text_field = textNew(val);
   }
   else
      sprintf(yyTOKEN_BUFFER, "'%s'", token);

   TRACE(fprintf(fo, "recognized %s\n", yyTOKEN_BUFFER);)
}
static void skip(text val)
{
   TRACE(FILE *fo = getTranslation_unitParserOutputStream();)

   TRACE(fprintf(fo, "skipping '%s'\n", val);)
}
%}

%option nounput yylineno


linecomment "//"[^\n]*
comment "/*"[^*]*"*"+([^/*][^*]*"*"+)*"/"

%%

[{}=,();.\[\]:']                         {lexReport("char", (text) yytext); return yytext[0];}
module {lexReport("MODULE", (text) yytext); return MODULE;}
endmodule {lexReport("ENDMODULE", (text) yytext); return ENDMODULE;}
input {lexReport("INPUT", (text) yytext); return INPUT;}
output {lexReport("OUTPUT", (text) yytext); return OUTPUT;}
inout {lexReport("INOUT", (text) yytext); return INOUT;}
wire {lexReport("WIRE", (text) yytext); return WIRE;}
supply0 {lexReport("SUPPLY0", (text) yytext); return SUPPLY0;}
supply1 {lexReport("SUPPLY1", (text) yytext); return SUPPLY1;}
tri {lexReport("TRI", (text) yytext); return TRI;}
tri0 {lexReport("TRI0", (text) yytext); return TRI0;}
tri1 {lexReport("TRI1", (text) yytext); return TRI1;}
trior {lexReport("TRIOR", (text) yytext); return TRIOR;}
triand {lexReport("TRIAND", (text) yytext); return TRIAND;}
trireg {lexReport("TRIREG", (text) yytext); return TRIREG;}
wor {lexReport("WOR", (text) yytext); return WOR;}
wand {lexReport("WAND", (text) yytext); return WAND;}
assign {lexReport("ASSIGN", (text) yytext); return ASSIGN;}
parameter {lexReport("PARAMETER", (text) yytext); return PARAMETER;}
MODULE {lexReport("E_MODULE", (text) yytext); return E_MODULE;}
-output {lexReport("E_OUTPUT", (text) yytext); return E_OUTPUT;}
-input {lexReport("E_INPUT", (text) yytext); return E_INPUT;}
-instance {lexReport("INSTANCE", (text) yytext); return INSTANCE;}
-addports {lexReport("ADDPORTS", (text) yytext); return ADDPORTS;}
-delports {lexReport("DELPORTS", (text) yytext); return DELPORTS;}
-rmports {lexReport("RMPORTS", (text) yytext); return RMPORTS;}
-delnets {lexReport("DELNETS", (text) yytext); return DELNETS;}
-addinst {lexReport("ADDINST", (text) yytext); return ADDINST;}
-modinst {lexReport("MODINST", (text) yytext); return MODINST;}
-keepmodname {lexReport("KEEPMODNAME", (text) yytext); return KEEPMODNAME;}
-delinst {lexReport("DELINST", (text) yytext); return DELINST;}
-addassign {lexReport("ADDASSIGN", (text) yytext); return ADDASSIGN;}
-delassign {lexReport("DELASSIGN", (text) yytext); return DELASSIGN;}
-addparameterdecl {lexReport("ADDPARAMETERDECL", (text) yytext); return ADDPARAMETERDECL;}
-delparameterdecl {lexReport("DELPARAMETERDECL", (text) yytext); return DELPARAMETERDECL;}
-delete {lexReport("DELETE", (text) yytext); return DELETE;}
-empty {lexReport("EMPTY", (text) yytext); return EMPTY;}
-bufferoutputs {lexReport("BUFFEROUTPUTS", (text) yytext); return BUFFEROUTPUTS;}
-exclude {lexReport("EXCLUDE", (text) yytext); return EXCLUDE;}
-removebuffers {lexReport("REMOVEBUFFERS", (text) yytext); return REMOVEBUFFERS;}
-bufferlist {lexReport("BUFFERLIST", (text) yytext); return BUFFERLIST;}
-buffer {lexReport("BUFFER", (text) yytext); return BUFFER;}
-bufferinput {lexReport("BUFFERINPUT", (text) yytext); return BUFFERINPUT;}
-insertobsinput {lexReport("INSERTOBSINPUT", (text) yytext); return INSERTOBSINPUT;}
-other {lexReport("OTHER", (text) yytext); return OTHER;}
-nets {lexReport("NETS", (text) yytext); return NETS;}
-insertobsoutput {lexReport("INSERTOBSOUTPUT", (text) yytext); return INSERTOBSOUTPUT;}
-listinst {lexReport("LISTINST", (text) yytext); return LISTINST;}
-net {lexReport("NET", (text) yytext); return NET;}
-tiecell {lexReport("TIECELL", (text) yytext); return TIECELL;}
-shell {lexReport("SHELL", (text) yytext); return SHELL;}
-bufferassigns {lexReport("BUFASSIGNS", (text) yytext); return BUFASSIGNS;}
-pulluppin {lexReport("PULLUPPIN", (text) yytext); return PULLUPPIN;}
-inst {lexReport("INST", (text) yytext); return INST;}
-label {lexReport("LABEL", (text) yytext); return LABEL;}
initial[ \t\n]+[^;]*[;] {lexReport("INITIALSTAT", (text) yytext, &yylval); return INITIALSTAT;}
defparam[ \t\n]+[^;]*[;] {lexReport("DEFPARAM", (text) yytext, &yylval); return DEFPARAM;}
[a-zA-Z_][a-zA-Z_0-9$]* {lexReport("IDENTIFIER", (text) yytext, &yylval); return IDENTIFIER;}
\\[^ \t\n]+[ \t\n] {lexReport("IDENTIFIER", (text) yytext, &yylval); return IDENTIFIER;}
[a-zA-Z_0-9$]*[*][a-zA-Z_0-9$*]* {lexReport("WILDCARDS", (text) yytext, &yylval); return WILDCARDS;}
["][^"]*["] {lexReport("STRINGVALUE", (text) yytext, &yylval); return STRINGVALUE;}
[0-9]+ {lexReport("INT_CONSTANT", (text) yytext); yylval.int_field = (int) strtol((text) yytext, NULL, 0); return INT_CONSTANT;}
-ALL {lexReport("ALL", (text) yytext); return ALL;}
"`"[^\n]* {lexReport("compiler_directive", (text) yytext, &yylval); return compiler_directive;}
{linecomment} {skip((text) yytext);}
{comment} {skip((text) yytext);}

.                                        {skip((text) yytext);}
\n                                       {skip((text) yytext);}

%%

static YY_BUFFER_STATE BUFFER_STATE = NULL;
expfun void setTranslation_unitScannerToString(text string)
{
   extern text yyCURRENT_ITEM;

   yyCURRENT_ITEM = string;
   BUFFER_STATE = yy_scan_string(string);
}
expfun void setTranslation_unitScannerToStream(FILE* stream)
{
   extern FILE *yyin;
   extern text yyCURRENT_ITEM;

   setTranslation_unitParserInputStream(stream);

   yyin = stream;
   yyCURRENT_ITEM = "stream";
}
expfun void flushTranslation_unitScannerBuffer(void)
{
   YY_FLUSH_BUFFER;
}
#ifdef yywrap
#undef yywrap
#endif
expfun int yywrap(void)
{
   extern nameset yyITEMS;
   extern text yyCURRENT_ITEM;
   extern FILE *yyin;
   extern int yylineno;
   FILE *fo = getTranslation_unitParserOutputStream();

   while(isEmpty(yyITEMS) eq false)
   {
      yyCURRENT_ITEM = popFirst(yyITEMS);
      if (BUFFER_STATE ne NULL)
      {
         yy_delete_buffer(BUFFER_STATE);
         setTranslation_unitScannerToString(yyCURRENT_ITEM);
         yylineno = 1;
         return 0;
      }
      else if (yyin ne stdin)
      {
         Close(yyin);

         yyin = openR(yyCURRENT_ITEM, true);
         if (yyin ne NULL)
         {
            yylineno = 1;
            fprintf(fo, "- parsing '%s' ...\n", yyCURRENT_ITEM);
            return 0;
         }
      }
   }

   if (yyin ne stdin)
      Close(yyin);

   return 1;
}
