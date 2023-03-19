// stock span problem
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
int func(struct stack* st,int ele,int count)
{
    // printf("%d %d\n",st->arr[st->top],ele);
    if(ele <= st->arr[st->top]) 
    {
        // printf("%d\n",count);
        push(st,ele);
        return count;
    }
    else if(ele > st->arr[st->top])
    {
        int temp=pop(st);
        count++;
        int a= func(st,ele,count);
        // printf("vlaue of a is  %d\n",a);
        push(st,temp);
        return a;
        // printf("element pushed back %d\n",temp);
    }
}
int  main()
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=100;
    st->top=-1;
    st->arr=(int*)malloc(sizeof(int) * st->size);
    int array[7]={100, 80, 60, 70, 60, 75, 85};
    push(st,array[0]);
    array[0]=1;
    for(int i=1;i<7;i++)
    {
        int count=func(st,array[i],1);
        array[i]=count;
    }
    for(int i=0;i<7;i++)
    {
        printf("%d ",array[i]);
    }
}