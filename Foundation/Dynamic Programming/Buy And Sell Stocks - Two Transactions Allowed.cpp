/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed two transactions at-most.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
Input Format
A number n
.. n more elements
Output Format
A number representing the maximum profit you can make if you are allowed a single transaction.
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
#include <climits>

using namespace std;


void transactions(vector<int> arr) {
  // write your code here
  int mpst=0; //maximum profit if sold today
  int lsf=arr[0]; //least so far
  int n=arr.size();
  int dpl[n];// maximum profit if sold upto today
  for(int i=0;i<n;i++)
  dpl[i]=0; //instead of doing this, we can make dp as vector instead of array: vector<int> dpl(arr.size(), 0);
  for(int i=1;i<arr.size();i++){
      if(arr[i]<lsf)
          lsf=arr[i];
      mpst=arr[i]-lsf;
      if(mpst>dpl[i-1])
      dpl[i]=mpst;
      else dpl[i]=dpl[i-1];
  }
  int mpbt=0; //max profit if bought today;
  int maxat=arr[n-1]; //max after today
  int dpr[n];
  for(int i=0;i<n;i++)
  dpr[i]=0;
  for(int i=n-2;i>=0;i--){
      if(arr[i]>maxat)
      maxat=arr[i];
      mpbt=maxat-arr[i];
      if(mpbt>dpr[i+1])
      dpr[i]=mpbt;
      else dpr[i]=dpr[i+1];
  }
  int op=0; //overall profit
  for(int i=0;i<n;i++){
      if(dpl[i]+dpr[i]>op)
      op=dpl[i]+dpr[i];
  }
  cout<<op;
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i] ;
  }
  transactions(arr);
  return 0;
}
