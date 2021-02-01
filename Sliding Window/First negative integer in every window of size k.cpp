#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int k;
        cin>>k;
        int i=0,j=0;
        deque<int> q;
        while(j<n)
        {
            if(a[j]<0)
                q.push_back(a[j]);
            if(j-i+1<k)
                j++;
            else if(j-i+1 ==k)
            {
                if(q.size()>0)
                    cout<<q.front()<<" ";
                else
                    cout<<0<<" ";
                if(q.front()==a[i])
                    q.pop_front();
                i++;
                j++;
            }
        }
        cout<<endl;
    }
	return 0;
}
