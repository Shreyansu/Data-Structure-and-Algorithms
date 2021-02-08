int dp[1001][1001];
int res(vector<vector<int>>& A,int i,int j)
{
    if(i==A.size()-1 && j==A[0].size()-1)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int right=0,down=0;
    if(j+1<A[0].size() && A[i][j+1]>A[i][j])
        right=res(A,i,j+1);
    if(i+1<A.size() && A[i+1][j]>A[i][j])
        down=res(A,i+1,j);
        
    return dp[i][j]=right || down;
}


int Solution::solve(vector<vector<int> > &A) 
{
    int n=A.size();
    int m=A[0].size();
    
    // int dp[n+1][m+1]={-1};
    memset(dp,-1,sizeof(dp));
    return res(A,0,0)==0?-1:n+m-1;
}
