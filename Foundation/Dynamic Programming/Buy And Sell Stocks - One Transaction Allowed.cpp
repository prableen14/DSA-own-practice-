/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed a single transaction.
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
17
*/
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

void Transaction(vector<int> arr) {
  //write your code here
  int lsf=INT_MAX; //least so far
  int pist=0;//profit if sold today
  int op=0; //overall profit
  for(int i=0;i<arr.size();i++){
      if(arr[i]<lsf)
      lsf=arr[i];
       pist=arr[i]-lsf;
  if(pist>op) op=pist;
  }
 cout<<op;
}

int  main() {
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  Transaction(arr);
  return 0;
}
