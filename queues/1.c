// circular queue implementatton;
#include<stdio.h>
#include<stdlib.h>
struct queue{
    int rear;
    int front;
    int size;
    int num;       // num is the number of elements in the queue at present
    int* arr;
};
struct queue* CreateQueue(int size)
{
    struct queue*  temp=(struct queue*)malloc(sizeof(struct queue));
    temp->size=size;
    temp->rear=-1;
    temp->front=-1;
    temp->num=0;
    temp->arr=(int*)malloc(sizeof(int));
    return temp;
}
int isfull(struct queue* Q)
{
    if(Q->num==Q->size) return 1;
    else return 0;
}
int isempty(struct queue* q)
{
    if(q->num==0) return 1;
    return 0;
}
void enqueue(struct queue* Q1,int n)
{
    if(isfull(Q1))
    {
        printf("cant enqueue ........ queue is full\n");
        return;
    }
    if(isempty(Q1))
    {
        Q1->front ++;
    }
    Q1->rear=(Q1->rear + 1)% Q1->size;
    Q1->arr[Q1->rear]=n;
    (Q1->num)++;
    printf("%d enqueued to queue\n",Q1->arr[Q1->rear]);
}
void dequeue(struct queue* q)
{
    if(isempty(q))
    {
        printf("cant dequeue......... queue is empty\n");
        return;
    }
    else
    {
        printf("dequeued element is %d\n",q->arr[q->front]);
        q->front=(q->front+1)% q->size;
        q->num=q->num -1;
    }
}
int main()
{
    struct queue* Q1=CreateQueue(3);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,1);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,2);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,3);
    printf("%d %d \n",Q1->front,Q1->rear);
    dequeue(Q1);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,4);
    printf("%d %d \n",Q1->front,Q1->rear);
    dequeue(Q1);
    printf("%d %d \n",Q1->front,Q1->rear);
    dequeue(Q1);
    printf("%d %d \n",Q1->front,Q1->rear);
    dequeue(Q1);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,10);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,20);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,30);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,40);
    printf("%d %d \n",Q1->front,Q1->rear);
    dequeue(Q1);
    printf("%d %d \n",Q1->front,Q1->rear);
    enqueue(Q1,40);
    printf("%d %d \n",Q1->front,Q1->rear);
}