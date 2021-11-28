/*
1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.
Input Format
A number n
Output Format
A number representing the number of ways in which the buildings can be built on both side of roads.
Constraints
0 < n <= 45
Sample Input
6
Sample Output
441
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int ob=1; //old building
    int os=1;//old space 
    for(int i=2;i<=n;i++){
    int nb=os; //new building
    int ns=ob+os; // new space
    
    ob=nb;
    os=ns;
    }
    int t=ob+os;  
    cout<<t*t; //total no. of ways
}
