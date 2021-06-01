#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
};
struct linkedList
{
	Node* head;
	linkedList()
	{
		head=NULL;
	}
	void push(int data)
	{
		Node* temp=head;
		Node* node =new Node(data);
		node->next=NULL;
		if(temp==NULL)
		{
			head=node;
		}
		else
		{
			while(temp->next !=NULL)
				temp=temp->next;
			temp->next=node;
			temp=node;
			
		}
	}
	void print()
	{
		Node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"--->";
			temp=temp->next;
		}
	}
	
	void merge()
	{
		Node* start=NULL;
		Node* stail=NULL;
		Node* end=NULL;
		Node* etail=NULL;
		
		Node* temp=head;
		while(temp!=NULL)
		{
			if(temp->data & 1)
			{
				if(end==NULL)
				{
					end=temp;
					etail=temp;
				}
				else
				{
					etail->next=temp;
					etail=etail->next;
//					etail->next=NULL;
				}
			}
			else
			{
				if(start==NULL)
				{
					start=temp;
					stail=temp;
				}
				else
				{
					stail->next=temp;
					stail=stail->next;
//					stail->next=NULL;
				}
			}
			temp=temp->next;
		}
		if(start)
		{
			head=start;
			stail->next=end;
		}
		else
		{
			head=end;
		}
		if(etail)
			etail->next=NULL;
	}
};

int main()
{
	linkedList ll;
    ll.push(2);
    ll.push(3);
    ll.push(1);
    ll.push(7);
    ll.push(5);
    ll.push(4);
    ll.push(6);
    
    ll.merge();
    
	
    ll.print();
 
    
    return 0;
}
