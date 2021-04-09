//
// Created by Nihfkeol on 2021/4/9.
//

#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct qnode {
    DataType qnode *next;
} LinkListQ;

typedef struct {
    LinkListQ *front, *rear;
} LinkQueue;

LinkQueue *InitQueue();

int EmptyQueue(LinkListQ *Q);

void InQueue(LinkQueue *Q, DataType x);

int DeQueue(LinkQueue *Q, DataType *x);

int GetFront(LinkQueue *Q, DataType *x);

void ShowQueue(LinkQueue *Q);

void MenuQueue();


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
                printf("队列的初始化完成！");
                break;
            case '2':
                printf("请输入要入队的元素个数：");
                scanf("%d", &n);
                printf("请输入%d个整数进行入队：", n);
                for (i = 0; i < n; ++i) {
                    scanf("%d", &x);
                    InQueue(Q, x);
                }
                printf("入队操作完成");
                break;
            case '3':
                printf("请输入要出队的元素个数：");
                scanf("%d", &n);
                printf("出队的元素顺序依次为：");
                for (i = 0; i < n; ++i) {
                    flag = DeQueue(Q, &x);
                    printf("%5d", x);
                }
                if (flag == 1){
                    printf("\n出队操作成功!");
                } else{
                    printf("\n出队操作失败!");
                }
                break;
            case '4':
                if ((flag = GetFront(Q, &x)))
                    printf("当前的对头元素值为：%d",x);
                break;
            case '5':
                ShowQueue(Q);
                break;
            case '0':
                ch1 = 'n';
                break;
            default:
                printf("输入有误，请输入0~4进行选择！");
        }
        if (ch2 != '0'){
            printf("\n按回车键继续，按任意键返回主菜单！\n");
            a = getchar();
            if (a != '\xA'){
                getchar();
                ch1 = 'n';
            }
        }
    }
}


























