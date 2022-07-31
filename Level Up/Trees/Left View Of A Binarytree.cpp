/*
1. Given a Binary Tree, print left view of it. 
2. Left view of a Binary Tree is set of nodes visible when tree is viewed from left side.
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
1
1
1
1
1
*/
#include <iostream>
#include <vector>
#include <queue>
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

class levelPair
{
public:
    TreeNode *par = nullptr;
    int lb = -(int)1e8;
    int rb = (int)1e8;

    levelPair()
    {
    }

    levelPair(TreeNode *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb;
        this->rb = rb;
    }
};

vector<int> leftView(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        ans.push_back(q.front()->val);
        while(n-->0){
            TreeNode* rm= q.front();
            q.pop();
            if(rm->left!=NULL) q.push(rm->left);
             if(rm->right!=NULL) q.push(rm->right);
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

       vector<int> ans = leftView(root);
    for (int i : ans)
        cout << i << endl;
}

int main()
{
    solve();
    return 0;
}
