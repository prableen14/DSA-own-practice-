/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. You are required to calculate and print true or false, if there is a subset the elements of which add 
     up to "tar" or not.
Input Format
A number n
n1
n2
.. n number of elements
A number tar
Output Format
true or false as required
Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 20
0 <= tar <= 50
Sample Input
5
4
2
7
1
3
10
Sample Output
true
*/
//No. of Subsets: 2^n (Each Element has 2 choices, whether to come or not)
//Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array
#include <iostream>
#include <vector>
using namespace std;

void targetSumSubset(int n, vector<int> arr, int tar) {

// write your code here
bool dp[n+1][tar+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<tar+1;j++){
        if(i==0 && j==0)
        dp[i][j]=true;
        else if(i==0) dp[i][j]=false;
        else if(j==0) dp[i][j]= true;
        else if(dp[i-1][j]==true) dp[i][j]=true;
        else {
            int val=arr[i-1];
            if(j>=val){
                if(dp[i-1][j-val]==true)  dp[i][j]=true;
            }
        }
        
    }
}
 if (dp[n][tar] == 1) {
    cout << "true";
  } else cout << "false";
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int tar;
  cin >> tar;
  targetSumSubset(n, arr, tar);

}
