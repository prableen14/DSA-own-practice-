3 * 1 = 3
3 * 2 = 6
3 * 3 = 9
3 * 4 = 12
3 * 5 = 15
3 * 6 = 18
3 * 7 = 21
3 * 8 = 24
3 * 9 = 27
3 * 10 = 30
  
  
#include<iostream>
using namespace std;
int main(int agrc, char** argv){
    int x;
    cin >> x;
    
    //write your code here
    for(int i=1;i<=10;i++){
            cout<<x<<" * "<<i<<" = "<<x*i;
            cout<<"\n";
        }
    }
