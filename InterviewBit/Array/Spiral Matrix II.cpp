vector<vector<int> > Solution::generateMatrix(int n) 
{
     vector<vector<int>> v(n,vector<int>(n));
        
        int rowstart=0,rowend=n-1,columnstart=0,columnend=n-1;
        
        int curr=1;
        while(curr<=n*n)
        {
            
            for(int i=columnstart;i<=columnend;i++)
                v[rowstart][i]=curr++;
            rowstart++;
            for(int i=rowstart;i<=rowend;i++)
                v[i][columnend]=curr++;
            columnend--;
            for(int i=columnend;i>=columnstart;i--)
                v[rowend][i]=curr++;
            rowend--;
            for(int i=rowend;i>=rowstart;i--)
                v[i][columnstart]=curr++;
            columnstart++;
        }
        
        return v;
        
}
