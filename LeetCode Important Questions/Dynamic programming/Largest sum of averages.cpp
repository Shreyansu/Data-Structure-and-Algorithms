class Solution 
{
    
    public double largestSumOfAverages(int[] A, int K) 
    {
        int n=A.length;
        
        double arr[]=new double[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=(i==0?A[i]:arr[i-1]+A[i]);
            // System.out.println(arr[i]+" ");
        }
        double[][] mp=new double[n][K+1];
        return dp(A,K,arr,0,n,mp);
    }
    public double dp(int[] A,int K,double[] arr,int s,int n,double[][] mp)
    {
        if(mp[s][K]!=0)
            return mp[s][K];
        if(K==1)
            return mp[s][K]=((double)((arr[n-1]-arr[s]+A[s])/(n-s)));
        
        
        // double res=0;
        
        for(int i=s;i<=n-K;i++)
        {
            mp[s][K]=Math.max(mp[s][K],((double) ((arr[i]-arr[s]+A[s])/(i-s+1) +dp(A,K-1,arr,i+1,n,mp))));
        }
                         
        return mp[s][K];
    }
}
