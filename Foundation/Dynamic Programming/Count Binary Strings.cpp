/*
1. You are given a number n.
2. You are required to print the number of binary strings of length n with no consecutive 0's.
Input Format
A number n
Output Format
A number representing the number of binary strings of length n with no consecutive 0's.
Constraints
0 < n <= 45
Sample Input
6
Sample Output
21
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int dp0[n+1];
    int dp1[n+1];
    for(int i=0;i<=n;i++){
        dp0[i]=0;
    }
    for(int i=0;i<=n;i++){
        dp1[i]=0;
    }
    dp0[1]=1;
    dp1[1]=1;
    for(int i=2;i<=n;i++){
        dp1[i]=dp0[i-1]+dp1[i-1];
        dp0[i]=dp1[i-1]; //We cant have consecutive 0s together so thats why this will only have 1s 
    }
    
    cout<<dp1[n]+dp0[n];
}
