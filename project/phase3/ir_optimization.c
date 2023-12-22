#include "ir_optimization.h"
#include "ir_translate.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Code* head;
struct Code* tail;

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