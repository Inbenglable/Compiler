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

void init(Code *head){
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
        if(i == 0 || i == 1 || i == 2 || i == 3 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 31){
            regs[i].preserved = 1;
        }else{
            regs[i].preserved = 0;
        }
    }
}

Mips gen_mips(char* op, char* tk_d, char* tk_s, char* tk_t, int offset1, int offset2){
    Mips *mips = (Mips*)malloc(sizeof(Mips));
    mips->op = op;
    mips->tk_d = tk_d;
    mips->tk_s = tk_s;
    mips->tk_t = tk_t;
    mips->offset1 = offset1;
    mips->offset2 = offset2;
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

Mips update_reg(int reg, int var_id){
    var[var_id].reg = -1;
    return gen_mips("sw", int_to_reg(reg), "reg_root", NULL, var_id*4-4, 0);
}

Mips load_var(int reg, int var_id){
    regs[reg].var_id = var_id;
    return gen_mips("lw", int_to_reg(reg), "reg_root", NULL, var_id*4-4, 0);
}

ret_struct get_reg(char *var_name){
    ret_struct ret;

    for(int i = 1;i <= var_cnt){
        if(strcmp(vars[i].name, var_name) == 0){
            if(vars[i].reg != -1){
                ret.reg = vars[i].reg;
                ret.code = NULL;
                return ret;
            }else{
                ret.reg = get_reg();
                ret.code = link_Mips(ret.code, update_reg(ret.reg, regs[ret.reg].var_id));
                ret.code = link_Mips(ret.code, load_var(ret.reg, i));
            }
        }
    }
}

///Radiance's part ends here
///Fc_Viiiiictor_K's part is over here