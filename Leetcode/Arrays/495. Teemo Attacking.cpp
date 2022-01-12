/*
Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. 
More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. 
If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.
You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.
Return the total number of seconds that Ashe is poisoned.

Example 1:
Input: timeSeries = [1,4], duration = 2
Output: 4
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 4, Teemo attacks, and Ashe is poisoned for seconds 4 and 5.
Ashe is poisoned for seconds 1, 2, 4, and 5, which is 4 seconds in total.

Example 2:
Input: timeSeries = [1,2], duration = 2
Output: 3
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 2 however, Teemo attacks again and resets the poison timer. Ashe is poisoned for seconds 2 and 3.
Ashe is poisoned for seconds 1, 2, and 3, which is 3 seconds in total.

Constraints:
1 <= timeSeries.length <= 104
0 <= timeSeries[i], duration <= 107
timeSeries is sorted in non-decreasing order.
*/
/*
If we look carefully at this problem we can see that all we need to do is to merge some intervals with equal length and return total length of merged intervals. 
Note also that intervals are already sorted by its beginings (and ends as well, because they have equal length), so usual sorting step can be skipped.
All we need to do is to traverse our timeSeries and check if difference between current point and previous is more than duration.
If it is more, we add duration to total sum, if it is less, we add difference between current and previous elements. 
Also we need to deal with border case of empty array and if array is not empty, add duration in the end.
Complexity: time complexity is O(n), space complexity is O(1).
*/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0)
            return 0;
        int res = 0;
        for(int i=0; i<timeSeries.size()-1; i++) {
            res+= min(timeSeries[i+1] - timeSeries[i], duration);
    }
     return res + duration;
    }
};

