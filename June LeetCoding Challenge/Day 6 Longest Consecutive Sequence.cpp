class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        set<int> s;
        int prev=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            if(nums[i]<prev)
                prev=nums[i];
        }
        int mx=INT_MIN;
        int count=0;
        
        for(auto& i :s)
        {
            if(abs(i-prev)<=1)
            {
                count++;
                mx=max(mx, count);
                prev=i;
                
            }
            else
            {
                prev=i;
                count=1;
            }
            
        }
        
        return mx;
    }
};
