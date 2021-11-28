/*

1. You are given a string str.
2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
For abbc -> there are 3 subsequences. abc, abc, abbc
For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.
Input Format
A string str
Output Format
count of subsequences of the nature a+b+c+
Constraints
0 < str.length <= 10
Sample Input
abcabc
Sample Output
7
*/
#include <iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int a=0;
    int ab=0;
    int abc=0;
    for(int i=0;i<str.size();i++){
        char ch=str.at(i);
        if(ch=='a'){
           a=2*a+1; 
        }
        else if(ch=='b'){
          ab=2*ab+a;  
        }
        else if(ch=='c'){
            abc=2*abc+ab;
        }
    }
    cout<<abc;
}
