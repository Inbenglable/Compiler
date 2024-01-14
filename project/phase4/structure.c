#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "structure.h"
#include "symbol_table.h"
#include "ir_translate.h"
#include "mips.h"

int hasError = 0;
int error_type = -1;
int error_line = -1;

nodePointer root = NULL;

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
    printf("Var-- name:%s dim:%d addr:%p\n", var->name, var->dim, var);
    print_type(var->type, deep+1);
    var = var->next;
    print_var(var, deep);
}

char* get_son_list(nodePointer node){
    if(node == NULL)return NULL;
    char* ret = (char*)malloc(sizeof(char)*200);
    memset(ret, 0, sizeof(ret));
    nodePointer son = node->head;
    while(son != NULL){
        strcat(ret, son->name);
        // strcat(ret, " ");
        son = son->next;
    }
    return ret;
}

nodePointer getTerminalNode(char *name, int line){
    // printf("terminal: %s %d %s\n", name, line, yytext);
    // fflush(stdout);
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> tmp_name = NULL;
    f -> code_head = f ->code_tail = NULL;
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
    temp -> offset = 0;
    temp -> line = yylineno;
    temp -> name = NULL;
    temp -> dim = 0;
    temp -> type = NULL;
    temp -> next = NULL;
    f -> var = temp;

    if(strcmp(name, "INT") == 0){
       temp -> type = (struct Type*)malloc(sizeof(struct Type));
       temp -> type -> size = 4;
       temp -> type -> isStruct = 'v';
       temp -> type -> hash = 2;
       temp -> type -> type_name = (char*)malloc(sizeof(char)*30);
       strcpy(temp -> type -> type_name, "int");
       temp -> type -> contain = NULL;
       f -> type = temp -> type;
    }else if(strcmp(name, "FLOAT") == 0){
       temp -> type = (struct Type*)malloc(sizeof(struct Type));
       temp -> type -> size = 4;
       temp -> type -> isStruct = 'v';
       temp -> type -> hash = 5;
       temp -> type -> type_name = (char*)malloc(sizeof(char)*30);
       strcpy(temp -> type -> type_name, "float");
       temp -> type -> contain = NULL;
       f -> type = temp -> type;
    }else if(strcmp(name, "CHAR") == 0){
       temp -> type = (struct Type*)malloc(sizeof(struct Type));
       temp -> type -> size = 4;
       temp -> type -> isStruct = 'v';
       temp -> type -> hash = 3;
       temp -> type -> type_name = (char*)malloc(sizeof(char)*30);
       strcpy(temp -> type -> type_name, "char");
       temp -> type -> contain = NULL;
       f -> type = temp -> type;
    }
    return f;
}

nodePointer getIDNode(char *name, int line){
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> tmp_name = NULL;
    f -> code_head = f ->code_tail = NULL;
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    f -> value = (char*)malloc(sizeof(char)*30);
    strcpy(f->value,yytext);
    struct Var* temp = (struct Var*)malloc(sizeof(struct Var));
    temp -> offset = 0;
    temp -> name = (char*)malloc(sizeof(char)*30);
    temp -> dim = 0;
    temp -> line = yylineno;
    strcpy(temp -> name,yytext);
    temp -> type = NULL;
    temp -> next = NULL;
    f -> var = temp;
    return f;
}

nodePointer getTypeNode(char *name, int line){
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> tmp_name = NULL;
    f -> code_head = f ->code_tail = NULL;
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    f -> value = (char*)malloc(sizeof(char)*30);
    strcpy(f->value,yytext);
    struct Type* temp = (struct Type*)malloc(sizeof(struct Type));
    temp -> size = 4;
    temp -> isStruct = 'v';
    temp -> hash = 0;
    temp -> type_name = (char*)malloc(sizeof(char)*30);
    strcpy(temp -> type_name,yytext);
    temp -> contain = NULL;
    temp -> hash = get_hash(temp);
    f -> type = temp;
    return f;
}

int push_fun(nodePointer fun_node){
    if(fun_node == NULL || fun_node -> var == NULL)return -1;
    if(store_Fun(fun_node->var->name, fun_node->var)){
        return 0;
    }
    fflush(stdout);
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
    int ret = 0;
    while(var != NULL){
        //print_var(varlist -> var, 0);
        int ret = store_ID(var -> name, var);
        if(ret == 0){
            error_type = 30;
            error_line = var->line;
            char* name = var->name;
            char* msg = (char*)malloc(sizeof(name)+sizeof(char)*100);
            memset(msg, 0,sizeof(msg));
            strcat(msg, "variable \"");
            strcat(msg, name);
            strcat(msg, "\" is redefined in the same scope");
            yyerror(msg);
            free(msg);
            error_line = -1;
        }
        var = var -> next;
    }
    return ret;
}

int getStruct(nodePointer spec, nodePointer id){
    struct Type* type = query_Type(id -> value);
    spec -> type = type;
    return (type != NULL) ? 1 : 0;
}

void newFuntype(nodePointer funspec, nodePointer id, nodePointer varlist){
    struct Var* fun = (struct Var*)malloc(sizeof(struct Var));
    fun -> offset = 0;
    fun -> dim = 0;
    fun -> next = NULL;
    fun -> type = NULL;
    fun -> name = (char*)malloc(sizeof(char)*30);
    fun -> line = yylineno;
    strcpy(fun -> name, id -> value);
    if(varlist != NULL)fun -> next = varlist -> var;
    
    funspec -> var = fun;
}

void assign_funtype(nodePointer spec, nodePointer fun){
    fun -> var -> type = spec -> type;
}

int set_offset(struct Var* varlist){
    struct Var* temp = varlist;
    int size = 0;
    while(temp != NULL){
        temp -> offset = size;
        size += temp -> type -> size;
        temp = temp -> next;
    }
    return size;
}

void newStructType(nodePointer spec, nodePointer id, nodePointer varlist){
    struct Type* temp = (struct Type*)malloc(sizeof(struct Type));
    temp -> isStruct = 's';
    temp -> type_name = (char*)malloc(sizeof(char)*30);
    strcpy(temp -> type_name,id -> value);
    temp -> hash = 0;
    temp -> contain = varlist -> var;
    temp -> hash = get_hash(temp);
    temp -> size = set_offset(temp->contain);
    spec -> type = temp;
}

int check_fun_varlist(nodePointer fun, nodePointer varlist){
    struct Var* funvar = fun->var->next;
    struct Var* var = varlist->var;
    // print_var(funvar, 0);
    // printf("\n");
    // print_var(var, 0);
    while(funvar != NULL){
        if(var == NULL){
            return -1;
        }
        if(var->type == NULL){
            funvar = funvar->next;
            var = var->next;
            continue;
        }
        var->type->hash = get_hash(var->type);
        funvar->type->hash = get_hash(funvar->type);
        if(funvar->type->hash != var->type->hash){
            return 0;
        }
        funvar = funvar->next;
        var = var->next;
    }
    if(var != NULL){
        return -1;
    }
    return 1;
}

struct Type* get_int_type(){
    struct Type* type = (struct Type*)malloc(sizeof(struct Type));
    type -> size = 4;
    type->contain = NULL;
    type->hash = 2;
    type->isStruct = 'V';
    type->type_name = (char*)malloc(30*sizeof(char));
    strcpy(type->type_name, "int");
    return type;
}

void generate_exp_var(nodePointer exp, struct Type* type){
    struct Var* var = NULL;
    if(exp->var == NULL){
        var = (struct Var*)malloc(sizeof(struct Var));
        var -> offset = 0;
    }else{
        var = exp->var;
        var -> type = type;
    }
    var -> line = yylineno;
    var -> dim = 0;
    var -> next = NULL;
    var -> name = (char*)malloc(30*sizeof(char));
    strcpy(var->name, "-expression");
    var->type = type;
    exp->var = var;
    exp->type = type;
}

int assign_type(nodePointer type_provider, nodePointer var_head){
    struct Var* var = var_head->var;
    struct Type* type = type_provider -> type;
    if(type == NULL)return 1;
    type->hash = get_hash(type);
    int ret = 1;
    while(var != NULL){
        if(var->type != NULL){
            var->type->hash = get_hash(var->type);
            if(var->type->hash != type->hash){
                error_type = 50;
                error_line = var->line;
                yyerror("unmatching type on both sides of assignment");
            }
        }
        var -> type = type;
        var = var -> next;
    }
    return ret;
}

void extend_type(nodePointer to, nodePointer from){
    to -> type = from -> type;
}

void connect_var(nodePointer now, nodePointer to){
    // printf("Connecting   \n");
    // fflush(stdout);
    // if(to->var != NULL)printf("Connecting %s to %s\n", now->var->name, to->var->name);
    // else printf("Connecting %s to NULL\n", now->var->name);
    // fflush(stdout);
    now -> var -> next = to -> var;
}

int check_ret_type(nodePointer spec, nodePointer varlist){
    spec->type->hash = get_hash(spec->type);

    struct Var* var = varlist->var;
    //print_var(var, 0);

    if(var == NULL)return 1;
    // printf("ret_check1\n");
    // fflush(stdout);
    while(var != NULL){
        if(var -> type == NULL){
            var = var->next;
            continue;
        }
        var->type->hash = get_hash(var->type);
        if(var->type->hash != spec->type->hash){
            error_type = 80;
            error_line = var->line;
            yyerror("incompatiable return type");     
        }
        var = var->next;
    }

    return 1;

}

void connect_link_var(nodePointer head, nodePointer ne){
    if(head -> var == NULL){
        head -> var = ne -> var;
        return;
    }
    // printf("Head\n");
    // print_var(head->var, 0);
    // printf("ne\n");
    // print_var(ne->var, 0);
    // fflush(stdout);
    struct Var* var = head->var;
    while(var->next != NULL){
        var = var->next;
    }
    var->next = ne->var;

}

void extend_var(nodePointer to, nodePointer from){
    to -> var = from -> var;
}

void extend_dim(nodePointer var){
    Var* tmp = (Var*)malloc(sizeof(Var));
    //Todo: define arrays' offset
    tmp->offset = var->var->offset;
    tmp->line = var->var->line;
    tmp->name = var->var->name;
    tmp->dim = var->var->dim + 1;
    tmp->type = var->var->type;
    tmp->next = var->var->next;
    var->var = tmp;
}

void reduce_dim(nodePointer var){
    Var* tmp = (Var*)malloc(sizeof(Var));
    //Todo: define arrays' offset
    tmp->offset = var->var->offset;
    tmp->line = var->var->line;
    tmp->name = var->var->name;
    tmp->dim = var->var->dim - 1;
    tmp->type = var->var->type;
    tmp->next = var->var->next;
    var->var = tmp;
}

struct Var* check_ID_def(nodePointer node){
    //print_var(node->var, 0);
    struct Var* var = query_ID(node -> var -> name);
    if(var != NULL)var->line = yylineno;
    return var;
}

struct Var* check_fun_def(nodePointer node){
    return query_Fun(node -> var -> name);
}

int check_boolean(nodePointer node1, nodePointer node2){
    if(node1->type == NULL || node2->type == NULL)return -1;
    if(check_assign_type(node1, node2) == 0)return 0;
    if (strcmp(node1 -> type->type_name, "int") == 0)return 1;
    return 0;
}

int check_arithmetic(nodePointer node1, nodePointer node2){
    if(node1->type == NULL || node2->type == NULL)return -1;
    if(check_assign_type(node1, node2) == 0)return 0;
    if (strcmp(node1 -> type->type_name, "int") == 0 || strcmp(node1 -> type->type_name, "float") == 0)return 1;
    return 0;
}

int check_assign_type(nodePointer lnode, nodePointer rnode){
    if(lnode -> type == NULL || rnode -> type == NULL)return -1;
    if(lnode -> type -> hash == rnode -> type -> hash)return 1;
    return 0;
}

int check_rvalue(nodePointer node){
    // print_var(node -> var, 0);
    if(node->var == NULL || node->type == NULL)return 0;
    if(node -> var -> name == NULL || strcmp(node -> var -> name, "-expression") == 0)return 1;
    return 0;
}

Var* check_field(Type* typeptr, char* name){
    Var* var = typeptr->contain;
    while(var != NULL){
        if(strcmp(var->name, name) == 0){
            return var;
        }
        var = var->next;
    }
    return NULL;
}

int check_dim(nodePointer node){
    if(node->var == NULL)return 0;
    if(node->var->dim > 0)return 1;
    return 0;
}

int check_index(nodePointer node){
    if(node->type == NULL)return 0;
    if(strcmp(node->type->type_name, "int") == 0)return 1;
    return 0;
}

int check_struct(nodePointer node){
    if(node->type == NULL)return 0;
    if(node->type->isStruct == 's')return 1;
    return 0;
}

nodePointer getNode(char* name, int num, ...){
    // printf("%s %d %s\n", name, yylineno, yytext);
    // fflush(stdout);
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> tmp_name = NULL;
    f -> code_head = f ->code_tail = NULL;
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
        printf("%s (%d, %s)\n",node->name, node -> line, get_son_list(node));
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
    if(error_line == -1)error_line = yylineno;
    if(error_type == 1 && strcmp(msg,"syntax error")!=0){
        printf("Error type B at line %d: %s\n",error_line ,msg); // 如果是syntax error
    }else if(error_type == 0 && strcmp(msg,"syntax error")!=0){
        printf("Error type A at line %d: %s\n",error_line ,msg); // 或者是 lex error
    }
    else if(error_type % 10 == 0){
        printf("Error type %d at line %d: %s\n",error_type / 10,error_line ,msg);
    }
    error_line = -1;
    fflush(stdout);
    hasError=1;
}

void initial_read_write(){
    //void newFuntype(nodePointer funspec, nodePointer id, nodePointer varlist){
    struct Type* type_int = (struct Type*)malloc(sizeof(struct Type));
    type_int->size = 4;
    type_int -> isStruct = 'v';
    type_int -> hash = 2;
    type_int -> type_name = (char*)malloc(sizeof(char)*30);
    strcpy(type_int -> type_name, "int");
    type_int -> contain = NULL;

    struct Var* read = (struct Var*)malloc(sizeof(struct Var));
    read -> dim = 0;
    read -> next = NULL;
    read -> type = type_int;
    read -> name = (char*)malloc(sizeof(char)*30);
    read -> line = -1;
    strcpy(read -> name, "read");

    struct Var* write = (struct Var*)malloc(sizeof(struct Var));
    write -> dim = 0;
    write -> next = NULL;
    write -> type = type_int;
    write -> name = (char*)malloc(sizeof(char)*30);
    write -> line = -1;
    strcpy(write -> name, "write");

    struct Var* write_arg = (struct Var*)malloc(sizeof(struct Var));
    write_arg -> dim = 0;
    write_arg -> next = NULL;
    write_arg -> type = type_int;
    write_arg -> name = (char*)malloc(sizeof(char)*30);
    write_arg -> line = -1;
    strcpy(write_arg -> name, "-write_arg");
    write->next = write_arg;

    store_Fun(read->name, read);
    store_Fun(write->name, write);
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

        //check whether the input f is .ir file or not
        int len = strlen(argv[i]);
        if(argv[i][len-1] == 'r' && argv[i][len-2] == 'i' && argv[i][len-3] == '.'){
            char* out_file = (char*)malloc(sizeof(char)*(strlen(argv[i]) + 5));
            strcat(out_file, argv[i]);
            Code* ir_code = parse_ir_file(f);
            for(int i = strlen(out_file)-1;i >= 0;i--){
                if(out_file[i] == '.'){
                    out_file[i] = '\0';
                    break;
                }
            }
            strcat(out_file, ".s");
            translate_mips(ir_code, out_file);
            return 0;
        }

        initial_read_write();
        //Var* read = query_Fun("read");
        //Var* write = query_Fun("write");
        //if(read == NULL || write == NULL){
        //    printf("Error: read or write function not found\n");
        //    return 1;
        //}
        yyrestart(f);
        //printf("oooooooo%s\n", argv[i]);
        fflush(stdout);
        yyparse();
        fclose(f);
        
    }
    char* out_file = (char*)malloc(sizeof(char)*strlen(argv[1]));
    memset(out_file, 0, sizeof(out_file));
    strcat(out_file, argv[1]);
    for(int i = strlen(out_file)-1;i >= 0;i--){
        if(out_file[i] == '.'){
            out_file[i] = '\0';
            break;
        }
    }
    strcat(out_file, ".ir");
    Code* ir_code = translate(root, out_file);
    for(int i = strlen(out_file)-1;i >= 0;i--){
        if(out_file[i] == '.'){
            out_file[i] = '\0';
            break;
        }
    }
    strcat(out_file, ".s");
    translate_mips(ir_code, out_file);
    //clear_symbol_table();
    return 0;
}