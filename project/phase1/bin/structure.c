#include "structure.h"

int hasError = 0;
int error_type = -1;

nodePointer getTerminalNode(char *name, char* value, int line){
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    f -> value = value;
    return f;
}

nodePointer getNode(char* name, int num, ...){
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    nodePointer temp = NULL;

    va_list ap;
    va_start(ap, num);
    for(int i = 0;i < num;i++){
        if(i == 0){
            f -> head = va_arg(ap, nodePointer);
            f -> line = f -> head -> line;
            temp = f -> head;
        }else{
            temp -> next = va_arg(ap, nodePointer);
            temp = temp -> next;
        }
    }
    va_end(ap);
    return f;
}

void writeTerminalNode(nodePointer node){
    if(strcmp(node->name,"ID")==0 
        || strcmp(node->name,"TYPE")==0 
        || strcmp(node->name,"CHAR")==0){
        printf("%s: %s", node->name, node->value);
    }else if(strcmp(node->name,"INT")==0){
        printf("INT: ");
        printf("%d",atoi(node->value));
    }else if(strcmp(node->name,"FLOAT")==0){
        printf("FLOAT: ");
        printf("%f",atof(node->value));
    }else{
        printf("%s",node->name);
    }
    printf("\n");
    return;
}

void writeNode(nodePointer node,int deep){
    if(node == NULL)return;
    if(node -> line == -1){
        writeNode(node->next, deep);
        return;
    }

    for(int i = 1;i <= deep;i++){
        printf("    ");
    }

    if(node -> head != NULL){
        printf("%s (%d)\n",node->name, node -> line);
        writeNode(node->head,deep+1);
        writeNode(node->next,deep);
    }else{
        writeTerminalNode(node);
        writeNode(node->next, deep);
    }
}

void yyerror(char *msg)
{
    if(strcmp(msg,"syntax error") !=0 && error_type == 1){
       printf("Error type B at line %d: %s\n",yylineno,msg); // 如果是syntax error
    }else if(error_type == 0){
        print("%s\n", msg); // 或者是 lex error
    }
    hasError=1;
}

int main() {
    yyparse();
}