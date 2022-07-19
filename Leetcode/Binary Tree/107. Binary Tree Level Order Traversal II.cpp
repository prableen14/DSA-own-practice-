/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/
//SAME AS LEVEL ORDER TRAVERSAL QUESTION (JUST REVERSAL STEP IS ADDED IN THE END)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if(root==NULL) return v;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            vector<int> v1;  
            while(x--){   
                 TreeNode* front= q.front();
            q.pop();
                if(front->left!=NULL) q.push(front->left);
                 if(front->right!=NULL) q.push(front->right);
                v1.push_back(front->val);
            }
            v.push_back(v1);  
        }
         reverse(v.begin(),v.end());
        return v;
    }
};
