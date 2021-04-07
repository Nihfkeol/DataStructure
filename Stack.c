            default：
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
    printf("\n                      栈子系统");
    printf("\n =======================================================");
    printf("\n |                1------初始化栈");
    printf("\n |                2------入栈操作");
    printf("\n |                3------出栈操作");
    printf("\n |                4------求栈顶元素");
    printf("\n |                5------显示栈中元素");
    printf("\n |                6------十、二进制数转换");
    printf("\n |                7------表达式转换并求值");
    printf("\n |                0------返回");
    printf("\n =======================================================");
    printf("\n 请输入菜单号（0-7）");
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
                printf("栈的初始化完成");
                break;
            case '2':
                printf("请输入要入栈的元素个数：");
                scanf("%d", &n);
                printf("请输入%d个整数进行入栈", n);
                for (int i = 0; i < n; ++i) {
                    scanf("%d", &x);
                    S = Push(S, x);
                }
                printf("入栈成功");
                break;
            case '3':
                printf("请输入要出栈的元素个数：");
                scanf("%d", &n);
                printf("出栈的元素为：")
                for (int i = 0; i < i; ++i) {
                    S = Pop(S, &x);
                    if (S != NULL) {
                        printf("%5d", x);
                    }
                }
                break;
            case '4':
                if (flag = GetTop(S, &x));
                printf("当前的栈顶元素为：%d", x);
                break;
            case '5':
                ShowStack(S);
                break;
            case '6':
                S = InitStack();
                printf("请输入十进制正整数：");
                scanf("%d", &x);
                D_B(S, x);
                break;
            case '7':
                printf("请输入算术表达式（只有+、-、*、/四种运算符），以‘#’结束：");
                scanf("%s", &exp);
                trans(exp, postexp);
                printf("则该表达式的中缀表达式为：%s\n", exp);
                printf("转换之后的后缀表达式为（每个操作数用“#”分隔）：%s\n", postexp);
                printf("表达式的值为:%.2f\n", compvalue(postexp));
                break;
            case '0':
                ch1 = 'n';
                break;
            default:
                printf("输入有误，请输入0-5进行选择！");
        }
        if (ch2 != '0')
        {
            printf("\n按回车键继续，按任意键返回主菜单！\n");
            a = getchar();
            if (a!='\xA'){
                getchar();
                ch1 = 'n';
            }
        }
    }
}