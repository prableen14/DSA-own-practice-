/*
1. You are given a string exp representing an expression.
2. You are required to check if the expression is balanced i.e. closing brackets and opening brackets match up well.

e.g.
[(a + b) + {(c + d) * (e / f)}] -> true
[(a + b) + {(c + d) * (e / f)]} -> false
[(a + b) + {(c + d) * (e / f)} -> false
([(a + b) + {(c + d) * (e / f)}] -> false
Input Format
A string str
Output Format
true or false
Constraints
0 <= str.length <= 100
Sample Input
[(a + b) + {(c + d) * (e / f)}]
Sample Output
true
*/
//opening brackets - push
//closing brackets - try to pop--> if size==0->false, unappropriate bracket->false
//in last, if stack size>0 means false, if size==0 means true
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    stack<char>st;
    string ans="true";
     for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(ch=='(' || ch=='[' || ch=='{') st.push(ch);
            else if(ch==')'){
               if(st.size()==0) ans="false";
               else if(st.top()!='(') ans="false"; //unappropriate match
               else st.pop(); 
            }
            else if(ch=='}'){
               if(st.size()==0) ans="false";
               else if(st.top()!='{') ans="false"; //unappropriate match
               else st.pop(); 
            }
            else if(ch==']'){
               if(st.size()==0) ans="false";
               else if(st.top()!='[') ans="false"; //unappropriate match
               else st.pop(); 
            }
     }
     if(st.size()>0) ans="false";
     cout<<ans;
}
