/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
class Solution {
public:
          vector<vector<int>> res;
    void solve(vector<int> t,vector<int> nums){
        if(nums.size()==0){
            res.push_back(t);
            return;
        }
        vector<int> t1 = t;
        vector<int> t2 = t;
        t2.push_back(nums[0]);
        nums.erase(nums.begin());
        solve(t2,nums);
        solve(t1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        solve(t,nums);
        return res;
    }    
};
