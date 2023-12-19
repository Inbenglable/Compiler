#include "ir_translate.h"

int label_count = 0;
int tmp_count = 0;

char* to_literal(int val){
    char* ret = (char*)malloc(sizeof(char) * 20);
    sprintf(ret, "#%d", val);
    return ret;
}

char* to_size(int val){
    char* ret = (char*)malloc(sizeof(char) * 20);
    sprintf(ret, "%d", val);
    return ret;
}

char* to_var(char* name){
    char* ret = (char*)malloc(sizeof(char) * 20);
    sprintf(ret, "var_%s", name);
    return ret;
}

char* new_label_name(){
    char* ret = (char*)malloc(sizeof(char) * 20);
    sprintf(ret, "label_%d", label_count++);
    return ret;
}

char* new_tmp_name(){
    char* ret = (char*)malloc(sizeof(char) * 20);
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
    retue = 0;
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


///////////////////////////////////////////////////////////////////////////////////////

//By radiance: 我写的部分都写下面好了