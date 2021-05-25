class Solution {
public:
    vector<vector<string>> res;
    
    
    void printsol(char result[][9],int n)
    {
        vector<string> ans(n);
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=0;j<n;j++)
            {
                temp=temp + result[i][j];
            }
            ans[i]=temp;
        }
        res.push_back(ans);
    }
    
    
    bool safe(char result[][9],int row,int col,int n)
    {
        for(int i=0;i<col;i++)
        {
            if(result[row][i]=='Q')
                return false;
        }
        int i,j;
        for (i=row,j=col; i>=0 && j>=0; i--, j--)
            if (result[i][j]=='Q')
                return false;
 
        for (i=row,j=col; j>=0 && i<n; i++, j--)
            if (result[i][j]=='Q')
                return false;
        
        
        return true;
    }
    
    bool solve(char result[][9],int col,int n)
    {
        if(col==n)
        {
            printsol(result,n);
            return true;;
        }
        bool nextQueen=false; 
        for(int i=0;i<n;i++)
        {
            if(safe(result,i,col,n))
            {
                result[i][col]='Q';
                nextQueen=solve(result,col+1,n);
                result[i][col]='.';
                
            }
        }
        return nextQueen;
    }
    
    
    vector<vector<string>> solveNQueens(int n) 
    {
        char result[9][9];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                result[i][j]='.';
            }
        }
        solve(result,0,n);

        return res;
     
        
    }
};
