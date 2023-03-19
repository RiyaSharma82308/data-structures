////// infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int isoperator(char c)
{
    if(c=='+'|| c=='-' || c=='%' || c=='/' || c=='*') return 1;
    return 0;
}
int prec(char c)
{
    if(c=='+' || c=='-') return 1;
    else if(c=='*' || c=='/' || c=='%') return 2;
    else return 0;
}
int top(struct stack* st){
    return st->arr[st->top];
}
int main()
{
    char* infix="a+b*c-d";
    char*postfix=(char*)malloc(sizeof(char) * strlen(infix+1));
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=100;
    st->top=-1;
    st->arr=(char*)malloc(sizeof(char)*st->size);
    int j=0;
    for(int i=0;infix[i]!='\0';i++)
    {
        if(isoperator(infix[i]))
        {
            if(prec(infix[i])>prec(st->arr[st->top]))
            {
                push(st,infix[i]);
            }
            else
            {
                while(prec(infix[i])<=prec(st->arr[st->top]))
                {
                    char x=pop(st);
                    postfix[j++]=x;
                }
                push(st,infix[i]);
            }
        }
        else
        {
            postfix[j++]=infix[i];
        }
    }
    while(!(isempty(st)))
    {
        char x=pop(st);
        postfix[j++]=x;
    }
    postfix[j]='\0';
    for(int i=0;postfix[i]!='\0';i++)
    {
        printf("%c ",postfix[i]);
    }
}