// Move last element to front of a given Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node*  exchange(struct node* head)
{
    struct node* x=head;
    struct node* y=head;
    struct node* prevy=NULL;
    if(x==NULL) return head;
    if(y->next==NULL) return head;
    while(y->next!=NULL)
    {
        // printf("%d ",y->data);
        prevy=y;
        y=y->next;
    }
    prevy->next=NULL;
    y->next=head;
    head=y;
    return head;
}
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
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));
    struct node* fifth=(struct node*)malloc(sizeof(struct node));
    struct node* sixth=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=fourth;
    fourth->data=40;
    fourth->next=fifth;
    fifth->data=50;
    fifth->next=sixth;
    sixth->data=60;
    sixth->next=NULL;
    head=exchange(head);
    print(head);
}