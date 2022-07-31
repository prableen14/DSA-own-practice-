/*
1. Given a Binary Tree, print Right view of it. 
2. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.
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
1
1
1
1
1
*/
vector<int> rightView(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        ans.push_back(q.back()->val);
        while(n-->0){
            TreeNode* rm= q.front();
            q.pop();
            if(rm->left!=NULL) q.push(rm->left);
            if(rm->right!=NULL) q.push(rm->right);
        }
    }
    return ans;
}
