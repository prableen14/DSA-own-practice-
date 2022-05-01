/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 
Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.

Follow up: Can you solve it in O(n) time and O(1) space?
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
           string result1 = "",result2 = "";
        int i = 0;
        
        while(s[i]!='\0')
        {
            if(s[i]>='a' && s[i]<='z')
                result1 += s[i];
            else if(!result1.empty())
                result1.pop_back();
            ++i;                
        }
        
        i = 0;
        while(t[i]!='\0')
        {
            if(t[i]>='a' && t[i]<='z')
                result2 += t[i];
            else if(!result2.empty())
                result2.pop_back();
            ++i;                
        }
        
        if(result1.compare(result2)==0)
            return true;
        return false;
    }
};
