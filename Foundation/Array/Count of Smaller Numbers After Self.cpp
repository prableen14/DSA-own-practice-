
/**
 * @brief 
 * Return how much numbers is smaller in the elements right direction.
 * 
 * @aglo1 Bruce force
 *  For each i, find smaller elements
 *  Time O(N^2)
 *  Space O(1)
 * 
 * @algo2 Merge sort
 *  During the merge function, in the merge function, when we rearrange the orders of the two array.
 *  We can count that how many right array element have been move to left.
 *  
 *  [Key] using index to represent the numbers, since we have to add the ans to original idx.
 *  [Key] How to count the smaller values? 
 *        - When we are filling a value X from the left array to the new merge array, 
 *          get the numbers in the new merge array array which originally is the left arr. 
 *          (Which means the numbers of smaller value in the right of X)
 *  Time O(NlogN)
 *  Space O(N)
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
