int Solution::longestSubsequenceLength(const vector<int> &a) 
{
    int n=a.size();
    if(n<=1)
        return n;
    vector<int> lis(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    vector<int> lds(n,1);
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[i]>a[j] && lds[i]<lds[j]+1)
                lds[i]=lds[j]+1;
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,lis[i]+lds[i]);
        
    }
    return mx-1;
}
