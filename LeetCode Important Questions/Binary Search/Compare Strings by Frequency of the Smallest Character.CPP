class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) 
    {
        
        int n=words.size();
        vector<int> v;
        vector<int> res;
        for(auto i:words)
        {
            map<char,int> mp;
            for(char c:i)
            {
                mp[c]++;
            }
            v.push_back(mp.begin()->second);
        }
        sort(v.begin(),v.end());
        
        for(auto i:queries)
        {
            map<char,int> mp;
            for(char c:i)
            {
                mp[c]++;
            }
            int x=mp.begin()->second;
            int temp=0;
            int a=0,b=n-1;
            while(a<=b)
            {
                int mid=a+(b-a)/2;
                if(v[mid]>x)
                {
                   temp=max(temp,n-mid);
                    b=mid-1;
                }
                else
                {
                    a=mid+1;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
