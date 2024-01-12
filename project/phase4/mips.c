#include <string.h>
#include "mips.h"

char* getRemainingString(char *variable, char* prefix) {
    char *start = strstr(variable, prefix);
    if (start != NULL) {
        return start + strlen(prefix);
    } else {
        return variable;
    }
}

int check_create_var(char* name){
    int i;
    for(i = 1; i <= var_cnt; i++){
        if(var[i].name == NULL){
            continue;
        }
        if(strcmp(vars[i].name, name) == 0){
            return 0;
        }
    }
    return 1;
}



int check_var(char* name){
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
        if(tmp->tk1 != NULL && check_var(tmp->tk1) == 1){
            vars[++var_cnt].name = tmp->tk1;
            vars[var_cnt].incash = 0;
            vars[var_cnt].reg = -1;
        }
        if(tmp->tk2 != NULL && check_var(tmp->tk2) == 1){
            vars[++var_cnt].name = tmp->tk2;
            vars[var_cnt].incash = 0;
            vars[var_cnt].reg = -1;
        }
        if(tmp->tk3 != NULL && check_var(tmp->tk3) == 1){
            vars[++var_cnt].name = tmp->tk3;
            vars[var_cnt].incash = 0;
            vars[var_cnt].reg = -1;
        }
    }
    int i;
    for(i = 0; i < 32; i++){
        regs[i].reg = i;
        regs[i].var_id = -1;
        regs[i].visited = 0;
        if(i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 31){
            regs[i].preserved = 1;
        }else{
            regs[i].preserved = 0;
        }
    }
    char* ret = NULL;
    if(var_cnt <= 25-8+1){
        for(int i = 1;i <= var_cnt;i++){
            vars[i].reg = i+8-1;
            regs[i+8-1].var_id = i;
        }
    }else{
        sprintf(ret, "reg_root: .space %d", var_cnt*4);
    }
    return ret;
}

Mips gen_mips(char* op, char* tk_d, char* tk_s, char* tk_t){
    Mips *mips = (Mips*)malloc(sizeof(Mips));
    mips->op = op;
    mips->tk_d = tk_d;
    mips->tk_s = tk_s;
    mips->tk_t = tk_t;
    mips->next = NULL;
    mips->prev = NULL;
    return mips;
}

Mips link_Mips(Mips *code1, Mips *code2){
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
        char* ret = (char*)malloc(sizeof(char)*5);
        sprintf(ret, "$t%d", reg-8);
        return ret;
    }else if(reg >= 16 && reg <= 23){
        char* ret = (char*)malloc(sizeof(char)*5);
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
    char* ret = NULL;
    if(offset == 0){
        ret = "reg_root";
    }else{
        sprintf(ret, "reg_root + %d", offset);
    }
    return ret;
}

Mips update_reg(int reg, int var_id){
    if(var_id == -1)return NULL;
    var[var_id].reg = -1;
    return gen_mips("sw", int_to_reg(reg), get_var_addr_str(var_id*4-4), NULL);
}

Mips load_var(int reg, int var_id){
    if(var_id == -1)return NULL;
    regs[reg].var_id = var_id;
    return gen_mips("lw", int_to_reg(reg), get_var_addr_str(var_id*4-4), NULL);
}

int get_unused_reg(){
    int ret = -1;
    int mi = 0x7fffffff;
    for(int i = 8;i <= 25;i++){
        if(regs[i].reg == -1){
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

ret_struct get_reg(char *var_name){
    ret_struct ret;

    for(int i = 1;i <= var_cnt){
        if(strcmp(vars[i].name, var_name) == 0){
            if(vars[i].reg != -1){
                ret.reg = vars[i].reg;
                ret.code = NULL;
                regs[ret.reg].visited = reg_used_cnt;
                return ret;
            }else{
                ret.reg = get_unused_reg();
                ret.code = link_Mips(ret.code, update_reg(ret.reg, regs[ret.reg].var_id));
                ret.code = link_Mips(ret.code, load_var(ret.reg, i));
                regs[ret.reg].visited = reg_used_cnt;
                return ret;
            }
        }
    }
    return ret;
}

///Radiance's part ends here
///FC_Viiiiictor_K's part is over here

Mips *code_2_mips(Code* code){
    /*
    type 0: LABEL tk1 :
    type 1: FUNCTION tk1 :
    type 2: tk1 := tk2
    type 3: tk1 := tk2 + tk3
    type 4: tk1 := tk2 - tk3
    type 5: tk1 := tk2 * tk3
    type 6: tk1 := tk2 / tk3
    type 7: tk1 := &tk2                 // this will not appear in our ir code
    type 8: tk1 := *tk2                 // this will not appear in our ir code
    type 9: *tk1 := tk2                 // this will not appear in our ir code
    type 10: GOTO tk1
    type 11: IF tk1 relop tk2 GOTO tk3
    type 12: RETURN tk1
    type 13: DEC tk1 size               // this will not appear in our ir code
    type 14: PARAM tk1
    type 15: ARG tk1
    type 16: tk1 := CALL tk2
    type 17: READ tk1
    type 18: WRITE tk1
    */
    /*
    relop 0: <
    relop 1: <=
    relop 2: >
    relop 3: >=
    relop 4: !=
    relop 5: ==
    */
    Mips *mips_code = NULL;
    if(code->type == 0){
        mips_code = link_Mips(mips_code, gen_mips("LABEL", code->tk1, NULL, NULL));
    }
    else if(code->type == 1){
        mips_code = link_Mips(mips_code, gen_mips("FUNCTION", code->tk1, NULL, NULL));
    }
    else if(code->type == 2){
        ret_struct reg_info1 = get_reg(code->tk1);
        ret_struct reg_info2 = get_reg(code->tk2);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, reg_info2.code);
        mips_code = link_Mips(mips_code, gen_mips("move", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), NULL));
    }
    else if(code->type == 3){
        ret_struct reg_info1 = get_reg(code->tk1);
        ret_struct reg_info2 = get_reg(code->tk2);
        ret_struct reg_info3 = get_reg(code->tk3);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, reg_info2.code);
        mips_code = link_Mips(mips_code, reg_info3.code);
        mips_code = link_Mips(mips_code, gen_mips("add", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), int_to_reg(reg_info3.reg)));
    }
    else if(code->type == 4){
        ret_struct reg_info1 = get_reg(code->tk1);
        ret_struct reg_info2 = get_reg(code->tk2);
        ret_struct reg_info3 = get_reg(code->tk3);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, reg_info2.code);
        mips_code = link_Mips(mips_code, reg_info3.code);
        mips_code = link_Mips(mips_code, gen_mips("sub", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), int_to_reg(reg_info3.reg)));
    }
    else if(code->type == 5){
        ret_struct reg_info1 = get_reg(code->tk1);
        ret_struct reg_info2 = get_reg(code->tk2);
        ret_struct reg_info3 = get_reg(code->tk3);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, reg_info2.code);
        mips_code = link_Mips(mips_code, reg_info3.code);
        mips_code = link_Mips(mips_code, gen_mips("mul", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), int_to_reg(reg_info3.reg)));
    }
    else if(code->type == 6){
        ret_struct reg_info1 = get_reg(code->tk1);
        ret_struct reg_info2 = get_reg(code->tk2);
        ret_struct reg_info3 = get_reg(code->tk3);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, reg_info2.code);
        mips_code = link_Mips(mips_code, reg_info3.code);
        mips_code = link_Mips(mips_code, gen_mips("div", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), int_to_reg(reg_info3.reg)));
    }
    else if(code->type == 10){
        mips_code = link_Mips(mips_code, gen_mips("j", code->tk1, NULL, NULL, 0, 0));
    }
    else if(code->type == 11){
        ret_struct reg_info1 = get_reg(code->tk1);
        ret_struct reg_info2 = get_reg(code->tk2);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, reg_info2.code);
        if(code->relop == 0){
            mips_code = link_Mips(mips_code, gen_mips("blt", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), code->tk3));
        }
        else if(code->relop == 1){
            mips_code = link_Mips(mips_code, gen_mips("ble", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), code->tk3));
        }
        else if(code->relop == 2){
            mips_code = link_Mips(mips_code, gen_mips("bgt", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), code->tk3));
        }
        else if(code->relop == 3){
            mips_code = link_Mips(mips_code, gen_mips("bge", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), code->tk3));
        }
        else if(code->relop == 4){
            mips_code = link_Mips(mips_code, gen_mips("bne", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), code->tk3));
        }
        else if(code->relop == 5){
            mips_code = link_Mips(mips_code, gen_mips("beq", int_to_reg(reg_info1.reg), int_to_reg(reg_info2.reg), code->tk3));
        }
    }
    else if(code->type == 12){
        ret_struct reg_info1 = get_reg(code->tk1);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, gen_mips("move", "$v0", int_to_reg(reg_info1.reg), NULL));
        mips_code = link_Mips(mips_code, gen_mips("jr", "$ra", NULL, NULL));
    }
    else if(code->type == 14){
        ret_struct reg_info1 = get_reg(code->tk1);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, gen_mips("move", int_to_reg(reg_info1.reg), "$a0", NULL));
    }
    else if(code->type == 15){
        ret_struct reg_info1 = get_reg(code->tk1);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, gen_mips("move", "$a0", int_to_reg(reg_info1.reg), NULL));
        mips_code = link_Mips(mips_code, gen_mips("addi", "$sp", "$sp", "-4"));
        mips_code = link_Mips(mips_code, gen_mips("sw", "$ra", "0($sp)", NULL));
        mips_code = link_Mips(mips_code, gen_mips("jal", code->tk1, NULL, NULL));
        mips_code = link_Mips(mips_code, gen_mips("lw", "$ra", "0($sp)", NULL));
        mips_code = link_Mips(mips_code, gen_mips("addi", "$sp", "$sp", "4"));
    }
    else if(code->type == 16){
        ret_struct reg_info1 = get_reg(code->tk1);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, gen_mips("move", "$v0", int_to_reg(reg_info1.reg), NULL));
    }
    else if(code->type == 17){
        ret_struct reg_info1 = get_reg(code->tk1);
        mips_code = link_Mips(mips_code, reg_info1.code);
        mips_code = link_Mips(mips_code, gen_mips("move", "$a0", int_to_reg(reg_info1.reg), NULL));
        mips_code = link_Mips(mips_code, gen_mips("addi", "$sp", "$sp", "-4"));
        mips_code = link_Mips(mips_code, gen_mips("sw", "$ra", "0($sp)", NULL));
    return mips_code;
}

void dump(Mips *head, char* preamble, char* filename){
    Mips *tmp = head;
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%s\n", preamble);
    while(tmp != NULL){
        fflush(stdout);
        if(tmp->tk_d == NULL){
            fprintf(fp, "%s\n", tmp->op);
        }
        else if(tmp->tk_s == NULL){
            if(strcmp(tmp->op, "LABEL") == 0 || strcmp(tmp->op, "FUNCTION") == 0){
                fprintf(fp, "%s:\n", tmp->tk_d);
            }
            else{
                fprintf(fp, "%s %s\n", tmp->op, tmp->tk_d);
            }
        }
        else if(tmp->tk_t == NULL){
            fprintf(fp, "%s %s, %s\n", tmp->op, tmp->tk_d, tmp->tk_s);
        }
        else{
            fprintf(fp, "%s %s, %s, %s\n", tmp->op, tmp->tk_d, tmp->tk_s, tmp->tk_t);
        }
        tmp = tmp->next;
    }
    fclose(fp);
}

void translate_mips(Code* ir_code, char* filename){
    char* preamble = init(ir_code);
    Mips *mips_code = NULL;
    Code *tmp = ir_code;
    while(tmp != NULL){
        mips_code = link_Mips(mips_code, code_2_mips(tmp));
        tmp = tmp->next;
    }
    dump(mips_code, preamble, filename);
}