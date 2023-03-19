// find the postorder traversal of BST from given preorder traversal
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
// int preindex=0;
struct node* newNode(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* construct(int pre[],int* preindex,int size,int mini,int maxi)
{
    if(*preindex >= size) return NULL;
    struct node* root=NULL;
    if(pre[*preindex]> mini && pre[*preindex]< maxi)
    {
        root=newNode(pre[*preindex]);
        *preindex=*preindex+1;
        if(*preindex < size)
        {
            root->left=construct(pre,preindex,size,mini,root->data);
        }
        if(*preindex < size)
        {
            root->right=construct(pre,preindex,size,root->data,maxi);
        }
        // printf("%d \n",*preindex);
    }
    return root;
}
void print(struct node* root)
{
    if(root==NULL) return;
    print(root->left);
    print(root->right);
    printf("%d ",root->data);
}
int main()
{
    int pre[] = { 40, 30, 35, 80, 100 };
    int n = sizeof(pre) / sizeof(pre[0]);
    int preindex=0;
    // printf("%d\n",preindex);
    struct node* root=construct(pre,&preindex,n,INT_MIN,INT_MAX);
    // printf("%d\n",root->data);
    print(root);
}