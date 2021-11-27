/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without 
     overflowing it's capacity.

Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item 
               again and again.
Input Format
A number n
v1 v2 .. n number of elements
w1 w2 .. n number of elements
A number cap
Output Format
A number representing the maximum value that can be created in the bag without overflowing it's capacity
Constraints
1 <= n <= 20
0 <= v1, v2, .. n elements <= 50
0 < w1, w2, .. n elements <= 10
0 < cap <= 10
Sample Input
5
15 14 10 45 30
2 5 1 3 4
7
Sample Output
75
*/
#include <iostream>
#include <vector>

using namespace std;

void zeroOneKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

  vector<vector<int>> dp(n + 1, vector<int>(cap + 1));
for(int i=1;i<n+1;i++){
    for(int j=1;j<=cap;j++){
        if(j>=weight[i-1])
        { int rCap=j-weight[i-1];
           if (dp[i-1][rCap]+val[i-1]>dp[i-1][j])
           dp[i][j]=dp[i-1][rCap]+val[i-1];
           else dp[i][j]=dp[i-1][j];
        }
       else dp[i][j]=dp[i-1][j];
    }
}
cout<<dp[n][cap];
}

int main() {

  int n;
  cin >> n;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int cap;
  cin >> cap;

  zeroOneKnapsack(n, val, weight, cap);

}
