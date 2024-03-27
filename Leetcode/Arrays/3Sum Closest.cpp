/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 
Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/
//O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      //  nums = [4, -1, 2, 1, -5, 2, -3, 4], target = 3
        sort(nums.begin(),nums.end()); //[-5, -3, -1, 1, 2, 2, 4, 4]
        int closestSum= nums[0]+nums[1]+nums[2]; // -5-3-1= -9 
  
        for (int i=0;i<=nums.size()-3;i++){
          
            int left=i+1; //at 1st index initially
            int right= nums.size()-1; //at 7th index initially
              while (left < right) {
           int currentSum=nums[i]+nums[left]+nums[right]; //-5-3+4=-4
           int currentClosestValue=abs(target-currentSum);
            if(currentClosestValue<abs(target-closestSum))     // 3-(-4)=7 <12
             closestSum=currentSum;   //closestSum=-4
              
            if(currentSum<target)
                left++;
        else right--;
    }}
    return closestSum;}
};
