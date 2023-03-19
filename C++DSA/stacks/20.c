// Maximum product of indexes of next greater on left and right
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
void leftindex(int left[],int array[])
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=10;
    st->arr=(int*)malloc(sizeof(int)*st->size);
    push(st,0);
    left[0]=0;
    for(int i=1;i<5;i++)
    {
        while((array[st->arr[st->top]] <= array[i]) && (st->top>=0))
        {
            int a=pop(st);
            if (st->top==-1) break;
        }
        if(st->top==-1) 
        {
            left[i]=0;
        }
        else
        {
            left[i]=st->arr[st->top]+1;
        }
        push(st,i);
    }
}
void rightindex(int right[],int array[])
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=10;
    st->arr=(int*)malloc(sizeof(int)*st->size);
    push(st,0);
    for(int i=1;i<5;i++)
    {
        while(array[i]>array[st->arr[st->top] ])
        {
            int a=pop(st);
            right[a]=i+1;
        }
        push(st,i);
    }
    while(st->top>=0)
    {
        int a=pop(st);
        right[a]=0;
    }
}
int main()
{
    int* left=(int*)malloc(sizeof(int)*5);
    int* right=(int*)malloc(sizeof(int)*5);
    int array[5]={5, 4, 3, 4, 5};
    leftindex(left,array);
    rightindex(right,array);
    // printf("hi");
    for(int i=0;i<5;i++)
    {

        printf("%d  \n",left[i]*right[i]);
    }
}