/*
1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. In one move, you are allowed to climb 1, 2 or 3 stairs.
4. You are required to print the number of different paths via which you can climb to the top.
Input Format
A number n
Output Format
A number representing the number of ways to climb the stairs from 0 to top.
Constraints
0 <= n <= 20
Sample Input
4
Sample Output
7
*/
//Using Memoization
#include <iostream>
using namespace std;

int cs(int n, int qb[]){
    // write your code here
if(n==0) return 1;
else if(n<0) return 0;
if(qb[n]>0) return qb[n];
int nm1=cs(n-1,qb);
int nm2=cs(n-2,qb);
int nm3=cs(n-3,qb);
int cp=nm1+nm2+nm3;
qb[n]=cp;
    return cp;

}

int main(){
    int n;
    cin>>n;
    cout<<cs(n,new int[n+1])<<endl;
}
//Using Tabulation (Iteration)
//3 Stages of Tabulation : 1) Storage and Meaning    2)Identify the Direction    3)Travel and Solve
#include <iostream>
using namespace std;

int cs(int n){
    // write your code here
    int dp[n+1];
    dp[0]=1;
for(int i=1;i<=n;i++){
    if(i==1)
    dp[i]=dp[i-1];
    else if(i==2) 
    dp[i]=dp[i-1]+dp[i-2];
    else
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
}
return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}
