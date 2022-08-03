/*
1. Given a Binary Tree, print Diagonal Order of it anti-clock wise. 
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
vector<vector<int>> diagonalOrderAnti(TreeNode *root)
{
   vector<vector<int>> ans;
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty()){
       int size=q.size();
       vector<int> smallAns;
       while(size-- >0){
           TreeNode* rm=q.front();
           q.pop();
           while(rm!=NULL){
           smallAns.push_back(rm->val);
           if(rm->right!=NULL) q.push(rm->right);
           rm=rm->left;
           }
       }
       ans.push_back(smallAns);
   }

    return ans;
}
