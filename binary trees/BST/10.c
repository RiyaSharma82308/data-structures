// convert BST into balanced BST
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int  d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    return temp;
}
void data(struct node* root,int arr[],int* i)
{
    if(root==NULL) return;
    data(root->left,arr,i);
    arr[(*i)++]=root->data;
    data(root->right,arr,i);
}
struct node* balanced_bst(int arr[],int start,int end)
{
    if(start>end) return NULL;
    int mid=(start+end)/2;
    struct node* root=newNode(arr[mid]);
    root->left=balanced_bst(arr,start,mid-1);
    root->right=balanced_bst(arr,mid+1,end);
    return root;
}
void print(struct node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    print(root->left);
    print(root->right);
}
int main()
{
    struct node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
    int i=0;
    int arr[5];
    data(root,arr,&i);
    struct node* q=balanced_bst(arr,0,4);
    print(q);
}