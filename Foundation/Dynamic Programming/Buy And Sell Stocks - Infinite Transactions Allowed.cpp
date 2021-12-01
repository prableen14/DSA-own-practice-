/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed infinite transactions.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy)
Input Format
A number n
.. n more elements
Output Format
A number representing the maximum profit you can make if you are allowed infinite transactions.
Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10
Sample Input
9
11
6
7
19
4
1
6
18
4
Sample Output
30
*/
#include <iostream>
#include <vector>
using namespace std;

void transactions(vector<int> arr) {

// write your code here
int bd=0; //buying date
int sd=0; //selling date
int profit=0;
for(int i=1;i<arr.size();i++){
    if(arr[i]>=arr[i-1]){ //whenever there is a upstock increase selling date
        sd++;
    }
    else{
        profit+=arr[sd]-arr[bd]; 
        sd=bd=i;
    }
}
profit+=arr[sd]-arr[bd]; //for last one
cout<<profit;
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  transactions(arr);
  return 0;
}
