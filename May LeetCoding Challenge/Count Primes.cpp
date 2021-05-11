class Solution {
public:
    int mx=5000001;
    int countPrimes(int n) 
    {
        vector<long long> prime;
        vector<long long> spf(mx);
        vector<bool> isprime(mx,true);
        
        
        for(int i=2;i<n;i++)
        {
            if(isprime[i])
            {
                prime.push_back(i);
                spf[i]=i;
                
            }
            for(int j=0;j<prime.size() && i*prime[j]<n && prime[j]<=spf[i];j++)
            {
                isprime[i*prime[j]]=false;
                spf[i*prime[j]]=prime[j];
            }
        }
        return prime.size();
    }
};
