%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "structure.h"
    #include "syntax.tab.h"
%}

%option yylineno

INT (0|[1-9][0-9]*)|(0[xX][a-fA-F0-9]+)

FLOAT (0|[1-9][0-9]*)\.[0-9]+
CHAR ['][a-zA-Z][']|['][\\][xX][1-9a-fA-F][0-9a-fA-F][']

ID [a-z_A-Z][a-z_A-Z0-9]*

STRUCT struct
RETURN return
IF if
ELSE else
WHILE while
TYPE int|float|char

SEMI  ;
COMMA ,
ASSIGN  =
PLUS  \+
MINUS \-
MUL  \*
DIV   \/
AND   &&
DOT   \.
NOT   \!
LP    \(
RP    \)
LB    \[
RB    \]
LC    \{
RC    \}
LT  <
LE  <=
GT  >
GE  >=
NE  !=
EQ  ==


COMMENT ("//".*)|("/*"([*]*(([^*/])+([/])*)*)*"*/")

SPACE [ \f\r\t\v]+
EOL \n
error0 .
error1 [0][0-9]+
error2 [0-9]+[a-w_A-Wy-zY-Z][a-z_A-Z0-9]*
error3 0[xX]0[a-fA-F0-9]+
error4 0[xX][0-9a-zA-Z]*[g-zG-Z][0-9a-zA-Z]*
error5 ['][\\][xX][0-9a-zA-Z]+[']
%%

{SPACE} {}
{COMMENT} {}
{EOL} {}

{TYPE} {yylval.type = getTerminalNode("TYPE", yylineno); return TYPE;}
{STRUCT} {yylval.type = getTerminalNode("STRUCT", yylineno); return STRUCT;}
{RETURN} {yylval.type = getTerminalNode("RETURN", yylineno); return RETURN;}
{IF} {yylval.type = getTerminalNode("IF", yylineno); return IF;}
{ELSE} {yylval.type = getTerminalNode("ELSE", yylineno); return ELSE;}
{WHILE} {yylval.type = getTerminalNode("WHILE", yylineno); return WHILE;}

{error1} {printf("Error type A at line %d: unknown lexeme %s\n",yylineno,yytext);error_type = 0;}
{error2} {printf("Error type A at line %d: unknown lexeme %s\n",yylineno,yytext);error_type = 0;}
{error3} {printf("Error type A at line %d: unknown lexeme %s\n",yylineno,yytext);error_type = 0;}
{error4} {printf("Error type A at line %d: unknown lexeme %s\n",yylineno,yytext);error_type = 0;}

{INT} {yylval.type = getTerminalNode("INT", yylineno); return INT;}
{FLOAT} {yylval.type = getTerminalNode("FLOAT", yylineno); return FLOAT;}
{CHAR} {yylval.type = getTerminalNode("CHAR", yylineno); return CHAR;}
{error5} {printf("Error type A at line %d: unknown lexeme %s\n",yylineno,yytext);error_type = 0;}

{SEMI} {yylval.type = getTerminalNode("SEMI", yylineno); return SEMI;}
{COMMA} {yylval.type = getTerminalNode("COMMA", yylineno); return COMMA;}
{ASSIGN} {yylval.type = getTerminalNode("ASSIGN", yylineno); return ASSIGN;}
{PLUS} { yylval.type = getTerminalNode("PLUS", yylineno); return PLUS; }
{MINUS} { yylval.type = getTerminalNode("MINUS", yylineno); return MINUS; }
{MUL} { yylval.type = getTerminalNode("MUL", yylineno); return MUL; }
{DIV} { yylval.type = getTerminalNode("DIV", yylineno); return DIV; }
{AND} { yylval.type = getTerminalNode("AND", yylineno); return AND; }
{DOT} { yylval.type = getTerminalNode("DOT", yylineno); return DOT; }
{NOT} { yylval.type = getTerminalNode("NOT", yylineno); return NOT; }
{LP} { yylval.type = getTerminalNode("LP", yylineno); return LP; }
{RP} { yylval.type = getTerminalNode("RP", yylineno); return RP; }
{LB} { yylval.type = getTerminalNode("LB", yylineno); return LB; }
{RB} { yylval.type = getTerminalNode("RB", yylineno); return RB; }
{LC} { yylval.type = getTerminalNode("LC", yylineno); return LC; }
{RC} { yylval.type = getTerminalNode("RC", yylineno); return RC; }
{LT} {yylval.type = getTerminalNode("LT", yylineno); return LT;}
{LE} {yylval.type = getTerminalNode("LE", yylineno); return LE;}
{GT} {yylval.type = getTerminalNode("GT", yylineno); return GT;}
{GE} {yylval.type = getTerminalNode("GE", yylineno); return GE;}
{NE} {yylval.type = getTerminalNode("NE", yylineno); return NE;}
{EQ} {yylval.type = getTerminalNode("EQ", yylineno); return EQ;}
{ID} {yylval.type = getTerminalNode("ID", yylineno); return ID;}
{error0} {
    error_type = 0;
    printf("Error type A at line %d: unknown lexeme %s\n",yylineno,yytext);
}
%%


int yywrap()
{
    return 1;
}
