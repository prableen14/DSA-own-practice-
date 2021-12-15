/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
       bool dp[n][n];
        int count=0;
        for(int g=0;g<s.size();g++){ //gap
            for(int i=0,j=g;j<n;i++,j++){
            //If gap is zero, means single character, therefore it is already palindrome
                if(g==0) 
                    dp[i][j]=true;
                else if(g==1) //If gap is one , put true only if both the characters are same
                    dp[i][j]=s.at(i)==s.at(j);
                else{
                if(s.at(i)==s.at(j) && dp[i+1][j-1]==true)
                 dp[i][j]=true;
                 else dp[i][j]=false;
                }
                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};
