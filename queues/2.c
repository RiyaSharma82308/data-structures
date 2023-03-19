// implement queue using 2 stacks
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int* arr;
};
int isfull(struct stack* S)
{
    if(S->top ==(S->size)-1) return 1;
    return 0;
}
int isempty(struct stack* S)
{
    if(S->top==-1) return 1;
    return 0;
}
void push(struct stack* S,int a)
{
    if(isfull(S)) return;
    else
    {
        S->top=S->top+1;
        S->arr[S->top]=a;
    }
}
int pop(struct stack* S)
{
    if(isempty(S)) return -1;
    else
    {
        int a=S->arr[S->top];
        S->top=S->top-1;
        return a;
    }
}
void enqueue(int d,struct stack* S1,struct stack* S2)
{
    if(isfull(S1)) return;
    else
    {
        while(!isempty(S1))
        {
            int a=pop(S1);
            push(S2,a);
        }
        push(S1,d);
        while(!isempty(S2))
        {
            int a=pop(S2);
            push(S1,a);
        }
    }
}
int dequeue(struct stack* S)
{
    if(isempty(S)) return -1;
    else{
        int a=pop(S);
        return a;
    }
}
int main()
{
    struct stack* S1=(struct stack*)malloc(sizeof(struct stack));
    S1->arr=(int*)malloc(sizeof(int));
    S1->top=-1;
    S1->size=5;
    struct stack* S2=(struct stack*)malloc(sizeof(struct stack));
    S2->arr=(int*)malloc(sizeof(int));
    S2->top=-1;
    S2->size=5;
    enqueue(10,S1,S2);
    enqueue(20,S1,S2);
    enqueue(30,S1,S2);
    int a=dequeue(S1);
    printf("%d\n",a);
    int b=dequeue(S1);
    printf("%d\n",b);
    int c=dequeue(S1);
    printf("%d\n",c);
    int d=dequeue(S1);
    printf("%d\n",d);
}