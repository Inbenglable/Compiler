#include "ir_translate.h"

char* to_literal(int val){
    char* ret = (char*)malloc(sizeof(char) * 20);
    sprintf(ret, "#%d", val);
    return ret;
}

char* to_var(char* name){
    char* ret = (char*)malloc(sizeof(char) * 20);
    sprintf(ret, "var_%s", name);
    return ret;
}

struct Code* construct(int type, struct Code* tk1, int relop, struct Code* tk2, struct Code* tk3){
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
    if(code1_head == NULL){
        return code2_head;
    }
    if(code2_head == NULL){
        return code1_head;
    }
    code1_tail->next = code2_head;
    code2_head->from = code1_tail;
    return code1_head;
}
