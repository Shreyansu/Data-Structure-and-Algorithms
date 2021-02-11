class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> index;
        stack<char> character;
        
        index.push(-1);
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                index.push(i);
                character.push('(');
            }
            else
            {
                if(character.empty())
                    index.push(i);
                else if(character.top()=='(')
                {
                    character.pop();
                    index.pop();
                    res=max(res,i-index.top());
                }
            }
        }
        
        return res;
    }
};
