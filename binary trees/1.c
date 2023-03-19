// inserting in a binary tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* right;
    struct node* left;
};
struct node* newnode(int d)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void push(struct node* q[],struct node* key,int* front,int* rear)
{
    if(*front==-1) (*front)++;
    (*rear)++;
    q[*rear]=key;
}
struct node* pop(struct node* q[],int* front,int* rear)
{
    struct node* temp=q[*front];
    (*front)++;
    return temp;
}
void insert(struct node* root,int d)
{
    if(root==NULL) return;
    struct node* queue[100];
    int front=-1;
    int rear=-1;
    push(queue,root,&front,&rear);
    while(front<=rear)
    {
        struct node* p=pop(queue,&front,&rear);
        if(p->left==NULL)
        {
            p->left=newnode(d);
            return;
        }
        else{
            push(queue,p->left,&front,&rear);
        }
        if(p->right==NULL) 
        {
            p->right=newnode(d);
            return;
        }
        else push(queue,p->left,&front,&rear);
    }
}
int height(struct node* root)
{
    if(root==NULL) return 0;
    else
    {
        int l=height(root->left);
        int r=height(root->right);
        if(l>r) return l+1;
        else return r+1;
    }
}
void currnode(struct node* root,int l)
{
    if(root==NULL) return;
    else if(l==1) printf("%d ",root->data);
    else{
        currnode(root->left,l-1);
        currnode(root->right,l-1);
    }
}
void level(struct node* root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        currnode(root,i);
        printf("\n");
    }
}
int main()
{
    struct node* root=newnode(10);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->right=newnode(200);
    root->left->left=newnode(300);
    root->right->left=newnode(500);
    root->right->right=newnode(400);
    insert(root,50);
    level(root);
}