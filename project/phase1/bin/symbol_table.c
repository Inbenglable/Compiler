#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"


ScopeStack *top;
Treap *symbol_treap, *type_treap, *fun_treap;


void init_symbol_table(){
    top = (ScopeStack*)malloc(sizeof(ScopeStack));
    top->next = NULL;
    top->scope = 0;
    top->link_start = NULL;
}

void clear_symbol_table(){
    clear_treap(symbol_treap);
    clear_treap(type_treap);
    clear_treap(fun_treap);
    while(top != NULL){
        ScopeStack* tmp = top;
        top = top->next;
        free(tmp);
    }
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

int store_ID(char* ID, Var* varptr){
    Treap* node = find(ID, symbol_treap);
    if(node == NULL){
        node = new_node(ID);
        Treap* l, *r;
        split(symbol_treap, ID, l, r);
        symbol_treap = merge(merge(l, node), r);
    }
    else if(node->link->scope == top->scope){
        return 0;
    }
    IntermediateLink* new_link = (IntermediateLink*)malloc(sizeof(IntermediateLink));
    new_link->next_scope = node->link;
    new_link->next_ID = top->link_start;
    new_link->from = node;
    new_link->scope = top->scope;
    new_link->varptr = varptr;
    top->link_start = new_link;
    node->link = new_link;
    return 1;
}

Var* query_ID(char* ID){
    Treap* node = find(ID, symbol_treap);
    if(node == NULL){
        return NULL;
    }
    return node->link->varptr;
}

int store_Type(char* ID, Type* typeptr){
    Treap* node = find(ID, type_treap);
    if(node == NULL){
        node = new_node(ID);
        Treap* l, *r;
        split(type_treap, ID, l, r);
        type_treap = merge(merge(l, node), r);
    }
    else if(node->link->scope == top->scope){
        return 0;
    }
    IntermediateLink* new_link = (IntermediateLink*)malloc(sizeof(IntermediateLink));
    new_link->next_scope = node->link;
    new_link->next_ID = top->link_start;
    new_link->from = node;
    new_link->scope = top->scope;
    new_link->typeptr = typeptr;
    top->link_start = new_link;
    node->link = new_link;
    return 1;
}

Type* query_Type(char* ID){
    Treap* node = find(ID, type_treap);
    if(node == NULL){
        return NULL;
    }
    return node->link->typeptr;
}

int store_Fun(char* ID, Var* varptr){
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
        return 1;
    }
    else{
        return 0;
    }
}

Var* query_Fun(char* ID){
    Treap* node = find(ID, fun_treap);
    if(node == NULL){
        return NULL;
    }
    return node->link->varptr;
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
            if(children_hash[i] == 0){
                children_hash[i] = tmp->type->hash = get_hash(tmp->type);
            }
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

void clear_treap(Treap* node){
    if(node == NULL){
        return;
    }
    clear_treap(node->lson);
    clear_treap(node->rson);
    clear_intermediate(node->link);
    free(node);
}

void clear_intermediate(IntermediateLink* link){
    if(link == NULL){
        return;
    }
    clear_Type(link->typeptr);
    clear_Var(link->varptr);
    clear_intermediate(link->next_scope);
    free(link);
}

void clear_Type(Type* typeptr){
    if(typeptr == NULL){
        return;
    }
    clear_Var(typeptr->contain);
    free(typeptr);
}

void clear_Var(Var* varptr){
    if(varptr == NULL){
        return;
    }
    clear_Var(varptr->next);
    clear_Type(varptr->type);
    free(varptr);
}


// wdh: 下面就是我瞎写的判等的部分了，还没在.h里面声明，上面没动（（

int check_int(nodePointer p){
    struct Type*
}