/*
Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 
Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool flag=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' ' && flag==true)
                break;
            else if(s[i]!=' ') {
                flag=true;
                ans++;
            }
       }
       return ans;  
        
    }
};
//Using stringstream

class Solution {
public:
    int lengthOfLastWord(string s) {
     // breaking input into word using string stream
        stringstream ss(s); // Used for breaking words
        string word;  //To store individual words
        int ans;
        while(ss>>word) ans=word.length();
        
        return ans;
    }
};