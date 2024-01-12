#ifndef MIPS_H
#define MIPS_H

#include "ir_translate.h"

typedef struct Var{
    char* name;
    int incash;
    int reg;
} Var;
extern Var vars[1145];
extern int var_cnt;

typedef struct Reg{
    int reg;
    int var_id;
    int visited;
    int preserved; //preserved==1 -> cannot be used by variables
    //preserved registers: 0, 1, 2, 3, 26, 27, 28, 29, 30, 31
} Reg;
extern Reg regs[32];

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

extern int reg_cnt;
ret_struct get_reg(char *var_name);

void init(Code *head);

char* getRemainingString(char *variable, char* prefix);    char *start
Mips link_Mips(Mips *code1, Mips *code2);
Mips gen_mips(char* op, char* tk_d, char* tk_s, char* tk_t);

#endif // MIPS_H