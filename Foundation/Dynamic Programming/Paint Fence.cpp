/*
1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two consecutive  fences have same colors.
Input Format
A number n
A number k
Output Format
A number representing the number of ways in which the fences could be painted so that not more than two fences have same colors.
Constraints
1 <= n <= 10
1 <= k <= 10
Sample Input
8
3
Sample Output
3672
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n ;
  cin >> n ;
  int k ;
  cin >> k ;
  long same=k*1;
  long different=k*(k-1);
  long total=same+different;
for(int house=3;house<=n;house++){
    same=different*1;
    different=total*(k-1);
    total=same+different;
}
 cout<<total;
}
