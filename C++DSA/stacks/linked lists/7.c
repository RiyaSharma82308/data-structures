// Remove duplicates from a sorted linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* removes(struct node* head)
{
    struct node* ptr=head;
    if(head==NULL) return NULL;
    else
    {
        while(ptr->next!=NULL)
        {
            if(ptr->data==ptr->next->data)
            {
                struct node* temp=ptr->next;
                ptr->next=temp->next;
                free(temp);
            }
            else
            {
                ptr=ptr->next;
            }
        }
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
    second->data=40;
    second->next=third;
    third->data=40;
    third->next=fourth;
    fourth->data=40;
    fourth->next=fifth;
    fifth->data=40;
    fifth->next=sixth;
    sixth->data=40;
    sixth->next=NULL;
    head=removes(head);
    print(head);
}