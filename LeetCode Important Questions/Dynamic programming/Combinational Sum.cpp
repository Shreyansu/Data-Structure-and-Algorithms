class Solution {
    public int combinationSum4(int[] nums, int target) 
    {
        if(nums==null || nums.length==0)
            return 0;
        
        int[] dp =new int[target+1];
        Arrays.fill(dp,-1);
        
        return helper(nums,0,target,dp);
        
    }
    public int helper(int[] nums,int curSum,int target,int[] dp)
    {
        if(curSum>target)
            return 0;
        if(curSum==target)
            return 1;
        
        if(dp[curSum]!=-1)
            return dp[curSum];
        int res=0;
        for(int i=0;i<nums.length;i++)
        {
            curSum+=nums[i];
            res+=helper(nums,curSum,target,dp);
            curSum-=nums[i];
        }
        
        return dp[curSum]=res;
    }
}
