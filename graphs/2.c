// create a graph and print it 
// bfs traversal of a graph
// DFS traversal of a graph
#include<stdio.h>
#include<stdlib.h>
struct adjListNode
{
    int dest;
    struct adjListNode* next;
};
struct adjList
{
    struct adjListNode* head;
};
struct graph
{
    int V;
    struct adjList* array;  
};
///queue////////////////////////////
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
    (*q)->size=((*q)->size)+1;
    // printf("pushed element at position %d and element is %d \n",(*q)->rear,d);
}
int pop(struct queue**q)
{
    if(isempty(*q)) return -1;
    int a=(*q)->qarr[(*q)->front];
    (*q)->front=((*q)->front+1) % (*q)->capacity;
    (*q)->size=(*q)->size-1;
    return a;
}
/////////////////////////////////////
struct adjListNode* createNode(int d)
{
    struct adjListNode* temp=(struct adjListNode*)malloc(sizeof(struct adjListNode));
    temp->dest=d;
    temp->next=NULL;
    return temp;
}
void addEdge(struct graph* g1,int src,int dest)
{
    struct adjListNode* ptr=NULL;
    struct adjListNode* newnode=createNode(dest);
    if(g1->array[src].head==NULL)
    {
        newnode->next=g1->array[src].head;
        g1->array[src].head=newnode;
    }
    else
    {
        ptr=g1->array[src].head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
    // newnode=createNode(src);
    // if(g1->array[dest].head==NULL)
    // {
    //     newnode->next=g1->array[dest].head;
    //     g1->array[dest].head=newnode;
    // }
    // else
    // {
    //     ptr=g1->array[dest].head;
    //     while(ptr->next!=NULL)
    //         ptr=ptr->next;
    //     ptr->next=newnode;
    // }
}
struct graph* createGraph(int v)
{
    struct graph* g1=(struct graph*)malloc(sizeof(struct graph));
    g1->V=v;
    g1->array=(struct adjList*)malloc(v*sizeof(struct adjList));
    for(int i=0;i<v;i++)
    {
        g1->array[i].head=NULL;
    }
    return g1;
}
void bfs(struct graph* g1,int a)
{
    int visited[g1->V];
    for(int i=0;i<g1->V;i++)
    {
        visited[i]=0;
    }
    struct queue* q1=(struct queue*)malloc(sizeof(struct queue));
    q1->front=-1;q1->rear=-1;
    q1->capacity=g1->V;
    q1->size=0;
    q1->qarr=(int*)malloc(sizeof(int));
    push(&q1,a);
    visited[a]=1;
    while(!isempty(q1))
    {
        int a=pop(&q1);
        struct adjListNode* ptr=g1->array[a].head;
        printf("%d ",a);
        while(ptr!=NULL)
        {
            if(visited[ptr->dest]==0)
            {
                visited[ptr->dest]=1;
                push(&q1,ptr->dest);
            }
            ptr=ptr->next;
        }
    }
}
void print(struct graph* g1)
{
    for(int i=0;i<g1->V;i++)
    {
        struct adjListNode* temp=g1->array[i].head;
        printf("for %d : ",i);
        while(temp)
        {
            // printf("hi");
            printf("%d ",temp->dest);
            temp=temp->next;
        }
        printf("\n");
    }
}
void DFS(struct graph* g1,int v,int visited[])
{
    if(g1->array[v].head==NULL) return;
    visited[v]=1;
    printf("%d ",v);
    struct adjListNode* ptr=g1->array[v].head;
    while(ptr!=NULL)
    {
        if(visited[ptr->dest]==0)
        {
            DFS(g1,ptr->dest,visited);
        }
        ptr=ptr->next;
    }
}
void matchingcount(struct graph* g1,int ans[])
{
    for(int i=0;i<g1->V;i++)
    {
        struct adjListNode* ptr=g1->array[i].head;
        int maxi=0;
        while(ptr!=NULL)
        {
            int count=0;
            struct adjListNode* temp=g1->array[ptr->dest].head;
            while(temp!=NULL)
            {
                count++;
                temp=temp->next;
            }
            if(count>maxi) {maxi=count;}
            ptr=ptr->next;
        }
        ans[i]=maxi;
    }
}
int main()
{
    struct graph*  g1=createGraph(4);
    // addEdge(g1, 0, 1);
    // addEdge(g1, 0, 4);
    // addEdge(g1, 1, 2);
    // addEdge(g1, 1, 3);
    // addEdge(g1, 1, 4);
    // addEdge(g1, 2, 3);
    // addEdge(g1, 3, 4);
    
    // print(g1);
    // bfs(g1,1);

    addEdge(g1,0, 1);
    addEdge(g1,0, 2);
    addEdge(g1,1, 2);
    addEdge(g1,2, 0);
    addEdge(g1,2, 3);
    addEdge(g1,3, 3);
    printf("\n");
    int ans[g1->V];
    matchingcount(g1,ans);
    int a=0;
    for(int i=0;i<g1->V;i++)
    {
        if(ans[i]>a)
        {
            a=ans[i];
        }
    }
    // printf("hi");
    printf("matching count is %d\n",a);
    int arr2[g1->V];
    for(int i=0;i<g1->V;i++)
    {
        arr2[i]=0;
    }
    DFS(g1,2,arr2);
}