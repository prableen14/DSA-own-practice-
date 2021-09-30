/*
Stable sort: Jab aap sort kare toh purana order kharab na kare. For example, 2 roll no. have same marks. 
  So after sorting jiska roll no. pehle aaya h that will come first in sorting
  
when no. of values are many but range is limited, that is when count sort is used.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countSort(int *arr,int n, int lo, int up){
     int range= up-lo+1;
     int *farr = new int [range]; //make frequency array
     for(int i=0;i<n;i++){
         int idx=arr[i]-lo;  //Finding right index in frequency array to put elements
         farr[idx]++;        //Increasing count at that index
     }
     for(int i=1;i<range;i++){
         farr[i]=farr[i]+farr[i-1]; //Calculating prefix sum in that frequency array
     }
     
     int ans[n];
  //Stable Sorting(Filling ans array)
     for(int i=n-1;i>=0;i--){
         int val=arr[i];
         int pos=farr[val-lo];
         int idx=pos-1;
         ans[idx]=val;
         farr[val-lo]--;
     }
  //Filling original array with the help of ans array
     for(int i=0;i<n;i++){
         arr[i]=ans[i];
     }
}
void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
      cout<<arr[i];
      cout<<"\n";
    }
  }
int main()
{
    
    int n;
    cout<<"Enter no. of Elements";
    cin>>n;
    int arr[n];
    int lo = INT_MAX;
    int up = INT_MIN;
    
    cout<<"\n Enter the elements:";
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        up = max(up, arr[i]);
      lo = min(lo, arr[i]);
    }
     cout << "Array before Sorting: ";
   print(arr, n);
   cout << "Array after Sorting: ";
    countSort(arr,n,lo,up);
    print(arr, n);
    

    return 0;
}
