class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int res=0;
        int n=arr.size();
        if(n==1 || n==2)
            return 0;
        for(int k=1;k<n-1;k++)
        {
            int i=k,j=k;
            while(i>0 && arr[i]>arr[i-1])
                i--;
            while(j<n-1 && arr[j]>arr[j+1])
                j++;
            if(abs(i-k)>=1 && abs(j-k)>=1)
                res=max(res,j-i+1);
        }
        return res;
    }
};
