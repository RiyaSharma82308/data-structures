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
void deletes(struct stack* st,int k,int  arr[])
{
    for(int i=1;i<5;i++)
    {
        while(arr[i] > st->arr[st->top] && k>0)
        {
            int t=pop(st);
            --k;
        }
        push(st,arr[i]);
    }
}
void display(struct stack* st)
{
    if(st->top==-1) return;
    int temp=st->arr[st->top];
    st->top--;
    display(st);
    printf("%d ",temp);
}
int main()
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=5;
    st->top=-1;
    st->arr=(int*)malloc(sizeof(int)*st->size);
    int arr[5]={20, 10, 25, 30, 40};
    push(st,arr[0]);
    deletes(st,2,arr);
    display(st);
}

//20, 10, 25, 30, 40
// 3, 100, 1
// 23, 45, 11, 77, 18