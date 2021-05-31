class Solution {
public:
    int count=0;
    bool issafe(int res[][9],int row,int col,int n)
    {
        
        for(int i=0;i<row;i++)
        {
            if(res[i][col]==1)
                return false;
        }
        int i,j;
        for(i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(res[i][j]==1)
                return false;
        }
        for(int i=row,j=col;i>=0 && j<n;i--,j++)
        {
            if(res[i][j]==1)
                return false;
        }
        return true;
    }
    void solve(int res[][9],int n,int row)
    {
        if(row==n)
            count++;
        
        for(int i=0;i<n;i++)
        {
            if(issafe(res,row,i,n))
            {
                res[row][i]=1;
                solve(res,n,row+1);
                res[row][i]=0;
            }
        }
        // return true;
    }
    
    int totalNQueens(int n) 
    {
        int res[9][9];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                res[i][j]=0;
        }
        solve(res,n,0);
        
        return count;
        
    }
};
