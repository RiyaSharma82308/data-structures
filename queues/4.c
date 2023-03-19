// linked list representation of queue
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* front;
    struct node* rear;
    struct node* next;
};
struct node* CreateQueue()
{
    struct node* q=(struct node*)malloc(sizeof(struct node));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
struct node* newNode(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    return temp;
}
void enqueue(struct node* q,int d)
{
    struct node* temp=newNode(d);
    if(q->rear==NULL)
    {
        q->rear=temp;
        q->front=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}
int dequeue(struct node* q)
{
    if(q->front==NULL) return -1;
    struct node* temp=q->front;
    int a=q->front->data;
    q->front=q->front->next;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    free(temp);
    return a;
}
int main()
{
    struct node* q1=CreateQueue();
    enqueue(q1,10);
    enqueue(q1,20);
    enqueue(q1,30);
    int a=dequeue(q1);
    printf("%d\n",a);
    int b=dequeue(q1);
    printf("%d\n",b);
    int c=dequeue(q1);
    printf("%d\n",c);
    int d=dequeue(q1);
    printf("%d\n",d);
}