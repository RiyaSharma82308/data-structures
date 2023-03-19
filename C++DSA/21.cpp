//////   singly linked circular lists
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
void insert(Node* &tail,int d,int element)
{
    if(tail==NULL)
    {
        Node* n1=new Node(d);
        tail=n1;
        n1->next=n1;
    }
    else
    {
        Node* curr=tail;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        Node* n1=new Node(d);
        n1->next=curr->next;
        curr->next=n1;
        // cout<<d<<" inserted"<<endl;
    }
}
void deletenode(Node* &tail,int element)
{
    if(tail==NULL)
    {
        cout<<"empty"<<endl;
    }
    else
    {
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=element)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(curr==prev)
        {
            tail=NULL;
        }
        if(tail==curr)
        {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* tail)
{
    Node* curr=tail;
    if(tail==NULL)
    {
        cout<<"empty list"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail !=curr);
    cout<<endl;   
}
int main() 
{
    Node* node1=new Node(10);
    Node* tail=node1;
    tail->next=tail;
    // insert(tail,200,10);
    print(tail);
    // // cout<<tail->data<<endl;
    // insert(tail,400,200);
    // print(tail);
    // insert(tail,800,10);
    // print(tail);
    deletenode(tail,10);
    print(tail);
}