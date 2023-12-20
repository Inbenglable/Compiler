#include "structure.h"

#ifndef __IR_TRANSLATE__
#define __IR_TRANSLATE__

typedef struct Code Code;
typedef struct ArgList ArgList;

struct Code{
    struct Code* from;
    int type;
    /*
    type 0: LABEL tk1 :
    type 1: FUNCTION tk1 :
    type 2: tk1 := tk2
    type 3: tk1 := tk2 + tk3
    type 4: tk1 := tk2 - tk3
    type 5: tk1 := tk2 * tk3
    type 6: tk1 := tk2 / tk3
    type 7: tk1 := &tk2
    type 8: tk1 := *tk2
    type 9: *tk1 := tk2
    type 10: GOTO tk1
    type 11: IF tk1 relop tk2 GOTO tk3
    type 12: RETURN tk1
    type 13: DEC tk1 size
    type 14: PARAM tk1
    type 15: ARG tk1
    type 16: tk1 := CALL tk2
    type 17: READ tk1
    type 18: WRITE tk1
    */
    char* tk1;
    int relop;
    /*
    relop 0: <
    relop 1: <=
    relop 2: >
    relop 3: >=
    relop 4: !=
    relop 5: ==
    */
    char* tk2;
    char* tk3;
    int is_const;
    int value;
    int is_tmp;
    struct Code* next;
};

struct ArgList{
    char* name;
    struct ArgList* next;
};

extern int label_count, tmp_count;

char* to_literal(int val);
char* to_size(int val);
char* to_var(char* name);
char* new_label_name();
char* new_tmp_name();
struct Code* construct(int type, char* tk1, int relop, char* tk2, char* tk3);
struct Code* append(struct Code* code1_head, struct Code* code1_tail, struct Code* code2_head, struct Code* code2_tail);
struct Code* append_wo_tail(struct Code* code1, struct Code* code2);
void dump(struct Code* head, char* filename);
struct Code* translate_exp(struct Node* node, char* place);
struct Code* translate_cond(struct Node* node, char* label_true, char* label_false);
struct Code* translate_stmt(struct Node* node);
struct Code* translate_args(struct Node* node, struct ArgList** arg_list);
struct Code* translate_fundec(struct Node* node);
struct Code* translate_other(struct Node* node);
void translate(struct Node* node, char* filename);

/////////////////
int char_to_int(const char* str);
int var_to_int(const char* str);
int start_with_well(const char* str);
struct Code* get_tail(struct Code* code);
void connect_code_to_node(nodePointer node, struct Code* code);

#endif // !__IR_TRANSLATE__