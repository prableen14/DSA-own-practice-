/*
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.

Example 1:
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.
*/
//string() creates a new string starting from rbegin(w) means reverse begin of w which is end of w and ending at rend(w) which means reverse end of w which is beginning of w --> in summary it creates a new string which is reverse of w
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
         for (auto &w : words)
        if (w == string(rbegin(w), rend(w)))
            return w;
    return "";
    }
};

//more efficient way to check the string (no need to create temporary strings)
string firstPalindrome(vector<string>& words) {
    for (auto &w : words)
        if (equal(begin(w), end(w), rbegin(w)))
            return w;
    return  {};
} 
