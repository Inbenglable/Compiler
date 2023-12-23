#include "ir_translate.h"

#ifndef __IR_OPTIMIZATION__
#define __IR_OPTIMIZATION__


struct block{
    int next;
    int if_next;
    struct Code* front;
    struct Code* end;
    struct Reg_list* regs;
};

struct Export{
    struct Export* next;
    int type;
    int relop;
    int arg;
    /*
        type 1. var
        type 2. write
        type 3. arg
        type 4. if

        relop 10: <
        relop 11: <=
        relop 12: >
        relop 13: >=
        relop 14: !=
        relop 15: ==
    */
}

struct Reg_list{
    struct Reg* reg;
    struct Reg_list* next;
}

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
        1. +
        2. -
        3. *
        4. /
        5. fun
        6. read
    */
   char* fun_name;
}



struct Reg{
    char* name;
    struct Dnode* active_in;
    int is_var;
}

struct Code* optimize(struct Code* code);



#endif // !__IR_OPTIMIZATION__