/*
1. You are given an array(arr) containing only 0's, 1's, and 2's.
2. You have to sort the given array in increasing order and in linear time.
Input Format
An Integer N 
arr1
arr2..
n integers
*/

#include <iostream>
using namespace std;

  void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
void sort012(int *arr, int n){
    //write your code here
    int i=0;
    int j=0;
    int k=n-1;
    while(i<=k){
        if(arr[i]==1){
            i++;
        }
        else if(arr[i]==0){
            swap(arr,i,j);
            i++;
            j++;
        }
        else { 
            swap(arr,i,k);
            k--;
        }
    }
    
  }
  void print(int *arr,int n){
    for(int i = 0 ; i < n; i++){
      cout<<arr[i];
    }
  }
int main()
{
    int n;
   cout<<"Enter the number of elements:";
   cin>>n;
int arr[n];
cout<<"Enter the elements:";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
sort012(arr,n);
    print(arr,n);

    return 0;
}
