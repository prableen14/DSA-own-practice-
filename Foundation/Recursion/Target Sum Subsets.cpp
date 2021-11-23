/*1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. Complete the body of printTargetSumSubsets function - without changing signature - to calculate and print all subsets of given elements, the contents of which sum to "tar". Use sample input and output to get more idea.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Input Format
Input Format
A number n
n1
n2
.. n number of elements
A number tar
Output Format
Comma separated elements of the subset, the contents of which add to "tar"
.. all such subsets, each in a single line (the elements of each subset should be comma separated)
Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 20
0 <= tar <= 50
Sample Input
5
10
20
30
40
50
60*/
#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar) {
  //write your code here
  if (sos > tar) {
    return;
  }
if(idx==arr.size())
{
    if(sos==tar) 
    {cout<<set<<"."<<endl;}
    return;
}
printTargetSumSubsets(arr,idx+1,set+to_string(arr[idx])+", ",sos+arr[idx],tar);
printTargetSumSubsets(arr,idx+1,set,sos,tar);
}


int main() {
  int n, tar;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> tar;
  printTargetSumSubsets(arr, 0, "", 0, tar);
}

//SAME SOLUTION
#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar) {
  if (sos > tar) {
    return;
  }
  if (idx == arr.size()) {
    if (sos == tar) {
      cout << set << "." << endl;
    }
    return;
  }
  string val = to_string(arr[idx]);
  printTargetSumSubsets(arr, idx + 1, set + val + ", ", sos + arr[idx], tar);
  printTargetSumSubsets(arr, idx + 1, set, sos, tar);
}


int main() {
  int n, tar;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> tar;
  printTargetSumSubsets(arr, 0, "", 0, tar);
}
