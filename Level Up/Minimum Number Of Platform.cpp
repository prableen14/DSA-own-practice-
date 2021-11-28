/*
1. We have arrival and departure times of all trains that reach a railway station. 
2. We have to find the minimum number of platforms required for the railway station so that no train is kept waiting.
3. Consider that all the trains arrive on the same day and leave on the same day. 
4. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. 
5. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
Input Format
n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output Format
3
Constraints
1. 1 <= no. of trains <= 10000
2. 0000 <= Arrival[i] < Departure[i] <= 2359
Sample Input
6 
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000
Sample Output
3
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int findPlatform(int arr[], int dep[], int n) {
    // write your code here
    sort(dep, dep + n);	
    sort(arr, arr + n);
    int i=0;
    int j=0;
    int maxtrains=0;
    int platform=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            maxtrains++;
            i++;
        }
        else {maxtrains--;
        j++;}
platform=max(platform,maxtrains);
}
return platform;
  }
int main(){
    int n;
    cin>>n;
    int arr[n];
    int dep[n];
        for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
        for(int i = 0 ; i < n; i++){
        cin>>dep[i];
    }
    
     int plateforms = findPlatform(arr, dep,n);
     cout<<plateforms;
     return 0;
}
