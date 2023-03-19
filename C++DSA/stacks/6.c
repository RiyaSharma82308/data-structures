#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char* arr;
};
int isempty(struct stack* st)
{
    if(st->top==-1) return 1;
    return 0;
}
int isfull(struct stack* st)
{
    if(st->top==st->size-1) return 1;
    return 0;
}
void push(struct stack* st,int ele)
{
    if(isfull(st)) printf("stack overflow\n");
    else
    {
        st->top++;
        st->arr[st->top]=ele;
    }
}
char pop(struct stack* st)
{
    if(isempty(st)) return '1';
    else
    {
        struct stack* s=st;
        char x=s->arr[s->top];
        st->top--;
        return x;
    }
}
int main()
{
    int p=1;
    char* exp="[{(2*3)+9}])";
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=100;
    st->top=-1;
    st->arr=(char*)malloc(sizeof(char)*st->size);
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' || exp[i]=='<') push(st,exp[i]);
        else if(exp[i]==')')
        {
            char a=pop(st);
            if(a!='(')
            {
                p=0;
                printf("invalid parenthesis\n");
                break;
            }
        }
        else if(exp[i]=='}')
        {
            char a=pop(st);
            if(a!='{')
            {
                p=0;
                printf("invalid parenthesis\n");
                break;
            }
        }
        else if(exp[i]==']')
        {
            char a=pop(st);
            if(a!='[')
            {
                p=0;
                printf("invalid parenthesis\n");
                break;
            }
        }
        else if(exp[i]=='>')
        {
            char a=pop(st);
            if(a!='<')
            {
                p=0;
                printf("invalid parenthesis\n");
                break;
            }
        }
    }
    if(p==1)
    {
        if(isempty(st)) printf("valid parenthesis \n");
        else printf("invalid parenthesis \n");
    }
}