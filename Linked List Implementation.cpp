#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void push(Node** head,int val)
{
    Node* node=new Node();
    node->data=val;
    node->next=*head;
    *head=node;
}
void deleteNode(Node** head,int key)
{
    Node* temp=*head;
    Node* prev=NULL;
    if(temp!=NULL && temp->data==key)
    {
        *head=temp->next;
        return;
    }
    else
    {
        while(temp!=NULL && temp->data!=key)
        {
        prev=temp;
        temp=temp->next;
        }
        if(temp==NULL)
            return;
        else
            prev->next=temp->next;
            
        delete temp;
    }
    
}

void append(Node** head,int val)
{
    Node* new_node=new Node();
    Node* last=*head;
    new_node->data=val;
    new_node->next=NULL;
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    return;
    
}
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}

int main() 
{
    Node* head=NULL;
    append(&head,5);
    append(&head,6);
    deleteNode(&head,6);
    print(head);
	
	return 0;
}
