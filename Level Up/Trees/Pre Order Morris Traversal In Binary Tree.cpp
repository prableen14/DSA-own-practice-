/*
1. Given a Binary Tree, return Preorder Traversal of it. 
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
4 2 1 3 6 5 7 
*/
TreeNode* getrightmostNode(TreeNode* leftNode, TreeNode* curr){
    while(leftNode->right!=NULL && leftNode->right!=curr){
        leftNode=leftNode->right;
    }
    return leftNode;
}
vector<int> morrisPreTraversal(TreeNode* root) {
vector<int> ans;
TreeNode* curr= root;
while(curr!=NULL){
    TreeNode* leftNode=curr->left;
    if(leftNode==NULL){
        ans.push_back(curr->val);
        curr=curr->right;
    }
    else{
        TreeNode* rightmostNode= getrightmostNode(leftNode,curr);
        
        if(rightmostNode->right==NULL){ //thread create
            rightmostNode->right=curr;
            ans.push_back(curr->val);
            curr=curr->left;
        }
        else{    //thread cut down
            rightmostNode->right==NULL;
            curr=curr->right;
        }
    }
}
return ans;
}
