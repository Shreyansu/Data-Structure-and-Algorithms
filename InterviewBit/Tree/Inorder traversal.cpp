vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    stack<TreeNode*> q;
    // q.push(A);
    vector<int> res;
    TreeNode* curr=A;
    while(true)
    {
        while(curr)
        {
            q.push(curr);
            curr=curr->left;
        }
        if(q.empty())
            break;
         curr=q.top();
        q.pop();
        res.push_back(curr->val);
        curr=curr->right;
    }
    
    return res;
}
