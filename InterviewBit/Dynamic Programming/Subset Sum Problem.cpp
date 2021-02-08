Memoization:-

int dp[102][100002];
 
bool helper(vector<int>& A,int i,int sum)
{
    
    if(i==0 && sum!=0)
        return false;
    if(sum==0)
        return true;
    // if(sum>B)
    //     return false;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(A[i-1]<=sum)
        dp[i][sum]= (int)(helper(A,i-1,sum-A[i-1]) || helper(A,i-1,sum));
    else
        dp[i][sum]=(int)helper(A,i-1,sum);
    
    return (bool)dp[i][sum];
}
 
int Solution::solve(vector<int> &A, int B) 
{
    int n=A.size();
    if(n==0)
        return 0;
    memset(dp,-1,sizeof(dp));
    
    return helper(A,n,B);
    
}


Top-Down Approach:-

int Solution::solve(vector<int> &A, int B) 
{
    int n=A.size();
    if(n==0)
        return 0;
    // memset(dp,-1,sizeof(dp));
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=A[i];
    bool dp[n+1][B+1];
    
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int j=1;j<=B;j++)
        dp[0][j]=false;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=B;j++)
        {
            if(A[i-1]<=j)
                dp[i][j]=dp[i-1][j-A[i-1]] || dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][B];
    // return helper(A,n,B);
    
}
