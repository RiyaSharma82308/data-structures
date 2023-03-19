///// delete middle element of stack
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int* arr;
};
void push(struct stack* st,int ele)
{
    st->top++;
    st->arr[st->top]=ele;
}
int pop(struct stack* st)
{
    int x=st->arr[st->top];
    st->top--;
    return x;
}
void deletemiddle(struct stack* st, int mid)
{
    if(st->top==mid)
    {
        int a=pop(st);
        return;
    }
    else
    {
        int temp=pop(st);
        deletemiddle(st,mid);
        push(st,temp);
    }
}
void display(struct stack* st)
{
    while(st->top!=-1)
    {
        printf("%d ",st->arr[st->top]);
        st->top--;
    }
}
int main()
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=100;
    st->top=-1;
    st->arr=(int*)malloc(sizeof(int)*st->size);
    push(st,10);
    push(st,20);
    push(st,30);
    push(st,40);
    push(st,50);
    int ssize=st->top;
    // printf("%d",ssize);
    deletemiddle(st,ssize/2);
    display(st);
}