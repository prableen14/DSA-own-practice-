/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the prices of a share on n days.
3. You are required to find the stock span for n days.
4. Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.

e.g.
for the array [2 5 9 3 1 12 6 8 7]
span for 2 is 1
span for 5 is 2
span for 9 is 3
span for 3 is 1
span for 1 is 1
span for 12 is 6
span for 6 is 1
span for 8 is 2
span for 7 is 1
Input Format
Input is managed for you
Output Format
Output is managed for you
Constraints
0 <= n < 10^5
-10^9 <= a[i] <= 10^9
For INPUT and OUTPUT example see the following link: https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/stock-span-official/ojquestion#!
*/
#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}
vector<int> solve(vector<int>arr)
{
  //write your code here
  stack<int> st;
  st.push(0);
  vector<int> span(arr.size(), 0);
  span[0] = 1;
  for (int i = 1; i < arr.size(); i++)
  {
    while (st.size() > 0 && arr[st.top()] <= arr[i]){
        st.pop();
    }
    if(st.size()==0) span[i]=i+1; //no greater element
    else span[i]=i-st.top(); //current element index - left greatest element's index
    st.push(i);
  }
  return span;
}
int main()
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int>span(n, 0);
  span = solve(arr);
  display(span);
  return 0;
}
