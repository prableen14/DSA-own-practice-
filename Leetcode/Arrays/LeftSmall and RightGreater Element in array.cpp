// Program to find the element which is greater than
// all left elements and smaller than all right elements.
#include <bits/stdc++.h>
using namespace std;
 
// Function to return the index of the element which is greater than
// all left elements and smaller than all right elements.
int findElement(int arr[], int n)
{
    // leftMax[i] stores maximum of arr[0..i-1]
    int leftMax[n];
    leftMax[0] = INT_MIN;
 
    // Fill leftMax[]1..n-1]
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
 
    // Initialize minimum from right
    int rightMin = INT_MAX;
 
    // Traverse array from right
    for (int i=n-1; i>=0; i--)
    {
        // Check if we found a required element
        if (leftMax[i] < arr[i] && rightMin > arr[i])
                 return i;
 
        // Update right minimum
        rightMin = min(rightMin, arr[i]);
    }
 
    // If there was no element matching criteria
    return -1;
}
 
int main()
{
    int n;
    cout<<"Enter no. of elements:";
    cin>>n;
    int arr[n];
    cout<<"\n Enter Elements:";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    cout << "Index of the element is " << findElement(arr, n);
    return 0;
}
