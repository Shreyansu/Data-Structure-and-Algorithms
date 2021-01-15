RECURSIVE SOLUTION:


 int isSym(TreeNode* t1,TreeNode* t2)
 {
     if(t1==NULL && t2==NULL)
        return 1;
     if(t1==NULL || t2==NULL)
        return 0;
        
    return (t1->val==t2->val) && isSym(t1->left,t2->right) && isSym(t1->right,t2->left);
 }
 
int Solution::isSymmetric(TreeNode* A) 
{
    return isSym(A,A);
}


ITERATIVE SOLUTION USING QUEUE:

int Solution::isSymmetric(TreeNode* A) 
{
    unordered_map<int,vector<int>> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({A,0});
    while(!q.empty())
    {
        auto x=q.front().first;
        int lev=q.front().second;
        q.pop();
        if(x->left)
        {
            q.push({x->left,lev+1});
            mp[lev+1].push_back(x->left->val);
        }
        if(x->right)
        {
            q.push({x->right,lev+1});
            mp[lev+1].push_back(x->right->val);
        }
        
        
    }
    for(auto i:mp)
    {
        auto k=i.second;
        if(k.size()%2==1)
            return false;
        for(int i=0;i<k.size()/2;i++)
        {
            if(k[i]!=k[k.size()-i-1])
                return false;
        }
    }
    return true;
}
