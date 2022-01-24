/*
1. You are given a string exp representing an expression.
2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
3. But, some of the pair of brackets maybe extra/needless. 
4. You are required to print true if you detect extra brackets and false otherwise.

e.g.'
((a + b) + (c + d)) -> false
(a + b) + ((c + d)) -> true
Input Format
A string str
Output Format
true or false
Constraints
0 <= str.length <= 100
Sample Input
(a + b) + ((c + d))
Sample Output
true
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    stack<char>st;
    string ans="false";
    for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(ch == ')'){
                if(st.top() == '('){
                    ans="true";
                    
                } else {
                    while(st.top() != '('){
                        st.pop();
                    }
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }
cout<<ans;
}
