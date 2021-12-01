/*
1. You are given an array(arr) of integers.
2. You have to find maximum subarray sum in the given array.
3. The subarray must have at least one element.
Input Format
A number N
a1
a2.. N integers
Output Format
A number representing maximum subarray sum in the given array.
Constraints
1 <= N <= 10000
-2^31 <= arr[i] <= 2^31 - 1 
Sample Input
3
1
2
3
Sample Output
6
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) 
    cin>>arr[i];
    
    int csum=arr[0]; //current sum
    int osum=arr[0]; //overall sum
    
    for(int i=1;i<n;i++){
        if(csum>=0)  //if current sum is not negative then add the current element to the same train
            csum+=arr[i];
        else  //else train is starting from the current element( I am an independent man)
        csum=arr[i];
        
        if(csum>osum) osum=csum;
    } 
    cout<<osum;
}
