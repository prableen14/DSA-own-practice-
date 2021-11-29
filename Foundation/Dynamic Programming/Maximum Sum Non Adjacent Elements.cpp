/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers, representing n elements.
3. You are required to find the maximum sum of a subsequence with no adjacent elements.
Input Format
A number n
n1
n2
.. n number of elements
Output Format
A number representing the maximum sum of a subsequence with no adjacent elements.
Constraints
1 <= n <= 1000
-1000 <= n1, n2, .. n elements <= 1000
Sample Input
6
5
10
10
100
5
6
Sample Output
116
*/
//GREEDY QUESTION
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int inc=arr[0];
    int exc=0;
    for(int i=1;i<n;i++){
        int ninc=exc+arr[i]; //new include
        int nexc=max(inc,exc); //new exclude
        
        inc=ninc;
        exc=nexc;
    }
    cout<<max(inc,exc);
}
