class Solution {
public:
    bool ispalindrome(string s)
    {
        int n=s.size();
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[n-i-1])
                return false;
            
        }
        return true;
    }
    
    int superpalindromesInRange(string left, string right) 
    {
        
        long long l=stoll(left);
        long long r=stoll(right);
        
        vector<long long> pal;
        for(int i=0;i<10;i++)
            pal.push_back(i);
        
        for(int i=0;i<=10000;i++)
        {
            string s1=to_string(i);
            string s2=to_string(i);
            
            reverse(s2.begin(),s2.end());
            pal.push_back(stoll(s1+s2));
            
            for(int i=0;i<10;i++)
            {
                string temp=s1+to_string(i)+s2;
                pal.push_back(stoll(temp));
            }
        }
        int res=0;
        for(auto i : pal)
        {
            if(i>1e9)
                continue;
            long long flag= i*i;
            if(flag>=l && flag<=r && ispalindrome(to_string(flag)))
                res++;
        }
        
        return res;
        
    }
};
