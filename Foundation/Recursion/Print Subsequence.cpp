/*
1. You are given a string str.
2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.
Use sample input and output to take idea about subsequences.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Input Format
A string str
Output Format
Subsequences of str in order hinted by Sample output
Constraints
0 <= str.length <= 7
Sample Input
yvTA

Sample Output
yvTA
yvT
yvA
yv
yTA
yT
yA
y
vTA
vT
vA
v
TA
T
A


*/
#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    if(ques.size()==0){
        cout<<ans<<"\n";
        return;
    }
    char ch=ques.at(0);
    string roq= ques.substr(1);
    printSS(roq,ans+ch);    //call of Yes
    printSS(roq,ans+"");   //call of No 
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}
