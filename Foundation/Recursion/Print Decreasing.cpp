/*
5
4
3
2
1
*/

#include <iostream>
using namespace std;

void printDecreasing(int n){
    // write your code here
    if(n==0) return;  //base case
    
    cout<<n<<"\n";
    printDecreasing(n-1);
    
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}
