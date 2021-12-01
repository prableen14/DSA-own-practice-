/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed infinite transactions, but have to cooldown for 1 day after 1 transaction
i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
Input Format
A number n
.. n more elements
Output Format
A number representing the maximum profit you can make if you are allowed infinite transactions with cooldown of 1 day.
Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10
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
Sample Output
19
*/
#include <iostream>
#include <vector>

using namespace std;

void transaction(vector<int> arr) {
  // write your code here
  int obsp=-arr[0]; //old bought state profit
  int ossp=0;      //old sell state profit
  int ocsp=0;     //old cooldown state profit
  
  for(int i=1;i<arr.size();i++){
      int nbsp=0;  //new bought state profit
      int nssp=0;  //new sell state profit
      int ncsp=0;  //new cooldown state profit
      
      if(ocsp-arr[i]>obsp) 
      nbsp=ocsp-arr[i];
      else nbsp=obsp;
      
      if(obsp+arr[i]>ossp)
      nssp=obsp+arr[i];
      else nssp=ossp;
      
      if(ossp>ocsp) 
      ncsp=ossp;
      else ncsp=ocsp;
     
     obsp=nbsp;
     ossp=nssp;
     ocsp=ncsp;
  }
  cout<<ossp;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i] ;
  }

  transaction(arr);
  return 0;
}
