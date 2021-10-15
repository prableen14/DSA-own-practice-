/*
1191. K-Concatenation Maximum Sum

Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0
 

Constraints:

1 <= arr.length <= 105
1 <= k <= 105
-104 <= arr[i] <= 104
*/

class Solution {
public:
        int kadanes(vector<int> &arr){
        int max_sum = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            
            max_sum = max(sum, max_sum);
            
            if(sum < 0) sum = 0;
        }
        return max_sum;
    }
    
    int kadaneForTwo(vector<int> nums){
        int arr[nums.size()*2];
        
        for(int i = 0; i < nums.size(); i++){
            arr[i] = nums[i];
        }
        
        for(int i = 0; i < nums.size(); i++){
            arr[i+ nums.size()] = nums[i];
        }
        
        int max_sum = INT_MIN, sum = 0;
        
        for(int i = 0; i < nums.size()*2; i++){
            sum += arr[i];
            max_sum = max(max_sum, sum);
            
            if(sum < 0) sum = 0;
        }
        
        return max_sum;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
        }
        
        if(k == 1){
            ans =  kadanes(arr) % 1000000007;
        } else if(sum < 0){
            ans = kadaneForTwo(arr) % 1000000007;
        } else {
            ans = (kadaneForTwo(arr) + (k-2)*sum) % 1000000007;
        }
        if(ans < 0){
            return 0;
        }
        return ans;
    }
};
