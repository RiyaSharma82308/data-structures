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
    temp->right=NULL;temp->left=NULL;
    return temp;
}
struct node* func(struct node* root,int t)
{
    if(root==NULL)
    {
        struct node* temp=newNode(t);
        root=temp;
        return root;
    }
    else
    {
        if(t<root->data)
        {
            root->left=func(root->left,t);
        }
        else{
            root->right=func(root->right,t);
        }
    }
    return root;
    // printf("%d\n",root->data);
}
struct node* createBST(int arr[],int n)
{
    if(n==0)
    {
        return NULL;
    }
    struct node* root=NULL;
    for(int i=0;i<n;i++)
    {
        // printf("%d\n",i);
        root=func(root,arr[i]);
    }
    return root;
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
    int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    struct node* root = createBST(arr, n);
    print(root);
}