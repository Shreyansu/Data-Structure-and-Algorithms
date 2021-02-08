int Solution::solve(vector<vector<int> > &A) 
{
    int n=A.size();
    int m=A[0].size();
    int dp[n+1][m+1]={0};
    dp[n-1][m-1]=A[n-1][m-1];
    for(int i=n-2;i>=0;i--)
    {
        dp[i][m-1]=dp[i+1][m-1]+A[i][m-1];
    }
    for(int i=m-2;i>=0;i--)
    {
        dp[n-1][i]=dp[n-1][i+1]+A[n-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            // dp[i][j]=dp[i+1][j+1]+A[i+1][j]+A[i][j+1];
            dp[i][j]=dp[i][j+1]+A[i][j]+dp[i+1][j]-dp[i+1][j+1];
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mx=max(mx,dp[i][j]);
        }
    }
    return mx;
}
