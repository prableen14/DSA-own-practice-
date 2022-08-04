/*
1. Given a Binary Tree, return root To Node path of it. 
Input Format
Input is managed for you.
Output Format
Input is managed for you.
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
5
Sample Output
5 6 4 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};

vector<TreeNode*> nodeToRootPath_(TreeNode* root, int data)
{
    if(root==NULL){
        vector<TreeNode*> base;
        return base;
    }
    if(root->val==data){ vector<TreeNode*> ans;
    ans.push_back(root);
    return ans;
    }
    
    vector<TreeNode*> left=nodeToRootPath_(root->left,data);
    if(left.size()!=0){
        left.push_back(root);
        return left;
    }
     vector<TreeNode*> right=nodeToRootPath_(root->right,data);
    if(right.size()!=0){
        right.push_back(root);
        return right;
    }
    vector<TreeNode*> base;
        return base;
}
vector<TreeNode*> nodeToRootPath(TreeNode* root, int data){
    return nodeToRootPath_(root,data);
}
// input_section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{

  if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
  {
    IDX[0]++;
    return nullptr;
  }

  TreeNode* node = new TreeNode(arr[IDX[0]++]);
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
  TreeNode* root = createTree(arr, IDX);

  int data;
  cin >> data;
  vector<TreeNode*> ans = nodeToRootPath(root, data);
  if (ans.size() == 0)
    cout << endl;
  for (TreeNode* node : ans)
  {
    cout << node->val << " ";
  }
}

int main()
{
  solve();
  return 0;
}
