/*
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]

Constraints:
The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/
class Solution {
public:
     vector<string>V;
    void dfs(TreeNode* root, string s)
    {
        if(root==NULL)
        {
            return;
        } 
        if(root->left == NULL and root->right==NULL)
        {
            V.push_back(s+to_string(root->val));
        }
        dfs(root->left, s+to_string(root->val)+"->");
        dfs(root->right, s+to_string(root->val)+"->");   
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return V;
    }
};
