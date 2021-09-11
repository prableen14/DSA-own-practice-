/* You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:

Input: nums = [-1]
Output: [0]

Example 3:

Input: nums = [-1,-1]
Output: [0,0]

*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
                int n = nums.size();
        vector<int> ans(n);

        /**
         * Just need to record the index only, to represent the numbers[i] 
         * Because we can use
         */
        vector<int> idxArr; 
        for(int i=0; i < n; i++) {
            // store the original idx to represent the 
            idxArr.push_back(i);
        }

        mergeSort(idxArr, 0, n-1, nums, ans);
        return ans;
    }
    void mergeSort(vector<int>& idxArr, int left, int right, vector<int>& nums, vector<int>& ans) {
        if(left >= right) {
            return;
        }
        int mid = (left + right)/2;
        mergeSort(idxArr, left, mid, nums, ans);
        mergeSort(idxArr, mid+1, right, nums, ans);
        merge(idxArr, left, mid, right, nums, ans);
    }

    void merge(vector<int>& idxArr, int left, int mid, int right, vector<int>& nums, vector<int>& ans) {
        vector<int> sortTemp(right-left+1);
        int i = left;
        int j = mid+1;
        int currIdx = 0;
        
        // start merge two array by two ptr method
        while(i <= mid && j <= right) {
            if(nums[idxArr[i]] <= nums[idxArr[j]]) {
                // Target the number that will move to right direction
                // [Key] Get the numbers in the new merge array array which originally is the left arr. 
                ans[idxArr[i]] += j - (mid+1);
                sortTemp[currIdx] = idxArr[i];
                i++;
            }
            else {
                sortTemp[currIdx] = idxArr[j];
                j++;
            }
            currIdx++;
        }
        
        // unfinished merging l1 or l2
        while(i <= mid) {
            ans[idxArr[i]] += j - (mid+1);
            sortTemp[currIdx] = idxArr[i];
            i++;
            currIdx++;
        }
        while(j <= right) {
            sortTemp[currIdx] = idxArr[j];
            j++;
            currIdx++;
        }

        // copy sorted temp arr back to arr
        for(int i=left; i<=right; i++) {
            idxArr[i] = sortTemp[i-left];
        }
    }
};
