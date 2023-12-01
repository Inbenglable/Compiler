#include "structure.h"

#ifndef __SYMBOL_TABLE__
#define __SYMBOL_TABLE__

typedef struct ScopeStack ScopeStack;
typedef struct IntermediateLink IntermediateLink;
typedef struct Treap Treap;


struct ScopeStack{
    struct ScopeStack* next;
    int scope;
    struct IntermediateLink* link_start;
};

struct IntermediateLink{
    struct IntermediateLink* next_scope;
    struct IntermediateLink* next_ID;
    struct Treap* from;
    int scope;
    struct Var* varptr;
    struct Type* typeptr;
};

struct Treap{
    struct Treap* lson;
    struct Treap* rson;
    int key;
    char* val;
    struct IntermediateLink* link;
};


extern struct ScopeStack *top;
extern struct Treap *symbol_treap, *type_treap, *fun_treap;

//store_ID(ID, varptr): insert an ID and its corresponding Var* into the symbol table
//new_scope(): enter a new scope, ID defined in the new scope will cover those in old scope
//pop_scope(): pop the symbol_top scope, as well as its IDs
//query_ID(ID): return the Var* of a certain ID
//store_Type(ID, typeptr): insert an Type and its corresponding Type* into the type table
//query_Type(ID): return the Type* of a certain Type
//store_Fun(ID, varptr): insert an ID of a function and its corresponding Var* into the function table
//query_Fun(ID): return the Var* of a certain function
//get_hash(typeptr): return the hash value of a certain Type
//When using symbol table, please run init_symbol_table() before start,
//and run clear_symbol_table() before exit
void init_symbol_table();
void clear_symbol_table();
void new_scope();
void pop_scope();
int store_ID(char* ID, struct Var* varptr);
struct Var* query_ID(char* ID);
int store_Type(char* ID, struct Type* typeptr);
struct Type* query_Type(char* ID);
int store_Fun(char* ID, struct Var* varptr);
struct Var* query_Fun(char* ID);
unsigned long long get_hash(struct Type* typeptr);


struct Treap* new_node(char* val);
struct Treap* merge(struct Treap* lnode, struct Treap* rnode);
void split(struct Treap* node, char* v, struct Treap* l, struct Treap* r);
struct Treap* find(char* v, struct Treap* node);
void clear_treap(struct Treap* node);
void clear_intermediate(struct IntermediateLink* link);
void clear_Type(struct Type* typeptr);
void clear_Var(struct Var* varptr);

#endif // !__SYMBOL_TABLE__