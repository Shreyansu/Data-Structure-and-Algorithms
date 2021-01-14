Recursive Solution:

TreeNode* helper(const vector<int>& A,int start,int end)
{
    if(start>end)
        return nullptr;
    int mid=start+(end-start)/2;
    TreeNode* node=new TreeNode(A[mid]);
    node->left=helper(A,start,mid-1);
    node->right=helper(A,mid+1,end);
    
    return node;
    
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) 
{
    if(A.size()==0)
        return nullptr;
    return helper(A,0,A.size()-1);
}
