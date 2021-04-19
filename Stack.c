
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
        printf("\tջ�գ����ܳ�ջ��");
        return NULL;
    } else {
        *x = S->data;
        p = S;
        S = S->next;
        free(p);
        return S;
    }
}

int GetTop(LinkStack *S, DataType *x) {
    if (EmptyStack(S)) {
        printf("ջ�գ�");
        return 0;
    } else {
        *x = S->data;
        return 1;
    }
}

void ShowStack(LinkStack *S) {
    LinkStack *p = S;
    if (p == NULL) {
        printf("ջ�գ�");
    } else {
        printf("��ջ��Ԫ����ջ�и�Ԫ��Ϊ��");
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
    printf("ת���������Ϊ��");
    while (!EmptyStack(S)) {
        S = Pop(S, &x);
        printf("%d", x);
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
        op.top--;
    }
    op.top--;exp++;
    break;
    case '+':
    case '-':
        while(op.top!=-1&&op.data[op.top]!='(')
        {
            postexp[i++]=op.data[op.top];

            op.top--;
        }
        op.top++;
        op.data[op.top]=*exp;
        exp++;
        break;
    case'*':
    case'/':
        while(op.data[op.top]=='*'||op.data[op.top]=='/')
        {
         postexp[i++]=op.data[op.top];
         op.top--;
        }
        op.top++;
        op.data[op.top]=*exp;
        exp++;
        break;
    case' ':break;
    default:
        while(*exp>='0'&&*exp<='9')
        {
            postexp[i++]=*exp;
            exp++;
        }
        postexp[i++]='#';
    }
}
    while(op.top!=-1)
    {
        postexp[i++]=op.data[op.top];
        op.top--;
    }
    postexp[i]='\0';
}
float compvalue(char *postexp){
    struct{
     float data[MAXSIZE];
     int top;
    }st;
    float a,b,c,d;
    st.top=-1;
    while (*postexp !='\0'){
        switch (*postexp) {
            case '+':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b+a;
                st.top++;
                st.data[st.top]=c;
                break;
            case '-':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b-a;
                st.top++;
                st.data[st.top] = c;
                break;
            case '*':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b*a;
                st.top++;
                st.data[st.top] = c;
                break;
            case '/':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                if (a!=0)
                {
                    c=b/a;
                    st.top++;
                    st.data[st.top]=c;
                } else
                    printf("\n\t�������\n");
                break;

            default:
                d = 0;
                while(*postexp >= '0' && *postexp <= '9'){
                    d = 10*d + *postexp - '0';
                    postexp++;
                }
                st.top++;
                st.data[st.top] = d;
                break;
        }
        postexp++;
    }
    return st.data[st.top];
}



void MenuStack(){
    printf("\n                      ջ��ϵͳ");
    printf("\n =======================================================");
    printf("\n |                1------��ʼ��ջ");
    printf("\n |                2------��ջ����");
    printf("\n |                3------��ջ����");
    printf("\n |                4------��ջ��Ԫ��");
    printf("\n |                5------��ʾջ��Ԫ��");
    printf("\n |                6------ʮ����������ת��");
    printf("\n |                7------���ʽת������ֵ");
    printf("\n |                0------����");
    printf("\n =======================================================");
    printf("\n ������˵��ţ�0-7��");
}
main(){
    int i,n,flag;
    LinkStack *S;
    DataType x;
    char ch1,ch2,a;
    char exp[MAXSIZE],postexp[MAXSIZE];
    ch1 = 'y';
    while (ch1 == 'y' || ch1 == 'Y'){
        MenuStack();
        scanf("%c",&ch2);
        getchar();
        switch (ch2) {
            case '1':
                S = InitStack();
                printf("ջ�ĳ�ʼ�����");
                break;
            case '2':
                printf("������Ҫ��ջ��Ԫ�ظ�����");
                scanf("%d", &n);
                printf("������%d������������ջ", n);
                for (int i = 0; i < n; ++i) {
                    scanf("%d", &x);
                    S = Push(S, x);
                }
                printf("��ջ�ɹ�");
                break;
            case '3':
                printf("������Ҫ��ջ��Ԫ�ظ�����");
                scanf("%d", &n);
                printf("��ջ��Ԫ��Ϊ��");
                for(int i = 0; i < n; ++i) {
                    S = Pop(S, &x);
                    if (S != NULL) {
                        printf("%5d", x);
                    }
                }
                break;
            case '4':
                if (flag = GetTop(S, &x))
                    printf("��ǰ��ջ��Ԫ��Ϊ��%d", x);
                break;
            case '5':
                ShowStack(S);
                break;
            case '6':
                S = InitStack();
                printf("������ʮ������������");
                scanf("%d", &x);
                D_B(S, x);
                break;
            case '7':
                printf("�������������ʽ��ֻ��+��-��*��/��������������ԡ�#��������");
                scanf("%s", &exp);
                trans(exp, postexp);
                printf("��ñ��ʽ����׺���ʽΪ��%s\n", exp);
                printf("ת��֮��ĺ�׺���ʽΪ��ÿ���������á�#���ָ�����%s\n", postexp);
                printf("���ʽ��ֵΪ:%.2f\n", compvalue(postexp));
                break;
            case '0':
                ch1 = 'n';
                break;
            default:
                printf("��������������0-5����ѡ��");
        }
        if (ch2 != '0')
        {
            printf("\n���س�����������������������˵���\n");
            a = getchar();
            if (a!='\xA'){
                getchar();
                ch1 = 'n';
            }
        }
    }
}
