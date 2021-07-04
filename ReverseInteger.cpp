//Given a signed 32-bit integer x, return x with its digits reversed. 
//If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

class Solution {
public:
    int reverse(int x) {
        long long res=0;
        while(x){
            res=res*10+x%10;
            x=x/10;
        }
        if(res<INT_MIN || res>INT_MAX) return 0;
        return res;
    }
};
