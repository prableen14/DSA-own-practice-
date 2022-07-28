/*Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
 
Constraints:
The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p==NULL && q==NULL) return true;
      else if(p==NULL || q==NULL) return false;
        else if(p->val!=q->val) return false;
        else 
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};
//ANOTHER WAY
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
         
    // If both are NULL trees, they are identical.       
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    
    // If any one of the trees is NULL, they are not identical. 
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    
    // Check if root's data of both the trees is same. 
    // Recursively check if left subtree and right subtree of both trees is identical. 
    // Return true only if all conditions satisfy. 
    
    return (root1->data == root2->data) && 
            identicalTrees(root1->left, root2->left) && 
            identicalTrees(root1->right, root2->right);
    
}
