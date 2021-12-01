/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are give a number fee, representing the transaction fee for every transaction.
4. You are required to print the maximum profit you can make if you are allowed infinite transactions, but has to pay "fee" for every closed transaction.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
Input Format
A number n
.. n more elements
A number fee
Output Format
A number representing the maximum profit you can make if you are allowed infinite transactions with transaction fee.
Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10
0 <= fee <= 5
Sample Input
12
10
15
17
20
16
18
22
20
22
20
23
25
3
Sample Output
13
*/
#include <iostream>
#include <vector>
using namespace std;

void transactions(vector<int> arr, int fee) {
// write your code here
int obsp=-arr[0]; //old buy state profit (after buying on first date we will comeinto loan of that much amount)
int ossp=0;      //old sell state profit
for(int i=1;i<arr.size();i++){
    int nbsp=0; //new buy state profit
    int nssp=0; //new sell state profit
  
  //changing bought state profit on every day
    if(ossp-arr[i]>obsp) nbsp=ossp-arr[i];
        else nbsp=obsp;
  //changing selling state profit on every day
        if(obsp+arr[i]-fee>ossp) nssp=obsp+arr[i]-fee;
        else nssp=ossp;
        
        obsp=nbsp;
        ossp=nssp;
}
cout<<ossp;
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int fee;
  cin >> fee;

  transactions(arr, fee);

  return 0;
}
