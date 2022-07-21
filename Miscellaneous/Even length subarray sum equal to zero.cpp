/*
Given an array A[] of size N. Check whether the length of every even length subarray is 0 or not. Return "YES" or "NO" accordingly.
Example 1:
Input:
N = 4
A[] = {8, -8, 7, 9}
Output: 
NO
Explanation: 
sum of subarray {7, 9} is not 0.

Example 2:
Input:
N = 2
A[] = {0, 0}
Output: 
YES
Explanation: 
The only possible even length
subarray is {0, 0} and its sum
is 0.
*/
class Solution {
    public:
    string solve(int N, vector<int> &A){
        // code here
        for(int i=0;i<N-1;i++){
           if(A[i]+A[i+1]!=0) return "NO";
        }
        return "YES";
    }
};
