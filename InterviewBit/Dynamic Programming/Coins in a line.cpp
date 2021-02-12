
int dp[501][501];
int helper(vector<int>&A,int i,int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return A[i];
    if(i+1==j)
        return max(A[i],A[j]);
    if(dp[i][j]!=-1)
        return dp[i][j];
        
        
    return dp[i][j]=max(A[i]+min(helper(A,i+2,j),helper(A,i+1,j-1)),A[j]+min(helper(A,i,j-2),helper(A,i+1,j-1)));
    
    
    
    
}

int Solution::maxcoin(vector<int> &A) 
{
    int n=A.size();
    int i=0;
    int j=n-1;
    memset(dp,-1,sizeof(dp));
    
    return helper(A,0,n-1);
    
    
}
