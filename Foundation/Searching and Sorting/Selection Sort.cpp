/* TC: O(n^2) in all cases
Selection sort can be good at checking if everything is already sorted. It is also good to use when memory space is limited. 
This is because unlike other sorting algorithms, selection sort doesn't go around swapping things until the very end, resulting in less temporary storage space used.
If there are 5 elements then 4 iterations will be carried out.
A pointer is started from next of 1st element and it searches through all array if any element is less than the 1st element. If that so, then swap them.

for(i=0;i< arr.length-1;i++){
min=i;
for(j=i+1;j<arr.length;j++){
if(isSmaller(arr,j,min){
min=j;
}}
swap(arr,i,mi);
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
void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
         //placing in correct position
         swap(array[i], array[imin]);
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
   selectionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
