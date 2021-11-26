/*
1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. You are given n numbers, where ith element's value represents - till how far from the step you 
     could jump to in a single move.  
     You can of course jump fewer number of steps in the move.
4. You are required to print the number of different paths via which you can climb to the top.
Input Format
A number n
.. n more elements
Output Format
A number representing the number of ways to climb the stairs from 0 to top.
Sample Input
10
3
3
0
2
1
2
4
2
0
0
Sample Output
5
*/
#include <iostream>
using namespace std;

int cs(int arr[], int n){
    int dp[n + 1];
    for(int i = 0 ; i <= n; i++){
        dp[i] = 0;
    }
    dp[n] = 1;

    for(int i = n - 1; i >= 0; i--){
        for(int jumps = 1; jumps <= arr[i]; jumps++){
            if(i + jumps <= n){
                dp[i] += dp[i + jumps];
            }
        }
    }
    return dp[0];

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}
