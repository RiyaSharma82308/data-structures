// find loop in a linked list
// another approach is use two pointers slow and fast. move fast by two and slow by one. if they meet at any point then there is a loop.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    int flag;
};
int findloop(struct node* head)
{
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->flag==1) return 1;
        else
        {
            ptr->flag=1;
        }
        ptr=ptr->next;
    }
    return 0;
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
    head->flag=0;
    head->next=second;
    second->data=20;
    second->flag=0;
    second->next=third;
    third->data=30;
    third->flag=0;
    third->next=fourth;
    fourth->data=40;
    fourth->flag=0;
    fourth->next=fifth;
    fifth->data=50;
    fifth->flag=0;
    fifth->next=sixth;
    sixth->data=60;
    sixth->flag=0;
    sixth->next=NULL;
    int a=findloop(head);
    printf("%d \n",a);
}