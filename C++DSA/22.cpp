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
void insertAtTail(int d,Node* &tail)
{
    if(tail==NULL)
    {
        Node* node1=new Node(d);
        tail=node1;
    }
    else
    {
        // Node* temp=tail;
        Node* node1=new Node(d);
        tail->next=node1;
        tail=node1;
    }
}
void insertAtPosition(int d,int position,Node* &head,Node* &tail)
{
    Node* node1=new Node(d);
    Node* temp=head;
    int count=1;
    if(position==1)
    {
        insertAtHead(d,head,tail);
        return;
    }
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(d,tail);
        return;
    }
    node1->next=temp->next;
    temp->next=node1;
}
void deleteNode(Node* &head,int position, Node* &tail)
{
    Node* curr=head;
    Node* prev=NULL;
    int count=1;
    if(curr->next==NULL)
    {
        head=NULL;
        delete curr;
    }
    if(position==1)
    {
        head=curr->next;
        curr->next=NULL;
        delete curr;
    }
    else
    {
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        if(curr->next==NULL)
        {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }

}
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* n=NULL;
    Node* head=n;
    Node* tail=n;
    insertAtHead(10,head,tail);
    print(head);
    // cout<<head->data<<" "<<tail->data<<" "<<"here"<<endl;
    insertAtHead(20,head,tail);
    // cout<<head->data<<" "<<tail->data<<" "<<"here"<<endl;
    insertAtHead(30,head,tail);
    // cout<<head->data<<" "<<tail->data<<" "<<"here"<<endl;
    insertAtHead(40,head,tail);
    print(head);
    // cout<<head->data<<" "<<tail->data<<" "<<"here"<<endl;
    insertAtTail(50,tail);
    print(head);
    // cout<<head->data<<" "<<tail->data<<" "<<"here"<<endl;
    insertAtPosition(100,6,head,tail);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head,3,tail);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
}