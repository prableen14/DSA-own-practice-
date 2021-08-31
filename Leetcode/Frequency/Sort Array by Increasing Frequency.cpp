/*Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

Example 1:
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

*/

 

class Solution {
public:
    static  bool comp(vector<int> a,vector<int> b)
    {
        if(a[0] < b[0]) return true;
        if(a[0] == b[0])
        {
            return a[1]>b[1];
        }
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
       unordered_map<int,int>m;
        for(auto n:nums)
        {
            m[n]++;
        }
        vector<vector<int>> v;
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(auto a:v)
        {
            int x = a[0];
            while(x--)
            {
                ans.push_back(a[1]);
            }
        }
        return ans;
        }
};
