/*
1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
2. The following list is the key to characters map
    0 -> .;
   1 -> abc
   2 -> def
   3 -> ghi
   4 -> jkl
   5 -> mno
   6 -> pqrs
   7 -> tu
   8 -> vwx
   9 -> yz
3. Complete the body of printKPC function - without changing signature - to print the list of all words that could be produced by the keys in str.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.     
                               
Input Format
A string str
Output Format
Words that can be produced by pressed keys indictated by str in order hinted by Sample output
Constraints
0 <= str.length <= 10
str contains numbers only
Sample Input
78
Sample Output
tv
tw
tx
uv
uw
ux
*/
#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here
    if(ques.size()==0){
        cout<<asf<<"\n";
        return;
    }
    char ch=ques.at(0);
    string roq= ques.substr(1);
    string codeforch= codes[ch-'0'];
    for(int i=0;i<codeforch.size();i++){
        char cho= codeforch.at(i);
        printKPC(roq, asf+cho);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}
