/*
You are given an array A of N integer . Find the Kth MEX of A.
The Kth MEX of an array is equal to the Kth smallest non-negative integer that is not present in the array. 

Input:
N = 4, K = 3,
A = { 7, 5, 7, 1 }
Output: 3
Explanation: The values which are not present in 
A are: 0, 2, 3, 4, 5..., out of which the 3rd 
samllest value is 3.

Input:
N = 1, K = 1,
A = { 2 }
Output: 0
Explanation: The values which are not present in 
A are: 0, 1, 3, 4, 5..., out of which 0 is the 
samllest value.

Your task:
You don't need to read input or print anything. Your task is to complete the function KthMEX(), which takes 2 integers K and N and array A as input parameters and return Kth MEX of A.
*/
int kthMex(int N, int K, int A[]) {
    // code here
    unordered_map<int,int> mp;
    for(int i=0;i<N;i++){
        mp[A[i]]++;
    }
    for(int i=0;;i++){
        if(!mp[i]) K--;
        
        if(K==0) return i;
    }
     return -1;
}

