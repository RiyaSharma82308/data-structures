// convert BTree into BST
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int d)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    return new;
}
int countnodes(struct node* root)
{
    if(root==NULL) return 0;
    return countnodes(root->left)+countnodes(root->right)+1;
}
void makingarray(struct node* root,int arr[],int* index)
{
    if(root==NULL) return;
    makingarray(root->left,arr,index);
    arr[(*index)++]=root->data;
    makingarray(root->right,arr,index);
}
void sortarray(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void changeelements(struct node* root,int arr[],int *index)
{
    if(root==NULL) return;
    changeelements(root->left,arr,index);
    root->data=arr[(*index)++];
    changeelements(root->right,arr,index);
}
void binarytreetoBST(struct node* root)
{
    int size=countnodes(root);
    // int* arr= new int[size];
    int arr[size];
    int ind=0;
    makingarray(root,arr,&ind);
    sortarray(arr,size);
    int index=0;
    changeelements(root,arr,&index);
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
    struct node* root=NULL;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    binarytreetoBST(root);

    inorder(root);
}
