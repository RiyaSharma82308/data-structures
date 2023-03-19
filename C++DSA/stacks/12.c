///// sorting a stack using recursion
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int* arr;
};
int pop(struct stack* st)
{
    int c=st->arr[st->top];
    st->top--;
    return c;
}
void push(struct stack* st,int val)
{
    st->top++;
    st->arr[st->top]=val;
}
int isempty(struct stack* st)
{
    if(st->top==-1) return 1;
    return 0;
}
void insert(struct stack* st,int val)
{
    if(isempty(st)) push(st,val);
    else
    {
        if(val < st->arr[st->top])
        {
            int temp=pop(st);
            insert(st,val);
            push(st,temp);
        }
        else
        {
            push(st,val);
        }
    }
}
void func(struct stack* st)
{
    if(isempty(st)) return;
    int temp=pop(st);
    func(st);
    insert(st,temp);
}
void print(struct stack* st)
{
    while(st->top!=-1)
    {
        printf("position %d: %d\n",st->top,st->arr[st->top]);
        st->top--;
    }
    printf("\n");
}
int main()
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=10;
    st->top=-1;
    st->arr=(int*)malloc(sizeof(int)*st->size);
    push(st,1);
    push(st,10);
    push(st,3);
    push(st,5);
    push(st,22);
    func(st);
    print(st);
}