#include "ir_translate.h"

#ifndef __IR_OPTIMIZATION__
#define __IR_OPTIMIZATION__

extern struct Code* head;
extern struct Code* tail;

void merge_label();
void remove_continuous_jump();
void replace_label(char* old, char* new);
void remove_unused_lval();
int check_use_in_code(struct Code* code, char* name);
int check_use(struct Code* code, char* name);
void const_simplif_1();
void const_simplif_2();
void replace_rval(char* old, char* new);

void delet(struct Code* code);

struct Code* optimize(struct Code* code);

#endif // !__IR_OPTIMIZATION__