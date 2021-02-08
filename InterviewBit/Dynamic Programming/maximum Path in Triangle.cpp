int dp[1001][1001];
int helper(vector<vector<int>> &A,int n,int i,int j,int sum)
{
    if(i>=n || j>=n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    sum+=A[i][j];
    sum+=max(helper(A,n,i+1,j,0),helper(A,n,i+1,j+1,0));
    
    return dp[i][j]=sum;
}


int Solution::solve(vector<vector<int> > &A) 
{
    int n=A.size();
    int sum=0;
    if(n==0)
        return 0;
    memset(dp,-1,sizeof(dp));
    return helper(A,n,0,0,0);
        
}
