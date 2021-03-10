class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)
            return root;
        TreeNode* temp=root;
        if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            if(!root->right)
                return root->left;
            else
            {
                TreeNode* x=root->right;
                while(x->left!=NULL)
                    x=x->left;
                root->val=x->val;
                root->right=deleteNode(root->right,root->val);
            }
        }
        
        return temp;

        
    }
};
