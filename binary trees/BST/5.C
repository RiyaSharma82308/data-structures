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
}
struct node* insert(struct node* root,int d)
{
    if(root==NULL)
    {
        struct node* temp=newNode(d);
        return temp;
    }
    if(d<(root)->data)
    {
        root->left=insert((root)->left,d);
    }
    else if(d> (root)->data)
    {
        root->right=insert((root)->right,d);
    }
    return root;
}
struct node* CreateBinaryTree(int k,int n)
{
    struct node* root=newNode(k);
    for(int i=1;i<=n;i++)
    {
        if(i!=k)
        {
            root=insert(root,i);
        }
    }
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
    int n=5;
    for(int i=1;i<=5;i++)
    {
        struct node* root1=NULL;
        root1=CreateBinaryTree(i,n);
        print(root1);
        printf("\n");
    }
}