class Solution {
public:
    int maxx(vector<int>& A,int start,int end)
    {
        int mx=INT_MIN;
        int index=-1;
        for(int i=start;i<end;i++)
        {
            if(A[i]>mx)
            {
                mx=A[i];
                index=i;
            }
        }
        return index;
    }
    vector<int> pancakeSort(vector<int>& A) 
    {
        vector<int> result;
        int n=A.size();
        for(int i=0;i<n-1;i++)
        {
            int pos=maxx(A,0,n-i);
            if(pos!=0)
                result.push_back(pos+1);
            result.push_back(n-i);
            reverse(A.begin(),A.begin()+pos+1);
            reverse(A.begin(),A.begin()+n-i);
        }
        return result;
    }
};
