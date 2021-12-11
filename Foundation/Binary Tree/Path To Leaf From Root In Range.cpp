/*
1. You are given a partially written BinaryTree class.
2. You are given a value lo and a value hi
3. You are required to complete the body of pathToLeafFromRoot function. The function is expected to print all paths from root to leaves which have sum of nodes in range from lo to hi (both inclusive). The elements in path should be separated by spaces. Each path should be in a separate line.
4. Input is managed for you.
Input Format
Input is managed for you
Output Format
The elements in path should be separated by spaces. Each path should be in a separate line.
Constraints
None
Sample Input
23
50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
150
250
Sample Output
50 25 37 40
50 75 62 60
50 75 87
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
  Node(int data)
  {
    this->data = data;
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

void pathToLeafFromRoot(Node* node, string path, int sum, int lo, int hi) {
  // write your code here
  if(node==nullptr) return;
  if(node->left==nullptr && node->right==nullptr){
  sum+=node->data; //last node data is added
  if(sum>=lo && sum<=hi)
  cout<<path+to_string(node->data)<<endl;
  }
  pathToLeafFromRoot(node->left,path+to_string(node->data)+" ",sum+node->data,lo,hi);
  pathToLeafFromRoot(node->right,path+to_string(node->data)+" ",sum+node->data,lo,hi);
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
  int lo;
  cin >> lo;
  int hi;
  cin >> hi;
  Node* root = constructTree(arr);
  pathToLeafFromRoot(root, "", 0, lo, hi);
  return 0;
}
