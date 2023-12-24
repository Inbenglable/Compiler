#include "ir_translate.h"

#ifndef __IR_OPTIMIZATION__
#define __IR_OPTIMIZATION__

extern int block_cnt;
extern int node_cnt;
extern int code_cnt;


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
} ;


struct Export{
    struct Export* next;
    int type;
    int relop;
    int k;
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
    int k;
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
};


struct Reg{
    char* name;
    struct Dnode* active_in;
    int is_var;
    int last_k;
};
extern struct Block block[114514];
extern struct Dnode* node_list[114514];
struct Code* optimize(struct Code* code);

void finish_gen_block(int id, struct Code* tail);
void generate_block(int id, struct Code* head);
void inital_block(int id);
int check_var(char* name);
struct Reg* generate_reg(char* name, struct Dnode* active_in, int is_var);
struct Reg* get_reg(char* name, int id);
void assign_reg(struct Reg* reg1, struct Reg* reg2);
int check_export_avail(struct Export* a, int id);
int check_bigger(struct Dnode* a, struct Dnode* b);
int check_bigger_insert(struct Export* a, struct Export* b, int id);
void insert_export(struct Dnode* node, struct Export* export, int id);
struct Dnode* find_same(struct Reg* reg, struct Dnode* tk2, struct Dnode* tk3, int operator);
struct Dnode* delet_dnode(struct Dnode* node);
struct Dnode* get_biggest(int id);
void assign_export(int id);
void reduce_useless(struct Dnode* node);
struct Code* solve(struct Dnode* node, int id);
void print_node_list();
char *get_token_name(struct Dnode* node);
int change_to_const(struct Dnode* node);
void complete_block(int id);
#endif // !__IR_OPTIMIZATION__