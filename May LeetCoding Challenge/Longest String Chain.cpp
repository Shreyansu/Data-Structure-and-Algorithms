class Solution {
public:
    
    static bool comp(string& x,string& y)
    {
        return x.size()<y.size();
    }
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),comp);
        int res=0;
        
        for(auto w:words)
        {
            for(int i=0;i<w.size();i++)
            {
                string k=w.substr(0,i)+w.substr(i+1);
                if(dp.find(k)!=dp.end())
                {
                    dp[w]=max(dp[w],dp[k]+1);
                }
                else
                    dp[w]=max(dp[w],1);
                
            }
            res=max(res,dp[w]);
        }
        
        return res;
    }
};
