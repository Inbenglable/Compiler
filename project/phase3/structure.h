#ifndef __STRUCTURE__
#define __STRUCTURE__

extern char* yytext;
extern int yylineno;
extern int error_type;
extern int error_line;
extern int hasError;
void yyerror(char *msg);

typedef struct Type Type;
typedef struct Var Var;
typedef struct Node Node;

struct Type{
    char* type_name;//the name of the type
    char isStruct;//s -> structure, v-> var, f->function
    unsigned long long hash;//type hash
    struct Var* contain;
};

struct Var{
    char* name;
    char* alias;
    int dim; // deep of the array, 0 if it is a variable
    int line;
    struct Type* type;
    struct Var *next;
};


// typedef struct {
//     char* name;  //变量名
//     char isStruct;  //v则为变量类型,s则为结构体名，f则为函数
//     char* value;  //变量，函数的type存在这里,结构体这里为结构体名
//     int array_layer;   
// }var;
// // int a, int a[],  struct A{}a [], int funtion a()   project: 

// typedef struct {
//     struct var* varPoint;
//     struct varlistNode* next;
// }varlistNode;
struct Node{
    int line;
    char* name;
    struct Node *head,*next;
    char* value;
    struct Type* type;
    struct Var* var;
    struct Code* code_head;
    struct Code* code_tail;
    char* tmp_name;
};

typedef struct Node* nodePointer;
void print_var(struct Var* var, int deep);
void print_type(struct Type* type, int deep);

char* get_son_list(nodePointer node);

nodePointer getTerminalNode(char *name, int line);
nodePointer getIDNode(char *name, int line);
nodePointer getTypeNode(char *name, int line);
int push_fun(nodePointer fun_node);
int push_type(nodePointer type_node);
int push_var(nodePointer var_node);
int getStruct(nodePointer spec, nodePointer id);
void newFuntype(nodePointer funspec, nodePointer id, nodePointer varlist);
void assign_funtype(nodePointer fun, nodePointer spec);
void newStructType(nodePointer spec, nodePointer id, nodePointer varlist);
int  assign_type(nodePointer var_head, nodePointer type_provider);
void extend_type(nodePointer to, nodePointer from);
void connect_var(nodePointer now, nodePointer to);
void extend_var(nodePointer to, nodePointer from);
void extend_dim(nodePointer var);
void reduce_dim(nodePointer var);
nodePointer getNode(char* token_name,int num,...);

struct Var* check_ID_def(nodePointer node);
struct Var* check_fun_def(nodePointer node);
int check_assign_type(nodePointer lnode, nodePointer rnode);
int check_rvalue(nodePointer node);
Type* check_field(Type* typeptr, char* name);
int check_boolean(nodePointer node1, nodePointer node2);
int check_arithmetic(nodePointer node1, nodePointer node2);
int check_dim(nodePointer node);
int check_index(nodePointer node);
int check_struct(nodePointer node);
int check_ret_type(nodePointer spec, nodePointer varlist);
void connect_link_var(nodePointer head, nodePointer ne);
int check_fun_varlist(nodePointer fun, nodePointer varlist);

struct Type* get_int_type();
void generate_exp_var(nodePointer exp, struct Type* type);

void writeNode(nodePointer node,int depth);
void writeTerminalNode(nodePointer node);

char* mystrcat(char* str1,char* str2,char* str3);

#endif // !__STRUCTURE__