/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

Example 1:
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

Constraints:
1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107
*/
/*
Key | value
 3  |   1
 1  |   2
 4  |   1
 5  |   1
Now, there are 2 cases :-

If k > 0, then in this case we just need to check wether the counter part exists or not. So, if we are iterating 'x + k' in our map, then we can increment our count
If k == 0, then we just need to check if x is more then 1 or not [x > 1] in our map.

But another thing we need to note that here as we iterate from the array after doing counting. Then we will get "1" two times. 
So, to avoid this instead of iterating over the array, we will iterate over the keyset of this map, which will give us the unique no. i.e. (3,1,4,5).

ANALYSIS :-
Time Complexity :- BigO(N)
Space Complexity :- BigO(N)
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
  unordered_map<int, int> m;
    for (int n : nums) m[n]++;
    int cnt = 0;
    for (auto p : m) {
      if ((k==0 && p.second > 1)
        || (k && m.count(p.first + k))) cnt++;
    }
    return cnt;
    }
};

//Java solution
class Solution {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int num : nums){
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int count = 0;
        for(int x : map.keySet()){
            if(k > 0 && map.containsKey(x + k) || k == 0 && map.get(x) > 1) count++;
        }
        return count;
    }
}
