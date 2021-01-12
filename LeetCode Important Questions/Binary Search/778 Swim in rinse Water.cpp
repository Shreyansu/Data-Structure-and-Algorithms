class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int low=grid[0][0],high=n*n-1;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            if(dfs(grid,mid,n))
                high=mid;
            else
                low=mid+1;
        }
        
        return high;
        
    }
    
    bool dfs(vector<vector<int>>& grid,int t,int n)
    {
        queue<pair<int,int>> q;
        bool vis[n+1][n+1];
        memset(vis,false,sizeof(vis));
        
        q.push({0,0});
        vis[0][0]=true;
         int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
        
        while(q.size()>0)
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            
            if(grid[x][y]<=t)
            {
                if(x==n-1 && y==n-1)
                    return true;
                for(auto d:dir)
                {
                    int p=x+d[0],s=y+d[1];
                    if(p>=0 && p<n && s>=0 && s<n && !vis[p][s])
                    {
                        vis[p][s]=true;
                        q.push({p,s});
                    }
                }
            }
            
        }
        
        return false;
        
    }
};
