//
// Created by Nihfkeol on 2021/4/9.
//

#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct qnode {
    DataType data;
    struct qnode *next;
} LinkListQ;

typedef struct {
    LinkListQ *front, *rear;
} LinkQueue;

LinkQueue *InitQueue(){
    LinkQueue *Q;
    LinkListQ *p;
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    p = (LinkListQ *)malloc(sizeof(LinkListQ));
    Q->front = p;
    Q->rear = p;
    return Q;
}

int EmptyQueue(LinkQueue *Q){
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

void InQueue(LinkQueue *Q, DataType x){
    LinkListQ *p;
    p = (LinkListQ *)malloc(sizeof(LinkListQ));
    p->data = x;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

int DeQueue(LinkQueue *Q, DataType *x){
    LinkListQ *p;
    if (EmptyQueue(Q)){
        printf("�ӿգ����ܳ���Ԫ�أ�");
        return 0;
    } else{
        p = Q -> front -> next;
        *x = p->data;
        Q->front->next=p->next;
        if(p->next==NULL){
            Q->rear=Q->front;
        }
        free(p);
        return 1;
    }
}

    int GetFront(LinkQueue *Q, DataType *x){
        if (EmptyQueue(Q)){
            printf("�ӿգ��޶�ͷԪ�أ�");
            return 0;
        } else{
            *x=Q->front->next->data;
            return 1;
        }
    }

    void ShowQueue(LinkQueue *Q){
        LinkListQ *p=Q->front->next;
        if (p==NULL){
            printf("����Ϊ�գ���Ԫ��");
        } else{
            printf("�Ӷ�ͷԪ�����Ԫ��Ϊ��");
            while (p!=NULL){
                printf("%5d",p->data);
                p=p->next;
            }
        }
    }

    void MenuQueue(){
        printf("\n               ������ϵͳ");
        printf("\n===========================================");
        printf("\n|              1--��ʼ������                  |");
        printf("\n|              2--��Ӳ���                    |");
        printf("\n|              3--���Ӳ���                    |");
        printf("\n|              4--���ͷԪ��                  |");
        printf("\n|              5--��ʾ��������Ԫ��             |");
        printf("\n|              0--����                       |");
        printf("\n===========================================");
        printf("\n������˵��ţ�0-5����");
    }


    void main() {
    int i, n, flag;
    LinkQueue *Q;
    DataType x;
    char ch1, ch2, a;
    ch1 = 'y';
    while (ch1 == 'y' || ch1 == 'Y') {
        MenuQueue();
        scanf("%c", &ch2);
        getchar();
        switch (ch2) {
            case '1':
                Q = InitQueue();
                printf("���еĳ�ʼ����ɣ�");
                break;
            case '2':
                printf("������Ҫ��ӵ�Ԫ�ظ�����");
                scanf("%d", &n);
                printf("������%d������������ӣ�", n);
                for (i = 0; i < n; ++i) {
                    scanf("%d", &x);
                    InQueue(Q, x);
                }
                printf("��Ӳ������");
                break;
            case '3':
                printf("������Ҫ���ӵ�Ԫ�ظ�����");
                scanf("%d", &n);
                printf("���ӵ�Ԫ��˳������Ϊ��");
                for (i = 0; i < n; ++i) {
                    flag = DeQueue(Q, &x);
                    printf("%5d", x);
                }
                if (flag == 1){
                    printf("\n���Ӳ����ɹ�!");
                } else{
                    printf("\n���Ӳ���ʧ��!");
                }
                break;
            case '4':
                if ((flag = GetFront(Q, &x)))
                    printf("��ǰ�Ķ�ͷԪ��ֵΪ��%d",x);
                break;
            case '5':
                ShowQueue(Q);
                break;
            case '0':
                ch1 = 'n';
                break;
            default:
                printf("��������������0~4����ѡ��");
        }
        if (ch2 != '0'){
            printf("\n���س�����������������������˵���\n");
            a = getchar();
            if (a != '\xA'){
                getchar();
                ch1 = 'n';
            }
        }
    }
}


























