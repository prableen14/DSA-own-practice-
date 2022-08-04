/*
1. Given a Binary Tree, print Diagonal order sum of it. 
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
17 10 1 
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

vector<int> diagonalOrderSum(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){ //each diagonal
        int size=q.size();
        int sum=0; //this is saving each diagonal in a vector
        while(size-->0){ //help to traverse each component of particular diagonal
            TreeNode* rm= q.front();
            q.pop();
            while(rm!=NULL){ //traverse a component
            sum+=rm->val;
            if(rm->left!=NULL) q.push(rm->left);
            rm=rm->right;
            }
        }
        ans.push_back(sum);
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

    vector<int> ans = diagonalOrderSum(root);
    int idx = 0;
    for (auto j : ans)
    {
            cout << j << " ";
    }
}

int main()
{
    solve();
    return 0;
}
