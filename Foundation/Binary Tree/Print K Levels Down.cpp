/*
1. You are given a partially written BinaryTree class.
2. You are given a value k.
3. You are required to complete the body of printKLevelsDown function. The function is expected to print in different lines all nodes which are k level deep. Use preorder for printing.
4. Input is managed for you.
Input Format
Input is managed for you
Output Format
All nodes k-level deep printed in separated lines and visited in preorder
Constraints
None
Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
3
Sample Output
30
70
*/
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
class Node {
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data) {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr) {
  if (idx == arr.size() || arr[idx] == -1) {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}

void kLevelsDown(Node* node, int k) {
  // write your code here
  if(node==nullptr || k<0) return;
  if(k==0) cout<<node->data<<endl;
  kLevelsDown(node->left,k-1);
  kLevelsDown(node->right,k-1);
}

int main() {
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
  Node* root = constructTree(arr);
  int k;
  cin >> k;
  kLevelsDown(root, k);
  return 0;
}
