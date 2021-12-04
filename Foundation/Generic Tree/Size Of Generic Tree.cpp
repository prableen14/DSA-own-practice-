/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of size function. The function is expected to count the number of nodes in the tree and return it.
3. Input and Output is managed for you.
Input Format
Input is managed for you
Output Format
Output is managed for you
Constraints
None
Sample Input
12
10 20 -1 30 50 -1 60 -1 -1 40 -1 -1
Sample Output
6
*/

#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  vector<Node*>children;
};

Node* newNode(int key) {
  Node* temp = new Node;
  temp->data = key;
  return temp;

}

Node* construct(int arr[], int n ) {
  Node* root = NULL;
  stack<Node*>st;
  for (int i = 0; i < n; i++) {
    if (arr[i] == -1) {
      st.pop();
    } else {
      Node* t = newNode(arr[i]);
      if (st.size() > 0) {
        st.top()->children.push_back(t);
      } else {
        root = t;
      }
      st.push(t);
    }
  }
  return root;
}
void display(Node* node)
{
  string str = to_string(node->data) + "-> ";
  for (Node* child : node->children)
  {
    str += to_string(child->data) + ", ";
  }
  str = str + ".";
  cout << str << endl;
  for (Node* child : node->children)
  {
    display(child);
  }
}

int size(Node* node) {
  if (node == NULL) {
    return 0;
  }
  int s = 0;
  for (Node* child : node->children) {
    s += size(child);
  }
  s += 1;
  return s;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Node* root = construct(arr, n);
  int sz = size(root);
  cout << sz << endl;
  //display(root);
}
