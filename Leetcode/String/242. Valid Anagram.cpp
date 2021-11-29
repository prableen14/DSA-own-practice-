/*

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
 
Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.*/
class Solution {
public:
    bool isAnagram(string s, string t) {
     int c=0;
        if(s.size() != t.size()) 
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[i])
                c++;
        }
		
        if(c==s.size())
            return true;
        
        else
            return false;   
    }
};

//Another 
class Solution {
public:
    bool isAnagram(string s, string t) {
     sort(s.begin(),s.end());
		sort(t.begin(),t.end());

		if(s==t) return true;

		return false;
   
    }
};
