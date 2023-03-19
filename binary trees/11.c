// Sorted Linked List to Balanced BST
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct lnode
{
    int data;
    struct lnode* next;
};
struct node* newNode(int d)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->left,new->right=NULL;
    return new;
}
struct lnode* insertinlist(struct lnode* head,int d,struct lnode* tail) 
{
    struct lnode* temp=(struct lnode*)malloc(sizeof(struct lnode));
    temp->data=d;
    temp->next=NULL;
    // printf("%d \n",temp->data);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        struct lnode* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    // printf("head and tail are %d %d\n",head->data,tail->data);
    return head;
}
struct node* makeBST(struct lnode** head,int n)
{
    if(n<=0) {
        return NULL;
    }
    // printf("head is %d \n",(*head)->data);
    struct node* left=makeBST(head,n/2);
    struct node* p=newNode((*head)->data);
    p->left=left;
    *head=(*head)->next;
    p-> right=makeBST(head,n-n/2-1);
    return p;
}
void print(struct node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    print(root->left);
    print(root->right);
}
int main()
{
    struct node* root=NULL;
    struct lnode* head=NULL;
    struct lnode* tail=NULL;
    head=insertinlist(head,1,tail);
    head=insertinlist(head,2,tail);
    head=insertinlist(head,3,tail);
    head=insertinlist(head,4,tail);
    head=insertinlist(head,5,tail);
    head=insertinlist(head,6,tail);
    head=insertinlist(head,7,tail);
    // printf("%d",head->data);
    root=makeBST(&head,7);
    print(root);
}