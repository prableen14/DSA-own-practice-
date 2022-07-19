/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector < vector < int >> v;
  if (root == NULL) {
    return v;
  }

  queue < TreeNode * > q;
  q.push(root);
  bool stateofTraversal = true;

  while (!q.empty()) {
    int x = q.size();
    vector < int > v1(x); //if we dont define size of vector v1 then code is giving error
    for (int i = 0; i < x; i++) {
      TreeNode * front = q.front();
      q.pop();

      // find position to fill node's value
      int index = (stateofTraversal) ? i : (x - 1 - i);

      v1[index] = front -> val;
      if (front -> left) {
        q.push(front -> left);
      }
      if (front -> right) {
        q.push(front -> right);
      }
    }
    // after this level
    stateofTraversal = !stateofTraversal;
    v.push_back(v1);
  }
  return v;
    }
};
