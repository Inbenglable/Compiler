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
        // printf("dumping code: %d %s %d %s %s\n", head->type, head->tk1, head->relop, head->tk2, head->tk3);
        fflush(stdout);
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
    if(place == NULL){
        place = "__tmp__";
    }
    char* son_list = get_son_list(node);
    node->tmp_name = place;
    struct Code* ret_head = NULL;
    if(strcmp(son_list, "INT") == 0){
        nodePointer con = node -> head;
        struct Code* code = construct(2, place, -1, to_literal(char_to_int(con -> value)), NULL);
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
        // printf("translate ID: %s\n", node->tmp_name);
        fflush(stdout);
        return code;
    }
    else if(strcmp(son_list, "ExpDOTID") == 0){
        char* struct_name = node -> var -> name;
        ret_head = NULL;
        char* tmp = new_tmp_name();
        if(node->var->offset != 0){
            ret_head = construct(3, tmp, -1, attach("&", to_var(struct_name)), to_literal(node->var->offset));
            struct Code* code = construct(2, place, -1, attach("*", tmp), NULL);
            ret_head = append_wo_tail(ret_head, code);
            connect_code_to_node(node, code);
            // printf("translate Struct %s.%s with offset %d\n", node->var->name, node->head->next->next->value, node->var->offset);
            // fflush(stdout);
            return ret_head;
        }else{
            ret_head = construct(2, place, -1, to_var(struct_name), NULL);
            // printf("translate Struct %s.%s with offset %d\n", node->var->name, node->head->next->next->value, node->var->offset);
            // fflush(stdout);
            return ret_head;
        }
        
    }
    else if(strcmp(son_list, "ExpASSIGNExp") == 0){
        nodePointer tk1 = node->head;
        nodePointer tk2 = tk1->next->next;
        char* tmp0 = new_tmp_name();
        char* tmp1 = new_tmp_name();
        struct Code* block1 = translate_exp(tk1, tmp0);
        struct Code* block2 = translate_exp(tk2, tmp1);
        struct Code* code = NULL;
        struct Code* code1 = NULL;
        char* var_name = NULL;
        if(tk1->var->offset == 0){
            ret_head = NULL;
            code = construct(2, to_var(tk1->var->name), -1, tk2->tmp_name, NULL);
            var_name = to_var(tk1->var->name);
        }else{
            var_name = new_tmp_name();
            char* struct_name = tk1->var->name;
            ret_head = construct(3, var_name, -1, attach("&", to_var(struct_name)), to_literal(tk1->var->offset));
            code = construct(2, attach("*", var_name), -1, tk2->tmp_name, NULL);
        }
        
        if(start_with_well(code->tk2)){
            ret_head = append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
        }else{
            ret_head = append_wo_tail(ret_head, block2);
            append_wo_tail(ret_head, code);
            connect_code_to_node(node, ret_head);
        }
        if(place != NULL){
            code = construct(2, place, -1, var_name, NULL);
            append_wo_tail(ret_head, code);
        }
        
        return ret_head;
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
                // printf("!!!%s\n", arg_list->name);
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

struct Code* translate_relop(struct Node* exp1, struct Node* exp2, int relop, int jump_only_if_true, int jump_only_if_false, char* label_true, char* label_false){
    char* tmp1 = new_tmp_name();
    char* tmp2 = new_tmp_name();
    struct Code* code1 = translate_exp(exp1, tmp1);
    struct Code* code2 = translate_exp(exp2, tmp2);
    if(jump_only_if_true){
        struct Code* code3 = construct(11, tmp1, relop, tmp2, label_true);
        return append_wo_tail(append_wo_tail(code1, code2), code3);
    }
    else if(jump_only_if_false){
        switch(relop){
            case 0:
                relop = 3;
                break;
            case 1:
                relop = 2;
                break;
            case 2:
                relop = 1;
                break;
            case 3:
                relop = 0;
                break;
            case 4:
                relop = 5;
                break;
            case 5:
                relop = 4;
                break;
        }
        struct Code* code3 = construct(11, tmp1, relop, tmp2, label_false);
        return append_wo_tail(append_wo_tail(code1, code2), code3);
    }
    struct Code* code3 = construct(11, tmp1, relop, tmp2, label_true);
    struct Code* code4 = construct(10, label_false, -1, NULL, NULL);
    return append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4);
}

struct Code* translate_cond(struct Node* node, char* label_true, char* label_false, int jump_only_if_true, int jump_only_if_false){
    print_node(node);
    char* son_list = get_son_list(node);
    struct Code* ret_head = NULL;
    if(strcmp(son_list, "ExpLTExp") == 0){
        return translate_relop(node->head, node->head->next->next, 0, jump_only_if_true, jump_only_if_false, label_true, label_false);
    }
    else if(strcmp(son_list, "ExpLEExp") == 0){
        return translate_relop(node->head, node->head->next->next, 1, jump_only_if_true, jump_only_if_false, label_true, label_false);
    }
    else if(strcmp(son_list, "ExpGTExp") == 0){
        return translate_relop(node->head, node->head->next->next, 2, jump_only_if_true, jump_only_if_false, label_true, label_false);
    }
    else if(strcmp(son_list, "ExpGEExp") == 0){
        return translate_relop(node->head, node->head->next->next, 3, jump_only_if_true, jump_only_if_false, label_true, label_false);
    }
    else if(strcmp(son_list, "ExpNEExp") == 0){
        return translate_relop(node->head, node->head->next->next, 4, jump_only_if_true, jump_only_if_false, label_true, label_false);
    }
    else if(strcmp(son_list, "ExpEQExp") == 0){
        return translate_relop(node->head, node->head->next->next, 5, jump_only_if_true, jump_only_if_false, label_true, label_false);
    }
    else if(strcmp(son_list, "ExpANDExp") == 0){
        if(jump_only_if_true){
            char* label1 = new_label_name();
            struct Code* code1 = translate_cond(node->head, NULL, label1, 0, 1);
            struct Code* code2 = translate_cond(node->head->next->next, label_true, NULL, 1, 0);
            struct Code* code3 = construct(0, label1, -1, NULL, NULL);
            return append_wo_tail(append_wo_tail(code1, code2), code3);
        }
        else if(jump_only_if_false){
            struct Code* code1 = translate_cond(node->head, NULL, label_false, 0, 1);
            struct Code* code2 = translate_cond(node->head->next->next, NULL, label_false, 0, 1);
            return append_wo_tail(code1, code2);
        }
        else{
            struct Code* code1 = translate_cond(node->head, NULL, label_false, 0, 1);
            struct Code* code2 = translate_cond(node->head->next->next, label_true, label_false, 0, 0);
            return append_wo_tail(code1, code2);
        }
    }
    else if(strcmp(son_list, "ExpORExp") == 0){
        if(jump_only_if_true){
            struct Code* code1 = translate_cond(node->head, label_true, NULL, 1, 0);
            struct Code* code2 = translate_cond(node->head->next->next, label_true, NULL, 1, 0);
            return append_wo_tail(code1, code2);
        }
        else if(jump_only_if_false){
            char* label1 = new_label_name();
            struct Code* code1 = translate_cond(node->head, label1, NULL, 1, 0);
            struct Code* code2 = translate_cond(node->head->next->next, NULL, label_false, 0, 1);
            struct Code* code3 = construct(0, label1, -1, NULL, NULL);
            return append_wo_tail(append_wo_tail(code1, code2), code3);
        }
        else{
            struct Code* code1 = translate_cond(node->head, label_true, NULL, 1, 0);
            struct Code* code2 = translate_cond(node->head->next->next, label_true, label_false, 0, 0);
            return append_wo_tail(code1, code2);
        }
    }
    else if(strcmp(son_list, "NOTExp") == 0){
        return translate_cond(node->head->next, label_false, label_true, jump_only_if_false, jump_only_if_true);
    }
    else if(strcmp(son_list, "LPExpRP") == 0){
        return translate_cond(node->head->next, label_true, label_false, jump_only_if_true, jump_only_if_false);
    }
    else{
        if(jump_only_if_true){
            char* tmp = new_tmp_name();
            struct Code* code = translate_exp(node, tmp);
            struct Code* code1 = construct(11, tmp, 4, to_literal(0), label_true);
            return append_wo_tail(code, code1);
        }
        else if(jump_only_if_false){
            char* tmp = new_tmp_name();
            struct Code* code = translate_exp(node, tmp);
            struct Code* code1 = construct(11, tmp, 5, to_literal(0), label_false);
            return append_wo_tail(code, code1);
        }
        else{
            char* tmp = new_tmp_name();
            struct Code* code = translate_exp(node, tmp);
            struct Code* code1 = construct(11, tmp, 4, to_literal(0), label_true);
            struct Code* code2 = construct(10, label_false, -1, NULL, NULL);
            return append_wo_tail(append_wo_tail(code, code1), code2);
        }
    }
}

struct Code* translate_stmt(struct Node* node){
    print_node(node);
    char* son_list = get_son_list(node);
    if(strcmp(son_list, "LCDefListStmtListRC") == 0){
        struct Code* code1 = translate_local_definition(0, node->head->next);
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
        char* label_false = new_label_name();
        struct Code* code1 = translate_cond(node->head->next->next, NULL, label_false, 0, 1);
        struct Code* code2 = translate_stmt(node->head->next->next->next->next);
        struct Code* code3 = construct(0, label_false, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(code1, code2), code3);
    }
    else if(strcmp(son_list, "IFLPExpRPStmtELSEStmt") == 0){
        char* label_else = new_label_name();
        char* label_endif = new_label_name();
        struct Code* code1 = translate_cond(node->head->next->next, NULL, label_else, 0, 1);
        struct Code* code2 = translate_stmt(node->head->next->next->next->next);
        struct Code* code3 = construct(10, label_endif, -1, NULL, NULL);
        struct Code* code4 = construct(0, label_else, -1, NULL, NULL);
        struct Code* code5 = translate_stmt(node->head->next->next->next->next->next->next);
        struct Code* code6 = construct(0, label_endif, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4), code5), code6);
    }
    else if(strcmp(son_list, "WHILELPExpRPStmt") == 0){
        char* label1 = new_label_name();
        char* label2 = new_label_name();
        struct Code* code1 = construct(0, label1, -1, NULL, NULL);
        struct Code* code2 = translate_cond(node->head->next->next, NULL, label2, 0, 1);
        struct Code* code3 = translate_stmt(node->head->next->next->next->next);
        struct Code* code4 = construct(10, label1, -1, NULL, NULL);
        struct Code* code5 = construct(0, label2, -1, NULL, NULL);
        return append_wo_tail(append_wo_tail(append_wo_tail(append_wo_tail(code1, code2), code3), code4), code5);
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
        printf("args--Seems that some unexpected things have happened!\n");
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
        printf("fundec--Seems that some unexpected things have happened!\n");
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
    if(strcmp(son_list, "INT") == 0){
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
        printf("specifier--Seems that some unexpected things have happened!--%s\n",son_list);
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
            return construct(13, var, -1, to_size(size), NULL);
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

Code* translate(struct Node* node, char* filename){
    //printf("Translation requires implementation, the name of the root is %s, the translation result will be output to %s\n", node->name, filename);
    struct Code* raw_code = translate_high_level_def(node);
    struct Code* optimized_code = optimize(raw_code);
    dump(optimized_code, filename);
    return optimized_code;
}

Code* parse_ir_file(FILE* file){
    Code* head = NULL;
    Code* tail = NULL;
    char* buffer = (char*)malloc(sizeof(char)*200);
    while(fgets(buffer, 200, file) != NULL){
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
        relop 0: <
        relop 1: <=
        relop 2: >
        relop 3: >=
        relop 4: !=
        relop 5: ==
        */
        Code* code = (Code*)malloc(sizeof(Code));
        char tokens[10][60];
        int i = 0;
        int j = 0;
        int k = 0;
        int len = strlen(buffer);
        if(buffer[len-2] == '\r' && buffer[len-1] == '\n'){
            buffer[len-2] = ' ';
            len --;
        }
        else if(buffer[len-1] == '\n'){
            buffer[len-1] = ' ';
        }
        while(i < len){
            if(buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n' || buffer[i] == '\r'){
                if(k != 0){
                    tokens[j][k] = '\0';
                    // printf("[%d:%s]", j, tokens[j]);
                    j++;
                    k = 0;
                }
            }
            else{
                tokens[j][k] = buffer[i];
                k++;
            }
            i++;
        }
        if(k != 0){
            tokens[j][k] = '\0';
            // printf("[%d:%s]", j, tokens[j]);
            j++;
            k = 0;
        }
        // printf("\n");
        if(strcmp(tokens[0], "LABEL") == 0){
            code->type = 0;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            strcpy(code->tk1, tokens[1]);
            code->tk2 = NULL;
            code->tk3 = NULL;
        }else if(strcmp(tokens[0], "FUNCTION") == 0){
            code->type = 1;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            strcpy(code->tk1, tokens[1]);
            code->tk2 = NULL;
            code->tk3 = NULL;
        }else if(strcmp(tokens[1], ":=") == 0){
            if(strcmp(tokens[2], "CALL") == 0){
                code->type = 16;
                code->tk1 = (char*)malloc(sizeof(char)*60);
                sprintf(code->tk1, "var_%s", tokens[0]);
                code->tk2 = (char*)malloc(sizeof(char)*60);
                strcpy(code->tk2, tokens[3]);
                code->tk3 = NULL;
            }else if(j == 3){
                if(tokens[0][0] == '*'){
                    code->type = 9;
                    code->tk1 = (char*)malloc(sizeof(char)*60);
                    sprintf(code->tk1, "var_%s", tokens[0]+1);
                    code->tk2 = (char*)malloc(sizeof(char)*60);
                    if(start_with_well(tokens[2])){
                        strcpy(code->tk2, tokens[2]);
                    }else{
                        sprintf(code->tk2, "var_%s", tokens[2]);
                    }
                    code->tk3 = NULL;
                }else if(tokens[2][0] == '&'){
                    code->type = 7;
                    code->tk1 = (char*)malloc(sizeof(char)*60);
                    sprintf(code->tk1, "var_%s", tokens[0]);
                    code->tk2 = (char*)malloc(sizeof(char)*60);
                    sprintf(code->tk2, "var_%s", tokens[2]+1);
                    code->tk3 = NULL;
                }else if(tokens[2][0] == '*'){
                    code->type = 8;
                    code->tk1 = (char*)malloc(sizeof(char)*60);
                    sprintf(code->tk1, "var_%s", tokens[0]);
                    code->tk2 = (char*)malloc(sizeof(char)*60);
                    sprintf(code->tk2, "var_%s", tokens[2]+1);
                    code->tk3 = NULL;
                }else{
                    code->type = 2;
                    code->tk1 = (char*)malloc(sizeof(char)*60);
                    sprintf(code->tk1, "var_%s", tokens[0]);
                    code->tk2 = (char*)malloc(sizeof(char)*60);
                    if(start_with_well(tokens[2])){
                        strcpy(code->tk2, tokens[2]);
                    }else{
                        sprintf(code->tk2, "var_%s", tokens[2]);
                    }
                    code->tk3 = NULL;
                }
            }else if(strcmp(tokens[3], "+") == 0){
                code->type = 3;
                code->tk1 = (char*)malloc(sizeof(char)*60);
                sprintf(code->tk1, "var_%s", tokens[0]);
                code->tk2 = (char*)malloc(sizeof(char)*60);
                if(start_with_well(tokens[2])){
                    strcpy(code->tk2, tokens[2]);
                }else{
                    sprintf(code->tk2, "var_%s", tokens[2]);
                }
                code->tk3 = (char*)malloc(sizeof(char)*60);
                if(start_with_well(tokens[4])){
                    strcpy(code->tk3, tokens[4]);
                }else{
                    sprintf(code->tk3, "var_%s", tokens[4]);
                }
            }else if(strcmp(tokens[3], "-") == 0){
                code->type = 4;
                code->tk1 = (char*)malloc(sizeof(char)*60);
                sprintf(code->tk1, "var_%s", tokens[0]);
                code->tk2 = (char*)malloc(sizeof(char)*60);
                if(start_with_well(tokens[2])){
                    strcpy(code->tk2, tokens[2]);
                }else{
                    sprintf(code->tk2, "var_%s", tokens[2]);
                }
                code->tk3 = (char*)malloc(sizeof(char)*60);
                if(start_with_well(tokens[4])){
                    strcpy(code->tk3, tokens[4]);
                }else{
                    sprintf(code->tk3, "var_%s", tokens[4]);
                }
            }else if(strcmp(tokens[3], "*") == 0){
                code->type = 5;
                code->tk1 = (char*)malloc(sizeof(char)*60);
                sprintf(code->tk1, "var_%s", tokens[0]);
                code->tk2 = (char*)malloc(sizeof(char)*60);
                if(start_with_well(tokens[2])){
                    strcpy(code->tk2, tokens[2]);
                }else{
                    sprintf(code->tk2, "var_%s", tokens[2]);
                }
                code->tk3 = (char*)malloc(sizeof(char)*60);
                if(start_with_well(tokens[4])){
                    strcpy(code->tk3, tokens[4]);
                }else{
                    sprintf(code->tk3, "var_%s", tokens[4]);
                }
            }else if(strcmp(tokens[3], "/") == 0){
                code->type = 6;
                code->tk1 = (char*)malloc(sizeof(char)*60);
                sprintf(code->tk1, "var_%s", tokens[0]);
                code->tk2 = (char*)malloc(sizeof(char)*60);
                if(start_with_well(tokens[2])){
                    strcpy(code->tk2, tokens[2]);
                }else{
                    sprintf(code->tk2, "var_%s", tokens[2]);
                }
                code->tk3 = (char*)malloc(sizeof(char)*60);
                if(start_with_well(tokens[4])){
                    strcpy(code->tk3, tokens[4]);
                }else{
                    sprintf(code->tk3, "var_%s", tokens[4]);
                }
            }
        }else if(strcmp(tokens[0], "GOTO") == 0){
            code->type = 10;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            strcpy(code->tk1, tokens[1]);
            code->tk2 = NULL;
            code->tk3 = NULL;
        }else if(strcmp(tokens[0], "IF") == 0){
            code->type = 11;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            if(start_with_well(tokens[1])){
                strcpy(code->tk1, tokens[1]);
            }else{
                sprintf(code->tk1, "var_%s", tokens[1]);
            }
            if(strcmp(tokens[2], "<") == 0){
                code->relop = 0;
            }else if(strcmp(tokens[2], "<=") == 0){
                code->relop = 1;
            }else if(strcmp(tokens[2], ">") == 0){
                code->relop = 2;
            }else if(strcmp(tokens[2], ">=") == 0){
                code->relop = 3;
            }else if(strcmp(tokens[2], "!=") == 0){
                code->relop = 4;
            }else if(strcmp(tokens[2], "==") == 0){
                code->relop = 5;
            }
            code->tk2 = (char*)malloc(sizeof(char)*60);
            if(start_with_well(tokens[3])){
                strcpy(code->tk2, tokens[3]);
            }else{
                sprintf(code->tk2, "var_%s", tokens[3]);
            }
            code->tk3 = (char*)malloc(sizeof(char)*60);
            strcpy(code->tk3, tokens[5]);
        }else if(strcmp(tokens[0], "RETURN") == 0){
            code->type = 12;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            if(start_with_well(tokens[1])){
                strcpy(code->tk1, tokens[1]);
            }else{
                sprintf(code->tk1, "var_%s", tokens[1]);
            }
            code->tk2 = NULL;
            code->tk3 = NULL;
        }else if(strcmp(tokens[0], "DEC") == 0){
            code->type = 13;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            sprintf(code->tk1, "var_%s", tokens[1]);
            code->tk2 = (char*)malloc(sizeof(char)*60);
            strcpy(code->tk2, tokens[2]);
            code->tk3 = NULL;
        }else if(strcmp(tokens[0], "PARAM") == 0){
            code->type = 14;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            if(start_with_well(tokens[1])){
                strcpy(code->tk1, tokens[1]);
            }else{
                sprintf(code->tk1, "var_%s", tokens[1]);
            }
            code->tk2 = NULL;
            code->tk3 = NULL;
        }else if(strcmp(tokens[0], "ARG") == 0){
            code->type = 15;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            if(start_with_well(tokens[1])){
                strcpy(code->tk1, tokens[1]);
            }else{
                sprintf(code->tk1, "var_%s", tokens[1]);
            }
            code->tk2 = NULL;
            code->tk3 = NULL;
        }else if(strcmp(tokens[0], "READ") == 0){
            code->type = 17;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            sprintf(code->tk1, "var_%s", tokens[1]);
            code->tk2 = NULL;
            code->tk3 = NULL;
        }else if(strcmp(tokens[0], "WRITE") == 0){
            code->type = 18;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            if(start_with_well(tokens[1])){
                strcpy(code->tk1, tokens[1]);
            }else{
                sprintf(code->tk1, "var_%s", tokens[1]);
            }
            code->tk2 = NULL;
            code->tk3 = NULL;
        }else{
            code->type = 0;
            code->tk1 = (char*)malloc(sizeof(char)*60);
            strcpy(code->tk1, tokens[1]);
            code->tk2 = NULL;
            code->tk3 = NULL;
        }
        if(head == NULL){
            head = code;
            tail = code;
        }else{
            tail->next = code;
            tail = code;
        }
    }
    // Code* tmp = head;
    // while(tmp != NULL){
    //     printf("%d %s %s %s\n", tmp->type, tmp->tk1, tmp->tk2, tmp->tk3);
    //     tmp = tmp->next;
    // }
    return head;
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
    int ENABLE_PRINT = 0;
    if(ENABLE_PRINT == 0)return;
    printf("node name: %s\n", node->name);
    printf("node value: %s\n", node->value);
    printf("node tmp_name: %s\n", node->tmp_name);
    printf("node son: %s\n\n", get_son_list(node));
}