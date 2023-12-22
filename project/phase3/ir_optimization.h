#include "ir_translate.h"

#ifndef __IR_OPTIMIZATION__
#define __IR_OPTIMIZATION__

struct Code* const_simplif_1(struct Code* code);
struct Code* const_simplif_2(struct Code* code);
struct Code* replace_rval(struct Code* code, char* old, char* new);

struct Code* optimize(struct Code* code);

#endif // !__IR_OPTIMIZATION__