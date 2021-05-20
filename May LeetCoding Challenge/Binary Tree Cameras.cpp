class Solution {
public:
    int res=0;
    int minCameraCover(TreeNode* root) 
    {
        if(dfs(root)==-1)
            return ++res;
        return res;
        
    }
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 1;
        // if(root->left==NULL && root->right==NULL)
        //     return -1;
        int left=dfs(root->left);
        int right=dfs(root->right);
        
        if(left==-1 || right==-1)
        {
            res++;
            return 0;
            
        }
        if(left==0 || right==0)
            return 1;
        
        
        return -1;
        
    }
};
