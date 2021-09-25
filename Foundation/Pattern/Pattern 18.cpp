*	*	*	*	*	*	*	
	*				*	
		*		*	
			*	
		*	*	*	
	*	*	*	*	*	
*	*	*	*	*	*	*	

#include <iostream>
using namespace std;
int main(int agrc, char**argv){
    int n;
    cin >> n;

    //write your code here
    int st=n;
    int sp=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sp;j++){
            cout<<"\t";}
        for(int j=1;j<=st;j++){
            if(i>1 && i<=n/2 &&j>1 && j< st){
                cout<<"\t";
            }else
            cout<<"*\t";
        }
        if(i<=n/2){
            sp++;
            st-=2;
            
        }
        else{
            sp--;
            st+=2;
        }
        cout<<"\n";
    }
}
