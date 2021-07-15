// 94. Given the root of a binary tree, return the inorder traversal of its nodes' values.
// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:
// Input: root = []
// Output: []

// Example 3:

// Input: root = [1]
// Output: [1]

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
         vector <int> v1, v2, v3;
    
    if(root == NULL)
        return v1;
    
    v2 = inorderTraversal(root->left);
    if(!v2.empty())
        if(!v1.empty())
            v1.insert( v1.end(), v2.begin(), v2.end());
        else
            v1 = v2;
    
    v1.push_back(root->val);
    v3 = inorderTraversal(root->right);
    if(!v3.empty())           
        v1.insert(v1.end(), v3.begin(), v3.end());
    
    return v1;   
    }
};
