/*
1. You are given a number x.
2. You are given another number n.
3. You are required to calculate x raised to the power n. Don't change the signature of power function.

Note1 -> This version expects the call stack to be of n height.

Note2 -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Input Format
A number x
A number n
Output Format
x raised to the power n

Constraints
1 <= x <= 10
0 <= n <= 9
Sample Input
2
5
Sample Output
32
*/

#include<iostream>
using namespace std;

int powerLinear(int x,int n){
    // write your code here
    if(n==0) return 1;
    
    int xnm1= powerLinear(x,n-1);
    int xn= x*xnm1;
    return xn;
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLinear(x,n);
}
