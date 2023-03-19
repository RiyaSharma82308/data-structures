// sorted linked list into a balanced B-Tree
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
int count(struct Lnode* head)
{
    int count=0;
    struct Lnode* ptr=head;
    while(ptr!=NULL)
    {
        // printf("%d ",ptr->data);
        ptr=ptr->next;
        count++;
    }
    return count;
}
struct Lnode* insertIntoLinkedList(struct Lnode* head,int d)
{
    struct Lnode* temp=(struct Lnode*)malloc(sizeof(struct Lnode));
    temp->data=d;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct Lnode* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}
struct Tnode* newNode(int d)
{
    struct Tnode* temp=(struct Tnode*)malloc(sizeof(struct Tnode));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct Tnode* insertIntoBinaryTree(struct Lnode** head,int n)
{
    if(n<=0) return NULL;
    struct Tnode* left=insertIntoBinaryTree(head,n/2);
    struct Tnode* root=newNode((*head)->data);
    root->left=left;
    *head=(*head)->next;
    root->right=insertIntoBinaryTree(head,n-n/2 -1);
    return root;
}
void printLinkedList(struct Lnode* head)
{
    struct Lnode* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void printBinaryTree(struct Tnode* root)
{
    if(root==NULL)
    {
        return;
    }
    printBinaryTree(root->left);
    printf("%d ",root->data);
    printBinaryTree(root->right);
}
int main()
{
    struct Tnode* root=NULL;
    struct Lnode* head=NULL;
    head=insertIntoLinkedList(head,10);
    head=insertIntoLinkedList(head,20);
    head=insertIntoLinkedList(head,30);
    head=insertIntoLinkedList(head,40);
    head=insertIntoLinkedList(head,50);
    int n=count(head);
    // printf("%d\n",n);
    root=insertIntoBinaryTree(&head,n);
    printBinaryTree(root);
}