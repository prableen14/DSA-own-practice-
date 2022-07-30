/*
1. Given a Binary Tree, return inorder Traversal of it. 
2. For more Information watch given video link below.
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
Sample Output
1 2 3 4 5 6 7 
*/
TreeNode* getRightmostNode(TreeNode* leftNode, TreeNode* curr)
{
    while(leftNode->right!=NULL && leftNode->right!=curr){
        leftNode=leftNode->right;
    }
    return leftNode;
    }
    
vector<int> morrisInTraversal(TreeNode* root) {
 vector<int> ans;
 TreeNode* curr=root;

 while(curr!=NULL){
    TreeNode* leftNode=curr->left;
    if(leftNode==NULL){
        ans.push_back(curr->val);
        curr=curr->right;
    }
    else{
        TreeNode* rightmostNode= getRightmostNode(leftNode,curr);
    
    if(rightmostNode->right==NULL){ //thread create
        rightmostNode->right=curr;
        curr=curr->left;
    }
    else{  //thread cut down
        rightmostNode->right=NULL;
        ans.push_back(curr->val);
        curr=curr->right;
     }
    }
}
return ans;
}
