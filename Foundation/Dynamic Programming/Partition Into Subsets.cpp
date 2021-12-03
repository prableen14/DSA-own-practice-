/*
1. You are given a number n, representing the number of elements.
2. You are given a number k, representing the number of subsets.
3. You are required to print the number of ways in which these elements can be partitioned in k non-empty subsets.
E.g.
For n = 4 and k = 3 total ways is 6
12-3-4
1-23-4
13-2-4
14-2-3
1-24-3
1-2-34
Input Format
A number n
A number k
Output Format
A number representing the number of ways in which these elements can be partitioned in k non-empty subsets.
Constraints
0 <= n <= 20
0 <= k <= n
Sample Input
4
3
Sample Output
6
*/
#include <iostream>
#include <vector>

using namespace std ;

int main() {
  int n ;
  cin >> n ;
  int k ;
  cin >> k ;

  if (n == 0 || k == 0 || n < k) {
    cout << 0 ;
  }

  vector<vector<long>>  dp(k + 1, vector<long>(n + 1, 0));
  for (int i = 1; i <= k; i++) { //teamsize or number of subsets
    for (int j = 1; j <= n; j++) { //no of people
      if (i == 1 || j == 1 || i == j) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j - 1] + i * dp[i][j - 1];
      }
    }
  }

  cout << dp[k][n] ;
}
