#include <bits/stdc++.h>
using namespace std;
#define mx 1000

class Stack
{
    int top;
    public:
        int arr[mx];
        Stack()
        {
            top=-1;
        }
        void push(int x);
        int pop();
        int peek();
        bool isEmpty();
    
    
    
};
    void Stack::push(int x)
    {
        if(top>=mx-1)
            cout<<"Stack is full"<<endl;
        else
            arr[++top]=x;
    }
    int Stack::pop()
    {
        if(top<0)
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else
        {
            int p= arr[top--];
            return p;
        }
    }
    int Stack::peek()
    {
        if(top<0)
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else
        {
           int p= arr[top];
           return p;
        }
    }
    bool Stack::isEmpty()
    {
        return (top<0);
    }

int main() 
{
    class Stack st;
    st.push(30);
    st.push(40);
    cout<<st.pop()<<endl;
    cout<<st.peek()<<endl;
    st.push(34);
    cout<<st.pop()<<endl;
    st.push(1);
    st.peek();
    while(!st.isEmpty())
    {
        st.peek();
        st.pop();
    }
	return 0;
}
