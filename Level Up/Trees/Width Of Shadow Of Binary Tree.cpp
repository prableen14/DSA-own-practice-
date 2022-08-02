/*
1. Given a Binary Tree, return Width Of Shadow Of A Binary Tree. 
2. For more detail watch the video.
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
3
*/
void width(TreeNode *root,int l, int ans[])
{
    if(root==NULL) return;
    ans[0]=min(ans[0],l); 
    ans[1]=max(ans[1],l);
    width(root->left,l-1,ans);
    width(root->right,l+1,ans);
    
}
int width(TreeNode *root)
{
     int ans[2];
     width(root,0,ans);
     return (ans[1]-ans[0]+1);
     
}
