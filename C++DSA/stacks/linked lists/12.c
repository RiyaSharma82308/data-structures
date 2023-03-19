// Segregate even and odd nodes in a Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* insert(struct node* head,int ele)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    struct node* ptr=head;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
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
void func(struct node* head)
{
    struct node* ptr=head;
    struct node* head1=NULL;
    struct node* head2=NULL;
    while(ptr!=NULL)
    {
        if(ptr->data%2==0)
        {
            head1=insert(head1,ptr->data);
        }
        else
        {
            head2=insert(head2,ptr->data);
        }
        ptr=ptr->next;
    }
    struct node* temp=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    // head2=NULL;
    print(head1);
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