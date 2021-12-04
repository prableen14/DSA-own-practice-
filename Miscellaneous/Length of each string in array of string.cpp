#include <iostream>
#include <bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<string> cha(n);
    for(int i=0;i<n;i++)
    cin>>cha[i];
 

for(int i=0;i<cha.size();i++){
    arr[i]=cha.at(i).length();
}

for(int i=0;i<n;i++)
cout<<arr[i];

    return 0;
}
//Another
#include <iostream>
#include <bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> arr(n);
    vector<string> cha(n);
    for(int i=0;i<n;i++)
    cin>>cha[i];
 

for(int i=0;i<cha.size();i++){
    arr[i]=cha.at(i);
    int len=0;
    for(int j=0;j<arr.at(i).size();j++){
        len++;
    }
    cout<<len<<endl;
}
    return 0;
}
