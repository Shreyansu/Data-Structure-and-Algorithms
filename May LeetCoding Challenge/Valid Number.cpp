class Solution {
public:
    bool isInteger(string s,int index){
        int n = s.length();
        if(index == n)
            return false;
        
        if(s[index]=='+' || s[index]=='-'){
            index++;
        }
        if(index==n)
            return false;
        while(index < n && isdigit(s[index]) )
            index++;
        return (index == s.length());
    }
    
    bool isDecimal(string s,int index){
        int n=s.length();
        while(index <n && isdigit(s[index]) )
            index++;
        if(index==n)
            return true;
        if(s[index]=='e' || s[index]=='E'){
            
            //Corner case #4 :
            if(index<2 || (!isdigit(s[index-2]) && !isdigit(s[index-1])) )
                return false;
            
            return isInteger(s,index+1);
        }
        return false;
    }
    bool isNumber(string s) {
        int n = s.length();
        int i=0;
        bool isSign = false;
        if(s[i]=='+' || s[i]=='-'){
            i++;
            isSign = true;
        }
        //Corner case #0 :
        if(i==n)
            return false;
        
        
        while(i<n && isdigit(s[i]) )
            i++;
        
        //Situation 1 - All digits
        if(i==n)
            return true;
        
        //Situation 2 - Encountered a decimal
        if(s[i] == '.'){
            
            //Corner case #1 :
            if(n == 1)
                return false;
            
            //Corner case #2 :
            if(i==1 && isSign && i+1==n)
                return false;
            
            return isDecimal(s,i+1);
        }
        
        //Situation 3 - Encountered 'e'/'E'
        if(s[i]=='e' || s[i]=='E'){
            
            //Corner case #3 :
            if(i == 0 || (i == 1 && isSign))
                return false;

            return isInteger(s,i+1);
        }
        
        return false;
    }
};
