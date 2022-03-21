/*
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. 
(A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
If it cannot be done, return -1.

Example 1:
Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

Example 2:
Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 
Constraints:
2 <= tops.length <= 2 * 104
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6
*/
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> countA(7), countB(7), countSame(7);
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            countA[a] += 1;
            countB[b] += 1;
            if (a == b) countSame[a] += 1;
        }
        int ans = n;
        for (int v = 1; v <= 6; v++) {
            if (countA[v] + countB[v] - countSame[v] == n) {
                int minSwap = min(countA[v], countB[v]) - countSame[v];
                ans = min(ans, minSwap);
            }
        }   
        return ans == n ? -1 : ans;
    }
};
