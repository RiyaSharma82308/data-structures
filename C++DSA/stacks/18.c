// next greater element
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
void func(struct stack* st, int array[])
{
    for(int i=1;i<4;i++)
    {
        while(st->arr[st->top] < array[i])
        {
            int x=pop(st);
            printf("%d -----> %d\n",x,array[i]);
        }
        push(st,array[i]);
    }
    while(!(st->top==-1))
    {
        printf("%d -----> %d\n",st->arr[st->top],-1);
        pop(st);
    }
}
int main()
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=100;
    st->top=-1;
    st->arr=(int*)malloc(sizeof(int) * st->size);
    int array[4]={4 , 5 , 2 , 25};
    push(st,array[0]);
    func(st,array);
}
