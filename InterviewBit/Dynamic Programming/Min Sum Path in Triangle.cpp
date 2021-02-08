
int dp[201][201];
    int helper(vector<vector<int>>& triangle,int i,int j,int n)
    {
        if(i==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int sum=triangle[i][j];
        sum+=min(helper(triangle,i+1,j,n),helper(triangle,i+1,j+1,n));
        
        return dp[i][j]=sum;
    }
int Solution::minimumTotal(vector<vector<int> > &triangle) {

    int n=triangle.size();
        memset(dp,-1,sizeof(dp));
        if(n==0)
            return 0;
        
        return helper(triangle,0,0,n);
}
