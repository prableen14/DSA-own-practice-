/*

*	*	*		*	*	*	
*	*				*	*	
*						*	
*	*				*	*	
*	*	*		*	*	*	

*/

#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
int st=n/2+1;
int sp=1;
    //write your code here
    for(int i=1;i<=n;i++){
    for(int j=1;j<=st;j++){
        cout<<"*\t";
        
    }
    for(int j=1;j<=sp;j++){
        cout<<"\t";
    }
    for(int j=1;j<=st;j++){
        cout<<"*\t";
        
    }
    
    if(i<=n/2){
        sp+=2;
        st--;
        
    }
    else{
        sp-=2;;
        st++;
    }
    cout<<"\n";
}
}
