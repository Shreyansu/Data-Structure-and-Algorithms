class Solution {
public:
    TreeNode* sorted(vector<int>& res,int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=start+(end-start)/2;
        
        TreeNode* temp=new TreeNode(res[mid]);
        temp->left=sorted(res,start,mid-1);
        temp->right=sorted(res,mid+1,end);
        
        return temp;
    }
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        vector<int> res;
        while(head!=NULL)
        {
            res.push_back(head->val);
            head=head->next;
        }
        
        int n=res.size();
        
        return sorted(res,0,n-1);
        
    }
};
