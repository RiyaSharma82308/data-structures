// stacks using linked list practice
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack* next;
};
void traversal(struct stack* top)
{
    struct stack* st=top;
    while(st!=NULL) 
    { 
        printf("%d ",st->data);
        st=st->next;
    }
    printf("\n");
}
int isempty(struct stack* top)
{
    if(top==NULL) return 1;
    return 0;
}
int isfull(struct stack* top)
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    if(st==NULL) return 1;
    return 0;
}
struct stack* push(struct stack* top,int ele)
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    if(isfull(st)) printf("stack is full cant push any elements\n");
    else{
        st->data=ele;
        st->next=top;
        top=st;
    }
    return st;
}
int pop(struct stack** top)
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    if(isempty(*top)) 
    {
        printf("stack empty cant pop any other element\n");
        return -1;
    }
    else
    {
        st=*top;
        *top=(*top)->next;
        int x=st->data;
        free(st);
        return x;
    }
}
int peek(struct stack* top,int position)
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st=top;
    for(int i=0;(i<position-1 && st!=NULL) ;i++)
    {
        st=st->next;
    }
    return st->data;
}
int main()
{
    struct stack* top=(struct stack*)malloc(sizeof(struct stack));
    top=NULL;
    if(isempty(top)) printf("empty stack\n");
    if(isfull(top)) printf("stack full\n");
    top=push(top,10);
    printf("%d\n",top->data);
    if(isempty(top)) printf("empty stack\n");
    if(isfull(top)) printf("stack full\n");
    top=push(top,20);
    top=push(top,30);
    top=push(top,40);
    traversal(top);
    // int a=pop(&top);
    // traversal(top);
    // int b=pop(&top);
    // traversal(top);
    // int c=pop(&top);
    // traversal(top);
    // int d=pop(&top);
    // traversal(top);
    // int e=pop(&top);
    // traversal(top);
    int f=peek(top,3);
    printf("%d\n",f);
}