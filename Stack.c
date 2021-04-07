//
// Created by Nihfkeol on 2021/4/7.
//

# include "stdio.h"
# include "malloc.h"

#define MAXSIZE 100
typedef int DataType;
typedef struct stacknode {
    DataType data;
    struct stacknode *next;
} LinkStack;

LinkStack *InitStack() {
    LinkStack *S;
    S = NULL;
    return S;
}

int EmptyStack(LinkStack *S) {
    if (S == NULL) {
        return 1;
    } else {
        return 0;
    }
}

LinkStack *Push(LinkStack *S, DataType x) {
    LinkStack *p;
    p = (LinkStack *) malloc(sizeof(LinkStack));
    p->data = x;
    p->next = S;
    S = p;
    return S;
}

LinkStack *Pop(LinkStack *S, DataType *x) {
    LinkStack *p;
    if (EmptyStack(S)) {
        printf("\t栈空，不能出栈！");
        return NULL;
    } else {
        *x = S->data;
        p = S;
        S = S->next;
        free(p);
        return s;
    }
}

int GetTop(LinkStack *S, DataType *x) {
    if (EmptyStack(S)) {
        printf("栈空！");
        return 0;
    } else {
        *x = S->data;
        return 1;
    }
}

void ShowStack(LinkStack *S) {
    LinkStack *p = S;
    if (p == NULL) {
        printf("栈空！");
    } else {
        printf("从栈顶元素起栈中各元素为：");
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
    }
}

void D_B(LinkStack *S, DataType x) {
    while (x) {
        S = Push(S, x % 2);
        x /= 2;
    }
    printf("转换后二进制为：");
    while (!EmptyStack(S)) {
        S = Pop(S, &x);
        printf("%d", x)
    }
}

void trans(char *exp, char *postexp){
    struct {
        char data[MAXSIZE];
        int top;
    } op;
    int i = 0;
    op.top=-1;
    while (*exp!='#'){
        switch (*exp) {
            case '(':
                op.top++;
                op.data[op.top] = *exp;
                exp++;
                break;
            case ')':
                while (op.data[op.top]!='('){
                    postexp[i++] = op.data[op.top];
