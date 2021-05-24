class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        
        int avg=0;
        sort(nums.begin(),nums.end());
     
        int md;
        int n=nums.size();
        if(nums.size()%2)
            md=nums[n/2];
        else
            md=(nums[n/2]+nums[n/2-1])/2;
        
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            res+=abs(nums[i]-md);
        }
        
        return res;
    }
};
