/*
1. You are given an array(arr) containing only 0's and 1's.
2. You have to sort the given array in increasing order and in linear time.
Input Format
An Integer N 
arr1
arr2..
n integers
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
void sort01(int *arr, int n){
    int i=0;
    int j=0;
    while(i< n){
        if(arr[i]==1) i++;
        else{
            swap(arr,i,j);
            i++;
            j++;
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
sort01(arr,n);
    print(arr,n);
    return 0;
}
