/*
1. You are given a partially written function to solve(Refer question video).
2. Task : Construct Binary Tree from InOrder and LevelOrder Traversal.
3. you will be given two arrays representing a valid InOrder & LevelOrder of a Binary Tree. Program is required to create a unique Binary Tree.
Input Format
Input is managed for you.
Output Format
Output is managed for you.

Constraints
0 <= Number of Nodes <= 10^9
-10^9 <= value of Node data <= 10^9
Valid InOrder and LevelOrder traversals.
Sample Input
9
2 7 15 12 6 9 5 11 4
12 7 5 6 11 2 15 4 9
Sample Output
7 -> 12 <- 5
2 -> 7 <- 15
. -> 2 <- .
. -> 15 <- .
6 -> 5 <- 11
. -> 6 <- 9
. -> 9 <- .
. -> 11 <- 4
. -> 4 <- .
*/
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};
TreeNode *construct(int inorder[],int levelorder[],int isi,int iei,int n)
{
    if(isi>iei) return NULL;
   int idx=isi;
    while(levelorder[0]!=inorder[idx]) idx++;
    TreeNode* node= new TreeNode(levelorder[0]);
     // Insert all left nodes in hash table
	unordered_set<int> s;
	for (int i=isi;i<idx;i++)
		s.insert(inorder[i]);
		// Separate level order traversals
	// of left and right subtrees.
	int lLevel[s.size()]; // Left
	int rLevel[iei-idx]; // Right
	int li = 0, ri = 0;
	for (int i=1;i<n;i++) {
		if (s.find(levelorder[i]) != s.end())
		lLevel[li++] = levelorder[i];
        else
            rLevel[ri++] = levelorder[i];       
		}	

	// Recursively build left and right
	// subtrees and return root.
	node->left = construct(inorder, lLevel,
				isi, idx-1,idx-isi);
	node->right = construct(inorder, rLevel,
				idx+1, iei,iei-idx);
	return node;
}
TreeNode *buildTree(int inorder[],int levelorder[],int n)
{
return construct(inorder,levelorder,0,n-1,n);
}


// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    int in[n];
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
int level[n];
    for (int i = 0; i < n; i++)
    {
        cin >> level[i];
    }
    TreeNode *root = buildTree(in, level,n);
    display(root);
}

int main()
{
    solve();
    return 0;
}
