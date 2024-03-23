/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
int n = height.size();
       int i = 0, j = n-1;
       int mxArea = 0;
        while(i < j)
        {
            if(height[i] <= height[j]){
                mxArea = max(mxArea, (j-i)*height[i]);
                i++;
            }
            else{
                mxArea = max(mxArea, (j-i)*height[j]);
                j--;
            }
        }
        return mxArea;
    }
};

/*
The logic behind the condition height[i] <= height[j] in the two-pointer approach is to maximize the area formed between two lines in the height array. This method relies on the principle that the area formed between two lines on a plane is limited by the shorter of the two lines.

Here's the breakdown of the logic:

Area Calculation: The area of water that can be contained between two lines is determined by two factors: the height of the shorter line (since water spills over the shorter line) and the distance between the two lines. The area can be calculated as Area = height * width, where height is the height of the shorter line, and width is the distance between the two lines.

Maximizing Area: To maximize the area, you would want to maximize both the height and the width. However, once you have chosen two lines, you cannot change the distance (width) between them without moving one or both lines. The strategy then becomes to try to find a pair of lines that are both tall and far apart.

Why Move the Shorter Line?: Given a pair of lines, if you move the longer line towards the shorter one, the distance (width) between the lines decreases, and since the height of the contained water is still limited by the shorter line, the maximum possible area decreases or remains the same. However, if you move the shorter line towards the longer one, there's a potential to find a taller line, which could lead to a larger area, because you might find a new pair of lines where the shorter one is taller than the previous shorter line, or you might maintain the width more efficiently.

Decision to Increment i or Decrement j: When height[i] <= height[j], it means the line at the ith position is not taller than the line at the jth position. Since moving the taller line inwards won't help in finding a bigger area (for reasons mentioned above), the algorithm moves the ith (shorter) line to the right, hoping to find a taller line. Conversely, if height[j] < height[i], it implies the line at the jth position is the limiting factor, and thus the algorithm moves this line leftward (by decrementing j), hoping to find a taller line that could potentially form a larger area with the line at i.

This approach ensures that the algorithm exhausts all possibilities of finding two lines that can contain the maximum area of water, doing so in an efficient manner by eliminating less promising candidates as it progresses.*/
