/* Partition of ana rray

0 to j-1 ->  <= pivot
j to i-1 ->   > pivot
i to end -> unknown area

int i=0;
int j=0;
while(i< arr.length){
if(arr[i]> pivot)
i++;
else{
swap(arr,i,j)
i++;
j++;
}

*/
/* It is also known as “partition exchange sort”.
TC: O(nlogn) in best and average case. O(n^2) in worst case.
*/
#include<iostream>
#include<cstdlib>

using namespace std;

void swap(int *a, int *b) {
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int Partition(int a[], int l, int h) {
   int pivot, index, i;
   index = l;
   pivot = h;
   for(i = l; i < h; i++) {
      if(a[i] < a[pivot]) {
         swap(&a[i], &a[index]);
         index++;
      }
   }
   swap(&a[pivot], &a[index]);
   return index;
}
int RandomPivotPartition(int a[], int l, int h) {
   int pvt, n, temp;
   n = rand();
   pvt = l + n%(h-l+1);    //finding pivot element
   swap(&a[h], &a[pvt]);
   return Partition(a, l, h);
}
int QuickSort(int a[], int l, int h) {
   int pindex;
   if(l < h) {
      pindex = RandomPivotPartition(a, l, h); 
      QuickSort(a, l, pindex-1);
      QuickSort(a, pindex+1, h);
   }
   return 0;
}
int main() {
   int n, i;
   cout<<"\nEnter the number of data element to be sorted: ";
   cin>>n;
   int arr[n];
   for(i = 0; i < n; i++) {
      cout<<"Enter element "<<i+1<<": ";
      cin>>arr[i];
   }
   QuickSort(arr, 0, n-1);
   cout<<"\nSorted Data ";
   for (i = 0; i < n; i++)
      cout<<"->"<<arr[i];
   return 0;
}
