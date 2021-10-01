//Count ways to make sum of odd and even indexed elements equal by removing an array element

/*Naive Approach: The simplest approach to solve this problem is to traverse the array and for each array element, check if removing the element from the array makes the sum of even-indexed and odd-indexed array elements equal or not. If found to be true, then increment the count. Finally, print the count.
TC: O(N^2) 
Optimized Approach: TC:O(N)
Removing any element from the given array makes even indices of succeeding elements as odd and odd indices of the succeeding elements as even. 
Algorithm:
1.Initialize two variables, say evenSum and oddSum, to store the sum of odd-indexed and even-indexed elements of the given array respectively.
2.Traverse the array using variable i.
3.Remove every ith element of the array and update the sum of the remaining even-indexed elements and the odd-indexed elements based on the above observation. Check if the sums are equal or not. If found to be true, then increment the count.
4.Finally, print the count obtained.
  */  

#include <iostream>

using namespace std;
int findEvenSum(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(i%2==0)
        sum+=arr[i];
    }
    return sum;
}
int findOddSum(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(i%2!=0)
        sum+=arr[i];
    }
    return sum;
}
int get_special_elements_count(int arr[], int n){
    if(n<=1) return 0;
    int evenSum=findEvenSum(arr,n);
    int oddSum=findOddSum(arr,n);
    int count=0;
    int evenSumSoFar=0;
    int oddSumSoFar=0;
    for(int i=0;i<n;i++){
        int val=arr[i];
        int newEven=0,newOdd=0;
        if(i%2==0){
            newEven=evenSumSoFar+(oddSum-oddSumSoFar);
            newOdd=oddSumSoFar+(evenSum-evenSumSoFar-val);
            if(newEven==newOdd) count++;
            evenSumSoFar+=val;
        }
        else{
            newEven=evenSumSoFar+(oddSum-oddSumSoFar-val);
            newOdd=oddSumSoFar+(evenSum-evenSumSoFar);
             if(newEven==newOdd) count++;
            oddSumSoFar+=val;
        }
    }
return count;}
int main()
{
    int n;
    cout<<"Enter no. of elements:";
    cin>>n;
    int arr[n];
    cout<<"\n Enter array elements:";
    for(int i=0;i<n;i++)
    cin>>arr[i];
int cnt=get_special_elements_count(arr,n);
cout<<cnt;
    return 0;
}
