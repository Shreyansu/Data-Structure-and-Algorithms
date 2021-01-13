int Solution::findMedian(vector<vector<int> > &A) 
{
    int m=A.size();
    int n=A[0].size();
    
    int element=1+(m*n)/2;
    int minm=INT_MAX;
    int maxm=INT_MIN;
    
    for(int i=0;i<m;i++)
    {
        if(A[i][0]<minm)
            minm=A[i][0];
        if(A[i][n-1]>maxm)
            maxm=A[i][n-1];
    }
    
    while(minm<maxm)
    {
        int mid=minm+(maxm-minm)/2;
        int count=0;
        for(int i=0;i<m;i++)
        {
            count+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        if(count<element)
            minm=mid+1;
        else
        {
            maxm=mid;
        }
    }
    return minm;
}
