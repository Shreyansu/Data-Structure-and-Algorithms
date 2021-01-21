class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.size()!=word2.size())
            return 0;
        vector<int> x(26,0),y(26,0),a(26,0),b(26,0);
        for(int i=0;i<word1.size();i++)
        {
            x[word1[i]-'a']++;
            y[word2[i]-'a']++;
            a[word1[i]-'a']=1;
            b[word2[i]-'a']=1;
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        return x==y && a==b;
        
    }
};
