/*
1. You are given a partially written function to solve(Refer question video).
2. Task : Construct Binary Search Tree from given PostOrder Traversal.
3. you will be given an array representing a valid PostOrder of a Binary Search Tree. Program is required to create a unique Binary Search Tree.
Input Format
Input is managed for you.
Output Format
Output is managed for you. 
Constraints
0 <= Number of Nodes <= 10^9
-10^9 <= value of Node data <= 10^9
Valid PostOrder traversal.
Sample Input
6
1 2 6 7 5 3
Sample Output
2 -> 3 <- 5
1 -> 2 <- .
. -> 1 <- .
. -> 5 <- 7
6 -> 7 <- .
. -> 6 <- .*/
int idx=0;
TreeNode* construct(vector<int> &postorder,int lr,int rr){
    if(idx<0 || postorder[idx]<lr || postorder[idx]>rr) return NULL;
    
    TreeNode* node= new TreeNode(postorder[idx--]);
    
    node->right=construct(postorder,node->val,rr);
    node->left=construct(postorder,lr,node->val);
    
    return node;
}
TreeNode *bstFromPostorder(vector<int> &postorder)
{
    idx=postorder.size()-1;
    int lr=-1e8; //left range: negative infinity
    int rr=1e8;  //right range: positive infinity
    
   return construct(postorder,lr,rr);
}
