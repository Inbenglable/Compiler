%{
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    #include <stdlib.h>
    #include <stdio.h>
    #include "structure.h"
    #include "syntax.tab.h"
%}

letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
Hex [0-9a-fA-F]

%%
0[xX]{Hex}+          { yylval.type=getTerminalNode("INT", yylineno);return INT; }
{digit}+             { yylval.type=getTerminalNode("INT", yylineno);return INT; }
{digit}*\.{digit}+   { yylval.type=getTerminalNode("FLOAT", yylineno);return FLOAT; }
{digit}+\.           { yylval.type=getTerminalNode("FLOAT", yylineno);return FLOAT; }
'\\x{Hex}{Hex}'      { yylval.type=getTerminalNode("CHAR", yylineno);return CHAR; }
'.'                  { yylval.type=getTerminalNode("CHAR", yylineno);return CHAR; }

int { printf("lex.l_begin");yylval.type=getTerminalNode("TYPE", yylineno);return TYPE; }
float { yylval.type=getTerminalNode("TYPE", yylineno);return TYPE; }
char { yylval.type=getTerminalNode("TYPE", yylineno);return TYPE; }
struct { yylval.type=getTerminalNode("STRUCT", yylineno);return STRUCT; }
if { yylval.type=getTerminalNode("IF", yylineno);return IF; }
else { yylval.type=getTerminalNode("ELSE", yylineno);return ELSE; }
while { yylval.type=getTerminalNode("WHILE", yylineno);return WHILE; }
return { yylval.type=getTerminalNode("RETURN", yylineno);return RETURN; }
{letter_}({letter_}|{digit})* { yylval.type=getTerminalNode("ID", yylineno);return ID; }
"." { yylval.type=getTerminalNode("DOT", yylineno);return DOT; }
";" { yylval.type=getTerminalNode("SEMI", yylineno);return SEMI; }
"," { yylval.type=getTerminalNode("COMMA", yylineno);return COMMA; }
"=" { yylval.type=getTerminalNode("ASSIGN", yylineno);return ASSIGN; }
"<" { yylval.type=getTerminalNode("LT", yylineno);return LT; }
"<=" { yylval.type=getTerminalNode("LE", yylineno);return LE; }
">" { yylval.type=getTerminalNode("GT", yylineno);return GT; }
">=" { yylval.type=getTerminalNode("GE", yylineno);return GE; }
"!=" { yylval.type=getTerminalNode("NE", yylineno);return NE; }
"==" { yylval.type=getTerminalNode("EQ", yylineno);return EQ; }
"+" { yylval.type=getTerminalNode("PLUS", yylineno);return PLUS; }
"-" { yylval.type=getTerminalNode("MINUS", yylineno);return MINUS; }
"*" { yylval.type = getTerminalNode("MUL", yylineno); return MUL; }
"/" { yylval.type = getTerminalNode("DIV", yylineno); return DIV; }
"&&" { yylval.type = getTerminalNode("AND", yylineno); return AND; }
"||" { yylval.type = getTerminalNode("OR", yylineno); return OR; }
"!" { yylval.type = getTerminalNode("NOT", yylineno); return NOT; }
"(" { yylval.type = getTerminalNode("LP", yylineno); return LP; }
")" { yylval.type = getTerminalNode("RP", yylineno); return RP; }
"[" { yylval.type = getTerminalNode("LB", yylineno); return LB; }
"]" { yylval.type = getTerminalNode("RB", yylineno); return RB; }
"{" { yylval.type = getTerminalNode("LC", yylineno); return LC; }
"}" { yylval.type = getTerminalNode("RC", yylineno); return RC; }

%%