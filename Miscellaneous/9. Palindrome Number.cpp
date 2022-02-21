/*
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is a palindrome while 123 is not.
 
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
Constraints:
-231 <= x <= 231 - 1
*/
class Solution {
public:
    bool isPalindrome(int x) {
      string rev = to_string(x);
        reverse(rev.begin(), rev.end());
        return to_string(x) == rev;
    }
};

//ANOTHER APPROACH
class Solution {
public:
    bool isPalindrome(int x) {
         long sum = 0, temp=x;         //to temp because x is changing
		while (x>0){                  //converting to opposite
			sum*=10;
			sum+=x%10;
			x/=10;
		}
        return(sum==temp);             //checking
    }
};
