// stacks code with harry
#include<stdio.h>
#include<stdlib.h>
struct stacks
{
    int size;
    int top;
    int* arr;
};
int isempty(struct stacks *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stacks *s)
{
    if(s->top==s->size-1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    struct stacks *s;
    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));
    // s->arr[0]=10;
    // s->top++;
    // s->arr[0]=10;
    // s->top++;
    // s->arr[0]=10;
    // s->top++;
    // s->arr[0]=10;
    // s->top++;
    // s->arr[0]=10;
    // s->top++;
    if(isempty(s)) printf("stack empty\n");
    else printf("stack isnt empty\n");
    if(isfull(s)) printf("stack is full\n");
    else printf("stack is not full\n");
}