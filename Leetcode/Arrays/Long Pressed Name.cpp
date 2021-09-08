/* Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.

*/
  

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.length()> typed.length()) return false;
        int i=0;
        int j=0;
        while(i<name.length()&& j<typed.length()){
            if(name.at(i)==typed.at(j))
            {i++;
            j++;
        }
            else if(i>0 && name.at(i-1)==typed.at(j))
                j++;
            else 
                return false;
            
    }
        while(j<typed.length())
        {
            if(name.at(i-1)!=typed.at(j))
                return false;
            j++;
        }
    return i<name.length() ? false: true;
    }
};
