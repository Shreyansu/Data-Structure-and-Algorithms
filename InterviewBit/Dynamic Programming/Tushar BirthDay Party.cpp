
long long int dp[1001][1001];
long long int party(const vector<int> &dcap, const vector<int> &price,int i,int capacity)
{
    if(capacity==0)
        return 0;
    if(dp[i][capacity]!=-1)
        return dp[i][capacity];
    
    if(i<=0)
        return INT_MAX;
    // int v1=INT_MAX,v2=INT_MAX;
    if(capacity>=dcap[i-1])
    {
        dp[i][capacity]=min(price[i-1]+party(dcap,price,i,capacity-dcap[i-1]),party(dcap,price,i-1,capacity));
    }
    else
        dp[i][capacity]=party(dcap,price,i-1,capacity);
        
    return dp[i][capacity];
}

int Solution::solve(const vector<int> &fcap, const vector<int> &dcap, const vector<int> &price)
{
    int n=fcap.size();
    int m=dcap.size();
    
    memset(dp,-1,sizeof(dp));
    int cost=0;
    for(int i=0;i<n;i++)
    {
        cost+=(int)party(dcap,price,m,fcap[i]);
    }
    return cost;
}
