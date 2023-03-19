/////  singly linked list
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
    ~Node()
    {
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
    }
};
void insertAtHead(Node*&head,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node*&tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertInMiddle(int position,Node*&head,int d,Node*&tail)
{
    if(position==1)
    {
        insertAtHead(head,d);
        return;
    }
    int cnt=1;
    Node* temp=head;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    Node* n=new Node(d);
    n->next=temp->next;
    temp->next=n;
}
void deletenode(Node*&head , int position)
{
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node*&head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}
int main()
{
    Node* n1=new Node(12);
    //cout<<n1->data;
    Node* head=n1;
    Node* tail=n1;
    insertAtHead(head,1000);
    print(head);
    cout<<endl;
    insertAtTail(tail,200);
    print(head);  
    cout<<endl;
    insertInMiddle(4,head,400,tail);
    print(head);
    cout<<endl;
    deletenode(head,4);
    print(head);
    cout<<endl;
}