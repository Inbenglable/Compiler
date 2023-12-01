//store_ID(ID, varptr): insert an ID and its corresponding Var* into the symbol table
//new_scope(): enter a new scope, ID defined in the new scope will cover those in old scope
//pop_scope(): pop the symbol_top scope, as well as its IDs
//query_ID(ID): return the Var* of a certain ID
//store_Type(ID, typeptr): insert an Type and its corresponding Type* into the type table
//query_Type(ID): return the Type* of a certain Type
//store_Fun(ID, varptr): insert an ID of a function and its corresponding Var* into the function table
//query_Fun(ID): return the Var* of a certain function
//get_hash(typeptr): return the hash value of a certain Type


#include <string.h>
#include <stdlib.h>
#include <structure.h>


void init_symbol_table(){
    top = (ScopeStack*)malloc(sizeof(ScopeStack));
    top->next = NULL;
    top->scope = 0;
    top->link_start = NULL;
}

void new_scope(){
    ScopeStack* new_node = (ScopeStack*)malloc(sizeof(ScopeStack));
    new_node->next = top;
    new_node->scope = top->scope + 1;
    new_node->link_start = NULL;
    top = new_node;
}

void pop_scope(){
    IntermediateLink* l1 = top->link_start;
    while(l1!=NULL){
        l1->from->link = l1->next_scope;
        IntermediateLink* tmp = l1;
        l1 = l1->next_ID;
        free(tmp);
    }
    ScopeStack* tmp = top;
    top = top->next;
    free(tmp);
}

bool store_ID(char* ID, Var* varptr){
    Treap* node = find(ID, symbol_treap);
    if(node == NULL){
        node = new_node(ID);
        Treap* l, *r;
        split(symbol_treap, ID, l, r);
        symbol_treap = merge(merge(l, node), r);
    }
    else if(node->link->scope == top->scope){
        return false;
    }
    IntermediateLink* new_link = (IntermediateLink*)malloc(sizeof(IntermediateLink));
    new_link->next_scope = node->link;
    new_link->next_ID = top->link_start;
    new_link->from = node;
    new_link->scope = top->scope;
    new_link->varptr = varptr;
    top->link_start = new_link;
    node->link = new_link;
    return true;
}

Var* query_ID(char* ID){
    Treap* node = find(ID, symbol_treap);
    if(node == NULL){
        return NULL;
    }
    return node->link->varptr;
}

bool store_Type(char* ID, Type* typeptr){
    Treap* node = find(ID, type_treap);
    if(node == NULL){
        node = new_node(ID);
        Treap* l, *r;
        split(type_treap, ID, l, r);
        type_treap = merge(merge(l, node), r);
    }
    else if(node->link->scope == top->scope){
        return false;
    }
    IntermediateLink* new_link = (IntermediateLink*)malloc(sizeof(IntermediateLink));
    new_link->next_scope = node->link;
    new_link->next_ID = top->link_start;
    new_link->from = node;
    new_link->scope = top->scope;
    new_link->typeptr = typeptr;
    top->link_start = new_link;
    node->link = new_link;
    return true;
}

Type* query_Type(char* ID){
    Treap* node = find(ID, type_treap);
    if(node == NULL){
        return NULL;
    }
    return node->link->typeptr;
}

bool store_Fun(char* ID, Var* varptr){
    Treap* node = find(ID, fun_treap);
    if(node == NULL){
        node = new_node(ID);
        Treap* l, *r;
        split(fun_treap, ID, l, r);
        fun_treap = merge(merge(l, node), r);
        IntermediateLink* new_link = (IntermediateLink*)malloc(sizeof(IntermediateLink));
        new_link->next_scope = NULL;
        new_link->next_ID = NULL;
        new_link->from = node;
        new_link->scope = top->scope;
        new_link->varptr = varptr;
        node->link = new_link;
        return true;
    }
    else{
        return false;
    }
}

Var* query_Fun(char* ID){
    Treap* node = find(ID, fun_treap);
    if(node == NULL){
        return NULL;
    }
    return node->link->varptr;
}

unsigned long long get_hash(Type* typeptr){
    unsigned long long base = 998244353, mod = 1610612741, hashval = 0;
    if(strcmp(typeptr->type_name, "int") == 0){
        hashval = 2;
    }
    else if(strcmp(typeptr->type_name, "char") == 0){
        hashval = 3;
    }
    else if(strcmp(typeptr->type_name, "float") == 0){
        hashval = 5;
    }
    else{
        Var* tmp = typeptr->contain;
        int length = 0;
        while(tmp != NULL){
            length ++;
            tmp = tmp->next;
        }
        unsigned long long* children_hash = (unsigned long long*)malloc(sizeof(unsigned long long) * length);
        tmp = typeptr->contain;
        for(int i = 0; i <= length; i ++){
            children_hash[i] = tmp->type->hash;
            int dim = tmp->dim;
            while(dim){
                unsigned long long tmpbase = base;
                if(dim & 1){
                    children_hash[i] = children_hash[i] * tmpbase % mod;
                }
                tmpbase *= tmpbase;
                dim >>= 1;
            }
            tmp = tmp->next; 
        }
        qsort(children_hash, length, sizeof(unsigned long long), cmp);
        for(int i = 0; i <= length; i ++){
            hashval = (hashval * base + children_hash[i]) % mod;
        }
        free(children_hash);
    }
    return hashval;
}

int cmp(const void* a, const void* b){
    unsigned long long A = *(unsigned long long*)a;
    unsigned long long B = *(unsigned long long*)b;
    if(A > B){
        return 1;
    }
    else if(A == B){
        return 0;
    }
    else{
        return -1;
    }
}

struct ScopeStack{
    ScopeStack* next;
    int scope;
    IntermediateLink* link_start;
}*top;

struct IntermediateLink{
    IntermediateLink* next_scope;
    IntermediateLink* next_ID;
    Treap* from;
    int scope;
    Var* varptr;
    Type* typeptr;
};

struct Treap{
    Treap* lson;
    Treap* rson;
    int key;
    char* val;
    IntermediateLink* link;
}*symbol_treap, *type_treap, *fun_treap;

Treap* new_node(char* val){
    Treap* node = (Treap*)malloc(sizeof(Treap));
    node->key = rand();
    node->val = val;
    node->link = NULL;
    return node;
}

Treap* merge(Treap* lnode, Treap* rnode){
    if(lnode == NULL){
        return rnode;
    }
    if(rnode == NULL){
        return lnode;
    }
    if(lnode->key >= rnode->key){
        rnode->lson = merge(lnode, rnode->lson);
        return rnode;
    }
    else{
        lnode->rson = merge(lnode->rson, rnode);
        return lnode;
    }
}

void split(Treap* node, char* v, Treap* l, Treap* r){
    if(node == NULL){
        l = r = NULL;
        return;
    }
    if(strcmp(node->val, v) < 0){
        l = node;
        split(node->rson, v, node->rson, r);
    }
    else{
        r = node;
        split(node->lson, v, l, node->lson);
    }
}

Treap* find(char* v, Treap* node){
    while(node != NULL){
        int cmp = strcmp(node->val, v);
        if(cmp == 0){
            return node;
        }
        else if(cmp < 0){
            node = node->rson;
        }
        else{
            node = node->lson;
        }
    }
    return NULL;
}