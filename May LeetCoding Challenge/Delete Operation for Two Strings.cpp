class Solution {
public:
    int dp[501][501];
    int dop(string word1,string word2,int i,int j)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(word1[i]==word2[j])
            return dp[i][j]= 1+dop(word1,word2,i-1,j-1);
        
        return dp[i][j]= max(dop(word1,word2,i-1,j),dop(word1,word2,i,j-1));
    }
    
    int minDistance(string word1, string word2) 
    {
        int m=word1.size();
        int n=word2.size();
        memset(dp,-1,sizeof(dp));
        
        int x= dop(word1,word2,m-1,n-1);
        return m+n-2*x;
    }
};
