// deletion in  binary tree 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* newnode(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->right=temp->left=NULL;
    return temp;
}
void push(struct node* q[],struct node* key,int* front,int* rear)
{
    if(*front==-1) (*front)++;
    (*rear)++;
    q[*rear]=key;
}
struct node* pop(struct node* q[],int* front,int* rear)
{
    struct node* temp=q[*front];
    (*front)++;
    return temp;
}
// void removed(struct node* root,struct node* key_node)
// {
//     struct node* array[100];
//     int front=-1;int rear=-1;
//     push(array,root,&front,&rear);
//     while(front<=rear)
//     {
//         struct node* temp=pop(array,&front,&rear);
//         if(temp==key_node)
//         {
//             temp=NULL;
//             free(temp);
//             return;
//         }
//         if(temp->right)
//         {
//             if(temp->right==key_node)
//             {
//                 temp->right=NULL;
//                 free(key_node);
//                 return;
//             }
//             else
//             {
//                 push(array,temp->right,&front,&rear);
//             }
//         }
//         if(temp->left)
//         {
//             if(temp->left==key_node)
//             {
//                 temp->left=NULL;
//                 free(key_node);
//                 return;
//             }
//             else{
//                 push(array,temp->left,&front,&rear);
//             }
//         }
//     }
// }
struct node* deletion(struct node* root,int key)
{
    if(root==NULL) return root;
    if(root->right==NULL && root->left==NULL)
    {
        if(root->data==key)
        {
            return NULL;
        }
        else return root;
    }
    struct node* queue[100];
    int front=-1; int rear=-1;
    push(queue,root,&front,&rear);
    struct node* temp;
    struct node* key_node=NULL;
    struct node* last;
    while(front<=rear)
    {
        temp=pop(queue,&front,&rear);
        if(temp->data==key)
        {
            key_node=temp;
        }
        if(temp->left)
        {
            last=temp;
            push(queue,temp->left,&front,&rear);
        }
        if(temp->right)
        {
            last=temp;
            push(queue,temp->right,&front,&rear);
        }
    }
    if(key_node!=NULL)
    {
        // int a=temp->data;
        // removed(root,temp);
        // key_node->data=a;
        key_node->data=temp->data;
        if(last->right==temp) last->right=NULL;
        else last->left=NULL;
        free(temp);
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
    struct node* root=newnode(9);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(7);
    int key=4;
    print(root);
    printf("\n");
    root=deletion(root,key);
    print(root);
}