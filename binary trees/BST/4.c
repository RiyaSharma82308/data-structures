// Transform a BST to greater sum tree
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
void convert(struct node* root,int* sum)
{
    if(root==NULL) return;
    convert(root->right,sum);
    (*sum)+=root->data;
    root->data=*sum-root->data;
    convert(root->left,sum);
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
    struct node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);
    print(root);
    printf("\n");
    int sum=0;
    convert(root,&sum);
    print(root);
}