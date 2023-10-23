%{
    #define EXIT_OK 0
    #define EXIT_FAIL 1
%}

letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
Hex [0-9a-fA-F]

%%
0[xX]{Hex}+          { return INT; }
{digit}+             { return INT; }
{digit}*\.{digit}+   { return FLOAT; }
{digit}+\.           { return FLOAT; }
'\\x{Hex}{Hex}'      { return CHAR; }
'.'                  { return CHAR; }

{letter_}({letter_}|{digit})* { return ID; }
int { return TYPE; }
float { return TYPE; }
char { return TYPE; }
struct { return STRUCT; }
if { return IF; }
else { return ELSE; }
while { return WHILE; }
return { return RETURN; }
"." { return DOT; }
";" { return SEMI; }
"," { return COMMA; }
"=" { return ASSIGN; }
"<" { return LT; }
"<=" { return LE; }
">" { return GT; }
">=" { return GE; }
"!=" { return NE; }
"==" { return EQ; }
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MUL; }
"/" { return DIV; }
"&&" { return AND; }
"||" { return OR; }
"!" { return NOT; }
"(" { return LP; }
")" { return RP; }
"[" { return LB; }
"]" { return RB; }
"{" { return LC; }
"}" { return RC; }

 /*
 * Error type:
 * 1. undefined tokens, eg., '@', '#' as non-literal token
 * 2. illegal hex int, eg., 0x5gg
 * 3. illegal hex char, eg., '\x9', '\xt0'
 */

'\\x{Hex}' { printf("Illegal hex char: %s\n",yytext);return HexCharErr;}
'\\x{Hex}{Hex}{Hex}+' { printf("Illegal hex char: %s\n",yytext);return HexCharErr;}
'\\x{Hex}*[g-zG-Z][0-9a-zA-Z]*' { printf("Illegal hex char: %s\n",yytext);return HexCharErr;}
0[xX]{Hex}*[g-zG-Z][0-9a-zA-Z]* { printf("Illegal hex int: %s\n",yytext);return HexIntErr;} 
.   { printf("Undefined token: %s\n",yytext);return TokenErr;}