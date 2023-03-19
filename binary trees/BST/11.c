#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
    int data;
    struct Tnode* left;
    struct Tnode* right;
};
struct Lnode
{
    int data;
    struct Lnode* next;
};
struct Tnode* newNode(int d)
{
    struct Tnode* temp=(struct Tnode*)malloc(sizeof(struct Tnode));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void push(struct Lnode** head,int d)
{
    struct Lnode* temp=(struct Lnode*)malloc(sizeof(struct Lnode));
    temp->data=d;
    if(*head==NULL)
    {
        *head=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=*head;
        *head=temp;
    }
}
struct Tnode* createBTree(struct Lnode** head,int n)
{
    if(n<=0)
    {
        return NULL;
    }
    struct Tnode* left=createBTree(head,n/2);
    struct Tnode* root=newNode((*head)->data);
    *head=(*head)->next;
    root->left=left;
    root->right=createBTree(head,n-n/2-1);
    return root;
}
// void print(struct Lnode* head)
// {
//     struct Lnode* ptr=head;
//     while(ptr!=NULL)
//     {
//         printf("%d ",ptr->data);
//         ptr=ptr->next;
//     }
//     printf("\n");
// }
void print(struct Tnode* root)
{
    if(root==NULL) return;
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}
int main()
{
    struct Lnode* head = NULL;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    // print(head);
    struct Tnode* root=createBTree(&head,7);
    print(root);
}