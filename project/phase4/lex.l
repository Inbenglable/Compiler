%{
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    #include <stdlib.h>
    #include <stdio.h>
    #include "structure.h"
    #include "symbol_table.h"
    #include "syntax.tab.h"
    #include <string.h>
    char tmp[500]; 
%}
SPACE [ \f\r\t\v]+
letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
Hex [0-9a-fA-F]
EOL \n
unknown .
%%

{SPACE} {}
{EOL} {yylineno += 1;}

(0[xX]([1-9a-fA-F]{Hex}*))|([1-9]{digit}*)|0     { yylval.type=getTerminalNode("INT", yylineno);return INT; }
(0|([1-9]{digit}*))\.{digit}*  { yylval.type=getTerminalNode("FLOAT", yylineno);return FLOAT; }
'\\x{Hex}{Hex}'       { yylval.type=getTerminalNode("CHAR", yylineno);return CHAR; }
'.'    { yylval.type=getTerminalNode("CHAR", yylineno);return CHAR; }


int {yylval.type=getTypeNode("INT", yylineno);return TYPE; }
float { yylval.type=getTypeNode("FLOAT", yylineno);return TYPE; }
char { yylval.type=getTypeNode("CHAR", yylineno);return TYPE; }
struct { yylval.type=getTerminalNode("STRUCT", yylineno);return STRUCT; }
if { yylval.type=getTerminalNode("IF", yylineno);return IF; }
else { yylval.type=getTerminalNode("ELSE", yylineno);return ELSE; }
while { yylval.type=getTerminalNode("WHILE", yylineno);return WHILE; }
for { yylval.type=getTerminalNode("FOR", yylineno);return FOR; }
return { yylval.type=getTerminalNode("RETURN", yylineno);return RETURN; }
{letter_}({letter_}|{digit})* { yylval.type=getIDNode("ID", yylineno);return ID; }
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
"{" { yylval.type = getTerminalNode("LC", yylineno);
    new_scope();
    return LC;
}
"}" { yylval.type = getTerminalNode("RC", yylineno);
    pop_scope();
    return RC;
    }
"//" { 
  int c;
  while((c = input()) != '\n');
  yylineno += 1;  
}
"/*" { 
  int c;
  while(1){
    c=input();
    if(c == '\n')yylineno += 1;
    if(c=='*') {
      c=input();
      if(c == '\n')yylineno += 1;
      if (c == '/') break;
    }
 
  }; 
}

'\\x{Hex}' { 
  error_type=0;
  sprintf(tmp,"Illegal hex char: %s",yytext);
  yyerror(tmp);
yylval.type = getTerminalNode("RB", yylineno);
return CHAR;
}
'\\x{Hex}{Hex}{Hex}+' {
  error_type=0;
    yylval.type = getTerminalNode("ERROR", yylineno);
 sprintf(tmp, "Illegal hex char: %s", yytext); 
 yyerror(tmp);
 return CHAR;
 }
'\\x{Hex}*[g-zG-Z][0-9a-zA-Z]*' {
  error_type=0;
    yylval.type = getTerminalNode("ERROR", yylineno);
   sprintf(tmp, "Illegal hex char: %s", yytext); 
   yyerror(tmp);
    return CHAR;
    }
0[xX]{Hex}*[g-zG-Z][0-9a-zA-Z]* { 
  error_type=0;
    yylval.type = getTerminalNode("ERROR", yylineno);
    sprintf(tmp, "Illegal hex char: %s", yytext);
    yyerror(tmp);
    return INT;
    } 
([1-9]|[#@$?])({letter_}|{digit})* { 
  error_type=0;
    yylval.type = getTerminalNode("ERROR", yylineno);
    sprintf(tmp, "Illegal id: %s", yytext);
     yyerror(tmp);
    return ID;
    }

[0][0-9]+ {
  error_type=0;
    yylval.type = getTerminalNode("ERROR", yylineno);
   sprintf(tmp, "Illegal int: %s", yytext); 
   yyerror(tmp);
    return INT;
    }

{unknown} {
  error_type=0;
    yylval.type = getTerminalNode("ERROR", yylineno);
   sprintf(tmp, "unknown lexeme: %s", yytext); 
   yyerror(tmp);
    return PLUS;
}

%%

int yywrap()
{
    return 1;
}