/* Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1*/

//All Solutions explained for interview (Inefficient to Efficient)

class Solution {
public:
    
    // Brute Force Method
    // Time Complexity O(n^2) 
    // Space Complexity O(1)
    // run loop for each element counting the number of times it occurs in the array
    // if the count is more than majority then return that element
    // Verdict Time Limit Exceeded
    int solveBrute(vector<int>&nums){
        int majority = nums.size()/2;
        for(int i=0;i<nums.size();i++){
            int targetElement = nums[i];
            int count = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j] == targetElement){
                    count++;
                }
            }
            if(count > majority)
                return targetElement;
        }
        return -1; // the majority element does not exist
    }
    
    //Sorting
    // Time Complexity O(nlogn) 
    // Space Complexity O(1)
    // Sort the array now the middle element will always be the majority element
    // this happens because the majority elements covers more than half the array 
    // and it will always be the case that it will cross the middle point
    // Verdict Accepted 
    int solveSort(vector<int>&nums){
        sort(nums.begin(), nums.end());
        return nums[(nums.size()-1)/2];
    }
    
    
    
    //Frequency Table
    // Maintain a hash table with frequency of each element if the count of an element 
    // breaches the majority mark then declare it as winner.
    // Time complexity O(n)
    // Space complexity O(n)
    // Verdict Accepted
    int solveFreq(vector<int>&nums){
        unordered_map<int,int>ump;
        int majority = nums.size()/2;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++; // add the element to frequency table
            if(ump[nums[i]]>majority)
                return nums[i];
        }
        return -1; // could not find majority element;
    }
    
    // Boyer Moore Majority Voting Algorithm
    // Time Complexity O(n)
    // Space Complexity O(1)
    // This algorithm works on the fact that the number of elements that are there apart from 
    // majority element will always have the frequency less than n/2. We will start 
    // with initial count as 1 and the majority element as first element now if we encounter the 
    // same element we increment the counter otherwise we decrement it. If after decrementing the 
    // count becomes zero. We reinitialize the majority element as next element and count as 1.
    // We can easily prove that we will always end up with majority element. For example take 
    // the minimum majority case this means majority is floor(n/2)+1 now remaining elements are 
    // less than half the elements since the majority element will always contain 1 element more 
    // than any other element even in the worst case this will always emerge as winner.
    // Verdict Accepted
    
    int solveVoting(vector<int>&nums){
        int majority;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                majority = nums[i];
                count = 1;
                continue;
            }
            if(nums[i] == majority){
                count++;
            }
            else{
                count--;
            }
        }
        return majority;
    }
    
    
    int majorityElement(vector<int>& nums) {
        return solveFreq(nums);
    }
};
