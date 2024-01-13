#ifndef __MIPS__
#define __MIPS__

#include "ir_translate.h"

typedef struct Mips_Var{
    char* name;
    int incash;
    int reg;
} Mips_Var;
extern Mips_Var vars[1145];
extern int var_cnt;

typedef struct Reg{
    int reg;
    int var_id;
    int visited;
    int preserved; //preserved==1 -> cannot be used by variables
    //preserved registers: 0, 1, 2, 3, 4, 5, 6, 7, 26, 27, 28, 29, 30, 31
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

typedef struct lable_name{
    char* name;
    int tag;
} lable_name;

extern int lable_cnt;
extern lable_name lables[1145];

extern int reg_used_cnt;
ret_struct get_reg(char *var_name);

char* init(Code *head);

Mips* link_Mips(Mips *code1, Mips *code2);
Mips* gen_mips(char* op, char* tk_d, char* tk_s, char* tk_t);
char* int_to_reg(int reg);

void translate_mips(Code* ir_code, char* filename);
#endif // __MIPS__