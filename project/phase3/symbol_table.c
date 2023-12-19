#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"


ScopeStack *top;
Treap *symbol_treap, *type_treap, *fun_treap;

int disable_new_scope = 1;


void init_symbol_table(){
    top = (ScopeStack*)malloc(sizeof(ScopeStack));
    top->next = NULL;
    top->scope = 0;
    top->link_start = NULL;
    symbol_treap = NULL;
    type_treap = NULL;
    fun_treap = NULL;
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

void disable_scope(){
    disable_new_scope = 1;
}

void new_scope(){
    ////printf("new scope\n");
    if(disable_new_scope){
        return;
    }
    ScopeStack* new_node = (ScopeStack*)malloc(sizeof(ScopeStack));
    new_node->next = top;
    new_node->scope = top->scope + 1;
    new_node->link_start = NULL;
    top = new_node;
    ////printf("new scope success\n");
}

void pop_scope(){
    //printf("pop scope\n");
    if(disable_new_scope){
        return;
    }
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
    //printf("pop scope success\n");
}

int store_ID(char* ID, Var* varptr){
    //printf("Try store ID %s\n", ID);
    fflush(stdout);
    Treap* node = find(ID, symbol_treap);
    if(node == NULL){
        node = new_node(ID);
        Treap* l, *r;
        split(symbol_treap, ID, &l, &r);
        symbol_treap = merge(merge(l, node), r);
    }
    else if(node->link != NULL && node->link->scope == top->scope){
        //printf("store ID fail\n");
        fflush(stdout);
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
    //printf("store ID %s success\n", ID);
    fflush(stdout);
    return 1;
}

Var* query_ID(char* ID){
    // printf("query ID %s!\n", ID);
    // fflush(stdout);
    Treap* node = find(ID, symbol_treap);
    if(node == NULL || node->link == NULL){
        // printf("query ID fail\n");
        // fflush(stdout);
        return NULL;
    }
    struct Var* ret = (struct Var*)malloc(sizeof(struct Var));
    ret -> dim = node->link->varptr->dim;
    ret -> name = (char*)malloc(30*sizeof(char));
    ret -> next = NULL;
    ret -> type = node->link->varptr->type;
    strcpy(ret -> name,node->link->varptr->name);
    // printf("query ID success\n");
    // fflush(stdout);
    return ret;
}

int store_Type(char* ID, Type* typeptr){
    //printf("store Type %s\n", ID);
    Treap* node = find(ID, type_treap);
    if(node == NULL){
        node = new_node(ID);
        Treap* l, *r;
        split(type_treap, ID, &l, &r);
        type_treap = merge(merge(l, node), r);
    }
    else if(node->link != NULL && node->link->scope == top->scope){
        //printf("store Type fail\n");
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
    //printf("store Type success\n");
    return 1;
}

Type* query_Type(char* ID){
    //printf("query Type %s\n", ID);
    Treap* node = find(ID, type_treap);
    if(node == NULL || node->link == NULL){
        //printf("query Type fail\n");
        return NULL;
    }
    //printf("query Type success\n");
    return node->link->typeptr;
}

int store_Fun(char* ID, Var* varptr){
    //printf("store Fun\n");
    fflush(stdout);
    Treap* node = find(ID, fun_treap);
    if(node == NULL){
        node = new_node(ID);
        Treap* l, *r;
        split(fun_treap, ID, &l, &r);
        fun_treap = merge(merge(l, node), r);
        IntermediateLink* new_link = (IntermediateLink*)malloc(sizeof(IntermediateLink));
        new_link->next_scope = NULL;
        new_link->next_ID = NULL;
        new_link->from = node;
        new_link->scope = top->scope;
        new_link->varptr = varptr;
        node->link = new_link;
        //printf("store Fun success\n");
        return 1;
    }
    else{
        //printf("store Fun fail\n");
        //fflush(stdout);
        return 0;
    }
}

Var* query_Fun(char* ID){
    //printf("query Fun\n");
    Treap* node = find(ID, fun_treap);
    if(node == NULL || node->link == NULL){
        //printf("query Fun fail\n");
        return NULL;
    }
    //printf("query Fun success\n");
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
    //printf("get hash\n");
    fflush(stdout);
    unsigned long long base1 = 998244353, base2 = 13331, base3 = 19260817, mod = 1610612741, hashval = 0;
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

        for(int i = 0; i < length; i ++){
            children_hash[i] = tmp->type->hash;
            if(children_hash[i] == 0){
                children_hash[i] = tmp->type->hash = get_hash(tmp->type);
            }
            int dim = tmp->dim;
            while(dim){
                unsigned long long tmpbase = base3;
                if(dim & 1){
                    children_hash[i] = children_hash[i] * tmpbase % mod;
                }
                tmpbase *= tmpbase;
                dim >>= 1;
            }
            tmp = tmp->next; 
        }
        qsort(children_hash, length, sizeof(unsigned long long), cmp);
        for(int i = 0; i < length; i ++){
            hashval = (hashval * base1 + children_hash[i]) % mod;
        }
        free(children_hash);
        return hashval * base2 % mod;
    }
    //printf("get hash success\n");
    fflush(stdout);
    return hashval;
}

void print_current_scope(){
    printf("print current scope:\n");
    IntermediateLink* l1 = top->link_start;
    while(l1 != NULL){
        printf("%s ", l1->from->val);
        l1 = l1->next_ID;
    }
    printf("\n");
}

Treap* new_node(char* val){
    Treap* node = (Treap*)malloc(sizeof(Treap));
    node->key = rand();
    node->val = val;
    node->link = NULL;
    node->lson = node->rson = NULL;
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

void split(Treap* node, char* v, Treap** l, Treap** r){
    if(node == NULL){
        *l = *r = NULL;
        return;
    }
    if(strcmp(node->val, v) < 0){
        *l = node;
        split(node->rson, v, &(node->rson), r);
    }
    else{
        *r = node;
        split(node->lson, v, l, &(node->lson));
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


// // wdh: 下面就是我瞎写的判等的部分了，还没在.h里面声明，上面没动（（

// int check_int(nodePointer p){
//     struct Type*
// }