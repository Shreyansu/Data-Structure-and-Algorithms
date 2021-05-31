class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int sum=0;
        int res=INT_MIN;
        while(j<nums.size() && i<=j)
        {
            if(mp.find(nums[j])!=mp.end())
            {
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
                // cout<<sum<<"--";
            }
            else
            {
                sum+=nums[j];
                mp[nums[j]]++;
                res=max(res,sum);
                j++;
                // cout<<sum<<"++";
            }
        }
        res=max(res,sum);
        return res;
    }
};
