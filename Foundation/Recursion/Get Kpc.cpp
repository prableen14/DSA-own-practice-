/*1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
2. The following list is the key to characters map :
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
3. Complete the body of getKPC function - without changing signature - to get the list of all words that could be produced by the keys in str.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Input Format
A string str
Output Format
Contents of the arraylist containing words as shown in sample output
Sample Input
78
Sample Output
[tv, tw, tx, uv, uw, ux]
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string codes[]= {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

vector<string> getKPC(string s) {
  //Write your code here
  if(s.size()==0){
      vector<string> bres;
    bres.push_back("");
    return bres;
  }
  char ch=s.at(0); 
    string ros=s.substr(1);
vector<string> rres= getKPC(ros); 
    vector<string> mres;
    string codeforch= codes[ch-'0'];
    for(int i=0; i<codeforch.length(); i++){
        char chcode= codeforch.at(i);
         for(string rstr: rres)
    mres.push_back(chcode+rstr);
    }
  return mres;
}


int main() {
  string s;
  cin >> s;
  vector<string> ans = getKPC(s);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}
