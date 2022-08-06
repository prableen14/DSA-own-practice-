/*
1. Given a binary tree and target. 
2. Find the minimum time required to burn the complete binary tree if the target is set on fire. 
3. It is known that in 1 second all nodes connected to a given node get burned. That is, its left child, right child and parent.
Input Format
Input is managed for you.
Output Format
Output is managed for you. 
Constraints
1. The number of nodes in the tree is in the range [1, 10000].
2. -1000 <= Node.val <= 1000
3. All the values Node.val are unique.
4. target is the value of one of the nodes in the tree.
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
2
Sample Output
3
*/
int maxTime=0;
void burnTree(TreeNode* root,TreeNode* blockNode,int timee){
    if(root==NULL ||root==blockNode) return;
    
    maxTime=max(maxTime,timee);
    
    burnTree(root->left,blockNode,timee+1);
    burnTree(root->right,blockNode,timee+1);
}

int burningTree_(TreeNode* root, int fireNode)
{
        if(root==NULL) return -1;
    if(root->val==fireNode){
        burnTree(root,NULL,0);
        return 1;
    }
    int leftTime=burningTree_(root->left,fireNode);
    if(leftTime!=-1){
        burnTree(root,root->left,leftTime);
        return leftTime+1;
    }
    int rightTime=burningTree_(root->right,fireNode);
    if(rightTime!=-1){
        burnTree(root,root->right,rightTime);
        return rightTime+1;
    }
    return -1;
}
int burningTree(TreeNode* root, int fireNode){
    burningTree_(root,fireNode);
    return maxTime;
}
