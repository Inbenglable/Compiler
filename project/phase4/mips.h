#ifndef MIPS_H
#define MIPS_H

#include<assert.h>
#include<ctype.h>
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Var{
    char* name;
    int incash;
    int reg;
} Var;
Var vars[1145];

typedef struct Reg{
    int reg;
    int var_id;
    int visited;
    int preserved; //preserved==1 -> cannot be used by variables
    //preserved registers: 0, 1, 2, 3, 26, 27, 28, 29, 30, 31
} Reg;
Reg regs[32];

typedef struct Mips{
    char* op;
    char* tk_d;
    char* tk_s;
    char* tk_t;
    struct Mips* next;
    struct Mips* prev;
} Mips;

typedef struct ret_struct{
    int reg;
    struct Mips* code;
} ret_struct;

ret_struct get_reg(char *var_name);


#endif // MIPS_H