/*
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false
 

Constraints:
-231 <= n <= 231 - 1
*/
//Bitwise
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n-1));
    }
};
//Another
class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n==0)
            return false;
        while(n!=1)
        {
            if(n%2!=0)
                return false;
            n = n/2;
        }
        return true;
    }
};