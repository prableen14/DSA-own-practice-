/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:
1 <= n <= 45
*/
//Bottom-Up Approach: Tabulation is a bottom-up approach to dynamic programming. 
//You start with the smallest subproblems and iteratively solve larger and larger problems, building up the solution to the main problem.
dp[0]=1 //isko tu bhulegi, that is why im documentiing this, iska reason h ki if you look at your base case of 2 (starting case) toh 2nd stair par pohochne ke 2 ways are there: ek toh 1+1 step lena (which is dp[1] =1 ya fir dp[0]=1 matlab direct 2 steps , toh dp[0] is base case ko start karne ke liye 1 liya gya h
class Solution {
public:
    int climbStairs(int n) {
       int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n]; 
    }
};
