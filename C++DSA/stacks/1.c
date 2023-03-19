// stacks using arrays
#include<stdio.h>
#include<stdlib.h>
struct stacks
{
    int size;
    int top;
    int* arr;
};
int isempty(struct stacks *st)
{
    if(st->top==-1) return 1;
    return 0;
}
int isfull(struct stacks *st)
{
    if(st->top==st->size-1) return 1;
    return 0;
}
void push(struct stacks* st,int val)
{
    if(isfull(st)) printf("Stack overflow\n");
    else{
        st->top++;
        st->arr[st->top]=val;
    }
}
int pop(struct stacks* st)
{
    if(isempty(st)) printf("stack underflow\n");
    else{
        int v=st->arr[st->top];
        st->top--;
        return v;
    }
}
int peek(struct stacks* st,int i)
{
    if(st->top-i+1 < 0) printf("invalid value of i");
    else return st->arr[st->top-i+1];
}
int top(struct stacks* st)
{
    return st->arr[st->top];
}
int bottom(struct stacks* st)
{
    return st->arr[0];
}
int main()
{
    struct stacks *st1=(struct stacks*)malloc(sizeof(struct stacks));
    st1->size=10;
    st1->top=-1;
    st1->arr=(int*)malloc(sizeof(int) * st1->size);
    printf("top is: %d\n",st1->top);
    push(st1,20);
    printf("top is: %d\n",st1->top);
    push(st1,22);
    printf("top is: %d\n",st1->top);
    push(st1,23);
    printf("top is: %d\n",st1->top);
    push(st1,24);
    printf("top is: %d\n",st1->top);
    push(st1,24);
    printf("top is: %d\n",st1->top);
    push(st1,24);
    printf("top is: %d\n",st1->top);
    if(isempty(st1)) printf("empty stack\n");
    if(isfull(st1)) printf("full stack\n");
    int a=pop(st1);
    int b=pop(st1);
    int c=pop(st1);
    int d=pop(st1);
    printf("top is(after pop): %d\n",st1->top);
    if(isempty(st1)) printf("empty stack\n");
    if(isfull(st1)) printf("full stack\n");
    for(int i=1;i<=st1->top+1;i++)
    {
        printf("%d\n", peek(st1,i));
    }
    // int x=top(st1);
    // int y=bottom(st1);
    printf("the top most value of the stack is: %d\n", top(st1));
    printf("the bottom most value of the stack is: %d\n", bottom(st1));
}