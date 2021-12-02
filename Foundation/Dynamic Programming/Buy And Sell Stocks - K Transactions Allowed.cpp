/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are given a number k, representing the number of transactions allowed.
3. You are required to print the maximum profit you can make if you are allowed k transactions at-most.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
Input Format
A number n
.. n more elements
A number k
Output Format
A number representing the maximum profit you can make if you are allowed a single transaction.
Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10
0 <= k <= n / 2
Sample Input
6
9
6
7
6
3
8
1

Sample Output
5
*/
//This one is not an optimised approach, TC: O(N^3)
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void transactions(vector<int> arr, int k) {
  //write your code here
  int n=arr.size();
   vector<vector<int>> dp(k + 1, vector<int>(n, 0));
  for(int t=1;t<=k;t++){
      for(int d=1;d<arr.size();d++){
          int max=dp[t][d-1];
          
          for(int pd=0;pd<d;pd++){ //previous days
              int ptillm1=dp[t-1][pd]; //profit till t-1 transaction
              int ptth=arr[d]-arr[pd]; //profit of tth transaction
              
              if(ptillm1+ptth>max)
              max=ptillm1+ptth;
          }
          dp[t][d]=max;
      }
  }
  cout<<dp[k][n-1];
}

int main() {

  int n;
  cin >> n;
  vector<int> arr(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int k ;
  cin >> k;

  transactions(arr, k);
  return 0;
}
