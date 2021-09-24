/*1. You are given a number n.
2. You've to create a pattern of * and separated by tab as shown in output format.

Input Format
A number n

Output Format

				*	
			*	*	
		*	*	*	
	*	*	*	*	
*	*	*	*	*	

*/

#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int sp=n-1;
    int st=1;
    //write your code here
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sp;j++){
            cout<<"\t";
            
        }
        for(int j=1;j<=st;j++){
            cout<<"*\t";
            
        }
        sp--;
        st++;
        cout<<"\n";
    }
}
