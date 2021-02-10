int Solution::maxProduct(const vector<int> &nums) 
{
    if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int max_end_here=0;
        int min_end_here=0;
        
        int max_so_far=0;
        int flag=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                max_end_here=max_end_here==0?nums[i]:max_end_here*nums[i];
                min_end_here=min_end_here==0?0:min(0,min_end_here*nums[i]);
                
                
            }
            else if(nums[i]==0)
            {
                max_end_here=0;
                min_end_here=0;
            }
            else
            {
                int temp=max_end_here;
                max_end_here=max(0,min_end_here*nums[i]);
                min_end_here=temp!=0?temp*nums[i]:nums[i];
            }
            
            if(max_end_here>max_so_far)
                max_so_far=max_end_here;
                 
        }
        // if(max_so_far==0)
        //     return 
        
        return max_so_far;
        
}
