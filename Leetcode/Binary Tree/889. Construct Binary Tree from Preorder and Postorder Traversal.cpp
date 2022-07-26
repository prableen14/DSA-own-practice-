/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder 
traversal of the same tree, reconstruct and return the binary tree.
If there exist multiple answers, you can return any of them.

Example 1:
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:
Input: preorder = [1], postorder = [1]
Output: [1]

Constraints:
1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
*/
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return construct(preorder,postorder,0,n-1,0,n-1);
    }
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder,int prsi,int prei, int posi, int poei) {
        if(prsi>prei) return NULL;
        TreeNode* node= new TreeNode(preorder[prsi]);
        if(prsi==prei) return node;
        int idx=posi;
        
        while(preorder[prsi+1]!=postorder[idx]) idx++;
        int te=idx-posi+1;
        
        node->left=construct(preorder,postorder,prsi+1,prsi+te,posi,idx);
        node->right=construct(preorder,postorder,prsi+te+1,prei,idx+1,poei-1);
        
        return node;
    }
};
