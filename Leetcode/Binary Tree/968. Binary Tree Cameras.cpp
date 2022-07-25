/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 
Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
*/
class Solution {
public:
    int cameras=0;
    int minCameraCover(TreeNode* root) {
        if(minCameraCoverCount(root)==-1) cameras++;
        return cameras;
    }
    int minCameraCoverCount(TreeNode* root){
        if(root==NULL) return 1;
        
        int lchild=minCameraCoverCount(root->left);
        int rchild=minCameraCoverCount(root->right);
        
        //working in postorder
        if(lchild==-1 || rchild==-1){
            cameras++;
            return 0; //this thing i told to my parent
        }
        if(lchild==0 || rchild==0){
            return 1;
        }
        return -1; //if both my child is not having camera and is saying that they dont need camera because they are already covered, then i will ask my parent to take care of me. that is why -1 is returned.
    }
};
