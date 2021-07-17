//************************329. Longest Increasing Path in a Matrix
// Given an m x n integers matrix, return the length of the longest increasing path in matrix.
// From each cell, you can either move in four directions: left, right, up, or down.
//You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

// Example 1:
// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Example 2:
// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

// Example 3:
// Input: matrix = [[1]]
// Output: 1
 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1
// USING MEMOIZATION
// Time: O(MN), Space:O(MN)

class Solution {
    int[][] dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    public int longestIncreasingPath(int[][] matrix) {
        if(matrix == null || matrix.length == 0) return 0;
        int m = matrix.length, n = matrix[0].length;
        int[][] mem = new int[m][n];
        int longestPath = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int path = dfs(matrix, m, n, i, j, mem);
                longestPath = Math.max(path, longestPath);
            }
        }
        
        return longestPath;
    }
    
    public int dfs(int[][] matrix, int m, int n, int i, int j, int[][] mem) {
        if(mem[i][j] > 0) return mem[i][j];
        int max = 0;
        for(int[] d : dir) {
            int x = i+d[0], y = j+d[1]; 
            if(x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] > matrix[i][j]) {
                max = Math.max(max, dfs(matrix, m, n, x, y, mem));
            }
        }
        mem[i][j] = max+1;
        return max+1;
    }
}
