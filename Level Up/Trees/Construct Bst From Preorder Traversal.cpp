/*
1. You are given a partially written function to solve(Refer question video).
2. Task : Construct Binary Search Tree from given PreOrder Traversal.
3. you will be given an array representing a valid PreOrder of a Binary Search Tree. Program is required to create a unique Binary Search Tree.
Input Format
Input is managed for you.
Output Format
Output is managed for you.
Constraints
0 <= Number of Nodes <= 10^9
-10^9 <= value of Node data <= 10^9
Valid PreOrder traversal.
Sample Input
6
3 2 1 6 5 7
Sample Output
2 -> 3 <- 6
1 -> 2 <- .
. -> 1 <- .
5 -> 6 <- 7
. -> 5 <- .
. -> 7 <- .
*/
int idx=0;
TreeNode* construct(vector<int> &preorder,int lr,int rr){
    if(idx>=preorder.size()|| preorder[idx]<lr || preorder[idx]>rr) return NULL;
    
    TreeNode* node= new TreeNode(preorder[idx++]);
    
    node->left=construct(preorder,lr,node->val);
    node->right=construct(preorder,node->val,rr);
    
    return node;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int lr=-1e8; //left range: negative infinity
    int rr=1e8;  //right range: positive infinity
    
   return construct(preorder,lr,rr);
}
