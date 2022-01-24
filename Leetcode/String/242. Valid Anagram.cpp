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

//Sorting Solution
//Time Complexity: O (n(log n)) 
//Space Complexity: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
     sort(s.begin(),s.end());
		sort(t.begin(),t.end());

		if(s==t) return true;

		return false;
   
    }
};
//Hashmap Solution
//Time Complexity: O(n)
//Space Complexcity : O(n)
class Solution {
public:
	bool isAnagram(string s, string t) {
		if(s.length() != t.length()){
			return false;
		}
         // Create a HashMap containing Character as Key and
        // Integer as Value. We will be storing character as
        // Key and count of character as Value.
		unordered_map<char, int> mp;
		for(int i = 0; i < s.size(); i++){
			mp[s[i]]++; // Increase the number of frequency
			mp[t[i]]--; // Decrease the number of frequency
		}
        // Loop over all keys and check if all keys are 0.
        // If so it means it is anagram.
		for(auto i : mp){
			if(i.second!=0){
				return false;
			} 
		}
		return true;
	}
};
