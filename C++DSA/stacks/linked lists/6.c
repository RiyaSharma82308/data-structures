// Find length of loop/cycle in given Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int looplength(struct node* head)
{
    struct node* fast=head;
    struct node* slow=head;
    while(fast && slow && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) break;
        else if(fast==NULL || fast->next==NULL)
        {
            return 0;
        }      
    }
    int count=1;
    fast=fast->next;
    while(fast!=slow)
    {
        count++;
        fast=fast->next;
    }
    return count;
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
    sixth->next=fourth;
    int length=looplength(head);
    printf("%d\n",length);
}