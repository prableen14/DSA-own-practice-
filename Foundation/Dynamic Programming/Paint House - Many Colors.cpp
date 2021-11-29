/*
1. You are given a number n and a number k separated by a space, representing the number of houses and number of colors.
2. In the next n rows, you are given k space separated numbers representing the cost of painting nth house with one of the k colors.
3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.
Input Format
A number n
n1-0th n1-1st n1-2nd .. n1-kth
n2-0th n2-1st n2-2nd .. n2-kth
.. n number of elements
Output Format
A number representing the minimum cost of painting all houses without painting any consecutive house with same color.
Constraints
1 <= n <= 1000
1 <= k <= 10
0 <= n1-0th, n1-1st, .. <= 1000
Sample Input
4 3
1 5 7
5 8 4
3 2 9
1 2 4
Sample Output
8
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int main()
{
  int n ;
  cin >> n ;
  int k ;
  cin >> k ;
  //write your code from here
  int arr[n][k];
  for(int i=0;i<n;i++){
      for(int j=0;j<k;j++){
          cin>>arr[i][j];
      }
  }
  int dp[n][k];
  for(int j=0;j<k;j++){
      dp[0][j]=arr[0][j];
  }
  int least=INT_MAX;
  int sleast=INT_MAX;
  //finding least and second least (of 1st row)
  for(int j=0;j<k;j++){
      dp[0][j]=arr[0][j]; //first row will be same 
      if(arr[0][j]<=least){
        sleast=least;
        least=arr[0][j];
      }
     else if(arr[0][j]<=sleast){
         sleast=arr[0][j];
     }
  }
  //finding least and second least of rows while parsing through it
  for(int i=1;i<n;i++){
      int nleast=INT_MAX; //new least
      int nsleast=INT_MAX; //new second least
      for(int j=0;j<k;j++){
          if(least==dp[i-1][j])
          dp[i][j]=arr[i][j]+sleast;
          else dp[i][j]=arr[i][j]+least;
          if(dp[i][j]<=nleast){
        nsleast=nleast;
        nleast=dp[i][j];
      }
     else if(dp[i][j]<=nsleast){
         nsleast=dp[i][j];
      }
  }
  least=nleast;
  sleast=nsleast;
}
cout<<least;
}
