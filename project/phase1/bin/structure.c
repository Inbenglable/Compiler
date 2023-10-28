#include "structure.h"

int hasError = 0;
int error_type = -1;

nodePointer getTerminalNode(char *name, int line){
    //printf("terminal: %s %d %s\n", name, line, yytext);
    //fflush(stdout);
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    //printf("Success\n");
    f -> value = (char*)malloc(sizeof(char)*30);
    strcpy(f->value,yytext);
    
    return f;
}

nodePointer getNode(char* name, int num, ...){
    //printf("%s %d %s\n", name, yylineno, yytext);
    //fflush(stdout);
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
            //if(strcmp("RC", temp->name) == 0)printf("OOOOO!");
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
        writeNode(node->head, deep+1);
        writeNode(node->next, deep);
        return;
    }

    for(int i = 1;i <= deep;i++){
        printf("  ");
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
    //printf("?? %d %s %s\n", yylineno, yytext, msg);
    if(error_type == 1 && strcmp(msg,"syntax error")!=0){
        printf("Error type B at line %d: %s\n",yylineno,msg); // 如果是syntax error
    }else if(error_type == 0){
        //printf("Error type A at line %d: %s\n",yylineno,msg); // 或者是 lex error
    }
    hasError=1;
}


int main(int argc, char **argv) {
    if (argc < 2)
    {
        
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
       
        hasError = 0;

        FILE *f = fopen(argv[i], "r");
        if (!f)
        {
            perror(argv[i]);
            return 1;
        }
        yyrestart(f);
        //printf("oooooooo%s\n", argv[i]);
        fflush(stdout);
        yyparse();
        fclose(f);
        
    }
}

