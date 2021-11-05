/*
Sample Input
5

3
1
0
7
5
Sample Output
3
1
0
7
5
*/

#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
    // write your code here
    if(idx==n) return;
    cout<<arr[idx]<<"\n";
    display(arr,idx+1,n);
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n);
}
