/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of permutations of the n coins using which the 
     amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
                  used for many installments in payment of "amt"
Note2 -> You are required to find the count of permutations and not combinations i.e.
                  2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
                  combination. You should treat them as 3 and not 1.
Input Format
A number n
n1
n2
.. n number of elements
A number amt
Output Format
A number representing the count of combinations of coins which can be used to pay the amount "amt"
Constraints
1 <= n <= 20
0 <= n1, n2, .. n elements <= 20
0 <= amt <= 30
Sample Input
4
2
3
5
6
7
Sample Output
5
*/
#include <iostream>
using namespace std;
int main(){
     int n,tar;
    cin>>n;
    int coins[n];
    for(int i = 0 ; i < n ;i++){
        cin>>coins[i];
    }
    cin>>tar;
       int dp[tar + 1];
       dp[0] = 1;
         for(int i = 1 ; i <=tar; i++){
        dp[i] = 0;
    }
       for(int amt=1;amt<=tar;amt++){
           for(int coin: coins){
               if(coin<=amt){
                   int ramt=amt-coin;
                   dp[amt]+=dp[ramt];
               }
           }
       }
       cout<<dp[tar];
}
