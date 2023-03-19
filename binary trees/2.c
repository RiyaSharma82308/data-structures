// level order traversal
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
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    return new;
}
int height(struct node* root)
{
    if(root==NULL) return 0;
    else
    {
        int l=height(root->left);
        int r=height(root->right);
        if(l>r) return l+1;
        else return r+1;
    }
}
void currnode(struct node* root,int l)
{
    if(root==NULL) return;
    else if(l==1) printf("%d ",root->data);
    else{
        currnode(root->left,l-1);
        currnode(root->right,l-1);
    }
}
void level(struct node* root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        currnode(root,i);
        printf("\n");
    }
}
int  main()
{
    struct node* root=newnode(10);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->left=newnode(40);
    root->left->right=newnode(50);
    root->right->left=newnode(60);
    root->right->right=newnode(70);
    // root->left->left->left=newnode(100);
    level(root);
}