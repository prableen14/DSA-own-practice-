/*
1. You are given a string str.
2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.
Use sample input and output to take idea about permutations.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Input Format
A string str
Output Format
Permutations of str in order hinted by Sample output
Constraints
0 <= str.length <= 7
Sample Input
abc
Sample Output
abc
acb
bac
bca
cab
cba
*/
#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.size()==0){
        cout<<asf<<endl;
        return;
    }
for(int i=0;i<str.size();i++){
    char ch= str.at(i);
    string lq=str.substr(0,i); //left part of question string
    string rq=str.substr(i+1); //right part of question string
    string roq=lq+rq;  //rest of the string
    printPermutations(roq,asf+ch);
}
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}
