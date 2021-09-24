				*	
			*		
		*			
	*				
*					
					
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    //write your code here
    for(int i=0;i<=n;i++){
        for(int j=n+1;j>=1;j--){
            if(i+1==j-1)
            cout<<"*";
            else cout<<"\t";
        }
        cout<<"\n";
    }
}
