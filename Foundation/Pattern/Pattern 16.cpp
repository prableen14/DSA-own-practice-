1												1	
1	2										2	1	
1	2	3								3	2	1	
1	2	3	4						4	3	2	1	
1	2	3	4	5				5	4	3	2	1	
1	2	3	4	5	6		6	5	4	3	2	1	
1	2	3	4	5	6	7	6	5	4	3	2	1	


#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin >> n;

    //write your code here
    int sp=2*n-3;
    int st=1;
    
    for(int i=1;i<=n;i++){
        int val=1;
        for(int j=1;j<=st;j++){
            cout<<val<<"\t";
            val++;
            
        }
        for(int j=1;j<=sp;j++){
            cout<<"\t";
        }
        if(i==n){
        st--;
        val--;
            
        }
        for(int j=1;j<=st;j++){
            val--;
            cout<<val<<"\t";
        }
        st++;
        sp-=2;
        cout<<"\n";
    }
}
