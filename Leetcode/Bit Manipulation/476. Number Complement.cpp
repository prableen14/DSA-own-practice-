/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

Example 1:
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 
Constraints:
1 <= num < 231
*/
//TC: O(logn)
//SC: O(1)
class Solution {
public:
    int findComplement(int num) {
       if(num==0) return 1;
        int ans=0;
        long p=1;
        while(num){
            int bit=num&1;
            if(bit==0) ans+=p;
            p*=2;   // p<<=1
            num/=2; // n>>=1
        }
        return ans;
    }
};

//Using array, naive approach
class Solution {
public:
    int findComplement(int n) {
        vector<int> arr;
        // creating binary array representation for the number
        while(n) {
            arr.push_back(n % 2);
            n /= 2;
        }
        int sz = arr.size();
        // Since, we are retrieving bits in backward fashion so we need to reverse it.
        reverse(arr.begin(), arr.end());
        // switching bit values
        for(int i = 0; i<sz; ++i) {
              arr[i] = !arr[i];
        }
        long long t = 1;
        // converting our above array into decimal form.
        for(int i = sz-1; i>=0; --i) {
            n += arr[i] * t;
            t *= 2;
        }
        return n;
    }
};
