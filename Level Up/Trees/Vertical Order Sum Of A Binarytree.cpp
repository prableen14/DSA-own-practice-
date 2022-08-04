/*
1. Given a Binary Tree, print Vertical Order Sum of it. 
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
2
3
2
*/
#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};
class vPair{
    public:
    TreeNode* node=nullptr;
    int hl=0; //horizontal level
    vPair(TreeNode* node, int hl){
        this->node=node;
        this->hl=hl;
    }
};
void width(TreeNode* root,int hl,vector<int> &ans){
    if(root==NULL) return;
    
    ans[0]=min(ans[0],hl);
    ans[1]=max(ans[1],hl);
    
    width(root->left,hl-1,ans);
    width(root->right,hl+1,ans);
}
vector<int> verticalOrderSum(TreeNode *root)
{
    list<vPair*> q;
    vector<int> minMax(2);
    width(root,0,minMax);
    int len=minMax[1]-minMax[0]+1;
    vector<int> ans;
    for(int i=0;i<len;i++) ans.push_back(0);
    vPair* temp= new vPair(root, abs(minMax[0]));
    q.push_back(temp);
    while(!q.empty()){
        int size=q.size();
        while(size-- >0){
            vPair* rp= q.front();
            q.pop_front();
            ans[rp->hl]=ans[rp->hl]+rp->node->val;
            if(rp->node->left!=NULL) q.push_back(new vPair(rp->node->left,rp->hl-1));
            if(rp->node->right!=NULL) q.push_back(new vPair(rp->node->right,rp->hl+1));
        }
    }
    return ans;
}

// input_section=================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

    vector<int> ans = verticalOrderSum(root);
    for (int j : ans)
    {
        cout << j << " "<<"\n";
    }
}

int main()
{
    solve();
    return 0;
}
