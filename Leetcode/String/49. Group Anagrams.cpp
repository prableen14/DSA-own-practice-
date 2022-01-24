/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
 
Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/
/*So naturally we can create an unordered map that has a string as key and a vector of strings as its corrosponding value. 
Then as we iterate over our given vector of string, we extract each string and make a copy of it after sorting it, then we push our original string into our map with sorted string as key. 
This will ensure that all anagrams are grouped together as they will be pushed into the same key value (i.e the string in sorted order).
In the end we simply iterate over our map and push every map value (vector of string) into ans (vector of vectorof string ) and we return the ans.*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>>m;
        vector<vector<string>>ans;
        
        for(auto x: strs){
            string temp = x;   //store the copy of every string we iterate over in x
            sort(x.begin(), x.end()); // sort the copy and use this as the key for our map
            m[x].push_back(temp);  // push the original string corrosponding to sorted version of the string in map
        }
        
        for(auto itr: m){
            vector<string> temp2= itr.second; 
            ans.push_back(temp2); //push all anagrams of a given string in ans
        }
        
        return ans;
    }
};
