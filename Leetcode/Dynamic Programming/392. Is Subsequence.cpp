/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.*/
//2 Pointer Approach
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return true;
        int t_pointer=0;
        int s_pointer=0;
        while(t_pointer<t.size()){
            if(t.at(t_pointer)==s.at(s_pointer))
                s_pointer++;
                if(s_pointer==s.size()) return true;
            t_pointer++;
                
        }
        return false;
    }
};
