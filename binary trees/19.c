// find nth node of postorder traversall
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
int count=0;
void NthInorder(struct node* root,int n)
{
    if(root==NULL) return;
    NthInorder(root->left,n);
    NthInorder(root->right,n);
    count++;
    if(count==n) 
    {
        printf("%d\n",root->data);
        return;
    }
}
int main()
{
    struct node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
 
    int n = 4;
 
    NthInorder(root, n);
}