#ifndef MIPS_H
#define MIPS_H

#include<assert.h>
#include<ctype.h>
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mips32.h"
#include "tac.h"

struct Regs{
    char* name;
    int incash;
    struct VarDesc var;
}regs[1145];


Register get_reg(char *reg_name);


#endif // MIPS_H