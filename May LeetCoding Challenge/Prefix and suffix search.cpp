class WordFilter {
public:
    unordered_map<string,int> mp;
    
    WordFilter(vector<string>& words) 
    {
        int index=0;
        for(auto word :words)
        {
            for(int i=0;i<word.size();i++)
            {
                for(int j=0;j<word.size();j++)
                {
                    string split=word.substr(0,i+1)+'('+word.substr(j);
                    mp[split]=index;
                }
            
            }
            index++;
        }
        
    }
    
    int f(string prefix, string suffix) 
    {
        string temp=prefix+'('+suffix;
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        
        return -1;
        
    }
};
