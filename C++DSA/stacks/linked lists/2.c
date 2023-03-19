#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* insertathead(struct node* head,int ele)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=head;
    head=temp;
    return head;
}
// search an element in linked list
int search(struct node* head,int ele)
{
    struct node* ptr=head;
    int index=0;
    while(ptr->data!=ele && ptr!=NULL)
    {
        ptr=ptr->next;
        index++;
        if(ptr==NULL) break;
    }
    if(ptr==NULL) return -1;
    return index;
}
int print(struct node* head)
{
    struct node* ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return count;
}
int main()
{
    struct node* head=NULL;
    head=insertathead(head,10);
    head=insertathead(head,5);
    head=insertathead(head,1);
    head=insertathead(head,2);
    head=insertathead(head,3);
    head=insertathead(head,54);
    int count=print(head);
    printf("%d \n",count);
    int index=search(head,100);
    printf("element at index %d \n",index);
}