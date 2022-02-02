/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 
Constraints:
1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k)
            return "0";
       string ans="";
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(k>0 && !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
            // We pop any preceeding zeroes
            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
            while(k>0  && !st.empty()) 
            {st.pop();
            k--;
            }
            while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() == 0)
            return "0";
        else
        return ans;    
    }
};
