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

// Eg: 123
//res= 0*10+123%10
//res=0+3=3
//x=123/10= 12

//res=3*10+12%10
//res=30+2=32
//x=12/10=1

//res=32*10+1%10
//res=320+1
//res=321
//x=1/10=0 (end of while loop)
