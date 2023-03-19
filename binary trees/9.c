// add elements of preorder traversal in the BST
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnew(int d)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->left,new->right=NULL;
    return new;
}
struct node* insert(int arr[],int* index,int key,int size,int min,int max)
{
    if(*index >= size)
        return NULL;
    struct node* root=NULL;
    if(key>min && key<max)
    {
        root=createnew(key);
        (*index)++;
        if(*index < size)
        {
            root->left=insert(arr,index,arr[*index],size,min,key);
        }
        if(*index<size)
        {
            root->right=insert(arr,index,arr[*index],size,key,max);
        }
    }
    return root;
}
void inorder(struct node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50  };
    int size = sizeof(pre) / sizeof(pre[0]);
    int ind=0;
    struct node* root=insert(pre,&ind,pre[0],size,INT_MIN,INT_MAX);
    inorder(root);
}