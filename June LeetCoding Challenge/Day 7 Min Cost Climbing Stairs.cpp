class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        cost.push_back(0);
        int n=cost.size();
        vector<int> f(n);
        
        f[0]=cost[0];
        f[1]=cost[1];
        
        for(int i=2;i<n;i++)
        {
            f[i]=cost[i]+min(f[i-1],f[i-2]);
        }
        
        return f[n-1];
        
    }
};
