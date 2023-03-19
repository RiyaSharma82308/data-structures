// check if a BTree is symmetric
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
    return temp;
}
int check_symmetric(struct node* root1,struct node* root2)
{
    if(root1==NULL && root2==NULL) return 1;
    if(root1->data==root2->data)
        return (check_symmetric(root1->left,root2->right) && check_symmetric(root1->right, root2->left));
    return 0;
}
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    int a=check_symmetric(root,root);
    printf("%d",a);
}