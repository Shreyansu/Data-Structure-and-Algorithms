class Solution {
    public boolean flipEquiv(TreeNode r1, TreeNode r2) 
    {
        Queue<TreeNode> q1=new LinkedList<>();
        Queue<TreeNode> q2=new LinkedList<>();
        q1.offer(r1);
        q2.offer(r2);
        while(!q1.isEmpty() && !q2.isEmpty())
        {
            TreeNode x=q1.poll();
            TreeNode y=q2.poll();
            
            if(x==null && y==null)
                continue;
            
            if(!equal(x,y))
                return false;
            if(equal(x.left,y.left) && equal(x.right,y.right))
            {
                q1.offer(x.left);
                q1.offer(x.right);
                q2.offer(y.left);
                q2.offer(y.right);
            }
            else if(equal(x.left,y.right) && equal(x.right,y.left))
            {
                q1.offer(x.left);
                q1.offer(x.right);
                q2.offer(y.right);
                q2.offer(y.left);
            }
            else
                return false;
            
            
        }
        
        return q1.isEmpty() && q2.isEmpty();
        
        
    }
    public boolean equal(TreeNode r1,TreeNode r2)
    {
        if(r1==null && r2==null)
            return true;
        if(r1!=null && r2!=null && r1.val==r2.val)
            return true;
        return false;
    }
    
    
    
    
}
