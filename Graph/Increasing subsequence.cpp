class Solution {
public:
    void dfs(vector<int>& nums,vector<int>& v,vector<vector<int>>& res,int start)
    {
        if(v.size()>=2)
            res.push_back(v);
        unordered_set<int> s;
        for(int i=start;i<nums.size();i++)
        {
            if((v.empty() || nums[i]>=v.back()) && (s.find(nums[i])==s.end()))
            {
                v.push_back(nums[i]);
                dfs(nums,v,res,i+1);
                v.pop_back();
                s.insert(nums[i]);
            }
        }
        
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> v;
       
        dfs(nums,v,res,0);
        // unordered_set<vector<int>> st;
        
        
        return res;
    }
};
