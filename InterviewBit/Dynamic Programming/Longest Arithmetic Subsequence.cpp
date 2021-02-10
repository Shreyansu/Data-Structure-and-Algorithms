int Solution::solve(const vector<int> &A) 
{
     int n=A.size();
        vector<unordered_map<int,int>> dp(n+1);
        
        int res=INT_MIN;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=A[i]-A[j];
                if(dp[j].count(diff)>0)
                    dp[i][diff]=1+dp[j][diff];
                else
                    dp[i][diff]=2;
                
                res=max(res,dp[i][diff]);
            }
        }
        
        return res;
}

