//
// Created by Nihfkeol on 2021/4/7.
//
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
        while(op.data[op.top]=='*'||op.top.data[op.top]=='/')
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
                st.data[st.top];
                break;
            case '*':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b*a;
                st.top++;
                st.data[st.top];
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
                    printf("\n\t除零错误！\n");
                break;

