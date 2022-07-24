/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
 
Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n=preorder.size();
        return build(preorder,inorder,0,n-1,0,n-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int psi,int pei,int isi, int iei) {
        if(isi>iei) return NULL;
        
        int idx=isi;
        while(inorder[idx]!=preorder[psi]) idx++;
        int colse=idx-isi;
        TreeNode* node=  new TreeNode(preorder[psi]);
        node->left=build(preorder,inorder,psi+1,psi+colse,isi,idx-1);
        node->right=build(preorder,inorder,psi+colse+1,pei,idx+1,iei);
        
        return node;
    }   
};
//isi - inorder starting index
//iei - inorder ending index
//psi - preorder starting index
//pei - preorder ending index
