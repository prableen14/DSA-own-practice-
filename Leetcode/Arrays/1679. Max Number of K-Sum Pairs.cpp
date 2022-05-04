/*
You are given an integer array nums and an integer k.
In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
Return the maximum number of operations you can perform on the array.

Example 1:
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.

Example 2:
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/
The brute force way to solve this problem is very easy, have 2 pointers one start from very begining & another start just after the second pointer. Means the 2nd pointer is depends on 1st pointer. And now you say if that's the case it wont gonna visit the same element over & over again.?

And my answer is Yes it'll, but we;ll gonna play mind games. So, the element which i & j pointer has already visited flag them as visited with any value, let's say i'll gonna mark them with -1. So, by that we can handle this case easily. Now Happy :)

class Solution {
    public int maxOperations(int[] nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == -1) continue;
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] == -1) continue;
                if(nums[i] + nums[j] == k){
                    count++;
                    nums[i] = -1;
                    nums[j] = -1;
                    break;
                }
            }
        }
        return count;
    }
}
ANALYSIS :-

Time Complexity :- BigO(N^2)

Space Complexity :- BigO(1)

BETTER

Now, Interviewer won't be happy with your brute solution, so just do some acting & behave like ya, I can improve it more. Tell him, why dont if we Sort the array & have 2 pointers one start from very begining & another from the end of the array.

Now we gonna get the sum,

if sum == k :- Increment our count & move our I & J pointer

if sum > k, Move our J pointer

if sum < k, Move our I pointer

class Solution {
    public int maxOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int count = 0;
        int i = 0;
        int j = nums.length - 1;
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == k) {
                count++;
                i++;
                j--;
            }
            else if(sum > k) j--;
            else i++;
        }
        return count;
    }
}

//ANALYSIS :-

//Time Complexity :- BigO(NlogN) + O(N) => O(NlogN)

//Space Complexity :- BigO(1)

//BEST

But, by looking at that, interviewer will say. I'm still not happy, so give him a flying kiss I mean give him a better solution 😅

Now again, perform a beautiful acting, and say why dont we use MAP. So, tell him by using map, we can optimise it more beautifully.
So, what we'll gonna do is & may be you know this one, it is similar to Two Sum, so if u dont know then listen to me.

We gonna fill our map as frequency map. And we gonna get the result by subtracting current value from k & whatever result we get, we gonna check in our map. If that is present increment the count & remove it from the map now. That's how we'll get our answer in just O(1) for searching & as we are using a loop thus, O(N). But it's a good approach.

class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        for(int i = 0; i < nums.length; i++){
            int res = k - nums[i];
            if(map.containsKey(res)){
                count++;
                if(map.get(res) == 1) map.remove(res);
                else map.put(res, map.get(res) - 1);
            }
            else{
                map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            }
        }
        return count;
    }
}

//ANALYSIS :-

//Time Complexity :- BigO(N)
//Space Complexity :- BigO(N)
