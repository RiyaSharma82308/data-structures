// The expression tree is a binary tree in which each internal node corresponds to the operator and each leaf node corresponds to the operand so for example expression tree for 3 + ((5+9)*2) would be:
#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node* right;
    struct node* left;
    struct node* next;
};
struct node* head=NULL;
struct node* newnode(char d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* pop()
{
    struct node* ptr=head;
    head=head->next;
    return ptr;
}
void push(struct node* temp)
{
    if(head==NULL) head=temp;
    else{
        temp->next=head;
        head=temp;
    }
}
void print(struct node* root)
{
    if(root==NULL) return;
    print(root->left);
    printf("%c",root->data);
    print(root->right);
}
int main()
{
    char arr[]={'A','B','C','*','+','D','/'};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if(arr[i]=='+' || arr[i]=='-' || arr[i]=='*' ||arr[i]=='/' || arr[i]=='^')
        {
            struct node* temp=newnode(arr[i]);
            struct node* x=pop();
            struct node* y=pop();
            temp->left=y;
            temp->right=x;
            push(temp);
        }
        else
        {
            struct node* temp=newnode(arr[i]);
            push(temp);
        }
    }
    print(head);
}