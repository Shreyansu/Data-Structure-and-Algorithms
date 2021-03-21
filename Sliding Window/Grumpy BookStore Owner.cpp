class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        
        int n=customers.size();
        int sat=0;
        int sum=0;
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(!grumpy[i])
            {
                sat+=customers[i];
                customers[i]=0;
            }
        }
        int i=0,j=0;
        while(j<n)
        {
            if(j-i+1 !=k)
            {
                sum+=customers[j];
                j++;
            }
            else
            {
                sum+=customers[j];
                if(sum+sat>res)
                {
                    res=sum+sat;

                }
                sum-=customers[i];
                i++;
                j++;
            }
        }
        
        return res;
        
        
    }
};
