// 96. Unique Binary Search Trees
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// Example 1:
// Input: n = 3
// Output: 5 (From 1 to 3 there are 5 possible trees)
// Example 2:

//Input: n = 1
// Output: 1

class Solution {
public:

int numTrees(int n, vector<int> &memo) {
	// base case
	if (n <= 1) return 1;
	// if subProblem is not solved
	if (not memo[n])
		// recursion
		for (int i = 1; i <= n; i++)
			memo[n] += numTrees(i - 1, memo) * numTrees(n - i, memo);
	// return solved subProblem
	return memo[n];
}

// main
int numTrees(int n) {
	// init memo
	vector<int> memo(20);
	return numTrees(n, memo); 
    }
};
