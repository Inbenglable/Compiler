#include "ir_optimization.h"
#include "ir_translate.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Code* head;
struct Code* tail;

void merge_label(){
    struct Code* ptr = head, next_ptr;
    while(ptr != NULL){
        next_ptr = ptr->next;
        if(ptr->type == 0 && next_ptr != NULL && next_ptr->type == 0){
            char* old = next_ptr->tk1;
            char* new = ptr->tk1;
            delet(next_ptr);
            replace_label(old, new);
            next_ptr = ptr->next;
        }
        ptr = next_ptr;
    }
}

void remove_continuous_jump(){
    struct Code* ptr = head, next_ptr;
    while(ptr != NULL){
        next_ptr = ptr->next;
        if(ptr->type == 0 && next_ptr != NULL && next_ptr->type == 10){
            char* old = ptr->tk1;
            char* new = next_ptr->tk1;
            delete(ptr);
            replace_label(old, new);
        }
        ptr = next_ptr;
    }
}

void replace_label(char* old, char* new){
    struct Code* p = head;
    while(p != NULL){
        if(p->type == 10 && strcmp(p->tk1, old) == 0){
            strcpy(p->tk1, new);
        }
        else if(p->type == 11 && strcmp(p->tk3, old) == 0){
            strcpy(p->tk3, new);
        }
        p = p->next;
    }
}

void remove_unused_lval(){
    struct Code* ptr = head, next_ptr;
    while(ptr != NULL){
        next_ptr = ptr->next;
        if(ptr->type >= 2 && ptr->type <= 8 && !check_use(ptr->tk1, ptr)){
            delet(ptr);
        }
        ptr = next_ptr;
    }
}

int check_use_in_code(struct Code* code, char* name){
    if(code->type >= 2 && code->type <= 8){
        if(strcmp(code->tk1, name) == 0)return 0;
        if(strcmp(code->tk2, name) == 0)return 1;
        if(code->type >= 3 && code->type <= 6){
            if(strcmp(code->tk3, name) == 0)return 1;
        }
    }
    else if(code->type == 12){
        if(strcmp(code->tk1, name) == 0)return 1;
        return 0;
    }
    else if(code->type == 11){
        if(strcmp(code->tk1, name) == 0)return 1;
        if(strcmp(code->tk2, name) == 0)return 1;
    }
    else if(code->type == 13){
        if(strcmp(code->tk1, name) == 0)return 0;
    }
    else if(code->type == 15){
        if(strcmp(code->tk1, name) == 0)return 1;
    }
    else if(code->type == 16){
        if(strcmp(code->tk1, name) == 0)return 0;
    }
    else if(code->type == 17){
        if(strcmp(code->tk1, name) == 0)return 0;
    }
    else if(code->type == 18){
        if(strcmp(code->tk1, name) == 0)return 1;
    }
    return -1;
}

int check_use(struct Code* code, char* name){
    struct Code* ptr = code->next;
    while(ptr != NULL){
        int res = check_use_in_code(ptr, name);
        if(res == 1)return 1;
        else if(res == 0)return 0;
        ptr = ptr->next;
    }
    return 0;
}

void delet(struct Code* code){
    struct Code* from = code -> from;
    struct Code* to = code -> next;
    
    if(from != NULL){
        from -> next = to;
    }else{
        head = to;
    }

    if(to != NULL){
        to -> from = from;
    }else{
        tail = from;
    }
    free(code);
}

struct Code* optimize(struct Code* code){
    // TODO: requires implementation
    int has_change = 1;
    head = code;
    tail = code;
    while(tail != NULL && tail->next != NULL)tail = tail->next;
    while(has_change){
        struct Code* p = tail;
        while(p != NULL){
            struct Code* tmp = p;
            p = p->from;
            int command = tmp->type;
            if(command == 2){
                replace(tmp->tk1, tmp->tk2, tmp->tk3, tmp);
                delet(tmp);
            }else if(3 <= command && command <= 6){
                if(check_use(tmp->tk1, tmp)){
                    replace(tmp->tk1, tmp->tk2, tmp->tk2, tmp);
                    delet(tmp);
                }
            }else if(command == 0){
                if(tmp->next == NULL || tmp->)
            }else if(command == 10){

            }


        }
    }
    
    return code;
}