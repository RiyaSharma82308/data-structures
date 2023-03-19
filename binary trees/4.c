// A tree is a Continuous tree if in each root to leaf path, the absolute difference between keys of two adjacent is 1. We are given a binary tree, we need to check if the tree is continuous or not.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
}
int check(struct node* root)
{
    if(root==NULL) return 1;
    if(root->right==NULL && root->left==NULL) return 1;
    if(root->left==NULL)
    {
        int a=root->data - root->right->data;
        if(a<0) a=a*(-1);
        return(a==1 && check(root->right));
    }
    if(root->right==NULL)
    {
        int a=root->data - root->left->data;
        if(a<0) a=a*(-1);
        return(a==1 && check(root->left));
    }
    int b=root->data - root->left->data;
    int c=root->data - root->right->data;
    if(b<0) b=b*(-1);
    if(c<0) c=c*(-1);
    return(b==1 && c==1 && check(root->left) && check(root->right));
}
int main()
{
    struct node* root=newnode(2);
    root->left=newnode(1);
    root->right=newnode(3);
    root->left->left=newnode(2);
    root->left->right=newnode(30);
    root->right->left=newnode(4);
    int a=check(root);
    printf("%d",a);
}