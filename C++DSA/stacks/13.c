/// sort stack using temporary stack
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
void push(struct stack* st,int x)
{
    st->top++;
    st->arr[st->top]=x;
}
int pop(struct stack* st)
{
    int x=st->arr[st->top];
    st->top--;
    return x;
}
void func(struct stack* st,int ele)
{
    // printf("%d\n",st->top);
    if((st)->top==-1)
    {
        // printf("hi\n");
        push(st,ele);
    }   
    else
    {
        // printf("hi\n");
        if(ele > (st)->arr[(st)->top])
        {
            int temp=pop(st);
            func(st,ele);
            push(st,temp);
        }
        else
        {
            push(st,ele);
        }
    }
}
struct stack* sort(struct stack* st)
{
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    temp->size=100;
    temp->top=-1;
    temp->arr=(int*)malloc(sizeof(int)*temp->size);
    // printf("hi\n");
    while(st->top!=-1)
    {
        // printf("hi\n");
        int a=pop(st);
        // printf("%d\n",temp->top);
        func(temp,a);
        // printf("hi\n");
    }
    // while(temp->top!=-1)
    // {
    //     printf("%d ",temp->arr[temp->top]);
    //     temp->top--;
    // }
    return temp;
}
int main()
{
    struct stack* st=(struct stack*) malloc(sizeof(struct stack));
    st->top=-1;
    st->size=100;
    st->arr=(int*) malloc(sizeof(int)* st->size);
    push(st,1);
    push(st,100);
    push(st,35);
    push(st,23);
    push(st,30);
    // printf("%d",st->top);
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    temp=sort(st);
    // printf("%d",temp->top);
    while(temp->top!=-1)
    {
        printf("%d ",temp->arr[temp->top]);
        temp->top--;
    }
}