// check if binary tree is BST
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
    temp->left=temp->right=NULL;
    return temp;
}
void check(struct node* root,int arr[],int* index)
{
    if(root==NULL) return;
    check(root->left,arr,index);
    arr[(*index)++]=root->data;
    check(root->right,arr,index);
}
void count(struct node* root,int* sum)
{
    if(root==NULL) return ;
    count(root->left,sum);
    (*sum)++;
    count(root->right,sum);
}
int main()
{
    struct node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    int index=0;
    int n=0;
    count(root,&n);
    int arr[n];
    check(root,arr,&index);
    int a=1;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]<arr[i]) 
        {
            a=0;
            break;
        }
    }
    if(a==1) printf("yes\n");
    else printf("NO\n");
}