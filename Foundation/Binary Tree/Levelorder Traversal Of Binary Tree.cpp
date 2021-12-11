/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of levelorder function. The function is expected to print tree level by level, left to right. Each level must be on a separate line and elements of same level should be separated by space
3. Input is managed for you.
Input Format
Input is managed for you
Output Format
Each level must be on a separate line and elements of same level should be separated by space
Constraints
None
Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
Sample Output
50 
25 75 
12 37 62 87 
30 70 
*/
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>

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

void display(Node* node) {
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


void levelOrder(Node* node) {
  // write your code here
   queue<Node*> mq;
  mq.push(node);

  while (mq.size() > 0) {
    int count = mq.size();

    for (int i = 0; i < count; i++) {
      node = mq.front();
      mq.pop();
      cout << node->data << " ";

      if (node->left != nullptr) {
        mq.push(node->left);
      }

      if (node->right != nullptr) {
        mq.push(node->right);
      }
    }
    cout << endl;
}
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if (temp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(temp);
    }
  }
  Node* root = constructTree(arr);
  levelOrder(root);
}
