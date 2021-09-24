		*	
	*	*	*	
*	*	*	*	*	
	*	*	*	
		*	
      
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    //write your code here
int sp=n/2;
int st=1;
for(int i=1;i<=n;i++){
    for(int j=1;j<=sp;j++){
        cout<<"\t";
        
    }
    for(int j=1;j<=st;j++){
        cout<<"*\t";
    }
    if(i<=n/2){
        sp--;
        st+=2;;
        
    }
    else{
        sp++;
        st-=2;
    }
    cout<<"\n";
}
    }
