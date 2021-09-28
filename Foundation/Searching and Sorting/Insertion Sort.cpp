/*
for(i=1;i<array.length;i++){
  for(j=i-1;j>=0;j--){
    if(isGreater(arr,j,j+1){
      swap(arr,j,j+1);
    }
       else break;
       }
      }
       */

#include<iostream>
using namespace std;
void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void insertionSort(int *array, int size) {
   int i, j;
   for(i = 1; i<size; i++) {
      for(j = i-1; j>=0; j--){
         if(array[j] > array[j+1])
         swap(array[j], array[j+1]);
         else break;}
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];           //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   insertionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
