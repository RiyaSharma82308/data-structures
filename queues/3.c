// implement stack using 2 queues
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int front;
    int rear;
    int size;
    int capacity;
    int* arr;
};
struct queue* CreateQueue(int n)
{
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    q->size=0;
    q->capacity=n;
    q->arr=(int*)malloc(sizeof(int));
}
int isfull(struct queue* q)
{
    if(q->size==q->capacity) return 1;
    return 0;
}
int isempty(struct queue* q)
{
    if(q->size==0) return 1;
    return 0;
}
void enqueue(struct queue* q,int d)
{
    if(isfull(q)) return;
    q->rear=(q->rear+1)%q->capacity;
    if(isempty(q))
    {
        q->front=0;
        q->rear=0;
    }
    q->arr[q->rear]=d;
    q->size=q->size+1;
}
int dequeue(struct queue* q)
{
    if(isempty(q)) return -1;
    int a=q->arr[q->front];
    q->front=(q->front+1)%q->capacity;
    q->size=q->size-1;
    return a;
}
void push(struct queue* q1,struct queue* q2,int d)
{
    if(isfull(q1)) return;
    else{
        while(!isempty(q1))
        {
            int a=dequeue(q1);
            enqueue(q2,a);  //enqueue in q2 elemtnt a
        }
        enqueue(q2,d);
        while(!isempty(q2))
        {
            // printf("hi\n");
            int a=dequeue(q2);
            // printf("%d\n",q2->size);
            enqueue(q1,a);
        }
    }
    // printf("element pushed in the stack %d %d\n",(q1)->arr[(q1)->rear],(q1)->size);
}
int pop(struct queue* q)
{
    if(isempty(q)) return -1;
    else{
        int a=dequeue(q);
        return a;
    }
}
int main()
{
    struct queue* q1=CreateQueue(5);
    struct queue* q2=CreateQueue(5);
    push(q1,q2,10);
    push(q1,q2,20);
    int a=pop(q1);
    printf("popped element is %d\n",a);
    int b=pop(q1);
    printf("popped element is %d\n",b);
    int c=pop(q1);
    printf("popped element is %d\n",c);
}