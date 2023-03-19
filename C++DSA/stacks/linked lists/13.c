// reverse a singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void print(struct node* head)
{
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void func(struct node* head)
{
    struct node* prev=NULL;
    struct node* curr=head;
    struct node* nex=NULL;
    while(curr!=NULL)
    {
        nex=curr->next;
        if(curr->next==NULL) head=curr;
        curr->next=prev;
        // prev->next=nex;
        prev=curr;
        curr=nex;
    }
    print(head);
}
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));
    struct node* fifth=(struct node*)malloc(sizeof(struct node));
    struct node* sixth=(struct node*)malloc(sizeof(struct node));
    head->data=15;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=fourth;
    fourth->data=45;
    fourth->next=fifth;
    fifth->data=54;
    fifth->next=sixth;
    sixth->data=67;
    sixth->next=NULL;
    func(head);
}