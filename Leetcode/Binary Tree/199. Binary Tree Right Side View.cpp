/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode *> que;
    que.push(root);
    vector<int> ans;
    if(root==nullptr) return ans;
    while (que.size() != 0)
    {
        int size = que.size();
        ans.push_back(que.front()->val);
        while (size-- > 0)
        {
            TreeNode *rn = que.front(); // rn : remove Node
            que.pop();

            if (rn->right != nullptr)
                que.push(rn->right);
            if (rn->left != nullptr)
                que.push(rn->left);
        }
    }
    return ans;
    }
};
