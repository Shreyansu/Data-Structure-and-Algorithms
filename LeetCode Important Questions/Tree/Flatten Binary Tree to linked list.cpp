class Solution 
{
public:
    void flat(TreeNode* node)
    {
        if(node==NULL)
            return;
        if(node->left)
        {
            TreeNode* x=node->left;
            while(x->right!=NULL)
                x=x->right;
            if(node->right)
            {
                TreeNode* temp=node->right;
                node->right=node->left;
                x->right=temp;
            }
            else
            {
                node->right=node->left;
            }
            node->left=NULL;
        }
        flat(node->right);
    }
    void flatten(TreeNode* root) 
    {
        if(root==NULL)
            return;
        
        TreeNode* temp=root;
        flat(temp);  
    }
};
