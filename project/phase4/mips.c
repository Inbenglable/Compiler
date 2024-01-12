#include "mips.h"

struct Ret_struct get_reg(char *reg){
    struct Ret_struct ret;
    ret = (struct Ret_struct)malloc(sizeof(struct Ret_struct));
    ret.tac = NULL;
    for(int i = 1;i <= num_reg;i++){
        if(strcmp(regs[i].name,reg) == 0){
            if(regs[i].incash == 1){
                ret.var = regs[i].var;
            }else{
                return 
            }
        }
    }
}