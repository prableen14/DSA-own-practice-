/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of transBackFromLeftClonedTree function. 
The function is expected to convert a left-cloned tree back to it's original form. 
The left cloned tree is dicussed in previous question. In a left-clone tree a new node for every node equal in value to it is inserted between itself and it's left child.
3. Input and Output is managed for you.
Input Format
Input is managed for you.
Output Format
Output is managed for you. 
Constraints
None
Sample Input
37
50 50 25 25 12 12 n n n n 37 37 30 30 n n n n n n 75 75 62 62 n n 70 70 n n n n 87 87 n n n
Sample Output
25 <- 50 -> 75
12 <- 25 -> 37
. <- 12 -> .
30 <- 37 -> .
. <- 30 -> .
62 <- 75 -> 87
. <- 62 -> 70
. <- 70 -> .
. <- 87 -> .
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

void display(Node* node) {
  if (node == nullptr) {
    return;
  }

  string str = "";
  str += node->left == nullptr ? "." : to_string(node->left->data) + "";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right == nullptr ? "." : to_string(node->right->data) + "";
  cout << str << endl;

  display(node->left);
  display(node->right);
}

Node* transBackFromLeftClonedTree(Node* node) {
  // write your code here
  if(node==nullptr) 
  return nullptr;
  Node* lnn=transBackFromLeftClonedTree(node->left->left); //left normalized node
  Node* rnn=transBackFromLeftClonedTree(node->right);     //right normalized node
  node->left=lnn;
  node->right=rnn;
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
  Node* root = constructTree(arr);
  root = transBackFromLeftClonedTree(root);
  display(root);
}
