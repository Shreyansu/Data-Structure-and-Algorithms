class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp;
            while(sz--)
            {
                temp.push_back(q.front()->val);
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
