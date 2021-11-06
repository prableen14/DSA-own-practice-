/*Subsequence - 2^no.of characters
For eg: Given abc then 2^3=8 possible sub sequence (2 bcoz aayega ya nhi aayega character)

SubString: No. of possible substrings for n length of string are: n*(n+1)/2

*/
/*
1. You are given a string str.
2. Complete the body of getSS function - without changing signature - to calculate all subsequences of str.
Use sample input and output to take idea about subsequences.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is.
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Input Format
A string str
Output Format
Contents of the arraylist containing subsequences as shown in sample output
Sample Input
abc
Sample Output
[, c, b, bc, a, ac, ab, abc]

*/

#include <iostream>
#include <vector>
using namespace std;

// bc -> [--, -c, b-, bc]
//abc -> [---, --c, -b-, -bc, a--, a-c, ab-, abc]
vector<string> gss(string s){
    // write your code here
    if(s.size()==0)
    {vector<string> bres;
    bres.push_back("");
    return bres;}
    char ch=s.at(0); //a
    string ros=s.substr(1);  //bc
    vector<string> rres= gss(ros); // [--, -c, b-, bc]
    
    vector<string> mres;
    for(string rstr: rres)
    mres.push_back(""+rstr);
    for(string rstr: rres)
    mres.push_back(ch+rstr);
    return mres;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
