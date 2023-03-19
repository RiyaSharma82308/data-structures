///// stacks using arrays practice
#include<stdio.h>
#include<stdlib.h>
struct stacks
{
    int size;
    int top;
    int* arr;
};
int isempty(struct stacks* st)
{
    if(st->top==-1) return 1;
    return 0;
}
int isfull(struct stacks* st)
{
    if(st->top==st->size-1) return 1;
    return 0;
}
void push(struct stacks* st,int ele)
{
    if(isfull(st)) printf("stack is full.........cant push anymore elements\n");
    else
    {
        st->top++;
        st->arr[st->top]=ele;
    }
}
int pop(struct stacks* st)
{
    if(isempty(st)) printf("stack is empty.... cant pop any element\n");
    else
    {
        int x=st->arr[st->top];
        st->top--;
        return x;
    }
}
int peek(struct stacks* st,int pos)
{
    if((st->top-pos+1)<0) return -1;
    return st->arr[st->top-pos+1];
}
int main()
{
    struct stacks* st=(struct stacks*)malloc(sizeof(struct stacks));
    st->size=5;
    st->top=-1;
    // if(isempty(st)) printf("stack underflow\n");
    // if(isfull(st)) printf("stack overflow\n");
    push(st,20);
    printf("%d \n",st->top);
    printf("%d \n",st->arr[st->top]);
    if(isempty(st)) printf("stack underflow\n");
    if(isfull(st)) printf("stack overflow\n");
    push(st,40);
    printf("%d\n",st->top);
    int a=pop(st);
    // printf("%d\n",a);
    push(st,50);
    push(st,60);
    push(st,70);
    push(st,80);
    printf("the top position now is %d topmost element is %d\n",st->top,st->arr[st->top]);
    int b=peek(st,1);
    printf("peeked element is : %d\n",b);
    int c=peek(st,2);
    printf("peeked element is : %d\n",c);
    int d=peek(st,3);
    printf("peeked element is : %d\n",d);
    int e=peek(st,4);
    printf("peeked element is : %d\n",e);
    int f=peek(st,5);
    printf("peeked element is : %d\n",f);
}
