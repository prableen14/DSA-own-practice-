1	
1	1	
1	2	1	
1	3	3	1	
1	4	6	4	1	

#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    
    //write your code here
    for(int i=0;i<n;i++){
        int iCj=1;
    for(int j=0;j<=i;j++){
        cout<<iCj<<"\t";
        int iCjp1= iCj*(i-j)/(j+1);
        iCj=iCjp1;
    }
    cout<<"\n";
    
}    
}
