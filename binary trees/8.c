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
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
}
void push(struct node* arr[],struct node* d,int* front)
{
    (*front)++;
    arr[*front]=d;
}
struct node* pop(struct node* arr[],int* top)
{
    struct node* a=arr[*top];
    (*top)--;
    return a;
}
void inorder(struct node* root)
{
    if(root==NULL) return;
    int a=1;
    struct node* s[100];
    int top=-1;
    struct node* ptr=root;
    while(a)
    {
        // printf("rrot data is%d \n",root->data);
        if(ptr!=NULL)
        {
            push(s,ptr,&top);
            ptr=ptr->left;
        }
        else
        {
            if(top!=-1)
            {
                struct node* a=pop(s,&top);
                printf("%d ",a->data);
                ptr=a->right;
            }
            else
            {
                a=0;
            }
        }
        // printf("%d \n",root->data);
    }
}
int main()
{
    struct node* root= newnode(1);
    root->left= newnode(2);
    root->right= newnode(3);
    root->left->left= newnode(4);
    root->left->right= newnode(5); 
    inorder(root);
}