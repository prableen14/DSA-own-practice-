/*
You are given an integer array nums. 
You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/
//TC and SC: O(N), O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n=nums.size();
        int reachable=0;
        for(int i=0;i<n;i++)
        {
            if(reachable<i)
                return false;
            reachable=max(reachable,i+nums[i]);
        }
        return true;
    }
};

//Another Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastGoodIndexPosition=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+nums[i]>=lastGoodIndexPosition)
                lastGoodIndexPosition=i;
        }
        return lastGoodIndexPosition==0;
    }
};

