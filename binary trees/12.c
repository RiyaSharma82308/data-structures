#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* ArrayToBST(int arr[],int n,int *index)
{
    if(n<=0) return NULL;
    struct node* left=ArrayToBST(arr,n/2,index);
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=arr[(*index)++];
    root->left=left;
    root->right=ArrayToBST(arr,n-n/2-1,index);
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index=0;
    struct node* root=NULL;
    root=ArrayToBST(arr,n,&index);
    print(root);
}