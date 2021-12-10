/*
Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
 
Constraints:
1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
               unordered_map<char,int> m; //to store count of each char of magazine
        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]++; //counting the frequency of each character
        }
        for(int i=0;i<ransomNote.size();i++){
            
            // if(character from ransomNote is found in map and its count is not zero yet
            if(m.find(ransomNote[i])!=m.end() && m[ransomNote[i]]!=0)
                m[ransomNote[i]]--; 
             else
                 return false; // else if character not found or count of that character became zero        
        }
        return true;
    }
};
