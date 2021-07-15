// 96. Unique Binary Search Trees
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// Example 1:
// Input: n = 3
// Output: 5 (From 1 to 3 there are 5 possible trees)
// Example 2:

//Input: n = 1
// Output: 1

class Solution {
    public int numTrees(int n) {
                int[] table = new int[n+1];
        table[0] = 1;

        for (int t = 1; t <= n; t++) {
            int sum = 0;
            for (int i = 1; i <= t; i++) {
                sum += table[i-1] * table[t-i];
            }
            table[t] = sum;
        }
        return table[n];
    }
}
