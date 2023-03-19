#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* swap(struct node* head,int x,int y)
{
    struct node* xnode=head;
    struct node* prevx=NULL;
    struct node* ynode=head;
    struct node* prevy=NULL;
    while(xnode->data!=x && xnode)
    {
        prevx=xnode;
        xnode=xnode->next;
        if(xnode==NULL) return head;
    }
    while(ynode->data!=y && ynode)
    {
        prevy=ynode;
        ynode=ynode->next;
        if(ynode==NULL) return head;
    }
    // if(xnode==NULL || ynode==NULL) return head;
    // x is the head;
    if(prevx==NULL)head=ynode;
    else prevx->next=ynode;
    // y is the head
    if(prevy==NULL) head=xnode;
    else prevy->next=xnode;
    // normal swapping 
    struct node* temp=xnode->next;
    xnode->next=ynode->next;
    ynode->next=temp;
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
    head=swap(head,30,70);
    print(head);
}