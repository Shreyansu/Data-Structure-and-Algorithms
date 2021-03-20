class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size();
        if(n==0)
            return 0;
        unordered_map<char,int> mp;
        
        int i=0,j=0;
        int res=INT_MIN;
        while(j<n)
        {
            if(mp[s[j]]<1)
            {
                mp[s[j]]++;
                res=max(res,j-i+1);
                j++;
            }
            else
            {
                mp[s[j]]++;
                while(mp[s[j]]>1)
                {
                    mp[s[i]]--;
                    i++;
                    
                }
                j++;
            }
        }
        
        return res;
        
        
        
    }
};
