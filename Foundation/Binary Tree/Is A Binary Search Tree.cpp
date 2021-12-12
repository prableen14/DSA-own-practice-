/*
1. You are given a partially written BinaryTree class.
2. You are required to check if the tree is a Binary Search Tree (BST) as well. 
In a BST every node has a value greater than all nodes on it's left side and smaller value than all node on it's right side.
3. Input is managed for you. 

Note -> Please refer the question video for clarity.
Input Format
Input is managed for you.
Output Format
true if the tree is a BST, false otherwise
Constraints
Time complexity must be O(n)
Space should not be more than required for recursion (call-stack)
Sample Input
15
50 25 12 n n 37 n n 75 62 n n 87 n n
Sample Output
true
*/
//USING POSTORDER
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
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
Node* constructTree(vector<int>& arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

//Display function
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
//Height function
int height(Node* node)
{
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}

class bst {
public:
  bool isbst = false;
  int max = 0;
  int min = 0;
};

bst Bst(Node* node) {

  if (node == nullptr)
  {
    bst bres;
    bres.isbst = true;
    bres.max = INT_MIN;
    bres.min = INT_MAX;
    return bres;
  }
  bst l = Bst(node->left);
  bst r = Bst(node->right);

  bst mp; //my pair (for parent of any node at any level)

  mp.max = max(node->data, max(l.max, r.max));
  mp.min = min(node->data, min(l.min, r.min));

  if (l.isbst == true && r.isbst == true && (node->data>l.max && node->data<r.min)) {
    mp.isbst = true;
  }
  return mp;
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    if (tmp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(tmp);
    }
  }
  Node* root = constructTree(arr);

  bst r = Bst(root);
  if (r.isbst == 1)
    cout << "true";
  else
    cout << "false";
}
