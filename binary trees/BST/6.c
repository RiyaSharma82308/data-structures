// check whether array elements represent the level order traversal of binary search tree
// not working
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    long int min;
    long int max;
};
struct queue
{
    // struct node* temp;
    int front;
    int rear;
    int size;
    int elenum;
    struct node** arr;
};
void push(struct queue** q,struct node* temps)
{
    if((*q)->elenum==(*q)->size) return;

    (*q)->rear=((*q)->rear+1)%(*q)->size;
    (*q)->arr[(*q)->rear]=temps;
    if((*q)->front==-1)
    {
        (*q)->front=((*q)->front+1)%(*q)->size;
    }
    (*q)->elenum=(*q)->elenum + 1;
}
struct node* pop(struct queue** q)
{
    if((*q)->elenum==0) return NULL;
    struct node* temp=(*q)->arr[(*q)->front];
    (*q)->front=((*q)->front+1)%(*q)->size;
    (*q)->elenum=(*q)->elenum-1;
    if((*q)->elenum ==0)
    {
        (*q)->front=-1; (*q)->rear=-1;
    }
    return temp;
}
int check(int arr[],int n)
{
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->front=-1;q->rear=-1;
    q->size=20;q->elenum=0;
    q->arr=(struct node**)malloc(sizeof(struct node*));

    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    int index=0;
    newNode->data=arr[index++];
    newNode->min=INT_MIN;
    newNode->max=INT_MAX;
    push(&q,newNode);
    // printf("pushed element %d\n",newNode->data);
    while(q->elenum>0 && index < n)
    {
        struct node* temp=pop(&q);
        int a=temp->data;
        int mini=temp->min;
        int maxi=temp->max;
        // printf("beginning %d %d\n",a,arr[index]);
        // printf("popped element %d\n",temp->data);
        if(index < n && arr[index] <a && arr[index]> mini)
        {
            newNode->data=arr[index];
            index=index+1;
            newNode->min=temp->min;
            newNode->max=temp->data;
            push(&q,newNode);
        }
        // printf("middle %d %d\n",a,arr[index]);
        if(index <n && arr[index] > a && arr[index] < maxi)
        {
            newNode->data=arr[index];
            index=index+1;
            newNode->min=temp->data;
            newNode->max=temp->max;
            push(&q,newNode);
            // printf("pushed element %d\n",newNode->data);
        }
    }
    // printf("%d\n",index);
    if(index>=n) return 1;
    else return 0;
}
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};   
    int n = sizeof(arr) / sizeof(arr[0]);
    int a=check(arr,n);  
    printf("%d\n",a);   
}