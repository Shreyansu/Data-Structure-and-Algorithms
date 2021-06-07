class Solution {
public:
    void island(vector<vector<int>>& grid,int i,int j,int &count,vector<vector<bool>>& vis)
    {
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || vis[i][j])
            return;
        vis[i][j]=true;
        count++;
        grid[i][j]=0;
        island(grid,i+1,j,count,vis);
        island(grid,i-1,j,count,vis);
        island(grid,i,j+1,count,vis);
        island(grid,i,j-1,count,vis);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int maxArea=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int temp=0;
                    
                    island(grid,i,j,temp,vis);
                    maxArea=max(temp,maxArea);
                }
                
            }
        }
        return maxArea;
        
    }
};
