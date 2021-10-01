#include <bits/stdc++.h>
using namespace std;
 
// Function to find the nearest perfect square
// for every element in the given array
void nearestPerfectSquare(int arr[], int n)
{
 
    // Traverse the array
    for (int i = 0; i < n; i++) {
 
        // Calculate square root of
        // current  element
        int sr = sqrt(arr[i]);
 
        // Calculate perfect square
        int a = sr * sr;
        int b = (sr + 1) * (sr + 1);
 
        // Find the nearest
        if ((arr[i] - a) < (b - arr[i]))
            cout << a << " ";
        else
            cout << b << " ";
    }
}
 
int main()
{ 
    int n;
    cout<<"Enter no. of elements in an array:";
    cin>>n;
    int arr[n];
    cout<<"\n Enter elements of the array:";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    nearestPerfectSquare(arr, n);
    return 0;
}
