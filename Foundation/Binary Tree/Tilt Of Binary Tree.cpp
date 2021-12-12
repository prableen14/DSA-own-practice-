/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of tilt function. The function is expected to set the value of data member "tilt". "tilt" of a node is the absolute value of difference between sum of nodes in it's left subtree and right subtree. "tilt" of the whole tree is represented as the sum of "tilt"s of all it's nodes.
3. Input and Output is managed for you. 

Note -> Please refer the video for clarity.
Input Format
Input is managed for you.
Output Format
Output is managed for you. 
Constraints
None
Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
Sample Output
390
*/
#include <iostream>
#include <vector>
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
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}

static int til = 0;
int tilt(Node* node)
{
  // write your code here
   if(node==nullptr) return 0;
 //will return left's sum and change tilt for left side
  int ls= tilt(node->left);
  //will return right's sum and change tilt for right side
   int rs= tilt(node->right);
   
   int ltilt=abs(ls-rs); //local tilt
   til+=ltilt;
   
   int ts=ls+rs+node->data; //total sum
   return ts;
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
  int r = tilt(root);
  cout << til;
}
