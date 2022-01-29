/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/
//finding next smaller element on left and right for an element
class Solution {
public:
vector<int> nextSmallerLeft(vector<int>heights) {
  vector<int>nsl(heights.size(), 0); //nse index on left
  stack<int>st;
  nsl[0] = -1;
  st.push(0);
  for (int i = 0; i < heights.size(); i++)
  {
    while (st.size() > 0 && heights[i] <= heights[st.top()]) {
      st.pop();
    }
    if (st.size() == 0)
    {
      nsl[i] = -1;

    } else
    {
      nsl[i] = st.top();
    }
    st.push(i);
  }
  return nsl;
}
vector<int> nextSmallerRight(vector<int>heights) {
  vector<int>nsr(heights.size(), 0);//nse index on right
  stack<int>st;
  nsr[heights.size() - 1] = heights.size();
  st.push(heights.size() - 1);
  for (int i = heights.size() - 2; i >= 0; i--)
  {
    while (st.size() > 0 && heights[i] <= heights[st.top()]) {
      st.pop();
    }
    if (st.size() == 0)
    {
      nsr[i] = heights.size();

    } else
    {
      nsr[i] = st.top();
    }
    st.push(i);
  }
  return nsr;
}

int largestRectangleArea(vector<int>& heights) {
  vector<int>nsl = nextSmallerLeft(heights);
  vector<int>nsr = nextSmallerRight(heights);
  int max = 0;
  for (int i = 0; i < heights.size(); i++)
  {
    int ans = heights[i] * (nsr[i] - nsl[i]-1);
    if (ans > max)
    {
      max = ans;
    }
  }
  return max;
    }
};
