%{
    #include<unistd.h>
    #include<stdio.h>   
    #include "structure.h"
    int yylex();
%}

%union{
    nodePointer type;
    double d;
}

%token <type> INT FLOAT CHAR
%token <type> ID TYPE STRUCT RETURN IF ELSE WHILE COMMENT SPACE SEMI COMMA ASSIGN PLUS
%token <type> MINUS MUL DIV AND OR DOT NOT LP RP LB RB LC RC AERROR LT LE GT GE NE EQ EOL

%type <type> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier 
%type <type> VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGN NOT
%left OR AND LT LE GT GE NE EQ
%left PLUS MINUS MUL DIV
%left LP RP LB RB DOT

%nonassoc LOWER_THAN_ELSE 
%nonassoc ELSE

%%

Program: ExtDefList {
    $$ = getNode("Program", 1, $1);
    if(!hasError)writeNode($$, 0);
    }
        ;
ExtDefList: ExtDef ExtDefList {$$ = getNode("ExtDefList", 2, $1, $2);}
          | {$$=getTerminalNode("ExtDefList", -1);}
        ;
ExtDef: Specifier ExtDecList SEMI {$$ = getNode("ExtDef", 3, $1, $2, $3);}
      | Specifier ExtDecList error {error_type = 1;yyerror("Missing semicolon ';'");}
      | Specifier SEMI {$$ = getNode("ExtDef", 2, $1, $2);}
      | Specifier error {error_type = 1;yyerror("Missing semicolon ';'");}
      | Specifier FunDec CompSt {$$ = getNode("ExtDef", 3, $1, $2, $3);}
      ;
ExtDecList: VarDec {$$ = getNode("ExtDecList", 1, $1);}
          | VarDec COMMA ExtDecList {$$ = getNode("ExtDecList", 3, $1, $2, $3);}
          ;

Specifier: TYPE {$$ = getNode("Specifier", 1, $1);}
         | StructSpecifier {$$ = getNode("Specifier", 1, $1);}
         ;
StructSpecifier: STRUCT ID LC DefList RC {$$ = getNode("StructSpecifier", 5, $1, $2, $3, $4, $5);}
              | STRUCT ID LC DefList error {error_type = 1;yyerror("Missing closing symbol '}'");}
              | STRUCT ID {$$ = getNode("StructSpecifier", 2, $1, $2);}
              ;

VarDec: ID {$$ = getNode("VarDec", 1, $1);}
      | VarDec LB INT RB {$$ = getNode("VarDec", 4, $1, $2, $3, $4);}
      | VarDec LB INT error {error_type = 1;yyerror("Missing closing symbol ']'");}
      ;
FunDec: ID LP VarList RP {$$ = getNode("FunDec", 4, $1, $2, $3, $4);}
      | ID LP RP {$$ = getNode("FunDec", 3, $1, $2, $3);}
      | ID LP VarList error {error_type = 1;yyerror("Missing closing symbol ')'");}
      | ID LP error {error_type = 1;yyerror("Missing closing symbol ')'");}
      ;
VarList: ParamDec COMMA VarList {$$ = getNode("VarList", 3, $1, $2, $3);}
       | ParamDec {$$ = getNode("VarList", 1, $1);}
       ;
ParamDec: Specifier VarDec {$$ = getNode("ParamDec", 2, $1, $2);}
         ;

CompSt: LC DefList StmtList RC {$$ = getNode("CompSt", 3, $1, $2, $3);}
      | LC DefList StmtList error {error_type = 1;yyerror("Missing closing symbol '}'");}
      ;
StmtList: Stmt StmtList {$$ = getNode("StmtList", 2, $1, $2);}
        |{$$=getTerminalNode("StmtList", -1);}
        ;
Stmt: Exp SEMI {$$ = getNode("Stmt", 2, $1, $2);}
    | Exp error {error_type = 1;yyerror("Missing semicolon ';'");}
    | CompSt {$$ = getNode("Stmt", 1, $1);}
    | RETURN Exp SEMI {$$ = getNode("Stmt", 3, $1, $2, $3);}
    | RETURN Exp error {error_type = 1;yyerror("Missing semicolon ';'");}
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {$$ = getNode("Stmt", 5, $1, $2, $3, $4, $5);}
    | IF LP Exp RP Stmt ELSE Stmt {$$ = getNode("Stmt", 7, $1, $2, $3, $4, $5, $6, $7);}
    | WHILE LP Exp RP Stmt {$$ = getNode("Stmt", 5, $1, $2, $3, $4, $5);}
    | IF LP Exp error Stmt %prec LOWER_THAN_ELSE {error_type = 1;yyerror("Missing closing symbol ')'");}
    | IF LP Exp error Stmt ELSE Stmt {error_type = 1;yyerror("Missing closing symbol ')'");}
    | WHILE LP Exp error Stmt {error_type = 1;yyerror("Missing closing symbol ')'");}
    ;
DefList: Def DefList {$$ = getNode("DefList", 2, $1, $2);}
        |{$$=getTerminalNode("DefList", -1);}
        ;
Def: Specifier DecList SEMI {$$ = getNode("Def", 3, $1, $2, $3);}
    | Specifier DecList error {error_type = 1;yyerror("Missing semicolon ';'");}
    ;
DecList: Dec {$$ = getNode("DecList", 1, $1);}
        | Dec COMMA DecList {$$ = getNode("DecList", 3, $1, $2, $3);}
//        | Dec error DecList {error_type = 1;yyerror("Missing comma ','");}
        ;
Dec: VarDec {$$ = getNode("Dec", 1, $1);}
    | VarDec ASSIGN Exp {$$ = getNode("Dec", 3, $1, $2, $3);}
    ;

Exp: Exp ASSIGN Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp AND Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp OR Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp LT Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp LE Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp GT Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp GE Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp NE Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp EQ Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp PLUS Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp MINUS Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp MUL Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | Exp DIV Exp {$$ = getNode("Exp", 3, $1, $2, $3);}
    | LP Exp RP {$$ = getNode("Exp", 3, $1, $2, $3);}
    | LP Exp error {error_type = 1;yyerror("Missing closing symbol ')'");}
    | MINUS Exp {$$ = getNode("Exp", 2, $1, $2);}
    | NOT Exp {$$ = getNode("Exp", 2, $1, $2);}
    | ID LP Args RP {$$ = getNode("Exp", 4, $1, $2, $3, $4);}
    | ID LP Args error {error_type = 1;yyerror("Missing closing symbol ')'");}
    | ID LP RP {$$ = getNode("Exp", 3, $1, $2, $3);}
    | ID LP error {error_type = 1;yyerror("Missing closing symbol ')'");}
    | Exp LB Exp RB {$$ = getNode("Exp", 4, $1, $2, $3, $4);}
    | Exp LB Exp error {error_type = 1;yyerror("Missing closing symbol ']'");}
    | Exp DOT ID {$$ = getNode("Exp", 3, $1, $2, $3);}
    | ID {$$ = getNode("Exp", 1, $1);}
    | INT {$$ = getNode("Exp", 1, $1);}
    | FLOAT {$$ = getNode("Exp", 1, $1);}
    | CHAR {$$ = getNode("Exp", 1, $1);}
    ;
Args: Exp COMMA Args {$$ = getNode("Args", 3, $1, $2, $3);}
//    | Exp error Args {error_type = 1;yyerror("Missing comma ','");}
    | COMMA Args {yyerror("Unexpected ','");}
    | Exp COMMA {yyerror("expected another parenthesis after ','");}
    | Exp {$$ = getNode("Args", 1, $1);}
    ;

%%