
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) 
{
    vector<vector<int>> v;
    if(!A)
        return v;
        
    queue<TreeNode*> q;
    q.push(A);
    int i=1;
    // v.push_back({A->val});
    
    while(!q.empty())
    {
        
        int sz=q.size();
        vector<int> v2;
        while(sz--)
        {
            TreeNode* root=q.front();
            q.pop();
            v2.push_back(root->val);
            if(root->left !=NULL)
            {
                q.push(root->left);
                
                    // st.push(root->left->val);
                
                // v2.push_back(root->left->val);
            }
            if(root->right !=NULL)
            {
                q.push(root->right);
                
                    // st.push(root->right->val);
                
                // v2.push_back(root->right->val);
            }
            
        }
        if(i%2==0)
            reverse(v2.begin(),v2.end());
        v.push_back(v2);
        i++;
        
    }
    return v;
}
