class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
       int m=str1.size();
        int n=str2.size();
        
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        string lc="";
        string res="";
        int i=m,j=n;
        
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                lc=str1[i-1]+lc;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
        int sz=lc.size();
        i=0,j=0;
        for(char c:lc)
        {
            while(str1[i]!=c)
                res+=str1[i++];
            while(str2[j]!=c)
                res+=str2[j++];
            
            res+=c;
            ++i;
            ++j;
        }
        
        res+=str1.substr(i)+str2.substr(j);
        return res;
    }
};
