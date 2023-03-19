// Given a binary tree, find out if the tree can be folded or not. A tree can be folded if the left and right subtrees of the tree are structure-wise mirror images of each other. An empty tree is considered foldable. 
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
    return temp;
}
void mirror(struct node* root)
{
    if(root==NULL) return;
    else{
        mirror(root->left);
        mirror(root->right);
        struct node* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}
int isstructsame(struct node* a,struct node* b)
{
    if(a==NULL && b==NULL) return 1;
    if(a!=NULL && b!=NULL && isstructsame(a->left,b->left) && isstructsame(a->right,b->right) ) return 1;
    return 0;
}
int isfoldable(struct node* root)
{
    if(root==NULL) return 1;
    mirror(root->left);
    int a=isstructsame(root->left,root->right);
    mirror(root->left);
    return a;
}
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->left->right = newNode(5);
    int a=isfoldable(root);
    printf("%d \n",a);
}