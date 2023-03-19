// find kth smallest element
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
}
struct node* insert(struct node* root,int d)
{
    if(root==NULL)
    {
        return newNode(d);
    }
    if(d<root->data)
    {
        root->left=insert(root->left,d);
    }
    else if(d> root->data)
    {
        root->right=insert(root->right,d);
    }
    return root;
}
int count=0;
struct node* find(struct node* root,int k)
{
    if(root==NULL) return NULL;
    struct node* left=find(root->left,k);
    // printf("check  %d\n",root->data);
    if(left!=NULL)
    {
        // printf("here %d \n",left->data);
        return left;
    }  
    count++;
    if(count==k) return root;
    struct node* right=find(root->right,k);
}
int count2=0;
struct node* klargest(struct node* root,int k)
{
    if(root==NULL) return NULL;
    struct node* right=klargest(root->right,k);
    if(right!=NULL)
    {
        return right;
    }
    count2++;
    if(count2==k) return root;
    struct node* left=klargest(root->left,k);
}
int main()
{
    struct node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
    int n = sizeof(keys) / sizeof(keys[0]);
    for(int i=0;i<n;i++)
    {
        root=insert(root,keys[i]);
    }
    int k=3;
    struct node* a=find(root,k);
    printf("%d\n",a->data);
    int k2=1;
    struct node* b=klargest(root,k2);
    printf("%d\n",b->data);
}