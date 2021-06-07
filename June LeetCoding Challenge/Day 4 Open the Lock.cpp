class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        set<string> dead(deadends.begin(),deadends.end());
        
        if(dead.find("0000")!=dead.end())
            return -1;
        if(target=="0000")
            return 0;
        queue<string> q;
        q.push("0000");
        set<string> v;
        
        int count=0;
        while(!q.empty())
        {
            int n=q.size();
            count++;
            while(n--)
            {
                string cur=q.front();
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    for(int dif=1;dif<=9;dif+=8)
                    {
                        string s=cur;
                        s[i]=(s[i]-'0'+dif)%10 + '0';
                        if(s==target)
                            return count;
                        if(dead.find(s)==dead.end() && v.find(s)==v.end())
                            q.push(s);
                        v.insert(s);
                        
                    }
                }
            }
        }
        
        return -1;
    }
};
