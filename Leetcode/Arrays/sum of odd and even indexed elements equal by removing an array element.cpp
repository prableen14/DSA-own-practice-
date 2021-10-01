//Count ways to make sum of odd and even indexed elements equal by removing an array element
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
