class Solution {
public:
    bool isSplit(vector<int>& nums,int m,int sum)
    {
        long long s=0;
        for(auto i:nums)
        {
            s+=i;
            if(s>sum)
            {
                m--;
                s=i;
            }
        }
        return m>=1;
    }
    
    
    int splitArray(vector<int>& nums, int m) 
    {
        int left=0,right=0;
        for(auto i:nums)
        {
            left=max(left,i);
            right+=i;
        }
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(isSplit(nums,m,mid))
                right=mid;
            else
                left=mid+1;
        }
        
        return right;
    }
};
