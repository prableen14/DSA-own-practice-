#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
      cout<<arr[i]<<" ";
    }
    cout<<"\n";
  }
void countSort(int *arr,int n, int expo){
     int *farr = new int [10]; //make frequency array
     for(int i=0;i<n;i++){
         farr[arr[i]/expo%10]++;        //Increasing count at that index
     }
     for(int i=1;i<10;i++){
         farr[i]=farr[i]+farr[i-1]; //Calculating prefix sum in that frequency array
     }
     
     int ans[n];
  //Stable Sorting(Filling ans array)
     for(int i=n-1;i>=0;i--){
         int pos=farr[arr[i]/expo%10]-1;
         ans[pos]=arr[i];
         farr[arr[i]/expo%10]--;
     }
  //Filling original array with the help of ans array
     for(int i=0;i<n;i++){
         arr[i]=ans[i];
     }
     cout<<"After sorting on "<<expo<< " place -> ";
    print(arr,n);
}
void radixSort(int *arr, int n){
    int max= INT_MIN;
    for(int val=0;val<n;val++){
        if(arr[val]> max) max=arr[val];
    }
    int expo=1;
    while (expo<=max){
        countSort(arr,n,expo);
        expo= expo*10;
    }
}


int main()
{
    int n;
    cout<<"Enter no. of Elements";
    cin>>n;
    int arr[n];
    
    cout<<"\n Enter the elements:";
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
   
   cout << "Array after Sorting: ";
    radixSort(arr,n);
    


    return 0;
}
