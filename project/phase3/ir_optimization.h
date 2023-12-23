#include "ir_translate.h"

#ifndef __IR_OPTIMIZATION__
#define __IR_OPTIMIZATION__
const int maxn = 114514;

struct Block{
    int next;
    int if_next;
    struct Code* front;
    struct Code* end;
    struct Code* recode;
    struct Reg_list* regs;
    int write_cnt;
    int arg_cnt;
    int node_cnt;
}block[maxn];

struct Export{
    struct Export* next;
    int type;
    int relop;
    int arg;
    /*
        type 1. var
        type 2. write
        type 3. arg
        type 4. return
        type 5. if

        relop 0: <
        relop 1: <=
        relop 2: >
        relop 3: >=
        relop 4: !=
        relop 5: ==
    */
};

struct Reg_list{
    struct Reg* reg;
    struct Reg_list* next;
};

struct Dnode{
    int in;
    int out;
    struct Export* export;
    struct Reg_list* reg_list;
    struct Dnode* tk2;
    struct Dnode* tk3;
    int isconst;
    int value;
    int operator;
    /*
        0. init
        1. +
        2. -
        3. *
        4. /
        5. fun
        6. read
        7. if
    */
   char* splc_name;
}*que[maxn], *node_list[maxn];

struct Reg{
    char* name;
    struct Dnode* active_in;
    int is_var;
};

struct Code* optimize(struct Code* code);


#endif // !__IR_OPTIMIZATION__