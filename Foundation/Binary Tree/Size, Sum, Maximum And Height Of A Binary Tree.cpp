/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of size, sum, max and height function. The functions are expected to
    2.1. size - return the number of nodes in BinaryTree
    2.2. sum - return the sum of nodes in BinaryTree
    2.3. max - return the highest node in BinaryTree
    2.4. height - return the height of tree in terms of edges
3. Input and Output is managed for you.
Input Format
Input is managed for you
Output Format
Output is managed for you
Constraints
None
Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
Sample Output
9
448
87
3
*/

#include<iostream>
#include<climits>
#include<string.h>
#include<vector>

using namespace std;

// structure of node
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


int size(Node* node)
{
  //write your code here
  if(node==NULL)
return 0;
int ls=size(node->left);
int rs=size(node->right);
int ts=ls+rs+1;
return ts;
}
//height- depth of the deepest node
int height(Node* node)
{
  //write your code here
    if(node==NULL)
return -1; //-1 for edges, 0 for nodes
int lh=height(node->left);
int rh=height(node->right);
int th=max(lh,rh)+1;
return th;
}

int maximum(Node* node)
{
  //write your code here
   if(node==NULL)
return INT_MIN;
int lm=maximum(node->left);
int rm=maximum(node->right);
int tm=max(node->data,max(lm,rm));
return tm;
}

int sum(Node* root)
{
if(root==NULL)
return 0;
int lsum=sum(root->left);
int rsum=sum(root->right);
int tsum=lsum+rsum+root->data;
return tsum;
  //write your code here
}

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    if (temp == "n")
    {
      arr[i] = -1;
    }
    else
    {
      arr[i] = stoi(temp); // the stoi() function converts a string to an integer value
    }
  }

  Node* root = constructTree(arr);

  int sz = size(root);
  int sm = sum(root);
  int max = maximum(root);
  int ht = height(root);
  cout << sz << endl;
  cout << sm << endl;
  cout << max << endl;
  cout << ht << endl;
}
