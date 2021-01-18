class Solution {
public:
    void helper(TreeNode* root,int sum,vector<int>& v,int& count)
    {
        if(!root)
            return;
        v.push_back(root->val);
        int s=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            s+=v[i];
            if(s==sum)
                count++;
        }
        helper(root->left,sum,v,count);
        helper(root->right,sum,v,count);
        v.pop_back();
    }
    
    
    
    int pathSum(TreeNode* root, int sum) 
    {
        vector<int> v;
        int count=0;
        if(!root)
            return 0;
        helper(root,sum,v,count);
        
        return count;
        
    }
};
