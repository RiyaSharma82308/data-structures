#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void rearrange(struct node* list)
{
    struct node* p;
    struct node* q;
    int temp;
    if(!(list) || !(list->next))
    {
        return;
    }
    p=list;
    q=list->next;
    while(q)
    {
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        p=q->next;
        printf(" first %d %d\n", p->data, q->data);
        if(q=p)
        {
            printf("here\n");
            q=p->next;
        }
        else
        {
            printf("there\n");
            q=NULL;
        }
        // q=p? p->next:0;
        // printf(" second %d %d\n", p->data, q->data);
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
    struct node* list=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));
    struct node* fifth=(struct node*)malloc(sizeof(struct node));
    struct node* sixth=(struct node*)malloc(sizeof(struct node));
    struct node* seventh=(struct node*)malloc(sizeof(struct node));
    list->data=1;
    second->data=2;
    third->data=3;
    fourth->data=4;
    fifth->data=5;
    sixth->data=6;
    seventh->data=7;
    list->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=NULL;
    rearrange(list);
    print(list);

}