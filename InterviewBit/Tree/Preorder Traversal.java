public class Solution {
    public ArrayList<Integer> preorderTraversal(TreeNode A) 
    {
        
            ArrayList<Integer> res=new ArrayList<Integer>();
    
            Stack<TreeNode> st =new Stack<>();
            st.push(A);
            
            while(!st.isEmpty())
            {
                TreeNode cur=st.pop();
                // st.pop();
                res.add(cur.val);
                if(cur.right!=null)
                    st.push(cur.right);
                if(cur.left!=null)
                    st.push(cur.left);
                
            }
            
            
            return res;
    
        
    }
}
