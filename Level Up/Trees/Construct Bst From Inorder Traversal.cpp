/*
1. You are given a partially written function to solve(Refer question video).
2. Task : Construct Binary Search Tree from given InOrder Traversal.
3. you will be given an array representing a valid InOrder of a Binary Search Tree. Program is required to create a unique Balanced Binary Search Tree.
Input Format
Input is managed for you.
Output Format
output is managed for you.
Constraints
0 <= Number of Nodes <= 10^9
-10^9 <= value of Node data <= 10^9
Valid InOrder traversal.
Sample Input
7
1 2 3 4 5 6 7
Sample Output
2 -> 4 <- 6
1 -> 2 <- 3
. -> 1 <- .
. -> 3 <- .
5 -> 6 <- 7
. -> 5 <- .
. -> 7 <- .
*/
TreeNode* construct(vector<int> &inorder,int isi,int iei){
if(isi>iei) return NULL;
    int mid=(isi+iei)/2;
    TreeNode* node= new TreeNode(inorder[mid]);
    
    node->left=construct(inorder,isi,mid-1);
    node->right=construct(inorder,mid+1,iei);
    return node;
}

TreeNode* constructFromInOrder(vector<int> &inorder)
{
    int n=inorder.size();
    return construct(inorder,0,n-1);
}
