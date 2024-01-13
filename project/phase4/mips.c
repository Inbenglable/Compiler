#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "mips.h"

Mips_Var vars[1145];
int var_cnt;
Reg regs[32];
int reg_used_cnt;
int label_cnt;
label_name labels[1145];

void change_label_tag(char* name){
    int exist = 0;
    for(int i = 1;i <= label_cnt;i++){
        if(strcmp(labels[i].name, name) == 0){
            labels[i].tag = 1;
            exist = 1;
            return;
        }
    }
    if(exist == 0){
        labels[++label_cnt].name = name;
        labels[label_cnt].tag = 1;
    }
    return;
}

int check_label_tag(char* name){
    for(int i = 1;i <= label_cnt;i++){
        if(strcmp(labels[i].name, name) == 0){
            return labels[i].tag;
        }
    }
    return 0;
}

Mips* update_all_regs(){
    if(var_cnt <= 25-8+1) return NULL;
    Mips* ret = NULL;
    for(int i = 8;i <= 25;i++){
        if(regs[i].reg != -1){
            ret = link_Mips(ret, update_reg(i, regs[i].var_id));
        }
    }
    return ret;
}

int check_create_var(char* name){
    int i;
    for(i = 1; i <= var_cnt; i++){
        if(vars[i].name == NULL){
            continue;
        }
        if(strcmp(vars[i].name, name) == 0){
            return 0;
        }
    }
    return 1;
}



int check_var_mips(char* name){
    if(strncmp(name, "var_", 4) == 0){
        return check_create_var(name);
    }else if(strncmp(name, "tmp_", 4) == 0){
        return check_create_var(name);
    }
    return 0;
}

char* init(Code *head){
    Code *tmp = head;
    var_cnt = 0;
    while(tmp != NULL){
        if(tmp->tk1 != NULL && check_var_mips(tmp->tk1) == 1){
            vars[++var_cnt].name = tmp->tk1;
            vars[var_cnt].incash = 0;
            vars[var_cnt].reg = -1;
        }
        if(tmp->tk2 != NULL && check_var_mips(tmp->tk2) == 1){
            vars[++var_cnt].name = tmp->tk2;
            vars[var_cnt].incash = 0;
            vars[var_cnt].reg = -1;
        }
        if(tmp->tk3 != NULL && check_var_mips(tmp->tk3) == 1){
            vars[++var_cnt].name = tmp->tk3;
            vars[var_cnt].incash = 0;
            vars[var_cnt].reg = -1;
        }
        tmp = tmp->next;
    }
    for(int i = 0; i < 32; i++){
        regs[i].reg = i;
        regs[i].var_id = -1;
        regs[i].visited = 0;
        if(i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 31){
            regs[i].preserved = 1;
        }else{
            regs[i].preserved = 0;
        }
    }
    
    char* ret = (char*)malloc(sizeof(char)*100);
    sprintf(ret, ".data\n");
    if(var_cnt <= 25-8+1){
        for(int i = 1;i <= var_cnt;i++){
            vars[i].reg = i+8-1;
            regs[i+8-1].var_id = i;
        }
    }else{
        sprintf(ret, "%s    reg_root: .space %d\n", ret, var_cnt*4);
    }
    sprintf(ret, "%s    .globl main\n", ret);
    sprintf(ret, "%s    __prompt__: .asciiz \"Enter an integer: \"\n", ret);
    sprintf(ret, "%s.text\n", ret);
    return ret;
}

Mips* gen_mips(char* op, char* tk_d, char* tk_s, char* tk_t){
    Mips *mips = (Mips*)malloc(sizeof(Mips));
    mips->op = op;
    mips->tk_d = tk_d;
    mips->tk_s = tk_s;
    mips->tk_t = tk_t;
    mips->next = NULL;
    mips->prev = NULL;
    return mips;
}

Mips* link_Mips(Mips *code1, Mips *code2){
    if(code1 == NULL){
        return code2;
    }
    if(code2 == NULL){
        return code1;
    }
    Mips *tmp = code1;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = code2;
    code2->prev = tmp;
    return code1;
}

char* int_to_reg(int reg){
    if(reg == 0){
        return "$zero";
    }else if(reg == 1){
        return "$at";
    }else if(reg == 2){
        return "$v0";
    }else if(reg == 3){
        return "$v1";
    }else if(reg == 4){
        return "$a0";
    }else if(reg == 5){
        return "$a1";
    }else if(reg == 6){
        return "$a2";
    }else if(reg == 7){
        return "$a3";
    }else if(reg >= 8 && reg <= 15){
        char* ret = (char*)malloc(sizeof(char)*30);
        sprintf(ret, "$t%d", reg-8);
        printf("%s\n", ret);
        fflush(stdout);
        return ret;
    }else if(reg >= 16 && reg <= 23){
        char* ret = (char*)malloc(sizeof(char)*30);
        sprintf(ret, "$s%d", reg-16);
        return ret;
    }else if(reg == 24){
        return "$t8";
    }else if(reg == 25){
        return "$t9";
    }else if(reg == 26){
        return "$k0";
    }else if(reg == 27){
        return "$k1";
    }else if(reg == 28){
        return "$gp";
    }else if(reg == 29){
        return "$sp";
    }else if(reg == 30){
        return "$fp";
    }else if(reg == 31){
        return "$ra";
    }else{
        return NULL;
    }
}

char* get_var_addr_str(int offset){
    char* ret = (char*)malloc(sizeof(char)*30);
    if(offset == 0){
        ret = "reg_root";
    }else{
        sprintf(ret, "reg_root + %d", offset);
    }
    return ret;
}

Mips* update_reg(int reg, int var_id){
    if(var_id == -1)return NULL;
    vars[var_id].reg = -1;
    regs[reg].var_id = -1;
    return gen_mips("sw", int_to_reg(reg), get_var_addr_str(var_id*4-4), NULL);
}

Mips* load_var(int reg, int var_id){
    
    if(var_id == -1)return NULL;printf("reg %d, var_id %d\n", reg, var_id);
    fflush(stdout);
    regs[reg].var_id = var_id;
    vars[var_id].reg = reg;
    return gen_mips("lw", int_to_reg(reg), get_var_addr_str(var_id*4-4), NULL);
}

int get_unused_reg(){
    int ret = -1;
    int mi = 0x7fffffff;
    for(int i = 8;i <= 25;i++){
        if(regs[i].var_id == -1){
            ret = i;
            break;
        }
        if(regs[i].visited < mi && regs[i].preserved == 0){
            ret = i;
            mi = regs[i].visited;
        }
    }
    return ret;
}

ret_struct get_mips_reg(char *var_name){
    ret_struct ret = {3, NULL};

    for(int i = 1;i <= var_cnt;i++){
        if(strcmp(vars[i].name, var_name) == 0){
            if(vars[i].reg != -1){
                ret.reg = vars[i].reg;
                ret.code = NULL;
                regs[ret.reg].visited = reg_used_cnt;
                return ret;
            }else{
                ret.reg = get_unused_reg();
                ret.code = NULL;
                ret.code = link_Mips(ret.code, update_reg(ret.reg, regs[ret.reg].var_id));
                ret.code = link_Mips(ret.code, load_var(ret.reg, i));
                printf("assign var %s to reg %d\n", var_name, ret.reg);
                fflush(stdout);
                regs[ret.reg].visited = reg_used_cnt;
                
                return ret;
            }
        }
    }
    return ret;
}

///Radiance's part ends here
///FC_Viiiiictor_K's part is over here

int arg_cnt = 0;

char* add_offset_to_reg(int reg, int offset){
    char* ret = (char*)malloc(sizeof(char)*30);
    sprintf(ret, "%d(%s)", offset, int_to_reg(reg));
    return ret;
}

Mips *code_2_mips(Code* code){
    /*
    type 0: LABEL tk1 :
    type 1: FUNCTION tk1 :
    type 2: tk1 := tk2                  // tk2 could be a constant or a variable
    type 3: tk1 := tk2 + tk3            // tk2 or tk3 could be a constant, but not both, or they can be both variables
    type 4: tk1 := tk2 - tk3            // tk2 or tk3 could be a constant, but not both, or they can be both variables
    type 5: tk1 := tk2 * tk3            // tk2 or tk3 could be a constant, but not both, or they can be both variables
    type 6: tk1 := tk2 / tk3            // tk2 or tk3 could be a constant, but not both, or they can be both variables
    type 7: tk1 := &tk2                 // this will not appear in our ir code
    type 8: tk1 := *tk2                 // this will not appear in our ir code
    type 9: *tk1 := tk2                 // this will not appear in our ir code
    type 10: GOTO tk1                   // tk1 must be a label name
    type 11: IF tk1 relop tk2 GOTO tk3  // tk3 must be a label name, tk1 or tk2 could be a constant or a variable, they may be both constants or both variables
    type 12: RETURN tk1                 // tk1 could be a constant or a variable
    type 13: DEC tk1 size               // this will not appear in our ir code
    type 14: PARAM tk1                  // tk1 must be a variable name
    type 15: ARG tk1                    // tk1 could be a constant or a variable
    type 16: tk1 := CALL tk2            // tk1 must be a variable, tk2 must be a function name (label in mips)
    type 17: READ tk1                   // tk1 must be a variable
    type 18: WRITE tk1                  // tk1 could be a constant or a variable
    // format of constant: #number (that is, a number with a # in front of it)
    // pay attention that in mips, the format of constants is different from that in ir code
    // format of constant in mips: number (that is, a number without a # in front of it)
    */
    /*
    relop 0: <
    relop 1: <=
    relop 2: >
    relop 3: >=
    relop 4: !=
    relop 5: ==
    */
    printf("start translating ir code: %d\n", code->type);
    fflush(stdout);
    Mips *mips_code = NULL;
    if(code->type == 0){
        mips_code = link_Mips(mips_code, gen_mips("LABEL", code->tk1, NULL, NULL));
        if(check_label_tag(code->tk1) == 1){
            mips_code = link_Mips(mips_code, update_all_regs());
        }
    }
    else if(code->type == 1){
        mips_code = link_Mips(mips_code, gen_mips("FUNCTION", code->tk1, NULL, NULL));
        mips_code = link_Mips(mips_code, update_all_regs());
        if(strcmp(code->tk1, "main") == 0){
            arg_cnt = -1; // main function definitely has no arguments
        }
        else{
            arg_cnt = 0;
            mips_code = link_Mips(mips_code, gen_mips("addi", "$sp", "$sp", "-4"));
            mips_code = link_Mips(mips_code, gen_mips("sw", "$ra", "0($sp)", NULL));
        }
    }
    else if(code->type == 2){
        if(code->tk2[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, gen_mips("li", int_to_reg(tmp1.reg), code->tk2+1, NULL));
        }
        else{
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            mips_code = link_Mips(mips_code, gen_mips("move", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), NULL));
        }
    }
    else if(code->type == 3){
        if(code->tk2[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp3 = get_mips_reg(code->tk3);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp3.code);
            mips_code = link_Mips(mips_code, gen_mips("addi", int_to_reg(tmp1.reg), int_to_reg(tmp3.reg), code->tk2+1));
        }
        else if(code->tk3[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            mips_code = link_Mips(mips_code, gen_mips("addi", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), code->tk3+1));
        }
        else{
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            ret_struct tmp3 = get_mips_reg(code->tk3);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            mips_code = link_Mips(mips_code, tmp3.code);
            mips_code = link_Mips(mips_code, gen_mips("add", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), int_to_reg(tmp3.reg)));
        }
    }
    else if(code->type == 4){
        if(code->tk2[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp3 = get_mips_reg(code->tk3);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp3.code);
            char* tmp_const = (char*)malloc(sizeof(char)*30);
            sprintf(tmp_const, "%d", -atoi(code->tk2+1));
            mips_code = link_Mips(mips_code, gen_mips("addi", int_to_reg(tmp1.reg), int_to_reg(tmp3.reg), tmp_const));
        }
        else if(code->tk3[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            char* tmp_const = (char*)malloc(sizeof(char)*30);
            sprintf(tmp_const, "%d", -atoi(code->tk3+1));
            mips_code = link_Mips(mips_code, gen_mips("addi", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), tmp_const));
        }
        else{
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            ret_struct tmp3 = get_mips_reg(code->tk3);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            mips_code = link_Mips(mips_code, tmp3.code);
            mips_code = link_Mips(mips_code, gen_mips("sub", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), int_to_reg(tmp3.reg)));
        }
    }
    else if(code->type == 5){
        if(code->tk2[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp3 = get_mips_reg(code->tk3);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp3.code);
            char* tmp_const = (char*)malloc(sizeof(char)*30);
            sprintf(tmp_const, "%d", atoi(code->tk2+1));
            mips_code = link_Mips(mips_code, gen_mips("mul", int_to_reg(tmp1.reg), int_to_reg(tmp3.reg), tmp_const));
        }
        else if(code->tk3[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            char* tmp_const = (char*)malloc(sizeof(char)*30);
            sprintf(tmp_const, "%d", atoi(code->tk3+1));
            mips_code = link_Mips(mips_code, gen_mips("mul", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), tmp_const));
        }
        else{
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            ret_struct tmp3 = get_mips_reg(code->tk3);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            mips_code = link_Mips(mips_code, tmp3.code);
            mips_code = link_Mips(mips_code, gen_mips("mul", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), int_to_reg(tmp3.reg)));
        }
    }
    else if(code->type == 6){
        if(code->tk2[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp3 = get_mips_reg(code->tk3);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp3.code);
            char* tmp_const = (char*)malloc(sizeof(char)*30);
            sprintf(tmp_const, "%d", atoi(code->tk2+1));
            mips_code = link_Mips(mips_code, gen_mips("div", int_to_reg(tmp1.reg), int_to_reg(tmp3.reg), tmp_const));
        }
        else if(code->tk3[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            char* tmp_const = (char*)malloc(sizeof(char)*30);
            sprintf(tmp_const, "%d", atoi(code->tk3+1));
            mips_code = link_Mips(mips_code, gen_mips("div", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), tmp_const));
        }
        else{
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            ret_struct tmp3 = get_mips_reg(code->tk3);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            mips_code = link_Mips(mips_code, tmp3.code);
            mips_code = link_Mips(mips_code, gen_mips("div", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), int_to_reg(tmp3.reg)));
        }
    }
    else if(code->type == 10){
        mips_code = link_Mips(mips_code, gen_mips("j", code->tk1, NULL, NULL));
    }
    else if(code->type == 11){
        mips_code = link_Mips(mips_code, update_all_regs());
        change_label_tag(code->tk3);
        if(code->tk1[0] == '#'){
            if(code->tk2[0] == '#'){
                mips_code = link_Mips(mips_code, gen_mips("li", "$a0", code->tk1+1, NULL));
                mips_code = link_Mips(mips_code, gen_mips("li", "$a1", code->tk2+1, NULL));
                if(code->relop == 0){
                    mips_code = link_Mips(mips_code, gen_mips("blt", "$a0", "$a1", code->tk3));
                }
                else if(code->relop == 1){
                    mips_code = link_Mips(mips_code, gen_mips("ble", "$a0", "$a1", code->tk3));
                }
                else if(code->relop == 2){
                    mips_code = link_Mips(mips_code, gen_mips("bgt", "$a0", "$a1", code->tk3));
                }
                else if(code->relop == 3){
                    mips_code = link_Mips(mips_code, gen_mips("bge", "$a0", "$a1", code->tk3));
                }
                else if(code->relop == 4){
                    mips_code = link_Mips(mips_code, gen_mips("bne", "$a0", "$a1", code->tk3));
                }
                else if(code->relop == 5){
                    mips_code = link_Mips(mips_code, gen_mips("beq", "$a0", "$a1", code->tk3));
                }
            }
            else{
                ret_struct tmp2 = get_mips_reg(code->tk2);
                mips_code = link_Mips(mips_code, tmp2.code);
                mips_code = link_Mips(mips_code, gen_mips("li", "$a0", code->tk1+1, NULL));
                if(code->relop == 0){
                    mips_code = link_Mips(mips_code, gen_mips("blt", "$a0", int_to_reg(tmp2.reg), code->tk3));
                }
                else if(code->relop == 1){
                    mips_code = link_Mips(mips_code, gen_mips("ble", "$a0", int_to_reg(tmp2.reg), code->tk3));
                }
                else if(code->relop == 2){
                    mips_code = link_Mips(mips_code, gen_mips("bgt", "$a0", int_to_reg(tmp2.reg), code->tk3));
                }
                else if(code->relop == 3){
                    mips_code = link_Mips(mips_code, gen_mips("bge", "$a0", int_to_reg(tmp2.reg), code->tk3));
                }
                else if(code->relop == 4){
                    mips_code = link_Mips(mips_code, gen_mips("bne", "$a0", int_to_reg(tmp2.reg), code->tk3));
                }
                else if(code->relop == 5){
                    mips_code = link_Mips(mips_code, gen_mips("beq", "$a0", int_to_reg(tmp2.reg), code->tk3));
                }
            }
        }
        else if(code->tk2[0] == '#'){
            ret_struct tmp1 = get_mips_reg(code->tk1);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, gen_mips("li", "$a1", code->tk2+1, NULL));
            if(code->relop == 0){
                mips_code = link_Mips(mips_code, gen_mips("blt", int_to_reg(tmp1.reg), "$a1", code->tk3));
            }
            else if(code->relop == 1){
                mips_code = link_Mips(mips_code, gen_mips("ble", int_to_reg(tmp1.reg), "$a1", code->tk3));
            }
            else if(code->relop == 2){
                mips_code = link_Mips(mips_code, gen_mips("bgt", int_to_reg(tmp1.reg), "$a1", code->tk3));
            }
            else if(code->relop == 3){
                mips_code = link_Mips(mips_code, gen_mips("bge", int_to_reg(tmp1.reg), "$a1", code->tk3));
            }
            else if(code->relop == 4){
                mips_code = link_Mips(mips_code, gen_mips("bne", int_to_reg(tmp1.reg), "$a1", code->tk3));
            }
            else if(code->relop == 5){
                mips_code = link_Mips(mips_code, gen_mips("beq", int_to_reg(tmp1.reg), "$a1", code->tk3));
            }
        }
        else{
            ret_struct tmp1 = get_mips_reg(code->tk1);
            ret_struct tmp2 = get_mips_reg(code->tk2);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, tmp2.code);
            if(code->relop == 0){
                mips_code = link_Mips(mips_code, gen_mips("blt", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), code->tk3));
            }
            else if(code->relop == 1){
                mips_code = link_Mips(mips_code, gen_mips("ble", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), code->tk3));
            }
            else if(code->relop == 2){
                mips_code = link_Mips(mips_code, gen_mips("bgt", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), code->tk3));
            }
            else if(code->relop == 3){
                mips_code = link_Mips(mips_code, gen_mips("bge", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), code->tk3));
            }
            else if(code->relop == 4){
                mips_code = link_Mips(mips_code, gen_mips("bne", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), code->tk3));
            }
            else if(code->relop == 5){
                mips_code = link_Mips(mips_code, gen_mips("beq", int_to_reg(tmp1.reg), int_to_reg(tmp2.reg), code->tk3));
            }
        }
    }
    else if(code->type == 12){
        if(arg_cnt == -1){
            mips_code = link_Mips(mips_code, gen_mips("li", "$v0", "10", NULL));
            mips_code = link_Mips(mips_code, gen_mips("syscall", NULL, NULL, NULL));
        }
        else{
            if(code->tk1[0] == '#'){
                mips_code = link_Mips(mips_code, gen_mips("li", "$v0", code->tk1+1, NULL));
            }
            else{
                ret_struct tmp1 = get_mips_reg(code->tk1);
                mips_code = link_Mips(mips_code, tmp1.code);
                mips_code = link_Mips(mips_code, gen_mips("move", "$v0", int_to_reg(tmp1.reg), NULL));
            }
            char* tmp = (char*)malloc(sizeof(char)*30);
            sprintf(tmp, "%d", (arg_cnt+1)*4);
            mips_code = link_Mips(mips_code, gen_mips("lw", "$ra", "0($sp)", NULL));
            mips_code = link_Mips(mips_code, gen_mips("addi", "$sp", "$sp", tmp));
            mips_code = link_Mips(mips_code, gen_mips("jr", "$ra", NULL, NULL));
        }
    }
    else if(code->type == 14){
        arg_cnt++;
        ret_struct tmp1 = get_mips_reg(code->tk1);
        mips_code = link_Mips(mips_code, tmp1.code);
        mips_code = link_Mips(mips_code, gen_mips("lw", int_to_reg(tmp1.reg), add_offset_to_reg(29, arg_cnt*4), NULL));
    }
    else if(code->type == 15){
        if(code->tk1[0] == '#'){
            mips_code = link_Mips(mips_code, gen_mips("li", "$a0", code->tk1+1, NULL));
        }
        else{
            ret_struct tmp1 = get_mips_reg(code->tk1);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, gen_mips("move", "$a0", int_to_reg(tmp1.reg), NULL));
        }
        mips_code = link_Mips(mips_code, gen_mips("addi", "$sp", "$sp", "-4"));
        mips_code = link_Mips(mips_code, gen_mips("sw", "$a0", "0($sp)", NULL));
    }
    else if(code->type == 16){
        mips_code = link_Mips(mips_code, gen_mips("jal", code->tk2, NULL, NULL));
        ret_struct tmp1 = get_mips_reg(code->tk1);
        mips_code = link_Mips(mips_code, tmp1.code);
        printf("tmp1.reg is %d, it's name is %s\n", tmp1.reg, code->tk1);
        fflush(stdout);
        mips_code = link_Mips(mips_code, gen_mips("move", int_to_reg(tmp1.reg), "$v0", NULL));
    }
    else if(code->type == 17){
        ret_struct tmp1 = get_mips_reg(code->tk1);
        mips_code = link_Mips(mips_code, tmp1.code);
        mips_code = link_Mips(mips_code, gen_mips("li", "$v0", "5", NULL));
        mips_code = link_Mips(mips_code, gen_mips("syscall", NULL, NULL, NULL));
        mips_code = link_Mips(mips_code, gen_mips("move", int_to_reg(tmp1.reg), "$v0", NULL));
    }
    else if(code->type == 18){
        if(code->tk1[0] == '#'){
            mips_code = link_Mips(mips_code, gen_mips("li", "$a0", code->tk1+1, NULL));
        }
        else{
            ret_struct tmp1 = get_mips_reg(code->tk1);
            mips_code = link_Mips(mips_code, tmp1.code);
            mips_code = link_Mips(mips_code, gen_mips("move", "$a0", int_to_reg(tmp1.reg), NULL));
        }
        mips_code = link_Mips(mips_code, gen_mips("li", "$v0", "1", NULL));
        mips_code = link_Mips(mips_code, gen_mips("syscall", NULL, NULL, NULL));
    }
    else{
        printf("Error: unknown type of ir code\n");
        fflush(stdout);
    }
    return mips_code;
}

void dump_mips(Mips *head, char* preamble, char* filename){
    Mips *tmp = head;
    FILE *fp = fopen(filename, "w");
    if(preamble != NULL){
        fprintf(fp, "%s\n", preamble);
    }
    while(tmp != NULL){
        fflush(stdout);
        if(tmp->tk_d == NULL){
            fprintf(fp, "        %s\n", tmp->op);
        }
        else if(tmp->tk_s == NULL){
            if(strcmp(tmp->op, "LABEL") == 0 || strcmp(tmp->op, "FUNCTION") == 0){
                fprintf(fp, "    %s:\n", tmp->tk_d);
            }
            else{
                fprintf(fp, "        %s %s\n", tmp->op, tmp->tk_d);
            }
        }
        else if(tmp->tk_t == NULL){
            fprintf(fp, "        %s %s, %s\n", tmp->op, tmp->tk_d, tmp->tk_s);
        }
        else{
            fprintf(fp, "        %s %s, %s, %s\n", tmp->op, tmp->tk_d, tmp->tk_s, tmp->tk_t);
        }
        tmp = tmp->next;
    }
    fclose(fp);
}

void print_end_code(Mips* mips_code){
    if(mips_code == NULL)return;
    while(mips_code->next != NULL){
        mips_code = mips_code->next;
    }
    printf("now_code_head is: %s, %s, %s, %s\n", mips_code->op, mips_code->tk_d, mips_code->tk_s, mips_code->tk_t);
    fflush(stdout);
}

void translate_mips(Code* ir_code, char* filename){
    char* preamble = init(ir_code);
    // printf("Start translating to mips...\n");
    // fflush(stdout);
    Mips *mips_code = NULL;
    Code *tmp = ir_code;
    // printf("tag111\n");
    // fflush(stdout);
    while(tmp != NULL){
        printf("translating ir: %d, %s, %s, %s\n", tmp->type, tmp->tk1, tmp->tk2, tmp->tk3);
        fflush(stdout);
        mips_code = link_Mips(mips_code, code_2_mips(tmp));
        print_end_code(mips_code);
        tmp = tmp->next;
    }
    // mips_code = link_Mips(mips_code, gen_mips("li", "$v0", "10", NULL));
    // mips_code = link_Mips(mips_code, gen_mips("syscall", NULL, NULL, NULL));
    // printf("start to dump codes\n");
    // fflush(stdout);
    dump_mips(mips_code, preamble, filename);
    // printf("finish dump codes\n");
    // fflush(stdout);
}