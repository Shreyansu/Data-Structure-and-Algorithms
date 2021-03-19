class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int j=0,i=0;
        
        int n=nums.size();
        int p=1;
        int res=0;
        while(j<n)
        {
            p=p*nums[j];
            
            while(i<n && p>=k)
            {
                p=p/nums[i];
                i++;
            }
            if(p<k)
                res+=j-i+1;
            j++;
        }
        
        return res;
        
    }
};
