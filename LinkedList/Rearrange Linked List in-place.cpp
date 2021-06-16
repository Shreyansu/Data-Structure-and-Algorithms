#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int data;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        if (head->next)
            cout << "-> ";
        head = head->next;
    }
    cout << endl;
}
void reverse(Node** head2)
{
//	Node* temp=*head2;
	Node* prev=NULL;
	Node* cur=*head2;
	Node* next;
	while(cur!=NULL)
	{
		next=cur->next;
		
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	*head2=prev;
	
} 

void rearrange(Node** head)
{
	Node* slow=*head;
	Node* fast=slow->next;
	
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	Node* head1=*head;
	Node* head2=slow->next;
	slow->next=NULL;
	
	reverse(&head2);
	
	*head=newNode(0);
	Node* cur=*head;
	while(head1 || head2)
	{
		if(head1)
		{
			cur->next=head1;
			cur=cur->next;
//			cur->next=NULL;
			head1=head1->next;
		}
		if(head2)
		{
			cur->next=head2;
			cur=cur->next;
//			cur->next=NULL;
			head2=head2->next;
		}
	}
	*head=(*head)->next;
	cout<<"List is rearranged"<<endl;
}


int main()
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    printlist(head); 
    rearrange(&head); 
    printlist(head); 
    return 0;
}
