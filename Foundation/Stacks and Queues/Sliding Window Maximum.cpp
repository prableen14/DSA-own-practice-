/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the elements of array a.
3. You are given a number k, representing the size of window.
4. You are required to find and print the maximum element in every window of size k.
e.g.
for the array [2 9 3 8 1 7 12 6 14 4 32 0 7 19 8 12 6] and k = 4, the answer is [9 9 8 12 12 14 14 32 32 32 32 19 19 19]
Input Format
Input is managed for you
Output Format
Maximum of each window in separate line
Constraints
0 <= n < 100000
-10^9 <= a[i] <= 10^9
0 < k < n
Sample Input
17
2
9
3
8
1
7
12
6
14
4
32
0
7
19
8
12
6
4
Sample Output
9
9
8
12
12
14
14
32
32
32
32
19
19
19
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;
  vector<int>nge(arr.size(), 0);
  nge[arr.size() - 1] = arr.size();
  stack<int>st;
  st.push(arr.size() - 1);
  for (int i = arr.size() - 2; i >= 0; i--)
  {
    while (st.size() > 0 && arr[st.top()] <= arr[i])
    {
      st.pop();
    }
    if (st.size() == 0)
    {
      nge[i] = arr.size();
    }
    else {
      nge[i] = st.top();
    }
    st.push(i);
  }
  int j=0;
   for (int i = 0; i <= arr.size()-k; i++){
       //enter the loop to find the maximum of window starting at i
       if(j<i) j=i;
       while(nge[j]<i+k){
       j=nge[j];
       }
       cout<<arr[j]<<endl;
   }
}
