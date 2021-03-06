/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         sort(begin(nums), end(nums));      
        int i = 0;
        while(i<nums.size()-1) {
            if(nums[i] == nums[i+1]) return true;        
            i++;
        }        
        return false;
    }
};

//Another Approach
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
		
        for(size_t i = 0; i < nums.size(); i++)
            if(!hashset.insert(nums[i]).second) /* if it's a duplicate */
                return true;
				
        return false; /* if there are no duplicates */
    }
};
