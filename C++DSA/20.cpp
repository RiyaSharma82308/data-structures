# include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }   
    ~Node()
    {
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
            delete prev;
            this->prev=NULL;   
        }
    }
};
void insertAtHead(Node*&head,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(Node*&tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtPosition(Node*&head , int d, int position,Node*&tail)
{
    Node* temp=head;
    if(position==1)
    {
        insertAtHead(head,d);
        return;
    }
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    Node* n=new Node(d);
    n->next=temp->next;
    temp->next->prev=n;
    temp->next=n;
    n->prev=temp;
}
void deletenode(int position,Node*&head, Node*&tail)
{
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    Node* curr=head;
    Node* prev1=NULL;
    int count=1;
    while(count < position)
    {
        prev1=curr;
        curr=curr->next;
        count++;
    }
    if(curr->next==NULL)
    {
        tail=prev1;
    }
    prev1->next=curr->next;
    //curr->next->prev=prev1;
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;
}
void print(Node*&head)
{
    // int count=1;
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* node1=new Node(10);
    Node* head= node1;
    Node* tail=node1;
    print(head);
    insertAtHead(head,5);
    print(head);
    insertAtTail(tail,15);
    print(head);
    insertAtPosition(head,100,4,tail);
    print(head);
    deletenode(3,head,tail);
    print(head);
    cout<<head->data<<endl;cout<<tail->data<<endl;  
}