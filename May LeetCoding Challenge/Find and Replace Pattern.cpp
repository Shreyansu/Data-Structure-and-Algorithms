class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> res;
        
        for(int j=0;j<words.size();j++)
        {
            unordered_map<char,char> mp;
            int flag=0;
            string s=words[j];
            if(s.size()!=pattern.size())
                continue;
            else
            {
                for(int i=0;i<pattern.size();i++)
                {
                    if(mp.find(pattern[i])!=mp.end())
                    {
                        if(mp[pattern[i]]!=s[i])
                        {
                            flag=1;
                            break;
                        }
                        
                    }
                    else
                    {
                        mp[pattern[i]]=s[i];
                    }
                    
                }
                vector<bool> seen(26,false);
                for(auto i:mp)
                {
                    if(seen[i.second-'a'])
                    {
                        flag=1;
                        break;
                    }
                    else
                        seen[i.second-'a']=true;
                }
                if(flag==0)
                        res.push_back(s);
            }
            
        }
            
        return res;
        
    }
};
