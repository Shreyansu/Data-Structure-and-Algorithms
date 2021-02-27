class Solution {
public:
    int find(int v,vector<int>& parent)
    {
        if(parent[v]==-1)
            return v;
        return find(parent[v],parent);
    }
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        vector<array<int,3>> edge;
        int n=points.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int dt=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                edge.push_back({dt,i,j});
            }
        }
        vector<int> parent(n,-1);
        int ans=0,count=0;
        sort(edge.begin(),edge.end());
        // int sz=n-1;
        for(auto i:edge)
        {
            int dist=i[0];
            int x=find(i[1],parent);
            int y=find(i[2],parent);
            
            if(x==y)
                continue;
            else
            {
                parent[x]=y;
                ans+=dist;
                count++;
                if(count==n-1)
                    break;
            }
        }
        return ans;
    }
};
