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


void push(Node** head,int data)
{
	struct Node* node=newNode(data);
	node->next=*head;
	*head=node;
}

Node* reverse(Node** head)
{
	Node* nxt=NULL;
	Node* prev=NULL;
	Node* temp=*head;
	while(temp!=NULL)
	{
		nxt=temp->next;
		temp->next=prev;
		prev=temp;
		temp=nxt;
	}
	return prev;
	
}

int add(Node* a,Node* b,Node** head)
{
	struct Node* x=reverse(&a);
	struct Node* y=reverse(&b);
	
	struct Node* prev=NULL;
	
	int carry=0;
	while(x || y)
	{
		int sum=0;
		if(x)
			sum+=x->data;
		if(y)
			sum+=y->data;
		
		sum+=carry;
		carry=sum/10;
		sum=sum%10;
		
		struct Node* res=newNode(sum);
		if(*head==NULL)
		{
			*head=res;
			prev=res;
		}
		else
		{
			prev->next=res;
			prev=res;
		}
		if(x)
			x=x->next;
		if(y)
			y=y->next;
	}
	if(carry!=0)
	{
		Node* temp=newNode(carry);
		prev->next=temp;
		temp->next=NULL;
		
	}
//	int answer=0;
//	Node* temp=*head;
//	while(temp!=NULL)
//	{
//		answer=answer*10+temp->data;
//	}
	Node* res=reverse(head);
	int answer=0;
	while(res!=NULL)
	{
//		answer+=res->data;
		cout<<res->data<<"--"<<endl;
		res=res->next;
	}
	
	return answer;
	
}


int main()
{
	int p=5678;
	int q=354;
	struct Node* x=NULL;
	while(p!=0)
	{
		int temp=p%10;
		push(&x,temp);
		p=p/10;
	}
	struct Node* y=NULL;
	
	while(q!=0)
	{
		int temp=q%10;
		push(&y,temp);
		q=q/10;
	}
	struct Node* head=NULL;
	int result=add(x,y,&head);
	cout<<result<<endl;
	return 0;
}
