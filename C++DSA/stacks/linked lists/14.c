// quick sort of linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* partition(struct node* first, struct node* last)
{
    struct node* front=first;
    struct node* pivot=first;
    while(front != last && front!=NULL)
    {
        pivot=first;
        if(front->data < last->data)
        {
            int temp=front->data;
            front->data=first->data;
            first->data=temp;
            first=first->next;
        }
        front=front->next;
    }
    int a=last->data;
    last->data=first->data;
    first->data=a;
    return pivot;
}
void quicksort(struct node* first,struct node* last)
{
    if(first == last) return;
    struct node* pivot=partition(first,last);
    quicksort(first,pivot);
    quicksort(pivot->next,last);
}

struct node* insert(struct node* head, int ele)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            if(ptr->next==NULL) break;
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
void merge(struct node* head1, struct node* head2)
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    while(ptr1 !=NULL && ptr2!=NULL)
    {
        if(ptr1->data <= ptr2->data)
        {
            head=insert(head,ptr1->data);
            ptr1=ptr1->next;
        }
        else 
        {
            head=insert(head,ptr2->data);
            ptr2=ptr2->next;
        }
        if( ptr1 ==NULL || ptr2 == NULL) break;
    }
    while(ptr1!=NULL)
    {
        insert(head ,ptr1->data);
        ptr1=ptr1->next;
        if(ptr1==NULL) break;
    }
    while(ptr2!=NULL)
    {
        insert(head,ptr2->data);
        ptr2=ptr2->next;
        if(ptr2==NULL) break;
    }
    print(head);
    return;
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
    second->data=2012;
    second->next=third;
    third->data=390;
    third->next=fourth;
    fourth->data=45;
    fourth->next=fifth;
    fifth->data=99;
    fifth->next=sixth;
    sixth->data=67;
    sixth->next=NULL;

    quicksort(head,sixth);
    print(head);

    struct node* head2=(struct node*)malloc(sizeof(struct node));
    struct node* second2=(struct node*)malloc(sizeof(struct node));
    struct node* third2=(struct node*)malloc(sizeof(struct node));
    struct node* fourth2=(struct node*)malloc(sizeof(struct node));
    struct node* fifth2=(struct node*)malloc(sizeof(struct node));
    struct node* sixth2=(struct node*)malloc(sizeof(struct node));
    head2->data=10;
    head2->next=second2;
    second2->data=2015;
    second2->next=third2;
    third2->data=398;
    third2->next=fourth2;
    fourth2->data=100;
    fourth2->next=fifth2;
    fifth2->data=40;
    fifth2->next=sixth2;
    sixth2->data=67;
    sixth2->next=NULL;

    quicksort(head2,sixth2);
    print(head2);

    merge(head,head2);
}