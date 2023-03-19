// sorted array to binary search tree;
#include<stdio.h>
#include<stdlib.h>
struct node{
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
struct node* insertIntoBinaryTree(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    struct node* root=newNode(arr[mid]);
    root->left=insertIntoBinaryTree(arr,start,mid-1);
    root->right=insertIntoBinaryTree(arr,mid+1,end);
    return root;
}
void print(struct node* root)
{
    if(root==NULL) return;
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct node* root=NULL;
    root=insertIntoBinaryTree(arr,0,n-1);
    print(root);
}
