class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) 
    {
        int n=a.size();
        int l=0,r=n-1;
        int res=INT_MAX;
        while(l<a.size()-1 && a[l]<=a[l+1])
            l++;
        while(r>0 && a[r]>=a[r-1])
            r--;
        if(l==n-1 || r==0)
            return 0;
        int i=0,j=r;
        res=min(r,n-1-l);
        while(i<=l && j<n)
        {
            if(a[j]>=a[i])
            {
                res=min(res,j-i-1);
                i++;
            }
            else
                j++;
        }
        
        
        return max(res,0);
        
    }
};
