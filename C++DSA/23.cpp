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
};
void insertAtHead(int d,Node* &head, Node* &tail)
{
    Node* node1=new Node(d);
    if(head==NULL)
    {
        head=node1;
        tail=node1;
        node1->next=NULL;
    }
    else
    {
        node1->next=head;
        head=node1;
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
    cout<<endl;
}
Node* func(Node* &head)
{
    // cout<<"first "<<head->data<<endl;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* n=func(head->next);
    // cout<<"head data"<<head->data<<endl;
    head->next->next=head;
    head->next=NULL;
    // cout<<"node data"<<n->data<<endl;
    return n;
}
int main()
{
    Node* n1=new Node(10);
    Node* head=n1;
    Node* tail=n1;
    insertAtHead(20,head,tail);
    insertAtHead(30,head,tail);
    insertAtHead(40,head,tail);
    insertAtHead(50,head,tail);
    print(head);
    Node* n=func(head);
    // print(head);
}