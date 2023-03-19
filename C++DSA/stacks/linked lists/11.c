// intersection of two Sorted Linked Lists
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
void func(struct node* head1, struct node* head2)
{
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head=NULL;
    while(ptr1 && ptr2)
    {
        if(ptr1->data==ptr2->data)
        {
            head=insert(head,ptr1->data);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->data < ptr2->data)
        {
            ptr1=ptr1->next;
        }
        else{
            ptr2=ptr2->next;
        }
    }
    print(head);
}
int main()
{
    struct node* head1=(struct node*)malloc(sizeof(struct node));
    struct node* second1=(struct node*)malloc(sizeof(struct node));
    struct node* third1=(struct node*)malloc(sizeof(struct node));
    struct node* fourth1=(struct node*)malloc(sizeof(struct node));
    struct node* fifth1=(struct node*)malloc(sizeof(struct node));
    struct node* sixth1=(struct node*)malloc(sizeof(struct node));
    head1->data=10;
    head1->next=second1;
    second1->data=20;
    second1->next=third1;
    third1->data=30;
    third1->next=fourth1;
    fourth1->data=40;
    fourth1->next=fifth1;
    fifth1->data=50;
    fifth1->next=sixth1;
    sixth1->data=60;
    sixth1->next=NULL;
    struct node* head2=(struct node*)malloc(sizeof(struct node));
    struct node* second2=(struct node*)malloc(sizeof(struct node));
    struct node* third2=(struct node*)malloc(sizeof(struct node));
    struct node* fourth2=(struct node*)malloc(sizeof(struct node));
    struct node* fifth2=(struct node*)malloc(sizeof(struct node));
    struct node* sixth2=(struct node*)malloc(sizeof(struct node));
    head2->data=5;
    head2->next=second2;
    second2->data=15;
    second2->next=third2;
    third2->data=25;
    third2->next=fourth2;
    fourth2->data=40;
    fourth2->next=fifth2;
    fifth2->data=50;
    fifth2->next=sixth2;
    sixth2->data=60;
    sixth2->next=NULL;
    func(head1,head2);
}