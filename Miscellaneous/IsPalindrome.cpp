class Solution {
public:
    bool isPalindrome(long int x) {
       long int r,sum=0,t;
        t=x;
        while(t>0)
        {
            r=t%10;
            sum=sum*10+r;
            t/=10;
        }
        if(sum==x)
            return true;
        return false;
    }
};
