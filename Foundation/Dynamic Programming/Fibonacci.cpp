/*
1. You are given a number n.
2. You are required to print the nth element of fibonnaci sequence.

Note -> Notice precisely how we have defined the fibonnaci sequence
0th element -> 0
1st element -> 1
2nd element -> 1
3rd element -> 2
4th element -> 3
5th element -> 5
6th element -> 8
Input Format
A number n
Output Format
A number representing the nth element of fibonnaci sequence
Constraints
0 <= n <= 45
Sample Input
10
Sample Output
55
*/
#include <iostream>
using namespace std;

int fibMemoized(int n, int qb[]){  //qb=question bank
    // write your code here
if(n==0 || n==1) return n;
if(qb[n]!=0) return qb[n];
int fibn1=fibMemoized(n-1,qb);
int fibn2=fibMemoized(n-2,qb);
int  fibn= fibn1+fibn2;
qb[n]=fibn;
    return fibn;
}

int main(){
    int n;
    cin>>n;
    int fibn=fibMemoized(n, new int[n+1]);
    cout<<fibn<<endl;
    return 0;
}
