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

//with 2 maps:
//Time Complexity: O(n)
//Space Complexcity : O(n) 
//In solution using maps:
/*
We create two unordered maps, mp_s and mp_t, to store the counts of characters in strings s and t, respectively.
The size of each map will depend on the number of unique characters in the respective strings.
Let's denote:

n as the length of string s.
m as the length of string t.
k as the total number of unique characters across both strings.
Now, let's analyze the space complexity:

The space complexity for the unordered maps mp_s and mp_t:
The worst-case scenario is when all characters in the strings are unique, meaning k = n + m.
In this case, both mp_s and mp_t will have a size of k.
Therefore, the space complexity for both maps combined is O(k).
However, if k is significantly smaller than n + m, then the space complexity will be closer to O(n + m).
So, the space complexity for the solution using maps is O(k), where k represents the total number of unique characters across both strings. 
*/
	class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;

        // Populate map for string s
        for (char c : s) {
            mp_s[c]++;
        }

        // Populate map for string t
        for (char c : t) {
            mp_t[c]++;
        }

        // Compare the maps
        return mp_s == mp_t;
    }

};
