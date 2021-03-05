class Solution {
public:
    int calculate(string s) 
    {
        stack<int> st;
        int sign=1;
        int num=0,ans=0;
        st.push(1);
        
        for(auto i:s)
        {
            if(i>='0' && i<='9')
                num=num*10+i-'0';
            else if(i=='+' || i=='-')
            {
                ans=ans+sign*st.top()*num;
                num=0;
                sign=(i=='+')?1:-1;
            }
            else if(i=='(')
            {
                st.push(st.top()*sign);
                
                sign=1;
            }
            else if(i==')')
            {
                ans=ans+sign*st.top()*num;
                num=0;
                sign=1;
                st.pop();
            }
        }
        if(num>0)
        {
            ans=ans+sign*st.top()*num;
        }
        return ans;
        
    }
};
