/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. You are required to calculate and print the count of encodings for the string str.

     For 123 -> there are 3 encodings. abc, aw, lc
     For 993 -> there is 1 encoding. iic 
     For 013 -> This is an invalid input. A string starting with 0 will not be passed.
     For 103 -> there is 1 encoding. jc
     For 303 -> there are 0 encodings. But such a string maybe passed. In this case 
     print 0.
Input Format
A string str
Output Format
count of encodings
Constraints
0 < str.length <= 10
Sample Input
123
*/
#include<bits/stdc++.h>

using namespace std;

int encode(char *str,int n){
    int dp[n];
    memset(dp,0,sizeof(dp));
    
    dp[0]=1;
    
    for(int i=1;i<=n;i++){
        if(str[i-1]=='0' && str[i]=='0'){
            dp[i]=0;
        } 
        else if(str[i-1]=='0' && str[i]!='0'){
            dp[i]=dp[i-1];
        }else if(str[i-1]!='0' && str[i]=='0'){
            if(str[i-1]=='2' || str[i-1]=='1'){
                dp[i]= (i>=2 ? dp[i-2] : 1);
            }else{
                dp[i]=0;
            }
        }
        else{
            if (str[i - 1] == '1'
        || (str[i - 1] == '2'
        && str[i] < '7')){
                dp[i]=dp[i-1] + (i>=2 ? dp[i-2] : 1);
            }else{
                dp[i]=dp[i-1];
            }
        }
     }
     
     return dp[n-1];
}

int main(){
    
    char str[11];
    cin>>str;
    
    int n=strlen(str);
    
    cout<<encode(str,n)<<endl;
}
//This following is one not giving giving right output
#include <iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int dp[str.size()];
    dp[0]=1;
    for(int i=1;i<str.size();i++){
        if(str.at(i-1)=='0' && str.at(i)=='0'){
          dp[i]=0;  
        }
        else if(str.at(i-1)=='0' && str.at(i)!='0'){
            dp[i]=dp[i-1];
        }
        else if(str.at(i-1)!='0' && str.at(i)=='0'){
            if(str.at(i-1)=='1' || str.at(i-1)=='2'){
                dp[i]=(i>=2? dp[i-2]: 1);
            }
            else dp[i]=0;
        }
        else{
            if(stoi(str.substr(i-1,i+1))<=26){
                dp[i]=dp[i-1]+(i>=2? dp[i-2]: 1);
            }
            else dp[i]=dp[i-1];
        }
    }
    cout<<dp[str.size()-1];
}
