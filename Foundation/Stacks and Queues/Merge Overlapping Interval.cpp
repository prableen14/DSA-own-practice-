/*
1. You are given a number n, representing the number of time-intervals.
2. In the next n lines, you are given a pair of space separated numbers.
3. The pair of numbers represent the start time and end time of a meeting (first number is start time and second number is end time)
4. You are required to merge the meetings and print the merged meetings output in increasing order of start time.

E.g. Let us say there are 6 meetings
1 8
5 12
14 19
22 28
25 27
27 30

Then the output of merged meetings will belongs
1 12
14 19
22 30

Note -> The given input maynot be sorted by start-time.
Input Format
Input is managed for you 
Output Format
Print a merged meeting start time and end time separated by a space in a line
.. print all merged meetings one in each line.
Constraints
1 <= n <= 10^4
0 <= ith start time < 100
ith start time < ith end time <= 100
Sample Input
6
22 28
1 8
25 27
14 19
27 30
5 12
Sample Output
1 12
14 19
22 30
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

// sorting method
bool compare(const vector<int> v1, const vector<int> v2) {
  return v1[0] < v2[0];
}

void mergeOverlappingIntervals(vector<vector<int>>& arr) {

  // sort
  sort( arr.begin(), arr.end(), compare);

  stack<vector<int>> st;

  for (int i = 0; i < arr.size() ; i++) {
    vector<int> meeting = arr[i];
    int sp = meeting[0];
    int ep = meeting[1];

    if (st.size() == 0) {
      st.push(meeting);
    }
    else {
      vector<int> lastmeeting = st.top();
      st.pop();
      if (lastmeeting[1] >= sp ) {
        vector<int> mergedmeeting{
          lastmeeting[0], max(lastmeeting[1], ep)
        };

        st.push(mergedmeeting);
      }
      else {
        st.push(lastmeeting);
        st.push(meeting);
      }
    }
  }
  // reverse stack
  stack<vector<int>> tempst;
  while (! st.empty()) {
    tempst.push(st.top());
    st.pop();

  }
  // print stack
  while (! tempst.empty()) {
    vector<int> a = tempst.top();
    tempst.pop();

    cout << a[0] << " ";
    cout << a[1] << endl;
  }
}
int main() {
  int n;
  cin >> n ;

  vector<vector<int>> arr( n, vector<int>(2) );

  // input
  for (int i = 0; i < n ; i++ ) {
    cin >> arr[i][0];
    cin >> arr[i][1];
  }
  mergeOverlappingIntervals(arr);
}
