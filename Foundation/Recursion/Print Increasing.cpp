/*
1
2
3
4
5
*/

#include<iostream>
using namespace std;

void printIncreasing(int n){
    // write your code here
    if(n==0) return;
    
    printIncreasing(n-1);
    cout<<n<<"\n";
}


int main(){
    int n; cin>>n;
    printIncreasing(n);
}
