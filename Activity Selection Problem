#include <bits/stdc++.h>
using namespace std;

struct activity
{
    int start,finish,index;
};


bool compare(activity s1,activity s2)
{
    return s1.finish<s2.finish;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    activity arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i].start;
	        arr[i].index=i;
	    }
	    for(int i=0;i<n;i++)
	        cin>>arr[i].finish;
	    sort(arr,arr+n,compare);
	    int count=1;
	    int j=0;
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i].start>arr[j].finish)
	        {
	            count++;
	            j=i;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
