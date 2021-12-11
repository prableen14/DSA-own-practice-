/*
1. You are given a partially written BinaryTree class.
2. You are given a value data and a value k.
3. You are required to complete the body of printKNodesFar function. The function is expected to print all nodes which are k distance away in any direction from node with value equal to data.
4. Input is managed for you.
Input Format
Input is managed for you
Output Format
All nodes which are k distance away in any direction from node with value equal to data, each in a separate line
Constraints
None
Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
37
2
Sample Output
12
50
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data, Node* left, Node* right)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++], nullptr, nullptr);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

vector<Node*> nodeToRootPath(Node* node, int data) {
  vector<Node*> temp;
  if (node == nullptr) {
    return temp;
  }

  vector<Node*> ans;
  if (node->data == data) {
    ans.push_back(node);
    return ans;
  }
  vector<Node*> left = nodeToRootPath(node->left, data);
  if (left.size() > 0) {
    left.push_back(node);
    return left;
  }
  vector<Node*> right = nodeToRootPath(node->right, data);
  if (right.size() > 0) {
    right.push_back(node);
    return right;
  }
  return temp;
}


void printKLevelsDown(Node* node, int k, Node* block)
{
  if (node == nullptr || node == block)
    return;

  if (k == 0)
  {
    cout << node->data << endl;
    return;
  }

  printKLevelsDown(node->left, k - 1, block);
  printKLevelsDown(node->right, k - 1, block);
}

void printKNodesFar(Node* node, int data, int k)
{
  // write your code here
  if (node == nullptr)
    return;
  vector<Node*> path = nodeToRootPath(node, data); //We fill the ArrayList with root to that node path
  for (int i = 0; i < path.size(); i++)
  {
    printKLevelsDown(path[i], k - i,i==0? nullptr : path[i-1]);
  }
}

int main()
{
  vector<int> arr;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string inp;
    cin >> inp;
    if (inp != "n") {
      arr.push_back(stoi(inp));
    }
    else {
      arr.push_back(-1);
    }
  }

  int data;
  cin >> data;
  int k;
  cin >> k;
  Node* root = constructTree(arr);
  printKNodesFar(root, data, k);

  return 0;
}
