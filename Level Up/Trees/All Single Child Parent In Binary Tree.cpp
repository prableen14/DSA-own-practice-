/*
1. Given a Binary Tree, return list of all single child parent of binary tree
Input Format
Input is managed for you.
Output Format
Output is managed for you. 
Constraints
0 <= Number of Nodes <= 10^5
-1000 <= value of Node data <= 1000
Sample Input
15
4
2
1
-1
-1
3
-1
-1
6
5
-1
-1
7
-1
-1
*/
void exactlyOneChild(TreeNode* root,vector<int> &ans){
    if(root==NULL ||(root->left==NULL && root->right==NULL)) return; //leaf nodes
    
    if(root->left==NULL || root->right==NULL) { //node with single child
    ans.push_back(root->val); //we wont put return statement after this line because if we return from this node then we wont be able to explore further nodes of it(Those nodes may have single child)
}
    exactlyOneChild(root->left,ans);
    exactlyOneChild(root->right,ans);
}
vector<int> exactlyOneChild(TreeNode* root)
{
  vector<int> ans;
  exactlyOneChild(root,ans);
  return ans;
}
