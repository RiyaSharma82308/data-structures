#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void  print(struct node* head)
{
    struct node* ptr=head;
    // (struct node*)malloc(sizeof(struct node));
    // ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
struct node* insertathead(struct node* head,int ele)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=head;
    head=temp;
    return head;
}
struct node* insertbefore(struct node* head,int ele,int before)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    struct node* ptr=head;
    struct node* pre=head;
    while(ptr->data!=before)
    {
        pre=ptr;
        ptr=ptr->next;
        if(ptr->data==before) break;
    }
    pre->next=temp;
    temp->next=ptr;
    return head;
}
struct node* insertafter(struct node* head,int ele,int after)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    struct node* ptr=head;
    while(ptr->data!=after)
    {
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
}
struct node* delete(struct node* head,int position)
{
    struct node* temp=head;
    struct node* pre=head;
    for(int i=0;i<position;i++)
    {
        if(i==0 && position==1)
        {
            head=head->next;
            free(temp);
        }
        else
        {
            if(i==position-1 && temp)
            {
                pre->next=temp->next;
                free(temp);
            }
            else
            {
                pre=temp;
                if(pre==NULL) break;
                temp=temp->next;
            }
        }
    }
    return head;
}
struct node* insertatend(struct node* head,int ele)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}
int main()
{
    struct node*  head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;
    print(head);
    printf("\n");
    head=insertathead(head,0);
    print(head);
    printf("\n");
    head=insertatend(head,50);
    print(head);
    printf("\n");
    head=insertafter(head,30,50);
    print(head);
    printf("\n");
    head=insertbefore(head,15,20);
    print(head);
    printf("\n");
    head=delete(head,3);
    print(head);
    printf("\n");
}