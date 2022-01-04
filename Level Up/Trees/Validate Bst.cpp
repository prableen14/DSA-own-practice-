/*
1. You are given a partially written function to solve.
2. Determine if it is a valid binary search tree (BST).
3. A valid BST is defined as follows:
   3.1 The left subtree of a node contains only nodes with keys less than the node's key.
   3.2 The right subtree of a node contains only nodes with keys greater than the node's key.
   3.3 Both the left and right subtrees must also be binary search trees.
Input Format
Input is managed for you.
Output Format
output is managed for you.
Constraints
0 <= Number of Nodes <= 10^9
-10^9 <= value of Node data <= 10^9
Sample Input
13
7
3
2
-1
-1
5
-1
-1
10
-1
12
-1
-1
Sample Output
true
*/
//using inorder
#include <vector>
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
TreeNode *previous=nullptr;
bool isValidBST(TreeNode *root)
{
    if(root==nullptr) return true;
    if(!isValidBST(root->left)) return false;
    if(previous!=nullptr && previous->val>=root->val) return false; 
    previous=root; 
     if(!isValidBST(root->right)) return false;
    return true;
}

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
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
    cout << (boolalpha) << isValidBST(root);
}

int main()
{
    solve();
    return 0;
}
