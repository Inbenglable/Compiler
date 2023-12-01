#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "structure.h"
#include "symbol_table.h"

int hasError = 0;
int error_type = -1;

void print_var(struct Var* var, int deep);
void print_type(struct Type* type, int deep){
    if(type == NULL)return;
    for(int i = 1;i <= deep;i++){
        printf("    ");
    }
    printf("Type-- name:%s, isStruct:%c, hash:%lld\n", type->type_name, type->isStruct, type->hash);
    print_var(type->contain, deep+1);
}

void print_var(struct Var* var, int deep){
    if(var == NULL)return;
    for(int i = 1;i <= deep;i++){
        printf("    ");
    }
    printf("Var-- name:%s dim:%d\n", var->name, var->dim);
    print_type(var->type, deep+1);
    var = var->next;
    while(var != NULL){
        print_var(var, deep);
        var = var->next;
    }
}

nodePointer getTerminalNode(char *name, int line){
    // printf("terminal: %s %d %s\n", name, line, yytext);
    // fflush(stdout);
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    //printf("Success\n");
    f -> value = (char*)malloc(sizeof(char)*30);
    strcpy(f->value,yytext);
    f->type = NULL;
    f->var = NULL;
    if(line == -1){
        return f;
    }
    struct Var* temp = (struct Var*)malloc(sizeof(struct Var));
    temp -> name = NULL;
    temp -> dim = 0;
    temp -> type = NULL;
    temp -> head = temp -> next = NULL;
    f -> var = temp;

    if(strcmp(name, "INT") == 0){
       temp -> type = (struct Type*)malloc(sizeof(struct Type));
       temp -> type -> isStruct = 'v';
       temp -> type -> hash = 0;
       temp -> type -> type_name = (char*)malloc(sizeof(char)*30);
       strcpy(temp -> type -> type_name, "int");
       temp -> type -> contain = NULL;
    }else if(strcmp(name, "FLOAT") == 0){
       temp -> type = (struct Type*)malloc(sizeof(struct Type));
       temp -> type -> isStruct = 'v';
       temp -> type -> hash = 0;
       temp -> type -> type_name = (char*)malloc(sizeof(char)*30);
       strcpy(temp -> type -> type_name, "float");
       temp -> type -> contain = NULL;
    }else if(strcmp(name, "CHAR") == 0){
       temp -> type = (struct Type*)malloc(sizeof(struct Type));
       temp -> type -> isStruct = 'v';
       temp -> type -> hash = 0;
       temp -> type -> type_name = (char*)malloc(sizeof(char)*30);
       strcpy(temp -> type -> type_name, "char");
       temp -> type -> contain = NULL;
    }
    return f;
}

nodePointer getIDNode(char *name, int line){
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    f -> value = (char*)malloc(sizeof(char)*30);
    strcpy(f->value,yytext);
    struct Var* temp = (struct Var*)malloc(sizeof(struct Var));
    temp -> name = (char*)malloc(sizeof(char)*30);
    temp -> dim = 0;
    strcpy(temp -> name,yytext);
    temp -> type = NULL;
    temp -> head = temp -> next = NULL;
    f -> var = temp;
    return f;
}

nodePointer getTypeNode(char *name, int line){
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    f -> value = (char*)malloc(sizeof(char)*30);
    strcpy(f->value,yytext);
    struct Type* temp = (struct Type*)malloc(sizeof(struct Type));
    temp -> isStruct = 'v';
    temp -> hash = 0;
    temp -> type_name = (char*)malloc(sizeof(char)*30);
    strcpy(temp -> type_name,yytext);
    temp -> contain = NULL;
    f -> type = temp;
    return f;
}

int push_fun(nodePointer fun_node){
    if(fun_node == NULL || fun_node -> var == NULL)return -1;
    if(store_Fun(fun_node->var->name, fun_node->var)){
        return 0;
    }
    return fun_node->line;
}

int push_type(nodePointer type_node){
    if(type_node == NULL || type_node -> type == NULL)return -1;
    if(store_Type(type_node -> type -> type_name, type_node->type)){
        return 0;
    }
    return type_node -> line;
}

int push_var(nodePointer varlist){
    struct Var* var = varlist -> var;
    while(var != NULL){
        //print_var(varlist -> var, 0);
        int ret = store_ID(var -> name, var);
        if(ret == 0){
            //printf("push_var error while trying push %s\n", var->name);
            fflush(stdout);
            return varlist -> line;
        }
        var = var -> next;
    }
    return 0;
}

int getStruct(nodePointer spec, nodePointer id){
    struct Type* type = query_Type(id -> value);
    spec -> type = type;
    return (type != NULL) ? 1 : 0;
}

void newFuntype(nodePointer funspec, nodePointer id, nodePointer varlist){
    struct Var* fun = (struct Var*)malloc(sizeof(struct Var));
    fun -> dim = 0;
    fun -> head = fun -> next = NULL;
    fun -> type = NULL;
    fun -> name = (char*)malloc(sizeof(char)*30);
    strcpy(fun -> name, id -> value);
    if(varlist != NULL)fun -> next = varlist -> var;
    
    funspec -> var = fun;
}

void assign_funtype(nodePointer spec, nodePointer fun){
    fun -> var -> type = spec -> type;
}

void newStructType(nodePointer spec, nodePointer id, nodePointer varlist){
    struct Type* temp = (struct Type*)malloc(sizeof(struct Type));
    temp -> isStruct = 's';
    temp -> type_name = (char*)malloc(sizeof(char)*30);
    strcpy(temp -> type_name,id -> value);
    temp -> hash = 0;
    temp -> contain = varlist -> var;
    temp -> hash = get_hash(temp);
    spec -> type = temp;
}

void assign_type(nodePointer type_provider, nodePointer var_head){
    //print_var(var_head -> var, 0);
    struct Var* var = var_head->var;
    struct Type* type = type_provider -> type;
    while(var != NULL){
        var -> type = type;
        var = var -> next;
    }
}

void extend_type(nodePointer to, nodePointer from){
    to -> type = from -> type;
}

void connect_var(nodePointer now, nodePointer to){
    now -> var -> next = to -> var;
}

void extend_var(nodePointer to, nodePointer from){
    to -> var = from -> var;
}

void extend_dim(nodePointer var){
    var -> var -> dim += 1;
}

struct Var* check_ID_def(nodePointer node){
    struct Var* var = query_ID(node -> var -> name);
    return var;
}

int check_fun_def(nodePointer node){
    if(query_Fun(node -> var -> name) != NULL){
        return 1;
    }
    return 0;
}

int check_assign_type(nodePointer lnode, nodePointer rnode){
    if(lnode -> var == NULL || rnode -> var == NULL){
        printf("!!!!\n");
        return 0;
    }
    if(lnode -> var -> type == NULL || rnode -> var -> type == NULL)return 0;
    if(lnode -> var -> type -> hash == rnode -> var -> type -> hash)return 1;
    return 0;
}

int check_rvalue(nodePointer node){
    if(node->var == NULL || node->type == NULL)return 0;
    if(node -> var -> name == NULL && strcmp(node->type->type_name, "int") == 0)return 1;
    if(node -> var -> name == NULL && strcmp(node->type->type_name, "float") == 0)return 1;
    if(node -> var -> name == NULL && strcmp(node->type->type_name, "char") == 0)return 1;
    return 0;
}

Type* check_field(Type* typeptr, char* name){
    Var* var = typeptr->contain;
    while(var != NULL){
        if(strcmp(var->name, name) == 0){
            return var->type;
        }
        var = var->next;
    }
    return NULL;
}

nodePointer getNode(char* name, int num, ...){
    printf("%s %d %s\n", name, yylineno, yytext);
    fflush(stdout);
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> type = NULL;
    f -> var = NULL;
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

char* mystrcat(char* str1,char* str2,char* str3){
    // 计算新字符串所需的总长度
    int totalLength = strlen(str1) + strlen(str2) + strlen(str2) + 1; // +1 为 '\0'

    // 动态分配空间
    char *result = malloc(totalLength * sizeof(char));
    if (result == NULL) {
        perror("Unable to allocate memory for the result string");
        exit(1);
    }

    // 使用 strcpy 和 strcat 来拼接字符串
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    return result;
}

void writeTerminalNode(nodePointer node){
    if(node == NULL)return;
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
    //printf("?? %d %s \"%s\"\n", yylineno, yytext, msg);
    if(error_type == 1 && strcmp(msg,"syntax error")!=0){
        printf("Error type B at line %d: %s\n",yylineno,msg); // 如果是syntax error
    }else if(error_type == 0 && strcmp(msg,"syntax error")!=0){
        printf("Error type A at line %d: %s\n",yylineno,msg); // 或者是 lex error
    }
    else if(error_type % 10 == 0){
        printf("!!Error type %d at line %d: %s\n",error_type / 10,yylineno,msg);
    }
    fflush(stdout);
    hasError=1;
}


int main(int argc, char **argv) {
    //printf("oooooooo\n");
    init_symbol_table();
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
    //clear_symbol_table();
}