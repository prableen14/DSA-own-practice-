/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []

1) Find index and mark its presence.
2) If already marked( which means if its value is -ve) ,that means duplicacy encoutered. Add that duplicate element in the answer.
For Example, an array is [4,3,2,7,8,2,3,1], then when loop starts then 1st element (i.e 4) will go to 4th positiin or 3rd index (nums[i]-1). 
After that, to mark the presence of that index, change the value present at that index to its negative, 
so that when duplicate element is encoutered we can check if that value is negative or positve. if its already negative then that means duplicacy happened. Add that duplicate element in the answer by adding 1 to it.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i])-1;
            int val=nums[index];
            if(val<0){
                res.push_back(index+1);
            }
            else{
                nums[index]= -nums[index];
            }
        }
        return res;
    }
};
