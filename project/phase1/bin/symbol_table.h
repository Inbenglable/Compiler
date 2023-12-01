//store(): insert an ID
//new_scope(): enter a new scope,ID defined in the new scope will cover those in old scope
//pop_scope(): pop the top scope, as well as its IDs
//query(): return the type of a certain ID

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

bool store(char* ID, Var* varptr){
    Treap* node = find(ID);
    if(node == NULL){
        node = new_node(ID);
        treap = merge(treap, node);
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

Var* query(char* ID){
    Treap* node = find(ID);
    if(node == NULL){
        return NULL;
    }
    return node->link->varptr;
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
};

struct Treap{
    Treap* lson;
    Treap* rson;
    int key;
    char* val;
    IntermediateLink* link;
}*treap;

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

Treap* find(char* v){
    Treap* node = treap;
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