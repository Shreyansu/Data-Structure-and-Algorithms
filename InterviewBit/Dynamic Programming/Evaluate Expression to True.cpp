int mod=1003;
int dp[151][151][2];
int result(string A,int i,int j,bool isreq)
{
    if(i>j)
        return 0;
    if(i==j)
    {
        if(isreq==true)
            return A[i]=='T';
        else
            return A[i]=='F';
    }
    if(dp[i][j][isreq]!=-1)
        return dp[i][j][isreq];
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lt,lf,rt,rf;
        lt=result(A,i,k-1,true);
        rf=result(A,k+1,j,false);
        rt=result(A,k+1,j,true);
        lf=result(A,i,k-1,false);
        
        if(A[k]=='|')
        {
            if(isreq==true)
            {
                ans=(ans%mod + lt*rf%mod +lf*rt%mod +lt*rt%mod)%mod;
            }
            else
                ans=(ans%mod +rf*lf%mod)%mod;
        }
        else if(A[k]=='&')
        {
            if(isreq==true)
                ans=(ans%mod+lt*rt%mod)%mod;
            else
                ans=(ans%mod + lt*rf%mod +lf*rt%mod +lf*rf%mod)%mod;
        }
        else
        {
            if(isreq==true)
                ans=(ans%mod + lt*rf%mod +lf*rt%mod)%mod;
            else
                ans=(ans%mod +lf*rf%mod +lt*rt%mod)%mod;
        }
    }
    return dp[i][j][isreq]=ans%mod;
}


int Solution::cnttrue(string A) 
{
    int n=A.size();
    
    memset(dp,-1,sizeof(dp));
    return result(A,0,n-1,true);
    
}
