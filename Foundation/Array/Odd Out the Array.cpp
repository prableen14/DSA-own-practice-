#include<stdlib.h>
#include<iostream>
int main(){
  int n;
	int arr[n];
	int mid;
	std::cout<<"enter";
	std::cin>>n;
	std::cout<<"\n";
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int start=0;
	int end=n-1;
	if(n%2==0){
		mid=(start+end)/2;
		arr[mid]+=arr[mid+1];
		for(int i=0;i<n;i++){
		if(i==mid+1){}
		else{
		std::cout<<arr[i]<<" ";}
		}	
	}
	else{
		for(int i=0;i<n;i++)
		std::cout<<arr[i]<<" ";
	}
    return 0;
}
