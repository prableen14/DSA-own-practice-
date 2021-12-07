/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
class Solution {
public:
bool isPalindrome(string s) {
for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
}
return true;
}};
