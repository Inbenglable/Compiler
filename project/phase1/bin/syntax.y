%{
    #include<unistd.h>
    #include<stdio.h>   
    #include "structure.h"
    #include "symbol_table.h"
    int yylex();
%}

%union{
    nodePointer type;
}

%token <type> INT FLOAT CHAR
%token <type> ID TYPE STRUCT RETURN IF ELSE WHILE FOR COMMENT SPACE SEMI COMMA ASSIGN PLUS
%token <type> MINUS MUL DIV AND OR DOT NOT LP RP LB RB LC RC AERROR LT LE GT GE NE EQ EOL

%type <type> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier 
%type <type> VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGN
%left OR
%left AND
%left LT LE GT GE NE EQ
%left PLUS MINUS
%left MUL DIV
%right NOT 
%left LP RP LB RB DOT

%nonassoc LOWER_THAN_ELSE 
%nonassoc ELSE

%%

Program: ExtDefList {
    $$ = getNode("Program", 1, $1);
    if(!hasError)
        writeNode($$, 0);
    }
        ;
ExtDefList: ExtDef ExtDefList {$$ = getNode("ExtDefList", 2, $1, $2);}
          | {$$=getTerminalNode("ExtDefList", -1);}
        ;
ExtDef: Specifier ExtDecList SEMI {
            $$ = getNode("ExtDef", 3, $1, $2, $3);
            assign_type($1, $2);
            if(push_var($2)!=0){// == 0 : acc , == x : error in line x 
                error_type = 3;
                yyerror("Variable aready exists");
            }
        }
      | Specifier ExtDecList error {error_type = 1;yyerror("Missing semicolon ';'");}
      | Specifier SEMI {$$ = getNode("ExtDef", 2, $1, $2);}
      | Specifier error {error_type = 1;yyerror("Missing semicolon ';'");}
      | Specifier FunDec CompSt {
            $$ = getNode("ExtDef", 3, $1, $2, $3);
            assign_funtype($2, $1);
            pop_scope();
            if(push_fun($2)!=0){// == 0 : acc , == x : error in line x 
                error_type = 3;
                yyerror("Function name aready exists");
            }
        }
      |  error ExtDecList SEMI {error_type = 1; yyerror("Missing specifier");}
      ;


ExtDecList: VarDec {
                $$ = getNode("ExtDecList", 1, $1);
                extend_var($$, $1);    
            }
          | VarDec COMMA ExtDecList {
                $$ = getNode("ExtDecList", 3, $1, $2, $3);
                connect_var($1, $3);
                extend_var($$, $1);
            }
          | COMMA ExtDecList {error_type = 1;yyerror("Unexpected ','");}
          | VarDec COMMA {error_type = 1;yyerror("Unexpected ','");}
          ;

Specifier: TYPE {
                $$ = getNode("Specifier", 1, $1);
                extend_type($$, $1);
            }
         | StructSpecifier {
                $$ = getNode("Specifier", 1, $1);
                extend_type($$, $1);
            }
         ;
StructSpecifier: STRUCT ID LC DefList RC {
                    $$ = getNode("StructSpecifier", 5, $1, $2, $3, $4, $5);
                    newStructType($$, $2, $4);
                    if(push_type($$)!=0){// == 0 : acc , == x : error in line x 
                        error_type = 3;
                        yyerror("Struct name aready exists");
                    }
                }
              | STRUCT ID {$$ = getNode("StructSpecifier", 2, $1, $2);
                    if(!getStruct($$, $1)){
                        error_type = 3;
                        yyerror("Undefined structer");
                    }
              }
//              | STRUCT ID LC DefList error {error_type = 1;yyerror("Missing closing symbol '}'");}
              ;

VarDec: ID {
            $$ = getNode("VarDec", 1, $1);
            extend_var($$, $1);
        }
      | VarDec LB INT RB {
        $$ = getNode("VarDec", 4, $1, $2, $3, $4);
        extend_dim($1);
        extend_var($$, $1);
      }
      | VarDec LB INT error {error_type = 1;yyerror("Missing closing symbol ']'");}
//      | VarDec LB Exp RB {$$ = getNode("VarDec", 4, $1, $2, $3, $4);}
//      | VarDec LB Exp error {error_type = 1;yyerror("Missing closing symbol ']'");}
      ;
FunDec: ID LP VarList RP {$$ = getNode("FunDec", 4, $1, $2, $3, $4);
            new_scope();
            if(push_var($2)!=0){// == 0 : acc , == x : error in line x 
                error_type = 3;
                yyerror("Variable aready exists");
            }
            newFuntype($$, $1, $3);
        }
      | ID LP RP {$$ = getNode("FunDec", 3, $1, $2, $3);
            new_scope();
            newFuntype($$, $1, NULL);
        }
      | ID LP VarList error {error_type = 1;yyerror("Missing closing symbol ')'");}
      | ID LP error {error_type = 1;yyerror("Missing closing symbol ')'");}
      ;
VarList: ParamDec COMMA VarList {
            $$ = getNode("VarList", 3, $1, $2, $3);
            connect_var($1, $3);
            extend_var($$, $3);    
        }
       | ParamDec {
            $$ = getNode("VarList", 1, $1);
            extend_var($$, $1);
        }
       ;
ParamDec: Specifier VarDec {
            $$ = getNode("ParamDec", 2, $1, $2);
            assign_type($1, $2);
            extend_var($$, $2);   
        }
        | error VarDec {error_type = 1;yyerror("Missing specifier");}
        | Specifier error {error_type = 1;yyerror("Missing variable name");}
         ;

CompSt: LC DefList StmtList RC {$$ = getNode("CompSt", 4, $1, $2, $3, $4);}
    //   | LC DefList StmtList error {error_type = 1;yyerror("Missing closing symbol '}'");}
      ;
StmtList: Stmt StmtList {$$ = getNode("StmtList", 2, $1, $2);}
        |{$$=getTerminalNode("StmtList", -1);}
        ;
Stmt: SEMI {$$ = getNode("Stmt", 1, $1);}
    | Exp SEMI {$$ = getNode("Stmt", 2, $1, $2);}
    | Exp error {error_type = 1;yyerror("Missing semicolon ';'");}
    | CompSt {$$ = getNode("Stmt", 1, $1);}
    | RETURN Exp SEMI {$$ = getNode("Stmt", 3, $1, $2, $3);}
    | RETURN Exp error {error_type = 1;yyerror("Missing semicolon ';'");}
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {$$ = getNode("Stmt", 5, $1, $2, $3, $4, $5);}
    | IF LP Exp error Stmt %prec LOWER_THAN_ELSE {error_type = 1;yyerror("This if function miss closing symbol ')'");}
    | IF LP Exp RP Stmt ELSE Stmt {$$ = getNode("Stmt", 7, $1, $2, $3, $4, $5, $6, $7);}
    | WHILE LP Exp RP Stmt {$$ = getNode("Stmt", 5, $1, $2, $3, $4, $5);}
    | WHILE LP RP Stmt {$$ = getNode("Stmt", 4, $1, $2, $3, $4);}
    | IF LP Exp error Stmt ELSE Stmt {error_type = 1;yyerror("This if function miss closing symbol ')'");}
    | WHILE LP Exp error Stmt {error_type = 1;yyerror("Missing closing symbol ')'");}
    // | FOR LP VarList SEMI Exp SEMI Exp RP Stmt {$$ = getNode("Stmt", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9);}
    // | FOR LP SEMI Exp SEMI Exp RP Stmt {$$ = getNode("Stmt", 8, $1, $2, $3, $4, $5, $6, $7, $8);}
    // | FOR LP VarList SEMI SEMI Exp RP Stmt {$$ = getNode("Stmt", 8, $1, $2, $3, $4, $5, $6, $7, $8);}
    // | FOR LP VarList SEMI Exp SEMI RP Stmt {$$ = getNode("Stmt", 8, $1, $2, $3, $4, $5, $6, $7, $8);}
    // | FOR LP SEMI SEMI Exp RP Stmt {$$ = getNode("Stmt", 7, $1, $2, $3, $4, $5, $6, $7);}
    // | FOR LP SEMI Exp SEMI RP Stmt {$$ = getNode("Stmt", 7, $1, $2, $3, $4, $5, $6, $7);}
    // | FOR LP VarList SEMI SEMI RP Stmt {$$ = getNode("Stmt", 7, $1, $2, $3, $4, $5, $6, $7);}
    // | FOR LP SEMI SEMI RP Stmt {$$ = getNode("Stmt", 6, $1, $2, $3, $4, $5, $6);}
    ;
DefList: Def DefList {
            $$ = getNode("DefList", 2, $1, $2);
            connect_var($1, $2);
            extend_var($$, $1);
        }
        |{$$=getTerminalNode("DefList", -1);}
        ;
Def: Specifier DecList SEMI {
        $$ = getNode("Def", 3, $1, $2, $3);
        assign_type($1, $2);
        extend_var($$, $2);
        if(push_var($2)!=0){// == 0 : acc , == x : error in line x 
            error_type = 3;
            yyerror("Variable aready exists");
        }

    }
   |error DecList SEMI {error_type = 1; yyerror("Missing specifier");}
   |Specifier DecList error {error_type = 1; yyerror("Missing semicolon ';'");}
    ;
DecList: Dec {
            $$ = getNode("DecList", 1, $1);
            extend_var($$, $1);
        }
        | Dec COMMA DecList {
            $$ = getNode("DecList", 3, $1, $2, $3);
            connect_var($1, $3);
            extend_var($$, $1);
        }
//        | Dec error DecList {error_type = 1;yyerror("Missing comma ','");}
        ;
Dec: VarDec {
        $$ = getNode("Dec", 1, $1);
        extend_var($$, $1);
        }
    | VarDec ASSIGN Exp {
        $$ = getNode("Dec", 3, $1, $2, $3);
        extend_var($$, $1);
    }
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
    | Exp ASSIGN error {error_type = 1; yyerror("Expect expression after '='");}
    | Exp AND error {error_type = 1; yyerror("Expect expression after 'ans'");}
    | Exp OR error {error_type = 1; yyerror("Expect expression after 'or'");}
    | Exp LT error {error_type = 1; yyerror("Expect expression after '<'");}
    | Exp LE error {error_type = 1; yyerror("Expect expression after '<='");}
    | Exp GT error {error_type = 1; yyerror("Expect expression after '>'");}
    | Exp GE error {error_type = 1; yyerror("Expect expression after '>=");}
    | Exp NE error {error_type = 1; yyerror("Expect expression after '!='");}
    | Exp EQ error {error_type = 1; yyerror("Expect expression after '=='");}
    | Exp PLUS error {error_type = 1; yyerror("Expect expression after '+'");}
    | Exp MINUS error {error_type = 1; yyerror("Expect expression after '-'");}
    | Exp MUL error {error_type = 1; yyerror("Expect expression after '*'");}
    | Exp DIV error {error_type = 1; yyerror("Expect expression after '/'");}
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
    | COMMA Args {error_type = 1;yyerror("Unexpected ','");}
    | Exp COMMA {error_type = 1;yyerror("Expected another parenthesis after ','");}
    | Exp {$$ = getNode("Args", 1, $1);}
    ;

%%