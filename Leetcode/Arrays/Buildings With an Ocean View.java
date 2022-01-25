//ASKED IN FACEBOOK MANY TIMES
/*There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.
The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. 
Formally, a building has an ocean view if all the buildings to its right have a smaller height.
Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

Example 1:
Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.

Example 2:
Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.

Example 3:
Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.

Example 4:
Input: heights = [2,2,2,2]
Output: [3]
Explanation: Buildings cannot see the ocean if there are buildings of the same height to its right.
Constraints:

1 <= heights.length <= 105
1 <= heights[i] <= 109
*/
//TC: O(N) //O(n)+O(n)= O(2n) which is taken as O(N)
//SC: O(N)
class Solution {
      public int[] findBuildings(int[] heights) {
          List<Integer> list = new ArrayList<>();
           int nextBiggest=0;
         for (int j = heights.length - 1; j >= 0; j--) {
           if(heights[j]>nextBiggest){
             nextBiggest=heights[j];
             list.add(j);
           }
         }
        int[] answer= new int[list.size()];
        int index=0;
        for(int i=list.size()-1;i>=0;i--){   //instead of doing this we can sort the list. In that case TC will be O(NlogN)
          answer[index]=list.get(i);
          index++;
        }
        return answer;
      }
};
