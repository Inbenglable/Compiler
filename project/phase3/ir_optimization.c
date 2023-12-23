#include "ir_optimization.h"
#include "ir_translate.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int block_cnt = 0;
int node_cnt = 0;

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

int check_var(char* name){
    return strncmp(name, "var_", 4) == 0;
}

struct Reg* generate_reg(char* name, struct Dnode* active_in, int is_var){
    struct Reg* ret = (struct Reg*)malloc(sizeof(struct Reg));
    ret->name = name;
    ret->active_in = active_in;
    ret->is_var = is_var;
    return ret;
}

struct Reg* get_reg(char* name, int id){
    if(name == NULL)return NULL;
    struct Reg_list* tmp = block[id].regs;
    while(tmp != NULL){
        if(strcmp(tmp->reg->name, name) == 0){
            return tmp->reg;
        }
        tmp = tmp->next;
    }
    
    tmp = (struct Reg_list*)malloc(sizeof(struct Reg_list));
    tmp->next = block[id].regs;
    block[id].regs = tmp;
    tmp->reg = generate_reg(name, NULL, check_var(name));
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

    if(tk2 != NULL){
        tk2->in++;
    }
    if(tk3 != NULL){
        tk3->in++;
    }
    node_list[++node_cnt] = ret;
    return ret;
}

struct Export* generate_export(int type, int relop, int arg){
    struct Export* ret = (struct Export*)malloc(sizeof(struct Export));
    ret->type = 0;
    ret->relop = relop;
    ret->arg = arg;
    ret->next = NULL;
    return ret;
}

void add_reg(struct Dnode* node, struct Reg* reg){
    struct Reg_list* tmp = node->reg_list;
    
    while(tmp != NULL){
        if(strcmp(tmp->reg->name, reg->name) == 0){
            return;
        }
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
    ret->export = generate_export(5, relop, 0);
    return ret;
}

void assign_reg(struct Reg* reg1, struct Reg* reg2){
    if(reg2->active_in == NULL){
        reg2->active_in = generate_init_Dnode(reg2);
    }
    re1->active_in = reg2->active_in;
    add_reg(reg2->active_in, reg1);
}

int check_export_avail(struct Export* a, int id){
    if(a->type == 4 && a->arg != block[id].arg_cnt)return 0;
    if(a->type == 2 && a->arg != block[id].write_cnt)return 0;
    return 1;
}

int check_bigger(struct Export* a, struct Export* b, int id){
    if(a == NULL)return 0;
    if(b == NULL)return 1;
    if(check_export_avail(a) == 0 && check_export_avail(b) == 1)return 0;
    if(check_export_avail(a) == 1 && check_export_avail(b) == 0)return 1;
    if(a->type > b->type)return 1;
    else if(a->type == b->type && a->arg > b->arg)return 1;
    return 0;
}

int check_bigger_insert(struct Export* a, struct Export* b, int id){
    if(a == NULL)return 0;
    if(b == NULL)return 1;
    if(a->type > b->type)return 1;
    else if(a->type == b->type && a->arg > b->arg)return 1;
    return 0;
}

void insert_export(struct Dnode* node, struct Export* export, int id){
    struct Export* tmp = node->export;
    struct Export* last = NULL
    while(1){
        if(check_bigger_insert(export, tmp, id)){
            if(last == NULL){
                node->export = export;
                export->next = tmp;
            }else{
                last->next = export;
                export->next = tmp;
            }
        }
        last = tmp;
        tmp = tmp->next;
    }
}

struct Reg* find_same(struct Reg* reg, struct Dnode* tk2, struct Dnode* tk3, int operator){
    for(int i = 1;i <= node_cnt;i++){
        if(node_list[i]->tk2 == tk2 && node_list->tk3 == tk3 && node_list->operator==operator){
            add_reg(node_list[i], reg);
            return node_list[i];
        }
    }
    return NULL;
}

struct Dnode* delet_dnode(struct Dnode* node){

    if(node->tk2 != NULL){
        node->tk2->in -= 1;
    }
    if(node->tk3->in != NULL){
        node->tk3->in -= 1;
    }

    free(node);
    return NULL;
}

struct Dnode* get_biggest(int id){
    struct Dnode* ret = NULL;
    for(int i = 1;i <= node_list;i++){
        if(node_list[i] == NULL)continue;
        else if(node_list[i]->in == 0){
            if(check_bigger(ret, node_list[i], id)){
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
            insert_export(list->reg->active_in, generate_export(1,-1,0), id);
        }
        list = list->next;
    }
}

void reduce_useless(struct Dnode* node){
    struct Reg_list* regs = node->reg_list;
    struct Reg_list* tmp = node->reg_list;
    node->reg_list = NULL;
    while(regs != NULL){
        if(regs->reg->is_var == 0)continue;
        if(regs->reg->active_in == node){
            add_reg(node, regs->reg);
        }
        regs = regs->next;
    }
    if(node->reg_list == NULL){
        tmp->next = NULL;
        node->reg_list = tmp;
    }
}

struct Code* solve(struct Dnode* node, int id){
    if(node->export != NULL){
        int export_command = node->export->type;
        if(export_command == 1){
            node->export = node->export->next;
            if(node->export == NULL){
                if(node->isconst == 1){
                    return construct(2, node->reg_list->reg->name, -1, to_literal(node->value), NULL);
                }
            }
            struct Reg_list* tmp = node->reg_list;
            node->reg_list = node->reg_list->next;
            return construct(2, tmp->reg->name, -1, node->reg_list->reg->name, NULL);
        }else if(export_command == 2){
            node->export = node->export->next;
            block[id].write_cnt--;
            return construct(18, node->reg_list->reg->name, -1, NULL, NULL);
        }else if(export_command == 3){
            node->export = node->export->next;
            block[id].arg_cnt--;
            return construct(15, node->reg_list->reg->name, -1, NULL, NULL);
        }else if(export_command == 4){
            node->export = node->export->next;
            return construct(12, node->reg_list->reg->name, -1, NULL, NULL);
        }else if(export_command == 5){
            node->export = node->export->next;
            struct Code* ret = construct(11, node->tk1->reg_list->reg->name, -1,node->tk2->reg_list->reg->name, node->splc_name);
            delet_dnode(node);
            return ret;
        }
        
    }else{
        struct Code* ret = NULL;
        if(command >= 1 && command <= 4){
            ret = construct(command+2, node->reg_list->reg->name, -1, node->tk2->reg_list->reg->name, node->tk3->reg_list->reg->name);
        }else if(command == 5){
            ret = construct(16, node->reg_list->reg->name, -1, node->splc_name, NULL);
        }else if(command == 6){
            ret = construct(17, node->reg_list->reg->name, -1, NULL, NULL);
        }
        delet_dnode(node);
        return ret;
    }
}

void complete_block(int id){
    node_cnt = 0;
    struct Code* tmp = block[id].front;
    if(tmp == NULL)return;
    while(1){
        int command = tmp->type;
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
        }else if(command >= 3 || command <= 6){
            reg1 = get_reg(tmp->tk1, id);
            reg2 = get_reg(tmp->tk2, id);
            reg3 = get_ret(tmp->tk3, id);
            if(reg2->active_in == NULL)reg2->active_in = generate_init_Dnode(reg2);
            if(reg3->active_in == NULL)reg3->active_in = generate_init_Dnode(reg3);
            reg1->active_in = find_same(reg1, re2->active_in, reg3->active_in, tmp->type-2);
            if(reg1->active_in == NULL){
                ret1->active_in = generate_Dnode(reg1, reg2->active_in, reg3->active_in, 0, 0, tmp->type-2,, NULL);
            }
        }else if(command == 11){
            reg2 = get_reg(tmp->tk1, id);
            reg3 = get_ret(tmp->tk2, id);
            if(reg2->active_in == NULL)reg2->active_in = generate_init_Dnode(reg2);
            if(reg3->active_in == NULL)reg3->active_in = generate_init_Dnode(reg3);    
            generate_if_Dnode(reg2->active_in, reg3->active_in, tmp->tk3, tmp->relop);
        }else if(command == 12){
            reg1 = get_reg(tmp->tk1, id);
            if(reg1->active_in == NULL)reg1->active_in = generate_init_Dnode(reg1);
            insert_export(reg1->active_in, generate_export(4, -1, 0), id);
        }else if(command == 15){
            reg1 = get_reg(tmp->tk1, id);
            if(reg1->active_in == NULL)reg1->active_in = generate_init_Dnode(reg1);
            insert_export(reg1->active_in, generate_export(3, -1, ++block[id].arg_cnt), id);
        }else if(command == 16){
            reg1 = get_reg(tmp->tk1, id);
            reg1->active_in = generate_Dnode(reg1, NULL, NULL, 0, 0, 5, tmp->tk2);
        }else if(command == 17){
            reg1 = get_reg(tmp->tk1, id);
            reg1->active_in = generate_Dnode(reg1, NULL, NULL, 0, 0, 6, NULL);
        }else if(command == 18){
            reg1 = get_reg(tmp->tk1, id);
            if(reg1->active_in == NULL)reg1->active_in = generate_init_Dnode(reg1);
            insert_export(reg1->active_in, generate_export(2, -1, ++block[id].write_cnt), id);
        }

        if(tmp == block[id].end)break;
        tmp = tmp->next;
    }

    assign_export(id);

    int has_delet = 1;
    while(has_delet){
        has_delet = 0;
        for(int i node_cnt;i >= 1;i--){
            if(node_list[i] == NULL)continue;
            if(node_list[i]->in == 0 && node_list[i]->export == NULL){
                node_list[i] = delet_dnode(node_list[i]);
                has_delet = 1;
            }
        }
    }

    for(int i = 1;i <= node_cnt;i++){
        if(node_list[i] == NULL)continue;
        reduce_useless(node_list[i]);
    }

    struct Code* code_head = NULL;
    struct Code* code = block[id].end;
    code->next = NULL;
    if(code->type == 10)code_head = code;
    while(true){
        struct Dnode* tmp = get_biggest(id);
        if(tmp == NULL)break;
        code = slove(tmp, id);
        code_head = append_wo_tail(code, code_head);
    }
    code = block[id].front;
    while(code->next != NULL && code->next->type == 14)code = code->next;
    code->next = NULL;
    block[id].front = append_wo_tail(block[id].front, code_head);
}

struct Code* optimize(struct Code* code){
    struct Code* head = code;
    struct Code* tail = code;
    while(tail != NULL && tail->next != NULL)tail = tail->next;

    struct Code* tmp = head;
    struct Block block = NULL;
    struct Code* last = NULL;
    int end_block = 1;
    while(tmp != NULL){
        int command = tmp->type;
        if(command == 0 || command == 1){
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
        }else if(command == 10||command == 11||command == 12){
            finish_gen_block(block_cnt, tmp);
            end_block = 1;
        }
        last = tmp;
        tmp = tmp->next;
    }
    if(end_block == 0)finish_gen_block(block_cnt, tail);

    for(int i = 1;i <= block_cnt;i++){
        inital_block(i);
    }

    struct Code* ret = NULL;
    for(int i = 1;i <= block_cnt;i++){
        complete_block(i);
        ret = append_wo_tail(ret, block[i].front);
    }

}