
#include<iostream>
  #include<vector>
  using namespace std;
  
  // This is a functional problem. You have to complete this function.
  // It takes as input the given array. It should return true if the array is sorted, else should return false.
  bool isSorted(vector<int>& arr) {
      // write your code here.
      bool flag=false;
      for(int i=0;i<arr.size();i++){
          if(arr[i]<=arr[i+1])
         flag=true;
         else{ 
         break;}
      }
      return flag;
  }
  
  int main(int argc,char** argv){
  
      int N;
      cin>>N;
      vector<int> arr;
      for(int i=0;i<N;i++){
          int a;
          cin>>a;
          arr.push_back(a);
      }    
      if(isSorted(arr)){
          cout<<"Yes"<<endl;
      } else {
          cout<<"No"<<endl;
      }
      
  }
  
  // utility function to display an array.
  void display(vector<int> arr) {
      if(arr.size()==0){
          return;
      }
  
      for(int i: arr){
          cout<<i<<" ";
      }
      cout<<endl;
  }
