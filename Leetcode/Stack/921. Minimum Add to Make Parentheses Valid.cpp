/*
A parentheses string is valid if and only if:
It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:
Input: s = "())"
Output: 1

Example 2:
Input: s = "((("
Output: 3

Constraints:
1 <= s.length <= 1000
s[i] is either '(' or ')'.
*/
//TC: O(N)
//SC:O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
      stack<char> st;
        for(int i=0;i<s.size();i++)
        { 
            if(s[i]=='(')
                st.push(s[i]);
            else if (st.size()>0 && st.top()=='(')
                st.pop();
            else
                st.push(s[i]);
           
        }
        return st.size();
    }
};

//Without using stack
//TC: O(N)
//SC:O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
	// open_balance stores the number of closing brackets to be added and close_balance stores number of open brackets to be added
        int close_balance = 0,open_balance = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(')open_balance++;
            else if(s[i] == ')' and open_balance>0)open_balance--;
            else close_balance++;
        }
        return open_balance+ close_balance;
    }
};
