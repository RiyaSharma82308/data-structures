//  pairwise swapping a singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
// void swap(int *x,int *y)
// {
//     int temp=*x;
//     *x=*y;
//     *y=temp;
// }
void pairswap(struct  node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return ;
    }
    else
    {
        int temp=head->data;
        // printf("%d %d \n",head->data,head->next->data);
        head->data=head->next->data;
        head->next->data=temp;
        // printf("%d %d \n",head->data,head->next->data);
        // swap(&(head->data),&(head->next->data));
        return pairswap(head->next->next);
    }
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
    pairswap(head);
    print(head);
}