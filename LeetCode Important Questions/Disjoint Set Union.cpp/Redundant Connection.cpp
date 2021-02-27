class Solution {
public:
    int find(int i,vector<int>& parent)
    {
        if(parent[i]==-1)
            return i;
        
        return find(parent[i],parent);
    }
    
    void unionp(int x,int y,vector<int>& parent)
    {
        parent[x]=y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        
        int n=edges.size();
        vector<int> parent(n+1,-1);
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int x=find(edges[i][0],parent);
            int y=find(edges[i][1],parent);
            
            if(x==y)
                res=edges[i];
            else
                unionp(x,y,parent);
        }
        
        
        return res;
        
    }
};
