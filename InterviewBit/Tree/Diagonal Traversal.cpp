void helper(TreeNode* root,int d,map<int,vector<int>>& mp)
{
    if(!root)
        return;
    mp[d].push_back(root->val);
    helper(root->left,d+1,mp);
    helper(root->right,d,mp);
}
 
vector<int> Solution::solve(TreeNode* root) 
{
    vector<int> res;
    if(!root)
        return {};
    map<int,vector<int>> mp;
    helper(root,0,mp);
    for(auto i:mp)
    {
        for(auto j:i.second)
            res.push_back(j);
    }
    return res;
    
}
