// iterative tower of hanoi
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
void auxdes(struct stack* auxiliary,struct stack* destination)
{
    if(auxiliary->arr[auxiliary->top] <= destination->arr[destination->top])
    {
        push(destination,auxiliary->arr[auxiliary->top]);
        pop(auxiliary);
    }
    else
    {
        push(auxiliary,destination->arr[destination->top]);
        pop(destination);
    }
}
void soudes(struct stack* source,struct stack* destination)
{
    if(source->arr[source->top] <= destination->arr[destination->top])
    {
        push(destination,source->arr[source->top]);
        pop(source);
    }
    else
    {
        push(source,destination->arr[destination->top]);
        pop(destination);
    }
}
void souaux(struct stack* source,struct stack* auxiliary)
{
    if(source->arr[source->top] <= auxiliary->arr[auxiliary->top])
    {
        push(auxiliary,source->arr[source->top]);
        pop(source);
    }
    else
    {
        push(source,auxiliary->arr[auxiliary->top]);
        pop(auxiliary);
    }
}

void func(int arr[],int n)
{
    struct stack* source=(struct stack*)malloc(sizeof(struct stack));
    source->size=n;
    source->top=-1;
    source->arr=(int*)malloc(sizeof(int) * source->size);
    struct stack* auxiliary=(struct stack*)malloc(sizeof(struct stack));
    auxiliary->size=n;
    auxiliary->top=-1;
    auxiliary->arr=(int*)malloc(sizeof(int) * auxiliary->size);
    struct stack* destination=(struct stack*)malloc(sizeof(struct stack));
    destination->size=n;
    destination->top=-1;
    destination->arr=(int*)malloc(sizeof(int) * destination->size);
    int size=n;
    for(int i=size-1;i>=0;i--)
    {
        push(source,arr[i]);
    }
    for(int i=1;i<=pow(2,n)-1;i++)
    {
        if(i%3==0)
        {
            auxdes(auxiliary,destination);
        }
        else if(i%3==1)
        {
            soudes(source,destination);
        }
        else if(i%3==2)
        {
            souaux(source,auxiliary);
        }
        // printf("%d\n",i);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",pop(destination));
    }

}
int main()
{
    int arr[5]={1,2,3,4,5};
    func(arr,5);

}