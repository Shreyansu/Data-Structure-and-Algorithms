class Solution {
public:
    int dp[10001];
    int n;
    int helper(vector<int>& nums,int start)
    {
        
        if(start==n-1)
            return 0;
        if(start>n-1)
            return 1e6;
        if(nums[start]==0)
            return 1e6;
        if(dp[start]!=-1)
            return dp[start];
        int res=1e6;
        for(int i=1;i<=nums[start];i++)
        {
            res=min(res,helper(nums,start+i));
        }
        dp[start]=res+1;
        return dp[start];
    }
    
    int jump(vector<int>& nums) 
    {
        n=nums.size();
        // vector<long> dp(n+1,-1);
        memset(dp,-1,sizeof(dp));
        int rest=helper(nums,0);
        if(rest>=1e6)
            return 0;
        return rest;
    }
};
