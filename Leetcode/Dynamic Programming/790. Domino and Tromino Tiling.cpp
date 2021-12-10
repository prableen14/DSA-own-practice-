/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
In a tiling, every square must be covered by a tile. 
Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

Example 1:
Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 1000
*/
class Solution {
public:
    int numTilings(int n) {
        if(n <= 2)
            return n;
        
        int mod = 1000000007;
        long fullTiling[n+1];
        long partTiling[n+1];
        
        // One tile vertical can fill a pair of cells (or 1 column)
        fullTiling[1] = 1;
        // 2 vertical and 2 horizontals can fill up 2 pair of cells (or 2 columns)
        fullTiling[2] = 2; 
        
        // Cannot fill one cell (in a column) with either domino or tromino
        partTiling[1] = 0; 
        // If 1 cell out of 4 (2 pair of cells) is already filled then a tromino can fill the remaining 3 cells
        partTiling[2] = 1; 
        
        for(int i=3; i <= n; i++){
            fullTiling[i] = (fullTiling[i-1] + fullTiling[i-2] + 2 * partTiling[i-1]) % mod;
            partTiling[i] = (partTiling[i-1] + fullTiling[i-2]) % mod;
        }        
        return (int)(fullTiling[n]); 
    }
};
