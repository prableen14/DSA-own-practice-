/* 1. You are given a number n.
2. You are given a digit d.
3. You are required to calculate the frequency of digit d in number n.

Sample Input
994543234
 4
 
Sample Output
3
*/

#include<iostream>
using namespace std;
int digFreq(int n, int d) {
  //write your code here
         int count=0;
        int r;  
        while(n!=0)
        {   r=n%10;
            n/=10;
        if(r==d)
           count++;
        }
        return count;
}
int main() {
  int n, d;
  cin >> n >> d;
  int res = digFreq(n, d);
  cout << res << endl;
}
