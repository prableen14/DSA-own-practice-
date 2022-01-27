/*
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
More formally check if there exists two indices i and j such that :
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 
Example 1:
Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
Example 2:
Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:
Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.

Constraints:
2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3
*/
// Brute Force Two Pointer Soln
// Time O(n.n)
// Space O(1)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int pointer_one = 0; pointer_one < arr.size(); pointer_one++) {
            int n = arr[pointer_one];
            for (int pointer_two = pointer_one + 1; pointer_two < arr.size(); pointer_two++) {
                int m = arr[pointer_two];
                if ( n == (2 * m) || m == (2 * n)) {
                    return true;
                }
            }
        }
        
        return false; 
    }
};
// Binary Search Soln
// Time O(N.logN)
// Space O(1)
class Solution {
public:
  bool binarySearch (vector<int> &arr, int l, int r, int target)
    {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == target)
                return true;
            else if (arr[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
    
    bool checkIfExist(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        for (int pointer_one = 0; pointer_one < arr.size(); pointer_one++) {
            if ((arr[pointer_one] % 2 == 0) && arr[pointer_one] < 0) {
                if (binarySearch(arr, pointer_one + 1, arr.size() - 1, arr[pointer_one] / 2))
                    return true; 
            }
            else {
                if (binarySearch(arr, pointer_one + 1, arr.size() - 1, 2 * arr[pointer_one])==true) //or simply we can write:  if (binarySearch(arr, pointer_one + 1, arr.size() - 1, 2 * arr[pointer_one]))
                    return true;
            }
        }
        return false;
    }
};
