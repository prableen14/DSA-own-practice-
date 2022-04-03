/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
then the next permutation of that array is the permutation that follows it in the sorted container. 
If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/
//BRUTE FORCE SOLUTION
class Solution {
	    // Brute Force Solution Time O(N!*N) & Auxiliary Space O(N^2)
		// Recursion & Backtracking
	    // TLE 64/265 test cases passed
public:
    void permute(int p,vector<int>& arr, vector<vector<int>>& res) {
        int n=arr.size();
        if(p==n) res.push_back(arr);
        for(int i=p;i<n;i++) {
            swap(arr[i],arr[p]);
            permute(p+1,arr,res);
            swap(arr[i],arr[p]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> arr=nums; 
        permute(0,arr,res); 
        set<vector<int>> s;
        for(int i=0;i<res.size();i++){
            s.insert(res[i]);
        }
        auto it=s.find(nums);
        if(it==(--s.end())){
            it=s.begin();
            nums=*it;
        }
        else{
            it++;
            nums=*it;
        }
    }
};
//Optimal Solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	    // Optimal Solution Time O(N) & Auxiliary Space O(1)
	    // Narayana Panditha's Algorithm
        int len=nums.size(), k=0, l=0;
        for(k=len-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(l=len-1;l>k;l--){
                if(nums[l]>nums[k])
                    break;
        }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};

//Optimal Solution(Inbuilt Function)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	    // Optimal Solution Time O(N) & Auxiliary Space O(1)
	    // Inbuilt Function
        next_permutation(nums.begin(),nums.end());
    }
};
