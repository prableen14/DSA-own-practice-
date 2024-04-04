/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 109
*/
//first we are converting all elements of array to string
//then we will use the logic of comparison and sort them based on that
//for instance,if a+b> b+a that means we are comparing 102> 210 , it will return false
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> con;
        for(auto num:nums){
            con.push_back(to_string(num));
        }
         sort(con.begin(), con.end(), compareNums);
        if (!con.empty() && con[0] == "0") {
    return "0";
}
          // Concatenate all strings
    string result;
    for (const string numStr : con) {
        result += numStr;
    }
        return result;
    }
     static bool compareNums(string a, string b ){
        return a+b>b+a;
    }
};
