#include "ir_optimization.h"
#include "ir_translate.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int block_cnt = 0;
int node_cnt = 0;
int code_cnt = 0;
int struct_cnt = 0;
struct Reg struct_list[114514];
struct Block block[114514];
struct Dnode* node_list[114514];

void finish_gen_block(int id, struct Code* tail){
    block[id].end = tail;
}

void generate_block(int id, struct Code* head){
    block[id].next = -1;
    block[id].if_next = -1;
    block[id].front = head;
    block[id].end = NULL;
    block[id].regs = NULL;
    block[id].write_cnt = 0;
    block[id].arg_cnt = 0;
    block[id].recode = NULL;
}

void inital_block(int id){
    //Todo: if you want to check the initial of var.
}

char* getRemainingString(char *variable, char* prefix) {
    // 使用strstr函数找到 "var_" 的位置
    char *start = strstr(variable, prefix);
    if (start != NULL) {
        return start + strlen(prefix);
    } else {
        return variable;
    }
}

int check_var(char* name, int id){
    if(strncmp(name, "var_", 4) == 0)return 1;
    if(strncmp(name, "*", 1) == 0){
        get_reg(getRemainingString(name, "*"), id)->is_var = 1;
        return 1;
    }else if(strncmp(name, "&", 1) == 0){
        get_reg(getRemainingString(name, "&"), id)->is_var = 1;
        return 1;
    }
    else return 0;
}

int check_is_struct(char* name){
    for(int i = 1;i <= struct_cnt;i++){
        if(strcmp(name, struct_list[i].name) == 0){
            return 1;
        }
    }
    return 0;
}

struct Reg* generate_reg(char* name, struct Dnode* active_in, int is_var){
    struct Reg* ret = (struct Reg*)malloc(sizeof(struct Reg));
    ret->name = name;
    ret->active_in = active_in;
    ret->is_var = is_var;
    ret->is_struct = 0;
    ret->is_struct = check_is_struct(name);
    return ret;
}

struct Reg* get_reg(char* name, int id){
    if(name == NULL)return NULL;
    struct Reg_list* tmp = block[id].regs;
    while(tmp != NULL){
        if(tmp->reg == NULL){
            tmp = tmp->next;
            continue;
        }
        if(strcmp(tmp->reg->name, name) == 0){
            tmp->reg->last_k = code_cnt;
            return tmp->reg;
        }
        tmp = tmp->next;
    }
    
    tmp = (struct Reg_list*)malloc(sizeof(struct Reg_list));
    tmp->reg = NULL;
    tmp->next = block[id].regs;
    block[id].regs = tmp;
    tmp->reg = generate_reg(name, NULL, check_var(name, id));
    tmp->reg->last_k = code_cnt;
    return tmp->reg;
}

struct Dnode* generate_Dnode(struct Reg* reg, struct Dnode* tk2, struct Dnode* tk3, int isconst, int value, int operator, char* splc_name){
    struct Dnode* ret = (struct Dnode*)malloc(sizeof(struct Dnode));
    ret->in = ret->out = 0;
    ret->export = NULL;
    ret->reg_list = (struct Reg_list*)malloc(sizeof(struct Reg_list));
    ret->reg_list->reg = reg;
    ret->reg_list->next = NULL;
    ret->tk2 = tk2;
    ret->tk3 = tk3;
    ret->isconst = isconst;
    ret->value = value;
    ret->operator = operator;
    ret->splc_name = splc_name;
    ret->k = code_cnt;
    if(tk2 != NULL){
        tk2->in++;
    }
    if(tk3 != NULL){
        tk3->in++;
    }
    node_list[++node_cnt] = ret;
    return ret;
}

struct Export* generate_export(int type, int relop, int k){
    struct Export* ret = (struct Export*)malloc(sizeof(struct Export));
    ret->type = type;
    ret->relop = relop;
    ret->k = k;
    ret->next = NULL;
    return ret;
}

void add_reg(struct Dnode* node, struct Reg* reg){
    struct Reg_list* tmp = node->reg_list;
    
    while(tmp != NULL){
        if(strcmp(tmp->reg->name, reg->name) == 0){
            return;
        }
        tmp = tmp->next;
    }

    tmp = (struct Reg_list*)malloc(sizeof(struct Reg_list));
    tmp->next = node->reg_list;
    node->reg_list = tmp;
    tmp->reg = reg;
}

struct Dnode* generate_init_Dnode(struct Reg* reg){
    return generate_Dnode(reg, NULL, NULL, 0, 0, 0, NULL);
}

struct Dnode* generate_if_Dnode(struct Dnode* tk2, struct Dnode* tk3, char* name, int relop){
    struct Dnode* ret = generate_Dnode(NULL, tk2, tk3, 0, 0, 7, name);
    ret->export = generate_export(5, relop, code_cnt);
    return ret;
}

int not_a_addr(char* name){
    if(strncmp(name, "*", 1) == 0 || strncmp(name, "&", 1) == 0){
        return 0;
    }
    return 1;
}

void assign_reg(struct Reg* reg1, struct Reg* reg2){
    if(reg2->active_in == NULL){
        reg2->active_in = generate_init_Dnode(reg2);
    }
    // printf("%s %s %d\n", reg1->name, reg2->name, reg2->active_in->isconst);
    // fflush(stdout);
    if(reg2->active_in->in == 0 && not_a_addr(reg1->name) == 1){
        reg1->active_in = reg2->active_in;
        add_reg(reg2->active_in, reg1);
    }else{
        reg1->active_in = generate_Dnode(reg1, reg2->active_in, NULL, 0, 0, 8, NULL);
    }
    
}

int check_bigger(struct Dnode* a, struct Dnode* b){
    if(a == NULL)return 0;
    if(b == NULL)return 1;
    int ak = a->k;
    if(a->export != NULL && a->export->k > ak)ak = a->export->k;
    int bk = b->k;
    if(b->export != NULL && b->export->k > bk)bk = b->export->k;
    if(ak > bk) return 1;
    return 0;
}

int check_bigger_insert(struct Export* a, struct Export* b, int id){
    if(a == NULL)return 0;
    if(b == NULL)return 1;
    if(a->k > b->k) return 1;
    return 0;
}

void insert_export(struct Dnode* node, struct Export* export, int id){
    struct Export* tmp = node->export;
    struct Export* last = NULL;
    // printf("%d %d %d\n",export->type, export->relop, export->k);
    // fflush(stdout);
    while(1){
        
        if(check_bigger_insert(export, tmp, id)){
            // printf("%d %d %d\n",export->type, export->relop, export->arg);
            // fflush(stdout);
            // printf("%d %d %d\n",tmp->type, tmp->relop, tmp->arg);
            // fflush(stdout);
            if(last == NULL){
                node->export = export;
                export->next = tmp;
            }else{
                last->next = export;
                export->next = tmp;
            }
            return;
        }
        last = tmp;
        tmp = tmp->next;
    }
}

struct Dnode* find_same(struct Reg* reg, struct Dnode* tk2, struct Dnode* tk3, int operator){
    for(int i = 1;i <= node_cnt;i++){
        if(node_list[i]->tk2 == tk2 && node_list[i]->tk3 == tk3 && node_list[i]->operator==operator){
            if(node_list[i]->in == 0){
                add_reg(node_list[i], reg);
                return node_list[i];
            }
        }
    }
    return NULL;
}

struct Dnode* delet_dnode(struct Dnode* node){

    if(node->tk2 != NULL){
        node->tk2->in -= 1;
    }
    if(node->tk3!= NULL){
        node->tk3->in -= 1;
    }

    node->in = -1;
    return NULL;
}

struct Dnode* get_biggest(int id){
    struct Dnode* ret = NULL;
    for(int i = 1;i <= node_cnt;i++){
        if(node_list[i] == NULL)continue;
        else if(node_list[i]->in == 0){
            if(ret == NULL)ret = node_list[i];
            if(check_bigger(node_list[i], ret)){
                ret = node_list[i];
            }
        }
    }
    return ret;
}

void assign_export(int id){
    struct Reg_list* list = block[id].regs;
    while(list != NULL){
        if(list->reg->is_var){
            insert_export(list->reg->active_in, generate_export(1,-1,list->reg->last_k), id);
        }
        list = list->next;
    }
}

void reduce_useless(struct Dnode* node){
    struct Reg_list* regs = node->reg_list;
    struct Reg_list* tmp = node->reg_list;
    if(node->operator == 7)return;
    node->reg_list = NULL;
    while(regs != NULL){
        
        if(regs->reg->is_var == 0){
            regs = regs->next;
            continue;
        }
        
        if(regs->reg->active_in == node){
            // printf("!%s\n", regs->reg->name);
            // fflush(stdout);
            add_reg(node, regs->reg);
        }
        regs = regs->next;
    }
    regs = node->reg_list;
    node->reg_list = NULL;
    while(regs != NULL){
        add_reg(node, regs->reg);
        regs = regs->next;
    }
    if(node->reg_list == NULL){
        while(tmp->next != NULL)tmp = tmp->next;
        node->reg_list = tmp;
    }

    regs = node->reg_list;
}

int check_exist_one(struct Export* export){
    if(export == NULL)return 0;
    struct Export* tmp = export;
    while(tmp != NULL){
        if(tmp->type == 1)return 1;
        tmp = tmp->next;
    }
    return 0;
}

struct Code* solve(struct Dnode* node, int id){
    if(node->export != NULL){
        int export_command = node->export->type;
        if(export_command == 1){
            node->export = node->export->next;
            if(check_exist_one(node->export) == 0){
                if(node->isconst == 1){
                    return construct(2, node->reg_list->reg->name, -1, to_literal(node->value), NULL);
                }else{
                    return NULL;
                }
            }
            struct Reg_list* tmp = node->reg_list;
            node->reg_list = node->reg_list->next;
            return construct(2, tmp->reg->name, -1, get_token_name(node), NULL);
        }else if(export_command == 2){
            node->export = node->export->next;
            block[id].write_cnt--;
            return construct(18, get_token_name(node), -1, NULL, NULL);
        }else if(export_command == 3){
            node->export = node->export->next;
            block[id].arg_cnt--;
            return construct(15, get_token_name(node), -1, NULL, NULL);
        }else if(export_command == 4){
            node->export = node->export->next;
            return construct(12, get_token_name(node), -1, NULL, NULL);
        }else if(export_command == 5){
            
            struct Code* ret = construct(11, get_token_name(node->tk2), node->export->relop,get_token_name(node->tk3), node->splc_name);
            delet_dnode(node);
            return ret;
        }
        
    }else{
        struct Code* ret = NULL;
        int command = node->operator;
        if(node->isconst){
            delet_dnode(node);
            return NULL;
        }
        if(command >= 1 && command <= 4){
            ret = construct(command+2, node->reg_list->reg->name, -1, get_token_name(node->tk2), get_token_name(node->tk3));
        }else if(command == 5){
            ret = construct(16, node->reg_list->reg->name, -1, node->splc_name, NULL);
        }else if(command == 6){
            ret = construct(17, node->reg_list->reg->name, -1, NULL, NULL);
        }else if(command == 8){
            ret = construct(2, node->reg_list->reg->name, -1, get_token_name(node->tk2), NULL);
        }
        delet_dnode(node);
        return ret;
    }
}

void print_node_list(){
    for(int i = 1;i <= node_cnt;i++){
        if(node_list[i] == NULL)continue;
        if(node_list[i]->operator != 7)printf("nodelist %d : operater is %d, var is %s, in is %d, k is %d\n", i, node_list[i]->operator, node_list[i]->reg_list->reg->name, node_list[i]->in, node_list[i]->k);
        else printf("nodelist %d : operater is %d, this is an if, in is %d\n", i, node_list[i]->operator, node_list[i]->in);
        if(node_list[i]->export != NULL){
            printf("with export type %dand it's k is %d\n", node_list[i]->export->type, node_list[i]->export->k);   
        }
        fflush(stdout);
    }
    printf("Finish list nodes\n");
    fflush(stdout);
}

char *get_token_name(struct Dnode* node){
    if(node->reg_list != NULL && node->reg_list->reg != NULL && node->reg_list->reg->is_struct == 1){
        return node->reg_list->reg->name;
    }
    if(node->isconst){
        return to_literal(node->value);
    }else return node->reg_list->reg->name;
    return NULL;
}

int change_to_const(struct Dnode* node){
    if(node->isconst == 1)return 0;
    if(node->operator == 5 || node->operator == 6 || node->operator == 7 || node->operator == 0)return 0;
    if(node->operator == 8 && node->tk2->isconst == 1){
        node->isconst = 1;
        node->value = node->tk2->value;
        return 1;
    }
    if(node->tk2->isconst == 1 && node->tk3->isconst == 1){
        node->isconst=1;
        if(node->operator == 1){
            node->value = node->tk2->value + node->tk3->value;
        }
        if(node->operator == 2){
            node->value = node->tk2->value - node->tk3->value;
        }
        if(node->operator == 3){
            node->value = node->tk2->value * node->tk3->value;
        }
        if(node->operator == 4){
            node->value = node->tk2->value / node->tk3->value;
        }
        return 1;
    }
    return 0;
}

void complete_block(int id){
    // printf("Start complete block%d\n", id);
    // fflush(stdout);
    node_cnt = 0;
    code_cnt = 0;
    struct Code* tmp = block[id].front;
    if(tmp == NULL)return;
    while(1){
        ++code_cnt;
        int command = tmp->type;
        // printf("building code: %d %s %d %s %s\n", tmp->type, tmp->tk1, tmp->relop, tmp->tk2, tmp->tk3);
        // fflush(stdout);
        struct Reg* reg1 = NULL;
        struct Reg* reg2 = NULL;
        struct Reg* reg3 = NULL;
        if(command == 0 || command == 1){
            //Nothing todo
        }else if(command == 2){
            if(start_with_well(tmp->tk2)){
                reg1 = get_reg(tmp->tk1, id);
                reg1->active_in = generate_Dnode(reg1, NULL, NULL, 1, var_to_int(tmp->tk2), 0, NULL);
            }else{
                reg1 = get_reg(tmp->tk1, id);
                reg2 = get_reg(tmp->tk2, id);
                assign_reg(reg1, reg2);
            }
        }else if(command >= 3 && command <= 6){
            reg1 = get_reg(tmp->tk1, id);
            reg2 = get_reg(tmp->tk2, id);
            reg3 = get_reg(tmp->tk3, id);
            if(reg2->active_in == NULL)reg2->active_in = generate_init_Dnode(reg2);
            if(reg3->active_in == NULL)reg3->active_in = generate_init_Dnode(reg3);
            reg1->active_in = find_same(reg1, reg2->active_in, reg3->active_in, tmp->type-2);
            if(reg1->active_in == NULL){
                reg1->active_in = generate_Dnode(reg1, reg2->active_in, reg3->active_in, 0, 0, tmp->type-2, NULL);
            }
        }else if(command == 11){
            reg2 = get_reg(tmp->tk1, id);
            reg3 = get_reg(tmp->tk2, id);
            if(reg2->active_in == NULL)reg2->active_in = generate_init_Dnode(reg2);
            if(reg3->active_in == NULL)reg3->active_in = generate_init_Dnode(reg3);    
            generate_if_Dnode(reg2->active_in, reg3->active_in, tmp->tk3, tmp->relop);
        }else if(command == 12){
            reg1 = get_reg(tmp->tk1, id);
            if(reg1->active_in == NULL)reg1->active_in = generate_init_Dnode(reg1);
            insert_export(reg1->active_in, generate_export(4, -1, code_cnt), id);
        }else if(command == 15){
            reg1 = get_reg(tmp->tk1, id);
            if(reg1->active_in == NULL)reg1->active_in = generate_init_Dnode(reg1);
            insert_export(reg1->active_in, generate_export(3, -1, code_cnt), id);
        }else if(command == 16){
            reg1 = get_reg(tmp->tk1, id);
            reg1->active_in = generate_Dnode(reg1, NULL, NULL, 0, 0, 5, tmp->tk2);
        }else if(command == 17){
            reg1 = get_reg(tmp->tk1, id);
            reg1->active_in = generate_Dnode(reg1, NULL, NULL, 0, 0, 6, NULL);
        }else if(command == 18){
            reg1 = get_reg(tmp->tk1, id);
            if(reg1->active_in == NULL)reg1->active_in = generate_init_Dnode(reg1);
            insert_export(reg1->active_in, generate_export(2, -1, code_cnt), id);
        }else{
            // printf("error with command = %d\n", command);
            // fflush(stdout);
        }

        if(tmp == block[id].end)break;
        tmp = tmp->next;
    }

    // printf("complete build dag of block %d\n", id);
    // fflush(stdout);

    assign_export(id);

    // printf("complete assign export of block %d\n", id);
    // fflush(stdout);
    // print_node_list();
    int has_delet = 1;
    while(has_delet){
        has_delet = 0;
        for(int i = node_cnt;i >= 1;i--){
            if(node_list[i] == NULL)continue;
            if(node_list[i]->in == 0 && node_list[i]->export == NULL && node_list[i]->operator != 6 && node_list[i]->operator != 5){
                //printf("Delet %d\n", i);
                node_list[i] = delet_dnode(node_list[i]);
                has_delet = 1;
            }
        }
    }

    // printf("complete delet usless node of block %d\n", id);
    // fflush(stdout);

    for(int i = 1;i <= node_cnt;i++){
        if(node_list[i] == NULL)continue;
        // printf("%d\n", i);
        // fflush(stdout);
        reduce_useless(node_list[i]);
    }

    // printf("complete delet usless var of block %d\n", id);
    // fflush(stdout);

    int has_change = 1;
    while(has_change){
        has_change = 0;
        for(int i = node_cnt;i >= 1;i--){
            if(node_list[i] == NULL)continue;
            if(change_to_const(node_list[i])){
                // printf("%d, %d\n", i, node_list[i]->value);
                has_change = 1;
            }
        }
    }

    // printf("complete compute constant %d\n", id);
    // fflush(stdout);
    

    struct Code* code_head = NULL;
    struct Code* code = block[id].end;
    code->next = NULL;
    if(code->type == 10)code_head = code;

    // printf("begin generate code* of block %d\n", id);
    // fflush(stdout);

    
    while(1){
        // print_node_list();
        struct Dnode* tmp = get_biggest(id);
        if(tmp == NULL)break;
        // if(tmp->operator != 7)printf("begin generate code* of Dnode: %d, %s\n", tmp->operator, tmp->reg_list->reg->name);
        // else printf("begin generate IF command\n");
        // if(tmp->export != NULL)printf("And it's export type is %d\n", tmp->export->type);
        // fflush(stdout);
        // printf("??!!!\n");
        // fflush(stdout);
        code = solve(tmp, id);
        // if(code != NULL)printf("generate code : %d %s %s %s\n", code->type, code->tk1, code->tk2, code->tk3);
        code_head = append_wo_tail(code, code_head);
    }
    // printf("??!\n");
    code = block[id].front;
    if(code->type == 1 || code->type == 0 || code->type == 13){
        while(code->next != NULL && code->next->type == 14)code = code->next;
        code->next = NULL;
        block[id].front = append_wo_tail(block[id].front, code_head);
    }else{
        code = NULL;
        block[id].front = append_wo_tail(code, code_head);
    }
    

    // printf("complete solve block %d\n", id);
    // fflush(stdout);
}

struct Code* optimize(struct Code* code){
    // printf("Start to optimize\n");
    fflush(stdout);
    struct Code* head = code;
    struct Code* tail = code;
    while(tail != NULL && tail->next != NULL)tail = tail->next;

    struct Code* tmp = head;
    struct Code* last = NULL;
    int end_block = 1;
    while(tmp != NULL){
        int command = tmp->type;
        if(command == 13){
            struct_list[++struct_cnt].name = tmp->tk1;
        }
        if(command == 0 || command == 1 || command == 13){
            if(!end_block){
                finish_gen_block(block_cnt, last);
                block_cnt++;
                generate_block(block_cnt, tmp);
                end_block = 0;
            }else{
                block_cnt++;
                generate_block(block_cnt, tmp);
                end_block = 0;
            }
        }else if(end_block){
            block_cnt++;
            generate_block(block_cnt, tmp);
            end_block = 0;
        }
        if(command == 10||command == 11||command == 12){
            finish_gen_block(block_cnt, tmp);
            end_block = 1;
        }
        last = tmp;
        tmp = tmp->next;
    }
    if(end_block == 0)finish_gen_block(block_cnt, tail);
    // printf("Finish blocking code\n");
    fflush(stdout);
    for(int i = 1;i <= block_cnt;i++){
        inital_block(i);
    }

    // printf("Finish init code\n");
    fflush(stdout);

    struct Code* ret = NULL;
    for(int i = 1;i <= block_cnt;i++){
        complete_block(i);
        ret = append_wo_tail(ret, block[i].front);
    }
    // printf("Finish combine code\n");
    // fflush(stdout);
    // if(ret == NULL)printf("???\n");
    return ret;
}