// convert BTree into greatest sum tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* right;
    struct node* left;
};
struct node* newNode(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void GreatestSum(struct node* root,int *sum)
{
    if(root==NULL) return;
    GreatestSum(root->right,sum);
    (*sum)+=root->data;
    root->data=*sum-root->data;
    // root->data=*sum;
    GreatestSum(root->left,sum);
}
void printInorder(struct node *root)
{
    if (root == NULL) return;
 
    printInorder(root->left);
    printf("%d ",root->data);
    printInorder(root->right);
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
    int sum=0;
    printInorder(root);
    printf("\n");
    GreatestSum(root,&sum);
    printInorder(root);
}