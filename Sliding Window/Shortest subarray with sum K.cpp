class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) 
    {
        
        int n=A.size();
        if(n==1)
        {
            if(A[0]==K)
                return 1;
            else
                return -1;
        }
        vector<int> p(n+1,0);
        // p[0]=A[0];
        
        int res=INT_MAX;
        for(int i=1;i<n+1;i++)
        {
            p[i]=A[i-1]+p[i-1];
        }
        // for(int i=0;i<n+1;i++)
        //     cout<<p[i]<<" ";
        deque<int> q;
        
        for(int i=0;i<n+1;i++)
        {
            while(!q.empty() && p[i]<=p[q.back()])
            {
                q.pop_back();
            }
            while(!q.empty() && p[i]-p[q.front()]>=K)
            {
                res=min(res,i-q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return res==INT_MAX ? -1:res;
    }
};
