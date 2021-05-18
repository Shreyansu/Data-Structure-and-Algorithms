class Solution {
public:
    int maxScore(vector<int>& card, int k) 
    {
        int n=card.size();
        int total=0;
        for(int i=0;i<n;i++)
            total+=card[i];
        if(n==k)
            return total;
        int sum=0;
        int res=INT_MIN;
        int i=0,j=0;
        while(j<n)
        {
            if(j-i+1 !=(n-k))
            {
                sum+=card[j];
                j++;
            }
            else
            {
                sum+=card[j];
                res=max(res,total-sum);
                // cout<<res<<" ";
                sum-=card[i];
                i++;
                j++;
            }
        }
        return res;
        
    }
};
