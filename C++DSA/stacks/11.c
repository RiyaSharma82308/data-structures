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
        st->arr[++st->top]=val;
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
void insert(struct stacks* st,int ele)
{
    if(isempty(st))
    {
        push(st,ele);
    }
    else
    {
        int temp=pop(st);
        insert(st,ele);
        push(st,temp);
    }
}
void func(struct stacks* st)
{
    // printf("%d\n",st->top);
    if(!isempty(st))
    {
        int temp=pop(st);
        func(st);
        insert(st,temp);
    }
}
void print(struct stacks* st)
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
    struct stacks* st=(struct stacks*)malloc(sizeof(struct stacks));
    st->size=10;
    st->top=-1;
    st->arr=(int*)malloc(sizeof(int) * st->size);
    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    func(st);
    print(st);
}