class Solution 
{
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        if(root == null)//base case when we reach to the null node 
            return null;//returning back 
        
        if(root == p || root == q)//wen we are founding the desired node we are returning it and deleting the current activation record 
            return root;
        
        TreeNode left= lowestCommonAncestor(root.left,p,q);//we are traversing the left subbtree 
        TreeNode right= lowestCommonAncestor(root.right,p,q);//and then the right subtree is trsversed 
        
        if(left != null && right != null)//when we got the lowest commont node from left and rigt subtree 
            return root;
        
        if(left == null && right == null)//when both(left,right) are null we return null as there is no chance of getting our desired node
            return null;
        
        return (left != null)?left: right;//when one of the node is null it returns the node without null in order to compare with the next node 
    }
}
