// element having next greater frequency
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
void func(struct stack* st,int A[])
{
    int n=7;
    int maxi=-1;
    for(int i=0;i<n;i++)
    {
        if(A[i]>maxi)
        {
            maxi=A[i];
        }
    }
    int* freq=(int*)malloc(sizeof(int)*maxi);
    for(int i=0;i<n;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        freq[A[i]]++;
    }
    int final[n];
    push(st,0);
    for(int i=1;i<n;i++)
    {
        while(freq[A[i]]>freq[A[st->top]] )
        {
            int temp=pop(st);
            final[temp]=A[i];
        }
        push(st,i);
    }
    while(!(st->top==-1))
    {
        final[pop(st)]=-1;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ---> %d\n",A[i],final[i]);
    }
}
int main()
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=100;
    st->top=-1;
    st->arr=(int*)malloc(sizeof(int) * st->size);
    int A[]={1, 1, 2, 3, 4, 2, 1};
    func(st,A);
}