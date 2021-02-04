int Solution::numDistinct(string s, string t) 
{
    int n=t.size();
        int m=s.size();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=m;i++)
            dp[0][i]=1;
        for(int i=1;i<=n;i++)
            dp[i][0]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[j-1]==t[i-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                else
                    dp[i][j]=dp[i][j-1];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return dp[n][m];
}
