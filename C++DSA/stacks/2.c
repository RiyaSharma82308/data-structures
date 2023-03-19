// stacks using linked lists
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void traversal(struct Node* top)
{
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n=top;
    while(n!=NULL)
    {
        printf("%d ",n->data);
        n=n->next;
    }
    printf("\n");
}
int isempty(struct Node* top)
{
    if(top==NULL) return 1;
    return 0;
}
int isfull(struct Node* top)
{
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL) return 1;
    return 0;
}
struct Node* push(struct Node* top,int ele)
{
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL) printf("stack overflow\n");
    else
    {
        n->data=ele;
        n->next=top;
        top=n;
    }
    return top;
}
int pop(struct Node** top)
{
    if(isempty(*top)) printf("stack underflow\n");
    else
    {
        struct Node* s=(*top);
        *top=(*top)->next;
        int a=s->data;
        free(s);
        return a;
    }
}
int peek(int position,struct Node* top)
{
    for(int i=0;(i<(position-1) && top!=NULL);i++) 
    {
        top=top->next;
    }
    if(top!=NULL) return top->data;
    return -1;
}
int topmost(struct Node* top)
{
    return top->data;
}
int main()
{
    struct Node* top=(struct Node*)malloc(sizeof(struct Node));
    top=NULL;
    if(isempty(top)) printf("stack underflow\n");
    if(isfull(top)) printf("stack overflow\n");
    top=push(top,20);
    traversal(top);
    int x=pop(&top);
    printf("popped element is %d\n",x);
    top=push(top,50);
    top=push(top,100);
    traversal(top);
    int y=peek(3,top);
    printf("%d\n",y);
    int z=topmost(top);
    printf("%d ",z);
}