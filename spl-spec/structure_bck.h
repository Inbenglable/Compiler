#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h> 

extern char* yytext;
extern int yylineno;
extern int error_type;
extern int hasError;
void yyerror(char *msg);


typedef struct Node{
    int line;
    char* name;
    struct Node *head,*next;
    char* value;

};

typedef struct Node* nodePointer;

nodePointer getTerminalNode(char *name, int line);
nodePointer getNode(char* token_name,int num,...);


void writeNode(nodePointer node,int depth);
void writeTerminalNode(nodePointer node);

