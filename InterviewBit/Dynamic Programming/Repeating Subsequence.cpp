int dp[102][102];

int lrs(string a,string b,int i,int j)
{
    if(i==0 || j==0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    if(a[i-1]==b[j-1] && i!=j)
        return dp[i][j]= 1+lrs(a,b,i-1,j-1);
    
    return dp[i][j]=max(lrs(a,b,i-1,j),lrs(a,b,i,j-1));
        
    // return dp[i][j];
    
        
}

int Solution::anytwo(string A) 
{
    int m=A.size();
    memset(dp,-1,sizeof(dp));
    
    return lrs(A,A,m,m)>=2?1:0;
    
}
