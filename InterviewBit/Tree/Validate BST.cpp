Recusrive solution using INT_MIN,INT_MAX:

 int helper(TreeNode* root,int minm,int maxm)
 {
     if(!root)
        return 1;
     if(root->val<=minm || root->val>=maxm)
        return 0;
        
     return helper(root->left,minm,root->val) && helper(root->right,root->val,maxm);
 }
 
 int Solution::isValidBST(TreeNode* A) 
{
    return helper(A,INT_MIN,INT_MAX);
  
}


Using Inorder:


int last=INT_MIN;
int inorder(TreeNode* A)
{
   
    if(!A)
        return 1;
    inorder(A->left);
    if(A->val<=last)
        return 0;
    last=A->val;
    inorder(A->right);
    
    return 1;
}

int Solution::isValidBST(TreeNode* A) 
{

    return inorder(A);
}
