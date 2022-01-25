/*
Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:
Input: arr = [2,1]
Output: false

Example 2:
Input: arr = [3,5,5]
Output: false

Example 3:
Input: arr = [0,3,2,1]
Output: true
 
Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int l = 0;
        int r = arr.size() - 1;
        
        // 1st we will check the strictly incresing part. We check the current pointer value has to be smaller then the next pointer value
        // to handle index out of bound error. we will go till arr.length - 1, not arr.length
        while(l + 1 < arr.size() - 1 && arr[l] < arr[l + 1]) l++;
        
        // Now we will check the strictly decreasing part. We check the current pointer value has to be smaller then the previous pointer value
        while(r - 1 > 0 && arr[r] < arr[r - 1]) r--;
        return l == r; //If left and right meets on same index value then we return true, because it's a stricly increasing and decreasing mountain.
    }
};
