*				
	*			
		*		
			*	
				*

#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    //write your code here
    for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i==j)
        cout<<"*";
        else
        cout<<"\t";
    }
    cout<<"\n";
}
}

/*
10000
02000
00300
00040
00005
*/
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    //write your code here
    for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i==j)
        cout<<i;
        else
        cout<<"0";
    }
    cout<<"\n";
}
}
