// create bst from preorder traversal
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* CreateNode(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* createBST(int pre[],int size,int* preindex,int min,int max,int key)
{
    if(*preindex >= size)
    {
        return NULL;
    }
    struct node* root=NULL;
    if(key>min && key<max)
    {
        root=CreateNode(key);
        *preindex=*preindex+1;
        if(*preindex < size)
        {
            root->left=createBST(pre,size,preindex,min,key,pre[*preindex]);
        }
        if(*preindex < size)
        {
            root->right=createBST(pre,size,preindex,key,max,pre[*preindex]);
        }
    }
    return root;
}
void print(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}
int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
    struct node* root=NULL;
    int preindex=0;
    root=createBST(pre,size,&preindex,INT_MIN,INT_MAX,pre[0]);
    print(root);
}