/*
1. Given a Binary Tree, print Diagonal Order of it. 
Input Format
Input is managed for you.
Output Format
Output is managed for you. 
Constraints
0 <= Number of Nodes <= 10^5
-1000 <= value of Node data <= 1000
Sample Input
15
1
1
-1
1
1
-1
1
-1
-1
1
-1
-1
1
-1
-1
Sample Output
0 -> 1 1 
1 -> 1 1 1 
2 -> 1 1 
*/
vector<vector<int>> diagonalOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){ //each diagonal
        int size=q.size();
        vector<int> smallAns; //this is saving each diagonal in a vector
        while(size-->0){ //help to traverse each component of particular diagonal
            TreeNode* rm= q.front();
            q.pop();
            while(rm!=NULL){ //traverse a component
            smallAns.push_back(rm->val);
            if(rm->left!=NULL) q.push(rm->left);
            rm=rm->right;
            }
        }
        ans.push_back(smallAns);
    }
    return ans;
}
