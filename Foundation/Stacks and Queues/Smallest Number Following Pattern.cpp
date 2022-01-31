/*
1. You are given a pattern of upto 8 length containing characters 'i' and 'd'.
2. 'd' stands for decreasing and 'i' stands for increasing
3. You have to print the smallest number, using the digits 1 to 9 only without repetition, such that 
the digit decreases following a d and increases follwing an i.

e.g.
d -> 21
i -> 12
ddd -> 4321
iii -> 1234
dddiddd -> 43218765
iiddd -> 126543
Input Format
Input is managed for you
Output Format
Smallest sequence of digits (from 1 to 9) without duplicacy and following the pattern
Constraints
0 < str.length <= 8
str contains only 'd' and 'i'
Sample Input
ddddiiii
Sample Output
543216789
*/
#include<iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int nums=1;
  string str;
  cin >> str;
stack<int> st;
for(int i=0;i<str.size();i++){
    if(str[i]=='d'){
        st.push(nums);
        nums++;
    }
    else{
        st.push(nums);
        nums++;
        
        while(st.size()>0){
        cout<<st.top();
        st.pop();
    }
    }
}
    st.push(nums);
    while (st.size() > 0) {
    cout << st.top();
    st.pop();
}
}

