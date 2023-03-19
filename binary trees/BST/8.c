// least common ancestor for 2 nodes
#include<stdio.h>
#include<Stdlib.h>
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
}
struct node* lca(struct node* root,int n1,int n2)
{
    if(root==NULL) return NULL;
    if(root->data >n1 && root->data > n2)
    {
        root=lca(root->left,n1,n2);
    }
    if(root->data < n1 && root->data <n2)
    {
        root=lca(root->right,n1,n2);
    }
    return  root;
}
int main()
{
    struct node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    int n1 = 14, n2 = 8;
    struct node* t = lca(root, n1, n2);
    printf("%d ",t->data);
}