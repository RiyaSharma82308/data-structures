// Find the middle of a given linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int middle(struct node* head)
{
    struct node* two=head;
    struct node* one=head;
    while(two->next!=NULL && two!=NULL)
    {
        two=two->next->next;
        one=one->next;
        // if(  (two->next==NULL) ) 
        // {
        //     break;
        // }
        // else if(two==NULL) break;
    }
    printf("%d\n",one->data);
    return one->data;
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
    int element=middle(head);
    printf("%d\n",element);
}