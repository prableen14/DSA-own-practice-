/*
1. You are given a positive number n
2. You need return all different combinations of its factors
3. Input and output is handled for you
4. It is a functional problem ,please do not modify main()
 
NOTE: Factors must be greater than 1 and less than n
For exapmple:
Number: 8
Factor combinations: 
2,2,4
4 2
Input Format
Input is handled for you
Output Format
Output is handled for you
Sample Input                                        
12                                   
Sample Output                                       
[2, 2, 3]
[2, 6]
[3, 4]
*/

//Hint: DFS/RECURSION/BACKTRACKING
class Solution {
 public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;
    vector<int> path;

    dfs(n, 2, path, ans);  // the smallest factor is 2

    return ans;
  }

 private:
  void dfs(int n, int index, vector<int>& path, vector<vector<int>>& ans) {
    if (n <= 1) {
      if (path.size() > 1)
        ans.push_back(path);
      return;
    }

    for (int i = index; i <= n; ++i)
      if (n % i == 0) {
        path.push_back(i);
        dfs(n / i, i, path, ans);
        path.pop_back();
      }
  }
};
