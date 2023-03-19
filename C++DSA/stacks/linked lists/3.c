// Program for Nth node from the end of a Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int findfromlast(struct node* head,int n)
{
    struct node* ptr=head;
    struct node* main=head;
    int count=1;
    while(count!=n)
    {
        ptr=ptr->next;
        count++;
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        main=main->next;
    }
    return main->data;
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
    int element=findfromlast(head,1);
    printf("%d\n",element);
}