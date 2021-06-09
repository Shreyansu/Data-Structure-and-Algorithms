#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	struct Node* next;
	
};
struct Node* newNode(int val)
{
	struct Node* node =new Node();
	node->data=val;
	node->next=NULL;
	
	return node;
}

void remove_loop(struct Node* slow,struct Node* head)
{
	struct Node *ptr1=slow;
	struct Node *ptr2=slow;
	
	int k=1;
// 	ptr1=slow, ptr2=slow;
	while(ptr1->next!=ptr2)
	{
		k++;
		ptr1=ptr1->next;
		
	}
	ptr1=head;ptr2=head;
	for(int i=0;i<k;i++)
		ptr2=ptr2->next;
	
	while(ptr1!=ptr2)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	while(ptr1->next!=ptr2)
	{
		ptr1=ptr1->next;
		
	}
	ptr1->next=NULL;
	
}

int detectloop(struct Node* head)
{
	struct Node* slow=head;
	struct Node* fast=head;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			remove_loop(slow,head);
			return 1;
		}
	}
	return 0;
}



int main()
{
	struct Node* head=newNode(40);
	head->next=newNode(30);
	head->next->next=newNode(25);
	head->next->next->next=newNode(15);
	head->next->next->next->next=newNode(10);
	
	head->next->next->next->next->next = head->next->next;
	
	detectloop(head);
//	cout<<t<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	
	return 0;
}
