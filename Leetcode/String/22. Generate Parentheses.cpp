/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8
*/
class Solution {
public:
vector<string> ans;

vector<string> generateParenthesis(int n) 
{
    backtrack(0,0,"",n);
    return ans;
   }
    void backtrack(int open,int close,string curr,int n)
{
    if(curr.size()==2*n)
    {
        ans.push_back(curr);
        return;
    }
    if(open<n)
        backtrack(open+1,close,curr+"(",n);
    if(close<open)
        backtrack(open,close+1,curr+")",n);
}
};
