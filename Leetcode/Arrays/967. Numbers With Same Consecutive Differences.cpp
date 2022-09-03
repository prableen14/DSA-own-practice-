/*
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.
Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.
You may return the answer in any order.

Example 1:
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Example 2:
Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

Constraints:

2 <= n <= 9
0 <= k <= 9
*/
class Solution {
public:
vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> res;
    for (auto num = 1; num <= 9;num++) 
        dfs(num, N - 1, K, res);
    return res;
}
void dfs(int num, int n, int K, vector<int> &res) {
  if (n == 0) 
      res.push_back(num);
  else {
      int dig = num % 10;
      if (dig + K <= 9)
          dfs(num * 10 + dig + K, n - 1, K, res);
      if (K != 0 && dig >= K)
          dfs(num * 10 + dig - K, n - 1, K, res);
    }
}
};
