#include "structure.h"

int hasError = 0;
int error_type = -1;

nodePointer getTerminalNode(char *name, int line){
    //printf("terminal: %s %d %s\n", name, line, yytext);
    //fflush(stdout);
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    //printf("Success\n");
    f -> value = (char*)malloc(sizeof(char)*30);
    strcpy(f->value,yytext);
    f->varList=NULL;
    return f;
}

nodePointer getIDNode(char *name, int line){
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    f -> line = line;
    f -> value = (char*)malloc(sizeof(char)*30);
    strcpy(f->value,yytext);
    
    var temp = {name,0, name, 0};
    varlistNode varNode = {&temp, NULL}; 
    f->varList=&varNode;
    return f;
}
 
    

nodePointer getNode(char* name, int num, ...){
    //printf("%s %d %s\n", name, yylineno, yytext);
    //fflush(stdout);
    nodePointer f = (nodePointer)malloc(sizeof(struct Node));
    f -> name = name;
    f -> head = f -> next = NULL;
    nodePointer temp = NULL;

    va_list ap;
    va_start(ap, num);
    for(int i = 0;i < num;i++){
        if(i == 0){
            f -> head = va_arg(ap, nodePointer);
            f -> line = f -> head -> line;
            temp = f -> head;
        }else{
            temp -> next = va_arg(ap, nodePointer);
            temp = temp -> next;
            //if(strcmp("RC", temp->name) == 0)printf("OOOOO!");
        }
    }
    va_end(ap);

// 变量部分：
    if(strcmp(name,"VarDec")==0){
        va_start(ap, num);
        f->varList = va_arg(ap, nodePointer)->varList;
        va_end(ap);
        if (num==4){
                varlistNode* temp=f->varList;
                var* temp2=temp->varPoint;
                temp2->array_layer++;
                }
    }
    if(strcmp(name,"ExtDecList")==0){
        va_start(ap, num);
        for(int i = 0;i < num;i++){
            nodePointer tmp=va_arg(ap, nodePointer);
            if(i == 0){
            f->varList = tmp->varList;
            }
            if(i==2){
                f->varList->next=tmp->varList;
            }
        }
        va_end(ap);
    }
    if(strcmp(name,"ExtDef")==0 && num==3){
        va_start(ap, num);
        for(int i = 0;i < num;i++){
            nodePointer tmp=va_arg(ap, nodePointer);
            if(i==1){
                varlistNode* temp=tmp->varList;
                while(temp!=NULL){
                    var* temp2=temp->varPoint;
                    temp2->value=f->head->value;  //将结构体名,基础类型，函数名都赋值到这里
                    store(temp2);   //存入符号表
                    temp=temp->next;
                }
            }
        }
        va_end(ap);
    }
    // 本地声明部分：
    if(strcmp(name,"Dec")==0){
        va_start(ap, num);
        f->varList = va_arg(ap, nodePointer)->varList;
        va_end(ap);
    }
    if(strcmp(name,"DecList")==0){
        va_start(ap, num);
        for(int i = 0;i < num;i++){
            nodePointer tmp=va_arg(ap, nodePointer);
            if(i == 0){
            f->varList = tmp->varList;
            }
            if(i==2){
                f->varList->next=tmp->varList;
            }
        }
        va_end(ap);
    }
    if(strcmp(name,"Def")==0){
        va_start(ap, num);
        for(int i = 0;i < num;i++){
            nodePointer tmp=va_arg(ap, nodePointer);
            if(i == 1){
            f->varList = tmp->varList;
            varlistNode* temp=tmp->varList;
                while(temp!=NULL){
                    var* temp2=temp->varPoint;
                    temp2->value=f->head->value;  //将结构体名,基础类型，函数名都赋值到这里
                    store(temp2);   //存入符号表
                    temp=temp->next;
                }
            }
        }
        va_end(ap);
    }
     if(strcmp(name,"DefList")==0){
        va_start(ap, num);
        for(int i = 0;i < num;i++){
            nodePointer tmp=va_arg(ap, nodePointer);
            if(i == 0){
            f->varList = tmp->varList;
            }
            if(i==1){
                f->varList->next=tmp->varList;
            }
        }
        va_end(ap);
    }
    if(strcmp(name,"CompSt")==0){
        //弹出当前作用域符号表内所用变量
    }
    if(strcmp(name,"StructSpecifier")==0){
      //弹出当前作用域符号表内所用变量。 result=popall()
    //   for var in result: var.name=mystrcat(f->head->value,".",var.name);
    }
    //变量

    return f;
}

char* mystrcat(char* str1,char* str2,char* str3){
    // 计算新字符串所需的总长度
    int totalLength = strlen(str1) + strlen(str2) + strlen(str2) + 1; // +1 为 '\0'

    // 动态分配空间
    char *result = malloc(totalLength * sizeof(char));
    if (result == NULL) {
        perror("Unable to allocate memory for the result string");
        exit(1);
    }

    // 使用 strcpy 和 strcat 来拼接字符串
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    return result;
}

void writeTerminalNode(nodePointer node){
    if(node == NULL)return;
    if(strcmp(node->name,"ID")==0 
        || strcmp(node->name,"TYPE")==0 
        || strcmp(node->name,"CHAR")==0){
        printf("%s: %s", node->name, node->value);
    }else if(strcmp(node->name,"INT")==0){
        printf("INT: ");
        printf("%d",atoi(node->value));
    }else if(strcmp(node->name,"FLOAT")==0){
        printf("FLOAT: ");
        printf("%f",atof(node->value));
    }else{
        printf("%s",node->name);
    }
    printf("\n");
    return;
}

void writeNode(nodePointer node,int deep){
    if(node == NULL)return;
    if(node -> line == -1){
        writeNode(node->head, deep+1);
        writeNode(node->next, deep);
        return;
    }

    for(int i = 1;i <= deep;i++){
        printf("  ");
    }

    if(node -> head != NULL){
        printf("%s (%d)\n",node->name, node -> line);
        writeNode(node->head,deep+1);
        writeNode(node->next,deep);
    }else{
        writeTerminalNode(node);
        writeNode(node->next, deep);
    }
}

void yyerror(char *msg)
{
    //printf("?? %d %s \"%s\"\n", yylineno, yytext, msg);
    if(error_type == 1 && strcmp(msg,"syntax error")!=0){
        printf("Error type B at line %d: %s\n",yylineno,msg); // 如果是syntax error
    }else if(error_type == 0 && strcmp(msg,"syntax error")!=0){
        printf("Error type A at line %d: %s\n",yylineno,msg); // 或者是 lex error
    }
    else if(error_type == 2){
        printf("Semantic Error at line %d: %s\n",yylineno,msg); 
    }
    hasError=1;
}


int main(int argc, char **argv) {
    if (argc < 2)
    {
        
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
       
        hasError = 0;

        FILE *f = fopen(argv[i], "r");
        if (!f)
        {
            perror(argv[i]);
            return 1;
        }
        yyrestart(f);
        //printf("oooooooo%s\n", argv[i]);
        fflush(stdout);
        yyparse();
        fclose(f);
        
    }
}

