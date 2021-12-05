/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. 
It will automatically contact the police if two directly-linked houses were broken into on the same night.
Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police. 

Example 1:
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

Constraints:
The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
*/
class Solution {
public:
    //DP on trees
    //Time Complexity O(N) N=number of nodes
    //Space Complexity O(N)
    unordered_map<TreeNode*,int> mp;
    int helper(TreeNode* root){
       if(root==NULL) return 0;   
        if(mp.count(root)) return mp[root];
       //option 1: rob current node
        int op1=root->val;
        if(root->left) op1+=helper(root->left->left) + helper(root->left->right);
        if(root->right) op1+=helper(root->right->left) + helper(root->right->right);
        
        //option 2: not rob current node
        int op2=helper(root->left)+helper(root->right);
        
        return mp[root]=max(op1,op2);
    }
    
    int rob(TreeNode* root) {
       int ans=helper(root);
       return ans;
    }
};
