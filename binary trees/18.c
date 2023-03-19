// Replace each node in binary tree with the sum of its inorder predecessor and successor
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void count(struct Node* root,int* n)
{
    if(root==NULL) return ;
    count(root->left,n);
    count(root->right,n);
    *n+=1;
}
struct Node* getNode(int d)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void fill_array(struct Node* root,int arr[],int* i)
{
    if(root==NULL) return;
    fill_array(root->left,arr,i);
    arr[(*i)++]=root->data;
    fill_array(root->right,arr,i);
}
void changeBTree(struct Node* root,int arr[],int* t)
{
    if(root==NULL) return;
    changeBTree(root->left,arr,t);
    root->data=arr[*t-1]+arr[*t+1];
    *t=(*t)+1;
    changeBTree(root->right,arr,t);
}
void print(struct Node* root)
{
    if(root==NULL) return;
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}
int main()
{
    struct Node* root = getNode(1);
    root->left = getNode(2);        
    root->right = getNode(3);       
    root->left->left = getNode(4);  
    root->left->right = getNode(5); 
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    int n=0;;
    count(root,&n);
    printf("%d\n",n);
    int arr[n+2];
    arr[0]=0;
    int i=1;
    fill_array(root,arr,&i);
    arr[n+1]=0;
    // for(int j=0;j<n+2;j++)
    // {
    //     printf("%d ",arr[j]);
    // }
    int t=1;
    changeBTree(root,arr,&t);
    // printf("hiii\n");
    print(root);
}