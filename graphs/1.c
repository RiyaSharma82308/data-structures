// BFS for graphs
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int size;
    int** arr;
};
struct queue
{
    int front;
    int rear;
    int capacity;
    int size;
    int* qarr;
};
int isempty(struct queue* q)
{
    if(q->size==0) return 1;
    return 0;
}
int isfull(struct queue* q)
{
    if(q->size==q->capacity) return 1;
    return 0;
}
void push(struct queue** q,int d)
{
    if(isfull(*q)) return;
    if(isempty(*q))
    {
        (*q)->rear=0;
        (*q)->front=0;
    }
    else
        (*q)->rear=(*q)->rear+1 % (*q)->capacity;
    (*q)->qarr[(*q)->rear]=d;
    (*q)->size=(*q)->size+1;
}
int pop(struct queue**q)
{
    if(isempty(*q)) return -1;
    int a=(*q)->qarr[(*q)->front];
    (*q)->front=((*q)->front+1) % (*q)->capacity;
    (*q)->size=(*q)->size-1;
    return a;
}
void addEdge(struct node* g1,int v,int w)
{
    g1->arr[v][w]=1;
}
void BFS(struct node* g1)
{
    int visited[g1->size];
    for(int i=0;i<g1->size;i++)
    {
        visited[i]=0;
    }
    struct queue* q1=(struct queue*)malloc(sizeof(struct queue));
    q1->qarr=(int*)malloc(sizeof(int));
    q1->rear=q1->front=-1;
    q1->capacity=g1->size;
    q1->size=0;
    int i=2;
    visited[i]=1;
    push(&q1,i);
    printf("%d ",i);
    while(!isempty(q1))
    {
        int a=pop(&q1);
        for(int j=0;j<g1->size;j++)
        {
            if(visited[j]==0 && g1->arr[a][j]==1)
            {
                printf("%d ",j);
                visited[j]=1;
                push(&q1,j);
            }
        }
    }
}
int main()
{
    struct node* g1=(struct node*)malloc(sizeof(struct node));
    g1->size=4;
    g1->arr=(int**)malloc(g1->size*sizeof(int));
    for(int i=0;i<g1->size;i++)
    {
        g1->arr[i]=(int*)malloc(g1->size*sizeof(int));
    }
    for(int i=0;i<g1->size;i++)
    {
        for(int j=0;j<g1->size;j++)
        {
            g1->arr[i][j]=0;
        }
        printf("\n");
    }
    addEdge(g1,2,3);
    addEdge(g1,2,0);
    addEdge(g1,0,2);
    addEdge(g1,0,1);
    addEdge(g1,1,2);
    // for(int i=0;i<g1->size;i++)
    // {
    //     for(int j=0;j<g1->size;j++)
    //     {
    //         printf("%d ",g1->arr[i][j]);
    //     }
    //     printf("\n");
    // }
    BFS(g1);
}