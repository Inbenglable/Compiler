#include "ir_translate.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int label_count = 0;
int tmp_count = 0;

char* to_literal(int val){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "#%d", val);
    return ret;
}

char* to_size(int val){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "%d", val);
    return ret;
}

char* to_var(char* name){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "var_%s", name);
    return ret;
}

char* new_label_name(){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "label_%d", label_count++);
    return ret;
}

char* new_tmp_name(){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "tmp_%d", tmp_count++);
    return ret;
}

struct Code* construct(int type, char* tk1, int relop, char* tk2, char* tk3){
    struct Code* ret = (struct Code*)malloc(sizeof(struct Code));
    ret->type = type;
    ret->tk1 = tk1;
    ret->relop = relop;
    ret->tk2 = tk2;
    ret->tk3 = tk3;
    ret->is_const = 0;
    ret->value = 0;
    ret->is_tmp = 0;
    ret->next = NULL;
    ret->from = NULL;
    return ret;
}

struct Code* append(struct Code* code1_head, struct Code* code1_tail, struct Code* code2_head, struct Code* code2_tail){
    if(code1_head == NULL || code1_head->type == -1){
        return code2_head;
    }
    if(code2_head == NULL || code2_head->type == -1){
        return code1_head;
    }
    code1_tail->next = code2_head;
    code2_head->from = code1_tail;
    return code1_head;
}


void dump(struct Code* head, char* filename){
    FILE* fp = fopen(filename, "w");
    while(head != NULL){
        switch(head->type){
            case 0:
                fprintf(fp, "LABEL %s :\n", head->tk1);
                break;
            case 1:
                fprintf(fp, "FUNCTION %s :\n", head->tk1);
                break;
            case 2:
                fprintf(fp, "%s := %s\n", head->tk1, head->tk2);
                break;
            case 3:
                fprintf(fp, "%s := %s + %s\n", head->tk1, head->tk2, head->tk3);
                break;
            case 4:
                fprintf(fp, "%s := %s - %s\n", head->tk1, head->tk2, head->tk3);
                break;
            case 5:
                fprintf(fp, "%s := %s * %s\n", head->tk1, head->tk2, head->tk3);
                break;
            case 6:
                fprintf(fp, "%s := %s / %s\n", head->tk1, head->tk2, head->tk3);
                break;
            case 7:
                fprintf(fp, "%s := &%s\n", head->tk1, head->tk2);
                break;
            case 8:
                fprintf(fp, "%s := *%s\n", head->tk1, head->tk2);
                break;
            case 9:
                fprintf(fp, "*%s := %s\n", head->tk1, head->tk2);
                break;
            case 10:
                fprintf(fp, "GOTO %s\n", head->tk1);
                break;
            case 11:
                fprintf(fp, "IF %s %s %s GOTO %s\n", head->tk1, head->relop == 0 ? "<" : head->relop == 1 ? "<=" : head->relop == 2 ? ">" : head->relop == 3 ? ">=" : head->relop == 4 ? "!=" : "==", head->tk2, head->tk3);
                break;
            case 12:
                fprintf(fp, "RETURN %s\n", head->tk1);
                break;
            case 13:
                fprintf(fp, "DEC %s %s\n", head->tk1, head->tk2);
                break;
            case 14:
                fprintf(fp, "PARAM %s\n", head->tk1);
                break;
            case 15:
                fprintf(fp, "ARG %s\n", head->tk1);
                break;
            case 16:
                fprintf(fp, "%s := CALL %s\n", head->tk1, head->tk2);
                break;
            case 17:
                fprintf(fp, "READ %s\n", head->tk1);
                break;
            case 18:
                fprintf(fp, "WRITE %s\n", head->tk1);
                break;
        }
        head = head->next;
    }
    fclose(fp);
}

struct Code* translate_exp(struct Node* node, char* place){
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "INT") == 0){

    }
    else if(strcmp(son_list, "ID") == 0){

    }
    else if(strcmp(son_list, "ExpPLUSExp") == 0){

    }
    else if(strcmp(son_list, "ExpMINUSExp") == 0){

    }
    else if(strcmp(son_list, "ExpMULExp") == 0){

    }
    else if(strcmp(son_list, "ExpDIVExp") == 0){

    }
    else if(strcmp(son_list, "LPExpRP") == 0){

    }
    else if(strcmp(son_list, "MINUSExp") == 0){

    }
    //below are function invocations
    else if(strcmp(son_list, "IDLPRP") == 0){

    }
    else if(strcmp(son_list, "IDLPArgsRP") == 0){

    }
    else{

    }
}

struct Code* translate_cond(struct Node* node, char* label_true, char* label_false){
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "ExpLTExp") == 0){

    }
    else if(strcmp(son_list, "ExpLEExp") == 0){

    }
    else if(strcmp(son_list, "ExpGTExp") == 0){

    }
    else if(strcmp(son_list, "ExpGEExp") == 0){

    }
    else if(strcmp(son_list, "ExpNEExp") == 0){

    }
    else if(strcmp(son_list, "ExpEQExp") == 0){

    }
    else if(strcmp(son_list, "ExpANDExp") == 0){

    }
    else if(strcmp(son_list, "ExpORExp") == 0){

    }
    else if(strcmp(son_list, "NOTExp") == 0){

    }
    else if(strcmp(son_list, "LPExpRP") == 0){

    }
    else{

    }
}

struct Code* translate_stmt(struct Node* node){
    char* son_list = get_son_list(node);
}

struct Code* translate_args(struct Node* node, struct ArgList** arg_list){
    char* son_list = get_son_list(node);
}

void translate(struct Node* node, char* filename){
    printf("Translation requires implementation, the name of the root is %s, the translation result will be output to %s\n", node->name, filename);
}


///////////////////////////////////////////////////////////////////////////////////////

//By radiance: 我写的部分都写下面好了

int char_to_int(const char* str) {
    // 使用atoi函数将字符串转换为整数
    int result = atoi(str);

    return result;
}


int var_to_int(const char* str) {
    int result;
    
    // 使用sscanf解析字符串，跳过'#'字符，将整数部分存储到result中
    sscanf(str, "#%d", &result);

    return result;
}

int start_with_hash(const char* str) {
    // 检查输入指针是否为NULL
    if (str == NULL) {
        return 0;
    }

    // 使用 strncmp 函数比较字符串的前缀是否为 "#"
    if (strncmp(str, "#", 1) == 0) {
        return 1;  // 字符串以 '#' 开头
    } else {
        return 0; // 字符串不以 '#' 开头
    }
}
