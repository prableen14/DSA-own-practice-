/*
https://leetcode.com/problems/knight-dialer/discuss/189287/O(n)-time-O(1)-space-DP-solution-%2B-Google-interview-question-writeup
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square 
vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:
A chess knight can move as indicated in the chess diagram below:
We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
Given an integer n, return how many distinct phone numbers of length n we can dial.
You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n.
All jumps should be valid knight jumps.
As the answer may be very large, return the answer modulo 109 + 7.

Example 1:
Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

Example 2:
Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

Example 3:
Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.

Constraints:
1 <= n <= 5000
*/
class Solution {
public:
    int knightDialer(int n) {
        long a = 1, b = 1, c = 1, d = 1, e = 1, f=1,g=1,h=1,i=1,j=1, mod = pow(10, 9)+7;
        long a2, b2, c2, d2, e2,f2,g2,h2,i2,j2; 
        
        for (int k = 2; k<= n; k++) {
            a2 = (f+h) % mod; //one
            b2 = (g+i) % mod; //two
            c2 = (d+h) % mod; //three
            d2 = (c+i+j) % mod; //four
            e2 = (0) % mod;    //five
            f2 = (j+a+g) % mod;  //six
            g2 = (b+f) % mod;   //seven
            h2 = (a+c) % mod;   //eight
            i2 = (b+d) % mod;   //nine
            j2= (d+f) % mod;    //zero
            a = a2, b = b2, c = c2, d = d2, e = e2, f=f2, g=g2, h=h2,i=i2,j=j2;
        }
        return (a + b + c + d + e+f+g+h+i+j) % mod;
    }
};
