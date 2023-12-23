#include "ir_optimization.h"
#include "ir_translate.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Code* head;
struct Code* tail;



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
            int command = tmp->type;
            p = p->from;
            if(command == 2){
                deeper(tmp->tk2,tmp);
                if(check_command2(tmp)){

                }
                replace_command2(tmp->tk1, tmp->tk2, tmp);
                delet(tmp);
            }else if(3 <= command && command <= 6){
                if(check_use(tmp->tk1, tmp)){
                    replace_command3(tmp->tk1, tmp->tk2, tmp->tk2, tmp);
                    delet(tmp);
                }
            }else if(command == 0){
                if(tmp->next != NULL && tmp->next->type == 0){

                }
            }else if(command == 10){
                struct Code* label = find_label(tmp->tk1);
                if(label->next != NULL && label->next->type == 10){

                }
            }
        }
    }
    
    return code;
}