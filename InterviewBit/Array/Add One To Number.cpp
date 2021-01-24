vector<int> Solution::plusOne(vector<int> &a) 
{
    while(a.size()!=1 && a[0]==0)
    {
        a.erase(a.begin());
        
    }
    if(a.size()==1 && a[0]==0)
    {
        a[0]=1;
        return a;
        
    }
    int n=a.size();
    int c=1;
    for(int i=n-1;i>=0;i--)
    {
        int rem=(c+a[i]);
        a[i]=rem%10;
        
        c=rem/10;
        if(c==0)
            break;
    }
    if(c>0)
        a.insert(a.begin(),1);
        
        
        
    
    return a;
}
