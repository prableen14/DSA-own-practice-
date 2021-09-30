#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void targetSumPair(int *arr,int n, int target){
    sort(arr,arr+n);
    int li=0;
    int ri=n-1;
    while(li<ri){
        if(arr[li]+arr[ri]> target){
            ri--;
        }
        else if(arr[li]+arr[ri]<target){
            li++;
        }
        else{
            cout<<arr[li]<<","<<arr[ri]<<"\n";
            li++;
            ri--;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter Number of Elements:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements:";
     for(int i = 0 ;i < n; i++){
      cin>>arr[i];
       }
int target;
cout<<"\nEnter the target:";
cin>>target;
targetSumPair(arr,n,target);
    return 0;
}
