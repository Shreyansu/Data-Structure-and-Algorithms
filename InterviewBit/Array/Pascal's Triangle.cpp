vector<vector<int> > Solution::solve(int A) 
{
    vector<vector<int>> v;
    if(A==0)
        return v;
        
    v.push_back({1});
    if(A==1)
        return v;
        
    for(int i=1;i<A;i++)
    {
        vector<int> res(i+1);
        res[0]=1;
        for(int j=1;j<i;j++)
        {
             res[j]=(v[i-1][j]+v[i-1][j-1]);
        }
        res[i]=1;
        v.push_back(res);
    }
    
    return v;
}
