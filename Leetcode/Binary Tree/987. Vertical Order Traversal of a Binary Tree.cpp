/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column
and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

Example 3:
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
           map<int,vector<int>> mp;    // create Map of int and vector<int>
        vector<vector<int>> ans;    // to store and return ans
        
        queue<pair<TreeNode*,int>> q;   // queue of pair of TreeNode and int
        q.push({root, 0});  // push root and 0 for column
        
        while(!q.empty()){
             vector< pair <int,int> > temp;   // values will not be stored in ascending order. see example below code for reference
            int n = q.size();
            
            while(n--){
                TreeNode *curr = q.front().first;
                int h = q.front().second;
                temp.push_back(make_pair(h, curr->val));    // firstly store in temp
                q.pop();
                
                if(curr->left)
                    q.push({curr->left, h-1});  // push if left then col - 1

                if(curr->right)
                    q.push({curr->right, h+1});  // push if right then col +1
            }
            for(auto it: temp)
                mp[it.first].push_back(it.second);  // secondly store in map
        }
        for(auto it: mp)
            ans.push_back(it.second);   // lastly store in ans vector
        
        return ans;
    }
};
/*If we take vector instead of multiset then the answer is not in correct sequence as left subtre is written first(see example below). But in case of multiset, elements are in ascending order.
Wrong Answer
Input
[1,2,3,4,6,5,7]
Output
[[4],[2],[1,6,5],[3],[7]]
Expected
[[4],[2],[1,5,6],[3],[7]]*/

//Using Multiset( Maintaining the correct sequence of ascending order)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
           map<int,vector<int>> mp;    // create Map of int and vector<int>
        vector<vector<int>> ans;    // to store and return ans
        
        queue<pair<TreeNode*,int>> q;   // queue of pair of TreeNode and int
        q.push({root, 0});  // push root and 0 for column
        
        while(!q.empty()){
             multiset< pair <int,int> > temp;   // to store values in correct sequence
            int n = q.size();
            
            while(n--){
                TreeNode *curr = q.front().first;
                int h = q.front().second;
                temp.insert({h, curr->val});    // firstly store in temp
                q.pop();
                
                if(curr->left)
                    q.push({curr->left, h-1});  // push if left then col - 1

                if(curr->right)
                    q.push({curr->right, h+1});  // push if right then col +1
            }
            for(auto it: temp)
                mp[it.first].push_back(it.second);  // secondly store in map
        }
        for(auto it: mp)
            ans.push_back(it.second);   // lastly store in ans vector
        
        return ans;
    }
};
