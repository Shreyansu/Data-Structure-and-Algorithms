#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* newNode(int data)
{
	struct Node* node =(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->next=NULL;
	
	return node;
}

int len(Node* a)
{
	int l=0;
	while(a!=NULL)
	{
		l++;
		a=a->next;
	}
	return l;
}

void push(Node** head,int data)
{
	struct Node* node=newNode(data);
	node->next=*head;
	*head=node;
}

Node* padZero(Node* snode,int dif)
{
	if(snode==NULL)
		return NULL;
	Node* prev=snode;
//	Node* head=NULL;
	while(dif--)
	{
		Node* node=newNode(0);
		node->next=prev;
		prev=node;
		
	}
	
	return prev;
	
}

Node* substractHelper(Node* lnode,Node* snode,bool& borrow)
{
	if(lnode==NULL && snode==NULL && borrow==false)
		return NULL;
		
	Node* prev=substractHelper(lnode?lnode->next:NULL,snode?snode->next:NULL,borrow);
	
	int d1=lnode->data;
	int d2=snode->data;
	int diff=0;
	
	if(borrow==true)
	{
		d1--;
		borrow=false;
	}
	if(d1<d2)
	{
		borrow=true;
		d1+=10;
		
	}
	diff=d1-d2;
	Node* node=newNode(diff);
	node->next=prev;
	
	return node;
	
}

Node* substract(Node* a,Node* b)
{
	if(a==NULL && b==NULL)
		return NULL;
	
	int len1=len(a);
	int len2=len(b);
	
	
	Node* lnode=NULL;
	Node* snode=NULL;
	
	Node* temp1=a;
	Node* temp2=b;
	if(len1!=len2)
	{
		lnode=len1>len2?a:b;
		snode=len2>len1?a:b;
		snode=padZero(snode,abs(len1-len2));
	}
	else
	{
		while(a && b)
		{
			if(a->data !=b->data)
			{
				lnode=a->data>b->data?temp1:temp2;
				snode=a->data>b->data?temp2:temp1;
				break;
			}
			a=a->next;
			b=b->next;
			
		}
	}
	bool borrow=false;
	return substractHelper(lnode,snode,borrow);
	
}


int main()
{
	Node* head1=newNode(1);
	head1->next=newNode(0);
	head1->next->next=newNode(0);
	
	Node* head2=newNode(1);
	
	Node* temp= substract(head1,head2);
	
	while(temp!=NULL)
	{
		cout<<temp->data<<"--->"<<endl;
		temp=temp->next;
	}
	
	return 0;
}
