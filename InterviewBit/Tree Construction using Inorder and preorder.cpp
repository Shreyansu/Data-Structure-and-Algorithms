 TreeNode* build(vector<int> &A,vector<int> &B,int start,int end,int &ps)
 {
     if(start>end)
        return nullptr;
    TreeNode* node= new TreeNode(A[ps++]);
    int pos=-1;
    for(int i=start;i<=end;i++)
    {
        if(B[i]==node->val)
        {
            pos=i;
            break;
        }
    }
    node->left=build(A,B,start,pos-1,ps);
    node->right=build(A,B,pos+1,end,ps);
    
    
    return node;
 }
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    int ps=0;
    return build(A,B,0,B.size()-1,ps);
}
