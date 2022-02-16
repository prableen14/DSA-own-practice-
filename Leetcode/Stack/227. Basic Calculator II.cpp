/*
Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5
 
Constraints:
1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/
               int sum = 0;
        long long last = 0, last_result = 1;  
        char last_operator = '+'; //we need to remember the last operator
        //base case
        if(s.size() < 1) return sum; 
        //The sign flag is for the case if in input user gives a negative value. This question has no such conditions but yet i have done, because this may be a genereal case for implementaion in real life .
        int i = 0, sign = 1; 

        //Traverse the given string s
        while(i < s.size()){
            //Condition 1
            if(s[i] == ' '){++i; continue;}

            //Condition 2
            if(s[i] == '+' || s[i] == '-'){
                sum += last_result * sign;
                sign = s[i++] == '+' ? 1 : -1; 
                last_result = 1;
                last_operator = '+'; 
            }
            else if(s[i] == '/' || s[i] == '*'){
                last_operator = s[i];
                ++i; 
            }

            //Condition 3
            if(isdigit(s[i])){
                last = 0; 
                while(i < s.size() && isdigit(s[i])){
                    last =  last * 10 + s[i] - '0'; 
                    i++;
                }
                if(last_operator == '*') last_result *= last;
                else if(last_operator == '/') last_result /= last;

                else  last_result = last; 
            }
        }
        sum += last_result * sign;
        return sum;
