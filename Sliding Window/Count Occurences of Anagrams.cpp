class Solution{
    
    bool check(vector<int>& patV,vector<int>& txtV)
    {
        for(int i=0;i<26;i++)
            if(patV[i]!=txtV[i])
                return false;
        
        return true;
    }
public:
	int search(string pat, string txt) 
	{
	    int k=pat.size();
	    int sz=txt.size();
	    
	    vector<int> patV(26,0);
	    vector<int> txtV(26,0);
	    
	    for(int i=0;i<k;i++)
	        patV[int(pat[i])-97]++;
	    int i=0,j=0;
	    int count=0;
	    while(j<sz)
	    {
	        txtV[int(txt[j])-97]++;
	        if(j-i+1<k)
	            j++;
	        else if(j-i+1==k)
	        {
	            if(check(patV,txtV))
	                count++;
	           txtV[int(txt[i])-97]--;
	           i++;
	           j++;
	        }
	    }
	    
	    return count;
	    
	}

};
