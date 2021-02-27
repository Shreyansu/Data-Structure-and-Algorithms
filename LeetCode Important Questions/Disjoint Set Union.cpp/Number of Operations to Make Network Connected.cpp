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
    
    int makeConnected(int n, vector<vector<int>>& con) 
    {
        
        vector<int> parent(n,-1);
        int cycle=0;
        for(int i=0;i<con.size();i++)
        {
            int x=find(con[i][0],parent);
            int y=find(con[i][1],parent);
            
            if(x==y)
                cycle++;
            else
                unionp(x,y,parent);
        }
        cout<<cycle<<endl;
        int ind=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
                ind++;
                // cout<<parent[i]<<" k";
                // 
        }
        // cout<<ind<<endl;
        ind=ind-1;
        if(ind<=cycle)
            return ind;
        return -1;
    }
};
