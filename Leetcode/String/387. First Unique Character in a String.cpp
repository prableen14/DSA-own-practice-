/*

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
 

Constraints:
1 <= s.length <= 105
s consists of only lowercase English letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26]={0};
        for(char i : s) {
            count[i-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(count[s[i]-'a']==1) return i;
        }
        return -1;
    }
};

//JAVA SOLUTION

class Solution {
    public int firstUniqChar(String s) {
       int [] arr=new int [26];
		for(int i=0;i<s.length();i++)
			arr[s.charAt(i)-'a']++;
			
		for(int i=0;i<s.length();i++)
			if(arr[s.charAt(i)-'a']==1)
				return i;
		
		return -1;	 
    }
}
