#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h> 

extern char* yytext;
extern int yylineno;
extern int error_type;
extern int hasError;
void yyerror(char *msg);

typedef struct Type{
    char* type_name;//the name of the type
    char isStruct;//s -> structure, v-> var, f->function
    int dim;// deep of the array
    int hash;//type hash
    struct Var* contain;
};

typedef struct Var{
    char* name;
    struct Type* type;
    struct Var* head, next;
};


// typedef struct {
//     char* name;  //变量名
//     char isStruct;  //v则为变量类型,s则为结构体名，f则为函数
//     char* value;  //变量，函数的type存在这里,结构体这里为结构体名
//     int array_layer;   
// }var;
// // int a, int a[],  struct A{}a [], int funtion a()   project: 

// typedef struct {
//     struct var* varPoint;
//     struct varlistNode* next;
// }varlistNode;

typedef struct Node{
    int line;
    char* name;
    struct Node *head,*next;
    char* value;
    struct Type* type;
    struct Var* var;
};

typedef struct Node* nodePointer;

nodePointer getTerminalNode(char *name, int line);
nodePointer getIDNode(char *name, int line);
nodePointer getNode(char* token_name,int num,...);

void writeNode(nodePointer node,int depth);
void writeTerminalNode(nodePointer node);

char* mystrcat(char* str1,char* str2,char* str3);
