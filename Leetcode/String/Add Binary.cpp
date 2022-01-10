/*Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
class Solution {
public:

    string addBinary(string a, string b) {
        int alen=a.length();
        int blen=b.length();
        int i=alen-1, carry=0;
        int j=blen-1;
        string ans="";
       while (i>=0 || j>=0 || carry!=0){
            int x=0;
            if (i>=0 && a[i]=='1'){
                x=1;
            }
            int y=0;
            if(j>=0 and b[j]=='1'){
                y=1;
            }
            ans=to_string((x+y+carry)%2) + ans;
            carry=(x+y+carry)/2;
            i--;
            j--;
        }
        return ans;
    }
};
  
