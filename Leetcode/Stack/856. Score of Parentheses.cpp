/*
Given a balanced parentheses string s, return the score of the string.
The score of a balanced parentheses string is based on the following rule:
"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 
Example 1:
Input: s = "()"
Output: 1

Example 2:
Input: s = "(())"
Output: 2

Example 3:
Input: s = "()()"
Output: 2
 
Constraints:
2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        // '('--> -1
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(-1);
            else{
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                   int score=0;
                   while(st.top()!=-1){
                    score+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(2*score);
            }
          }
        }
         int score=0;     
         while(st.size()>0){   //for ()() case
                  score+=st.top();
                    st.pop();
          }
        return score;
    }
};
