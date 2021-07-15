// 95. Unique Binary Search Trees II
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// Example 1:
// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

// Example 2:
// Input: n = 1
// Output: [[1]]

class Solution {
public:
    
	// function that takes sub parameters left and right value
    vector<TreeNode*> solve(int l,int r){
        vector<TreeNode*> ans;
        
		// if l>r just return null
        if(l>r){
            ans.push_back(NULL);
            return ans;
        }
		// if l==r  then we have only 1 node with value l or r
        if(l==r){
            TreeNode* temp=new TreeNode(l);
            ans.push_back(temp);
            return ans;
        }
        
		// else for every k between l to r append subtree of values left to it to left child and subtrees of values right to it to right child of k
        vector<TreeNode*> ansl; // stores pointer to left subtree
        vector<TreeNode*> ansr; // stores pointer to right subtree

        for(int k=l;k<=r;k++){
            ansl = solve(l,k-1);
            ansr = solve(k+1,r);
            if(ansl.size()==0) ansl.push_back(NULL);
            if(ansr.size()==0) ansr.push_back(NULL);
			
			// make all combinations with left current and right
            for(int i=0;i<ansl.size();i++){
                for(int j=0;j<ansr.size();j++){
                    TreeNode* temp = new TreeNode(k,ansl[i],ansr[j]);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    
    
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1,n);
        
    }
};
