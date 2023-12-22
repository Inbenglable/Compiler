#include "ir_translate.h"
#include "ir_optimization.h"
#include "symbol_table.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int label_count = 0;
int tmp_count = 0;

char* to_literal(int val){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "#%d", val);
    return ret;
}

char* to_size(int val){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "%d", val);
    return ret;
}

char* to_var(char* name){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "var_%s", name);
    return ret;
}

char* attach(char* str1, char* str2){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "%s%s", str1, str2);
    return ret;
}

char* new_label_name(){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "label_%d", label_count++);
    return ret;
}

char* new_tmp_name(){
    char* ret = (char*)malloc(sizeof(char) * 30);
    sprintf(ret, "tmp_%d", tmp_count++);
    return ret;
}

struct Code* construct(int type, char* tk1, int relop, char* tk2, char* tk3){
    struct Code* ret = (struct Code*)malloc(sizeof(struct Code));
    ret->type = type;
    ret->tk1 = tk1;
    ret->relop = relop;
    ret->tk2 = tk2;
    ret->tk3 = tk3;
    ret->is_const = 0;
    ret->value = 0;
    ret->is_tmp = 0;
    ret->next = NULL;
    ret->from = NULL;
    return ret;
}

struct Code* append(struct Code* code1_head, struct Code* code1_tail, struct Code* code2_head, struct Code* code2_tail){
    if(code1_head == NULL || code1_head->type == -1){
        return code2_head;
    }
    if(code2_head == NULL || code2_head->type == -1){
        return code1_head;
    }
    code1_tail->next = code2_head;
    code2_head->from = code1_tail;
    return code1_head;
}

struct Code* append_wo_tail(struct Code* code1, struct Code* code2){
    if(code1 == NULL || code1->type == -1){
        return code2;
    }
    if(code2 == NULL || code2->type == -1){
        return code1;
    }
    struct Code* code1_tail = code1;
    while(code1_tail->next != NULL){
        code1_tail = code1_tail->next;
    }
    code1_tail->next = code2;
    code2->from = code1_tail;
    return code1;
}

void dump(struct Code* head, char* filename){
    FILE* fp = fopen(filename, "w");
    while(head != NULL){
        switch(head->type){
            case 0:
                fprintf(fp, "LABEL %s :\n", head->tk1);
                break;
            case 1:
                fprintf(fp, "FUNCTION %s :\n", head->tk1);
                break;
            case 2:
                fprintf(fp, "%s := %s\n", head->tk1, head->tk2);
                break;
            case 3:
                fprintf(fp, "%s := %s + %s\n", head->tk1, head->tk2, head->tk3);
                break;
            case 4:
                fprintf(fp, "%s := %s - %s\n", head->tk1, head->tk2, head->tk3);
                break;
            case 5:
                fprintf(fp, "%s := %s * %s\n", head->tk1, head->tk2, head->tk3);
                break;
            case 6:
                fprintf(fp, "%s := %s / %s\n", head->tk1, head->tk2, head->tk3);
                break;
            case 7:
                fprintf(fp, "%s := &%s\n", head->tk1, head->tk2);
                break;
            case 8:
                fprintf(fp, "%s := *%s\n", head->tk1, head->tk2);
                break;
            case 9:
                fprintf(fp, "*%s := %s\n", head->tk1, head->tk2);
                break;
            case 10:
                fprintf(fp, "GOTO %s\n", head->tk1);
                break;
            case 11:
                fprintf(fp, "IF %s %s %s GOTO %s\n", head->tk1, head->relop == 0 ? "<" : head->relop == 1 ? "<=" : head->relop == 2 ? ">" : head->relop == 3 ? ">=" : head->relop == 4 ? "!=" : "==", head->tk2, head->tk3);
                break;
            case 12:
                fprintf(fp, "RETURN %s\n", head->tk1);
                break;
            case 13:
                fprintf(fp, "DEC %s %s\n", head->tk1, head->tk2);
                break;
            case 14:
                fprintf(fp, "PARAM %s\n", head->tk1);
                break;
            case 15:
                fprintf(fp, "ARG %s\n", head->tk1);
                break;
            case 16:
                fprintf(fp, "%s := CALL %s\n", head->tk1, head->tk2);
                break;
            case 17:
                fprintf(fp, "READ %s\n", head->tk1);
                break;
            case 18:
                fprintf(fp, "WRITE %s\n", head->tk1);
                break;
        }
        head = head->next;
    }
    fclose(fp);
}

struct Code* translate_exp(struct Node* node, char* place){
    print_node(node);
    char* son_list = get_son_list(node);
    node->tmp_name = place;
    struct Code* ret_head = NULL;
    if(strcmp(son_list, "INT") == 0){
        nodePointer con = node -> head;
        struct Code* code = construct(2, place, -1, to_literal(char_to_int(con -> value)), NULL);
        code->is_const = 1;
        code->value = var_to_int(code->tk2);
        con->tmp_name = code->tk2;
        connect_code_to_node(node, code);
        node->tmp_name = con->tmp_name;
        return code;
    }
    else if(strcmp(son_list, "ID") == 0){
        nodePointer id = node -> head;
        struct Code* code = construct(2, place, -1, to_var(id->value), NULL);
        id->tmp_name = code->tk2;
        node->tmp_name = id->tmp_name;
        connect_code_to_node(node, code);
        printf("translate ID: %s\n", node->tmp_name);
        fflush(stdout);
        return code;
    }
    else if(strcmp(son_list, "ExpDOTID") == 0){
        char* struct_name = node -> var -> name;
        struct Code* code = construct()
    }
    else if(strcmp(son_list, "ExpASSIGNExp") == 0){
        nodePointer tk1 = node->head;
        nodePointer tk2 = tk1->next->next;
        char* tmp1 = new_tmp_name();
        struct Code* block1 = translate_exp(tk1, tmp1);
        struct Code* block2 = translate_exp(tk2, tmp1);
        struct Code* code = construct(2, tk1->tmp_name, -1, tmp1, NULL);
        if(start_with_well(code->tk2)){
            ret_head = block1;
            ret_head = append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else{
            ret_head = block1;
            append_wo_tail(ret_head, block1);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }
    }
    else if(strcmp(son_list, "ExpPLUSExp") == 0){
        nodePointer tk1 = node->head;
        nodePointer tk2 = tk1->next->next;
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* block1 = translate_exp(tk1, tmp1);
        struct Code* block2 = translate_exp(tk2, tmp2);
        struct Code* code = construct(3, place, -1, tk1->tmp_name, tk2->tmp_name);
        if(start_with_well(code->tk2) && start_with_well(code->tk3)){
            int res = var_to_int(code->tk2)+var_to_int(code->tk3);
            code->type = 3;
            code->tk2 = to_literal(res);
            code->tk3 = NULL;
            node->tmp_name = code->tk2;
            connect_code_to_node(node, code);
            return code;
        }else if(start_with_well(code->tk2)){
            ret_head = block2;
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else if(start_with_well(code->tk3)){
            ret_head = block1;
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else{
            ret_head = block1;
            append_wo_tail(ret_head, block2);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }
    }
    else if(strcmp(son_list, "ExpMINUSExp") == 0){
        nodePointer tk1 = node->head;
        nodePointer tk2 = tk1->next->next;
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* block1 = translate_exp(tk1, tmp1);
        struct Code* block2 = translate_exp(tk2, tmp2);
        struct Code* code = construct(4, place, -1, tk1->tmp_name, tk2->tmp_name);
        if(start_with_well(code->tk2) && start_with_well(code->tk3)){
            int res = var_to_int(code->tk2)-var_to_int(code->tk3);
            code->type = 2;
            code->tk2 = to_literal(res);
            code->tk3 = NULL;
            node->tmp_name = code->tk2;
            connect_code_to_node(node, code);
            return code;
        }else if(start_with_well(code->tk2)){
            ret_head = block2;
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else if(start_with_well(code->tk3)){
            ret_head = block1;
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else{
            ret_head = block1;
            append_wo_tail(ret_head, block2);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }
    }
    else if(strcmp(son_list, "ExpMULExp") == 0){
        nodePointer tk1 = node->head;
        nodePointer tk2 = tk1->next->next;
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* block1 = translate_exp(tk1, tmp1);
        struct Code* block2 = translate_exp(tk2, tmp2);
        struct Code* code = construct(5, place, -1, tk1->tmp_name, tk2->tmp_name);
        if(start_with_well(code->tk2) && start_with_well(code->tk3)){
            int res = var_to_int(code->tk2)*var_to_int(code->tk3);
            code->type = 2;
            code->tk2 = to_literal(res);
            code->tk3 = NULL;
            node->tmp_name = code->tk2;
            connect_code_to_node(node, code);
            return code;
        }else if(start_with_well(code->tk2)){
            ret_head = block2;
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else if(start_with_well(code->tk3)){
            ret_head = block1;
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else{
            ret_head = block1;
            append_wo_tail(ret_head, block2);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }
    }
    else if(strcmp(son_list, "ExpDIVExp") == 0){
        nodePointer tk1 = node->head;
        nodePointer tk2 = tk1->next->next;
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* block1 = translate_exp(tk1, tmp1);
        struct Code* block2 = translate_exp(tk2, tmp2);
        struct Code* code = construct(6, place, -1, tk1->tmp_name, tk2->tmp_name);
        if(start_with_well(code->tk2) && start_with_well(code->tk3)){
            int res = var_to_int(code->tk2)/var_to_int(code->tk3);
            code->type = 2;
            code->tk2 = to_literal(res);
            code->tk3 = NULL;
            node->tmp_name = code->tk2;
            connect_code_to_node(node, code);
            return code;
        }else if(start_with_well(code->tk2)){
            ret_head = block2;
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else if(start_with_well(code->tk3)){
            ret_head = block1;
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }else{
            ret_head = block1;
            append_wo_tail(ret_head, block2);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }
    }
    else if(strcmp(son_list, "LPExpRP") == 0){
        nodePointer ftk1 = node->head->next;
        ret_head = translate_exp(ftk1, place);
        return ret_head; 
    }
    else if(strcmp(son_list, "MINUSExp") == 0){
        nodePointer ftk1 = node->head->next;
        char* tmp = new_tmp_name();
        struct Code* block1 = translate_exp(ftk1, tmp);
        if(start_with_well(ftk1->tmp_name)){
            int res = var_to_int(ftk1->tmp_name)*(-1);
            struct Code* code = construct(2, place, -1, to_literal(res), NULL);
            connect_code_to_node(node, ret_head);
            return code;
        }else{
            ret_head = block1;
            struct Code* code = construct(4, place, -1, to_literal(0), ftk1->tmp_name);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }
    }
    //below are function invocations
    else if(strcmp(son_list, "IDLPRP") == 0){
        nodePointer fun = node->head;
        char* fun_name = fun->value;
        if(strcmp(fun_name, "read") == 0){
            struct Code* code = construct(17, place, -1, NULL, NULL);
            connect_code_to_node(node, code);
            return code;
        }else{
            struct Code* code = construct(16, place, -1, fun_name, NULL);
            connect_code_to_node(node, code);
            return code;
        }
    }
    else if(strcmp(son_list, "IDLPArgsRP") == 0){
        nodePointer fun = node->head;
        nodePointer args = fun->next->next;
        char* fun_name = fun->value;
        struct ArgList* arg_list = NULL;
        struct Code* block1 = translate_args(args, &(arg_list));
        
        if(strcmp(fun_name, "write") == 0){
            ret_head = block1;
            struct Code* code = construct(18, arg_list->name, -1, NULL, NULL);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, code);
            return ret_head;
        }else{
            struct Code* block2 = NULL;
            struct Code* tmp = NULL;
            while(arg_list != NULL){
                printf("!!!%s\n", arg_list->name);
                tmp = construct(15, arg_list->name, -1, NULL, NULL);
                block2 = append_wo_tail(block2, tmp);
                arg_list = arg_list->next;
            }
            //dump(block2,"debug.out");
            ret_head = block1;
            append_wo_tail(ret_head, block2);
            struct Code* code = construct(16, place, -1, fun_name, NULL);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
            return ret_head;
        }
    }
    else{
        // can be used for other purposes
        return NULL;
        //printf("Match expression Fail\n");
    }
    //printf("Finish translate expression\n");
    //fflush(stdout);
}

struct Code* translate_cond(struct Node* node, char* label_true, char* label_false){
    print_node(node);
    char* son_list = get_son_list(node);
    struct Code* ret_head = NULL;
    if(strcmp(son_list, "ExpLTExp") == 0){
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* code1 = translate_exp(node->head, tmp1);
        struct Code* code2 = translate_exp(node->head->next->next, tmp2);
        struct Code* code3 = construct(11, tmp1, 0, tmp2, label_true);
        struct Code* code4 = construct(10, label_false, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4);
    }
    else if(strcmp(son_list, "ExpLEExp") == 0){
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* code1 = translate_exp(node->head, tmp1);
        struct Code* code2 = translate_exp(node->head->next->next, tmp2);
        struct Code* code3 = construct(11, tmp1, 1, tmp2, label_true);
        struct Code* code4 = construct(10, label_false, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4);
    }
    else if(strcmp(son_list, "ExpGTExp") == 0){
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* code1 = translate_exp(node->head, tmp1);
        struct Code* code2 = translate_exp(node->head->next->next, tmp2);
        struct Code* code3 = construct(11, tmp1, 2, tmp2, label_true);
        struct Code* code4 = construct(10, label_false, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4);
    }
    else if(strcmp(son_list, "ExpGEExp") == 0){
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* code1 = translate_exp(node->head, tmp1);
        struct Code* code2 = translate_exp(node->head->next->next, tmp2);
        struct Code* code3 = construct(11, tmp1, 3, tmp2, label_true);
        struct Code* code4 = construct(10, label_false, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4);
    }
    else if(strcmp(son_list, "ExpNEExp") == 0){
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* code1 = translate_exp(node->head, tmp1);
        struct Code* code2 = translate_exp(node->head->next->next, tmp2);
        struct Code* code3 = construct(11, tmp1, 4, tmp2, label_true);
        struct Code* code4 = construct(10, label_false, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4);
    }
    else if(strcmp(son_list, "ExpEQExp") == 0){
        char* tmp1 = new_tmp_name();
        char* tmp2 = new_tmp_name();
        struct Code* code1 = translate_exp(node->head, tmp1);
        struct Code* code2 = translate_exp(node->head->next->next, tmp2);
        struct Code* code3 = construct(11, tmp1, 5, tmp2, label_true);
        struct Code* code4 = construct(10, label_false, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4);
    }
    else if(strcmp(son_list, "ExpANDExp") == 0){
        char* label1 = new_label_name();
        struct Code* code1 = translate_cond(node->head, label1, label_false);
        struct Code* code2 = construct(0, label1, -1, NULL, NULL);
        struct Code* code3 = translate_cond(node->head->next->next, label_true, label_false);
        return append_wo_tail(append_wo_tail(code1, code2), code3);
    }
    else if(strcmp(son_list, "ExpORExp") == 0){
        char* label1 = new_label_name();
        struct Code* code1 = translate_cond(node->head, label_true, label1);
        struct Code* code2 = construct(0, label1, -1, NULL, NULL);
        struct Code* code3 = translate_cond(node->head->next->next, label_true, label_false);
        return append_wo_tail(append_wo_tail(code1, code2), code3);
    }
    else if(strcmp(son_list, "NOTExp") == 0){
        nodePointer ftk1 = node->head->next;
        ret_head = translate_cond(ftk1, label_false, label_true);
        return ret_head; 
    }
    else if(strcmp(son_list, "LPExpRP") == 0){
        nodePointer ftk1 = node->head->next;
        ret_head = translate_cond(ftk1, label_true, label_false);
        return ret_head; 
    }
    else{
        char* tmp = new_tmp_name();
        struct Code* code = translate_exp(node, tmp);
        struct Code* code1 = construct(11, tmp, 5, to_literal(0), label_false);
        struct Code* code2 = construct(10, label_true, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(code, code1), code2);
    }
}

struct Code* translate_stmt(struct Node* node){
    print_node(node);
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "LCDefListStmtListRC") == 0){
        struct Code* code1 = translate_local_definition(node->head->next);
        struct Code* code2 = translate_stmt(node->head->next->next);
        return append_wo_tail(code1, code2);
    }
    else if(strcmp(son_list, "StmtStmtList") == 0){
        struct Code* code1 = translate_stmt(node->head);
        struct Code* code2 = translate_stmt(node->head->next);
        return append_wo_tail(code1, code2);
    }
    else if(strcmp(son_list, "ExpSEMI") == 0){
        return translate_exp(node->head, NULL); // TODO: probably can be optimized
    }
    else if(strcmp(son_list, "CompSt") == 0){
        return translate_stmt(node->head);
    }
    else if(strcmp(son_list, "RETURNExpSEMI") == 0){
        char* tmp = new_tmp_name();
        struct Code* code = translate_exp(node->head->next, tmp);
        return append_wo_tail(code, construct(12, tmp, -1, NULL, NULL));
    }
    else if(strcmp(son_list, "IFLPExpRPStmt") == 0){
        char* label1 = new_label_name();
        char* label2 = new_label_name();
        struct Code* code1 = append_wo_tail(translate_cond(node->head->next->next, label1, label2), construct(0, label1, -1, NULL, NULL));
        struct Code* code2 = append_wo_tail(translate_stmt(node->head->next->next->next->next), construct(0, label2, -1, NULL, NULL));
        return append_wo_tail(code1, code2);
    }
    else if(strcmp(son_list, "IFLPExpRPStmtELSEStmt") == 0){
        char* label1 = new_label_name();
        char* label2 = new_label_name();
        char* label3 = new_label_name();
        struct Code* code1 = append_wo_tail(translate_cond(node->head->next->next, label1, label2), construct(0, label1, -1, NULL, NULL));
        struct Code* code2 = append_wo_tail(translate_stmt(node->head->next->next->next->next), append_wo_tail(construct(10, label3, -1, NULL, NULL), construct(0, label2, -1, NULL, NULL)));
        struct Code* code3 = append_wo_tail(translate_stmt(node->head->next->next->next->next->next->next), construct(0, label3, -1, NULL, NULL));
        return append_wo_tail(append_wo_tail(code1, code2), code3);
    }
    else if(strcmp(son_list, "WHILELPExpRPStmt") == 0){
        char* label1 = new_label_name();
        char* label2 = new_label_name();
        char* label3 = new_label_name();
        struct Code* code1 = append_wo_tail(construct(0, label1, -1, NULL, NULL), translate_cond(node->head->next->next, label2, label3));
        struct Code* code2 = append_wo_tail(construct(0, label2, -1, NULL, NULL), append_wo_tail(translate_stmt(node->head->next->next->next->next), construct(10, label1, -1, NULL, NULL)));
        return append_wo_tail(append_wo_tail(code1, code2), construct(0, label3, -1, NULL, NULL));
    }
    else{
        return NULL;
    }
}

struct Code* translate_args(struct Node* node, struct ArgList** arg_list){
    print_node(node);
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "Exp") == 0){
        char* tmp = new_tmp_name();
        struct Code* code = translate_exp(node->head, tmp);
        struct ArgList* tmp_arg = (struct ArgList*)malloc(sizeof(struct ArgList));;
        tmp_arg->name = tmp;
        tmp_arg->next = *arg_list;
        *arg_list = tmp_arg;
        return code;
    }
    else if(strcmp(son_list, "ExpCOMMAArgs") == 0){
        char* tmp = new_tmp_name();
        struct Code* code1 = translate_exp(node->head, tmp);
        struct ArgList* tmp_arg = (struct ArgList*)malloc(sizeof(struct ArgList));
        tmp_arg->name = tmp;
        tmp_arg->next = *arg_list;
        *arg_list = tmp_arg;
        fflush(stdout);
        struct Code* code2 = translate_args(node->head->next->next, arg_list);
        return append_wo_tail(code1, code2);
    }
    else{
        printf("Seems that some unexpected things have happened!\n");
        return NULL;
    }
}

struct Code* translate_fundec(struct Node* node){
    print_node(node);
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "IDLPVarListRP") == 0){
        struct Code* code = construct(1, node->head->value, -1, NULL, NULL);
        struct Code* code1 = translate_fundec(node->head->next->next);
        return append_wo_tail(code, code1);
    }
    else if(strcmp(son_list, "IDLPRP") == 0){
        struct Code* code = construct(1, node->head->value, -1, NULL, NULL);
        return code;
    }
    else if(strcmp(son_list, "ParamDecCOMMAVarList") == 0){
        struct Code* code1 = translate_fundec(node->head);
        struct Code* code2 = translate_fundec(node->head->next->next);
        return append_wo_tail(code1, code2);
    }
    else if(strcmp(son_list, "ParamDec") == 0){
        return translate_fundec(node->head);
    }
    else if(strcmp(son_list, "SpecifierVarDec") == 0){
        return translate_fundec(node->head->next);
    }
    else if(strcmp(son_list, "ID") == 0){
        return construct(14, to_var(node->head->value), -1, NULL, NULL);
    }
    else if(strcmp(son_list, "VarDecLBINTRB") == 0){
        // TODO: may be modified, if consider array
        return translate_fundec(node->head);
    }
    else{
        printf("Seems that some unexpected things have happened!\n");
        return NULL;
    }
}

struct Code* translate_high_level_def(struct Node* node){
    print_node(node);
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "ExtDefList") == 0){
        return translate_high_level_def(node->head);
    }
    else if(strcmp(son_list, "ExtDefExtDefList") == 0){
        struct Code* code1 = translate_high_level_def(node->head);
        struct Code* code2 = translate_high_level_def(node->head->next);
        return append_wo_tail(code1, code2);
    }
    // TODO: now we don't consider struct, but we may modify it in the future
    else if(strcmp(son_list, "SpecifierExtDecListSEMI") == 0){
        // do not consider global variable, so return NULL.
        return NULL;
    }
    else if(strcmp(son_list, "SpecifierSEMI") == 0){
        return NULL;
    }
    else if(strcmp(son_list, "FunspecifierCompSt") == 0){
        struct Code* code1 = translate_high_level_def(node->head);
        struct Code* code2 = translate_stmt(node->head->next);
        return append_wo_tail(code1, code2);
    }
    else if(strcmp(son_list, "FunspecifierSEMI") == 0){
        // struct Code* code = translate_fundec(node->head->next);
        // return code;
        // we don't consider function declaration, so return NULL.
        return NULL;
    }
    else if(strcmp(son_list, "SpecifierFunDec") == 0){
        struct Code* code = translate_fundec(node->head->next);
        return code;
    }
    else{
        return NULL;
    }
}

int translate_specifier(struct Node* node){
    print_node(node);
    // Seems that we don't need to translate specifier, but we leave it temporarily.
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "TYPE") == 0){
        return 0;
    }
    // TODO: now we don't consider struct, but we may modify it in the future
    else if(strcmp(son_list, "StructSpecifier") == 0){
        return translate_specifier(node->head);
    }
    else if(strcmp(son_list, "STRUCTIDLCDefListRC") == 0){
        struct Type* type = query_Type(node->head->next->value);
        return type->size;
    }
    else if(strcmp(son_list, "STRUCTID") == 0){
        struct Type* type = query_Type(node->head->next->value);
        return type->size;
    }
    else{
        printf("Seems that some unexpected things have happened!\n");
        return 0;
    }
}

struct Code* translate_local_definition(int size, struct Node* node){
    print_node(node);
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "DefDefList") == 0){
        struct Code* code1 = translate_local_definition(0, node->head);
        struct Code* code2 = translate_local_definition(0, node->head->next);
        return append_wo_tail(code1, code2);
    }
    else if(strcmp(son_list, "SpecifierDecListSEMI") == 0){
        // TODO: now we don't consider struct, but we may modify it in the future
        return translate_local_definition(translate_specifier(node->head), node->head->next);
    }
    else if(strcmp(son_list, "Dec") == 0){
        return translate_local_definition(size, node->head);
    }
    else if(strcmp(son_list, "DecCOMMADecList") == 0){
        struct Code* code1 = translate_local_definition(size, node->head);
        struct Code* code2 = translate_local_definition(size, node->head->next->next);
        return append_wo_tail(code1, code2);
    }
    else if(strcmp(son_list, "VarDec") == 0){
        if(size == 0){
            return NULL;
        }
        else{
            char* var = to_var(node->head->head->value);
            return construct(13, var, -1, to_literal(size), NULL);
        }
    }
    else if(strcmp(son_list, "VarDecASSIGNExp") == 0){
        // no need to consider struct
        char* var = node->head->head->value;
        return translate_exp(node->head->next->next, to_var(var));
    }
    else{
        return NULL;
    }
}

void translate(struct Node* node, char* filename){
    //printf("Translation requires implementation, the name of the root is %s, the translation result will be output to %s\n", node->name, filename);
    struct Code* raw_code = translate_high_level_def(node);
    struct Code* optimized_code = optimize(raw_code);
    printf("Start dumping code to %s\n", filename);
    dump(optimized_code, filename);
}


///////////////////////////////////////////////////////////////////////////////////////

//By radiance: 我写的部分都写下面好了

int char_to_int(const char* str) {
    // 使用atoi函数将字符串转换为整数
    int result = atoi(str);

    return result;
}


int var_to_int(const char* str) {
    int result;
    
    // 使用sscanf解析字符串，跳过'#'字符，将整数部分存储到result中
    sscanf(str, "#%d", &result);

    return result;
}

int start_with_well(const char* str) {
    // 检查输入指针是否为NULL
    if (str == NULL) {
        return 0;
    }

    // 使用 strncmp 函数比较字符串的前缀是否为 "#"
    if (strncmp(str, "#", 1) == 0) {
        return 1;  // 字符串以 '#' 开头
    } else {
        return 0; // 字符串不以 '#' 开头
    }
}

struct Code* get_tail(struct Code* code){
    if(code == NULL)return NULL;
    struct Code* tmp = code;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    return tmp;
}

void connect_code_to_node(nodePointer node, struct Code* code){
    node->code_head = code;
    node->code_tail = get_tail(code);
}

void print_node(nodePointer node){
    ENABLE_PRINT = 0;
    if(ENABLE_PRINT == 0)return;
    printf("node name: %s\n", node->name);
    printf("node value: %s\n", node->value);
    printf("node tmp_name: %s\n", node->tmp_name);
    printf("node son: %s\n\n", get_son_list(node));
}