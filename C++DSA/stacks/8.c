/// infix to postfix includes every aspect
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stacks
{
    int size;
    int top;
    char* arr;
};
int isoperand(char ch)
{
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z') return 1;
    return 0;
}
void push(struct stacks* st,char ch)
{
    st->top++;
    st->arr[st->top]=ch;
}
char pop(struct stacks* st)
{
    char ch=st->arr[st->top];
    st->top--;
    return ch;
}
int precedence(char ch)
{
    if(ch=='(') return 0;
    else if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/' || ch=='%') return 2;
    else if(ch=='^') return 3;
}
char top(struct stacks* st)
{
    return st->arr[st->top];
}
int isempty(struct stacks* st)
{
    if(st->top==-1) return 1;
    return 0;
}
void infixtopostfix(char* infix)
{
    struct stacks* st=(struct stacks*)malloc(sizeof(struct stacks));
    st->size=100;
    st->top=-1;
    st->arr=(char*)malloc(sizeof(char) * st->size);
    char* postfix=(char*)malloc(sizeof(char)*strlen(infix));
    int k=-1;
    for(int i=0;infix[i]!='\0';i++)
    {
        if(isoperand(infix[i])) postfix[++k]=infix[i];
        else
        {
            if(infix[i]=='(') 
            {
                push(st,'(');
            }
            else if(infix[i]==')')
            {
                while(top(st)!='(' && !isempty(st))
                {
                    postfix[++k]=pop(st);
                }
                if(top(st)=='(')
                {
                    char x=pop(st);
                }
                else
                {
                    printf("invalid empression");
                    break;
                } 
            }
            else
            {
                while(precedence(infix[i])<=precedence(top(st)) && !isempty(st))
                {
                    postfix[++k]=pop(st);
                }
                push(st,infix[i]);
            }
        }
    }
    while(!isempty(st)) postfix[++k]=pop(st);
    postfix[++k]='\0';
    printf("%s ",postfix);
}
int main()
{
    char* infix="a+b*(c^d-e)^(f+g*h)-i";
    infixtopostfix(infix);
}